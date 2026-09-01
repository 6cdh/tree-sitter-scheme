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
#define STATE_COUNT 140
#define LARGE_STATE_COUNT 55
#define SYMBOL_COUNT 60
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
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
  sym_directive = 7,
  sym_boolean = 8,
  sym_number = 9,
  sym_character = 10,
  anon_sym_DQUOTE = 11,
  aux_sym_string_token1 = 12,
  sym_escape_sequence = 13,
  sym_symbol = 14,
  anon_sym_LPAREN = 15,
  anon_sym_RPAREN = 16,
  anon_sym_LBRACK = 17,
  anon_sym_RBRACK = 18,
  sym_dot = 19,
  anon_sym_POUND_LPAREN = 20,
  anon_sym_POUNDvu8_LPAREN = 21,
  anon_sym_POUNDu8_LPAREN = 22,
  anon_sym_SQUOTE = 23,
  anon_sym_BQUOTE = 24,
  anon_sym_COMMA = 25,
  anon_sym_COMMA_AT = 26,
  anon_sym_POUND_SQUOTE = 27,
  anon_sym_POUND_BQUOTE = 28,
  anon_sym_POUND_COMMA = 29,
  anon_sym_POUND_COMMA_AT = 30,
  anon_sym_POUND = 31,
  aux_sym_datum_label_token1 = 32,
  anon_sym_EQ = 33,
  sym_program = 34,
  sym__token = 35,
  sym__intertoken = 36,
  sym__datum = 37,
  sym_block_comment = 38,
  sym_sexp_comment = 39,
  sym_string = 40,
  sym_list = 41,
  sym_vector = 42,
  sym_byte_vector = 43,
  sym_quote = 44,
  sym_quasiquote = 45,
  sym_unquote = 46,
  sym_unquote_splicing = 47,
  sym_syntax_quote = 48,
  sym_quasisyntax = 49,
  sym_unsyntax = 50,
  sym_unsyntax_splicing = 51,
  sym_datum_label = 52,
  sym_datum_reference = 53,
  aux_sym_program_repeat1 = 54,
  aux_sym_block_comment_repeat1 = 55,
  aux_sym_sexp_comment_repeat1 = 56,
  aux_sym_string_repeat1 = 57,
  aux_sym_list_repeat1 = 58,
  aux_sym_byte_vector_repeat1 = 59,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__intertoken_token1] = "_intertoken_token1",
  [sym_comment] = "comment",
  [anon_sym_POUND_PIPE] = "#|",
  [aux_sym_block_comment_token1] = "block_comment_token1",
  [anon_sym_PIPE_POUND] = "|#",
  [anon_sym_POUND_SEMI] = "#;",
  [sym_directive] = "directive",
  [sym_boolean] = "boolean",
  [sym_number] = "number",
  [sym_character] = "character",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [sym_escape_sequence] = "escape_sequence",
  [sym_symbol] = "symbol",
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
  [anon_sym_POUND] = "#",
  [aux_sym_datum_label_token1] = "datum_label_id",
  [anon_sym_EQ] = "=",
  [sym_program] = "program",
  [sym__token] = "_token",
  [sym__intertoken] = "_intertoken",
  [sym__datum] = "_datum",
  [sym_block_comment] = "block_comment",
  [sym_sexp_comment] = "sexp_comment",
  [sym_string] = "string",
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
  [sym_directive] = sym_directive,
  [sym_boolean] = sym_boolean,
  [sym_number] = sym_number,
  [sym_character] = sym_character,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_symbol] = sym_symbol,
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
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym_datum_label_token1] = aux_sym_datum_label_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_program] = sym_program,
  [sym__token] = sym__token,
  [sym__intertoken] = sym__intertoken,
  [sym__datum] = sym__datum,
  [sym_block_comment] = sym_block_comment,
  [sym_sexp_comment] = sym_sexp_comment,
  [sym_string] = sym_string,
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
  [sym_directive] = {
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
  [anon_sym_POUND] = {
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
  [6] = 6,
  [7] = 7,
  [8] = 5,
  [9] = 4,
  [10] = 6,
  [11] = 3,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 12,
  [16] = 13,
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
  [31] = 20,
  [32] = 32,
  [33] = 30,
  [34] = 34,
  [35] = 35,
  [36] = 17,
  [37] = 37,
  [38] = 32,
  [39] = 18,
  [40] = 21,
  [41] = 22,
  [42] = 23,
  [43] = 24,
  [44] = 25,
  [45] = 26,
  [46] = 27,
  [47] = 28,
  [48] = 19,
  [49] = 34,
  [50] = 35,
  [51] = 37,
  [52] = 29,
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
  [89] = 87,
  [90] = 88,
  [91] = 56,
  [92] = 68,
  [93] = 72,
  [94] = 73,
  [95] = 65,
  [96] = 77,
  [97] = 79,
  [98] = 80,
  [99] = 81,
  [100] = 82,
  [101] = 84,
  [102] = 85,
  [103] = 74,
  [104] = 57,
  [105] = 58,
  [106] = 59,
  [107] = 60,
  [108] = 61,
  [109] = 62,
  [110] = 55,
  [111] = 64,
  [112] = 83,
  [113] = 76,
  [114] = 75,
  [115] = 70,
  [116] = 63,
  [117] = 69,
  [118] = 67,
  [119] = 66,
  [120] = 71,
  [121] = 121,
  [122] = 122,
  [123] = 122,
  [124] = 121,
  [125] = 121,
  [126] = 126,
  [127] = 122,
  [128] = 128,
  [129] = 128,
  [130] = 130,
  [131] = 131,
  [132] = 131,
  [133] = 83,
  [134] = 76,
  [135] = 135,
  [136] = 135,
  [137] = 137,
  [138] = 138,
  [139] = 138,
};

static TSCharacterRange aux_sym__intertoken_token1_character_set_1[] = {
  {'\t', '\r'}, {' ', ' '}, {0x85, 0x85}, {0xa0, 0xa0}, {0x1680, 0x1680}, {0x2000, 0x200a}, {0x2028, 0x2029}, {0x202f, 0x202f},
  {0x205f, 0x205f}, {0x3000, 0x3000},
};

static TSCharacterRange sym_escape_sequence_character_set_2[] = {
  {'\t', '\n'}, {' ', ' '}, {0x85, 0x85}, {0xa0, 0xa0}, {0x1680, 0x1680}, {0x2000, 0x200a}, {0x202f, 0x202f}, {0x205f, 0x205f},
  {0x3000, 0x3000},
};

static TSCharacterRange sym_escape_sequence_character_set_3[] = {
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

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(276);
      ADVANCE_MAP(
        '\t', 278,
        '"', 409,
        '#', 476,
        '\'', 464,
        '(', 455,
        ')', 456,
        ',', 466,
        '.', 459,
        ';', 280,
        '=', 478,
        '[', 457,
        ']', 458,
        '`', 465,
        '|', 283,
        '\n', 277,
        '\r', 277,
        ' ', 277,
      );
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(279);
      if (lookahead != 0) ADVANCE(282);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '\t', 278,
        '#', 5,
        ')', 456,
        '.', 232,
        ';', 280,
        '+', 51,
        '-', 51,
        '\n', 277,
        '\r', 277,
        ' ', 277,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(279);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\n', 413,
        '\r', 412,
        'X', 274,
        'x', 274,
        '\t', 3,
        ' ', 3,
        0x85, 415,
        0x2028, 415,
        '"', 411,
        '\\', 411,
        'a', 411,
        'b', 411,
        'f', 411,
        'n', 411,
        'r', 411,
        't', 411,
        'v', 411,
      );
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(413);
      if (lookahead == '\r') ADVANCE(412);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead == 0x85 ||
          lookahead == 0x2028) ADVANCE(415);
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\r') ADVANCE(414);
      if (lookahead == '\n' ||
          lookahead == 0x85 ||
          lookahead == 0x2028) ADVANCE(415);
      if (set_contains(sym_escape_sequence_character_set_3, 11, lookahead)) ADVANCE(4);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '!', 105,
        ';', 286,
        '|', 281,
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
        '"', 409,
        '#', 475,
        '\'', 464,
        '(', 455,
        '+', 418,
        ',', 467,
        '-', 417,
        '.', 38,
        '[', 457,
        '\\', 129,
        '`', 465,
        '|', 86,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
      if (('!' <= lookahead && lookahead <= '&') ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('^' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(430);
      if (set_contains(sym_symbol_character_set_1, 219, lookahead)) ADVANCE(431);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(409);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(410);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(219);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(193);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(298);
      END_STATE();
    case 9:
      if (lookahead == '#') ADVANCE(162);
      if (lookahead == '.') ADVANCE(232);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '#', 12,
        '.', 14,
        '/', 248,
        '|', 249,
        'E', 154,
        'e', 154,
        'I', 291,
        'i', 291,
        'D', 154,
        'F', 154,
        'L', 154,
        'S', 154,
        'd', 154,
        'f', 154,
        'l', 154,
        's', 154,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(248);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '/') ADVANCE(248);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(151);
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '.') ADVANCE(15);
      if (lookahead == '/') ADVANCE(248);
      if (lookahead == '|') ADVANCE(249);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 14:
      ADVANCE_MAP(
        '#', 16,
        '|', 249,
        'E', 154,
        'e', 154,
        'I', 291,
        'i', 291,
        'D', 154,
        'F', 154,
        'L', 154,
        'S', 154,
        'd', 154,
        'f', 154,
        'l', 154,
        's', 154,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == '|') ADVANCE(249);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(151);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(18);
      if (lookahead == '/') ADVANCE(214);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 19:
      if (lookahead == '#') ADVANCE(18);
      if (lookahead == '/') ADVANCE(214);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(19);
      END_STATE();
    case 20:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 21:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == '#') ADVANCE(284);
      if (lookahead == '|') ADVANCE(283);
      if (lookahead != 0) ADVANCE(282);
      END_STATE();
    case 26:
      if (lookahead == '#') ADVANCE(473);
      if (lookahead == '=') ADVANCE(478);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 27:
      if (lookahead == '#') ADVANCE(222);
      if (lookahead == '.') ADVANCE(232);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
      END_STATE();
    case 28:
      if (lookahead == '#') ADVANCE(28);
      if (lookahead == '/') ADVANCE(227);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 29:
      if (lookahead == '#') ADVANCE(28);
      if (lookahead == '/') ADVANCE(227);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      END_STATE();
    case 30:
      if (lookahead == '#') ADVANCE(220);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(325);
      END_STATE();
    case 31:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '/') ADVANCE(268);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 32:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '/') ADVANCE(268);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 33:
      if (lookahead == '#') ADVANCE(221);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(337);
      END_STATE();
    case 34:
      if (lookahead == '(') ADVANCE(463);
      END_STATE();
    case 35:
      if (lookahead == '(') ADVANCE(462);
      END_STATE();
    case 36:
      if (lookahead == '-') ADVANCE(104);
      END_STATE();
    case 37:
      if (lookahead == '-') ADVANCE(93);
      END_STATE();
    case 38:
      if (lookahead == '.') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 39:
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == '/') ADVANCE(249);
      if (lookahead == '|') ADVANCE(249);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 40:
      if (lookahead == '.') ADVANCE(69);
      END_STATE();
    case 41:
      ADVANCE_MAP(
        '.', 130,
        '/', 249,
        '|', 249,
        'E', 154,
        'e', 154,
        'I', 291,
        'i', 291,
        'D', 154,
        'F', 154,
        'L', 154,
        'S', 154,
        'd', 154,
        'f', 154,
        'l', 154,
        's', 154,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 42:
      if (lookahead == '.') ADVANCE(68);
      END_STATE();
    case 43:
      if (lookahead == '.') ADVANCE(232);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
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
      if (lookahead == '.') ADVANCE(241);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 48:
      if (lookahead == '.') ADVANCE(241);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 49:
      if (lookahead == '.') ADVANCE(67);
      END_STATE();
    case 50:
      if (lookahead == '.') ADVANCE(242);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 51:
      if (lookahead == '.') ADVANCE(233);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(383);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(294);
      END_STATE();
    case 52:
      if (lookahead == '.') ADVANCE(243);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 53:
      if (lookahead == '.') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 54:
      if (lookahead == '.') ADVANCE(244);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 55:
      if (lookahead == '.') ADVANCE(251);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(355);
      END_STATE();
    case 56:
      if (lookahead == '.') ADVANCE(251);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(355);
      END_STATE();
    case 57:
      if (lookahead == '.') ADVANCE(252);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 58:
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      END_STATE();
    case 59:
      if (lookahead == '.') ADVANCE(253);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      END_STATE();
    case 60:
      if (lookahead == '.') ADVANCE(254);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 61:
      if (lookahead == '.') ADVANCE(255);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 62:
      if (lookahead == '.') ADVANCE(255);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 63:
      if (lookahead == '.') ADVANCE(256);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 64:
      if (lookahead == '/') ADVANCE(216);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(64);
      END_STATE();
    case 65:
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(65);
      END_STATE();
    case 66:
      if (lookahead == '/') ADVANCE(271);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 67:
      if (lookahead == '0') ADVANCE(291);
      END_STATE();
    case 68:
      if (lookahead == '0') ADVANCE(368);
      END_STATE();
    case 69:
      if (lookahead == '0') ADVANCE(172);
      END_STATE();
    case 70:
      if (lookahead == '0') ADVANCE(373);
      END_STATE();
    case 71:
      if (lookahead == '0') ADVANCE(369);
      END_STATE();
    case 72:
      if (lookahead == '0') ADVANCE(370);
      END_STATE();
    case 73:
      if (lookahead == '6') ADVANCE(119);
      END_STATE();
    case 74:
      if (lookahead == '8') ADVANCE(34);
      END_STATE();
    case 75:
      if (lookahead == '8') ADVANCE(35);
      END_STATE();
    case 76:
      if (lookahead == ';') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 77:
      if (lookahead == ';') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 78:
      if (lookahead == ';') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 79:
      if (lookahead == 'A') ADVANCE(163);
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 80:
      if (lookahead == 'C') ADVANCE(164);
      if (lookahead == 'c') ADVANCE(164);
      END_STATE();
    case 81:
      if (lookahead == 'I') ADVANCE(199);
      if (lookahead == 'i') ADVANCE(84);
      END_STATE();
    case 82:
      if (lookahead == 'L') ADVANCE(192);
      if (lookahead == 'l') ADVANCE(81);
      END_STATE();
    case 83:
      ADVANCE_MAP(
        'N', 406,
        'S', 407,
        'X', 408,
        'a', 403,
        'b', 395,
        'd', 400,
        'e', 404,
        'l', 401,
        'n', 393,
        'p', 396,
        'r', 399,
        's', 394,
        't', 397,
        'u', 408,
        'v', 405,
        'x', 408,
      );
      if (lookahead != 0) ADVANCE(392);
      END_STATE();
    case 84:
      if (lookahead == 'N') ADVANCE(164);
      if (lookahead == 'n') ADVANCE(164);
      END_STATE();
    case 85:
      if (lookahead == 'W') ADVANCE(197);
      if (lookahead == 'w') ADVANCE(82);
      END_STATE();
    case 86:
      if (lookahead == '\\') ADVANCE(209);
      if (lookahead == '|') ADVANCE(416);
      if (lookahead != 0) ADVANCE(86);
      END_STATE();
    case 87:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 88:
      if (lookahead == 'a') ADVANCE(120);
      END_STATE();
    case 89:
      if (lookahead == 'a') ADVANCE(124);
      END_STATE();
    case 90:
      if (lookahead == 'a') ADVANCE(94);
      END_STATE();
    case 91:
      if (lookahead == 'b') ADVANCE(392);
      END_STATE();
    case 92:
      if (lookahead == 'c') ADVANCE(108);
      END_STATE();
    case 93:
      if (lookahead == 'c') ADVANCE(89);
      END_STATE();
    case 94:
      if (lookahead == 'c') ADVANCE(98);
      END_STATE();
    case 95:
      if (lookahead == 'c') ADVANCE(398);
      END_STATE();
    case 96:
      if (lookahead == 'd') ADVANCE(392);
      END_STATE();
    case 97:
      if (lookahead == 'd') ADVANCE(37);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(392);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(287);
      END_STATE();
    case 100:
      if (lookahead == 'e') ADVANCE(126);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 103:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 104:
      if (lookahead == 'f') ADVANCE(115);
      END_STATE();
    case 105:
      if (lookahead == 'f') ADVANCE(115);
      if (lookahead == 'n') ADVANCE(116);
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 106:
      if (lookahead == 'f') ADVANCE(103);
      END_STATE();
    case 107:
      if (lookahead == 'g') ADVANCE(98);
      END_STATE();
    case 108:
      if (lookahead == 'k') ADVANCE(123);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(100);
      END_STATE();
    case 111:
      if (lookahead == 'l') ADVANCE(402);
      END_STATE();
    case 112:
      if (lookahead == 'm') ADVANCE(392);
      END_STATE();
    case 113:
      if (lookahead == 'n') ADVANCE(392);
      END_STATE();
    case 114:
      if (lookahead == 'n') ADVANCE(102);
      END_STATE();
    case 115:
      if (lookahead == 'o') ADVANCE(109);
      END_STATE();
    case 116:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 117:
      if (lookahead == 'p') ADVANCE(98);
      END_STATE();
    case 118:
      if (lookahead == 'p') ADVANCE(90);
      END_STATE();
    case 119:
      if (lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 120:
      if (lookahead == 'r') ADVANCE(112);
      END_STATE();
    case 121:
      if (lookahead == 'r') ADVANCE(113);
      END_STATE();
    case 122:
      if (lookahead == 's') ADVANCE(287);
      END_STATE();
    case 123:
      if (lookahead == 's') ADVANCE(118);
      END_STATE();
    case 124:
      if (lookahead == 's') ADVANCE(99);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 126:
      if (lookahead == 't') ADVANCE(98);
      END_STATE();
    case 127:
      if (lookahead == 'u') ADVANCE(121);
      END_STATE();
    case 128:
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 129:
      if (lookahead == 'x') ADVANCE(263);
      END_STATE();
    case 130:
      ADVANCE_MAP(
        '|', 249,
        'E', 154,
        'e', 154,
        'I', 291,
        'i', 291,
        'D', 154,
        'F', 154,
        'L', 154,
        'S', 154,
        'd', 154,
        'f', 154,
        'l', 154,
        's', 154,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 131:
      if (lookahead == '|') ADVANCE(249);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 132:
      if (lookahead == '|') ADVANCE(249);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 133:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(193);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(298);
      END_STATE();
    case 134:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(325);
      END_STATE();
    case 135:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(337);
      END_STATE();
    case 136:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(186);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(319);
      END_STATE();
    case 137:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 138:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(348);
      END_STATE();
    case 139:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(211);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(319);
      END_STATE();
    case 140:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 141:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(187);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(358);
      END_STATE();
    case 142:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(359);
      END_STATE();
    case 143:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(360);
      END_STATE();
    case 144:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(348);
      END_STATE();
    case 145:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 146:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 147:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(362);
      END_STATE();
    case 148:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(372);
      END_STATE();
    case 149:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(365);
      END_STATE();
    case 150:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      END_STATE();
    case 151:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(177);
      END_STATE();
    case 152:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(364);
      END_STATE();
    case 153:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(377);
      END_STATE();
    case 154:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 155:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(163);
      END_STATE();
    case 156:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(198);
      END_STATE();
    case 157:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(200);
      END_STATE();
    case 158:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(201);
      END_STATE();
    case 159:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(202);
      END_STATE();
    case 160:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 161:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(204);
      END_STATE();
    case 162:
      ADVANCE_MAP(
        'B', 133,
        'b', 133,
        'D', 43,
        'd', 43,
        'O', 134,
        'o', 134,
        'X', 135,
        'x', 135,
      );
      END_STATE();
    case 163:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(164);
      END_STATE();
    case 164:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(392);
      END_STATE();
    case 165:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(288);
      END_STATE();
    case 166:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(40);
      END_STATE();
    case 167:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(42);
      END_STATE();
    case 168:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(44);
      END_STATE();
    case 169:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(45);
      END_STATE();
    case 170:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(46);
      END_STATE();
    case 171:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(49);
      END_STATE();
    case 172:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 173:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(19);
      END_STATE();
    case 174:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(174);
      END_STATE();
    case 175:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      END_STATE();
    case 176:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(176);
      END_STATE();
    case 177:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(177);
      END_STATE();
    case 178:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 179:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(179);
      END_STATE();
    case 180:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(19);
      END_STATE();
    case 181:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(64);
      END_STATE();
    case 182:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      END_STATE();
    case 183:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(65);
      END_STATE();
    case 184:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 185:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(380);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 186:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(319);
      END_STATE();
    case 187:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(358);
      END_STATE();
    case 188:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 189:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(359);
      END_STATE();
    case 190:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(348);
      END_STATE();
    case 191:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(205);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(360);
      END_STATE();
    case 192:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(199);
      END_STATE();
    case 193:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(382);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(157);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(309);
      END_STATE();
    case 194:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(384);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(330);
      END_STATE();
    case 195:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(385);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(342);
      END_STATE();
    case 196:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(206);
      END_STATE();
    case 197:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(192);
      END_STATE();
    case 198:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 199:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(164);
      END_STATE();
    case 200:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 201:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 202:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 203:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 204:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 205:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(171);
      END_STATE();
    case 206:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(165);
      END_STATE();
    case 207:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(165);
      END_STATE();
    case 208:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(197);
      END_STATE();
    case 209:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(270);
      if (lookahead == 'a' ||
          lookahead == 'b' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == '|') ADVANCE(86);
      END_STATE();
    case 210:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(327);
      END_STATE();
    case 211:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(319);
      END_STATE();
    case 212:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(332);
      END_STATE();
    case 213:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(321);
      END_STATE();
    case 214:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(21);
      END_STATE();
    case 215:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(386);
      END_STATE();
    case 216:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(174);
      END_STATE();
    case 217:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(329);
      END_STATE();
    case 218:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(334);
      END_STATE();
    case 219:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(133);
      END_STATE();
    case 220:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(134);
      END_STATE();
    case 221:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(135);
      END_STATE();
    case 222:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(43);
      END_STATE();
    case 223:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(339);
      END_STATE();
    case 224:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 225:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(344);
      END_STATE();
    case 226:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(322);
      END_STATE();
    case 227:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(22);
      END_STATE();
    case 228:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(387);
      END_STATE();
    case 229:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(176);
      END_STATE();
    case 230:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(341);
      END_STATE();
    case 231:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(346);
      END_STATE();
    case 232:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      END_STATE();
    case 233:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(300);
      END_STATE();
    case 234:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(300);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 235:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(302);
      END_STATE();
    case 236:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(367);
      END_STATE();
    case 237:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 238:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 239:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(366);
      END_STATE();
    case 240:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(362);
      END_STATE();
    case 241:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(314);
      END_STATE();
    case 242:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 243:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(317);
      END_STATE();
    case 244:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 245:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 246:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      END_STATE();
    case 247:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(377);
      END_STATE();
    case 248:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 249:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(177);
      END_STATE();
    case 250:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 251:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(376);
      END_STATE();
    case 252:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 253:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(315);
      END_STATE();
    case 254:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 255:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(375);
      END_STATE();
    case 256:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 257:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(304);
      END_STATE();
    case 258:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(365);
      END_STATE();
    case 259:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 260:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(313);
      END_STATE();
    case 261:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(364);
      END_STATE();
    case 262:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(372);
      END_STATE();
    case 263:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 264:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(349);
      END_STATE();
    case 265:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(348);
      END_STATE();
    case 266:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(352);
      END_STATE();
    case 267:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(324);
      END_STATE();
    case 268:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 269:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(390);
      END_STATE();
    case 270:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 271:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(179);
      END_STATE();
    case 272:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(351);
      END_STATE();
    case 273:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(354);
      END_STATE();
    case 274:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 275:
      if (eof) ADVANCE(276);
      ADVANCE_MAP(
        '\t', 278,
        '"', 409,
        '#', 474,
        '\'', 464,
        '(', 455,
        ')', 456,
        '+', 418,
        ',', 467,
        '-', 417,
        '.', 460,
        ';', 280,
        '[', 457,
        '\\', 129,
        ']', 458,
        '`', 465,
        '|', 86,
        '\n', 277,
        '\r', 277,
        ' ', 277,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(279);
      if (('!' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(430);
      if (set_contains(sym_symbol_character_set_1, 219, lookahead)) ADVANCE(431);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (lookahead == '\t') ADVANCE(278);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(277);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(279);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(278);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(279);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(279);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x85 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(280);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_POUND_PIPE);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '#') ADVANCE(285);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '|') ADVANCE(281);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_PIPE_POUND);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_POUND_SEMI);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_directive);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_boolean);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_boolean);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(196);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_boolean);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(207);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_number);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 293,
        '.', 296,
        '/', 235,
        '@', 47,
        '|', 236,
        '+', 50,
        '-', 50,
        'E', 145,
        'e', 145,
        'D', 146,
        'F', 146,
        'L', 146,
        'S', 146,
        'd', 146,
        'f', 146,
        'l', 146,
        's', 146,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(292);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(293);
      if (lookahead == '.') ADVANCE(297);
      if (lookahead == '/') ADVANCE(257);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(149);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 295,
        '.', 300,
        '/', 238,
        '@', 47,
        '|', 239,
        '+', 50,
        '-', 50,
        'E', 147,
        'e', 147,
        'I', 291,
        'i', 291,
        'D', 148,
        'F', 148,
        'L', 148,
        'S', 148,
        'd', 148,
        'f', 148,
        'l', 148,
        's', 148,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 295,
        '.', 301,
        '/', 260,
        '@', 52,
        '+', 54,
        '-', 54,
        'I', 291,
        'i', 291,
      );
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(152);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 297,
        '@', 47,
        '|', 236,
        '+', 50,
        '-', 50,
        'E', 145,
        'e', 145,
        'D', 146,
        'F', 146,
        'L', 146,
        'S', 146,
        'd', 146,
        'f', 146,
        'l', 146,
        's', 146,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(297);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(149);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(299);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == '@') ADVANCE(136);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(299);
      if (lookahead == '/') ADVANCE(217);
      if (lookahead == '@') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(173);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 301,
        '@', 47,
        '|', 239,
        '+', 50,
        '-', 50,
        'E', 147,
        'e', 147,
        'I', 291,
        'i', 291,
        'D', 148,
        'F', 148,
        'L', 148,
        'S', 148,
        'd', 148,
        'f', 148,
        'l', 148,
        's', 148,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(300);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(301);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(152);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(303);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(302);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(303);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(303);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(304);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 307,
        '.', 314,
        '/', 245,
        '|', 246,
        'E', 153,
        'e', 153,
        'D', 153,
        'F', 153,
        'L', 153,
        'S', 153,
        'd', 153,
        'f', 153,
        'l', 153,
        's', 153,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(307);
      if (lookahead == '.') ADVANCE(317);
      if (lookahead == '/') ADVANCE(245);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(306);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(307);
      if (lookahead == '.') ADVANCE(316);
      if (lookahead == '/') ADVANCE(245);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(150);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(307);
      if (lookahead == '.') ADVANCE(315);
      if (lookahead == '/') ADVANCE(245);
      if (lookahead == '|') ADVANCE(246);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(308);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 310,
        '/', 212,
        '@', 136,
        '+', 180,
        '-', 180,
        'I', 291,
        'i', 291,
        '0', 309,
        '1', 309,
      );
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(310);
      if (lookahead == '/') ADVANCE(218);
      if (lookahead == '@') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(173);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(312);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(312);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(312);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(313);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 316,
        '|', 246,
        'E', 153,
        'e', 153,
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
      if (lookahead == '#') ADVANCE(316);
      if (lookahead == '|') ADVANCE(246);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(315);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(316);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(150);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(316);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(317);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(318);
      if (lookahead == '/') ADVANCE(213);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(318);
      if (lookahead == '/') ADVANCE(213);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(319);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(320);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(320);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(321);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(324);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(326);
      if (lookahead == '/') ADVANCE(223);
      if (lookahead == '@') ADVANCE(137);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(325);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(326);
      if (lookahead == '/') ADVANCE(230);
      if (lookahead == '@') ADVANCE(140);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(175);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(328);
      if (lookahead == '@') ADVANCE(136);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(328);
      if (lookahead == '@') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(173);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(328);
      if (lookahead == '@') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(173);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(329);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(331);
      if (lookahead == '/') ADVANCE(225);
      if (lookahead == '@') ADVANCE(137);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(182);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(330);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(331);
      if (lookahead == '/') ADVANCE(231);
      if (lookahead == '@') ADVANCE(140);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(175);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(333);
      if (lookahead == '@') ADVANCE(136);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(180);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(332);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(333);
      if (lookahead == '@') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(173);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(333);
      if (lookahead == '@') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(173);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(334);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(335);
      if (lookahead == '/') ADVANCE(226);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(335);
      if (lookahead == '/') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(336);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(338);
      if (lookahead == '/') ADVANCE(264);
      if (lookahead == '@') ADVANCE(138);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(337);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(338);
      if (lookahead == '/') ADVANCE(272);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(340);
      if (lookahead == '@') ADVANCE(137);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(339);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(340);
      if (lookahead == '@') ADVANCE(140);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(175);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(340);
      if (lookahead == '@') ADVANCE(140);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(341);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(343);
      if (lookahead == '/') ADVANCE(266);
      if (lookahead == '@') ADVANCE(138);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(184);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(342);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(343);
      if (lookahead == '/') ADVANCE(273);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(345);
      if (lookahead == '@') ADVANCE(137);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(182);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(344);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(345);
      if (lookahead == '@') ADVANCE(140);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(175);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(345);
      if (lookahead == '@') ADVANCE(140);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(175);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(347);
      if (lookahead == '/') ADVANCE(267);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(347);
      if (lookahead == '/') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(348);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(350);
      if (lookahead == '@') ADVANCE(138);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(349);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(350);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(350);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(351);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(353);
      if (lookahead == '@') ADVANCE(138);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(184);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(352);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(353);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(353);
      if (lookahead == '@') ADVANCE(144);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(178);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(354);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(376);
      if (lookahead == '/') ADVANCE(246);
      if (lookahead == '|') ADVANCE(246);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(355);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 374,
        '/', 450,
        '|', 246,
        'E', 434,
        'e', 434,
        'D', 434,
        'F', 434,
        'L', 434,
        'S', 434,
        'd', 434,
        'f', 434,
        'l', 434,
        's', 434,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(356);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 375,
        '/', 246,
        '|', 246,
        'E', 153,
        'e', 153,
        'D', 153,
        'F', 153,
        'L', 153,
        'S', 153,
        'd', 153,
        'f', 153,
        'l', 153,
        's', 153,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(215);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(358);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(359);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(360);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '|') ADVANCE(236);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '|') ADVANCE(239);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(50);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(362);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(421);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(425);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(391);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(364);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(52);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(365);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(55);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(57);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(366);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(55);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(367);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(141);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(181);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(142);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(183);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(185);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(58);
      if (lookahead == '|') ADVANCE(236);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(58);
      if (lookahead == '|') ADVANCE(239);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(60);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(372);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(61);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(63);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(291);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '|', 246,
        'E', 434,
        'e', 434,
        'D', 434,
        'F', 434,
        'L', 434,
        'S', 434,
        'd', 434,
        'f', 434,
        'l', 434,
        's', 434,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(374);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '|', 246,
        'E', 153,
        'e', 153,
        'D', 153,
        'F', 153,
        'L', 153,
        'S', 153,
        'd', 153,
        'f', 153,
        'l', 153,
        's', 153,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(375);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(246);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(376);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(377);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(378);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(439);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(440);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(167);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(168);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(169);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(170);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(386);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(387);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(388);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(389);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(390);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_number);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_character);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'E') ADVANCE(208);
      if (lookahead == 'e') ADVANCE(85);
      if (lookahead == 'u') ADVANCE(111);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'P') ADVANCE(155);
      if (lookahead == 'p') ADVANCE(79);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(117);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'e') ADVANCE(125);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'i') ADVANCE(114);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'l') ADVANCE(392);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'l') ADVANCE(88);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 's') ADVANCE(95);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 't') ADVANCE(87);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(155);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_character);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(408);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(410);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\n') ADVANCE(413);
      if (lookahead == 0x85) ADVANCE(415);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(413);
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(415);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(413);
      if (lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(415);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\n' ||
          lookahead == 0x85) ADVANCE(415);
      if (set_contains(sym_escape_sequence_character_set_2, 9, lookahead)) ADVANCE(415);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_escape_sequence);
      if ((set_contains(sym_escape_sequence_character_set_2, 9, lookahead)) &&
          lookahead != '\n' &&
          lookahead != 0x85) ADVANCE(415);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_symbol);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(234);
      if (lookahead == '>') ADVANCE(430);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(379);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(234);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(379);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(454);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(427);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(448);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(356);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(448);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(447);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(356);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_symbol);
      ADVANCE_MAP(
        '.', 432,
        '/', 452,
        '|', 249,
        'E', 435,
        'e', 435,
        'I', 391,
        'i', 391,
        'D', 435,
        'F', 435,
        'L', 435,
        'S', 435,
        'd', 435,
        'f', 435,
        'l', 435,
        's', 435,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(423);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(429);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(449);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(381);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(423);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(428);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '0') ADVANCE(363);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '0') ADVANCE(391);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '0') ADVANCE(443);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '\\') ADVANCE(129);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(430);
      if (set_contains(sym_symbol_character_set_3, 65, lookahead)) ADVANCE(431);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '\\') ADVANCE(129);
      if (set_contains(sym_symbol_character_set_3, 65, lookahead)) ADVANCE(431);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_symbol);
      ADVANCE_MAP(
        '|', 249,
        'E', 435,
        'e', 435,
        'I', 391,
        'i', 391,
        'D', 435,
        'F', 435,
        'L', 435,
        'S', 435,
        'd', 435,
        'f', 435,
        'l', 435,
        's', 435,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(432);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '|') ADVANCE(249);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(433);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(378);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(453);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(433);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(444);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(445);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(446);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(420);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(424);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(426);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(442);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(391);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(420);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(424);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(426);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(441);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(374);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(432);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(389);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(378);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(442);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_symbol);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(433);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_symbol);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead) ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(454);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_dot);
      if (lookahead == '.') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      if (set_contains(sym_symbol_character_set_2, 9, lookahead)) ADVANCE(454);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(anon_sym_POUND_LPAREN);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(anon_sym_POUNDvu8_LPAREN);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_POUNDu8_LPAREN);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '@') ADVANCE(468);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_COMMA_AT);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(anon_sym_POUND_SQUOTE);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(anon_sym_POUND_BQUOTE);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_POUND_COMMA);
      if (lookahead == '@') ADVANCE(472);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_POUND_COMMA_AT);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(anon_sym_POUND);
      ADVANCE_MAP(
        '!', 105,
        '\'', 469,
        '(', 461,
        ',', 471,
        ';', 286,
        '\\', 83,
        '`', 470,
        'u', 74,
        'v', 128,
        '|', 281,
        'B', 8,
        'b', 8,
        'D', 27,
        'd', 27,
        'F', 289,
        'f', 289,
        'O', 30,
        'o', 30,
        'T', 290,
        't', 290,
        'X', 33,
        'x', 33,
        'E', 9,
        'I', 9,
        'e', 9,
        'i', 9,
      );
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_POUND);
      ADVANCE_MAP(
        '\'', 469,
        '(', 461,
        ',', 471,
        '\\', 83,
        '`', 470,
        'u', 74,
        'v', 128,
        'B', 8,
        'b', 8,
        'D', 27,
        'd', 27,
        'F', 289,
        'f', 289,
        'O', 30,
        'o', 30,
        'T', 290,
        't', 290,
        'X', 33,
        'x', 33,
        'E', 9,
        'I', 9,
        'e', 9,
        'i', 9,
      );
      END_STATE();
    case 476:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead == '|') ADVANCE(281);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(aux_sym_datum_label_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(477);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 275},
  [2] = {.lex_state = 275},
  [3] = {.lex_state = 275},
  [4] = {.lex_state = 275},
  [5] = {.lex_state = 275},
  [6] = {.lex_state = 275},
  [7] = {.lex_state = 275},
  [8] = {.lex_state = 275},
  [9] = {.lex_state = 275},
  [10] = {.lex_state = 275},
  [11] = {.lex_state = 275},
  [12] = {.lex_state = 275},
  [13] = {.lex_state = 275},
  [14] = {.lex_state = 275},
  [15] = {.lex_state = 275},
  [16] = {.lex_state = 275},
  [17] = {.lex_state = 275},
  [18] = {.lex_state = 275},
  [19] = {.lex_state = 275},
  [20] = {.lex_state = 275},
  [21] = {.lex_state = 275},
  [22] = {.lex_state = 275},
  [23] = {.lex_state = 275},
  [24] = {.lex_state = 275},
  [25] = {.lex_state = 275},
  [26] = {.lex_state = 275},
  [27] = {.lex_state = 275},
  [28] = {.lex_state = 275},
  [29] = {.lex_state = 275},
  [30] = {.lex_state = 275},
  [31] = {.lex_state = 275},
  [32] = {.lex_state = 275},
  [33] = {.lex_state = 275},
  [34] = {.lex_state = 275},
  [35] = {.lex_state = 275},
  [36] = {.lex_state = 275},
  [37] = {.lex_state = 275},
  [38] = {.lex_state = 275},
  [39] = {.lex_state = 275},
  [40] = {.lex_state = 275},
  [41] = {.lex_state = 275},
  [42] = {.lex_state = 275},
  [43] = {.lex_state = 275},
  [44] = {.lex_state = 275},
  [45] = {.lex_state = 275},
  [46] = {.lex_state = 275},
  [47] = {.lex_state = 275},
  [48] = {.lex_state = 275},
  [49] = {.lex_state = 275},
  [50] = {.lex_state = 275},
  [51] = {.lex_state = 275},
  [52] = {.lex_state = 275},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 275},
  [56] = {.lex_state = 275},
  [57] = {.lex_state = 275},
  [58] = {.lex_state = 275},
  [59] = {.lex_state = 275},
  [60] = {.lex_state = 275},
  [61] = {.lex_state = 275},
  [62] = {.lex_state = 275},
  [63] = {.lex_state = 275},
  [64] = {.lex_state = 275},
  [65] = {.lex_state = 275},
  [66] = {.lex_state = 275},
  [67] = {.lex_state = 275},
  [68] = {.lex_state = 275},
  [69] = {.lex_state = 275},
  [70] = {.lex_state = 275},
  [71] = {.lex_state = 275},
  [72] = {.lex_state = 275},
  [73] = {.lex_state = 275},
  [74] = {.lex_state = 275},
  [75] = {.lex_state = 275},
  [76] = {.lex_state = 275},
  [77] = {.lex_state = 275},
  [78] = {.lex_state = 275},
  [79] = {.lex_state = 275},
  [80] = {.lex_state = 275},
  [81] = {.lex_state = 275},
  [82] = {.lex_state = 275},
  [83] = {.lex_state = 275},
  [84] = {.lex_state = 275},
  [85] = {.lex_state = 275},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 1},
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
  [121] = {.lex_state = 25},
  [122] = {.lex_state = 25},
  [123] = {.lex_state = 25},
  [124] = {.lex_state = 25},
  [125] = {.lex_state = 25},
  [126] = {.lex_state = 25},
  [127] = {.lex_state = 25},
  [128] = {.lex_state = 7},
  [129] = {.lex_state = 7},
  [130] = {.lex_state = 7},
  [131] = {.lex_state = 7},
  [132] = {.lex_state = 7},
  [133] = {.lex_state = 25},
  [134] = {.lex_state = 25},
  [135] = {.lex_state = 26},
  [136] = {.lex_state = 26},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 26},
  [139] = {.lex_state = 26},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__intertoken_token1] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_POUND_PIPE] = ACTIONS(1),
    [aux_sym_block_comment_token1] = ACTIONS(1),
    [anon_sym_PIPE_POUND] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_dot] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(137),
    [sym__token] = STATE(14),
    [sym__intertoken] = STATE(14),
    [sym__datum] = STATE(14),
    [sym_block_comment] = STATE(14),
    [sym_sexp_comment] = STATE(14),
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
    [sym_directive] = ACTIONS(5),
    [sym_boolean] = ACTIONS(5),
    [sym_number] = ACTIONS(11),
    [sym_character] = ACTIONS(5),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [2] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
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
    [aux_sym__intertoken_token1] = ACTIONS(41),
    [sym_comment] = ACTIONS(41),
    [anon_sym_POUND_PIPE] = ACTIONS(44),
    [anon_sym_POUND_SEMI] = ACTIONS(47),
    [sym_directive] = ACTIONS(41),
    [sym_boolean] = ACTIONS(41),
    [sym_number] = ACTIONS(50),
    [sym_character] = ACTIONS(41),
    [anon_sym_DQUOTE] = ACTIONS(53),
    [sym_symbol] = ACTIONS(50),
    [anon_sym_LPAREN] = ACTIONS(56),
    [anon_sym_RPAREN] = ACTIONS(59),
    [anon_sym_LBRACK] = ACTIONS(61),
    [anon_sym_RBRACK] = ACTIONS(59),
    [sym_dot] = ACTIONS(50),
    [anon_sym_POUND_LPAREN] = ACTIONS(64),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(67),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(67),
    [anon_sym_SQUOTE] = ACTIONS(70),
    [anon_sym_BQUOTE] = ACTIONS(73),
    [anon_sym_COMMA] = ACTIONS(76),
    [anon_sym_COMMA_AT] = ACTIONS(79),
    [anon_sym_POUND_SQUOTE] = ACTIONS(82),
    [anon_sym_POUND_BQUOTE] = ACTIONS(85),
    [anon_sym_POUND_COMMA] = ACTIONS(88),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(91),
    [anon_sym_POUND] = ACTIONS(94),
  },
  [3] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
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
    [aux_sym__intertoken_token1] = ACTIONS(97),
    [sym_comment] = ACTIONS(97),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(97),
    [sym_boolean] = ACTIONS(97),
    [sym_number] = ACTIONS(99),
    [sym_character] = ACTIONS(97),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(99),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(101),
    [sym_dot] = ACTIONS(99),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [4] = {
    [sym__token] = STATE(3),
    [sym__intertoken] = STATE(3),
    [sym__datum] = STATE(3),
    [sym_block_comment] = STATE(3),
    [sym_sexp_comment] = STATE(3),
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
    [aux_sym__intertoken_token1] = ACTIONS(103),
    [sym_comment] = ACTIONS(103),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(103),
    [sym_boolean] = ACTIONS(103),
    [sym_number] = ACTIONS(105),
    [sym_character] = ACTIONS(103),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(105),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(107),
    [sym_dot] = ACTIONS(105),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [5] = {
    [sym__token] = STATE(10),
    [sym__intertoken] = STATE(10),
    [sym__datum] = STATE(10),
    [sym_block_comment] = STATE(10),
    [sym_sexp_comment] = STATE(10),
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
    [aux_sym__intertoken_token1] = ACTIONS(109),
    [sym_comment] = ACTIONS(109),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(109),
    [sym_boolean] = ACTIONS(109),
    [sym_number] = ACTIONS(111),
    [sym_character] = ACTIONS(109),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(111),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(113),
    [anon_sym_LBRACK] = ACTIONS(17),
    [sym_dot] = ACTIONS(111),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [6] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
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
    [aux_sym__intertoken_token1] = ACTIONS(97),
    [sym_comment] = ACTIONS(97),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(97),
    [sym_boolean] = ACTIONS(97),
    [sym_number] = ACTIONS(99),
    [sym_character] = ACTIONS(97),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(99),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(101),
    [anon_sym_LBRACK] = ACTIONS(17),
    [sym_dot] = ACTIONS(99),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [7] = {
    [sym__token] = STATE(7),
    [sym__intertoken] = STATE(7),
    [sym__datum] = STATE(7),
    [sym_block_comment] = STATE(7),
    [sym_sexp_comment] = STATE(7),
    [sym_string] = STATE(7),
    [sym_list] = STATE(7),
    [sym_vector] = STATE(7),
    [sym_byte_vector] = STATE(7),
    [sym_quote] = STATE(7),
    [sym_quasiquote] = STATE(7),
    [sym_unquote] = STATE(7),
    [sym_unquote_splicing] = STATE(7),
    [sym_syntax_quote] = STATE(7),
    [sym_quasisyntax] = STATE(7),
    [sym_unsyntax] = STATE(7),
    [sym_unsyntax_splicing] = STATE(7),
    [sym_datum_label] = STATE(7),
    [sym_datum_reference] = STATE(7),
    [aux_sym_program_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(115),
    [aux_sym__intertoken_token1] = ACTIONS(117),
    [sym_comment] = ACTIONS(117),
    [anon_sym_POUND_PIPE] = ACTIONS(120),
    [anon_sym_POUND_SEMI] = ACTIONS(123),
    [sym_directive] = ACTIONS(117),
    [sym_boolean] = ACTIONS(117),
    [sym_number] = ACTIONS(126),
    [sym_character] = ACTIONS(117),
    [anon_sym_DQUOTE] = ACTIONS(129),
    [sym_symbol] = ACTIONS(126),
    [anon_sym_LPAREN] = ACTIONS(132),
    [anon_sym_RPAREN] = ACTIONS(115),
    [anon_sym_LBRACK] = ACTIONS(135),
    [anon_sym_POUND_LPAREN] = ACTIONS(138),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(141),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(141),
    [anon_sym_SQUOTE] = ACTIONS(144),
    [anon_sym_BQUOTE] = ACTIONS(147),
    [anon_sym_COMMA] = ACTIONS(150),
    [anon_sym_COMMA_AT] = ACTIONS(153),
    [anon_sym_POUND_SQUOTE] = ACTIONS(156),
    [anon_sym_POUND_BQUOTE] = ACTIONS(159),
    [anon_sym_POUND_COMMA] = ACTIONS(162),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(165),
    [anon_sym_POUND] = ACTIONS(168),
  },
  [8] = {
    [sym__token] = STATE(6),
    [sym__intertoken] = STATE(6),
    [sym__datum] = STATE(6),
    [sym_block_comment] = STATE(6),
    [sym_sexp_comment] = STATE(6),
    [sym_string] = STATE(6),
    [sym_list] = STATE(6),
    [sym_vector] = STATE(6),
    [sym_byte_vector] = STATE(6),
    [sym_quote] = STATE(6),
    [sym_quasiquote] = STATE(6),
    [sym_unquote] = STATE(6),
    [sym_unquote_splicing] = STATE(6),
    [sym_syntax_quote] = STATE(6),
    [sym_quasisyntax] = STATE(6),
    [sym_unsyntax] = STATE(6),
    [sym_unsyntax_splicing] = STATE(6),
    [sym_datum_label] = STATE(6),
    [sym_datum_reference] = STATE(6),
    [aux_sym_list_repeat1] = STATE(6),
    [aux_sym__intertoken_token1] = ACTIONS(171),
    [sym_comment] = ACTIONS(171),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(171),
    [sym_boolean] = ACTIONS(171),
    [sym_number] = ACTIONS(173),
    [sym_character] = ACTIONS(171),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(173),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(107),
    [anon_sym_LBRACK] = ACTIONS(17),
    [sym_dot] = ACTIONS(173),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [9] = {
    [sym__token] = STATE(11),
    [sym__intertoken] = STATE(11),
    [sym__datum] = STATE(11),
    [sym_block_comment] = STATE(11),
    [sym_sexp_comment] = STATE(11),
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
    [aux_sym__intertoken_token1] = ACTIONS(175),
    [sym_comment] = ACTIONS(175),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(175),
    [sym_boolean] = ACTIONS(175),
    [sym_number] = ACTIONS(177),
    [sym_character] = ACTIONS(175),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(177),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(113),
    [sym_dot] = ACTIONS(177),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [10] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
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
    [aux_sym__intertoken_token1] = ACTIONS(97),
    [sym_comment] = ACTIONS(97),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(97),
    [sym_boolean] = ACTIONS(97),
    [sym_number] = ACTIONS(99),
    [sym_character] = ACTIONS(97),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(99),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(179),
    [anon_sym_LBRACK] = ACTIONS(17),
    [sym_dot] = ACTIONS(99),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [11] = {
    [sym__token] = STATE(2),
    [sym__intertoken] = STATE(2),
    [sym__datum] = STATE(2),
    [sym_block_comment] = STATE(2),
    [sym_sexp_comment] = STATE(2),
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
    [aux_sym__intertoken_token1] = ACTIONS(97),
    [sym_comment] = ACTIONS(97),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(97),
    [sym_boolean] = ACTIONS(97),
    [sym_number] = ACTIONS(99),
    [sym_character] = ACTIONS(97),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(99),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(179),
    [sym_dot] = ACTIONS(99),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [12] = {
    [sym__token] = STATE(13),
    [sym__intertoken] = STATE(13),
    [sym__datum] = STATE(13),
    [sym_block_comment] = STATE(13),
    [sym_sexp_comment] = STATE(13),
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
    [aux_sym__intertoken_token1] = ACTIONS(181),
    [sym_comment] = ACTIONS(181),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(181),
    [sym_boolean] = ACTIONS(181),
    [sym_number] = ACTIONS(183),
    [sym_character] = ACTIONS(181),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(183),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(185),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [13] = {
    [sym__token] = STATE(7),
    [sym__intertoken] = STATE(7),
    [sym__datum] = STATE(7),
    [sym_block_comment] = STATE(7),
    [sym_sexp_comment] = STATE(7),
    [sym_string] = STATE(7),
    [sym_list] = STATE(7),
    [sym_vector] = STATE(7),
    [sym_byte_vector] = STATE(7),
    [sym_quote] = STATE(7),
    [sym_quasiquote] = STATE(7),
    [sym_unquote] = STATE(7),
    [sym_unquote_splicing] = STATE(7),
    [sym_syntax_quote] = STATE(7),
    [sym_quasisyntax] = STATE(7),
    [sym_unsyntax] = STATE(7),
    [sym_unsyntax_splicing] = STATE(7),
    [sym_datum_label] = STATE(7),
    [sym_datum_reference] = STATE(7),
    [aux_sym_program_repeat1] = STATE(7),
    [aux_sym__intertoken_token1] = ACTIONS(187),
    [sym_comment] = ACTIONS(187),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(187),
    [sym_boolean] = ACTIONS(187),
    [sym_number] = ACTIONS(189),
    [sym_character] = ACTIONS(187),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(189),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(191),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [14] = {
    [sym__token] = STATE(7),
    [sym__intertoken] = STATE(7),
    [sym__datum] = STATE(7),
    [sym_block_comment] = STATE(7),
    [sym_sexp_comment] = STATE(7),
    [sym_string] = STATE(7),
    [sym_list] = STATE(7),
    [sym_vector] = STATE(7),
    [sym_byte_vector] = STATE(7),
    [sym_quote] = STATE(7),
    [sym_quasiquote] = STATE(7),
    [sym_unquote] = STATE(7),
    [sym_unquote_splicing] = STATE(7),
    [sym_syntax_quote] = STATE(7),
    [sym_quasisyntax] = STATE(7),
    [sym_unsyntax] = STATE(7),
    [sym_unsyntax_splicing] = STATE(7),
    [sym_datum_label] = STATE(7),
    [sym_datum_reference] = STATE(7),
    [aux_sym_program_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(193),
    [aux_sym__intertoken_token1] = ACTIONS(187),
    [sym_comment] = ACTIONS(187),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(187),
    [sym_boolean] = ACTIONS(187),
    [sym_number] = ACTIONS(189),
    [sym_character] = ACTIONS(187),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(189),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [15] = {
    [sym__token] = STATE(16),
    [sym__intertoken] = STATE(16),
    [sym__datum] = STATE(16),
    [sym_block_comment] = STATE(16),
    [sym_sexp_comment] = STATE(16),
    [sym_string] = STATE(16),
    [sym_list] = STATE(16),
    [sym_vector] = STATE(16),
    [sym_byte_vector] = STATE(16),
    [sym_quote] = STATE(16),
    [sym_quasiquote] = STATE(16),
    [sym_unquote] = STATE(16),
    [sym_unquote_splicing] = STATE(16),
    [sym_syntax_quote] = STATE(16),
    [sym_quasisyntax] = STATE(16),
    [sym_unsyntax] = STATE(16),
    [sym_unsyntax_splicing] = STATE(16),
    [sym_datum_label] = STATE(16),
    [sym_datum_reference] = STATE(16),
    [aux_sym_program_repeat1] = STATE(16),
    [aux_sym__intertoken_token1] = ACTIONS(195),
    [sym_comment] = ACTIONS(195),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(195),
    [sym_boolean] = ACTIONS(195),
    [sym_number] = ACTIONS(197),
    [sym_character] = ACTIONS(195),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(197),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(199),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [16] = {
    [sym__token] = STATE(7),
    [sym__intertoken] = STATE(7),
    [sym__datum] = STATE(7),
    [sym_block_comment] = STATE(7),
    [sym_sexp_comment] = STATE(7),
    [sym_string] = STATE(7),
    [sym_list] = STATE(7),
    [sym_vector] = STATE(7),
    [sym_byte_vector] = STATE(7),
    [sym_quote] = STATE(7),
    [sym_quasiquote] = STATE(7),
    [sym_unquote] = STATE(7),
    [sym_unquote_splicing] = STATE(7),
    [sym_syntax_quote] = STATE(7),
    [sym_quasisyntax] = STATE(7),
    [sym_unsyntax] = STATE(7),
    [sym_unsyntax_splicing] = STATE(7),
    [sym_datum_label] = STATE(7),
    [sym_datum_reference] = STATE(7),
    [aux_sym_program_repeat1] = STATE(7),
    [aux_sym__intertoken_token1] = ACTIONS(187),
    [sym_comment] = ACTIONS(187),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(187),
    [sym_boolean] = ACTIONS(187),
    [sym_number] = ACTIONS(189),
    [sym_character] = ACTIONS(187),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(189),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(201),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [17] = {
    [sym__intertoken] = STATE(26),
    [sym__datum] = STATE(70),
    [sym_block_comment] = STATE(26),
    [sym_sexp_comment] = STATE(26),
    [sym_string] = STATE(70),
    [sym_list] = STATE(70),
    [sym_vector] = STATE(70),
    [sym_byte_vector] = STATE(70),
    [sym_quote] = STATE(70),
    [sym_quasiquote] = STATE(70),
    [sym_unquote] = STATE(70),
    [sym_unquote_splicing] = STATE(70),
    [sym_syntax_quote] = STATE(70),
    [sym_quasisyntax] = STATE(70),
    [sym_unsyntax] = STATE(70),
    [sym_unsyntax_splicing] = STATE(70),
    [sym_datum_label] = STATE(70),
    [sym_datum_reference] = STATE(70),
    [aux_sym_sexp_comment_repeat1] = STATE(26),
    [aux_sym__intertoken_token1] = ACTIONS(203),
    [sym_comment] = ACTIONS(203),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(203),
    [sym_boolean] = ACTIONS(205),
    [sym_number] = ACTIONS(207),
    [sym_character] = ACTIONS(205),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(207),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [18] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(77),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(77),
    [sym_list] = STATE(77),
    [sym_vector] = STATE(77),
    [sym_byte_vector] = STATE(77),
    [sym_quote] = STATE(77),
    [sym_quasiquote] = STATE(77),
    [sym_unquote] = STATE(77),
    [sym_unquote_splicing] = STATE(77),
    [sym_syntax_quote] = STATE(77),
    [sym_quasisyntax] = STATE(77),
    [sym_unsyntax] = STATE(77),
    [sym_unsyntax_splicing] = STATE(77),
    [sym_datum_label] = STATE(77),
    [sym_datum_reference] = STATE(77),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(211),
    [sym_number] = ACTIONS(213),
    [sym_character] = ACTIONS(211),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(213),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [19] = {
    [sym__intertoken] = STATE(18),
    [sym__datum] = STATE(65),
    [sym_block_comment] = STATE(18),
    [sym_sexp_comment] = STATE(18),
    [sym_string] = STATE(65),
    [sym_list] = STATE(65),
    [sym_vector] = STATE(65),
    [sym_byte_vector] = STATE(65),
    [sym_quote] = STATE(65),
    [sym_quasiquote] = STATE(65),
    [sym_unquote] = STATE(65),
    [sym_unquote_splicing] = STATE(65),
    [sym_syntax_quote] = STATE(65),
    [sym_quasisyntax] = STATE(65),
    [sym_unsyntax] = STATE(65),
    [sym_unsyntax_splicing] = STATE(65),
    [sym_datum_label] = STATE(65),
    [sym_datum_reference] = STATE(65),
    [aux_sym_sexp_comment_repeat1] = STATE(18),
    [aux_sym__intertoken_token1] = ACTIONS(215),
    [sym_comment] = ACTIONS(215),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(215),
    [sym_boolean] = ACTIONS(217),
    [sym_number] = ACTIONS(219),
    [sym_character] = ACTIONS(217),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(219),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [20] = {
    [sym__intertoken] = STATE(21),
    [sym__datum] = STATE(72),
    [sym_block_comment] = STATE(21),
    [sym_sexp_comment] = STATE(21),
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
    [aux_sym_sexp_comment_repeat1] = STATE(21),
    [aux_sym__intertoken_token1] = ACTIONS(221),
    [sym_comment] = ACTIONS(221),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(221),
    [sym_boolean] = ACTIONS(223),
    [sym_number] = ACTIONS(225),
    [sym_character] = ACTIONS(223),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(225),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [21] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(84),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(84),
    [sym_list] = STATE(84),
    [sym_vector] = STATE(84),
    [sym_byte_vector] = STATE(84),
    [sym_quote] = STATE(84),
    [sym_quasiquote] = STATE(84),
    [sym_unquote] = STATE(84),
    [sym_unquote_splicing] = STATE(84),
    [sym_syntax_quote] = STATE(84),
    [sym_quasisyntax] = STATE(84),
    [sym_unsyntax] = STATE(84),
    [sym_unsyntax_splicing] = STATE(84),
    [sym_datum_label] = STATE(84),
    [sym_datum_reference] = STATE(84),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(227),
    [sym_number] = ACTIONS(229),
    [sym_character] = ACTIONS(227),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(229),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [22] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(85),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(231),
    [sym_number] = ACTIONS(233),
    [sym_character] = ACTIONS(231),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(233),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [23] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(56),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(235),
    [sym_number] = ACTIONS(237),
    [sym_character] = ACTIONS(235),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(237),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [24] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(57),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(57),
    [sym_list] = STATE(57),
    [sym_vector] = STATE(57),
    [sym_byte_vector] = STATE(57),
    [sym_quote] = STATE(57),
    [sym_quasiquote] = STATE(57),
    [sym_unquote] = STATE(57),
    [sym_unquote_splicing] = STATE(57),
    [sym_syntax_quote] = STATE(57),
    [sym_quasisyntax] = STATE(57),
    [sym_unsyntax] = STATE(57),
    [sym_unsyntax_splicing] = STATE(57),
    [sym_datum_label] = STATE(57),
    [sym_datum_reference] = STATE(57),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(239),
    [sym_number] = ACTIONS(241),
    [sym_character] = ACTIONS(239),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(241),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [25] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(58),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(243),
    [sym_number] = ACTIONS(245),
    [sym_character] = ACTIONS(243),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(245),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [26] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(59),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(59),
    [sym_list] = STATE(59),
    [sym_vector] = STATE(59),
    [sym_byte_vector] = STATE(59),
    [sym_quote] = STATE(59),
    [sym_quasiquote] = STATE(59),
    [sym_unquote] = STATE(59),
    [sym_unquote_splicing] = STATE(59),
    [sym_syntax_quote] = STATE(59),
    [sym_quasisyntax] = STATE(59),
    [sym_unsyntax] = STATE(59),
    [sym_unsyntax_splicing] = STATE(59),
    [sym_datum_label] = STATE(59),
    [sym_datum_reference] = STATE(59),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(247),
    [sym_number] = ACTIONS(249),
    [sym_character] = ACTIONS(247),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(249),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [27] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(60),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(60),
    [sym_list] = STATE(60),
    [sym_vector] = STATE(60),
    [sym_byte_vector] = STATE(60),
    [sym_quote] = STATE(60),
    [sym_quasiquote] = STATE(60),
    [sym_unquote] = STATE(60),
    [sym_unquote_splicing] = STATE(60),
    [sym_syntax_quote] = STATE(60),
    [sym_quasisyntax] = STATE(60),
    [sym_unsyntax] = STATE(60),
    [sym_unsyntax_splicing] = STATE(60),
    [sym_datum_label] = STATE(60),
    [sym_datum_reference] = STATE(60),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(251),
    [sym_number] = ACTIONS(253),
    [sym_character] = ACTIONS(251),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(253),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [28] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(61),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(61),
    [sym_list] = STATE(61),
    [sym_vector] = STATE(61),
    [sym_byte_vector] = STATE(61),
    [sym_quote] = STATE(61),
    [sym_quasiquote] = STATE(61),
    [sym_unquote] = STATE(61),
    [sym_unquote_splicing] = STATE(61),
    [sym_syntax_quote] = STATE(61),
    [sym_quasisyntax] = STATE(61),
    [sym_unsyntax] = STATE(61),
    [sym_unsyntax_splicing] = STATE(61),
    [sym_datum_label] = STATE(61),
    [sym_datum_reference] = STATE(61),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(255),
    [sym_number] = ACTIONS(257),
    [sym_character] = ACTIONS(255),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(257),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [29] = {
    [sym__intertoken] = STATE(22),
    [sym__datum] = STATE(75),
    [sym_block_comment] = STATE(22),
    [sym_sexp_comment] = STATE(22),
    [sym_string] = STATE(75),
    [sym_list] = STATE(75),
    [sym_vector] = STATE(75),
    [sym_byte_vector] = STATE(75),
    [sym_quote] = STATE(75),
    [sym_quasiquote] = STATE(75),
    [sym_unquote] = STATE(75),
    [sym_unquote_splicing] = STATE(75),
    [sym_syntax_quote] = STATE(75),
    [sym_quasisyntax] = STATE(75),
    [sym_unsyntax] = STATE(75),
    [sym_unsyntax_splicing] = STATE(75),
    [sym_datum_label] = STATE(75),
    [sym_datum_reference] = STATE(75),
    [aux_sym_sexp_comment_repeat1] = STATE(22),
    [aux_sym__intertoken_token1] = ACTIONS(259),
    [sym_comment] = ACTIONS(259),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(259),
    [sym_boolean] = ACTIONS(261),
    [sym_number] = ACTIONS(263),
    [sym_character] = ACTIONS(261),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(263),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [30] = {
    [sym__intertoken] = STATE(23),
    [sym__datum] = STATE(63),
    [sym_block_comment] = STATE(23),
    [sym_sexp_comment] = STATE(23),
    [sym_string] = STATE(63),
    [sym_list] = STATE(63),
    [sym_vector] = STATE(63),
    [sym_byte_vector] = STATE(63),
    [sym_quote] = STATE(63),
    [sym_quasiquote] = STATE(63),
    [sym_unquote] = STATE(63),
    [sym_unquote_splicing] = STATE(63),
    [sym_syntax_quote] = STATE(63),
    [sym_quasisyntax] = STATE(63),
    [sym_unsyntax] = STATE(63),
    [sym_unsyntax_splicing] = STATE(63),
    [sym_datum_label] = STATE(63),
    [sym_datum_reference] = STATE(63),
    [aux_sym_sexp_comment_repeat1] = STATE(23),
    [aux_sym__intertoken_token1] = ACTIONS(265),
    [sym_comment] = ACTIONS(265),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(265),
    [sym_boolean] = ACTIONS(267),
    [sym_number] = ACTIONS(269),
    [sym_character] = ACTIONS(267),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(269),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [31] = {
    [sym__intertoken] = STATE(40),
    [sym__datum] = STATE(93),
    [sym_block_comment] = STATE(40),
    [sym_sexp_comment] = STATE(40),
    [sym_string] = STATE(93),
    [sym_list] = STATE(93),
    [sym_vector] = STATE(93),
    [sym_byte_vector] = STATE(93),
    [sym_quote] = STATE(93),
    [sym_quasiquote] = STATE(93),
    [sym_unquote] = STATE(93),
    [sym_unquote_splicing] = STATE(93),
    [sym_syntax_quote] = STATE(93),
    [sym_quasisyntax] = STATE(93),
    [sym_unsyntax] = STATE(93),
    [sym_unsyntax_splicing] = STATE(93),
    [sym_datum_label] = STATE(93),
    [sym_datum_reference] = STATE(93),
    [aux_sym_sexp_comment_repeat1] = STATE(40),
    [aux_sym__intertoken_token1] = ACTIONS(271),
    [sym_comment] = ACTIONS(271),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(271),
    [sym_boolean] = ACTIONS(273),
    [sym_number] = ACTIONS(275),
    [sym_character] = ACTIONS(273),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(275),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [32] = {
    [sym__intertoken] = STATE(28),
    [sym__datum] = STATE(73),
    [sym_block_comment] = STATE(28),
    [sym_sexp_comment] = STATE(28),
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
    [aux_sym_sexp_comment_repeat1] = STATE(28),
    [aux_sym__intertoken_token1] = ACTIONS(305),
    [sym_comment] = ACTIONS(305),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(305),
    [sym_boolean] = ACTIONS(307),
    [sym_number] = ACTIONS(309),
    [sym_character] = ACTIONS(307),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(309),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [33] = {
    [sym__intertoken] = STATE(42),
    [sym__datum] = STATE(116),
    [sym_block_comment] = STATE(42),
    [sym_sexp_comment] = STATE(42),
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
    [aux_sym_sexp_comment_repeat1] = STATE(42),
    [aux_sym__intertoken_token1] = ACTIONS(311),
    [sym_comment] = ACTIONS(311),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(311),
    [sym_boolean] = ACTIONS(313),
    [sym_number] = ACTIONS(315),
    [sym_character] = ACTIONS(313),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(315),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [34] = {
    [sym__intertoken] = STATE(43),
    [sym__datum] = STATE(119),
    [sym_block_comment] = STATE(43),
    [sym_sexp_comment] = STATE(43),
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
    [aux_sym_sexp_comment_repeat1] = STATE(43),
    [aux_sym__intertoken_token1] = ACTIONS(317),
    [sym_comment] = ACTIONS(317),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(317),
    [sym_boolean] = ACTIONS(319),
    [sym_number] = ACTIONS(321),
    [sym_character] = ACTIONS(319),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(321),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [35] = {
    [sym__intertoken] = STATE(44),
    [sym__datum] = STATE(92),
    [sym_block_comment] = STATE(44),
    [sym_sexp_comment] = STATE(44),
    [sym_string] = STATE(92),
    [sym_list] = STATE(92),
    [sym_vector] = STATE(92),
    [sym_byte_vector] = STATE(92),
    [sym_quote] = STATE(92),
    [sym_quasiquote] = STATE(92),
    [sym_unquote] = STATE(92),
    [sym_unquote_splicing] = STATE(92),
    [sym_syntax_quote] = STATE(92),
    [sym_quasisyntax] = STATE(92),
    [sym_unsyntax] = STATE(92),
    [sym_unsyntax_splicing] = STATE(92),
    [sym_datum_label] = STATE(92),
    [sym_datum_reference] = STATE(92),
    [aux_sym_sexp_comment_repeat1] = STATE(44),
    [aux_sym__intertoken_token1] = ACTIONS(323),
    [sym_comment] = ACTIONS(323),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(323),
    [sym_boolean] = ACTIONS(325),
    [sym_number] = ACTIONS(327),
    [sym_character] = ACTIONS(325),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(327),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [36] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(115),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
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
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(329),
    [sym_comment] = ACTIONS(329),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(329),
    [sym_boolean] = ACTIONS(331),
    [sym_number] = ACTIONS(333),
    [sym_character] = ACTIONS(331),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(333),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [37] = {
    [sym__intertoken] = STATE(46),
    [sym__datum] = STATE(120),
    [sym_block_comment] = STATE(46),
    [sym_sexp_comment] = STATE(46),
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
    [aux_sym_sexp_comment_repeat1] = STATE(46),
    [aux_sym__intertoken_token1] = ACTIONS(335),
    [sym_comment] = ACTIONS(335),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(335),
    [sym_boolean] = ACTIONS(337),
    [sym_number] = ACTIONS(339),
    [sym_character] = ACTIONS(337),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(339),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [38] = {
    [sym__intertoken] = STATE(47),
    [sym__datum] = STATE(94),
    [sym_block_comment] = STATE(47),
    [sym_sexp_comment] = STATE(47),
    [sym_string] = STATE(94),
    [sym_list] = STATE(94),
    [sym_vector] = STATE(94),
    [sym_byte_vector] = STATE(94),
    [sym_quote] = STATE(94),
    [sym_quasiquote] = STATE(94),
    [sym_unquote] = STATE(94),
    [sym_unquote_splicing] = STATE(94),
    [sym_syntax_quote] = STATE(94),
    [sym_quasisyntax] = STATE(94),
    [sym_unsyntax] = STATE(94),
    [sym_unsyntax_splicing] = STATE(94),
    [sym_datum_label] = STATE(94),
    [sym_datum_reference] = STATE(94),
    [aux_sym_sexp_comment_repeat1] = STATE(47),
    [aux_sym__intertoken_token1] = ACTIONS(341),
    [sym_comment] = ACTIONS(341),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(341),
    [sym_boolean] = ACTIONS(343),
    [sym_number] = ACTIONS(345),
    [sym_character] = ACTIONS(343),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(345),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [39] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(96),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(96),
    [sym_list] = STATE(96),
    [sym_vector] = STATE(96),
    [sym_byte_vector] = STATE(96),
    [sym_quote] = STATE(96),
    [sym_quasiquote] = STATE(96),
    [sym_unquote] = STATE(96),
    [sym_unquote_splicing] = STATE(96),
    [sym_syntax_quote] = STATE(96),
    [sym_quasisyntax] = STATE(96),
    [sym_unsyntax] = STATE(96),
    [sym_unsyntax_splicing] = STATE(96),
    [sym_datum_label] = STATE(96),
    [sym_datum_reference] = STATE(96),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(347),
    [sym_number] = ACTIONS(349),
    [sym_character] = ACTIONS(347),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(349),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [40] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(101),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(101),
    [sym_list] = STATE(101),
    [sym_vector] = STATE(101),
    [sym_byte_vector] = STATE(101),
    [sym_quote] = STATE(101),
    [sym_quasiquote] = STATE(101),
    [sym_unquote] = STATE(101),
    [sym_unquote_splicing] = STATE(101),
    [sym_syntax_quote] = STATE(101),
    [sym_quasisyntax] = STATE(101),
    [sym_unsyntax] = STATE(101),
    [sym_unsyntax_splicing] = STATE(101),
    [sym_datum_label] = STATE(101),
    [sym_datum_reference] = STATE(101),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(351),
    [sym_number] = ACTIONS(353),
    [sym_character] = ACTIONS(351),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(353),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [41] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(102),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(355),
    [sym_number] = ACTIONS(357),
    [sym_character] = ACTIONS(355),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(357),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [42] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(91),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
    [sym_string] = STATE(91),
    [sym_list] = STATE(91),
    [sym_vector] = STATE(91),
    [sym_byte_vector] = STATE(91),
    [sym_quote] = STATE(91),
    [sym_quasiquote] = STATE(91),
    [sym_unquote] = STATE(91),
    [sym_unquote_splicing] = STATE(91),
    [sym_syntax_quote] = STATE(91),
    [sym_quasisyntax] = STATE(91),
    [sym_unsyntax] = STATE(91),
    [sym_unsyntax_splicing] = STATE(91),
    [sym_datum_label] = STATE(91),
    [sym_datum_reference] = STATE(91),
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(359),
    [sym_number] = ACTIONS(361),
    [sym_character] = ACTIONS(359),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(361),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [43] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(104),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(363),
    [sym_number] = ACTIONS(365),
    [sym_character] = ACTIONS(363),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(365),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [44] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(105),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(367),
    [sym_number] = ACTIONS(369),
    [sym_character] = ACTIONS(367),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(369),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [45] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(106),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(371),
    [sym_number] = ACTIONS(373),
    [sym_character] = ACTIONS(371),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(373),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [46] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(107),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(375),
    [sym_number] = ACTIONS(377),
    [sym_character] = ACTIONS(375),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(377),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [47] = {
    [sym__intertoken] = STATE(78),
    [sym__datum] = STATE(108),
    [sym_block_comment] = STATE(78),
    [sym_sexp_comment] = STATE(78),
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
    [aux_sym_sexp_comment_repeat1] = STATE(78),
    [aux_sym__intertoken_token1] = ACTIONS(209),
    [sym_comment] = ACTIONS(209),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(209),
    [sym_boolean] = ACTIONS(379),
    [sym_number] = ACTIONS(381),
    [sym_character] = ACTIONS(379),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(381),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [48] = {
    [sym__intertoken] = STATE(39),
    [sym__datum] = STATE(95),
    [sym_block_comment] = STATE(39),
    [sym_sexp_comment] = STATE(39),
    [sym_string] = STATE(95),
    [sym_list] = STATE(95),
    [sym_vector] = STATE(95),
    [sym_byte_vector] = STATE(95),
    [sym_quote] = STATE(95),
    [sym_quasiquote] = STATE(95),
    [sym_unquote] = STATE(95),
    [sym_unquote_splicing] = STATE(95),
    [sym_syntax_quote] = STATE(95),
    [sym_quasisyntax] = STATE(95),
    [sym_unsyntax] = STATE(95),
    [sym_unsyntax_splicing] = STATE(95),
    [sym_datum_label] = STATE(95),
    [sym_datum_reference] = STATE(95),
    [aux_sym_sexp_comment_repeat1] = STATE(39),
    [aux_sym__intertoken_token1] = ACTIONS(383),
    [sym_comment] = ACTIONS(383),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(383),
    [sym_boolean] = ACTIONS(385),
    [sym_number] = ACTIONS(387),
    [sym_character] = ACTIONS(385),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(387),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [49] = {
    [sym__intertoken] = STATE(24),
    [sym__datum] = STATE(66),
    [sym_block_comment] = STATE(24),
    [sym_sexp_comment] = STATE(24),
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
    [aux_sym_sexp_comment_repeat1] = STATE(24),
    [aux_sym__intertoken_token1] = ACTIONS(389),
    [sym_comment] = ACTIONS(389),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(389),
    [sym_boolean] = ACTIONS(391),
    [sym_number] = ACTIONS(393),
    [sym_character] = ACTIONS(391),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(393),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [50] = {
    [sym__intertoken] = STATE(25),
    [sym__datum] = STATE(68),
    [sym_block_comment] = STATE(25),
    [sym_sexp_comment] = STATE(25),
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
    [aux_sym_sexp_comment_repeat1] = STATE(25),
    [aux_sym__intertoken_token1] = ACTIONS(395),
    [sym_comment] = ACTIONS(395),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(395),
    [sym_boolean] = ACTIONS(397),
    [sym_number] = ACTIONS(399),
    [sym_character] = ACTIONS(397),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(399),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [51] = {
    [sym__intertoken] = STATE(27),
    [sym__datum] = STATE(71),
    [sym_block_comment] = STATE(27),
    [sym_sexp_comment] = STATE(27),
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
    [aux_sym_sexp_comment_repeat1] = STATE(27),
    [aux_sym__intertoken_token1] = ACTIONS(401),
    [sym_comment] = ACTIONS(401),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(401),
    [sym_boolean] = ACTIONS(403),
    [sym_number] = ACTIONS(405),
    [sym_character] = ACTIONS(403),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(405),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [52] = {
    [sym__intertoken] = STATE(41),
    [sym__datum] = STATE(114),
    [sym_block_comment] = STATE(41),
    [sym_sexp_comment] = STATE(41),
    [sym_string] = STATE(114),
    [sym_list] = STATE(114),
    [sym_vector] = STATE(114),
    [sym_byte_vector] = STATE(114),
    [sym_quote] = STATE(114),
    [sym_quasiquote] = STATE(114),
    [sym_unquote] = STATE(114),
    [sym_unquote_splicing] = STATE(114),
    [sym_syntax_quote] = STATE(114),
    [sym_quasisyntax] = STATE(114),
    [sym_unsyntax] = STATE(114),
    [sym_unsyntax_splicing] = STATE(114),
    [sym_datum_label] = STATE(114),
    [sym_datum_reference] = STATE(114),
    [aux_sym_sexp_comment_repeat1] = STATE(41),
    [aux_sym__intertoken_token1] = ACTIONS(407),
    [sym_comment] = ACTIONS(407),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(407),
    [sym_boolean] = ACTIONS(409),
    [sym_number] = ACTIONS(411),
    [sym_character] = ACTIONS(409),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(411),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
  [53] = {
    [sym__datum] = STATE(64),
    [sym_string] = STATE(64),
    [sym_list] = STATE(64),
    [sym_vector] = STATE(64),
    [sym_byte_vector] = STATE(64),
    [sym_quote] = STATE(64),
    [sym_quasiquote] = STATE(64),
    [sym_unquote] = STATE(64),
    [sym_unquote_splicing] = STATE(64),
    [sym_syntax_quote] = STATE(64),
    [sym_quasisyntax] = STATE(64),
    [sym_unsyntax] = STATE(64),
    [sym_unsyntax_splicing] = STATE(64),
    [sym_datum_label] = STATE(64),
    [sym_datum_reference] = STATE(64),
    [sym_boolean] = ACTIONS(413),
    [sym_number] = ACTIONS(415),
    [sym_character] = ACTIONS(413),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [sym_symbol] = ACTIONS(415),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(39),
  },
  [54] = {
    [sym__datum] = STATE(111),
    [sym_string] = STATE(111),
    [sym_list] = STATE(111),
    [sym_vector] = STATE(111),
    [sym_byte_vector] = STATE(111),
    [sym_quote] = STATE(111),
    [sym_quasiquote] = STATE(111),
    [sym_unquote] = STATE(111),
    [sym_unquote_splicing] = STATE(111),
    [sym_syntax_quote] = STATE(111),
    [sym_quasisyntax] = STATE(111),
    [sym_unsyntax] = STATE(111),
    [sym_unsyntax_splicing] = STATE(111),
    [sym_datum_label] = STATE(111),
    [sym_datum_reference] = STATE(111),
    [sym_boolean] = ACTIONS(417),
    [sym_number] = ACTIONS(419),
    [sym_character] = ACTIONS(417),
    [anon_sym_DQUOTE] = ACTIONS(277),
    [sym_symbol] = ACTIONS(419),
    [anon_sym_LPAREN] = ACTIONS(279),
    [anon_sym_LBRACK] = ACTIONS(281),
    [anon_sym_POUND_LPAREN] = ACTIONS(283),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(285),
    [anon_sym_POUNDu8_LPAREN] = ACTIONS(285),
    [anon_sym_SQUOTE] = ACTIONS(287),
    [anon_sym_BQUOTE] = ACTIONS(289),
    [anon_sym_COMMA] = ACTIONS(291),
    [anon_sym_COMMA_AT] = ACTIONS(293),
    [anon_sym_POUND_SQUOTE] = ACTIONS(295),
    [anon_sym_POUND_BQUOTE] = ACTIONS(297),
    [anon_sym_POUND_COMMA] = ACTIONS(299),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(301),
    [anon_sym_POUND] = ACTIONS(303),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(423), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(421), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [33] = 2,
    ACTIONS(427), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(425), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [66] = 2,
    ACTIONS(431), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(429), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [99] = 2,
    ACTIONS(435), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(433), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [132] = 2,
    ACTIONS(439), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(437), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [165] = 2,
    ACTIONS(443), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(441), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [198] = 2,
    ACTIONS(447), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(445), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [231] = 2,
    ACTIONS(451), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(449), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [264] = 2,
    ACTIONS(455), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(453), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [297] = 2,
    ACTIONS(459), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(457), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [330] = 2,
    ACTIONS(463), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(461), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
    ACTIONS(467), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(465), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [396] = 2,
    ACTIONS(471), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(469), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [429] = 2,
    ACTIONS(475), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(473), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [462] = 2,
    ACTIONS(479), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(477), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [495] = 2,
    ACTIONS(483), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(481), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [528] = 2,
    ACTIONS(487), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(485), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [561] = 2,
    ACTIONS(491), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(489), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [594] = 2,
    ACTIONS(495), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(493), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [627] = 2,
    ACTIONS(499), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(497), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [660] = 2,
    ACTIONS(503), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(501), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [693] = 2,
    ACTIONS(507), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(505), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [726] = 2,
    ACTIONS(511), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(509), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [759] = 6,
    ACTIONS(516), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(519), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(513), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
    STATE(78), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_sexp_comment_repeat1,
    ACTIONS(524), 5,
      sym_number,
      sym_symbol,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(522), 14,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [800] = 2,
    ACTIONS(528), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(526), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [833] = 2,
    ACTIONS(532), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(530), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [866] = 2,
    ACTIONS(536), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(534), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [899] = 2,
    ACTIONS(540), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(538), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [932] = 2,
    ACTIONS(544), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(542), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [965] = 2,
    ACTIONS(548), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(546), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [998] = 2,
    ACTIONS(552), 6,
      sym_number,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
      anon_sym_POUND,
    ACTIONS(550), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_character,
      anon_sym_DQUOTE,
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
  [1031] = 5,
    ACTIONS(557), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(560), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(563), 1,
      anon_sym_RPAREN,
    ACTIONS(554), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(86), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [1053] = 5,
    ACTIONS(567), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(569), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(571), 1,
      anon_sym_RPAREN,
    ACTIONS(565), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(86), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [1075] = 5,
    ACTIONS(567), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(569), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(575), 1,
      anon_sym_RPAREN,
    ACTIONS(573), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(89), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [1097] = 5,
    ACTIONS(567), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(569), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(577), 1,
      anon_sym_RPAREN,
    ACTIONS(565), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(86), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [1119] = 5,
    ACTIONS(567), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(569), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(581), 1,
      anon_sym_RPAREN,
    ACTIONS(579), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(87), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [1141] = 1,
    ACTIONS(425), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1151] = 1,
    ACTIONS(473), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1161] = 1,
    ACTIONS(489), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1171] = 1,
    ACTIONS(493), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1181] = 1,
    ACTIONS(461), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1191] = 1,
    ACTIONS(509), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1201] = 1,
    ACTIONS(526), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1211] = 1,
    ACTIONS(530), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1221] = 1,
    ACTIONS(534), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1231] = 1,
    ACTIONS(538), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1241] = 1,
    ACTIONS(546), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1251] = 1,
    ACTIONS(550), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1261] = 1,
    ACTIONS(497), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1271] = 1,
    ACTIONS(429), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1281] = 1,
    ACTIONS(433), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1291] = 1,
    ACTIONS(437), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1301] = 1,
    ACTIONS(441), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1311] = 1,
    ACTIONS(445), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1321] = 1,
    ACTIONS(449), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1331] = 1,
    ACTIONS(421), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1341] = 1,
    ACTIONS(457), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1351] = 1,
    ACTIONS(542), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1361] = 1,
    ACTIONS(505), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1371] = 1,
    ACTIONS(501), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1381] = 1,
    ACTIONS(481), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1391] = 1,
    ACTIONS(453), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1401] = 1,
    ACTIONS(477), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1411] = 1,
    ACTIONS(469), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1421] = 1,
    ACTIONS(465), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1431] = 1,
    ACTIONS(485), 7,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_number,
      anon_sym_RPAREN,
  [1441] = 4,
    ACTIONS(583), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(585), 1,
      aux_sym_block_comment_token1,
    ACTIONS(587), 1,
      anon_sym_PIPE_POUND,
    STATE(126), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1455] = 4,
    ACTIONS(583), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(589), 1,
      aux_sym_block_comment_token1,
    ACTIONS(591), 1,
      anon_sym_PIPE_POUND,
    STATE(121), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1469] = 4,
    ACTIONS(583), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(593), 1,
      aux_sym_block_comment_token1,
    ACTIONS(595), 1,
      anon_sym_PIPE_POUND,
    STATE(125), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1483] = 4,
    ACTIONS(583), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(585), 1,
      aux_sym_block_comment_token1,
    ACTIONS(597), 1,
      anon_sym_PIPE_POUND,
    STATE(126), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1497] = 4,
    ACTIONS(583), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(585), 1,
      aux_sym_block_comment_token1,
    ACTIONS(599), 1,
      anon_sym_PIPE_POUND,
    STATE(126), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1511] = 4,
    ACTIONS(601), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(604), 1,
      aux_sym_block_comment_token1,
    ACTIONS(607), 1,
      anon_sym_PIPE_POUND,
    STATE(126), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1525] = 4,
    ACTIONS(583), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(609), 1,
      aux_sym_block_comment_token1,
    ACTIONS(611), 1,
      anon_sym_PIPE_POUND,
    STATE(124), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1539] = 3,
    ACTIONS(613), 1,
      anon_sym_DQUOTE,
    STATE(131), 1,
      aux_sym_string_repeat1,
    ACTIONS(615), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1550] = 3,
    ACTIONS(617), 1,
      anon_sym_DQUOTE,
    STATE(132), 1,
      aux_sym_string_repeat1,
    ACTIONS(619), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1561] = 3,
    ACTIONS(621), 1,
      anon_sym_DQUOTE,
    STATE(130), 1,
      aux_sym_string_repeat1,
    ACTIONS(623), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1572] = 3,
    ACTIONS(626), 1,
      anon_sym_DQUOTE,
    STATE(130), 1,
      aux_sym_string_repeat1,
    ACTIONS(628), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1583] = 3,
    ACTIONS(630), 1,
      anon_sym_DQUOTE,
    STATE(130), 1,
      aux_sym_string_repeat1,
    ACTIONS(628), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1594] = 2,
    ACTIONS(544), 1,
      aux_sym_block_comment_token1,
    ACTIONS(542), 2,
      anon_sym_POUND_PIPE,
      anon_sym_PIPE_POUND,
  [1602] = 2,
    ACTIONS(507), 1,
      aux_sym_block_comment_token1,
    ACTIONS(505), 2,
      anon_sym_POUND_PIPE,
      anon_sym_PIPE_POUND,
  [1610] = 2,
    ACTIONS(632), 1,
      anon_sym_POUND,
    ACTIONS(634), 1,
      anon_sym_EQ,
  [1617] = 2,
    ACTIONS(636), 1,
      anon_sym_POUND,
    ACTIONS(638), 1,
      anon_sym_EQ,
  [1624] = 1,
    ACTIONS(640), 1,
      ts_builtin_sym_end,
  [1628] = 1,
    ACTIONS(642), 1,
      aux_sym_datum_label_token1,
  [1632] = 1,
    ACTIONS(644), 1,
      aux_sym_datum_label_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(55)] = 0,
  [SMALL_STATE(56)] = 33,
  [SMALL_STATE(57)] = 66,
  [SMALL_STATE(58)] = 99,
  [SMALL_STATE(59)] = 132,
  [SMALL_STATE(60)] = 165,
  [SMALL_STATE(61)] = 198,
  [SMALL_STATE(62)] = 231,
  [SMALL_STATE(63)] = 264,
  [SMALL_STATE(64)] = 297,
  [SMALL_STATE(65)] = 330,
  [SMALL_STATE(66)] = 363,
  [SMALL_STATE(67)] = 396,
  [SMALL_STATE(68)] = 429,
  [SMALL_STATE(69)] = 462,
  [SMALL_STATE(70)] = 495,
  [SMALL_STATE(71)] = 528,
  [SMALL_STATE(72)] = 561,
  [SMALL_STATE(73)] = 594,
  [SMALL_STATE(74)] = 627,
  [SMALL_STATE(75)] = 660,
  [SMALL_STATE(76)] = 693,
  [SMALL_STATE(77)] = 726,
  [SMALL_STATE(78)] = 759,
  [SMALL_STATE(79)] = 800,
  [SMALL_STATE(80)] = 833,
  [SMALL_STATE(81)] = 866,
  [SMALL_STATE(82)] = 899,
  [SMALL_STATE(83)] = 932,
  [SMALL_STATE(84)] = 965,
  [SMALL_STATE(85)] = 998,
  [SMALL_STATE(86)] = 1031,
  [SMALL_STATE(87)] = 1053,
  [SMALL_STATE(88)] = 1075,
  [SMALL_STATE(89)] = 1097,
  [SMALL_STATE(90)] = 1119,
  [SMALL_STATE(91)] = 1141,
  [SMALL_STATE(92)] = 1151,
  [SMALL_STATE(93)] = 1161,
  [SMALL_STATE(94)] = 1171,
  [SMALL_STATE(95)] = 1181,
  [SMALL_STATE(96)] = 1191,
  [SMALL_STATE(97)] = 1201,
  [SMALL_STATE(98)] = 1211,
  [SMALL_STATE(99)] = 1221,
  [SMALL_STATE(100)] = 1231,
  [SMALL_STATE(101)] = 1241,
  [SMALL_STATE(102)] = 1251,
  [SMALL_STATE(103)] = 1261,
  [SMALL_STATE(104)] = 1271,
  [SMALL_STATE(105)] = 1281,
  [SMALL_STATE(106)] = 1291,
  [SMALL_STATE(107)] = 1301,
  [SMALL_STATE(108)] = 1311,
  [SMALL_STATE(109)] = 1321,
  [SMALL_STATE(110)] = 1331,
  [SMALL_STATE(111)] = 1341,
  [SMALL_STATE(112)] = 1351,
  [SMALL_STATE(113)] = 1361,
  [SMALL_STATE(114)] = 1371,
  [SMALL_STATE(115)] = 1381,
  [SMALL_STATE(116)] = 1391,
  [SMALL_STATE(117)] = 1401,
  [SMALL_STATE(118)] = 1411,
  [SMALL_STATE(119)] = 1421,
  [SMALL_STATE(120)] = 1431,
  [SMALL_STATE(121)] = 1441,
  [SMALL_STATE(122)] = 1455,
  [SMALL_STATE(123)] = 1469,
  [SMALL_STATE(124)] = 1483,
  [SMALL_STATE(125)] = 1497,
  [SMALL_STATE(126)] = 1511,
  [SMALL_STATE(127)] = 1525,
  [SMALL_STATE(128)] = 1539,
  [SMALL_STATE(129)] = 1550,
  [SMALL_STATE(130)] = 1561,
  [SMALL_STATE(131)] = 1572,
  [SMALL_STATE(132)] = 1583,
  [SMALL_STATE(133)] = 1594,
  [SMALL_STATE(134)] = 1602,
  [SMALL_STATE(135)] = 1610,
  [SMALL_STATE(136)] = 1617,
  [SMALL_STATE(137)] = 1624,
  [SMALL_STATE(138)] = 1628,
  [SMALL_STATE(139)] = 1632,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [120] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [132] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [135] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [138] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [141] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [150] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [153] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [162] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [183] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [257] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [263] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [299] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [309] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [315] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [321] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [327] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [333] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [339] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [345] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [349] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [353] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [357] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [361] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [365] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [369] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [373] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [377] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [381] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [387] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [393] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [399] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [405] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [411] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [415] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [419] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 2, 0, 0),
  [423] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 2, 0, 0),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 3, 0, 0),
  [427] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 3, 0, 0),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [431] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_syntax_quote, 3, 0, 0),
  [435] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_syntax_quote, 3, 0, 0),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasisyntax, 3, 0, 0),
  [439] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasisyntax, 3, 0, 0),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax, 3, 0, 0),
  [443] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax, 3, 0, 0),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax_splicing, 3, 0, 0),
  [447] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax_splicing, 3, 0, 0),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_datum_reference, 3, 0, 1),
  [451] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_datum_reference, 3, 0, 1),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 2, 0, 0),
  [455] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 2, 0, 0),
  [457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_datum_label, 4, 0, 1),
  [459] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_datum_label, 4, 0, 1),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sexp_comment, 2, 0, 0),
  [463] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sexp_comment, 2, 0, 0),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [467] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [471] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [473] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_syntax_quote, 2, 0, 0),
  [475] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_syntax_quote, 2, 0, 0),
  [477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byte_vector, 2, 0, 0),
  [479] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_byte_vector, 2, 0, 0),
  [481] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasisyntax, 2, 0, 0),
  [483] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasisyntax, 2, 0, 0),
  [485] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax, 2, 0, 0),
  [487] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax, 2, 0, 0),
  [489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 2, 0, 0),
  [491] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 2, 0, 0),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax_splicing, 2, 0, 0),
  [495] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax_splicing, 2, 0, 0),
  [497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2, 0, 0),
  [499] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 2, 0, 0),
  [501] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [503] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 3, 0, 0),
  [507] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 3, 0, 0),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sexp_comment, 3, 0, 0),
  [511] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sexp_comment, 3, 0, 0),
  [513] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [516] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [519] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [522] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0),
  [524] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [528] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3, 0, 0),
  [532] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 3, 0, 0),
  [534] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 3, 0, 0),
  [536] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 3, 0, 0),
  [538] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byte_vector, 3, 0, 0),
  [540] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_byte_vector, 3, 0, 0),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 2, 0, 0),
  [544] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 2, 0, 0),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 3, 0, 0),
  [548] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 3, 0, 0),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [552] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [554] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(86),
  [557] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(127),
  [560] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [585] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [589] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [593] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [601] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [604] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(126),
  [607] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0),
  [609] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [621] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [623] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [640] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
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
