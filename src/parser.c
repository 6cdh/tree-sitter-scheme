#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 17
#define SYMBOL_COUNT 33
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  aux_sym__intertoken_token1 = 1,
  sym_comment = 2,
  sym_boolean = 3,
  sym_number = 4,
  sym_character = 5,
  anon_sym_DQUOTE = 6,
  aux_sym_string_token1 = 7,
  sym_escape_sequence = 8,
  sym_symbol = 9,
  anon_sym_LPAREN = 10,
  anon_sym_RPAREN = 11,
  sym_dot = 12,
  anon_sym_POUND_LPAREN = 13,
  anon_sym_SQUOTE = 14,
  anon_sym_BQUOTE = 15,
  anon_sym_COMMA = 16,
  anon_sym_COMMA_AT = 17,
  sym_program = 18,
  sym__token = 19,
  sym__intertoken = 20,
  sym__datum = 21,
  sym_string = 22,
  sym_list = 23,
  sym_vector = 24,
  sym_quote = 25,
  sym_quasiquote = 26,
  sym_unquote = 27,
  sym_unquote_splicing = 28,
  aux_sym_program_repeat1 = 29,
  aux_sym_string_repeat1 = 30,
  aux_sym_list_repeat1 = 31,
  aux_sym_quote_repeat1 = 32,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__intertoken_token1] = "_intertoken_token1",
  [sym_comment] = "comment",
  [sym_boolean] = "boolean",
  [sym_number] = "number",
  [sym_character] = "character",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [sym_escape_sequence] = "escape_sequence",
  [sym_symbol] = "symbol",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_dot] = "dot",
  [anon_sym_POUND_LPAREN] = "#(",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_COMMA] = ",",
  [anon_sym_COMMA_AT] = ",@",
  [sym_program] = "program",
  [sym__token] = "_token",
  [sym__intertoken] = "_intertoken",
  [sym__datum] = "_datum",
  [sym_string] = "string",
  [sym_list] = "list",
  [sym_vector] = "vector",
  [sym_quote] = "quote",
  [sym_quasiquote] = "quasiquote",
  [sym_unquote] = "unquote",
  [sym_unquote_splicing] = "unquote_splicing",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_list_repeat1] = "list_repeat1",
  [aux_sym_quote_repeat1] = "quote_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__intertoken_token1] = aux_sym__intertoken_token1,
  [sym_comment] = sym_comment,
  [sym_boolean] = sym_boolean,
  [sym_number] = sym_number,
  [sym_character] = sym_character,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_symbol] = sym_symbol,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_dot] = sym_dot,
  [anon_sym_POUND_LPAREN] = anon_sym_POUND_LPAREN,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_COMMA_AT] = anon_sym_COMMA_AT,
  [sym_program] = sym_program,
  [sym__token] = sym__token,
  [sym__intertoken] = sym__intertoken,
  [sym__datum] = sym__datum,
  [sym_string] = sym_string,
  [sym_list] = sym_list,
  [sym_vector] = sym_vector,
  [sym_quote] = sym_quote,
  [sym_quasiquote] = sym_quasiquote,
  [sym_unquote] = sym_unquote,
  [sym_unquote_splicing] = sym_unquote_splicing,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_list_repeat1] = aux_sym_list_repeat1,
  [aux_sym_quote_repeat1] = aux_sym_quote_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__intertoken_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_character] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_dot] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUND_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA_AT] = {
    .visible = true,
    .named = false,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym__token] = {
    .visible = false,
    .named = true,
  },
  [sym__intertoken] = {
    .visible = false,
    .named = true,
  },
  [sym__datum] = {
    .visible = false,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_list] = {
    .visible = true,
    .named = true,
  },
  [sym_vector] = {
    .visible = true,
    .named = true,
  },
  [sym_quote] = {
    .visible = true,
    .named = true,
  },
  [sym_quasiquote] = {
    .visible = true,
    .named = true,
  },
  [sym_unquote] = {
    .visible = true,
    .named = true,
  },
  [sym_unquote_splicing] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quote_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
};

static TSCharacterRange sym_symbol_character_set_1[] = {
  {'!', '!'}, {'$', '&'}, {'*', '+'}, {'-', '/'}, {':', ':'}, {'<', '?'}, {'A', 'Z'}, {'^', '_'},
  {'a', 'z'}, {'~', '~'},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(87);
      ADVANCE_MAP(
        '"', 149,
        '#', 22,
        '\'', 159,
        '(', 155,
        ')', 156,
        ',', 161,
        '.', 157,
        ';', 89,
        '\\', 29,
        '`', 160,
        '+', 153,
        '-', 153,
        '\n', 88,
        '\r', 88,
        ' ', 88,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (('!' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('^' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(154);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(149);
      if (lookahead == '\\') ADVANCE(29);
      if (lookahead != 0) ADVANCE(150);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(61);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(44);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(99);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(41);
      if (lookahead == '.') ADVANCE(70);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(5);
      if (lookahead == '.') ADVANCE(7);
      if (lookahead == '/') ADVANCE(80);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(5);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '/') ADVANCE(80);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(39);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(6);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(39);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(6);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(8);
      if (lookahead == '/') ADVANCE(60);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 9:
      if (lookahead == '#') ADVANCE(8);
      if (lookahead == '/') ADVANCE(60);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 11:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(64);
      if (lookahead == '.') ADVANCE(70);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == '/') ADVANCE(69);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == '/') ADVANCE(69);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(62);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(120);
      END_STATE();
    case 19:
      if (lookahead == '#') ADVANCE(19);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 20:
      if (lookahead == '#') ADVANCE(19);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == '#') ADVANCE(63);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      END_STATE();
    case 22:
      ADVANCE_MAP(
        '(', 158,
        '\\', 53,
        'B', 2,
        'b', 2,
        'D', 15,
        'd', 15,
        'O', 18,
        'o', 18,
        'X', 21,
        'x', 21,
        'E', 3,
        'I', 3,
        'e', 3,
        'i', 3,
        'F', 90,
        'T', 90,
        'f', 90,
        't', 90,
      );
      END_STATE();
    case 23:
      if (lookahead == '.') ADVANCE(71);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 24:
      if (lookahead == '.') ADVANCE(152);
      END_STATE();
    case 25:
      if (lookahead == '.') ADVANCE(70);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 26:
      if (lookahead == '.') ADVANCE(76);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(104);
      END_STATE();
    case 27:
      if (lookahead == '.') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(104);
      END_STATE();
    case 28:
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(4);
      END_STATE();
    case 29:
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(151);
      END_STATE();
    case 30:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(44);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(99);
      END_STATE();
    case 31:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(120);
      END_STATE();
    case 32:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      END_STATE();
    case 33:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(57);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(113);
      END_STATE();
    case 34:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      END_STATE();
    case 35:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(138);
      END_STATE();
    case 36:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 37:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 38:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      END_STATE();
    case 39:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      END_STATE();
    case 40:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(42);
      END_STATE();
    case 41:
      ADVANCE_MAP(
        'B', 30,
        'b', 30,
        'D', 25,
        'd', 25,
        'O', 31,
        'o', 31,
        'X', 32,
        'x', 32,
      );
      END_STATE();
    case 42:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(43);
      END_STATE();
    case 43:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(146);
      END_STATE();
    case 44:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(107);
      END_STATE();
    case 45:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(9);
      END_STATE();
    case 46:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(124);
      END_STATE();
    case 47:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(17);
      END_STATE();
    case 48:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      END_STATE();
    case 49:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(134);
      END_STATE();
    case 50:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 51:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(54);
      END_STATE();
    case 52:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(51);
      END_STATE();
    case 53:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(147);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(148);
      if (lookahead != 0) ADVANCE(146);
      END_STATE();
    case 54:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 55:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(52);
      END_STATE();
    case 56:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(122);
      END_STATE();
    case 57:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(113);
      END_STATE();
    case 58:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(126);
      END_STATE();
    case 59:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(115);
      END_STATE();
    case 60:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(11);
      END_STATE();
    case 61:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 62:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 63:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 64:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(25);
      END_STATE();
    case 65:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(132);
      END_STATE();
    case 66:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      END_STATE();
    case 67:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(136);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(116);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(12);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      END_STATE();
    case 72:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 73:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(109);
      END_STATE();
    case 75:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 76:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);
      END_STATE();
    case 77:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 78:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(117);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 81:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      END_STATE();
    case 82:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(140);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(138);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(142);
      END_STATE();
    case 85:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(118);
      END_STATE();
    case 86:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(14);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_boolean);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_number);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '.') ADVANCE(95);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '.') ADVANCE(94);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(36);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(94);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(36);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(94);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 97,
        '.', 101,
        '/', 74,
        '@', 26,
        '+', 28,
        '-', 28,
        'I', 91,
        'i', 91,
      );
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 97,
        '.', 100,
        '/', 74,
        '@', 26,
        '+', 28,
        '-', 28,
        'I', 91,
        'i', 91,
      );
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(37);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(98);
      if (lookahead == '/') ADVANCE(56);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(98);
      if (lookahead == '/') ADVANCE(56);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(100);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(37);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(100);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(102);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(102);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(105);
      if (lookahead == '.') ADVANCE(111);
      if (lookahead == '/') ADVANCE(78);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(104);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(105);
      if (lookahead == '.') ADVANCE(110);
      if (lookahead == '/') ADVANCE(78);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(38);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '/') ADVANCE(58);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 106,
        '/', 58,
        '@', 33,
        '+', 45,
        '-', 45,
        'I', 91,
        'i', 91,
        '0', 107,
        '1', 107,
      );
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(108);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(108);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(109);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(110);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(38);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(110);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(111);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(112);
      if (lookahead == '/') ADVANCE(59);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(112);
      if (lookahead == '/') ADVANCE(59);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(113);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(114);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(114);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(115);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(117);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(118);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(119);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(119);
      if (lookahead == '/') ADVANCE(65);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(121);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(121);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(122);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(123);
      if (lookahead == '/') ADVANCE(67);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(123);
      if (lookahead == '/') ADVANCE(67);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(125);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(125);
      if (lookahead == '@') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(127);
      if (lookahead == '/') ADVANCE(68);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(127);
      if (lookahead == '/') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(129);
      if (lookahead == '/') ADVANCE(82);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(129);
      if (lookahead == '/') ADVANCE(82);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(131);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(131);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(133);
      if (lookahead == '/') ADVANCE(84);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(133);
      if (lookahead == '/') ADVANCE(84);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(135);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(135);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(47);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(137);
      if (lookahead == '/') ADVANCE(85);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(137);
      if (lookahead == '/') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(139);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(139);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(141);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(141);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_character);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(40);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(150);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_symbol);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(71);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_symbol);
      if (set_contains(sym_symbol_character_set_1, 10, lookahead) ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '@') ADVANCE(154);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_dot);
      if (lookahead == '.') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_POUND_LPAREN);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '@') ADVANCE(162);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_COMMA_AT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__intertoken_token1] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_boolean] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_character] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_dot] = ACTIONS(1),
    [anon_sym_POUND_LPAREN] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_COMMA_AT] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(35),
    [sym__token] = STATE(8),
    [sym__intertoken] = STATE(8),
    [sym__datum] = STATE(8),
    [sym_string] = STATE(8),
    [sym_list] = STATE(8),
    [sym_vector] = STATE(8),
    [sym_quote] = STATE(8),
    [sym_quasiquote] = STATE(8),
    [sym_unquote] = STATE(8),
    [sym_unquote_splicing] = STATE(8),
    [aux_sym_program_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__intertoken_token1] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [sym_boolean] = ACTIONS(5),
    [sym_number] = ACTIONS(5),
    [sym_character] = ACTIONS(5),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(9),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [2] = {
    [sym__token] = STATE(3),
    [sym__intertoken] = STATE(3),
    [sym__datum] = STATE(3),
    [sym_string] = STATE(3),
    [sym_list] = STATE(3),
    [sym_vector] = STATE(3),
    [sym_quote] = STATE(3),
    [sym_quasiquote] = STATE(3),
    [sym_unquote] = STATE(3),
    [sym_unquote_splicing] = STATE(3),
    [aux_sym_list_repeat1] = STATE(3),
    [aux_sym__intertoken_token1] = ACTIONS(23),
    [sym_comment] = ACTIONS(23),
    [sym_boolean] = ACTIONS(23),
    [sym_number] = ACTIONS(23),
    [sym_character] = ACTIONS(23),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(25),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(27),
    [sym_dot] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [3] = {
    [sym__token] = STATE(5),
    [sym__intertoken] = STATE(5),
    [sym__datum] = STATE(5),
    [sym_string] = STATE(5),
    [sym_list] = STATE(5),
    [sym_vector] = STATE(5),
    [sym_quote] = STATE(5),
    [sym_quasiquote] = STATE(5),
    [sym_unquote] = STATE(5),
    [sym_unquote_splicing] = STATE(5),
    [aux_sym_list_repeat1] = STATE(5),
    [aux_sym__intertoken_token1] = ACTIONS(29),
    [sym_comment] = ACTIONS(29),
    [sym_boolean] = ACTIONS(29),
    [sym_number] = ACTIONS(29),
    [sym_character] = ACTIONS(29),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(33),
    [sym_dot] = ACTIONS(31),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [4] = {
    [sym__token] = STATE(4),
    [sym__intertoken] = STATE(4),
    [sym__datum] = STATE(4),
    [sym_string] = STATE(4),
    [sym_list] = STATE(4),
    [sym_vector] = STATE(4),
    [sym_quote] = STATE(4),
    [sym_quasiquote] = STATE(4),
    [sym_unquote] = STATE(4),
    [sym_unquote_splicing] = STATE(4),
    [aux_sym_program_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(35),
    [aux_sym__intertoken_token1] = ACTIONS(37),
    [sym_comment] = ACTIONS(37),
    [sym_boolean] = ACTIONS(37),
    [sym_number] = ACTIONS(37),
    [sym_character] = ACTIONS(37),
    [anon_sym_DQUOTE] = ACTIONS(40),
    [sym_symbol] = ACTIONS(43),
    [anon_sym_LPAREN] = ACTIONS(46),
    [anon_sym_RPAREN] = ACTIONS(35),
    [anon_sym_POUND_LPAREN] = ACTIONS(49),
    [anon_sym_SQUOTE] = ACTIONS(52),
    [anon_sym_BQUOTE] = ACTIONS(55),
    [anon_sym_COMMA] = ACTIONS(58),
    [anon_sym_COMMA_AT] = ACTIONS(61),
  },
  [5] = {
    [sym__token] = STATE(5),
    [sym__intertoken] = STATE(5),
    [sym__datum] = STATE(5),
    [sym_string] = STATE(5),
    [sym_list] = STATE(5),
    [sym_vector] = STATE(5),
    [sym_quote] = STATE(5),
    [sym_quasiquote] = STATE(5),
    [sym_unquote] = STATE(5),
    [sym_unquote_splicing] = STATE(5),
    [aux_sym_list_repeat1] = STATE(5),
    [aux_sym__intertoken_token1] = ACTIONS(64),
    [sym_comment] = ACTIONS(64),
    [sym_boolean] = ACTIONS(64),
    [sym_number] = ACTIONS(64),
    [sym_character] = ACTIONS(64),
    [anon_sym_DQUOTE] = ACTIONS(67),
    [sym_symbol] = ACTIONS(70),
    [anon_sym_LPAREN] = ACTIONS(73),
    [anon_sym_RPAREN] = ACTIONS(76),
    [sym_dot] = ACTIONS(70),
    [anon_sym_POUND_LPAREN] = ACTIONS(78),
    [anon_sym_SQUOTE] = ACTIONS(81),
    [anon_sym_BQUOTE] = ACTIONS(84),
    [anon_sym_COMMA] = ACTIONS(87),
    [anon_sym_COMMA_AT] = ACTIONS(90),
  },
  [6] = {
    [sym__token] = STATE(4),
    [sym__intertoken] = STATE(4),
    [sym__datum] = STATE(4),
    [sym_string] = STATE(4),
    [sym_list] = STATE(4),
    [sym_vector] = STATE(4),
    [sym_quote] = STATE(4),
    [sym_quasiquote] = STATE(4),
    [sym_unquote] = STATE(4),
    [sym_unquote_splicing] = STATE(4),
    [aux_sym_program_repeat1] = STATE(4),
    [aux_sym__intertoken_token1] = ACTIONS(93),
    [sym_comment] = ACTIONS(93),
    [sym_boolean] = ACTIONS(93),
    [sym_number] = ACTIONS(93),
    [sym_character] = ACTIONS(93),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(95),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(97),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [7] = {
    [sym__token] = STATE(6),
    [sym__intertoken] = STATE(6),
    [sym__datum] = STATE(6),
    [sym_string] = STATE(6),
    [sym_list] = STATE(6),
    [sym_vector] = STATE(6),
    [sym_quote] = STATE(6),
    [sym_quasiquote] = STATE(6),
    [sym_unquote] = STATE(6),
    [sym_unquote_splicing] = STATE(6),
    [aux_sym_program_repeat1] = STATE(6),
    [aux_sym__intertoken_token1] = ACTIONS(99),
    [sym_comment] = ACTIONS(99),
    [sym_boolean] = ACTIONS(99),
    [sym_number] = ACTIONS(99),
    [sym_character] = ACTIONS(99),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(101),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(103),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [8] = {
    [sym__token] = STATE(4),
    [sym__intertoken] = STATE(4),
    [sym__datum] = STATE(4),
    [sym_string] = STATE(4),
    [sym_list] = STATE(4),
    [sym_vector] = STATE(4),
    [sym_quote] = STATE(4),
    [sym_quasiquote] = STATE(4),
    [sym_unquote] = STATE(4),
    [sym_unquote_splicing] = STATE(4),
    [aux_sym_program_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(105),
    [aux_sym__intertoken_token1] = ACTIONS(93),
    [sym_comment] = ACTIONS(93),
    [sym_boolean] = ACTIONS(93),
    [sym_number] = ACTIONS(93),
    [sym_character] = ACTIONS(93),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(95),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [9] = {
    [sym__intertoken] = STATE(15),
    [sym__datum] = STATE(24),
    [sym_string] = STATE(24),
    [sym_list] = STATE(24),
    [sym_vector] = STATE(24),
    [sym_quote] = STATE(24),
    [sym_quasiquote] = STATE(24),
    [sym_unquote] = STATE(24),
    [sym_unquote_splicing] = STATE(24),
    [aux_sym_quote_repeat1] = STATE(15),
    [aux_sym__intertoken_token1] = ACTIONS(107),
    [sym_comment] = ACTIONS(107),
    [sym_boolean] = ACTIONS(109),
    [sym_number] = ACTIONS(109),
    [sym_character] = ACTIONS(109),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(111),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [10] = {
    [sym__intertoken] = STATE(14),
    [sym__datum] = STATE(22),
    [sym_string] = STATE(22),
    [sym_list] = STATE(22),
    [sym_vector] = STATE(22),
    [sym_quote] = STATE(22),
    [sym_quasiquote] = STATE(22),
    [sym_unquote] = STATE(22),
    [sym_unquote_splicing] = STATE(22),
    [aux_sym_quote_repeat1] = STATE(14),
    [aux_sym__intertoken_token1] = ACTIONS(113),
    [sym_comment] = ACTIONS(113),
    [sym_boolean] = ACTIONS(115),
    [sym_number] = ACTIONS(115),
    [sym_character] = ACTIONS(115),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(117),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [11] = {
    [sym__intertoken] = STATE(31),
    [sym__datum] = STATE(26),
    [sym_string] = STATE(26),
    [sym_list] = STATE(26),
    [sym_vector] = STATE(26),
    [sym_quote] = STATE(26),
    [sym_quasiquote] = STATE(26),
    [sym_unquote] = STATE(26),
    [sym_unquote_splicing] = STATE(26),
    [aux_sym_quote_repeat1] = STATE(31),
    [aux_sym__intertoken_token1] = ACTIONS(119),
    [sym_comment] = ACTIONS(119),
    [sym_boolean] = ACTIONS(121),
    [sym_number] = ACTIONS(121),
    [sym_character] = ACTIONS(121),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(123),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [12] = {
    [sym__intertoken] = STATE(31),
    [sym__datum] = STATE(28),
    [sym_string] = STATE(28),
    [sym_list] = STATE(28),
    [sym_vector] = STATE(28),
    [sym_quote] = STATE(28),
    [sym_quasiquote] = STATE(28),
    [sym_unquote] = STATE(28),
    [sym_unquote_splicing] = STATE(28),
    [aux_sym_quote_repeat1] = STATE(31),
    [aux_sym__intertoken_token1] = ACTIONS(119),
    [sym_comment] = ACTIONS(119),
    [sym_boolean] = ACTIONS(125),
    [sym_number] = ACTIONS(125),
    [sym_character] = ACTIONS(125),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(127),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [13] = {
    [sym__intertoken] = STATE(11),
    [sym__datum] = STATE(21),
    [sym_string] = STATE(21),
    [sym_list] = STATE(21),
    [sym_vector] = STATE(21),
    [sym_quote] = STATE(21),
    [sym_quasiquote] = STATE(21),
    [sym_unquote] = STATE(21),
    [sym_unquote_splicing] = STATE(21),
    [aux_sym_quote_repeat1] = STATE(11),
    [aux_sym__intertoken_token1] = ACTIONS(129),
    [sym_comment] = ACTIONS(129),
    [sym_boolean] = ACTIONS(131),
    [sym_number] = ACTIONS(131),
    [sym_character] = ACTIONS(131),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(133),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [14] = {
    [sym__intertoken] = STATE(31),
    [sym__datum] = STATE(29),
    [sym_string] = STATE(29),
    [sym_list] = STATE(29),
    [sym_vector] = STATE(29),
    [sym_quote] = STATE(29),
    [sym_quasiquote] = STATE(29),
    [sym_unquote] = STATE(29),
    [sym_unquote_splicing] = STATE(29),
    [aux_sym_quote_repeat1] = STATE(31),
    [aux_sym__intertoken_token1] = ACTIONS(119),
    [sym_comment] = ACTIONS(119),
    [sym_boolean] = ACTIONS(135),
    [sym_number] = ACTIONS(135),
    [sym_character] = ACTIONS(135),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(137),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [15] = {
    [sym__intertoken] = STATE(31),
    [sym__datum] = STATE(30),
    [sym_string] = STATE(30),
    [sym_list] = STATE(30),
    [sym_vector] = STATE(30),
    [sym_quote] = STATE(30),
    [sym_quasiquote] = STATE(30),
    [sym_unquote] = STATE(30),
    [sym_unquote_splicing] = STATE(30),
    [aux_sym_quote_repeat1] = STATE(31),
    [aux_sym__intertoken_token1] = ACTIONS(119),
    [sym_comment] = ACTIONS(119),
    [sym_boolean] = ACTIONS(139),
    [sym_number] = ACTIONS(139),
    [sym_character] = ACTIONS(139),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(141),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
  [16] = {
    [sym__intertoken] = STATE(12),
    [sym__datum] = STATE(20),
    [sym_string] = STATE(20),
    [sym_list] = STATE(20),
    [sym_vector] = STATE(20),
    [sym_quote] = STATE(20),
    [sym_quasiquote] = STATE(20),
    [sym_unquote] = STATE(20),
    [sym_unquote_splicing] = STATE(20),
    [aux_sym_quote_repeat1] = STATE(12),
    [aux_sym__intertoken_token1] = ACTIONS(143),
    [sym_comment] = ACTIONS(143),
    [sym_boolean] = ACTIONS(145),
    [sym_number] = ACTIONS(145),
    [sym_character] = ACTIONS(145),
    [anon_sym_DQUOTE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(147),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_POUND_LPAREN] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(19),
    [anon_sym_COMMA_AT] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(151), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(149), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [21] = 2,
    ACTIONS(155), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(153), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [42] = 2,
    ACTIONS(159), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(157), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [63] = 2,
    ACTIONS(163), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(161), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [84] = 2,
    ACTIONS(167), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(165), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [105] = 2,
    ACTIONS(171), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(169), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [126] = 2,
    ACTIONS(175), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(173), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [147] = 2,
    ACTIONS(179), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(177), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [168] = 2,
    ACTIONS(183), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(181), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [189] = 2,
    ACTIONS(187), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(185), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [210] = 2,
    ACTIONS(191), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(189), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [231] = 2,
    ACTIONS(195), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(193), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [252] = 2,
    ACTIONS(199), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(197), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [273] = 2,
    ACTIONS(203), 3,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
    ACTIONS(201), 13,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [294] = 4,
    ACTIONS(205), 2,
      aux_sym__intertoken_token1,
      sym_comment,
    ACTIONS(210), 2,
      sym_symbol,
      anon_sym_COMMA,
    STATE(31), 2,
      sym__intertoken,
      aux_sym_quote_repeat1,
    ACTIONS(208), 9,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_POUND_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
  [318] = 3,
    ACTIONS(212), 1,
      anon_sym_DQUOTE,
    STATE(34), 1,
      aux_sym_string_repeat1,
    ACTIONS(214), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [329] = 3,
    ACTIONS(216), 1,
      anon_sym_DQUOTE,
    STATE(32), 1,
      aux_sym_string_repeat1,
    ACTIONS(218), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [340] = 3,
    ACTIONS(220), 1,
      anon_sym_DQUOTE,
    STATE(34), 1,
      aux_sym_string_repeat1,
    ACTIONS(222), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [351] = 1,
    ACTIONS(225), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(17)] = 0,
  [SMALL_STATE(18)] = 21,
  [SMALL_STATE(19)] = 42,
  [SMALL_STATE(20)] = 63,
  [SMALL_STATE(21)] = 84,
  [SMALL_STATE(22)] = 105,
  [SMALL_STATE(23)] = 126,
  [SMALL_STATE(24)] = 147,
  [SMALL_STATE(25)] = 168,
  [SMALL_STATE(26)] = 189,
  [SMALL_STATE(27)] = 210,
  [SMALL_STATE(28)] = 231,
  [SMALL_STATE(29)] = 252,
  [SMALL_STATE(30)] = 273,
  [SMALL_STATE(31)] = 294,
  [SMALL_STATE(32)] = 318,
  [SMALL_STATE(33)] = 329,
  [SMALL_STATE(34)] = 340,
  [SMALL_STATE(35)] = 351,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 2, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 2, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 2, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 2, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 2, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 2, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 2, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 3, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 3, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 3, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 3, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 3, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 3, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 3, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [205] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quote_repeat1, 2, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quote_repeat1, 2, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [222] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [225] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_scheme(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
