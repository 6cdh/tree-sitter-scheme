#include <tree_sitter/api.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const TSLanguage *tree_sitter_scheme(void);

static TSPoint point_at(const char *source, size_t offset) {
  TSPoint point = {0};
  for (size_t i = 0; i < offset; i++) {
    if (source[i] == '\n') {
      point.row++;
      point.column = 0;
    } else {
      point.column++;
    }
  }
  return point;
}

static bool same_nodes(TSNode a, TSNode b) {
  if (strcmp(ts_node_type(a), ts_node_type(b)) ||
      ts_node_start_byte(a) != ts_node_start_byte(b) ||
      ts_node_end_byte(a) != ts_node_end_byte(b) ||
      ts_node_child_count(a) != ts_node_child_count(b)) return false;
  for (uint32_t i = 0; i < ts_node_child_count(a); i++) {
    if (!same_nodes(ts_node_child(a, i), ts_node_child(b, i))) return false;
  }
  return true;
}

static void check_edit(
    TSParser *parser, TSParser *fresh_parser, TSTree *original,
    const char *source, size_t start, const char *replacement) {
  size_t length = strlen(source);
  size_t removed = start < length ? 1 : 0;
  size_t inserted = strlen(replacement);
  size_t new_length = length - removed + inserted;
  char *edited = calloc(new_length + 1, 1);
  assert(edited);
  memcpy(edited, source, start);
  memcpy(edited + start, replacement, inserted);
  memcpy(edited + start + inserted, source + start + removed, length - start - removed);
  TSInputEdit edit = {
    (uint32_t)start, (uint32_t)(start + removed), (uint32_t)(start + inserted),
    point_at(source, start), point_at(source, start + removed),
    point_at(edited, start + inserted),
  };
  TSTree *old = ts_tree_copy(original);
  ts_tree_edit(old, &edit);
  TSTree *incremental = ts_parser_parse_string(parser, old, edited, (uint32_t)new_length);
  TSTree *fresh = ts_parser_parse_string(fresh_parser, NULL, edited, (uint32_t)new_length);
  char *actual = ts_node_string(ts_tree_root_node(incremental));
  char *expected = ts_node_string(ts_tree_root_node(fresh));
  // Compare fields, anonymous nodes, and ranges. Some edits damage
  // delimiters, so the comparison also checks error recovery.
  if (strcmp(actual, expected) ||
      !same_nodes(ts_tree_root_node(incremental), ts_tree_root_node(fresh))) {
    fprintf(stderr, "Incremental mismatch at byte %zu, replacement '%s':\n%s\n%s\n",
            start, replacement, actual, expected);
    exit(1);
  }
  free(actual);
  free(expected);
  free(edited);
  ts_tree_delete(old);
  ts_tree_delete(incremental);
  ts_tree_delete(fresh);
}

int main(void) {
  TSParser *parser = ts_parser_new(), *fresh_parser = ts_parser_new();
  assert(ts_parser_set_language(parser, tree_sitter_scheme()));
  assert(ts_parser_set_language(fresh_parser, tree_sitter_scheme()));
  const char *tags[] = {"", "TAG", "#{tag", "終"};
  const char *endings[] = {"\n", "\r\n"};
  const char *replacements[] = {"", "#", "{", "\n", "\r", "λ"};
  unsigned depths[] = {3, 128};
  unsigned checks = 0;
  for (unsigned t = 0; t < 4; t++) {
    for (unsigned e = 0; e < 2; e++) {
      for (unsigned d = 0; d < 2; d++) {
        char source[8192] = "";
        for (unsigned i = 0; i < depths[d]; i++) {
          strcat(source, "#<#");
          strcat(source, tags[t]);
          strcat(source, endings[e]);
          strcat(source, "#(");
        }
        strcat(source, "x");
        strcat(source, endings[e]);
        for (unsigned i = 0; i < depths[d]; i++) {
          strcat(source, ")");
          strcat(source, endings[e]);
          strcat(source, tags[t]);
          strcat(source, endings[e]);
        }
        size_t length = strlen(source);
        TSTree *original = ts_parser_parse_string(parser, NULL, source, (uint32_t)length);
        assert(!ts_node_has_error(ts_tree_root_node(original)));
        // Depth 128 exercises growth of the serialized depth field.
        size_t step = d == 0 ? 1 : length / 30;
        for (size_t pos = 0; pos <= length; pos += step) {
          for (unsigned r = 0; r < 6; r++) {
            check_edit(parser, fresh_parser, original, source, pos, replacements[r]);
            checks++;
          }
        }
        ts_tree_delete(original);
      }
    }
  }
  // The Scheme form after each boundary must remain outside the preceding construct.
  const char *boundaries[] = {
    "#<#\nbody\n\n(+ 1 2)\n",
    "#<#\n#'#<<INNER\nx\nINNER\n\n(+ 3 4)\n",
    "#<#OUTER\n#'#<<INNER\nx\nINNER\nOUTER\n(+ 1 2)\n",
    "#<#OUTER\n#'#<#INNER\nx\nINNER\nOUTER\n(+ 1 2)\n",
    "#<#OUTER\n#'#<#\nx\n\nOUTER\n(+ 1 2)\n",
    "#><<#\n(+ 1 2)\n#>next<#\n(+ 3 4)\n",
  };
  for (unsigned b = 0; b < sizeof(boundaries) / sizeof(*boundaries); b++) {
    const char *source = boundaries[b];
    size_t length = strlen(source);
    TSTree *original = ts_parser_parse_string(parser, NULL, source, (uint32_t)length);
    TSNode root = ts_tree_root_node(original);
    assert(!ts_node_has_error(root));
    TSNode last = ts_node_named_child(root, ts_node_named_child_count(root) - 1);
    assert(!strcmp(ts_node_type(last), "list"));
    for (size_t pos = 0; pos <= length; pos++) {
      for (unsigned r = 0; r < 6; r++) {
        check_edit(parser, fresh_parser, original, source, pos, replacements[r]);
        checks++;
      }
    }
    ts_tree_delete(original);
  }
  ts_parser_delete(parser);
  ts_parser_delete(fresh_parser);
  printf("CHICKEN incremental parsing: %u edits passed\n", checks);
  return 0;
}
