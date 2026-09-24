#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"

#include <stdint.h>
#include <stdlib.h>

enum TokenType {
  HERE_STRING,
  HERE_STRING_START,
  HERE_STRING_CONTENT,
  HERE_STRING_HASH,
  HERE_STRING_HASH_BRACE,
  HERE_STRING_END,
};

typedef Array(int32_t) Chars;

// `chars` concatenates open `#<#` tags; `lengths` stores one entry per tag.
// The innermost tag is therefore the suffix of `chars`. As in CHICKEN's
// reader, only LF ends a line; CR remains part of the tag or content line.
//
// `line_start` is set when a start or content token ends with a newline.
// The next body token may then be the closing line. A
// closing tag leaves its LF unconsumed. The enclosing grammar or here-string
// body then consumes that newline, so nested strings preserve line boundaries
// without depending on the lexer column during incremental reuse.
//
// Serialized state contains one line_start byte, a LEB128 tag count, and
// each tag's LEB128 codepoint count and codepoints.
typedef struct {
  Chars chars;
  Array(uint32_t) lengths;
  bool line_start;
} Scanner;

static unsigned varuint_size(uint32_t value) {
  unsigned size = 1;
  while (value >= 0x80) {
    value >>= 7;
    size++;
  }
  return size;
}

static unsigned encode(uint8_t *out, uint32_t value) {
  unsigned size = 0;
  do {
    uint8_t byte = (uint8_t)(value & 0x7f);
    value >>= 7;
    out[size++] = byte | (value ? 0x80 : 0);
  } while (value);
  return size;
}

static uint32_t decode(const uint8_t **cursor) {
  uint32_t value = 0;
  for (unsigned shift = 0;; shift += 7) {
    uint8_t byte = *(*cursor)++;
    value |= (uint32_t)(byte & 0x7f) << shift;
    if (!(byte & 0x80)) return value;
  }
}

static unsigned serialized_size(const Scanner *scanner) {
  unsigned size = 1 + varuint_size(scanner->lengths.size);
  for (uint32_t i = 0; i < scanner->lengths.size; i++) {
    size += varuint_size(scanner->lengths.contents[i]);
  }
  for (uint32_t i = 0; i < scanner->chars.size; i++) {
    size += varuint_size((uint32_t)scanner->chars.contents[i]);
  }
  return size;
}

static void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

// Consume the rest of the line while matching `tag` from index `i`.
// Return whether the entire line matches the tag.
static bool match_line(TSLexer *lexer, const int32_t *tag, uint32_t length, uint32_t i) {
  while (i < length && !lexer->eof(lexer) && lexer->lookahead == tag[i]) {
    advance(lexer);
    i++;
  }
  return i == length && lexer->lookahead == '\n';
}

// The tag is the rest of the opening line. It is invalid without a newline.
static bool read_tag(TSLexer *lexer, Chars *chars) {
  while (!lexer->eof(lexer) && lexer->lookahead != '\n') {
    array_push(chars, lexer->lookahead);
    advance(lexer);
  }
  return !lexer->eof(lexer);
}

static bool scan_start(Scanner *scanner, TSLexer *lexer) {
  uint32_t start = scanner->chars.size;
  if (!read_tag(lexer, &scanner->chars)) return false;
  array_push(&scanner->lengths, scanner->chars.size - start);
  if (serialized_size(scanner) > TREE_SITTER_SERIALIZATION_BUFFER_SIZE) return false;
  advance(lexer);
  scanner->line_start = true;
  return true;
}

// Opaque strings finish within this scan, so their tag only borrows the end
// of `chars` and is not limited by serialized state.
static bool scan_opaque(Scanner *scanner, TSLexer *lexer) {
  uint32_t start = scanner->chars.size;
  if (!read_tag(lexer, &scanner->chars)) return false;
  const int32_t *tag = scanner->chars.contents + start;
  uint32_t length = scanner->chars.size - start;
  while (lexer->lookahead == '\n') {
    advance(lexer);
    if (match_line(lexer, tag, length, 0)) {
      break;
    }
    while (!lexer->eof(lexer) && lexer->lookahead != '\n') advance(lexer);
  }
  scanner->chars.size = start;
  scanner->line_start = false;
  return true;
}

static bool scan_open(Scanner *scanner, TSLexer *lexer, const bool *valid) {
  advance(lexer);
  if (lexer->lookahead != '<') return false;
  advance(lexer);
  if (lexer->lookahead == '<' && valid[HERE_STRING]) {
    advance(lexer);
    lexer->result_symbol = HERE_STRING;
    return scan_opaque(scanner, lexer);
  }
  if (lexer->lookahead == '#' && valid[HERE_STRING_START]) {
    advance(lexer);
    lexer->result_symbol = HERE_STRING_START;
    return scan_start(scanner, lexer);
  }
  return false;
}

typedef struct {
  const int32_t *tag;
  uint32_t length, matched;
  bool matching;
} TagMatch;

static void advance_matching(TSLexer *lexer, TagMatch *match) {
  match->matching = match->matching && match->matched < match->length &&
      lexer->lookahead == match->tag[match->matched];
  match->matched++;
  advance(lexer);
}

// Scan the next ordinary token. At a line start, keep matching the tag past
// that token: a complete terminator line replaces it with the closer. For tag
// `ab#c`, a failed match of `ab#x` returns `ab`; for tag `#{tag`, a failed
// match of `#{x}` returns `#{`.
static enum TokenType scan_line(Scanner *scanner, TSLexer *lexer, const bool *valid) {
  uint32_t length = *array_back(&scanner->lengths);
  TagMatch match = {
    .tag = scanner->chars.contents + scanner->chars.size - length,
    .length = length,
    .matching = scanner->line_start && valid[HERE_STRING_END],
  };
  scanner->line_start = false;
  enum TokenType type = HERE_STRING_CONTENT;
  if (lexer->lookahead == '#') {
    advance_matching(lexer, &match);
    type = HERE_STRING_HASH;
    if (lexer->lookahead == '{' && valid[HERE_STRING_HASH_BRACE]) {
      advance_matching(lexer, &match);
      type = HERE_STRING_HASH_BRACE;
    }
  } else {
    while (!lexer->eof(lexer) && lexer->lookahead != '#' && lexer->lookahead != '\n') {
      advance_matching(lexer, &match);
    }
    bool closes = match.matching && match.matched == length;
    if (lexer->lookahead == '\n' && !closes) {
      advance(lexer);
      scanner->line_start = true;
      return type;
    }
  }
  lexer->mark_end(lexer);
  if (!match.matching || !match_line(lexer, match.tag, length, match.matched)) return type;
  lexer->mark_end(lexer);
  return HERE_STRING_END;
}

static bool scan_body(Scanner *scanner, TSLexer *lexer, const bool *valid) {
  if (!scanner->lengths.size) return false;
  enum TokenType type =
      lexer->eof(lexer) ? HERE_STRING_END : scan_line(scanner, lexer, valid);
  if (type == HERE_STRING_END) {
    // Empty tags and EOF can close without consuming text. Popping the tag
    // changes serialized state, so even a zero-width closer makes progress.
    scanner->chars.size -= array_pop(&scanner->lengths);
  }
  lexer->result_symbol = type;
  return true;
}

// Tree-sitter deserializes the state before every scan, so a rejected scan
// need not undo its changes.
bool tree_sitter_scheme_external_scanner_scan(
    void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = payload;
  bool can_open = valid_symbols[HERE_STRING] || valid_symbols[HERE_STRING_START];
  bool found = can_open && lexer->lookahead == '#'
      ? scan_open(scanner, lexer, valid_symbols)
      : scan_body(scanner, lexer, valid_symbols);
  return found && valid_symbols[lexer->result_symbol];
}

void *tree_sitter_scheme_external_scanner_create(void) {
  return calloc(1, sizeof(Scanner));
}

void tree_sitter_scheme_external_scanner_destroy(void *payload) {
  Scanner *scanner = payload;
  array_delete(&scanner->chars);
  array_delete(&scanner->lengths);
  free(scanner);
}

unsigned tree_sitter_scheme_external_scanner_serialize(void *payload, char *buffer) {
  const Scanner *scanner = payload;
  if (!scanner->lengths.size) return 0;
  uint8_t *out = (uint8_t *)buffer;
  out[0] = scanner->line_start;
  unsigned size = 1 + encode(out + 1, scanner->lengths.size);
  const int32_t *c = scanner->chars.contents;
  for (uint32_t i = 0; i < scanner->lengths.size; i++) {
    size += encode(out + size, scanner->lengths.contents[i]);
    for (uint32_t j = 0; j < scanner->lengths.contents[i]; j++) {
      size += encode(out + size, (uint32_t)*c++);
    }
  }
  return size;
}

void tree_sitter_scheme_external_scanner_deserialize(
    void *payload, const char *buffer, unsigned length) {
  Scanner *scanner = payload;
  array_clear(&scanner->chars);
  array_clear(&scanner->lengths);
  scanner->line_start = false;
  if (!length) return;
  const uint8_t *data = (const uint8_t *)buffer;
  scanner->line_start = data[0];
  const uint8_t *cursor = data + 1;
  uint32_t depth = decode(&cursor);
  for (uint32_t i = 0; i < depth; i++) {
    uint32_t count = decode(&cursor);
    array_push(&scanner->lengths, count);
    for (uint32_t j = 0; j < count; j++) {
      array_push(&scanner->chars, (int32_t)decode(&cursor));
    }
  }
}
