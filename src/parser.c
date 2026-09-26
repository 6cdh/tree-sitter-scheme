#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 154
#define LARGE_STATE_COUNT 53
#define SYMBOL_COUNT 75
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  aux_sym__intertoken_token1 = 1,
  sym_comment = 2,
  anon_sym_POUND_PIPE = 3,
  aux_sym_block_comment_token1 = 4,
  anon_sym_PIPE_POUND = 5,
  anon_sym_POUND_SEMI = 6,
  anon_sym_POUND_BANG = 7,
  aux_sym_directive_token1 = 8,
  aux_sym_directive_token2 = 9,
  anon_sym_POUND = 10,
  aux_sym_boolean_token1 = 11,
  aux_sym_boolean_token2 = 12,
  sym_number = 13,
  anon_sym_POUND_BSLASH = 14,
  aux_sym_character_token1 = 15,
  aux_sym_character_token2 = 16,
  aux_sym_character_token3 = 17,
  aux_sym_character_token4 = 18,
  anon_sym_DQUOTE = 19,
  aux_sym_string_token1 = 20,
  anon_sym_BSLASH = 21,
  aux_sym_escape_sequence_token1 = 22,
  aux_sym_escape_sequence_token2 = 23,
  aux_sym_escape_sequence_token3 = 24,
  sym_symbol = 25,
  sym_keyword = 26,
  anon_sym_LPAREN = 27,
  anon_sym_RPAREN = 28,
  anon_sym_LBRACK = 29,
  anon_sym_RBRACK = 30,
  sym_dot = 31,
  anon_sym_POUND_LPAREN = 32,
  anon_sym_POUNDvu8_LPAREN = 33,
  anon_sym_POUNDu8_LPAREN = 34,
  anon_sym_SQUOTE = 35,
  anon_sym_BQUOTE = 36,
  anon_sym_COMMA = 37,
  anon_sym_COMMA_AT = 38,
  anon_sym_POUND_SQUOTE = 39,
  anon_sym_POUND_BQUOTE = 40,
  anon_sym_POUND_COMMA = 41,
  anon_sym_POUND_COMMA_AT = 42,
  aux_sym_datum_label_token1 = 43,
  anon_sym_EQ = 44,
  sym_program = 45,
  sym__token = 46,
  sym__intertoken = 47,
  sym__datum = 48,
  sym_block_comment = 49,
  sym_sexp_comment = 50,
  sym_directive = 51,
  sym_boolean = 52,
  sym_character = 53,
  sym_string = 54,
  sym_escape_sequence = 55,
  sym_list = 56,
  sym_vector = 57,
  sym_byte_vector = 58,
  sym_quote = 59,
  sym_quasiquote = 60,
  sym_unquote = 61,
  sym_unquote_splicing = 62,
  sym_syntax_quote = 63,
  sym_quasisyntax = 64,
  sym_unsyntax = 65,
  sym_unsyntax_splicing = 66,
  sym_datum_label = 67,
  sym_datum_reference = 68,
  aux_sym_program_repeat1 = 69,
  aux_sym_block_comment_repeat1 = 70,
  aux_sym_sexp_comment_repeat1 = 71,
  aux_sym_string_repeat1 = 72,
  aux_sym_list_repeat1 = 73,
  aux_sym_byte_vector_repeat1 = 74,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__intertoken_token1] = "_intertoken_token1",
  [sym_comment] = "comment",
  [anon_sym_POUND_PIPE] = "#|",
  [aux_sym_block_comment_token1] = "block_comment_token1",
  [anon_sym_PIPE_POUND] = "|#",
  [anon_sym_POUND_SEMI] = "#;",
  [anon_sym_POUND_BANG] = "#!",
  [aux_sym_directive_token1] = "directive_token1",
  [aux_sym_directive_token2] = "directive_token2",
  [anon_sym_POUND] = "#",
  [aux_sym_boolean_token1] = "boolean_token1",
  [aux_sym_boolean_token2] = "boolean_token2",
  [sym_number] = "number",
  [anon_sym_POUND_BSLASH] = "#\\",
  [aux_sym_character_token1] = "character_token1",
  [aux_sym_character_token2] = "character_token2",
  [aux_sym_character_token3] = "character_token3",
  [aux_sym_character_token4] = "character_token4",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_BSLASH] = "\\",
  [aux_sym_escape_sequence_token1] = "escape_sequence_token1",
  [aux_sym_escape_sequence_token2] = "escape_sequence_token2",
  [aux_sym_escape_sequence_token3] = "escape_sequence_token3",
  [sym_symbol] = "symbol",
  [sym_keyword] = "keyword",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_dot] = "dot",
  [anon_sym_POUND_LPAREN] = "#(",
  [anon_sym_POUNDvu8_LPAREN] = "#vu8(",
  [anon_sym_POUNDu8_LPAREN] = "#u8(",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_COMMA] = ",",
  [anon_sym_COMMA_AT] = ",@",
  [anon_sym_POUND_SQUOTE] = "#'",
  [anon_sym_POUND_BQUOTE] = "#`",
  [anon_sym_POUND_COMMA] = "#,",
  [anon_sym_POUND_COMMA_AT] = "#,@",
  [aux_sym_datum_label_token1] = "datum_label_id",
  [anon_sym_EQ] = "=",
  [sym_program] = "program",
  [sym__token] = "_token",
  [sym__intertoken] = "_intertoken",
  [sym__datum] = "_datum",
  [sym_block_comment] = "block_comment",
  [sym_sexp_comment] = "sexp_comment",
  [sym_directive] = "directive",
  [sym_boolean] = "boolean",
  [sym_character] = "character",
  [sym_string] = "string",
  [sym_escape_sequence] = "escape_sequence",
  [sym_list] = "list",
  [sym_vector] = "vector",
  [sym_byte_vector] = "byte_vector",
  [sym_quote] = "quote",
  [sym_quasiquote] = "quasiquote",
  [sym_unquote] = "unquote",
  [sym_unquote_splicing] = "unquote_splicing",
  [sym_syntax_quote] = "syntax_quote",
  [sym_quasisyntax] = "quasisyntax",
  [sym_unsyntax] = "unsyntax",
  [sym_unsyntax_splicing] = "unsyntax_splicing",
  [sym_datum_label] = "datum_label",
  [sym_datum_reference] = "datum_reference",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_block_comment_repeat1] = "block_comment_repeat1",
  [aux_sym_sexp_comment_repeat1] = "sexp_comment_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_list_repeat1] = "list_repeat1",
  [aux_sym_byte_vector_repeat1] = "byte_vector_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__intertoken_token1] = aux_sym__intertoken_token1,
  [sym_comment] = sym_comment,
  [anon_sym_POUND_PIPE] = anon_sym_POUND_PIPE,
  [aux_sym_block_comment_token1] = aux_sym_block_comment_token1,
  [anon_sym_PIPE_POUND] = anon_sym_PIPE_POUND,
  [anon_sym_POUND_SEMI] = anon_sym_POUND_SEMI,
  [anon_sym_POUND_BANG] = anon_sym_POUND_BANG,
  [aux_sym_directive_token1] = aux_sym_directive_token1,
  [aux_sym_directive_token2] = aux_sym_directive_token2,
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym_boolean_token1] = aux_sym_boolean_token1,
  [aux_sym_boolean_token2] = aux_sym_boolean_token2,
  [sym_number] = sym_number,
  [anon_sym_POUND_BSLASH] = anon_sym_POUND_BSLASH,
  [aux_sym_character_token1] = aux_sym_character_token1,
  [aux_sym_character_token2] = aux_sym_character_token2,
  [aux_sym_character_token3] = aux_sym_character_token3,
  [aux_sym_character_token4] = aux_sym_character_token4,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [aux_sym_escape_sequence_token1] = aux_sym_escape_sequence_token1,
  [aux_sym_escape_sequence_token2] = aux_sym_escape_sequence_token2,
  [aux_sym_escape_sequence_token3] = aux_sym_escape_sequence_token3,
  [sym_symbol] = sym_symbol,
  [sym_keyword] = sym_keyword,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_dot] = sym_dot,
  [anon_sym_POUND_LPAREN] = anon_sym_POUND_LPAREN,
  [anon_sym_POUNDvu8_LPAREN] = anon_sym_POUNDvu8_LPAREN,
  [anon_sym_POUNDu8_LPAREN] = anon_sym_POUNDu8_LPAREN,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_COMMA_AT] = anon_sym_COMMA_AT,
  [anon_sym_POUND_SQUOTE] = anon_sym_POUND_SQUOTE,
  [anon_sym_POUND_BQUOTE] = anon_sym_POUND_BQUOTE,
  [anon_sym_POUND_COMMA] = anon_sym_POUND_COMMA,
  [anon_sym_POUND_COMMA_AT] = anon_sym_POUND_COMMA_AT,
  [aux_sym_datum_label_token1] = aux_sym_datum_label_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_program] = sym_program,
  [sym__token] = sym__token,
  [sym__intertoken] = sym__intertoken,
  [sym__datum] = sym__datum,
  [sym_block_comment] = sym_block_comment,
  [sym_sexp_comment] = sym_sexp_comment,
  [sym_directive] = sym_directive,
  [sym_boolean] = sym_boolean,
  [sym_character] = sym_character,
  [sym_string] = sym_string,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_list] = sym_list,
  [sym_vector] = sym_vector,
  [sym_byte_vector] = sym_byte_vector,
  [sym_quote] = sym_quote,
  [sym_quasiquote] = sym_quasiquote,
  [sym_unquote] = sym_unquote,
  [sym_unquote_splicing] = sym_unquote_splicing,
  [sym_syntax_quote] = sym_syntax_quote,
  [sym_quasisyntax] = sym_quasisyntax,
  [sym_unsyntax] = sym_unsyntax,
  [sym_unsyntax_splicing] = sym_unsyntax_splicing,
  [sym_datum_label] = sym_datum_label,
  [sym_datum_reference] = sym_datum_reference,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_block_comment_repeat1] = aux_sym_block_comment_repeat1,
  [aux_sym_sexp_comment_repeat1] = aux_sym_sexp_comment_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_list_repeat1] = aux_sym_list_repeat1,
  [aux_sym_byte_vector_repeat1] = aux_sym_byte_vector_repeat1,
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
  [anon_sym_POUND_PIPE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_block_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PIPE_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_directive_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_directive_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_boolean_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_boolean_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUND_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_character_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_character_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_character_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_character_token4] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_escape_sequence_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_escape_sequence_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_escape_sequence_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_keyword] = {
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
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
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
  [anon_sym_POUNDvu8_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUNDu8_LPAREN] = {
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
  [anon_sym_POUND_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_COMMA_AT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_datum_label_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
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
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_sexp_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_character] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
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
  [sym_byte_vector] = {
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
  [sym_syntax_quote] = {
    .visible = true,
    .named = true,
  },
  [sym_quasisyntax] = {
    .visible = true,
    .named = true,
  },
  [sym_unsyntax] = {
    .visible = true,
    .named = true,
  },
  [sym_unsyntax_splicing] = {
    .visible = true,
    .named = true,
  },
  [sym_datum_label] = {
    .visible = true,
    .named = true,
  },
  [sym_datum_reference] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_comment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_sexp_comment_repeat1] = {
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
  [aux_sym_byte_vector_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_label = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_label] = "label",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_label, 1},
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
  [6] = 5,
  [7] = 7,
  [8] = 8,
  [9] = 7,
  [10] = 4,
  [11] = 3,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 13,
  [16] = 12,
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
  [31] = 17,
  [32] = 25,
  [33] = 26,
  [34] = 27,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 18,
  [39] = 19,
  [40] = 20,
  [41] = 21,
  [42] = 22,
  [43] = 23,
  [44] = 24,
  [45] = 35,
  [46] = 28,
  [47] = 36,
  [48] = 29,
  [49] = 30,
  [50] = 50,
  [51] = 37,
  [52] = 50,
  [53] = 53,
  [54] = 53,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 90,
  [92] = 92,
  [93] = 93,
  [94] = 92,
  [95] = 59,
  [96] = 75,
  [97] = 76,
  [98] = 78,
  [99] = 79,
  [100] = 89,
  [101] = 80,
  [102] = 81,
  [103] = 77,
  [104] = 82,
  [105] = 83,
  [106] = 85,
  [107] = 86,
  [108] = 88,
  [109] = 58,
  [110] = 60,
  [111] = 61,
  [112] = 62,
  [113] = 64,
  [114] = 65,
  [115] = 66,
  [116] = 67,
  [117] = 68,
  [118] = 69,
  [119] = 56,
  [120] = 71,
  [121] = 72,
  [122] = 73,
  [123] = 74,
  [124] = 84,
  [125] = 57,
  [126] = 63,
  [127] = 70,
  [128] = 87,
  [129] = 129,
  [130] = 130,
  [131] = 130,
  [132] = 132,
  [133] = 133,
  [134] = 133,
  [135] = 132,
  [136] = 129,
  [137] = 133,
  [138] = 130,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 141,
  [143] = 57,
  [144] = 144,
  [145] = 145,
  [146] = 144,
  [147] = 147,
  [148] = 84,
  [149] = 149,
  [150] = 149,
  [151] = 151,
  [152] = 152,
  [153] = 152,
};

static TSCharacterRange aux_sym__intertoken_token1_character_set_1[] = {
  {'\t', '\r'}, {' ', ' '}, {0x85, 0x85}, {0xa0, 0xa0}, {0x1680, 0x1680}, {0x2000, 0x200a}, {0x2028, 0x2029}, {0x202f, 0x202f},
  {0x205f, 0x205f}, {0x3000, 0x3000},
};

static TSCharacterRange aux_sym_escape_sequence_token1_character_set_2[] = {
  {'\t', '\n'}, {' ', ' '}, {0x85, 0x85}, {0xa0, 0xa0}, {0x1680, 0x1680}, {0x2000, 0x200a}, {0x202f, 0x202f}, {0x205f, 0x205f},
  {0x3000, 0x3000},
};

static TSCharacterRange aux_sym_escape_sequence_token1_character_set_3[] = {
  {'\t', '\n'}, {'\r', '\r'}, {' ', ' '}, {0x85, 0x85}, {0xa0, 0xa0}, {0x1680, 0x1680}, {0x2000, 0x200a}, {0x2028, 0x2028},
  {0x202f, 0x202f}, {0x205f, 0x205f}, {0x3000, 0x3000},
};

static TSCharacterRange sym_symbol_character_set_1[] = {
  {'!', '!'}, {'$', '&'}, {'*', '+'}, {'-', '/'}, {':', ':'}, {'<', '?'}, {'A', 'Z'}, {'\\', '\\'},
  {'^', '_'}, {'a', 'z'}, {'|', '|'}, {'~', '~'}, {0xa1, 0xaa}, {0xac, 0xac}, {0xae, 0xba}, {0xbc, 0x487},
  {0x48a, 0x5ff}, {0x606, 0x61b}, {0x61d, 0x65f}, {0x66a, 0x6dc}, {0x6de, 0x6ef}, {0x6fa, 0x70e}, {0x710, 0x7bf}, {0x7ca, 0x88f},
  {0x892, 0x8e1}, {0x8e3, 0x902}, {0x904, 0x93a}, {0x93c, 0x93d}, {0x941, 0x948}, {0x94d, 0x94d}, {0x950, 0x965}, {0x970, 0x981},
  {0x984, 0x9bd}, {0x9c1, 0x9c6}, {0x9c9, 0x9ca}, {0x9cd, 0x9d6}, {0x9d8, 0x9e5}, {0x9f0, 0xa02}, {0xa04, 0xa3d}, {0xa41, 0xa65},
  {0xa70, 0xa82}, {0xa84, 0xabd}, {0xac1, 0xac8}, {0xaca, 0xaca}, {0xacd, 0xae5}, {0xaf0, 0xb01}, {0xb04, 0xb3d}, {0xb3f, 0xb3f},
  {0xb41, 0xb46}, {0xb49, 0xb4a}, {0xb4d, 0xb56}, {0xb58, 0xb65}, {0xb70, 0xbbd}, {0xbc0, 0xbc0}, {0xbc3, 0xbc5}, {0xbc9, 0xbc9},
  {0xbcd, 0xbd6}, {0xbd8, 0xbe5}, {0xbf0, 0xc00}, {0xc04, 0xc40}, {0xc45, 0xc65}, {0xc70, 0xc81}, {0xc84, 0xcbd}, {0xcbf, 0xcbf},
  {0xcc5, 0xcc6}, {0xcc9, 0xcc9}, {0xccc, 0xcd4}, {0xcd7, 0xce5}, {0xcf0, 0xcf2}, {0xcf4, 0xd01}, {0xd04, 0xd3d}, {0xd41, 0xd45},
  {0xd49, 0xd49}, {0xd4d, 0xd56}, {0xd58, 0xd65}, {0xd70, 0xd81}, {0xd84, 0xdce}, {0xdd2, 0xdd7}, {0xde0, 0xde5}, {0xdf0, 0xdf1},
  {0xdf4, 0xe4f}, {0xe5a, 0xecf}, {0xeda, 0xf1f}, {0xf2a, 0xf39}, {0xf40, 0xf7e}, {0xf80, 0x102a}, {0x102d, 0x1030}, {0x1032, 0x1037},
  {0x1039, 0x103a}, {0x103d, 0x103f}, {0x104a, 0x1055}, {0x1058, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1082}, {0x1085, 0x1086}, {0x108d, 0x108e},
  {0x109d, 0x167f}, {0x1681, 0x169a}, {0x169d, 0x1714}, {0x1716, 0x1733}, {0x1735, 0x17b5}, {0x17b7, 0x17bd}, {0x17c6, 0x17c6}, {0x17c9, 0x17df},
  {0x17ea, 0x180d}, {0x180f, 0x180f}, {0x181a, 0x1922}, {0x1927, 0x1928}, {0x192c, 0x192f}, {0x1932, 0x1932}, {0x1939, 0x1945}, {0x1950, 0x19cf},
  {0x19da, 0x1a18}, {0x1a1b, 0x1a54}, {0x1a56, 0x1a56}, {0x1a58, 0x1a60}, {0x1a62, 0x1a62}, {0x1a65, 0x1a6c}, {0x1a73, 0x1a7f}, {0x1a8a, 0x1a8f},
  {0x1a9a, 0x1abd}, {0x1abf, 0x1b03}, {0x1b05, 0x1b34}, {0x1b36, 0x1b3a}, {0x1b3c, 0x1b3c}, {0x1b42, 0x1b42}, {0x1b45, 0x1b4f}, {0x1b5a, 0x1b81},
  {0x1b83, 0x1ba0}, {0x1ba2, 0x1ba5}, {0x1ba8, 0x1ba9}, {0x1bab, 0x1baf}, {0x1bba, 0x1be6}, {0x1be8, 0x1be9}, {0x1bed, 0x1bed}, {0x1bef, 0x1bf1},
  {0x1bf4, 0x1c23}, {0x1c2c, 0x1c33}, {0x1c36, 0x1c3f}, {0x1c4a, 0x1c4f}, {0x1c5a, 0x1ce0}, {0x1ce2, 0x1cf6}, {0x1cf8, 0x1fff}, {0x2010, 0x2017},
  {0x2020, 0x2027}, {0x2030, 0x2038}, {0x203b, 0x2044}, {0x2047, 0x205e}, {0x2065, 0x2065}, {0x2070, 0x207c}, {0x207f, 0x208c}, {0x208f, 0x20dc},
  {0x20e1, 0x20e1}, {0x20e5, 0x2307}, {0x230c, 0x2328}, {0x232b, 0x2767}, {0x2776, 0x27c4}, {0x27c7, 0x27e5}, {0x27f0, 0x2982}, {0x2999, 0x29d7},
  {0x29dc, 0x29fb}, {0x29fe, 0x2e01}, {0x2e06, 0x2e08}, {0x2e0b, 0x2e0b}, {0x2e0e, 0x2e1b}, {0x2e1e, 0x2e1f}, {0x2e2a, 0x2e41}, {0x2e43, 0x2e54},
  {0x2e5d, 0x2fff}, {0x3001, 0x3007}, {0x3012, 0x3013}, {0x301c, 0x301c}, {0x3020, 0x302d}, {0x3030, 0xa61f}, {0xa62a, 0xa66f}, {0xa673, 0xa822},
  {0xa825, 0xa826}, {0xa828, 0xa87f}, {0xa882, 0xa8b3}, {0xa8c4, 0xa8cf}, {0xa8da, 0xa8ff}, {0xa90a, 0xa951}, {0xa954, 0xa982}, {0xa984, 0xa9b3},
  {0xa9b6, 0xa9b9}, {0xa9bc, 0xa9bd}, {0xa9c1, 0xa9cf}, {0xa9da, 0xa9ef}, {0xa9fa, 0xaa2e}, {0xaa31, 0xaa32}, {0xaa35, 0xaa4c}, {0xaa4e, 0xaa4f},
  {0xaa5a, 0xaa7a}, {0xaa7c, 0xaa7c}, {0xaa7e, 0xaaea}, {0xaaec, 0xaaed}, {0xaaf0, 0xaaf4}, {0xaaf6, 0xabe2}, {0xabe5, 0xabe5}, {0xabe8, 0xabe8},
  {0xabeb, 0xabeb}, {0xabed, 0xabef}, {0xabfa, 0xfd3d}, {0xfd40, 0xfe16}, {0xfe19, 0xfe34}, {0xfe45, 0xfe46}, {0xfe49, 0xfe58}, {0xfe5f, 0xfefe},
  {0xff00, 0xff07}, {0xff0a, 0xff0f}, {0xff1a, 0xff3a}, {0xff3c, 0xff3c}, {0xff3e, 0xff5a}, {0xff5c, 0xff5c}, {0xff5e, 0xff5e}, {0xff61, 0xff61},
  {0xff64, 0xfff8}, {0xfffc, 0x1049f}, {0x104aa, 0x10ffff},
};

static TSCharacterRange sym_symbol_character_set_2[] = {
  {'!', '!'}, {'$', '&'}, {'*', '+'}, {'-', '/'}, {':', ':'}, {'<', 'Z'}, {'^', '_'}, {'a', 'z'},
  {'~', '~'},
};

static TSCharacterRange sym_symbol_character_set_3[] = {
  {'!', '!'}, {'$', '&'}, {'*', '+'}, {'-', ':'}, {'<', 'Z'}, {'\\', '\\'}, {'^', '_'}, {'a', 'z'},
  {'~', '~'}, {0xa1, 0xaa}, {0xac, 0xac}, {0xae, 0xba}, {0xbc, 0x5ff}, {0x606, 0x61b}, {0x61d, 0x6dc}, {0x6de, 0x70e},
  {0x710, 0x88f}, {0x892, 0x8e1}, {0x8e3, 0xf39}, {0xf3e, 0x167f}, {0x1681, 0x169a}, {0x169d, 0x180d}, {0x180f, 0x1fff}, {0x2010, 0x2017},
  {0x2020, 0x2027}, {0x2030, 0x2038}, {0x203b, 0x2044}, {0x2047, 0x205e}, {0x2065, 0x2065}, {0x2070, 0x207c}, {0x207f, 0x208c}, {0x208f, 0x2307},
  {0x230c, 0x2328}, {0x232b, 0x2767}, {0x2776, 0x27c4}, {0x27c7, 0x27e5}, {0x27f0, 0x2982}, {0x2999, 0x29d7}, {0x29dc, 0x29fb}, {0x29fe, 0x2e01},
  {0x2e06, 0x2e08}, {0x2e0b, 0x2e0b}, {0x2e0e, 0x2e1b}, {0x2e1e, 0x2e1f}, {0x2e2a, 0x2e41}, {0x2e43, 0x2e54}, {0x2e5d, 0x2fff}, {0x3001, 0x3007},
  {0x3012, 0x3013}, {0x301c, 0x301c}, {0x3020, 0xfd3d}, {0xfd40, 0xfe16}, {0xfe19, 0xfe34}, {0xfe45, 0xfe46}, {0xfe49, 0xfe58}, {0xfe5f, 0xfefe},
  {0xff00, 0xff07}, {0xff0a, 0xff3a}, {0xff3c, 0xff3c}, {0xff3e, 0xff5a}, {0xff5c, 0xff5c}, {0xff5e, 0xff5e}, {0xff61, 0xff61}, {0xff64, 0xfff8},
  {0xfffc, 0x10ffff},
};

static TSCharacterRange sym_keyword_character_set_2[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'!', '!'}, {'$', '&'}, {'*', '+'}, {'-', ':'}, {'<', 'Z'}, {'^', '_'},
  {'a', 'z'}, {'~', 0x9f}, {0xa1, 0x167f}, {0x1681, 0x1fff}, {0x200b, 0x2027}, {0x202a, 0x202e}, {0x2030, 0x205e}, {0x2060, 0x2fff},
  {0x3001, 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(284);
      ADVANCE_MAP(
        '\t', 286,
        '"', 430,
        '#', 301,
        '\'', 489,
        '(', 480,
        ')', 481,
        ',', 491,
        '.', 484,
        ';', 288,
        '=', 499,
        '[', 482,
        '\\', 432,
        ']', 483,
        '`', 490,
        '|', 291,
        '\n', 285,
        '\r', 285,
        ' ', 285,
        'F', 290,
        'T', 290,
        'f', 290,
        't', 290,
      );
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(287);
      if (lookahead != 0) ADVANCE(290);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '\t', 286,
        '#', 5,
        ')', 481,
        '.', 238,
        ';', 288,
        'f', 119,
        'n', 120,
        '+', 51,
        '-', 51,
        '\n', 285,
        '\r', 285,
        ' ', 285,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(287);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\n', 435,
        '\r', 434,
        'X', 281,
        'x', 282,
        '\t', 3,
        ' ', 3,
        '"', 433,
        '\\', 433,
        'f', 433,
        'v', 433,
        0x85, 437,
        0x2028, 437,
        'a', 433,
        'b', 433,
        'n', 433,
        'r', 433,
        't', 433,
      );
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(435);
      if (lookahead == '\r') ADVANCE(434);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead == 0x85 ||
          lookahead == 0x2028) ADVANCE(437);
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\r') ADVANCE(436);
      if (lookahead == '\n' ||
          lookahead == 0x85 ||
          lookahead == 0x2028) ADVANCE(437);
      if (set_contains(aux_sym_escape_sequence_token1_character_set_3, 11, lookahead)) ADVANCE(4);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '!', 295,
        ';', 294,
        '|', 289,
        'B', 8,
        'b', 8,
        'D', 27,
        'd', 27,
        'O', 30,
        'o', 30,
        'X', 33,
        'x', 33,
        'E', 9,
        'I', 9,
        'e', 9,
        'i', 9,
      );
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '"', 430,
        '#', 300,
        '\'', 489,
        '(', 480,
        '+', 441,
        ',', 492,
        '-', 440,
        '.', 38,
        '[', 482,
        '\\', 133,
        '`', 490,
        '|', 89,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      if (('!' <= lookahead && lookahead <= '&') ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('^' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(453);
      if (set_contains(sym_symbol_character_set_1, 219, lookahead)) ADVANCE(454);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(430);
      if (lookahead == '\\') ADVANCE(432);
      if (lookahead != 0) ADVANCE(431);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(225);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(198);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(312);
      END_STATE();
    case 9:
      if (lookahead == '#') ADVANCE(167);
      if (lookahead == '.') ADVANCE(238);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '#', 12,
        '.', 14,
        '/', 254,
        '|', 255,
        'E', 159,
        'e', 159,
        'I', 305,
        'i', 305,
        'D', 159,
        'F', 159,
        'L', 159,
        'S', 159,
        'd', 159,
        'f', 159,
        'l', 159,
        's', 159,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(254);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '/') ADVANCE(254);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(156);
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '.') ADVANCE(15);
      if (lookahead == '/') ADVANCE(254);
      if (lookahead == '|') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 14:
      ADVANCE_MAP(
        '#', 16,
        '|', 255,
        'E', 159,
        'e', 159,
        'I', 305,
        'i', 305,
        'D', 159,
        'F', 159,
        'L', 159,
        'S', 159,
        'd', 159,
        'f', 159,
        'l', 159,
        's', 159,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == '|') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(156);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(18);
      if (lookahead == '/') ADVANCE(220);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 19:
      if (lookahead == '#') ADVANCE(18);
      if (lookahead == '/') ADVANCE(220);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(19);
      END_STATE();
    case 20:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 21:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == '#') ADVANCE(292);
      if (lookahead == '|') ADVANCE(291);
      if (lookahead != 0) ADVANCE(290);
      END_STATE();
    case 26:
      if (lookahead == '#') ADVANCE(298);
      if (lookahead == '=') ADVANCE(499);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(303);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(498);
      END_STATE();
    case 27:
      if (lookahead == '#') ADVANCE(228);
      if (lookahead == '.') ADVANCE(238);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 28:
      if (lookahead == '#') ADVANCE(28);
      if (lookahead == '/') ADVANCE(233);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 29:
      if (lookahead == '#') ADVANCE(28);
      if (lookahead == '/') ADVANCE(233);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      END_STATE();
    case 30:
      if (lookahead == '#') ADVANCE(226);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(339);
      END_STATE();
    case 31:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '/') ADVANCE(274);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 32:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '/') ADVANCE(274);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 33:
      if (lookahead == '#') ADVANCE(227);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(351);
      END_STATE();
    case 34:
      if (lookahead == '(') ADVANCE(488);
      END_STATE();
    case 35:
      if (lookahead == '(') ADVANCE(487);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(109);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(96);
      END_STATE();
    case 38:
      if (lookahead == '.') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 39:
      if (lookahead == '.') ADVANCE(136);
      if (lookahead == '/') ADVANCE(255);
      if (lookahead == '|') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 40:
      if (lookahead == '.') ADVANCE(68);
      END_STATE();
    case 41:
      ADVANCE_MAP(
        '.', 135,
        '/', 255,
        '|', 255,
        'E', 159,
        'e', 159,
        'I', 305,
        'i', 305,
        'D', 159,
        'F', 159,
        'L', 159,
        'S', 159,
        'd', 159,
        'f', 159,
        'l', 159,
        's', 159,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 42:
      if (lookahead == '.') ADVANCE(69);
      END_STATE();
    case 43:
      if (lookahead == '.') ADVANCE(238);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 44:
      if (lookahead == '.') ADVANCE(70);
      END_STATE();
    case 45:
      if (lookahead == '.') ADVANCE(71);
      END_STATE();
    case 46:
      if (lookahead == '.') ADVANCE(72);
      END_STATE();
    case 47:
      if (lookahead == '.') ADVANCE(247);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(319);
      END_STATE();
    case 48:
      if (lookahead == '.') ADVANCE(247);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(319);
      END_STATE();
    case 49:
      if (lookahead == '.') ADVANCE(67);
      END_STATE();
    case 50:
      if (lookahead == '.') ADVANCE(248);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 51:
      if (lookahead == '.') ADVANCE(239);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(397);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      END_STATE();
    case 52:
      if (lookahead == '.') ADVANCE(249);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(320);
      END_STATE();
    case 53:
      if (lookahead == '.') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(320);
      END_STATE();
    case 54:
      if (lookahead == '.') ADVANCE(250);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 55:
      if (lookahead == '.') ADVANCE(257);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 56:
      if (lookahead == '.') ADVANCE(257);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 57:
      if (lookahead == '.') ADVANCE(258);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 58:
      if (lookahead == '.') ADVANCE(259);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(322);
      END_STATE();
    case 59:
      if (lookahead == '.') ADVANCE(259);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(322);
      END_STATE();
    case 60:
      if (lookahead == '.') ADVANCE(260);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 61:
      if (lookahead == '.') ADVANCE(261);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 62:
      if (lookahead == '.') ADVANCE(261);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 63:
      if (lookahead == '.') ADVANCE(262);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 64:
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(64);
      END_STATE();
    case 65:
      if (lookahead == '/') ADVANCE(235);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(65);
      END_STATE();
    case 66:
      if (lookahead == '/') ADVANCE(277);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 67:
      if (lookahead == '0') ADVANCE(305);
      END_STATE();
    case 68:
      if (lookahead == '0') ADVANCE(177);
      END_STATE();
    case 69:
      if (lookahead == '0') ADVANCE(382);
      END_STATE();
    case 70:
      if (lookahead == '0') ADVANCE(387);
      END_STATE();
    case 71:
      if (lookahead == '0') ADVANCE(383);
      END_STATE();
    case 72:
      if (lookahead == '0') ADVANCE(384);
      END_STATE();
    case 73:
      if (lookahead == '6') ADVANCE(123);
      END_STATE();
    case 74:
      if (lookahead == '8') ADVANCE(34);
      END_STATE();
    case 75:
      if (lookahead == '8') ADVANCE(35);
      END_STATE();
    case 76:
      if (lookahead == ';') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 77:
      if (lookahead == ';') ADVANCE(454);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 78:
      if (lookahead == ';') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 79:
      if (lookahead == ';') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 80:
      if (lookahead == ';') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 81:
      if (lookahead == 'A') ADVANCE(168);
      if (lookahead == 'a') ADVANCE(82);
      END_STATE();
    case 82:
      if (lookahead == 'C') ADVANCE(169);
      if (lookahead == 'c') ADVANCE(83);
      END_STATE();
    case 83:
      if (lookahead == 'E') ADVANCE(428);
      if (lookahead == 'e') ADVANCE(407);
      END_STATE();
    case 84:
      if (lookahead == 'I') ADVANCE(204);
      if (lookahead == 'i') ADVANCE(87);
      END_STATE();
    case 85:
      if (lookahead == 'L') ADVANCE(197);
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 86:
      ADVANCE_MAP(
        'N', 421,
        'S', 422,
        'X', 423,
        'a', 418,
        'b', 413,
        'd', 415,
        'e', 419,
        'l', 416,
        'n', 408,
        'p', 410,
        'r', 414,
        's', 409,
        't', 411,
        'u', 424,
        'v', 420,
        'x', 425,
      );
      if (lookahead != 0) ADVANCE(407);
      END_STATE();
    case 87:
      if (lookahead == 'N') ADVANCE(169);
      if (lookahead == 'n') ADVANCE(83);
      END_STATE();
    case 88:
      if (lookahead == 'W') ADVANCE(202);
      if (lookahead == 'w') ADVANCE(85);
      END_STATE();
    case 89:
      if (lookahead == '\\') ADVANCE(214);
      if (lookahead == '|') ADVANCE(439);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 90:
      if (lookahead == '\\') ADVANCE(215);
      if (lookahead == '|') ADVANCE(478);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 91:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 92:
      if (lookahead == 'a') ADVANCE(124);
      END_STATE();
    case 93:
      if (lookahead == 'a') ADVANCE(127);
      END_STATE();
    case 94:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 95:
      if (lookahead == 'b') ADVANCE(407);
      END_STATE();
    case 96:
      if (lookahead == 'c') ADVANCE(93);
      END_STATE();
    case 97:
      if (lookahead == 'c') ADVANCE(112);
      END_STATE();
    case 98:
      if (lookahead == 'c') ADVANCE(103);
      END_STATE();
    case 99:
      if (lookahead == 'c') ADVANCE(412);
      END_STATE();
    case 100:
      if (lookahead == 'd') ADVANCE(407);
      END_STATE();
    case 101:
      if (lookahead == 'd') ADVANCE(37);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(296);
      END_STATE();
    case 103:
      if (lookahead == 'e') ADVANCE(407);
      END_STATE();
    case 104:
      if (lookahead == 'e') ADVANCE(426);
      END_STATE();
    case 105:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 106:
      if (lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 107:
      if (lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 108:
      if (lookahead == 'e') ADVANCE(105);
      END_STATE();
    case 109:
      if (lookahead == 'f') ADVANCE(119);
      END_STATE();
    case 110:
      if (lookahead == 'f') ADVANCE(108);
      END_STATE();
    case 111:
      if (lookahead == 'g') ADVANCE(103);
      END_STATE();
    case 112:
      if (lookahead == 'k') ADVANCE(128);
      END_STATE();
    case 113:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 114:
      if (lookahead == 'l') ADVANCE(107);
      END_STATE();
    case 115:
      if (lookahead == 'l') ADVANCE(417);
      END_STATE();
    case 116:
      if (lookahead == 'm') ADVANCE(407);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(407);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(106);
      END_STATE();
    case 119:
      if (lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 120:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 121:
      if (lookahead == 'p') ADVANCE(94);
      END_STATE();
    case 122:
      if (lookahead == 'p') ADVANCE(104);
      END_STATE();
    case 123:
      if (lookahead == 'r') ADVANCE(126);
      END_STATE();
    case 124:
      if (lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 125:
      if (lookahead == 'r') ADVANCE(117);
      END_STATE();
    case 126:
      if (lookahead == 's') ADVANCE(297);
      END_STATE();
    case 127:
      if (lookahead == 's') ADVANCE(102);
      END_STATE();
    case 128:
      if (lookahead == 's') ADVANCE(121);
      END_STATE();
    case 129:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 130:
      if (lookahead == 't') ADVANCE(103);
      END_STATE();
    case 131:
      if (lookahead == 'u') ADVANCE(125);
      END_STATE();
    case 132:
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 133:
      if (lookahead == 'x') ADVANCE(269);
      END_STATE();
    case 134:
      if (lookahead == '|') ADVANCE(90);
      if ((!eof && set_contains(sym_keyword_character_set_2, 17, lookahead))) ADVANCE(479);
      END_STATE();
    case 135:
      ADVANCE_MAP(
        '|', 255,
        'E', 159,
        'e', 159,
        'I', 305,
        'i', 305,
        'D', 159,
        'F', 159,
        'L', 159,
        'S', 159,
        'd', 159,
        'f', 159,
        'l', 159,
        's', 159,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 136:
      if (lookahead == '|') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 137:
      if (lookahead == '|') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 138:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(198);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(312);
      END_STATE();
    case 139:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(339);
      END_STATE();
    case 140:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(351);
      END_STATE();
    case 141:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(191);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(333);
      END_STATE();
    case 142:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(350);
      END_STATE();
    case 143:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(362);
      END_STATE();
    case 144:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(217);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(333);
      END_STATE();
    case 145:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(350);
      END_STATE();
    case 146:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(192);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(372);
      END_STATE();
    case 147:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(373);
      END_STATE();
    case 148:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(374);
      END_STATE();
    case 149:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(362);
      END_STATE();
    case 150:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(375);
      END_STATE();
    case 151:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(385);
      END_STATE();
    case 152:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(376);
      END_STATE();
    case 153:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(386);
      END_STATE();
    case 154:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(379);
      END_STATE();
    case 155:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(402);
      END_STATE();
    case 156:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(182);
      END_STATE();
    case 157:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(378);
      END_STATE();
    case 158:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(391);
      END_STATE();
    case 159:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 160:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(168);
      END_STATE();
    case 161:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 162:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(205);
      END_STATE();
    case 163:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(206);
      END_STATE();
    case 164:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(207);
      END_STATE();
    case 165:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(208);
      END_STATE();
    case 166:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(209);
      END_STATE();
    case 167:
      ADVANCE_MAP(
        'B', 138,
        'b', 138,
        'D', 43,
        'd', 43,
        'O', 139,
        'o', 139,
        'X', 140,
        'x', 140,
      );
      END_STATE();
    case 168:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(169);
      END_STATE();
    case 169:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(428);
      END_STATE();
    case 170:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(302);
      END_STATE();
    case 171:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(40);
      END_STATE();
    case 172:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(42);
      END_STATE();
    case 173:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(44);
      END_STATE();
    case 174:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(45);
      END_STATE();
    case 175:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(46);
      END_STATE();
    case 176:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(49);
      END_STATE();
    case 177:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 178:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(19);
      END_STATE();
    case 179:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(179);
      END_STATE();
    case 180:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      END_STATE();
    case 181:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(181);
      END_STATE();
    case 182:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(182);
      END_STATE();
    case 183:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 184:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(184);
      END_STATE();
    case 185:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(19);
      END_STATE();
    case 186:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(64);
      END_STATE();
    case 187:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      END_STATE();
    case 188:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(65);
      END_STATE();
    case 189:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 190:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(394);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 191:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(333);
      END_STATE();
    case 192:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(372);
      END_STATE();
    case 193:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(350);
      END_STATE();
    case 194:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(373);
      END_STATE();
    case 195:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(362);
      END_STATE();
    case 196:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(374);
      END_STATE();
    case 197:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(204);
      END_STATE();
    case 198:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(396);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(162);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(323);
      END_STATE();
    case 199:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(398);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(344);
      END_STATE();
    case 200:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(399);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(356);
      END_STATE();
    case 201:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(211);
      END_STATE();
    case 202:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(197);
      END_STATE();
    case 203:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 204:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(169);
      END_STATE();
    case 205:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 206:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 207:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 208:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 209:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 210:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(176);
      END_STATE();
    case 211:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(170);
      END_STATE();
    case 212:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(170);
      END_STATE();
    case 213:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(202);
      END_STATE();
    case 214:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(276);
      if (lookahead == 'a' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == '|') ADVANCE(89);
      END_STATE();
    case 215:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(280);
      if (lookahead == 'a' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == '|') ADVANCE(90);
      END_STATE();
    case 216:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(341);
      END_STATE();
    case 217:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(333);
      END_STATE();
    case 218:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(346);
      END_STATE();
    case 219:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(335);
      END_STATE();
    case 220:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(21);
      END_STATE();
    case 221:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(400);
      END_STATE();
    case 222:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(179);
      END_STATE();
    case 223:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(343);
      END_STATE();
    case 224:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(348);
      END_STATE();
    case 225:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(138);
      END_STATE();
    case 226:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(139);
      END_STATE();
    case 227:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(140);
      END_STATE();
    case 228:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(43);
      END_STATE();
    case 229:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(353);
      END_STATE();
    case 230:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(350);
      END_STATE();
    case 231:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(358);
      END_STATE();
    case 232:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 233:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(22);
      END_STATE();
    case 234:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(401);
      END_STATE();
    case 235:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(181);
      END_STATE();
    case 236:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(355);
      END_STATE();
    case 237:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(360);
      END_STATE();
    case 238:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      END_STATE();
    case 239:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(314);
      END_STATE();
    case 240:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(314);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 241:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(316);
      END_STATE();
    case 242:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(381);
      END_STATE();
    case 243:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(375);
      END_STATE();
    case 244:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(325);
      END_STATE();
    case 245:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(380);
      END_STATE();
    case 246:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(376);
      END_STATE();
    case 247:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(328);
      END_STATE();
    case 248:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 249:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(331);
      END_STATE();
    case 250:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 251:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(337);
      END_STATE();
    case 252:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(402);
      END_STATE();
    case 253:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(391);
      END_STATE();
    case 254:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 255:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(182);
      END_STATE();
    case 256:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 257:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(390);
      END_STATE();
    case 258:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 259:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(329);
      END_STATE();
    case 260:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 261:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(389);
      END_STATE();
    case 262:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 263:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(318);
      END_STATE();
    case 264:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(379);
      END_STATE();
    case 265:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(385);
      END_STATE();
    case 266:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      END_STATE();
    case 267:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(378);
      END_STATE();
    case 268:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(386);
      END_STATE();
    case 269:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 270:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(363);
      END_STATE();
    case 271:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(362);
      END_STATE();
    case 272:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(366);
      END_STATE();
    case 273:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(338);
      END_STATE();
    case 274:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 275:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(404);
      END_STATE();
    case 276:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 277:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(184);
      END_STATE();
    case 278:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(365);
      END_STATE();
    case 279:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(368);
      END_STATE();
    case 280:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 281:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 282:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 283:
      if (eof) ADVANCE(284);
      ADVANCE_MAP(
        '\t', 286,
        '"', 430,
        '#', 299,
        '\'', 489,
        '(', 480,
        ')', 481,
        '+', 441,
        ',', 492,
        '-', 440,
        '.', 485,
        ';', 288,
        '[', 482,
        '\\', 133,
        ']', 483,
        '`', 490,
        '|', 89,
        '\n', 285,
        '\r', 285,
        ' ', 285,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(287);
      if (('!' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(453);
      if (set_contains(sym_symbol_character_set_1, 219, lookahead)) ADVANCE(454);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (lookahead == '\t') ADVANCE(286);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(285);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(287);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(286);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(287);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(287);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x85 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(288);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_POUND_PIPE);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '#') ADVANCE(293);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '|') ADVANCE(289);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_PIPE_POUND);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_POUND_SEMI);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_POUND_BANG);
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_directive_token1);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_directive_token2);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_POUND);
      ADVANCE_MAP(
        '!', 295,
        '\'', 494,
        '(', 486,
        ',', 496,
        ':', 134,
        ';', 294,
        '\\', 406,
        '`', 495,
        'u', 74,
        'v', 132,
        '|', 289,
        'B', 8,
        'b', 8,
        'D', 27,
        'd', 27,
        'O', 30,
        'o', 30,
        'X', 33,
        'x', 33,
        'E', 9,
        'I', 9,
        'e', 9,
        'i', 9,
      );
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_POUND);
      ADVANCE_MAP(
        '\'', 494,
        '(', 486,
        ',', 496,
        ':', 134,
        '\\', 406,
        '`', 495,
        'u', 74,
        'v', 132,
        'B', 8,
        'b', 8,
        'D', 27,
        'd', 27,
        'O', 30,
        'o', 30,
        'X', 33,
        'x', 33,
        'E', 9,
        'I', 9,
        'e', 9,
        'i', 9,
      );
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead == '|') ADVANCE(289);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_boolean_token1);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_boolean_token1);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(201);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_boolean_token1);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(212);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_number);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 307,
        '.', 310,
        '/', 241,
        '@', 47,
        '|', 242,
        '+', 50,
        '-', 50,
        'E', 150,
        'e', 150,
        'D', 151,
        'F', 151,
        'L', 151,
        'S', 151,
        'd', 151,
        'f', 151,
        'l', 151,
        's', 151,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(307);
      if (lookahead == '.') ADVANCE(311);
      if (lookahead == '/') ADVANCE(263);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(154);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 309,
        '.', 314,
        '/', 244,
        '@', 47,
        '|', 245,
        '+', 50,
        '-', 50,
        'E', 152,
        'e', 152,
        'I', 305,
        'i', 305,
        'D', 153,
        'F', 153,
        'L', 153,
        'S', 153,
        'd', 153,
        'f', 153,
        'l', 153,
        's', 153,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 309,
        '.', 315,
        '/', 266,
        '@', 52,
        '+', 54,
        '-', 54,
        'I', 305,
        'i', 305,
      );
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(157);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 311,
        '@', 47,
        '|', 242,
        '+', 50,
        '-', 50,
        'E', 150,
        'e', 150,
        'D', 151,
        'F', 151,
        'L', 151,
        'S', 151,
        'd', 151,
        'f', 151,
        'l', 151,
        's', 151,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(311);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(154);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(313);
      if (lookahead == '/') ADVANCE(216);
      if (lookahead == '@') ADVANCE(141);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(185);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(312);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(313);
      if (lookahead == '/') ADVANCE(223);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 315,
        '@', 47,
        '|', 245,
        '+', 50,
        '-', 50,
        'E', 152,
        'e', 152,
        'I', 305,
        'i', 305,
        'D', 153,
        'F', 153,
        'L', 153,
        'S', 153,
        'd', 153,
        'f', 153,
        'l', 153,
        's', 153,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(314);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(315);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(157);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(317);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(316);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(317);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(317);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(318);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 321,
        '.', 328,
        '/', 251,
        '|', 252,
        'E', 158,
        'e', 158,
        'D', 158,
        'F', 158,
        'L', 158,
        'S', 158,
        'd', 158,
        'f', 158,
        'l', 158,
        's', 158,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(319);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(321);
      if (lookahead == '.') ADVANCE(331);
      if (lookahead == '/') ADVANCE(251);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(320);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(321);
      if (lookahead == '.') ADVANCE(330);
      if (lookahead == '/') ADVANCE(251);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(155);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(321);
      if (lookahead == '.') ADVANCE(329);
      if (lookahead == '/') ADVANCE(251);
      if (lookahead == '|') ADVANCE(252);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 324,
        '/', 218,
        '@', 141,
        '+', 185,
        '-', 185,
        'I', 305,
        'i', 305,
        '0', 323,
        '1', 323,
      );
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(324);
      if (lookahead == '/') ADVANCE(224);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(326);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(325);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(326);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(326);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 330,
        '|', 252,
        'E', 158,
        'e', 158,
        'D', 158,
        'F', 158,
        'L', 158,
        'S', 158,
        'd', 158,
        'f', 158,
        'l', 158,
        's', 158,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(328);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(330);
      if (lookahead == '|') ADVANCE(252);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(329);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(330);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(155);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(330);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(331);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(332);
      if (lookahead == '/') ADVANCE(219);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(332);
      if (lookahead == '/') ADVANCE(219);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(333);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(334);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(334);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(335);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(337);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(338);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(340);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '@') ADVANCE(142);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(339);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(340);
      if (lookahead == '/') ADVANCE(236);
      if (lookahead == '@') ADVANCE(145);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(342);
      if (lookahead == '@') ADVANCE(141);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(185);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(341);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(342);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(342);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(343);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(345);
      if (lookahead == '/') ADVANCE(231);
      if (lookahead == '@') ADVANCE(142);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(187);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(344);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(345);
      if (lookahead == '/') ADVANCE(237);
      if (lookahead == '@') ADVANCE(145);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(347);
      if (lookahead == '@') ADVANCE(141);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(185);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(347);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(347);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(348);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(349);
      if (lookahead == '/') ADVANCE(232);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(349);
      if (lookahead == '/') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(350);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(352);
      if (lookahead == '/') ADVANCE(270);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(351);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(352);
      if (lookahead == '/') ADVANCE(278);
      if (lookahead == '@') ADVANCE(149);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(354);
      if (lookahead == '@') ADVANCE(142);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(353);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(354);
      if (lookahead == '@') ADVANCE(145);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(354);
      if (lookahead == '@') ADVANCE(145);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(355);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(357);
      if (lookahead == '/') ADVANCE(272);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(189);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(356);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(357);
      if (lookahead == '/') ADVANCE(279);
      if (lookahead == '@') ADVANCE(149);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(359);
      if (lookahead == '@') ADVANCE(142);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(187);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(358);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(359);
      if (lookahead == '@') ADVANCE(145);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(359);
      if (lookahead == '@') ADVANCE(145);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(360);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(361);
      if (lookahead == '/') ADVANCE(273);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(361);
      if (lookahead == '/') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(362);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(364);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(363);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(364);
      if (lookahead == '@') ADVANCE(149);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(364);
      if (lookahead == '@') ADVANCE(149);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(365);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(367);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(189);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(366);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(367);
      if (lookahead == '@') ADVANCE(149);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(367);
      if (lookahead == '@') ADVANCE(149);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(368);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(390);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == '|') ADVANCE(252);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 388,
        '/', 473,
        '|', 252,
        'E', 457,
        'e', 457,
        'D', 457,
        'F', 457,
        'L', 457,
        'S', 457,
        'd', 457,
        'f', 457,
        'l', 457,
        's', 457,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 389,
        '/', 252,
        '|', 252,
        'E', 158,
        'e', 158,
        'D', 158,
        'F', 158,
        'L', 158,
        'S', 158,
        'd', 158,
        'f', 158,
        'l', 158,
        's', 158,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(221);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(372);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(373);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(374);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '|') ADVANCE(242);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(375);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '|') ADVANCE(245);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(376);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(444);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(448);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(405);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(378);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(379);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(55);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(57);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(380);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(55);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(381);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(146);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(186);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(147);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(188);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(148);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(190);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(58);
      if (lookahead == '|') ADVANCE(242);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(385);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(58);
      if (lookahead == '|') ADVANCE(245);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(60);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(386);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(61);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(63);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(305);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '|', 252,
        'E', 457,
        'e', 457,
        'D', 457,
        'F', 457,
        'L', 457,
        'S', 457,
        'd', 457,
        'f', 457,
        'l', 457,
        's', 457,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '|', 252,
        'E', 158,
        'e', 158,
        'D', 158,
        'F', 158,
        'L', 158,
        'S', 158,
        'd', 158,
        'f', 158,
        'l', 158,
        's', 158,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(389);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(252);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(390);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(391);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(392);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(462);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(171);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(463);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(172);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(173);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(174);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(175);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(400);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(401);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(402);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(403);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(404);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_number);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(anon_sym_POUND_BSLASH);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(aux_sym_character_token1);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'E') ADVANCE(213);
      if (lookahead == 'e') ADVANCE(88);
      if (lookahead == 'u') ADVANCE(115);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'P') ADVANCE(160);
      if (lookahead == 'p') ADVANCE(81);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'a') ADVANCE(111);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'a') ADVANCE(122);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'e') ADVANCE(129);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'i') ADVANCE(118);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'l') ADVANCE(426);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'l') ADVANCE(92);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 's') ADVANCE(99);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 't') ADVANCE(91);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(213);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(160);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(427);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(429);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(425);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(aux_sym_character_token2);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(aux_sym_character_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(427);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(aux_sym_character_token3);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(aux_sym_character_token4);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(429);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(431);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      if (lookahead == '\n') ADVANCE(435);
      if (lookahead == 0x85) ADVANCE(437);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(435);
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(437);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(435);
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(437);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      if (lookahead == '\n' ||
          lookahead == 0x85) ADVANCE(437);
      if (set_contains(aux_sym_escape_sequence_token1_character_set_2, 9, lookahead)) ADVANCE(437);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      if ((set_contains(aux_sym_escape_sequence_token1_character_set_2, 9, lookahead)) &&
          lookahead != '\n' &&
          lookahead != 0x85) ADVANCE(437);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token2);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_symbol);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(240);
      if (lookahead == '>') ADVANCE(453);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(393);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(459);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(240);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(393);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(459);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(477);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(450);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(471);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(471);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(470);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(461);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_symbol);
      ADVANCE_MAP(
        '.', 455,
        '/', 475,
        '|', 255,
        'E', 458,
        'e', 458,
        'I', 405,
        'i', 405,
        'D', 458,
        'F', 458,
        'L', 458,
        'S', 458,
        'd', 458,
        'f', 458,
        'l', 458,
        's', 458,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(446);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(452);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(472);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(395);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(460);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(446);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(451);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '0') ADVANCE(377);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '0') ADVANCE(405);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '0') ADVANCE(466);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '\\') ADVANCE(133);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(453);
      if (set_contains(sym_symbol_character_set_3, 65, lookahead)) ADVANCE(454);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '\\') ADVANCE(133);
      if (set_contains(sym_symbol_character_set_3, 65, lookahead)) ADVANCE(454);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_symbol);
      ADVANCE_MAP(
        '|', 255,
        'E', 458,
        'e', 458,
        'I', 405,
        'i', 405,
        'D', 458,
        'F', 458,
        'L', 458,
        'S', 458,
        'd', 458,
        'f', 458,
        'l', 458,
        's', 458,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(455);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '|') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(456);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(474);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(392);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(476);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(456);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(467);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(468);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(469);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(443);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(447);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(449);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(465);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(405);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(443);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(447);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(449);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(464);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(455);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(403);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(392);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(465);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(456);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_symbol);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_keyword);
      if ((!eof && set_contains(sym_keyword_character_set_2, 17, lookahead))) ADVANCE(479);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_dot);
      if (lookahead == '.') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(477);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_POUND_LPAREN);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_POUNDvu8_LPAREN);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_POUNDu8_LPAREN);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '@') ADVANCE(493);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_COMMA_AT);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_POUND_SQUOTE);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(anon_sym_POUND_BQUOTE);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_POUND_COMMA);
      if (lookahead == '@') ADVANCE(497);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(anon_sym_POUND_COMMA_AT);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(aux_sym_datum_label_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(498);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 283},
  [2] = {.lex_state = 283},
  [3] = {.lex_state = 283},
  [4] = {.lex_state = 283},
  [5] = {.lex_state = 283},
  [6] = {.lex_state = 283},
  [7] = {.lex_state = 283},
  [8] = {.lex_state = 283},
  [9] = {.lex_state = 283},
  [10] = {.lex_state = 283},
  [11] = {.lex_state = 283},
  [12] = {.lex_state = 283},
  [13] = {.lex_state = 283},
  [14] = {.lex_state = 283},
  [15] = {.lex_state = 283},
  [16] = {.lex_state = 283},
  [17] = {.lex_state = 283},
  [18] = {.lex_state = 283},
  [19] = {.lex_state = 283},
  [20] = {.lex_state = 283},
  [21] = {.lex_state = 283},
  [22] = {.lex_state = 283},
  [23] = {.lex_state = 283},
  [24] = {.lex_state = 283},
  [25] = {.lex_state = 283},
  [26] = {.lex_state = 283},
  [27] = {.lex_state = 283},
  [28] = {.lex_state = 283},
  [29] = {.lex_state = 283},
  [30] = {.lex_state = 283},
  [31] = {.lex_state = 283},
  [32] = {.lex_state = 283},
  [33] = {.lex_state = 283},
  [34] = {.lex_state = 283},
  [35] = {.lex_state = 283},
  [36] = {.lex_state = 283},
  [37] = {.lex_state = 283},
  [38] = {.lex_state = 283},
  [39] = {.lex_state = 283},
  [40] = {.lex_state = 283},
  [41] = {.lex_state = 283},
  [42] = {.lex_state = 283},
  [43] = {.lex_state = 283},
  [44] = {.lex_state = 283},
  [45] = {.lex_state = 283},
  [46] = {.lex_state = 283},
  [47] = {.lex_state = 283},
  [48] = {.lex_state = 283},
  [49] = {.lex_state = 283},
  [50] = {.lex_state = 283},
  [51] = {.lex_state = 283},
  [52] = {.lex_state = 283},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 283},
  [56] = {.lex_state = 283},
  [57] = {.lex_state = 283},
  [58] = {.lex_state = 283},
  [59] = {.lex_state = 283},
  [60] = {.lex_state = 283},
  [61] = {.lex_state = 283},
  [62] = {.lex_state = 283},
  [63] = {.lex_state = 283},
  [64] = {.lex_state = 283},
  [65] = {.lex_state = 283},
  [66] = {.lex_state = 283},
  [67] = {.lex_state = 283},
  [68] = {.lex_state = 283},
  [69] = {.lex_state = 283},
  [70] = {.lex_state = 283},
  [71] = {.lex_state = 283},
  [72] = {.lex_state = 283},
  [73] = {.lex_state = 283},
  [74] = {.lex_state = 283},
  [75] = {.lex_state = 283},
  [76] = {.lex_state = 283},
  [77] = {.lex_state = 283},
  [78] = {.lex_state = 283},
  [79] = {.lex_state = 283},
  [80] = {.lex_state = 283},
  [81] = {.lex_state = 283},
  [82] = {.lex_state = 283},
  [83] = {.lex_state = 283},
  [84] = {.lex_state = 283},
  [85] = {.lex_state = 283},
  [86] = {.lex_state = 283},
  [87] = {.lex_state = 283},
  [88] = {.lex_state = 283},
  [89] = {.lex_state = 283},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 1},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 1},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 1},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 1},
  [113] = {.lex_state = 1},
  [114] = {.lex_state = 1},
  [115] = {.lex_state = 1},
  [116] = {.lex_state = 1},
  [117] = {.lex_state = 1},
  [118] = {.lex_state = 1},
  [119] = {.lex_state = 1},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 1},
  [122] = {.lex_state = 1},
  [123] = {.lex_state = 1},
  [124] = {.lex_state = 1},
  [125] = {.lex_state = 1},
  [126] = {.lex_state = 1},
  [127] = {.lex_state = 1},
  [128] = {.lex_state = 1},
  [129] = {.lex_state = 7},
  [130] = {.lex_state = 25},
  [131] = {.lex_state = 25},
  [132] = {.lex_state = 7},
  [133] = {.lex_state = 25},
  [134] = {.lex_state = 25},
  [135] = {.lex_state = 7},
  [136] = {.lex_state = 7},
  [137] = {.lex_state = 25},
  [138] = {.lex_state = 25},
  [139] = {.lex_state = 7},
  [140] = {.lex_state = 25},
  [141] = {.lex_state = 86},
  [142] = {.lex_state = 86},
  [143] = {.lex_state = 25},
  [144] = {.lex_state = 26},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 26},
  [147] = {.lex_state = 7},
  [148] = {.lex_state = 25},
  [149] = {.lex_state = 26},
  [150] = {.lex_state = 26},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 1},
  [153] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__intertoken_token1] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_POUND_PIPE] = ACTIONS(1),
    [aux_sym_block_comment_token1] = ACTIONS(1),
    [anon_sym_PIPE_POUND] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [aux_sym_boolean_token2] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [aux_sym_escape_sequence_token3] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_dot] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(151),
    [sym__token] = STATE(14),
    [sym__intertoken] = STATE(14),
    [sym__datum] = STATE(14),
    [sym_block_comment] = STATE(14),
    [sym_sexp_comment] = STATE(14),
    [sym_directive] = STATE(14),
    [sym_boolean] = STATE(14),
    [sym_character] = STATE(14),
    [sym_string] = STATE(14),
    [sym_list] = STATE(14),
    [sym_vector] = STATE(14),
    [sym_byte_vector] = STATE(14),
    [sym_quote] = STATE(14),
    [sym_quasiquote] = STATE(14),
    [sym_unquote] = STATE(14),
    [sym_unquote_splicing] = STATE(14),
    [sym_syntax_quote] = STATE(14),
    [sym_quasisyntax] = STATE(14),
    [sym_unsyntax] = STATE(14),
    [sym_unsyntax_splicing] = STATE(14),
    [sym_datum_label] = STATE(14),
    [sym_datum_reference] = STATE(14),
    [aux_sym_program_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__intertoken_token1] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(17),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(17),
    [sym_keyword] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [2] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
    [sym_directive] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_character] = STATE(2),
    [sym_string] = STATE(2),
    [sym_list] = STATE(2),
    [sym_vector] = STATE(2),
    [sym_byte_vector] = STATE(2),
    [sym_quote] = STATE(2),
    [sym_quasiquote] = STATE(2),
    [sym_unquote] = STATE(2),
    [sym_unquote_splicing] = STATE(2),
    [sym_syntax_quote] = STATE(2),
    [sym_quasisyntax] = STATE(2),
    [sym_unsyntax] = STATE(2),
    [sym_unsyntax_splicing] = STATE(2),
    [sym_datum_label] = STATE(2),
    [sym_datum_reference] = STATE(2),
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(47),
    [sym_comment] = ACTIONS(47),
    [anon_sym_POUND_PIPE] = ACTIONS(50),
    [anon_sym_POUND_SEMI] = ACTIONS(53),
    [anon_sym_POUND_BANG] = ACTIONS(56),
    [aux_sym_directive_token2] = ACTIONS(59),
    [anon_sym_POUND] = ACTIONS(62),
    [sym_number] = ACTIONS(65),
    [anon_sym_POUND_BSLASH] = ACTIONS(68),
    [anon_sym_DQUOTE] = ACTIONS(71),
    [sym_symbol] = ACTIONS(65),
    [sym_keyword] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(74),
    [anon_sym_RPAREN] = ACTIONS(77),
    [anon_sym_LBRACK] = ACTIONS(79),
    [anon_sym_RBRACK] = ACTIONS(77),
    [sym_dot] = ACTIONS(65),
    [anon_sym_POUND_LPAREN] = ACTIONS(82),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(85),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(85),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [anon_sym_BQUOTE] = ACTIONS(91),
    [anon_sym_COMMA] = ACTIONS(94),
    [anon_sym_COMMA_AT] = ACTIONS(97),
    [anon_sym_POUND_SQUOTE] = ACTIONS(100),
    [anon_sym_POUND_BQUOTE] = ACTIONS(103),
    [anon_sym_POUND_COMMA] = ACTIONS(106),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(109),
  },
  [3] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
    [sym_directive] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_character] = STATE(2),
    [sym_string] = STATE(2),
    [sym_list] = STATE(2),
    [sym_vector] = STATE(2),
    [sym_byte_vector] = STATE(2),
    [sym_quote] = STATE(2),
    [sym_quasiquote] = STATE(2),
    [sym_unquote] = STATE(2),
    [sym_unquote_splicing] = STATE(2),
    [sym_syntax_quote] = STATE(2),
    [sym_quasisyntax] = STATE(2),
    [sym_unsyntax] = STATE(2),
    [sym_unsyntax_splicing] = STATE(2),
    [sym_datum_label] = STATE(2),
    [sym_datum_reference] = STATE(2),
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(112),
    [sym_comment] = ACTIONS(112),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(114),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(114),
    [sym_keyword] = ACTIONS(112),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_RBRACK] = ACTIONS(116),
    [sym_dot] = ACTIONS(114),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [4] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
    [sym_directive] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_character] = STATE(2),
    [sym_string] = STATE(2),
    [sym_list] = STATE(2),
    [sym_vector] = STATE(2),
    [sym_byte_vector] = STATE(2),
    [sym_quote] = STATE(2),
    [sym_quasiquote] = STATE(2),
    [sym_unquote] = STATE(2),
    [sym_unquote_splicing] = STATE(2),
    [sym_syntax_quote] = STATE(2),
    [sym_quasisyntax] = STATE(2),
    [sym_unsyntax] = STATE(2),
    [sym_unsyntax_splicing] = STATE(2),
    [sym_datum_label] = STATE(2),
    [sym_datum_reference] = STATE(2),
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(112),
    [sym_comment] = ACTIONS(112),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(114),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(114),
    [sym_keyword] = ACTIONS(112),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(116),
    [anon_sym_LBRACK] = ACTIONS(25),
    [sym_dot] = ACTIONS(114),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [5] = {
    [sym__token] = STATE(10),
    [sym__intertoken] = STATE(10),
    [sym__datum] = STATE(10),
    [sym_block_comment] = STATE(10),
    [sym_sexp_comment] = STATE(10),
    [sym_directive] = STATE(10),
    [sym_boolean] = STATE(10),
    [sym_character] = STATE(10),
    [sym_string] = STATE(10),
    [sym_list] = STATE(10),
    [sym_vector] = STATE(10),
    [sym_byte_vector] = STATE(10),
    [sym_quote] = STATE(10),
    [sym_quasiquote] = STATE(10),
    [sym_unquote] = STATE(10),
    [sym_unquote_splicing] = STATE(10),
    [sym_syntax_quote] = STATE(10),
    [sym_quasisyntax] = STATE(10),
    [sym_unsyntax] = STATE(10),
    [sym_unsyntax_splicing] = STATE(10),
    [sym_datum_label] = STATE(10),
    [sym_datum_reference] = STATE(10),
    [aux_sym_list_repeat1] = STATE(10),
    [aux_sym__intertoken_token1] = ACTIONS(118),
    [sym_comment] = ACTIONS(118),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(120),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(120),
    [sym_keyword] = ACTIONS(118),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(122),
    [anon_sym_LBRACK] = ACTIONS(25),
    [sym_dot] = ACTIONS(120),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [6] = {
    [sym__token] = STATE(4),
    [sym__intertoken] = STATE(4),
    [sym__datum] = STATE(4),
    [sym_block_comment] = STATE(4),
    [sym_sexp_comment] = STATE(4),
    [sym_directive] = STATE(4),
    [sym_boolean] = STATE(4),
    [sym_character] = STATE(4),
    [sym_string] = STATE(4),
    [sym_list] = STATE(4),
    [sym_vector] = STATE(4),
    [sym_byte_vector] = STATE(4),
    [sym_quote] = STATE(4),
    [sym_quasiquote] = STATE(4),
    [sym_unquote] = STATE(4),
    [sym_unquote_splicing] = STATE(4),
    [sym_syntax_quote] = STATE(4),
    [sym_quasisyntax] = STATE(4),
    [sym_unsyntax] = STATE(4),
    [sym_unsyntax_splicing] = STATE(4),
    [sym_datum_label] = STATE(4),
    [sym_datum_reference] = STATE(4),
    [aux_sym_list_repeat1] = STATE(4),
    [aux_sym__intertoken_token1] = ACTIONS(124),
    [sym_comment] = ACTIONS(124),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(126),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(126),
    [sym_keyword] = ACTIONS(124),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(128),
    [anon_sym_LBRACK] = ACTIONS(25),
    [sym_dot] = ACTIONS(126),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [7] = {
    [sym__token] = STATE(3),
    [sym__intertoken] = STATE(3),
    [sym__datum] = STATE(3),
    [sym_block_comment] = STATE(3),
    [sym_sexp_comment] = STATE(3),
    [sym_directive] = STATE(3),
    [sym_boolean] = STATE(3),
    [sym_character] = STATE(3),
    [sym_string] = STATE(3),
    [sym_list] = STATE(3),
    [sym_vector] = STATE(3),
    [sym_byte_vector] = STATE(3),
    [sym_quote] = STATE(3),
    [sym_quasiquote] = STATE(3),
    [sym_unquote] = STATE(3),
    [sym_unquote_splicing] = STATE(3),
    [sym_syntax_quote] = STATE(3),
    [sym_quasisyntax] = STATE(3),
    [sym_unsyntax] = STATE(3),
    [sym_unsyntax_splicing] = STATE(3),
    [sym_datum_label] = STATE(3),
    [sym_datum_reference] = STATE(3),
    [aux_sym_list_repeat1] = STATE(3),
    [aux_sym__intertoken_token1] = ACTIONS(130),
    [sym_comment] = ACTIONS(130),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(132),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(132),
    [sym_keyword] = ACTIONS(130),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_RBRACK] = ACTIONS(128),
    [sym_dot] = ACTIONS(132),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [8] = {
    [sym__token] = STATE(8),
    [sym__intertoken] = STATE(8),
    [sym__datum] = STATE(8),
    [sym_block_comment] = STATE(8),
    [sym_sexp_comment] = STATE(8),
    [sym_directive] = STATE(8),
    [sym_boolean] = STATE(8),
    [sym_character] = STATE(8),
    [sym_string] = STATE(8),
    [sym_list] = STATE(8),
    [sym_vector] = STATE(8),
    [sym_byte_vector] = STATE(8),
    [sym_quote] = STATE(8),
    [sym_quasiquote] = STATE(8),
    [sym_unquote] = STATE(8),
    [sym_unquote_splicing] = STATE(8),
    [sym_syntax_quote] = STATE(8),
    [sym_quasisyntax] = STATE(8),
    [sym_unsyntax] = STATE(8),
    [sym_unsyntax_splicing] = STATE(8),
    [sym_datum_label] = STATE(8),
    [sym_datum_reference] = STATE(8),
    [aux_sym_program_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(134),
    [aux_sym__intertoken_token1] = ACTIONS(136),
    [sym_comment] = ACTIONS(136),
    [anon_sym_POUND_PIPE] = ACTIONS(139),
    [anon_sym_POUND_SEMI] = ACTIONS(142),
    [anon_sym_POUND_BANG] = ACTIONS(145),
    [aux_sym_directive_token2] = ACTIONS(148),
    [anon_sym_POUND] = ACTIONS(151),
    [sym_number] = ACTIONS(154),
    [anon_sym_POUND_BSLASH] = ACTIONS(157),
    [anon_sym_DQUOTE] = ACTIONS(160),
    [sym_symbol] = ACTIONS(154),
    [sym_keyword] = ACTIONS(136),
    [anon_sym_LPAREN] = ACTIONS(163),
    [anon_sym_RPAREN] = ACTIONS(134),
    [anon_sym_LBRACK] = ACTIONS(166),
    [anon_sym_POUND_LPAREN] = ACTIONS(169),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(172),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(172),
    [anon_sym_SQUOTE] = ACTIONS(175),
    [anon_sym_BQUOTE] = ACTIONS(178),
    [anon_sym_COMMA] = ACTIONS(181),
    [anon_sym_COMMA_AT] = ACTIONS(184),
    [anon_sym_POUND_SQUOTE] = ACTIONS(187),
    [anon_sym_POUND_BQUOTE] = ACTIONS(190),
    [anon_sym_POUND_COMMA] = ACTIONS(193),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(196),
  },
  [9] = {
    [sym__token] = STATE(11),
    [sym__intertoken] = STATE(11),
    [sym__datum] = STATE(11),
    [sym_block_comment] = STATE(11),
    [sym_sexp_comment] = STATE(11),
    [sym_directive] = STATE(11),
    [sym_boolean] = STATE(11),
    [sym_character] = STATE(11),
    [sym_string] = STATE(11),
    [sym_list] = STATE(11),
    [sym_vector] = STATE(11),
    [sym_byte_vector] = STATE(11),
    [sym_quote] = STATE(11),
    [sym_quasiquote] = STATE(11),
    [sym_unquote] = STATE(11),
    [sym_unquote_splicing] = STATE(11),
    [sym_syntax_quote] = STATE(11),
    [sym_quasisyntax] = STATE(11),
    [sym_unsyntax] = STATE(11),
    [sym_unsyntax_splicing] = STATE(11),
    [sym_datum_label] = STATE(11),
    [sym_datum_reference] = STATE(11),
    [aux_sym_list_repeat1] = STATE(11),
    [aux_sym__intertoken_token1] = ACTIONS(199),
    [sym_comment] = ACTIONS(199),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(201),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(201),
    [sym_keyword] = ACTIONS(199),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_RBRACK] = ACTIONS(122),
    [sym_dot] = ACTIONS(201),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [10] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
    [sym_directive] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_character] = STATE(2),
    [sym_string] = STATE(2),
    [sym_list] = STATE(2),
    [sym_vector] = STATE(2),
    [sym_byte_vector] = STATE(2),
    [sym_quote] = STATE(2),
    [sym_quasiquote] = STATE(2),
    [sym_unquote] = STATE(2),
    [sym_unquote_splicing] = STATE(2),
    [sym_syntax_quote] = STATE(2),
    [sym_quasisyntax] = STATE(2),
    [sym_unsyntax] = STATE(2),
    [sym_unsyntax_splicing] = STATE(2),
    [sym_datum_label] = STATE(2),
    [sym_datum_reference] = STATE(2),
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(112),
    [sym_comment] = ACTIONS(112),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(114),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(114),
    [sym_keyword] = ACTIONS(112),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(203),
    [anon_sym_LBRACK] = ACTIONS(25),
    [sym_dot] = ACTIONS(114),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [11] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
    [sym_directive] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_character] = STATE(2),
    [sym_string] = STATE(2),
    [sym_list] = STATE(2),
    [sym_vector] = STATE(2),
    [sym_byte_vector] = STATE(2),
    [sym_quote] = STATE(2),
    [sym_quasiquote] = STATE(2),
    [sym_unquote] = STATE(2),
    [sym_unquote_splicing] = STATE(2),
    [sym_syntax_quote] = STATE(2),
    [sym_quasisyntax] = STATE(2),
    [sym_unsyntax] = STATE(2),
    [sym_unsyntax_splicing] = STATE(2),
    [sym_datum_label] = STATE(2),
    [sym_datum_reference] = STATE(2),
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(112),
    [sym_comment] = ACTIONS(112),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(114),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(114),
    [sym_keyword] = ACTIONS(112),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_RBRACK] = ACTIONS(203),
    [sym_dot] = ACTIONS(114),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [12] = {
    [sym__token] = STATE(13),
    [sym__intertoken] = STATE(13),
    [sym__datum] = STATE(13),
    [sym_block_comment] = STATE(13),
    [sym_sexp_comment] = STATE(13),
    [sym_directive] = STATE(13),
    [sym_boolean] = STATE(13),
    [sym_character] = STATE(13),
    [sym_string] = STATE(13),
    [sym_list] = STATE(13),
    [sym_vector] = STATE(13),
    [sym_byte_vector] = STATE(13),
    [sym_quote] = STATE(13),
    [sym_quasiquote] = STATE(13),
    [sym_unquote] = STATE(13),
    [sym_unquote_splicing] = STATE(13),
    [sym_syntax_quote] = STATE(13),
    [sym_quasisyntax] = STATE(13),
    [sym_unsyntax] = STATE(13),
    [sym_unsyntax_splicing] = STATE(13),
    [sym_datum_label] = STATE(13),
    [sym_datum_reference] = STATE(13),
    [aux_sym_program_repeat1] = STATE(13),
    [aux_sym__intertoken_token1] = ACTIONS(205),
    [sym_comment] = ACTIONS(205),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(207),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(207),
    [sym_keyword] = ACTIONS(205),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(209),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [13] = {
    [sym__token] = STATE(8),
    [sym__intertoken] = STATE(8),
    [sym__datum] = STATE(8),
    [sym_block_comment] = STATE(8),
    [sym_sexp_comment] = STATE(8),
    [sym_directive] = STATE(8),
    [sym_boolean] = STATE(8),
    [sym_character] = STATE(8),
    [sym_string] = STATE(8),
    [sym_list] = STATE(8),
    [sym_vector] = STATE(8),
    [sym_byte_vector] = STATE(8),
    [sym_quote] = STATE(8),
    [sym_quasiquote] = STATE(8),
    [sym_unquote] = STATE(8),
    [sym_unquote_splicing] = STATE(8),
    [sym_syntax_quote] = STATE(8),
    [sym_quasisyntax] = STATE(8),
    [sym_unsyntax] = STATE(8),
    [sym_unsyntax_splicing] = STATE(8),
    [sym_datum_label] = STATE(8),
    [sym_datum_reference] = STATE(8),
    [aux_sym_program_repeat1] = STATE(8),
    [aux_sym__intertoken_token1] = ACTIONS(211),
    [sym_comment] = ACTIONS(211),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(213),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(213),
    [sym_keyword] = ACTIONS(211),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(215),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [14] = {
    [sym__token] = STATE(8),
    [sym__intertoken] = STATE(8),
    [sym__datum] = STATE(8),
    [sym_block_comment] = STATE(8),
    [sym_sexp_comment] = STATE(8),
    [sym_directive] = STATE(8),
    [sym_boolean] = STATE(8),
    [sym_character] = STATE(8),
    [sym_string] = STATE(8),
    [sym_list] = STATE(8),
    [sym_vector] = STATE(8),
    [sym_byte_vector] = STATE(8),
    [sym_quote] = STATE(8),
    [sym_quasiquote] = STATE(8),
    [sym_unquote] = STATE(8),
    [sym_unquote_splicing] = STATE(8),
    [sym_syntax_quote] = STATE(8),
    [sym_quasisyntax] = STATE(8),
    [sym_unsyntax] = STATE(8),
    [sym_unsyntax_splicing] = STATE(8),
    [sym_datum_label] = STATE(8),
    [sym_datum_reference] = STATE(8),
    [aux_sym_program_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(217),
    [aux_sym__intertoken_token1] = ACTIONS(211),
    [sym_comment] = ACTIONS(211),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(213),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(213),
    [sym_keyword] = ACTIONS(211),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [15] = {
    [sym__token] = STATE(8),
    [sym__intertoken] = STATE(8),
    [sym__datum] = STATE(8),
    [sym_block_comment] = STATE(8),
    [sym_sexp_comment] = STATE(8),
    [sym_directive] = STATE(8),
    [sym_boolean] = STATE(8),
    [sym_character] = STATE(8),
    [sym_string] = STATE(8),
    [sym_list] = STATE(8),
    [sym_vector] = STATE(8),
    [sym_byte_vector] = STATE(8),
    [sym_quote] = STATE(8),
    [sym_quasiquote] = STATE(8),
    [sym_unquote] = STATE(8),
    [sym_unquote_splicing] = STATE(8),
    [sym_syntax_quote] = STATE(8),
    [sym_quasisyntax] = STATE(8),
    [sym_unsyntax] = STATE(8),
    [sym_unsyntax_splicing] = STATE(8),
    [sym_datum_label] = STATE(8),
    [sym_datum_reference] = STATE(8),
    [aux_sym_program_repeat1] = STATE(8),
    [aux_sym__intertoken_token1] = ACTIONS(211),
    [sym_comment] = ACTIONS(211),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(213),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(213),
    [sym_keyword] = ACTIONS(211),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(219),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [16] = {
    [sym__token] = STATE(15),
    [sym__intertoken] = STATE(15),
    [sym__datum] = STATE(15),
    [sym_block_comment] = STATE(15),
    [sym_sexp_comment] = STATE(15),
    [sym_directive] = STATE(15),
    [sym_boolean] = STATE(15),
    [sym_character] = STATE(15),
    [sym_string] = STATE(15),
    [sym_list] = STATE(15),
    [sym_vector] = STATE(15),
    [sym_byte_vector] = STATE(15),
    [sym_quote] = STATE(15),
    [sym_quasiquote] = STATE(15),
    [sym_unquote] = STATE(15),
    [sym_unquote_splicing] = STATE(15),
    [sym_syntax_quote] = STATE(15),
    [sym_quasisyntax] = STATE(15),
    [sym_unsyntax] = STATE(15),
    [sym_unsyntax_splicing] = STATE(15),
    [sym_datum_label] = STATE(15),
    [sym_datum_reference] = STATE(15),
    [aux_sym_program_repeat1] = STATE(15),
    [aux_sym__intertoken_token1] = ACTIONS(221),
    [sym_comment] = ACTIONS(221),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(223),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(223),
    [sym_keyword] = ACTIONS(221),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_RPAREN] = ACTIONS(225),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [17] = {
    [sym__intertoken] = STATE(36),
    [sym__datum] = STATE(128),
    [sym_block_comment] = STATE(36),
    [sym_sexp_comment] = STATE(36),
    [sym_directive] = STATE(36),
    [sym_boolean] = STATE(128),
    [sym_character] = STATE(128),
    [sym_string] = STATE(128),
    [sym_list] = STATE(128),
    [sym_vector] = STATE(128),
    [sym_byte_vector] = STATE(128),
    [sym_quote] = STATE(128),
    [sym_quasiquote] = STATE(128),
    [sym_unquote] = STATE(128),
    [sym_unquote_splicing] = STATE(128),
    [sym_syntax_quote] = STATE(128),
    [sym_quasisyntax] = STATE(128),
    [sym_unsyntax] = STATE(128),
    [sym_unsyntax_splicing] = STATE(128),
    [sym_datum_label] = STATE(128),
    [sym_datum_reference] = STATE(128),
    [aux_sym_sexp_comment_repeat1] = STATE(36),
    [aux_sym__intertoken_token1] = ACTIONS(227),
    [sym_comment] = ACTIONS(227),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(231),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(231),
    [sym_keyword] = ACTIONS(237),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [18] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(67),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(67),
    [sym_character] = STATE(67),
    [sym_string] = STATE(67),
    [sym_list] = STATE(67),
    [sym_vector] = STATE(67),
    [sym_byte_vector] = STATE(67),
    [sym_quote] = STATE(67),
    [sym_quasiquote] = STATE(67),
    [sym_unquote] = STATE(67),
    [sym_unquote_splicing] = STATE(67),
    [sym_syntax_quote] = STATE(67),
    [sym_quasisyntax] = STATE(67),
    [sym_unsyntax] = STATE(67),
    [sym_unsyntax_splicing] = STATE(67),
    [sym_datum_label] = STATE(67),
    [sym_datum_reference] = STATE(67),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(265),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(265),
    [sym_keyword] = ACTIONS(267),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [19] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(68),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(68),
    [sym_character] = STATE(68),
    [sym_string] = STATE(68),
    [sym_list] = STATE(68),
    [sym_vector] = STATE(68),
    [sym_byte_vector] = STATE(68),
    [sym_quote] = STATE(68),
    [sym_quasiquote] = STATE(68),
    [sym_unquote] = STATE(68),
    [sym_unquote_splicing] = STATE(68),
    [sym_syntax_quote] = STATE(68),
    [sym_quasisyntax] = STATE(68),
    [sym_unsyntax] = STATE(68),
    [sym_unsyntax_splicing] = STATE(68),
    [sym_datum_label] = STATE(68),
    [sym_datum_reference] = STATE(68),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(269),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(269),
    [sym_keyword] = ACTIONS(271),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [20] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(69),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(69),
    [sym_character] = STATE(69),
    [sym_string] = STATE(69),
    [sym_list] = STATE(69),
    [sym_vector] = STATE(69),
    [sym_byte_vector] = STATE(69),
    [sym_quote] = STATE(69),
    [sym_quasiquote] = STATE(69),
    [sym_unquote] = STATE(69),
    [sym_unquote_splicing] = STATE(69),
    [sym_syntax_quote] = STATE(69),
    [sym_quasisyntax] = STATE(69),
    [sym_unsyntax] = STATE(69),
    [sym_unsyntax_splicing] = STATE(69),
    [sym_datum_label] = STATE(69),
    [sym_datum_reference] = STATE(69),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(273),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(273),
    [sym_keyword] = ACTIONS(275),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [21] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(56),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(56),
    [sym_character] = STATE(56),
    [sym_string] = STATE(56),
    [sym_list] = STATE(56),
    [sym_vector] = STATE(56),
    [sym_byte_vector] = STATE(56),
    [sym_quote] = STATE(56),
    [sym_quasiquote] = STATE(56),
    [sym_unquote] = STATE(56),
    [sym_unquote_splicing] = STATE(56),
    [sym_syntax_quote] = STATE(56),
    [sym_quasisyntax] = STATE(56),
    [sym_unsyntax] = STATE(56),
    [sym_unsyntax_splicing] = STATE(56),
    [sym_datum_label] = STATE(56),
    [sym_datum_reference] = STATE(56),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(277),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(277),
    [sym_keyword] = ACTIONS(279),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [22] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(71),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(71),
    [sym_character] = STATE(71),
    [sym_string] = STATE(71),
    [sym_list] = STATE(71),
    [sym_vector] = STATE(71),
    [sym_byte_vector] = STATE(71),
    [sym_quote] = STATE(71),
    [sym_quasiquote] = STATE(71),
    [sym_unquote] = STATE(71),
    [sym_unquote_splicing] = STATE(71),
    [sym_syntax_quote] = STATE(71),
    [sym_quasisyntax] = STATE(71),
    [sym_unsyntax] = STATE(71),
    [sym_unsyntax_splicing] = STATE(71),
    [sym_datum_label] = STATE(71),
    [sym_datum_reference] = STATE(71),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(281),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(281),
    [sym_keyword] = ACTIONS(283),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [23] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(72),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(72),
    [sym_character] = STATE(72),
    [sym_string] = STATE(72),
    [sym_list] = STATE(72),
    [sym_vector] = STATE(72),
    [sym_byte_vector] = STATE(72),
    [sym_quote] = STATE(72),
    [sym_quasiquote] = STATE(72),
    [sym_unquote] = STATE(72),
    [sym_unquote_splicing] = STATE(72),
    [sym_syntax_quote] = STATE(72),
    [sym_quasisyntax] = STATE(72),
    [sym_unsyntax] = STATE(72),
    [sym_unsyntax_splicing] = STATE(72),
    [sym_datum_label] = STATE(72),
    [sym_datum_reference] = STATE(72),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(285),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(285),
    [sym_keyword] = ACTIONS(287),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [24] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(73),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(73),
    [sym_character] = STATE(73),
    [sym_string] = STATE(73),
    [sym_list] = STATE(73),
    [sym_vector] = STATE(73),
    [sym_byte_vector] = STATE(73),
    [sym_quote] = STATE(73),
    [sym_quasiquote] = STATE(73),
    [sym_unquote] = STATE(73),
    [sym_unquote_splicing] = STATE(73),
    [sym_syntax_quote] = STATE(73),
    [sym_quasisyntax] = STATE(73),
    [sym_unsyntax] = STATE(73),
    [sym_unsyntax_splicing] = STATE(73),
    [sym_datum_label] = STATE(73),
    [sym_datum_reference] = STATE(73),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(289),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(289),
    [sym_keyword] = ACTIONS(291),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [25] = {
    [sym__intertoken] = STATE(21),
    [sym__datum] = STATE(83),
    [sym_block_comment] = STATE(21),
    [sym_sexp_comment] = STATE(21),
    [sym_directive] = STATE(21),
    [sym_boolean] = STATE(83),
    [sym_character] = STATE(83),
    [sym_string] = STATE(83),
    [sym_list] = STATE(83),
    [sym_vector] = STATE(83),
    [sym_byte_vector] = STATE(83),
    [sym_quote] = STATE(83),
    [sym_quasiquote] = STATE(83),
    [sym_unquote] = STATE(83),
    [sym_unquote_splicing] = STATE(83),
    [sym_syntax_quote] = STATE(83),
    [sym_quasisyntax] = STATE(83),
    [sym_unsyntax] = STATE(83),
    [sym_unsyntax_splicing] = STATE(83),
    [sym_datum_label] = STATE(83),
    [sym_datum_reference] = STATE(83),
    [aux_sym_sexp_comment_repeat1] = STATE(21),
    [aux_sym__intertoken_token1] = ACTIONS(293),
    [sym_comment] = ACTIONS(293),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(295),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(295),
    [sym_keyword] = ACTIONS(297),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [26] = {
    [sym__intertoken] = STATE(22),
    [sym__datum] = STATE(85),
    [sym_block_comment] = STATE(22),
    [sym_sexp_comment] = STATE(22),
    [sym_directive] = STATE(22),
    [sym_boolean] = STATE(85),
    [sym_character] = STATE(85),
    [sym_string] = STATE(85),
    [sym_list] = STATE(85),
    [sym_vector] = STATE(85),
    [sym_byte_vector] = STATE(85),
    [sym_quote] = STATE(85),
    [sym_quasiquote] = STATE(85),
    [sym_unquote] = STATE(85),
    [sym_unquote_splicing] = STATE(85),
    [sym_syntax_quote] = STATE(85),
    [sym_quasisyntax] = STATE(85),
    [sym_unsyntax] = STATE(85),
    [sym_unsyntax_splicing] = STATE(85),
    [sym_datum_label] = STATE(85),
    [sym_datum_reference] = STATE(85),
    [aux_sym_sexp_comment_repeat1] = STATE(22),
    [aux_sym__intertoken_token1] = ACTIONS(299),
    [sym_comment] = ACTIONS(299),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(301),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(301),
    [sym_keyword] = ACTIONS(303),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [27] = {
    [sym__intertoken] = STATE(23),
    [sym__datum] = STATE(86),
    [sym_block_comment] = STATE(23),
    [sym_sexp_comment] = STATE(23),
    [sym_directive] = STATE(23),
    [sym_boolean] = STATE(86),
    [sym_character] = STATE(86),
    [sym_string] = STATE(86),
    [sym_list] = STATE(86),
    [sym_vector] = STATE(86),
    [sym_byte_vector] = STATE(86),
    [sym_quote] = STATE(86),
    [sym_quasiquote] = STATE(86),
    [sym_unquote] = STATE(86),
    [sym_unquote_splicing] = STATE(86),
    [sym_syntax_quote] = STATE(86),
    [sym_quasisyntax] = STATE(86),
    [sym_unsyntax] = STATE(86),
    [sym_unsyntax_splicing] = STATE(86),
    [sym_datum_label] = STATE(86),
    [sym_datum_reference] = STATE(86),
    [aux_sym_sexp_comment_repeat1] = STATE(23),
    [aux_sym__intertoken_token1] = ACTIONS(305),
    [sym_comment] = ACTIONS(305),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(307),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(307),
    [sym_keyword] = ACTIONS(309),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [28] = {
    [sym__intertoken] = STATE(37),
    [sym__datum] = STATE(99),
    [sym_block_comment] = STATE(37),
    [sym_sexp_comment] = STATE(37),
    [sym_directive] = STATE(37),
    [sym_boolean] = STATE(99),
    [sym_character] = STATE(99),
    [sym_string] = STATE(99),
    [sym_list] = STATE(99),
    [sym_vector] = STATE(99),
    [sym_byte_vector] = STATE(99),
    [sym_quote] = STATE(99),
    [sym_quasiquote] = STATE(99),
    [sym_unquote] = STATE(99),
    [sym_unquote_splicing] = STATE(99),
    [sym_syntax_quote] = STATE(99),
    [sym_quasisyntax] = STATE(99),
    [sym_unsyntax] = STATE(99),
    [sym_unsyntax_splicing] = STATE(99),
    [sym_datum_label] = STATE(99),
    [sym_datum_reference] = STATE(99),
    [aux_sym_sexp_comment_repeat1] = STATE(37),
    [aux_sym__intertoken_token1] = ACTIONS(311),
    [sym_comment] = ACTIONS(311),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(313),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(313),
    [sym_keyword] = ACTIONS(315),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [29] = {
    [sym__intertoken] = STATE(38),
    [sym__datum] = STATE(100),
    [sym_block_comment] = STATE(38),
    [sym_sexp_comment] = STATE(38),
    [sym_directive] = STATE(38),
    [sym_boolean] = STATE(100),
    [sym_character] = STATE(100),
    [sym_string] = STATE(100),
    [sym_list] = STATE(100),
    [sym_vector] = STATE(100),
    [sym_byte_vector] = STATE(100),
    [sym_quote] = STATE(100),
    [sym_quasiquote] = STATE(100),
    [sym_unquote] = STATE(100),
    [sym_unquote_splicing] = STATE(100),
    [sym_syntax_quote] = STATE(100),
    [sym_quasisyntax] = STATE(100),
    [sym_unsyntax] = STATE(100),
    [sym_unsyntax_splicing] = STATE(100),
    [sym_datum_label] = STATE(100),
    [sym_datum_reference] = STATE(100),
    [aux_sym_sexp_comment_repeat1] = STATE(38),
    [aux_sym__intertoken_token1] = ACTIONS(317),
    [sym_comment] = ACTIONS(317),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(319),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(319),
    [sym_keyword] = ACTIONS(321),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [30] = {
    [sym__intertoken] = STATE(39),
    [sym__datum] = STATE(102),
    [sym_block_comment] = STATE(39),
    [sym_sexp_comment] = STATE(39),
    [sym_directive] = STATE(39),
    [sym_boolean] = STATE(102),
    [sym_character] = STATE(102),
    [sym_string] = STATE(102),
    [sym_list] = STATE(102),
    [sym_vector] = STATE(102),
    [sym_byte_vector] = STATE(102),
    [sym_quote] = STATE(102),
    [sym_quasiquote] = STATE(102),
    [sym_unquote] = STATE(102),
    [sym_unquote_splicing] = STATE(102),
    [sym_syntax_quote] = STATE(102),
    [sym_quasisyntax] = STATE(102),
    [sym_unsyntax] = STATE(102),
    [sym_unsyntax_splicing] = STATE(102),
    [sym_datum_label] = STATE(102),
    [sym_datum_reference] = STATE(102),
    [aux_sym_sexp_comment_repeat1] = STATE(39),
    [aux_sym__intertoken_token1] = ACTIONS(323),
    [sym_comment] = ACTIONS(323),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(325),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(325),
    [sym_keyword] = ACTIONS(327),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [31] = {
    [sym__intertoken] = STATE(47),
    [sym__datum] = STATE(87),
    [sym_block_comment] = STATE(47),
    [sym_sexp_comment] = STATE(47),
    [sym_directive] = STATE(47),
    [sym_boolean] = STATE(87),
    [sym_character] = STATE(87),
    [sym_string] = STATE(87),
    [sym_list] = STATE(87),
    [sym_vector] = STATE(87),
    [sym_byte_vector] = STATE(87),
    [sym_quote] = STATE(87),
    [sym_quasiquote] = STATE(87),
    [sym_unquote] = STATE(87),
    [sym_unquote_splicing] = STATE(87),
    [sym_syntax_quote] = STATE(87),
    [sym_quasisyntax] = STATE(87),
    [sym_unsyntax] = STATE(87),
    [sym_unsyntax_splicing] = STATE(87),
    [sym_datum_label] = STATE(87),
    [sym_datum_reference] = STATE(87),
    [aux_sym_sexp_comment_repeat1] = STATE(47),
    [aux_sym__intertoken_token1] = ACTIONS(329),
    [sym_comment] = ACTIONS(329),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(331),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(331),
    [sym_keyword] = ACTIONS(333),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [32] = {
    [sym__intertoken] = STATE(41),
    [sym__datum] = STATE(105),
    [sym_block_comment] = STATE(41),
    [sym_sexp_comment] = STATE(41),
    [sym_directive] = STATE(41),
    [sym_boolean] = STATE(105),
    [sym_character] = STATE(105),
    [sym_string] = STATE(105),
    [sym_list] = STATE(105),
    [sym_vector] = STATE(105),
    [sym_byte_vector] = STATE(105),
    [sym_quote] = STATE(105),
    [sym_quasiquote] = STATE(105),
    [sym_unquote] = STATE(105),
    [sym_unquote_splicing] = STATE(105),
    [sym_syntax_quote] = STATE(105),
    [sym_quasisyntax] = STATE(105),
    [sym_unsyntax] = STATE(105),
    [sym_unsyntax_splicing] = STATE(105),
    [sym_datum_label] = STATE(105),
    [sym_datum_reference] = STATE(105),
    [aux_sym_sexp_comment_repeat1] = STATE(41),
    [aux_sym__intertoken_token1] = ACTIONS(335),
    [sym_comment] = ACTIONS(335),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(337),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(337),
    [sym_keyword] = ACTIONS(339),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [33] = {
    [sym__intertoken] = STATE(42),
    [sym__datum] = STATE(106),
    [sym_block_comment] = STATE(42),
    [sym_sexp_comment] = STATE(42),
    [sym_directive] = STATE(42),
    [sym_boolean] = STATE(106),
    [sym_character] = STATE(106),
    [sym_string] = STATE(106),
    [sym_list] = STATE(106),
    [sym_vector] = STATE(106),
    [sym_byte_vector] = STATE(106),
    [sym_quote] = STATE(106),
    [sym_quasiquote] = STATE(106),
    [sym_unquote] = STATE(106),
    [sym_unquote_splicing] = STATE(106),
    [sym_syntax_quote] = STATE(106),
    [sym_quasisyntax] = STATE(106),
    [sym_unsyntax] = STATE(106),
    [sym_unsyntax_splicing] = STATE(106),
    [sym_datum_label] = STATE(106),
    [sym_datum_reference] = STATE(106),
    [aux_sym_sexp_comment_repeat1] = STATE(42),
    [aux_sym__intertoken_token1] = ACTIONS(341),
    [sym_comment] = ACTIONS(341),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(343),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(343),
    [sym_keyword] = ACTIONS(345),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [34] = {
    [sym__intertoken] = STATE(43),
    [sym__datum] = STATE(107),
    [sym_block_comment] = STATE(43),
    [sym_sexp_comment] = STATE(43),
    [sym_directive] = STATE(43),
    [sym_boolean] = STATE(107),
    [sym_character] = STATE(107),
    [sym_string] = STATE(107),
    [sym_list] = STATE(107),
    [sym_vector] = STATE(107),
    [sym_byte_vector] = STATE(107),
    [sym_quote] = STATE(107),
    [sym_quasiquote] = STATE(107),
    [sym_unquote] = STATE(107),
    [sym_unquote_splicing] = STATE(107),
    [sym_syntax_quote] = STATE(107),
    [sym_quasisyntax] = STATE(107),
    [sym_unsyntax] = STATE(107),
    [sym_unsyntax_splicing] = STATE(107),
    [sym_datum_label] = STATE(107),
    [sym_datum_reference] = STATE(107),
    [aux_sym_sexp_comment_repeat1] = STATE(43),
    [aux_sym__intertoken_token1] = ACTIONS(347),
    [sym_comment] = ACTIONS(347),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(349),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(349),
    [sym_keyword] = ACTIONS(351),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [35] = {
    [sym__intertoken] = STATE(44),
    [sym__datum] = STATE(108),
    [sym_block_comment] = STATE(44),
    [sym_sexp_comment] = STATE(44),
    [sym_directive] = STATE(44),
    [sym_boolean] = STATE(108),
    [sym_character] = STATE(108),
    [sym_string] = STATE(108),
    [sym_list] = STATE(108),
    [sym_vector] = STATE(108),
    [sym_byte_vector] = STATE(108),
    [sym_quote] = STATE(108),
    [sym_quasiquote] = STATE(108),
    [sym_unquote] = STATE(108),
    [sym_unquote_splicing] = STATE(108),
    [sym_syntax_quote] = STATE(108),
    [sym_quasisyntax] = STATE(108),
    [sym_unsyntax] = STATE(108),
    [sym_unsyntax_splicing] = STATE(108),
    [sym_datum_label] = STATE(108),
    [sym_datum_reference] = STATE(108),
    [aux_sym_sexp_comment_repeat1] = STATE(44),
    [aux_sym__intertoken_token1] = ACTIONS(353),
    [sym_comment] = ACTIONS(353),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(355),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(355),
    [sym_keyword] = ACTIONS(357),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [36] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(109),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(109),
    [sym_character] = STATE(109),
    [sym_string] = STATE(109),
    [sym_list] = STATE(109),
    [sym_vector] = STATE(109),
    [sym_byte_vector] = STATE(109),
    [sym_quote] = STATE(109),
    [sym_quasiquote] = STATE(109),
    [sym_unquote] = STATE(109),
    [sym_unquote_splicing] = STATE(109),
    [sym_syntax_quote] = STATE(109),
    [sym_quasisyntax] = STATE(109),
    [sym_unsyntax] = STATE(109),
    [sym_unsyntax_splicing] = STATE(109),
    [sym_datum_label] = STATE(109),
    [sym_datum_reference] = STATE(109),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(359),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(359),
    [sym_keyword] = ACTIONS(361),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [37] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(115),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(115),
    [sym_character] = STATE(115),
    [sym_string] = STATE(115),
    [sym_list] = STATE(115),
    [sym_vector] = STATE(115),
    [sym_byte_vector] = STATE(115),
    [sym_quote] = STATE(115),
    [sym_quasiquote] = STATE(115),
    [sym_unquote] = STATE(115),
    [sym_unquote_splicing] = STATE(115),
    [sym_syntax_quote] = STATE(115),
    [sym_quasisyntax] = STATE(115),
    [sym_unsyntax] = STATE(115),
    [sym_unsyntax_splicing] = STATE(115),
    [sym_datum_label] = STATE(115),
    [sym_datum_reference] = STATE(115),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(363),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(363),
    [sym_keyword] = ACTIONS(365),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [38] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(116),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(116),
    [sym_character] = STATE(116),
    [sym_string] = STATE(116),
    [sym_list] = STATE(116),
    [sym_vector] = STATE(116),
    [sym_byte_vector] = STATE(116),
    [sym_quote] = STATE(116),
    [sym_quasiquote] = STATE(116),
    [sym_unquote] = STATE(116),
    [sym_unquote_splicing] = STATE(116),
    [sym_syntax_quote] = STATE(116),
    [sym_quasisyntax] = STATE(116),
    [sym_unsyntax] = STATE(116),
    [sym_unsyntax_splicing] = STATE(116),
    [sym_datum_label] = STATE(116),
    [sym_datum_reference] = STATE(116),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(367),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(367),
    [sym_keyword] = ACTIONS(369),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [39] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(117),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(117),
    [sym_character] = STATE(117),
    [sym_string] = STATE(117),
    [sym_list] = STATE(117),
    [sym_vector] = STATE(117),
    [sym_byte_vector] = STATE(117),
    [sym_quote] = STATE(117),
    [sym_quasiquote] = STATE(117),
    [sym_unquote] = STATE(117),
    [sym_unquote_splicing] = STATE(117),
    [sym_syntax_quote] = STATE(117),
    [sym_quasisyntax] = STATE(117),
    [sym_unsyntax] = STATE(117),
    [sym_unsyntax_splicing] = STATE(117),
    [sym_datum_label] = STATE(117),
    [sym_datum_reference] = STATE(117),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(371),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(371),
    [sym_keyword] = ACTIONS(373),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [40] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(118),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(118),
    [sym_character] = STATE(118),
    [sym_string] = STATE(118),
    [sym_list] = STATE(118),
    [sym_vector] = STATE(118),
    [sym_byte_vector] = STATE(118),
    [sym_quote] = STATE(118),
    [sym_quasiquote] = STATE(118),
    [sym_unquote] = STATE(118),
    [sym_unquote_splicing] = STATE(118),
    [sym_syntax_quote] = STATE(118),
    [sym_quasisyntax] = STATE(118),
    [sym_unsyntax] = STATE(118),
    [sym_unsyntax_splicing] = STATE(118),
    [sym_datum_label] = STATE(118),
    [sym_datum_reference] = STATE(118),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(375),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(375),
    [sym_keyword] = ACTIONS(377),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [41] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(119),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(119),
    [sym_character] = STATE(119),
    [sym_string] = STATE(119),
    [sym_list] = STATE(119),
    [sym_vector] = STATE(119),
    [sym_byte_vector] = STATE(119),
    [sym_quote] = STATE(119),
    [sym_quasiquote] = STATE(119),
    [sym_unquote] = STATE(119),
    [sym_unquote_splicing] = STATE(119),
    [sym_syntax_quote] = STATE(119),
    [sym_quasisyntax] = STATE(119),
    [sym_unsyntax] = STATE(119),
    [sym_unsyntax_splicing] = STATE(119),
    [sym_datum_label] = STATE(119),
    [sym_datum_reference] = STATE(119),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(379),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(379),
    [sym_keyword] = ACTIONS(381),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [42] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(120),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(120),
    [sym_character] = STATE(120),
    [sym_string] = STATE(120),
    [sym_list] = STATE(120),
    [sym_vector] = STATE(120),
    [sym_byte_vector] = STATE(120),
    [sym_quote] = STATE(120),
    [sym_quasiquote] = STATE(120),
    [sym_unquote] = STATE(120),
    [sym_unquote_splicing] = STATE(120),
    [sym_syntax_quote] = STATE(120),
    [sym_quasisyntax] = STATE(120),
    [sym_unsyntax] = STATE(120),
    [sym_unsyntax_splicing] = STATE(120),
    [sym_datum_label] = STATE(120),
    [sym_datum_reference] = STATE(120),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(383),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(383),
    [sym_keyword] = ACTIONS(385),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [43] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(121),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(121),
    [sym_character] = STATE(121),
    [sym_string] = STATE(121),
    [sym_list] = STATE(121),
    [sym_vector] = STATE(121),
    [sym_byte_vector] = STATE(121),
    [sym_quote] = STATE(121),
    [sym_quasiquote] = STATE(121),
    [sym_unquote] = STATE(121),
    [sym_unquote_splicing] = STATE(121),
    [sym_syntax_quote] = STATE(121),
    [sym_quasisyntax] = STATE(121),
    [sym_unsyntax] = STATE(121),
    [sym_unsyntax_splicing] = STATE(121),
    [sym_datum_label] = STATE(121),
    [sym_datum_reference] = STATE(121),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(387),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(387),
    [sym_keyword] = ACTIONS(389),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [44] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(122),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(122),
    [sym_character] = STATE(122),
    [sym_string] = STATE(122),
    [sym_list] = STATE(122),
    [sym_vector] = STATE(122),
    [sym_byte_vector] = STATE(122),
    [sym_quote] = STATE(122),
    [sym_quasiquote] = STATE(122),
    [sym_unquote] = STATE(122),
    [sym_unquote_splicing] = STATE(122),
    [sym_syntax_quote] = STATE(122),
    [sym_quasisyntax] = STATE(122),
    [sym_unsyntax] = STATE(122),
    [sym_unsyntax_splicing] = STATE(122),
    [sym_datum_label] = STATE(122),
    [sym_datum_reference] = STATE(122),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(391),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(391),
    [sym_keyword] = ACTIONS(393),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
  [45] = {
    [sym__intertoken] = STATE(24),
    [sym__datum] = STATE(88),
    [sym_block_comment] = STATE(24),
    [sym_sexp_comment] = STATE(24),
    [sym_directive] = STATE(24),
    [sym_boolean] = STATE(88),
    [sym_character] = STATE(88),
    [sym_string] = STATE(88),
    [sym_list] = STATE(88),
    [sym_vector] = STATE(88),
    [sym_byte_vector] = STATE(88),
    [sym_quote] = STATE(88),
    [sym_quasiquote] = STATE(88),
    [sym_unquote] = STATE(88),
    [sym_unquote_splicing] = STATE(88),
    [sym_syntax_quote] = STATE(88),
    [sym_quasisyntax] = STATE(88),
    [sym_unsyntax] = STATE(88),
    [sym_unsyntax_splicing] = STATE(88),
    [sym_datum_label] = STATE(88),
    [sym_datum_reference] = STATE(88),
    [aux_sym_sexp_comment_repeat1] = STATE(24),
    [aux_sym__intertoken_token1] = ACTIONS(395),
    [sym_comment] = ACTIONS(395),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(397),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(397),
    [sym_keyword] = ACTIONS(399),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [46] = {
    [sym__intertoken] = STATE(51),
    [sym__datum] = STATE(79),
    [sym_block_comment] = STATE(51),
    [sym_sexp_comment] = STATE(51),
    [sym_directive] = STATE(51),
    [sym_boolean] = STATE(79),
    [sym_character] = STATE(79),
    [sym_string] = STATE(79),
    [sym_list] = STATE(79),
    [sym_vector] = STATE(79),
    [sym_byte_vector] = STATE(79),
    [sym_quote] = STATE(79),
    [sym_quasiquote] = STATE(79),
    [sym_unquote] = STATE(79),
    [sym_unquote_splicing] = STATE(79),
    [sym_syntax_quote] = STATE(79),
    [sym_quasisyntax] = STATE(79),
    [sym_unsyntax] = STATE(79),
    [sym_unsyntax_splicing] = STATE(79),
    [sym_datum_label] = STATE(79),
    [sym_datum_reference] = STATE(79),
    [aux_sym_sexp_comment_repeat1] = STATE(51),
    [aux_sym__intertoken_token1] = ACTIONS(401),
    [sym_comment] = ACTIONS(401),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(403),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(403),
    [sym_keyword] = ACTIONS(405),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [47] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(58),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(58),
    [sym_character] = STATE(58),
    [sym_string] = STATE(58),
    [sym_list] = STATE(58),
    [sym_vector] = STATE(58),
    [sym_byte_vector] = STATE(58),
    [sym_quote] = STATE(58),
    [sym_quasiquote] = STATE(58),
    [sym_unquote] = STATE(58),
    [sym_unquote_splicing] = STATE(58),
    [sym_syntax_quote] = STATE(58),
    [sym_quasisyntax] = STATE(58),
    [sym_unsyntax] = STATE(58),
    [sym_unsyntax_splicing] = STATE(58),
    [sym_datum_label] = STATE(58),
    [sym_datum_reference] = STATE(58),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(407),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(407),
    [sym_keyword] = ACTIONS(409),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [48] = {
    [sym__intertoken] = STATE(18),
    [sym__datum] = STATE(89),
    [sym_block_comment] = STATE(18),
    [sym_sexp_comment] = STATE(18),
    [sym_directive] = STATE(18),
    [sym_boolean] = STATE(89),
    [sym_character] = STATE(89),
    [sym_string] = STATE(89),
    [sym_list] = STATE(89),
    [sym_vector] = STATE(89),
    [sym_byte_vector] = STATE(89),
    [sym_quote] = STATE(89),
    [sym_quasiquote] = STATE(89),
    [sym_unquote] = STATE(89),
    [sym_unquote_splicing] = STATE(89),
    [sym_syntax_quote] = STATE(89),
    [sym_quasisyntax] = STATE(89),
    [sym_unsyntax] = STATE(89),
    [sym_unsyntax_splicing] = STATE(89),
    [sym_datum_label] = STATE(89),
    [sym_datum_reference] = STATE(89),
    [aux_sym_sexp_comment_repeat1] = STATE(18),
    [aux_sym__intertoken_token1] = ACTIONS(411),
    [sym_comment] = ACTIONS(411),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(413),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(413),
    [sym_keyword] = ACTIONS(415),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [49] = {
    [sym__intertoken] = STATE(19),
    [sym__datum] = STATE(81),
    [sym_block_comment] = STATE(19),
    [sym_sexp_comment] = STATE(19),
    [sym_directive] = STATE(19),
    [sym_boolean] = STATE(81),
    [sym_character] = STATE(81),
    [sym_string] = STATE(81),
    [sym_list] = STATE(81),
    [sym_vector] = STATE(81),
    [sym_byte_vector] = STATE(81),
    [sym_quote] = STATE(81),
    [sym_quasiquote] = STATE(81),
    [sym_unquote] = STATE(81),
    [sym_unquote_splicing] = STATE(81),
    [sym_syntax_quote] = STATE(81),
    [sym_quasisyntax] = STATE(81),
    [sym_unsyntax] = STATE(81),
    [sym_unsyntax_splicing] = STATE(81),
    [sym_datum_label] = STATE(81),
    [sym_datum_reference] = STATE(81),
    [aux_sym_sexp_comment_repeat1] = STATE(19),
    [aux_sym__intertoken_token1] = ACTIONS(417),
    [sym_comment] = ACTIONS(417),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(419),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(419),
    [sym_keyword] = ACTIONS(421),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [50] = {
    [sym__intertoken] = STATE(20),
    [sym__datum] = STATE(82),
    [sym_block_comment] = STATE(20),
    [sym_sexp_comment] = STATE(20),
    [sym_directive] = STATE(20),
    [sym_boolean] = STATE(82),
    [sym_character] = STATE(82),
    [sym_string] = STATE(82),
    [sym_list] = STATE(82),
    [sym_vector] = STATE(82),
    [sym_byte_vector] = STATE(82),
    [sym_quote] = STATE(82),
    [sym_quasiquote] = STATE(82),
    [sym_unquote] = STATE(82),
    [sym_unquote_splicing] = STATE(82),
    [sym_syntax_quote] = STATE(82),
    [sym_quasisyntax] = STATE(82),
    [sym_unsyntax] = STATE(82),
    [sym_unsyntax_splicing] = STATE(82),
    [sym_datum_label] = STATE(82),
    [sym_datum_reference] = STATE(82),
    [aux_sym_sexp_comment_repeat1] = STATE(20),
    [aux_sym__intertoken_token1] = ACTIONS(423),
    [sym_comment] = ACTIONS(423),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(425),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(425),
    [sym_keyword] = ACTIONS(427),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [51] = {
    [sym__intertoken] = STATE(55),
    [sym__datum] = STATE(66),
    [sym_block_comment] = STATE(55),
    [sym_sexp_comment] = STATE(55),
    [sym_directive] = STATE(55),
    [sym_boolean] = STATE(66),
    [sym_character] = STATE(66),
    [sym_string] = STATE(66),
    [sym_list] = STATE(66),
    [sym_vector] = STATE(66),
    [sym_byte_vector] = STATE(66),
    [sym_quote] = STATE(66),
    [sym_quasiquote] = STATE(66),
    [sym_unquote] = STATE(66),
    [sym_unquote_splicing] = STATE(66),
    [sym_syntax_quote] = STATE(66),
    [sym_quasisyntax] = STATE(66),
    [sym_unsyntax] = STATE(66),
    [sym_unsyntax_splicing] = STATE(66),
    [sym_datum_label] = STATE(66),
    [sym_datum_reference] = STATE(66),
    [aux_sym_sexp_comment_repeat1] = STATE(55),
    [aux_sym__intertoken_token1] = ACTIONS(263),
    [sym_comment] = ACTIONS(263),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [sym_number] = ACTIONS(429),
    [anon_sym_POUND_BSLASH] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [sym_symbol] = ACTIONS(429),
    [sym_keyword] = ACTIONS(431),
    [anon_sym_LPAREN] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(25),
    [anon_sym_POUND_LPAREN] = ACTIONS(27),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(29),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_BQUOTE] = ACTIONS(33),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND_SQUOTE] = ACTIONS(39),
    [anon_sym_POUND_BQUOTE] = ACTIONS(41),
    [anon_sym_POUND_COMMA] = ACTIONS(43),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(45),
  },
  [52] = {
    [sym__intertoken] = STATE(40),
    [sym__datum] = STATE(104),
    [sym_block_comment] = STATE(40),
    [sym_sexp_comment] = STATE(40),
    [sym_directive] = STATE(40),
    [sym_boolean] = STATE(104),
    [sym_character] = STATE(104),
    [sym_string] = STATE(104),
    [sym_list] = STATE(104),
    [sym_vector] = STATE(104),
    [sym_byte_vector] = STATE(104),
    [sym_quote] = STATE(104),
    [sym_quasiquote] = STATE(104),
    [sym_unquote] = STATE(104),
    [sym_unquote_splicing] = STATE(104),
    [sym_syntax_quote] = STATE(104),
    [sym_quasisyntax] = STATE(104),
    [sym_unsyntax] = STATE(104),
    [sym_unsyntax_splicing] = STATE(104),
    [sym_datum_label] = STATE(104),
    [sym_datum_reference] = STATE(104),
    [aux_sym_sexp_comment_repeat1] = STATE(40),
    [aux_sym__intertoken_token1] = ACTIONS(433),
    [sym_comment] = ACTIONS(433),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [anon_sym_POUND_BANG] = ACTIONS(11),
    [aux_sym_directive_token2] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(229),
    [sym_number] = ACTIONS(435),
    [anon_sym_POUND_BSLASH] = ACTIONS(233),
    [anon_sym_DQUOTE] = ACTIONS(235),
    [sym_symbol] = ACTIONS(435),
    [sym_keyword] = ACTIONS(437),
    [anon_sym_LPAREN] = ACTIONS(239),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_POUND_LPAREN] = ACTIONS(243),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(245),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(245),
    [anon_sym_SQUOTE] = ACTIONS(247),
    [anon_sym_BQUOTE] = ACTIONS(249),
    [anon_sym_COMMA] = ACTIONS(251),
    [anon_sym_COMMA_AT] = ACTIONS(253),
    [anon_sym_POUND_SQUOTE] = ACTIONS(255),
    [anon_sym_POUND_BQUOTE] = ACTIONS(257),
    [anon_sym_POUND_COMMA] = ACTIONS(259),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(261),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 18,
    ACTIONS(229), 1,
      anon_sym_POUND,
    ACTIONS(233), 1,
      anon_sym_POUND_BSLASH,
    ACTIONS(235), 1,
      anon_sym_DQUOTE,
    ACTIONS(239), 1,
      anon_sym_LPAREN,
    ACTIONS(241), 1,
      anon_sym_LBRACK,
    ACTIONS(243), 1,
      anon_sym_POUND_LPAREN,
    ACTIONS(247), 1,
      anon_sym_SQUOTE,
    ACTIONS(249), 1,
      anon_sym_BQUOTE,
    ACTIONS(251), 1,
      anon_sym_COMMA,
    ACTIONS(253), 1,
      anon_sym_COMMA_AT,
    ACTIONS(255), 1,
      anon_sym_POUND_SQUOTE,
    ACTIONS(257), 1,
      anon_sym_POUND_BQUOTE,
    ACTIONS(259), 1,
      anon_sym_POUND_COMMA,
    ACTIONS(261), 1,
      anon_sym_POUND_COMMA_AT,
    ACTIONS(441), 1,
      sym_keyword,
    ACTIONS(245), 2,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
    ACTIONS(439), 2,
      sym_number,
      sym_symbol,
    STATE(123), 17,
      sym__datum,
      sym_boolean,
      sym_character,
      sym_string,
      sym_list,
      sym_vector,
      sym_byte_vector,
      sym_quote,
      sym_quasiquote,
      sym_unquote,
      sym_unquote_splicing,
      sym_syntax_quote,
      sym_quasisyntax,
      sym_unsyntax,
      sym_unsyntax_splicing,
      sym_datum_label,
      sym_datum_reference,
  [73] = 18,
    ACTIONS(15), 1,
      anon_sym_POUND,
    ACTIONS(19), 1,
      anon_sym_POUND_BSLASH,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_POUND_LPAREN,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(33), 1,
      anon_sym_BQUOTE,
    ACTIONS(35), 1,
      anon_sym_COMMA,
    ACTIONS(37), 1,
      anon_sym_COMMA_AT,
    ACTIONS(39), 1,
      anon_sym_POUND_SQUOTE,
    ACTIONS(41), 1,
      anon_sym_POUND_BQUOTE,
    ACTIONS(43), 1,
      anon_sym_POUND_COMMA,
    ACTIONS(45), 1,
      anon_sym_POUND_COMMA_AT,
    ACTIONS(445), 1,
      sym_keyword,
    ACTIONS(29), 2,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
    ACTIONS(443), 2,
      sym_number,
      sym_symbol,
    STATE(74), 17,
      sym__datum,
      sym_boolean,
      sym_character,
      sym_string,
      sym_list,
      sym_vector,
      sym_byte_vector,
      sym_quote,
      sym_quasiquote,
      sym_unquote,
      sym_unquote_splicing,
      sym_syntax_quote,
      sym_quasisyntax,
      sym_unsyntax,
      sym_unsyntax_splicing,
      sym_datum_label,
      sym_datum_reference,
  [146] = 8,
    ACTIONS(450), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(453), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(456), 1,
      anon_sym_POUND_BANG,
    ACTIONS(459), 1,
      aux_sym_directive_token2,
    ACTIONS(447), 2,
      aux_sym__intertoken_token1,
      sym_comment,
    ACTIONS(462), 5,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    STATE(55), 5,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      sym_directive,
      aux_sym_sexp_comment_repeat1,
    ACTIONS(464), 14,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [193] = 2,
    ACTIONS(468), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(466), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [227] = 2,
    ACTIONS(472), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(470), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [261] = 2,
    ACTIONS(476), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(474), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [295] = 2,
    ACTIONS(480), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(478), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [329] = 2,
    ACTIONS(484), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(482), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [363] = 2,
    ACTIONS(488), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(486), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [397] = 2,
    ACTIONS(492), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(490), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [431] = 2,
    ACTIONS(496), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(494), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [465] = 2,
    ACTIONS(500), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(498), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [499] = 2,
    ACTIONS(504), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(502), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [533] = 2,
    ACTIONS(508), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(506), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [567] = 2,
    ACTIONS(512), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(510), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [601] = 2,
    ACTIONS(516), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(514), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [635] = 2,
    ACTIONS(520), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(518), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [669] = 2,
    ACTIONS(524), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(522), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [703] = 2,
    ACTIONS(528), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(526), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [737] = 2,
    ACTIONS(532), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(530), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [771] = 2,
    ACTIONS(536), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(534), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [805] = 2,
    ACTIONS(540), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(538), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [839] = 2,
    ACTIONS(544), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(542), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [873] = 2,
    ACTIONS(548), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(546), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [907] = 2,
    ACTIONS(552), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(550), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [941] = 2,
    ACTIONS(556), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(554), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [975] = 2,
    ACTIONS(560), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(558), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1009] = 2,
    ACTIONS(564), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(562), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1043] = 2,
    ACTIONS(568), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(566), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1077] = 2,
    ACTIONS(572), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(570), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1111] = 2,
    ACTIONS(576), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(574), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1145] = 2,
    ACTIONS(580), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(578), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1179] = 2,
    ACTIONS(584), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(582), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1213] = 2,
    ACTIONS(588), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(586), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1247] = 2,
    ACTIONS(592), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(590), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1281] = 2,
    ACTIONS(596), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(594), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1315] = 2,
    ACTIONS(600), 7,
      anon_sym_POUND_BANG,
      anon_sym_POUND,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(598), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      anon_sym_POUND_BSLASH,
      anon_sym_DQUOTE,
      sym_keyword,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_POUNDu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [1349] = 7,
    ACTIONS(604), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(606), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(608), 1,
      anon_sym_POUND_BANG,
    ACTIONS(610), 1,
      aux_sym_directive_token2,
    ACTIONS(612), 1,
      anon_sym_RPAREN,
    ACTIONS(602), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_number,
    STATE(93), 5,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      sym_directive,
      aux_sym_byte_vector_repeat1,
  [1377] = 7,
    ACTIONS(604), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(606), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(608), 1,
      anon_sym_POUND_BANG,
    ACTIONS(610), 1,
      aux_sym_directive_token2,
    ACTIONS(614), 1,
      anon_sym_RPAREN,
    ACTIONS(602), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_number,
    STATE(93), 5,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      sym_directive,
      aux_sym_byte_vector_repeat1,
  [1405] = 7,
    ACTIONS(604), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(606), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(608), 1,
      anon_sym_POUND_BANG,
    ACTIONS(610), 1,
      aux_sym_directive_token2,
    ACTIONS(618), 1,
      anon_sym_RPAREN,
    ACTIONS(616), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_number,
    STATE(91), 5,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      sym_directive,
      aux_sym_byte_vector_repeat1,
  [1433] = 7,
    ACTIONS(623), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(626), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(629), 1,
      anon_sym_POUND_BANG,
    ACTIONS(632), 1,
      aux_sym_directive_token2,
    ACTIONS(635), 1,
      anon_sym_RPAREN,
    ACTIONS(620), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_number,
    STATE(93), 5,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      sym_directive,
      aux_sym_byte_vector_repeat1,
  [1461] = 7,
    ACTIONS(604), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(606), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(608), 1,
      anon_sym_POUND_BANG,
    ACTIONS(610), 1,
      aux_sym_directive_token2,
    ACTIONS(639), 1,
      anon_sym_RPAREN,
    ACTIONS(637), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_number,
    STATE(90), 5,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      sym_directive,
      aux_sym_byte_vector_repeat1,
  [1489] = 2,
    ACTIONS(480), 1,
      anon_sym_POUND_BANG,
    ACTIONS(478), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1502] = 2,
    ACTIONS(544), 1,
      anon_sym_POUND_BANG,
    ACTIONS(542), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1515] = 2,
    ACTIONS(548), 1,
      anon_sym_POUND_BANG,
    ACTIONS(546), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1528] = 2,
    ACTIONS(556), 1,
      anon_sym_POUND_BANG,
    ACTIONS(554), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1541] = 2,
    ACTIONS(560), 1,
      anon_sym_POUND_BANG,
    ACTIONS(558), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1554] = 2,
    ACTIONS(600), 1,
      anon_sym_POUND_BANG,
    ACTIONS(598), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1567] = 2,
    ACTIONS(564), 1,
      anon_sym_POUND_BANG,
    ACTIONS(562), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1580] = 2,
    ACTIONS(568), 1,
      anon_sym_POUND_BANG,
    ACTIONS(566), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1593] = 2,
    ACTIONS(552), 1,
      anon_sym_POUND_BANG,
    ACTIONS(550), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1606] = 2,
    ACTIONS(572), 1,
      anon_sym_POUND_BANG,
    ACTIONS(570), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1619] = 2,
    ACTIONS(576), 1,
      anon_sym_POUND_BANG,
    ACTIONS(574), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1632] = 2,
    ACTIONS(584), 1,
      anon_sym_POUND_BANG,
    ACTIONS(582), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1645] = 2,
    ACTIONS(588), 1,
      anon_sym_POUND_BANG,
    ACTIONS(586), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1658] = 2,
    ACTIONS(596), 1,
      anon_sym_POUND_BANG,
    ACTIONS(594), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1671] = 2,
    ACTIONS(476), 1,
      anon_sym_POUND_BANG,
    ACTIONS(474), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1684] = 2,
    ACTIONS(484), 1,
      anon_sym_POUND_BANG,
    ACTIONS(482), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1697] = 2,
    ACTIONS(488), 1,
      anon_sym_POUND_BANG,
    ACTIONS(486), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1710] = 2,
    ACTIONS(492), 1,
      anon_sym_POUND_BANG,
    ACTIONS(490), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1723] = 2,
    ACTIONS(500), 1,
      anon_sym_POUND_BANG,
    ACTIONS(498), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1736] = 2,
    ACTIONS(504), 1,
      anon_sym_POUND_BANG,
    ACTIONS(502), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1749] = 2,
    ACTIONS(508), 1,
      anon_sym_POUND_BANG,
    ACTIONS(506), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1762] = 2,
    ACTIONS(512), 1,
      anon_sym_POUND_BANG,
    ACTIONS(510), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1775] = 2,
    ACTIONS(516), 1,
      anon_sym_POUND_BANG,
    ACTIONS(514), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1788] = 2,
    ACTIONS(520), 1,
      anon_sym_POUND_BANG,
    ACTIONS(518), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1801] = 2,
    ACTIONS(468), 1,
      anon_sym_POUND_BANG,
    ACTIONS(466), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1814] = 2,
    ACTIONS(528), 1,
      anon_sym_POUND_BANG,
    ACTIONS(526), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1827] = 2,
    ACTIONS(532), 1,
      anon_sym_POUND_BANG,
    ACTIONS(530), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1840] = 2,
    ACTIONS(536), 1,
      anon_sym_POUND_BANG,
    ACTIONS(534), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1853] = 2,
    ACTIONS(540), 1,
      anon_sym_POUND_BANG,
    ACTIONS(538), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1866] = 2,
    ACTIONS(580), 1,
      anon_sym_POUND_BANG,
    ACTIONS(578), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1879] = 2,
    ACTIONS(472), 1,
      anon_sym_POUND_BANG,
    ACTIONS(470), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1892] = 2,
    ACTIONS(496), 1,
      anon_sym_POUND_BANG,
    ACTIONS(494), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1905] = 2,
    ACTIONS(524), 1,
      anon_sym_POUND_BANG,
    ACTIONS(522), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1918] = 2,
    ACTIONS(592), 1,
      anon_sym_POUND_BANG,
    ACTIONS(590), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      aux_sym_directive_token2,
      sym_number,
      anon_sym_RPAREN,
  [1931] = 4,
    ACTIONS(641), 1,
      anon_sym_DQUOTE,
    ACTIONS(643), 1,
      aux_sym_string_token1,
    ACTIONS(645), 1,
      anon_sym_BSLASH,
    STATE(139), 2,
      sym_escape_sequence,
      aux_sym_string_repeat1,
  [1945] = 4,
    ACTIONS(647), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(649), 1,
      aux_sym_block_comment_token1,
    ACTIONS(651), 1,
      anon_sym_PIPE_POUND,
    STATE(134), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1959] = 4,
    ACTIONS(647), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(653), 1,
      aux_sym_block_comment_token1,
    ACTIONS(655), 1,
      anon_sym_PIPE_POUND,
    STATE(137), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1973] = 4,
    ACTIONS(645), 1,
      anon_sym_BSLASH,
    ACTIONS(657), 1,
      anon_sym_DQUOTE,
    ACTIONS(659), 1,
      aux_sym_string_token1,
    STATE(136), 2,
      sym_escape_sequence,
      aux_sym_string_repeat1,
  [1987] = 4,
    ACTIONS(647), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(661), 1,
      aux_sym_block_comment_token1,
    ACTIONS(663), 1,
      anon_sym_PIPE_POUND,
    STATE(140), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [2001] = 4,
    ACTIONS(647), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(661), 1,
      aux_sym_block_comment_token1,
    ACTIONS(665), 1,
      anon_sym_PIPE_POUND,
    STATE(140), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [2015] = 4,
    ACTIONS(645), 1,
      anon_sym_BSLASH,
    ACTIONS(667), 1,
      anon_sym_DQUOTE,
    ACTIONS(669), 1,
      aux_sym_string_token1,
    STATE(129), 2,
      sym_escape_sequence,
      aux_sym_string_repeat1,
  [2029] = 4,
    ACTIONS(643), 1,
      aux_sym_string_token1,
    ACTIONS(645), 1,
      anon_sym_BSLASH,
    ACTIONS(671), 1,
      anon_sym_DQUOTE,
    STATE(139), 2,
      sym_escape_sequence,
      aux_sym_string_repeat1,
  [2043] = 4,
    ACTIONS(647), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(661), 1,
      aux_sym_block_comment_token1,
    ACTIONS(673), 1,
      anon_sym_PIPE_POUND,
    STATE(140), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [2057] = 4,
    ACTIONS(647), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(675), 1,
      aux_sym_block_comment_token1,
    ACTIONS(677), 1,
      anon_sym_PIPE_POUND,
    STATE(133), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [2071] = 4,
    ACTIONS(679), 1,
      anon_sym_DQUOTE,
    ACTIONS(681), 1,
      aux_sym_string_token1,
    ACTIONS(684), 1,
      anon_sym_BSLASH,
    STATE(139), 2,
      sym_escape_sequence,
      aux_sym_string_repeat1,
  [2085] = 4,
    ACTIONS(687), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(690), 1,
      aux_sym_block_comment_token1,
    ACTIONS(693), 1,
      anon_sym_PIPE_POUND,
    STATE(140), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [2099] = 2,
    ACTIONS(697), 1,
      aux_sym_character_token4,
    ACTIONS(695), 3,
      aux_sym_character_token1,
      aux_sym_character_token2,
      aux_sym_character_token3,
  [2108] = 2,
    ACTIONS(701), 1,
      aux_sym_character_token4,
    ACTIONS(699), 3,
      aux_sym_character_token1,
      aux_sym_character_token2,
      aux_sym_character_token3,
  [2117] = 2,
    ACTIONS(472), 1,
      aux_sym_block_comment_token1,
    ACTIONS(470), 2,
      anon_sym_POUND_PIPE,
      anon_sym_PIPE_POUND,
  [2125] = 3,
    ACTIONS(703), 1,
      aux_sym_boolean_token1,
    ACTIONS(705), 1,
      aux_sym_boolean_token2,
    ACTIONS(707), 1,
      aux_sym_datum_label_token1,
  [2135] = 2,
    ACTIONS(709), 1,
      aux_sym_escape_sequence_token1,
    ACTIONS(711), 2,
      aux_sym_escape_sequence_token2,
      aux_sym_escape_sequence_token3,
  [2143] = 3,
    ACTIONS(713), 1,
      aux_sym_boolean_token1,
    ACTIONS(715), 1,
      aux_sym_boolean_token2,
    ACTIONS(717), 1,
      aux_sym_datum_label_token1,
  [2153] = 1,
    ACTIONS(719), 3,
      anon_sym_DQUOTE,
      aux_sym_string_token1,
      anon_sym_BSLASH,
  [2159] = 2,
    ACTIONS(580), 1,
      aux_sym_block_comment_token1,
    ACTIONS(578), 2,
      anon_sym_POUND_PIPE,
      anon_sym_PIPE_POUND,
  [2167] = 2,
    ACTIONS(721), 1,
      anon_sym_POUND,
    ACTIONS(723), 1,
      anon_sym_EQ,
  [2174] = 2,
    ACTIONS(725), 1,
      anon_sym_POUND,
    ACTIONS(727), 1,
      anon_sym_EQ,
  [2181] = 1,
    ACTIONS(729), 1,
      ts_builtin_sym_end,
  [2185] = 1,
    ACTIONS(731), 1,
      aux_sym_directive_token1,
  [2189] = 1,
    ACTIONS(733), 1,
      aux_sym_directive_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(53)] = 0,
  [SMALL_STATE(54)] = 73,
  [SMALL_STATE(55)] = 146,
  [SMALL_STATE(56)] = 193,
  [SMALL_STATE(57)] = 227,
  [SMALL_STATE(58)] = 261,
  [SMALL_STATE(59)] = 295,
  [SMALL_STATE(60)] = 329,
  [SMALL_STATE(61)] = 363,
  [SMALL_STATE(62)] = 397,
  [SMALL_STATE(63)] = 431,
  [SMALL_STATE(64)] = 465,
  [SMALL_STATE(65)] = 499,
  [SMALL_STATE(66)] = 533,
  [SMALL_STATE(67)] = 567,
  [SMALL_STATE(68)] = 601,
  [SMALL_STATE(69)] = 635,
  [SMALL_STATE(70)] = 669,
  [SMALL_STATE(71)] = 703,
  [SMALL_STATE(72)] = 737,
  [SMALL_STATE(73)] = 771,
  [SMALL_STATE(74)] = 805,
  [SMALL_STATE(75)] = 839,
  [SMALL_STATE(76)] = 873,
  [SMALL_STATE(77)] = 907,
  [SMALL_STATE(78)] = 941,
  [SMALL_STATE(79)] = 975,
  [SMALL_STATE(80)] = 1009,
  [SMALL_STATE(81)] = 1043,
  [SMALL_STATE(82)] = 1077,
  [SMALL_STATE(83)] = 1111,
  [SMALL_STATE(84)] = 1145,
  [SMALL_STATE(85)] = 1179,
  [SMALL_STATE(86)] = 1213,
  [SMALL_STATE(87)] = 1247,
  [SMALL_STATE(88)] = 1281,
  [SMALL_STATE(89)] = 1315,
  [SMALL_STATE(90)] = 1349,
  [SMALL_STATE(91)] = 1377,
  [SMALL_STATE(92)] = 1405,
  [SMALL_STATE(93)] = 1433,
  [SMALL_STATE(94)] = 1461,
  [SMALL_STATE(95)] = 1489,
  [SMALL_STATE(96)] = 1502,
  [SMALL_STATE(97)] = 1515,
  [SMALL_STATE(98)] = 1528,
  [SMALL_STATE(99)] = 1541,
  [SMALL_STATE(100)] = 1554,
  [SMALL_STATE(101)] = 1567,
  [SMALL_STATE(102)] = 1580,
  [SMALL_STATE(103)] = 1593,
  [SMALL_STATE(104)] = 1606,
  [SMALL_STATE(105)] = 1619,
  [SMALL_STATE(106)] = 1632,
  [SMALL_STATE(107)] = 1645,
  [SMALL_STATE(108)] = 1658,
  [SMALL_STATE(109)] = 1671,
  [SMALL_STATE(110)] = 1684,
  [SMALL_STATE(111)] = 1697,
  [SMALL_STATE(112)] = 1710,
  [SMALL_STATE(113)] = 1723,
  [SMALL_STATE(114)] = 1736,
  [SMALL_STATE(115)] = 1749,
  [SMALL_STATE(116)] = 1762,
  [SMALL_STATE(117)] = 1775,
  [SMALL_STATE(118)] = 1788,
  [SMALL_STATE(119)] = 1801,
  [SMALL_STATE(120)] = 1814,
  [SMALL_STATE(121)] = 1827,
  [SMALL_STATE(122)] = 1840,
  [SMALL_STATE(123)] = 1853,
  [SMALL_STATE(124)] = 1866,
  [SMALL_STATE(125)] = 1879,
  [SMALL_STATE(126)] = 1892,
  [SMALL_STATE(127)] = 1905,
  [SMALL_STATE(128)] = 1918,
  [SMALL_STATE(129)] = 1931,
  [SMALL_STATE(130)] = 1945,
  [SMALL_STATE(131)] = 1959,
  [SMALL_STATE(132)] = 1973,
  [SMALL_STATE(133)] = 1987,
  [SMALL_STATE(134)] = 2001,
  [SMALL_STATE(135)] = 2015,
  [SMALL_STATE(136)] = 2029,
  [SMALL_STATE(137)] = 2043,
  [SMALL_STATE(138)] = 2057,
  [SMALL_STATE(139)] = 2071,
  [SMALL_STATE(140)] = 2085,
  [SMALL_STATE(141)] = 2099,
  [SMALL_STATE(142)] = 2108,
  [SMALL_STATE(143)] = 2117,
  [SMALL_STATE(144)] = 2125,
  [SMALL_STATE(145)] = 2135,
  [SMALL_STATE(146)] = 2143,
  [SMALL_STATE(147)] = 2153,
  [SMALL_STATE(148)] = 2159,
  [SMALL_STATE(149)] = 2167,
  [SMALL_STATE(150)] = 2174,
  [SMALL_STATE(151)] = 2181,
  [SMALL_STATE(152)] = 2185,
  [SMALL_STATE(153)] = 2189,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(144),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(141),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [97] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [151] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(144),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [157] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(141),
  [160] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [163] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [169] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [172] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [175] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [178] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [181] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [184] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [187] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [190] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [193] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [196] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [251] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [259] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [273] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [277] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [281] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [295] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [301] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [313] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [319] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [331] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [337] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [343] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [349] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [355] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [359] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [367] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [371] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [375] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [379] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [383] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [387] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [391] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [397] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [403] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [407] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [413] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [419] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [425] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [429] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [435] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [439] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [443] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [447] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [450] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [453] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [456] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [459] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [462] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_syntax_quote, 3, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_syntax_quote, 3, 0, 0),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 3, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 3, 0, 0),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sexp_comment, 3, 0, 0),
  [476] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sexp_comment, 3, 0, 0),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 2, 0, 0),
  [480] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 2, 0, 0),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_datum_reference, 3, 0, 1),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_datum_reference, 3, 0, 1),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [488] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 3, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character, 2, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character, 2, 0, 0),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 3, 0, 0),
  [500] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 3, 0, 0),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byte_vector, 3, 0, 0),
  [504] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_byte_vector, 3, 0, 0),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 3, 0, 0),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 3, 0, 0),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [512] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [514] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 3, 0, 0),
  [516] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 3, 0, 0),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [520] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [522] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [524] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasisyntax, 3, 0, 0),
  [528] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasisyntax, 3, 0, 0),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax, 3, 0, 0),
  [532] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax, 3, 0, 0),
  [534] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax_splicing, 3, 0, 0),
  [536] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax_splicing, 3, 0, 0),
  [538] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_datum_label, 4, 0, 1),
  [540] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_datum_label, 4, 0, 1),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2, 0, 0),
  [544] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 2, 0, 0),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 2, 0, 0),
  [548] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 2, 0, 0),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 1, 0, 0),
  [552] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 1, 0, 0),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byte_vector, 2, 0, 0),
  [556] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_byte_vector, 2, 0, 0),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 2, 0, 0),
  [560] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 2, 0, 0),
  [562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 2, 0, 0),
  [564] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive, 2, 0, 0),
  [566] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 2, 0, 0),
  [568] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 2, 0, 0),
  [570] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [572] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_syntax_quote, 2, 0, 0),
  [576] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_syntax_quote, 2, 0, 0),
  [578] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 2, 0, 0),
  [580] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 2, 0, 0),
  [582] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasisyntax, 2, 0, 0),
  [584] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasisyntax, 2, 0, 0),
  [586] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax, 2, 0, 0),
  [588] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax, 2, 0, 0),
  [590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sexp_comment, 2, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sexp_comment, 2, 0, 0),
  [594] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax_splicing, 2, 0, 0),
  [596] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax_splicing, 2, 0, 0),
  [598] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [600] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [608] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [620] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [623] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [626] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [629] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(152),
  [632] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [635] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [649] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [653] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [661] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [675] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [677] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [679] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [681] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [684] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [687] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [690] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0),
  [695] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [699] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [705] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [711] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [715] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [719] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2, 0, 0),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [729] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
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
