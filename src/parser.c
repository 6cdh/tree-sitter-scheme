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
#define STATE_COUNT 72
#define LARGE_STATE_COUNT 29
#define SYMBOL_COUNT 54
#define ALIAS_COUNT 0
#define TOKEN_COUNT 30
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

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
  anon_sym_SQUOTE = 22,
  anon_sym_BQUOTE = 23,
  anon_sym_COMMA = 24,
  anon_sym_COMMA_AT = 25,
  anon_sym_POUND_SQUOTE = 26,
  anon_sym_POUND_BQUOTE = 27,
  anon_sym_POUND_COMMA = 28,
  anon_sym_POUND_COMMA_AT = 29,
  sym_program = 30,
  sym__token = 31,
  sym__intertoken = 32,
  sym__datum = 33,
  sym_block_comment = 34,
  sym_sexp_comment = 35,
  sym_string = 36,
  sym_list = 37,
  sym_vector = 38,
  sym_byte_vector = 39,
  sym_quote = 40,
  sym_quasiquote = 41,
  sym_unquote = 42,
  sym_unquote_splicing = 43,
  sym_syntax_quote = 44,
  sym_quasisyntax = 45,
  sym_unsyntax = 46,
  sym_unsyntax_splicing = 47,
  aux_sym_program_repeat1 = 48,
  aux_sym_block_comment_repeat1 = 49,
  aux_sym_sexp_comment_repeat1 = 50,
  aux_sym_string_repeat1 = 51,
  aux_sym_list_repeat1 = 52,
  aux_sym_byte_vector_repeat1 = 53,
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
  [anon_sym_SQUOTE] = "'",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_COMMA] = ",",
  [anon_sym_COMMA_AT] = ",@",
  [anon_sym_POUND_SQUOTE] = "#'",
  [anon_sym_POUND_BQUOTE] = "#`",
  [anon_sym_POUND_COMMA] = "#,",
  [anon_sym_POUND_COMMA_AT] = "#,@",
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
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_COMMA_AT] = anon_sym_COMMA_AT,
  [anon_sym_POUND_SQUOTE] = anon_sym_POUND_SQUOTE,
  [anon_sym_POUND_BQUOTE] = anon_sym_POUND_BQUOTE,
  [anon_sym_POUND_COMMA] = anon_sym_POUND_COMMA,
  [anon_sym_POUND_COMMA_AT] = anon_sym_POUND_COMMA_AT,
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
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 61,
  [65] = 63,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 43,
  [70] = 32,
  [71] = 71,
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
  {'^', '_'}, {'a', 'z'}, {'~', '~'}, {0xa1, 0xaa}, {0xac, 0xac}, {0xae, 0xba}, {0xbc, 0x377}, {0x37a, 0x37f},
  {0x384, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x487}, {0x48a, 0x52f}, {0x531, 0x556}, {0x559, 0x58a}, {0x58d, 0x58f},
  {0x591, 0x5c7}, {0x5d0, 0x5ea}, {0x5ef, 0x5f4}, {0x606, 0x61b}, {0x61d, 0x65f}, {0x66a, 0x6dc}, {0x6de, 0x6ef}, {0x6fa, 0x70d},
  {0x710, 0x74a}, {0x74d, 0x7b1}, {0x7ca, 0x7fa}, {0x7fd, 0x82d}, {0x830, 0x83e}, {0x840, 0x85b}, {0x85e, 0x85e}, {0x860, 0x86a},
  {0x870, 0x88e}, {0x898, 0x8e1}, {0x8e3, 0x902}, {0x904, 0x93a}, {0x93c, 0x93d}, {0x941, 0x948}, {0x94d, 0x94d}, {0x950, 0x965},
  {0x970, 0x981}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bc, 0x9bd},
  {0x9c1, 0x9c4}, {0x9cd, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e3}, {0x9f0, 0x9fe}, {0xa01, 0xa02}, {0xa05, 0xa0a}, {0xa0f, 0xa10},
  {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa3c, 0xa3c}, {0xa41, 0xa42}, {0xa47, 0xa48},
  {0xa4b, 0xa4d}, {0xa51, 0xa51}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa70, 0xa76}, {0xa81, 0xa82}, {0xa85, 0xa8d}, {0xa8f, 0xa91},
  {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabc, 0xabd}, {0xac1, 0xac5}, {0xac7, 0xac8}, {0xacd, 0xacd},
  {0xad0, 0xad0}, {0xae0, 0xae3}, {0xaf0, 0xaf1}, {0xaf9, 0xaff}, {0xb01, 0xb01}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28},
  {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39}, {0xb3c, 0xb3d}, {0xb3f, 0xb3f}, {0xb41, 0xb44}, {0xb4d, 0xb4d}, {0xb55, 0xb56},
  {0xb5c, 0xb5d}, {0xb5f, 0xb63}, {0xb70, 0xb77}, {0xb82, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95}, {0xb99, 0xb9a},
  {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbc0, 0xbc0}, {0xbcd, 0xbcd}, {0xbd0, 0xbd0},
  {0xbf0, 0xbfa}, {0xc00, 0xc00}, {0xc04, 0xc0c}, {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3c, 0xc40}, {0xc46, 0xc48},
  {0xc4a, 0xc4d}, {0xc55, 0xc56}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc63}, {0xc77, 0xc81}, {0xc84, 0xc8c}, {0xc8e, 0xc90},
  {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbc, 0xcbd}, {0xcbf, 0xcbf}, {0xcc6, 0xcc6}, {0xccc, 0xccd}, {0xcdd, 0xcde},
  {0xce0, 0xce3}, {0xcf1, 0xcf2}, {0xd00, 0xd01}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3d}, {0xd41, 0xd44}, {0xd4d, 0xd4f},
  {0xd54, 0xd56}, {0xd58, 0xd63}, {0xd70, 0xd7f}, {0xd81, 0xd81}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd},
  {0xdc0, 0xdc6}, {0xdca, 0xdca}, {0xdd2, 0xdd4}, {0xdd6, 0xdd6}, {0xdf4, 0xdf4}, {0xe01, 0xe3a}, {0xe3f, 0xe4f}, {0xe5a, 0xe5b},
  {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6},
  {0xec8, 0xece}, {0xedc, 0xedf}, {0xf00, 0xf1f}, {0xf2a, 0xf39}, {0xf40, 0xf47}, {0xf49, 0xf6c}, {0xf71, 0xf7e}, {0xf80, 0xf97},
  {0xf99, 0xfbc}, {0xfbe, 0xfcc}, {0xfce, 0xfda}, {0x1000, 0x102a}, {0x102d, 0x1030}, {0x1032, 0x1037}, {0x1039, 0x103a}, {0x103d, 0x103f},
  {0x104a, 0x1055}, {0x1058, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1082}, {0x1085, 0x1086}, {0x108d, 0x108e}, {0x109d, 0x10c5}, {0x10c7, 0x10c7},
  {0x10cd, 0x10cd}, {0x10d0, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d},
  {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315},
  {0x1318, 0x135a}, {0x135d, 0x137c}, {0x1380, 0x1399}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd}, {0x1400, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16f8},
  {0x1700, 0x1714}, {0x171f, 0x1733}, {0x1735, 0x1736}, {0x1740, 0x1753}, {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1772, 0x1773}, {0x1780, 0x17b5},
  {0x17b7, 0x17bd}, {0x17c6, 0x17c6}, {0x17c9, 0x17dd}, {0x17f0, 0x17f9}, {0x1800, 0x180d}, {0x180f, 0x180f}, {0x1820, 0x1878}, {0x1880, 0x18aa},
  {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1920, 0x1922}, {0x1927, 0x1928}, {0x1932, 0x1932}, {0x1939, 0x193b}, {0x1940, 0x1940}, {0x1944, 0x1945},
  {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x19da, 0x19da}, {0x19de, 0x1a18}, {0x1a1b, 0x1a1b}, {0x1a1e, 0x1a54},
  {0x1a56, 0x1a56}, {0x1a58, 0x1a5e}, {0x1a60, 0x1a60}, {0x1a62, 0x1a62}, {0x1a65, 0x1a6c}, {0x1a73, 0x1a7c}, {0x1a7f, 0x1a7f}, {0x1aa0, 0x1aad},
  {0x1ab0, 0x1abd}, {0x1abf, 0x1ace}, {0x1b00, 0x1b03}, {0x1b05, 0x1b34}, {0x1b36, 0x1b3a}, {0x1b3c, 0x1b3c}, {0x1b42, 0x1b42}, {0x1b45, 0x1b4c},
  {0x1b5a, 0x1b7e}, {0x1b80, 0x1b81}, {0x1b83, 0x1ba0}, {0x1ba2, 0x1ba5}, {0x1ba8, 0x1ba9}, {0x1bab, 0x1baf}, {0x1bba, 0x1be6}, {0x1be8, 0x1be9},
  {0x1bed, 0x1bed}, {0x1bef, 0x1bf1}, {0x1bfc, 0x1c23}, {0x1c2c, 0x1c33}, {0x1c36, 0x1c37}, {0x1c3b, 0x1c3f}, {0x1c4d, 0x1c4f}, {0x1c5a, 0x1c88},
  {0x1c90, 0x1cba}, {0x1cbd, 0x1cc7}, {0x1cd0, 0x1ce0}, {0x1ce2, 0x1cf6}, {0x1cf8, 0x1cfa}, {0x1d00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45},
  {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fc4},
  {0x1fc6, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fdd, 0x1fef}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffe}, {0x2010, 0x2017}, {0x2020, 0x2027}, {0x2030, 0x2038},
  {0x203b, 0x2044}, {0x2047, 0x205e}, {0x2070, 0x2071}, {0x2074, 0x207c}, {0x207f, 0x208c}, {0x2090, 0x209c}, {0x20a0, 0x20c0}, {0x20d0, 0x20dc},
  {0x20e1, 0x20e1}, {0x20e5, 0x20f0}, {0x2100, 0x218b}, {0x2190, 0x2307}, {0x230c, 0x2328}, {0x232b, 0x2426}, {0x2440, 0x244a}, {0x2460, 0x2767},
  {0x2776, 0x27c4}, {0x27c7, 0x27e5}, {0x27f0, 0x2982}, {0x2999, 0x29d7}, {0x29dc, 0x29fb}, {0x29fe, 0x2b73}, {0x2b76, 0x2b95}, {0x2b97, 0x2cf3},
  {0x2cf9, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d70}, {0x2d7f, 0x2d96}, {0x2da0, 0x2da6}, {0x2da8, 0x2dae},
  {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2de0, 0x2e01}, {0x2e06, 0x2e08},
  {0x2e0b, 0x2e0b}, {0x2e0e, 0x2e1b}, {0x2e1e, 0x2e1f}, {0x2e2a, 0x2e41}, {0x2e43, 0x2e54}, {0x2e5d, 0x2e5d}, {0x2e80, 0x2e99}, {0x2e9b, 0x2ef3},
  {0x2f00, 0x2fd5}, {0x2ff0, 0x2fff}, {0x3001, 0x3007}, {0x3012, 0x3013}, {0x301c, 0x301c}, {0x3020, 0x302d}, {0x3030, 0x303f}, {0x3041, 0x3096},
  {0x3099, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x3190, 0x31e3}, {0x31ef, 0x321e}, {0x3220, 0x3400}, {0x4dbf, 0x4e00}, {0x9fff, 0xa48c},
  {0xa490, 0xa4c6}, {0xa4d0, 0xa61f}, {0xa62a, 0xa62b}, {0xa640, 0xa66f}, {0xa673, 0xa6f7}, {0xa700, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3},
  {0xa7d5, 0xa7d9}, {0xa7f2, 0xa822}, {0xa825, 0xa826}, {0xa828, 0xa82c}, {0xa830, 0xa839}, {0xa840, 0xa877}, {0xa882, 0xa8b3}, {0xa8c4, 0xa8c5},
  {0xa8ce, 0xa8cf}, {0xa8e0, 0xa8ff}, {0xa90a, 0xa951}, {0xa95f, 0xa97c}, {0xa980, 0xa982}, {0xa984, 0xa9b3}, {0xa9b6, 0xa9b9}, {0xa9bc, 0xa9bd},
  {0xa9c1, 0xa9cd}, {0xa9cf, 0xa9cf}, {0xa9de, 0xa9ef}, {0xa9fa, 0xa9fe}, {0xaa00, 0xaa2e}, {0xaa31, 0xaa32}, {0xaa35, 0xaa36}, {0xaa40, 0xaa4c},
  {0xaa5c, 0xaa7a}, {0xaa7c, 0xaa7c}, {0xaa7e, 0xaac2}, {0xaadb, 0xaaea}, {0xaaec, 0xaaed}, {0xaaf0, 0xaaf4}, {0xaaf6, 0xaaf6}, {0xab01, 0xab06},
  {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab6b}, {0xab70, 0xabe2}, {0xabe5, 0xabe5}, {0xabe8, 0xabe8},
  {0xabeb, 0xabeb}, {0xabed, 0xabed}, {0xac00, 0xac00}, {0xd7a3, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xe000, 0xe000}, {0xf8ff, 0xfa6d},
  {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44},
  {0xfb46, 0xfbc2}, {0xfbd3, 0xfd3d}, {0xfd40, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdcf, 0xfdcf}, {0xfdf0, 0xfe16}, {0xfe19, 0xfe19}, {0xfe20, 0xfe34},
  {0xfe45, 0xfe46}, {0xfe49, 0xfe52}, {0xfe54, 0xfe58}, {0xfe5f, 0xfe66}, {0xfe68, 0xfe6b}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff01, 0xff07},
  {0xff0a, 0xff0f}, {0xff1a, 0xff3a}, {0xff3c, 0xff3c}, {0xff3e, 0xff5a}, {0xff5c, 0xff5c}, {0xff5e, 0xff5e}, {0xff61, 0xff61}, {0xff64, 0xffbe},
  {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0xffe0, 0xffe6}, {0xffe8, 0xffee}, {0xfffc, 0xfffd}, {0x10000, 0x1000b},
  {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa}, {0x10100, 0x10102}, {0x10107, 0x10133},
  {0x10137, 0x1018e}, {0x10190, 0x1019c}, {0x101a0, 0x101a0}, {0x101d0, 0x101fd}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x102e0, 0x102fb}, {0x10300, 0x10323},
  {0x1032d, 0x1034a}, {0x10350, 0x1037a}, {0x10380, 0x1039d}, {0x1039f, 0x103c3}, {0x103c8, 0x103d5}, {0x10400, 0x1049d}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb},
  {0x10500, 0x10527}, {0x10530, 0x10563}, {0x1056f, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1},
  {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba},
  {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10857, 0x1089e}, {0x108a7, 0x108af},
  {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x108fb, 0x1091b}, {0x1091f, 0x1091f},
};

static TSCharacterRange sym_symbol_character_set_2[] = {
  {'!', '!'}, {'$', '&'}, {'*', '+'}, {'-', ':'}, {'<', 'Z'}, {'\\', '\\'}, {'^', '_'}, {'a', 'z'},
  {'~', '~'}, {0xa1, 0xaa}, {0xac, 0xac}, {0xae, 0xba}, {0xbc, 0x377}, {0x37a, 0x37f}, {0x384, 0x38a}, {0x38c, 0x38c},
  {0x38e, 0x3a1}, {0x3a3, 0x52f}, {0x531, 0x556}, {0x559, 0x58a}, {0x58d, 0x58f}, {0x591, 0x5c7}, {0x5d0, 0x5ea}, {0x5ef, 0x5f4},
  {0x606, 0x61b}, {0x61d, 0x6dc}, {0x6de, 0x70d}, {0x710, 0x74a}, {0x74d, 0x7b1}, {0x7c0, 0x7fa}, {0x7fd, 0x82d}, {0x830, 0x83e},
  {0x840, 0x85b}, {0x85e, 0x85e}, {0x860, 0x86a}, {0x870, 0x88e}, {0x898, 0x8e1}, {0x8e3, 0x983}, {0x985, 0x98c}, {0x98f, 0x990},
  {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bc, 0x9c4}, {0x9c7, 0x9c8}, {0x9cb, 0x9ce}, {0x9d7, 0x9d7},
  {0x9dc, 0x9dd}, {0x9df, 0x9e3}, {0x9e6, 0x9fe}, {0xa01, 0xa03}, {0xa05, 0xa0a}, {0xa0f, 0xa10}, {0xa13, 0xa28}, {0xa2a, 0xa30},
  {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa3c, 0xa3c}, {0xa3e, 0xa42}, {0xa47, 0xa48}, {0xa4b, 0xa4d}, {0xa51, 0xa51},
  {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa66, 0xa76}, {0xa81, 0xa83}, {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0},
  {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabc, 0xac5}, {0xac7, 0xac9}, {0xacb, 0xacd}, {0xad0, 0xad0}, {0xae0, 0xae3}, {0xae6, 0xaf1},
  {0xaf9, 0xaff}, {0xb01, 0xb03}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39},
  {0xb3c, 0xb44}, {0xb47, 0xb48}, {0xb4b, 0xb4d}, {0xb55, 0xb57}, {0xb5c, 0xb5d}, {0xb5f, 0xb63}, {0xb66, 0xb77}, {0xb82, 0xb83},
  {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95}, {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa},
  {0xbae, 0xbb9}, {0xbbe, 0xbc2}, {0xbc6, 0xbc8}, {0xbca, 0xbcd}, {0xbd0, 0xbd0}, {0xbd7, 0xbd7}, {0xbe6, 0xbfa}, {0xc00, 0xc0c},
  {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3c, 0xc44}, {0xc46, 0xc48}, {0xc4a, 0xc4d}, {0xc55, 0xc56}, {0xc58, 0xc5a},
  {0xc5d, 0xc5d}, {0xc60, 0xc63}, {0xc66, 0xc6f}, {0xc77, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9},
  {0xcbc, 0xcc4}, {0xcc6, 0xcc8}, {0xcca, 0xccd}, {0xcd5, 0xcd6}, {0xcdd, 0xcde}, {0xce0, 0xce3}, {0xce6, 0xcef}, {0xcf1, 0xcf3},
  {0xd00, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd44}, {0xd46, 0xd48}, {0xd4a, 0xd4f}, {0xd54, 0xd63}, {0xd66, 0xd7f}, {0xd81, 0xd83},
  {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xdca, 0xdca}, {0xdcf, 0xdd4}, {0xdd6, 0xdd6},
  {0xdd8, 0xddf}, {0xde6, 0xdef}, {0xdf2, 0xdf4}, {0xe01, 0xe3a}, {0xe3f, 0xe5b}, {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a},
  {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xec8, 0xece}, {0xed0, 0xed9}, {0xedc, 0xedf},
  {0xf00, 0xf39}, {0xf3e, 0xf47}, {0xf49, 0xf6c}, {0xf71, 0xf97}, {0xf99, 0xfbc}, {0xfbe, 0xfcc}, {0xfce, 0xfda}, {0x1000, 0x10c5},
  {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288},
  {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310},
  {0x1312, 0x1315}, {0x1318, 0x135a}, {0x135d, 0x137c}, {0x1380, 0x1399}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd}, {0x1400, 0x167f}, {0x1681, 0x169a},
  {0x16a0, 0x16f8}, {0x1700, 0x1715}, {0x171f, 0x1736}, {0x1740, 0x1753}, {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1772, 0x1773}, {0x1780, 0x17dd},
  {0x17e0, 0x17e9}, {0x17f0, 0x17f9}, {0x1800, 0x180d}, {0x180f, 0x1819}, {0x1820, 0x1878}, {0x1880, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e},
  {0x1920, 0x192b}, {0x1930, 0x193b}, {0x1940, 0x1940}, {0x1944, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x19d0, 0x19da},
  {0x19de, 0x1a1b}, {0x1a1e, 0x1a5e}, {0x1a60, 0x1a7c}, {0x1a7f, 0x1a89}, {0x1a90, 0x1a99}, {0x1aa0, 0x1aad}, {0x1ab0, 0x1ace}, {0x1b00, 0x1b4c},
  {0x1b50, 0x1b7e}, {0x1b80, 0x1bf3}, {0x1bfc, 0x1c37}, {0x1c3b, 0x1c49}, {0x1c4d, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cc7}, {0x1cd0, 0x1cfa},
  {0x1d00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d},
  {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fc4}, {0x1fc6, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fdd, 0x1fef}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffe},
  {0x2010, 0x2017}, {0x2020, 0x2027}, {0x2030, 0x2038}, {0x203b, 0x2044}, {0x2047, 0x205e}, {0x2070, 0x2071}, {0x2074, 0x207c}, {0x207f, 0x208c},
  {0x2090, 0x209c}, {0x20a0, 0x20c0}, {0x20d0, 0x20f0}, {0x2100, 0x218b}, {0x2190, 0x2307}, {0x230c, 0x2328}, {0x232b, 0x2426}, {0x2440, 0x244a},
  {0x2460, 0x2767}, {0x2776, 0x27c4}, {0x27c7, 0x27e5}, {0x27f0, 0x2982}, {0x2999, 0x29d7}, {0x29dc, 0x29fb}, {0x29fe, 0x2b73}, {0x2b76, 0x2b95},
  {0x2b97, 0x2cf3}, {0x2cf9, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d70}, {0x2d7f, 0x2d96}, {0x2da0, 0x2da6},
  {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2de0, 0x2e01},
  {0x2e06, 0x2e08}, {0x2e0b, 0x2e0b}, {0x2e0e, 0x2e1b}, {0x2e1e, 0x2e1f}, {0x2e2a, 0x2e41}, {0x2e43, 0x2e54}, {0x2e5d, 0x2e5d}, {0x2e80, 0x2e99},
  {0x2e9b, 0x2ef3}, {0x2f00, 0x2fd5}, {0x2ff0, 0x2fff}, {0x3001, 0x3007}, {0x3012, 0x3013}, {0x301c, 0x301c}, {0x3020, 0x303f}, {0x3041, 0x3096},
  {0x3099, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x3190, 0x31e3}, {0x31ef, 0x321e}, {0x3220, 0x3400}, {0x4dbf, 0x4e00}, {0x9fff, 0xa48c},
  {0xa490, 0xa4c6}, {0xa4d0, 0xa62b}, {0xa640, 0xa6f7}, {0xa700, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9}, {0xa7f2, 0xa82c},
  {0xa830, 0xa839}, {0xa840, 0xa877}, {0xa880, 0xa8c5}, {0xa8ce, 0xa8d9}, {0xa8e0, 0xa953}, {0xa95f, 0xa97c}, {0xa980, 0xa9cd}, {0xa9cf, 0xa9d9},
  {0xa9de, 0xa9fe}, {0xaa00, 0xaa36}, {0xaa40, 0xaa4d}, {0xaa50, 0xaa59}, {0xaa5c, 0xaac2}, {0xaadb, 0xaaf6}, {0xab01, 0xab06}, {0xab09, 0xab0e},
  {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab6b}, {0xab70, 0xabed}, {0xabf0, 0xabf9}, {0xac00, 0xac00}, {0xd7a3, 0xd7a3},
  {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xe000, 0xe000}, {0xf8ff, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb36},
  {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbc2}, {0xfbd3, 0xfd3d}, {0xfd40, 0xfd8f}, {0xfd92, 0xfdc7},
  {0xfdcf, 0xfdcf}, {0xfdf0, 0xfe16}, {0xfe19, 0xfe19}, {0xfe20, 0xfe34}, {0xfe45, 0xfe46}, {0xfe49, 0xfe52}, {0xfe54, 0xfe58}, {0xfe5f, 0xfe66},
  {0xfe68, 0xfe6b}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff01, 0xff07}, {0xff0a, 0xff3a}, {0xff3c, 0xff3c}, {0xff3e, 0xff5a}, {0xff5c, 0xff5c},
  {0xff5e, 0xff5e}, {0xff61, 0xff61}, {0xff64, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0xffe0, 0xffe6},
  {0xffe8, 0xffee}, {0xfffc, 0xfffd}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d},
  {0x10080, 0x100fa}, {0x10100, 0x10102}, {0x10107, 0x10133}, {0x10137, 0x1018e}, {0x10190, 0x1019c}, {0x101a0, 0x101a0}, {0x101d0, 0x101fd}, {0x10280, 0x1029c},
  {0x102a0, 0x102d0}, {0x102e0, 0x102fb}, {0x10300, 0x10323}, {0x1032d, 0x1034a}, {0x10350, 0x1037a}, {0x10380, 0x1039d}, {0x1039f, 0x103c3}, {0x103c8, 0x103d5},
  {0x10400, 0x1049d}, {0x104a0, 0x104a9}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x1056f, 0x1057a}, {0x1057c, 0x1058a},
  {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736}, {0x10740, 0x10755},
  {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838},
  {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10857, 0x1089e}, {0x108a7, 0x108af}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x108fb, 0x1091b}, {0x1091f, 0x1091f},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(231);
      ADVANCE_MAP(
        '"', 345,
        '#', 238,
        '\'', 363,
        '(', 355,
        ')', 356,
        ',', 365,
        '.', 359,
        ';', 234,
        '[', 357,
        ']', 358,
        '`', 364,
        '|', 237,
        '\n', 232,
        '\r', 232,
        ' ', 232,
      );
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(233);
      if (lookahead != 0) ADVANCE(236);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '\r', 348,
        'x', 226,
        '\n', 349,
        0x85, 349,
        0x2028, 349,
        '"', 347,
        '\\', 347,
        'a', 347,
        'b', 347,
        'f', 347,
        'n', 347,
        'r', 347,
        't', 347,
        'v', 347,
      );
      if (set_contains(sym_escape_sequence_character_set_3, 11, lookahead)) ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == '\r') ADVANCE(348);
      if (lookahead == '\n' ||
          lookahead == 0x85 ||
          lookahead == 0x2028) ADVANCE(349);
      if (set_contains(sym_escape_sequence_character_set_3, 11, lookahead)) ADVANCE(2);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '!', 90,
        '\'', 368,
        '(', 361,
        ',', 370,
        ';', 240,
        '\\', 65,
        '`', 369,
        'v', 98,
        '|', 235,
        'B', 6,
        'b', 6,
        'D', 21,
        'd', 21,
        'O', 24,
        'o', 24,
        'X', 27,
        'x', 27,
        'E', 7,
        'I', 7,
        'e', 7,
        'i', 7,
        'F', 242,
        'T', 242,
        'f', 242,
        't', 242,
      );
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(345);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead != 0) ADVANCE(346);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(238);
      if (lookahead == '|') ADVANCE(237);
      if (lookahead != 0) ADVANCE(236);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(182);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(160);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(250);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(130);
      if (lookahead == '.') ADVANCE(195);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(244);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == '|') ADVANCE(211);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '.') ADVANCE(13);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(119);
      END_STATE();
    case 11:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == '|') ADVANCE(211);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(119);
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(12);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '#') ADVANCE(14);
      if (lookahead == '/') ADVANCE(177);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(14);
      if (lookahead == '/') ADVANCE(177);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(18);
      END_STATE();
    case 19:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 20:
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == '#') ADVANCE(185);
      if (lookahead == '.') ADVANCE(195);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(244);
      END_STATE();
    case 22:
      if (lookahead == '#') ADVANCE(22);
      if (lookahead == '/') ADVANCE(190);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 23:
      if (lookahead == '#') ADVANCE(22);
      if (lookahead == '/') ADVANCE(190);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == '#') ADVANCE(183);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(275);
      END_STATE();
    case 25:
      if (lookahead == '#') ADVANCE(25);
      if (lookahead == '/') ADVANCE(224);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 26:
      if (lookahead == '#') ADVANCE(25);
      if (lookahead == '/') ADVANCE(224);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == '#') ADVANCE(184);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(287);
      END_STATE();
    case 28:
      if (lookahead == '(') ADVANCE(362);
      END_STATE();
    case 29:
      if (lookahead == '.') ADVANCE(196);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(321);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(246);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(350);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(52);
      END_STATE();
    case 32:
      if (lookahead == '.') ADVANCE(101);
      if (lookahead == '/') ADVANCE(211);
      if (lookahead == '|') ADVANCE(211);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      if (lookahead == '.') ADVANCE(53);
      END_STATE();
    case 34:
      if (lookahead == '.') ADVANCE(51);
      END_STATE();
    case 35:
      if (lookahead == '.') ADVANCE(195);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(244);
      END_STATE();
    case 36:
      if (lookahead == '.') ADVANCE(203);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(257);
      END_STATE();
    case 37:
      if (lookahead == '.') ADVANCE(203);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(257);
      END_STATE();
    case 38:
      if (lookahead == '.') ADVANCE(204);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 39:
      if (lookahead == '.') ADVANCE(205);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(258);
      END_STATE();
    case 40:
      if (lookahead == '.') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(258);
      END_STATE();
    case 41:
      if (lookahead == '.') ADVANCE(206);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 42:
      if (lookahead == '.') ADVANCE(213);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 43:
      if (lookahead == '.') ADVANCE(213);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 44:
      if (lookahead == '.') ADVANCE(214);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 45:
      if (lookahead == '.') ADVANCE(54);
      END_STATE();
    case 46:
      if (lookahead == '.') ADVANCE(55);
      END_STATE();
    case 47:
      if (lookahead == '.') ADVANCE(56);
      END_STATE();
    case 48:
      if (lookahead == '/') ADVANCE(179);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(48);
      END_STATE();
    case 49:
      if (lookahead == '/') ADVANCE(192);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(49);
      END_STATE();
    case 50:
      if (lookahead == '/') ADVANCE(227);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 51:
      if (lookahead == '0') ADVANCE(243);
      END_STATE();
    case 52:
      if (lookahead == '0') ADVANCE(313);
      END_STATE();
    case 53:
      if (lookahead == '0') ADVANCE(139);
      END_STATE();
    case 54:
      if (lookahead == '0') ADVANCE(316);
      END_STATE();
    case 55:
      if (lookahead == '0') ADVANCE(317);
      END_STATE();
    case 56:
      if (lookahead == '0') ADVANCE(318);
      END_STATE();
    case 57:
      if (lookahead == '6') ADVANCE(91);
      END_STATE();
    case 58:
      if (lookahead == '8') ADVANCE(28);
      END_STATE();
    case 59:
      if (lookahead == ';') ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 60:
      if (lookahead == ';') ADVANCE(347);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 61:
      if (lookahead == 'A') ADVANCE(131);
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 62:
      if (lookahead == 'C') ADVANCE(132);
      if (lookahead == 'c') ADVANCE(132);
      END_STATE();
    case 63:
      if (lookahead == 'I') ADVANCE(164);
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 64:
      if (lookahead == 'L') ADVANCE(153);
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 65:
      ADVANCE_MAP(
        'N', 342,
        'S', 343,
        'a', 339,
        'b', 333,
        'd', 336,
        'e', 340,
        'l', 338,
        'n', 331,
        'p', 334,
        'r', 337,
        's', 332,
        't', 335,
        'v', 341,
        'x', 344,
      );
      if (lookahead != 0) ADVANCE(330);
      END_STATE();
    case 66:
      if (lookahead == 'N') ADVANCE(132);
      if (lookahead == 'n') ADVANCE(132);
      END_STATE();
    case 67:
      if (lookahead == 'W') ADVANCE(163);
      if (lookahead == 'w') ADVANCE(64);
      END_STATE();
    case 68:
      if (lookahead == 'a') ADVANCE(71);
      END_STATE();
    case 69:
      if (lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 70:
      if (lookahead == 'a') ADVANCE(74);
      END_STATE();
    case 71:
      if (lookahead == 'b') ADVANCE(330);
      END_STATE();
    case 72:
      if (lookahead == 'c') ADVANCE(330);
      END_STATE();
    case 73:
      if (lookahead == 'c') ADVANCE(83);
      END_STATE();
    case 74:
      if (lookahead == 'c') ADVANCE(76);
      END_STATE();
    case 75:
      if (lookahead == 'd') ADVANCE(330);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(330);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(97);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 81:
      if (lookahead == 'f') ADVANCE(80);
      END_STATE();
    case 82:
      if (lookahead == 'g') ADVANCE(76);
      END_STATE();
    case 83:
      if (lookahead == 'k') ADVANCE(95);
      END_STATE();
    case 84:
      if (lookahead == 'l') ADVANCE(330);
      END_STATE();
    case 85:
      if (lookahead == 'l') ADVANCE(79);
      END_STATE();
    case 86:
      if (lookahead == 'm') ADVANCE(330);
      END_STATE();
    case 87:
      if (lookahead == 'n') ADVANCE(330);
      END_STATE();
    case 88:
      if (lookahead == 'n') ADVANCE(77);
      END_STATE();
    case 89:
      if (lookahead == 'p') ADVANCE(70);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 91:
      if (lookahead == 'r') ADVANCE(94);
      END_STATE();
    case 92:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 93:
      if (lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 94:
      if (lookahead == 's') ADVANCE(241);
      END_STATE();
    case 95:
      if (lookahead == 's') ADVANCE(89);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(99);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(76);
      END_STATE();
    case 98:
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 99:
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 100:
      if (lookahead == 'x') ADVANCE(219);
      END_STATE();
    case 101:
      if (lookahead == '|') ADVANCE(211);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      END_STATE();
    case 102:
      if (lookahead == '|') ADVANCE(211);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 103:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(160);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(250);
      END_STATE();
    case 104:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(275);
      END_STATE();
    case 105:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(287);
      END_STATE();
    case 106:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(147);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(269);
      END_STATE();
    case 107:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(286);
      END_STATE();
    case 108:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(298);
      END_STATE();
    case 109:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(174);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(269);
      END_STATE();
    case 110:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(286);
      END_STATE();
    case 111:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(148);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(306);
      END_STATE();
    case 112:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(307);
      END_STATE();
    case 113:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(308);
      END_STATE();
    case 114:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(298);
      END_STATE();
    case 115:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(309);
      END_STATE();
    case 116:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      END_STATE();
    case 117:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      END_STATE();
    case 118:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(328);
      END_STATE();
    case 119:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 120:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 121:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(320);
      END_STATE();
    case 122:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 123:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(165);
      END_STATE();
    case 124:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(131);
      END_STATE();
    case 125:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(166);
      END_STATE();
    case 126:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(167);
      END_STATE();
    case 127:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(168);
      END_STATE();
    case 128:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(170);
      END_STATE();
    case 129:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(171);
      END_STATE();
    case 130:
      ADVANCE_MAP(
        'B', 103,
        'b', 103,
        'D', 35,
        'd', 35,
        'O', 104,
        'o', 104,
        'X', 105,
        'x', 105,
      );
      END_STATE();
    case 131:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(132);
      END_STATE();
    case 132:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(330);
      END_STATE();
    case 133:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(31);
      END_STATE();
    case 134:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(33);
      END_STATE();
    case 135:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(34);
      END_STATE();
    case 136:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(45);
      END_STATE();
    case 137:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(46);
      END_STATE();
    case 138:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(47);
      END_STATE();
    case 139:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 140:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(15);
      END_STATE();
    case 141:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(141);
      END_STATE();
    case 142:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(23);
      END_STATE();
    case 143:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(143);
      END_STATE();
    case 144:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 145:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 146:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(146);
      END_STATE();
    case 147:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(269);
      END_STATE();
    case 148:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(306);
      END_STATE();
    case 149:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(286);
      END_STATE();
    case 150:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(307);
      END_STATE();
    case 151:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(298);
      END_STATE();
    case 152:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(169);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(308);
      END_STATE();
    case 153:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(164);
      END_STATE();
    case 154:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(15);
      END_STATE();
    case 155:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(48);
      END_STATE();
    case 156:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(23);
      END_STATE();
    case 157:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(49);
      END_STATE();
    case 158:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 159:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(322);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 160:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(323);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(127);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(260);
      END_STATE();
    case 161:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(324);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(280);
      END_STATE();
    case 162:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(325);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(292);
      END_STATE();
    case 163:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(153);
      END_STATE();
    case 164:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(132);
      END_STATE();
    case 165:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 166:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(33);
      END_STATE();
    case 167:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 168:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 169:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(135);
      END_STATE();
    case 170:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 171:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 172:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(163);
      END_STATE();
    case 173:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(277);
      END_STATE();
    case 174:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(269);
      END_STATE();
    case 175:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(282);
      END_STATE();
    case 176:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(271);
      END_STATE();
    case 177:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(17);
      END_STATE();
    case 178:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(326);
      END_STATE();
    case 179:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(141);
      END_STATE();
    case 180:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(279);
      END_STATE();
    case 181:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(284);
      END_STATE();
    case 182:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(103);
      END_STATE();
    case 183:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(104);
      END_STATE();
    case 184:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(105);
      END_STATE();
    case 185:
      if (lookahead == 'E' ||
          lookahead == 'I' ||
          lookahead == 'e' ||
          lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 186:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(289);
      END_STATE();
    case 187:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(286);
      END_STATE();
    case 188:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(294);
      END_STATE();
    case 189:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(272);
      END_STATE();
    case 190:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(18);
      END_STATE();
    case 191:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(327);
      END_STATE();
    case 192:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(143);
      END_STATE();
    case 193:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(291);
      END_STATE();
    case 194:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(296);
      END_STATE();
    case 195:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(248);
      END_STATE();
    case 196:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(252);
      END_STATE();
    case 197:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(254);
      END_STATE();
    case 198:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(315);
      END_STATE();
    case 199:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(309);
      END_STATE();
    case 200:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(262);
      END_STATE();
    case 201:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(314);
      END_STATE();
    case 202:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      END_STATE();
    case 203:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(265);
      END_STATE();
    case 204:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 205:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      END_STATE();
    case 206:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 207:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(273);
      END_STATE();
    case 208:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(328);
      END_STATE();
    case 209:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(320);
      END_STATE();
    case 210:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 211:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 212:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 213:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(319);
      END_STATE();
    case 214:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(101);
      END_STATE();
    case 215:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(256);
      END_STATE();
    case 216:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      END_STATE();
    case 217:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(264);
      END_STATE();
    case 218:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 219:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 220:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(299);
      END_STATE();
    case 221:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(298);
      END_STATE();
    case 222:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(302);
      END_STATE();
    case 223:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(274);
      END_STATE();
    case 224:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 225:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(329);
      END_STATE();
    case 226:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 227:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(146);
      END_STATE();
    case 228:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(301);
      END_STATE();
    case 229:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(304);
      END_STATE();
    case 230:
      if (eof) ADVANCE(231);
      ADVANCE_MAP(
        '"', 345,
        '#', 3,
        '\'', 363,
        '(', 355,
        ')', 356,
        '+', 352,
        ',', 366,
        '-', 351,
        '.', 360,
        ';', 234,
        '[', 357,
        '\\', 100,
        ']', 358,
        '`', 364,
        '\n', 232,
        '\r', 232,
        ' ', 232,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(244);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(233);
      if (('!' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(353);
      if (set_contains(sym_symbol_character_set_1, 524, lookahead)) ADVANCE(354);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(232);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(233);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym__intertoken_token1);
      if (set_contains(aux_sym__intertoken_token1_character_set_1, 10, lookahead)) ADVANCE(233);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x85 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(234);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_POUND_PIPE);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '#') ADVANCE(239);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(aux_sym_block_comment_token1);
      if (lookahead == '|') ADVANCE(235);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_PIPE_POUND);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_POUND_SEMI);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_directive);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_boolean);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_number);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '.') ADVANCE(248);
      if (lookahead == '/') ADVANCE(197);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '|') ADVANCE(198);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(244);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(245);
      if (lookahead == '.') ADVANCE(249);
      if (lookahead == '/') ADVANCE(215);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(117);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 247,
        '.', 252,
        '/', 200,
        '@', 36,
        '|', 201,
        '+', 38,
        '-', 38,
        'I', 243,
        'i', 243,
      );
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(246);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 247,
        '.', 253,
        '/', 217,
        '@', 39,
        '+', 41,
        '-', 41,
        'I', 243,
        'i', 243,
      );
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(120);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(249);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '|') ADVANCE(198);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(248);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(249);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(117);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(251);
      if (lookahead == '/') ADVANCE(173);
      if (lookahead == '@') ADVANCE(106);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(154);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(250);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(251);
      if (lookahead == '/') ADVANCE(180);
      if (lookahead == '@') ADVANCE(109);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(140);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(253);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '|') ADVANCE(201);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(252);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(253);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(120);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(255);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(254);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(255);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(255);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(256);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(259);
      if (lookahead == '.') ADVANCE(265);
      if (lookahead == '/') ADVANCE(207);
      if (lookahead == '|') ADVANCE(208);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(257);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(259);
      if (lookahead == '.') ADVANCE(267);
      if (lookahead == '/') ADVANCE(207);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(258);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(259);
      if (lookahead == '.') ADVANCE(266);
      if (lookahead == '/') ADVANCE(207);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(118);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '#', 261,
        '/', 175,
        '@', 106,
        '+', 154,
        '-', 154,
        'I', 243,
        'i', 243,
        '0', 260,
        '1', 260,
      );
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(261);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == '@') ADVANCE(109);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(140);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(263);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(262);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(263);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(263);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(264);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(266);
      if (lookahead == '|') ADVANCE(208);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(265);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(266);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(118);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(266);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(268);
      if (lookahead == '/') ADVANCE(176);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(268);
      if (lookahead == '/') ADVANCE(176);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(269);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(270);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(270);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(271);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(272);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(273);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(274);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(276);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '@') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(275);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(276);
      if (lookahead == '/') ADVANCE(193);
      if (lookahead == '@') ADVANCE(110);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(142);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(278);
      if (lookahead == '@') ADVANCE(106);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(154);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(277);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(278);
      if (lookahead == '@') ADVANCE(109);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(140);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(278);
      if (lookahead == '@') ADVANCE(109);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(140);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(279);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(281);
      if (lookahead == '/') ADVANCE(188);
      if (lookahead == '@') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(156);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(280);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(281);
      if (lookahead == '/') ADVANCE(194);
      if (lookahead == '@') ADVANCE(110);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(142);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(283);
      if (lookahead == '@') ADVANCE(106);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(154);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(282);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(283);
      if (lookahead == '@') ADVANCE(109);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(140);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(283);
      if (lookahead == '@') ADVANCE(109);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(140);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(284);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(285);
      if (lookahead == '/') ADVANCE(189);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(285);
      if (lookahead == '/') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(286);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(288);
      if (lookahead == '/') ADVANCE(220);
      if (lookahead == '@') ADVANCE(108);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(287);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(288);
      if (lookahead == '/') ADVANCE(228);
      if (lookahead == '@') ADVANCE(114);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(145);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(290);
      if (lookahead == '@') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(289);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(290);
      if (lookahead == '@') ADVANCE(110);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(142);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(290);
      if (lookahead == '@') ADVANCE(110);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(291);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(293);
      if (lookahead == '/') ADVANCE(222);
      if (lookahead == '@') ADVANCE(108);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(158);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(292);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(293);
      if (lookahead == '/') ADVANCE(229);
      if (lookahead == '@') ADVANCE(114);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(145);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(295);
      if (lookahead == '@') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(156);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(295);
      if (lookahead == '@') ADVANCE(110);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(142);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(295);
      if (lookahead == '@') ADVANCE(110);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(142);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(296);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(297);
      if (lookahead == '/') ADVANCE(223);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(297);
      if (lookahead == '/') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(300);
      if (lookahead == '@') ADVANCE(108);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(299);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(300);
      if (lookahead == '@') ADVANCE(114);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(145);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(300);
      if (lookahead == '@') ADVANCE(114);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(301);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(303);
      if (lookahead == '@') ADVANCE(108);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(158);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(302);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(303);
      if (lookahead == '@') ADVANCE(114);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(145);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '#') ADVANCE(303);
      if (lookahead == '@') ADVANCE(114);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(145);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(304);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(319);
      if (lookahead == '/') ADVANCE(208);
      if (lookahead == '|') ADVANCE(208);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(178);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(306);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(307);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '/') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(308);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '|') ADVANCE(198);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(309);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '|') ADVANCE(201);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(310);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(312);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(42);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(44);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(42);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(44);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(314);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(42);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(315);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(111);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(155);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(112);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(157);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '@') ADVANCE(113);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(159);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(208);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'L' ||
          lookahead == 'S' ||
          ('d' <= lookahead && lookahead <= 'f') ||
          lookahead == 'l' ||
          lookahead == 's') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(319);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '|') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(320);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(133);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(134);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(136);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(137);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(138);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(326);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(328);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(329);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_character);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'E') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(67);
      if (lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'P') ADVANCE(124);
      if (lookahead == 'p') ADVANCE(61);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(73);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(82);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'a') ADVANCE(71);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'i') ADVANCE(88);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'l') ADVANCE(69);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 's') ADVANCE(72);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 't') ADVANCE(68);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(172);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_character);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(124);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_character);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(344);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(346);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\n' ||
          lookahead == 0x85) ADVANCE(349);
      if (set_contains(sym_escape_sequence_character_set_2, 9, lookahead)) ADVANCE(349);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_escape_sequence);
      if ((set_contains(sym_escape_sequence_character_set_2, 9, lookahead)) &&
          lookahead != '\n' &&
          lookahead != 0x85) ADVANCE(349);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_symbol);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(196);
      if (lookahead == '>') ADVANCE(354);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(321);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(246);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '.') ADVANCE(196);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(321);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(246);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '\\') ADVANCE(100);
      if (lookahead == '!' ||
          ('$' <= lookahead && lookahead <= '&') ||
          lookahead == '*' ||
          lookahead == '+' ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(353);
      if (set_contains(sym_symbol_character_set_2, 448, lookahead)) ADVANCE(354);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_symbol);
      if (lookahead == '\\') ADVANCE(100);
      if (set_contains(sym_symbol_character_set_2, 448, lookahead)) ADVANCE(354);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_dot);
      if (lookahead == '.') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(248);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_POUND_LPAREN);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_POUNDvu8_LPAREN);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '@') ADVANCE(367);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_COMMA_AT);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_POUND_SQUOTE);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_POUND_BQUOTE);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(anon_sym_POUND_COMMA);
      if (lookahead == '@') ADVANCE(371);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(anon_sym_POUND_COMMA_AT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 230},
  [2] = {.lex_state = 230},
  [3] = {.lex_state = 230},
  [4] = {.lex_state = 230},
  [5] = {.lex_state = 230},
  [6] = {.lex_state = 230},
  [7] = {.lex_state = 230},
  [8] = {.lex_state = 230},
  [9] = {.lex_state = 230},
  [10] = {.lex_state = 230},
  [11] = {.lex_state = 230},
  [12] = {.lex_state = 230},
  [13] = {.lex_state = 230},
  [14] = {.lex_state = 230},
  [15] = {.lex_state = 230},
  [16] = {.lex_state = 230},
  [17] = {.lex_state = 230},
  [18] = {.lex_state = 230},
  [19] = {.lex_state = 230},
  [20] = {.lex_state = 230},
  [21] = {.lex_state = 230},
  [22] = {.lex_state = 230},
  [23] = {.lex_state = 230},
  [24] = {.lex_state = 230},
  [25] = {.lex_state = 230},
  [26] = {.lex_state = 230},
  [27] = {.lex_state = 230},
  [28] = {.lex_state = 230},
  [29] = {.lex_state = 230},
  [30] = {.lex_state = 230},
  [31] = {.lex_state = 230},
  [32] = {.lex_state = 230},
  [33] = {.lex_state = 230},
  [34] = {.lex_state = 230},
  [35] = {.lex_state = 230},
  [36] = {.lex_state = 230},
  [37] = {.lex_state = 230},
  [38] = {.lex_state = 230},
  [39] = {.lex_state = 230},
  [40] = {.lex_state = 230},
  [41] = {.lex_state = 230},
  [42] = {.lex_state = 230},
  [43] = {.lex_state = 230},
  [44] = {.lex_state = 230},
  [45] = {.lex_state = 230},
  [46] = {.lex_state = 230},
  [47] = {.lex_state = 230},
  [48] = {.lex_state = 230},
  [49] = {.lex_state = 230},
  [50] = {.lex_state = 230},
  [51] = {.lex_state = 230},
  [52] = {.lex_state = 230},
  [53] = {.lex_state = 230},
  [54] = {.lex_state = 230},
  [55] = {.lex_state = 230},
  [56] = {.lex_state = 230},
  [57] = {.lex_state = 230},
  [58] = {.lex_state = 230},
  [59] = {.lex_state = 230},
  [60] = {.lex_state = 230},
  [61] = {.lex_state = 5},
  [62] = {.lex_state = 5},
  [63] = {.lex_state = 5},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 5},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 4},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 5},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 0},
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
  },
  [1] = {
    [sym_program] = STATE(71),
    [sym__token] = STATE(9),
    [sym__intertoken] = STATE(9),
    [sym__datum] = STATE(9),
    [sym_block_comment] = STATE(9),
    [sym_sexp_comment] = STATE(9),
    [sym_string] = STATE(9),
    [sym_list] = STATE(9),
    [sym_vector] = STATE(9),
    [sym_byte_vector] = STATE(9),
    [sym_quote] = STATE(9),
    [sym_quasiquote] = STATE(9),
    [sym_unquote] = STATE(9),
    [sym_unquote_splicing] = STATE(9),
    [sym_syntax_quote] = STATE(9),
    [sym_quasisyntax] = STATE(9),
    [sym_unsyntax] = STATE(9),
    [sym_unsyntax_splicing] = STATE(9),
    [aux_sym_program_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__intertoken_token1] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(5),
    [sym_boolean] = ACTIONS(5),
    [sym_number] = ACTIONS(5),
    [sym_character] = ACTIONS(5),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(13),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
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
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(39),
    [sym_comment] = ACTIONS(39),
    [anon_sym_POUND_PIPE] = ACTIONS(42),
    [anon_sym_POUND_SEMI] = ACTIONS(45),
    [sym_directive] = ACTIONS(39),
    [sym_boolean] = ACTIONS(39),
    [sym_number] = ACTIONS(39),
    [sym_character] = ACTIONS(39),
    [anon_sym_DQUOTE] = ACTIONS(48),
    [sym_symbol] = ACTIONS(51),
    [anon_sym_LPAREN] = ACTIONS(54),
    [anon_sym_RPAREN] = ACTIONS(57),
    [anon_sym_LBRACK] = ACTIONS(59),
    [anon_sym_RBRACK] = ACTIONS(57),
    [sym_dot] = ACTIONS(51),
    [anon_sym_POUND_LPAREN] = ACTIONS(62),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(65),
    [anon_sym_SQUOTE] = ACTIONS(68),
    [anon_sym_BQUOTE] = ACTIONS(71),
    [anon_sym_COMMA] = ACTIONS(74),
    [anon_sym_COMMA_AT] = ACTIONS(77),
    [anon_sym_POUND_SQUOTE] = ACTIONS(80),
    [anon_sym_POUND_BQUOTE] = ACTIONS(83),
    [anon_sym_POUND_COMMA] = ACTIONS(86),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(89),
  },
  [3] = {
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
    [aux_sym_list_repeat1] = STATE(6),
    [aux_sym__intertoken_token1] = ACTIONS(92),
    [sym_comment] = ACTIONS(92),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(92),
    [sym_boolean] = ACTIONS(92),
    [sym_number] = ACTIONS(92),
    [sym_character] = ACTIONS(92),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(94),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(96),
    [anon_sym_LBRACK] = ACTIONS(17),
    [sym_dot] = ACTIONS(94),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [4] = {
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
    [aux_sym_list_repeat1] = STATE(7),
    [aux_sym__intertoken_token1] = ACTIONS(98),
    [sym_comment] = ACTIONS(98),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(98),
    [sym_boolean] = ACTIONS(98),
    [sym_number] = ACTIONS(98),
    [sym_character] = ACTIONS(98),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(100),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(96),
    [sym_dot] = ACTIONS(100),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [5] = {
    [sym__token] = STATE(5),
    [sym__intertoken] = STATE(5),
    [sym__datum] = STATE(5),
    [sym_block_comment] = STATE(5),
    [sym_sexp_comment] = STATE(5),
    [sym_string] = STATE(5),
    [sym_list] = STATE(5),
    [sym_vector] = STATE(5),
    [sym_byte_vector] = STATE(5),
    [sym_quote] = STATE(5),
    [sym_quasiquote] = STATE(5),
    [sym_unquote] = STATE(5),
    [sym_unquote_splicing] = STATE(5),
    [sym_syntax_quote] = STATE(5),
    [sym_quasisyntax] = STATE(5),
    [sym_unsyntax] = STATE(5),
    [sym_unsyntax_splicing] = STATE(5),
    [aux_sym_program_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(102),
    [aux_sym__intertoken_token1] = ACTIONS(104),
    [sym_comment] = ACTIONS(104),
    [anon_sym_POUND_PIPE] = ACTIONS(107),
    [anon_sym_POUND_SEMI] = ACTIONS(110),
    [sym_directive] = ACTIONS(104),
    [sym_boolean] = ACTIONS(104),
    [sym_number] = ACTIONS(104),
    [sym_character] = ACTIONS(104),
    [anon_sym_DQUOTE] = ACTIONS(113),
    [sym_symbol] = ACTIONS(116),
    [anon_sym_LPAREN] = ACTIONS(119),
    [anon_sym_RPAREN] = ACTIONS(102),
    [anon_sym_LBRACK] = ACTIONS(122),
    [anon_sym_POUND_LPAREN] = ACTIONS(125),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(128),
    [anon_sym_SQUOTE] = ACTIONS(131),
    [anon_sym_BQUOTE] = ACTIONS(134),
    [anon_sym_COMMA] = ACTIONS(137),
    [anon_sym_COMMA_AT] = ACTIONS(140),
    [anon_sym_POUND_SQUOTE] = ACTIONS(143),
    [anon_sym_POUND_BQUOTE] = ACTIONS(146),
    [anon_sym_POUND_COMMA] = ACTIONS(149),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(152),
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
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(155),
    [sym_comment] = ACTIONS(155),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(155),
    [sym_boolean] = ACTIONS(155),
    [sym_number] = ACTIONS(155),
    [sym_character] = ACTIONS(155),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(157),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(159),
    [anon_sym_LBRACK] = ACTIONS(17),
    [sym_dot] = ACTIONS(157),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [7] = {
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
    [aux_sym_list_repeat1] = STATE(2),
    [aux_sym__intertoken_token1] = ACTIONS(155),
    [sym_comment] = ACTIONS(155),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(155),
    [sym_boolean] = ACTIONS(155),
    [sym_number] = ACTIONS(155),
    [sym_character] = ACTIONS(155),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(157),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_RBRACK] = ACTIONS(159),
    [sym_dot] = ACTIONS(157),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [8] = {
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
    [aux_sym_program_repeat1] = STATE(10),
    [aux_sym__intertoken_token1] = ACTIONS(161),
    [sym_comment] = ACTIONS(161),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(161),
    [sym_boolean] = ACTIONS(161),
    [sym_number] = ACTIONS(161),
    [sym_character] = ACTIONS(161),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(163),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(165),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [9] = {
    [sym__token] = STATE(5),
    [sym__intertoken] = STATE(5),
    [sym__datum] = STATE(5),
    [sym_block_comment] = STATE(5),
    [sym_sexp_comment] = STATE(5),
    [sym_string] = STATE(5),
    [sym_list] = STATE(5),
    [sym_vector] = STATE(5),
    [sym_byte_vector] = STATE(5),
    [sym_quote] = STATE(5),
    [sym_quasiquote] = STATE(5),
    [sym_unquote] = STATE(5),
    [sym_unquote_splicing] = STATE(5),
    [sym_syntax_quote] = STATE(5),
    [sym_quasisyntax] = STATE(5),
    [sym_unsyntax] = STATE(5),
    [sym_unsyntax_splicing] = STATE(5),
    [aux_sym_program_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(167),
    [aux_sym__intertoken_token1] = ACTIONS(169),
    [sym_comment] = ACTIONS(169),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(169),
    [sym_boolean] = ACTIONS(169),
    [sym_number] = ACTIONS(169),
    [sym_character] = ACTIONS(169),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(171),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [10] = {
    [sym__token] = STATE(5),
    [sym__intertoken] = STATE(5),
    [sym__datum] = STATE(5),
    [sym_block_comment] = STATE(5),
    [sym_sexp_comment] = STATE(5),
    [sym_string] = STATE(5),
    [sym_list] = STATE(5),
    [sym_vector] = STATE(5),
    [sym_byte_vector] = STATE(5),
    [sym_quote] = STATE(5),
    [sym_quasiquote] = STATE(5),
    [sym_unquote] = STATE(5),
    [sym_unquote_splicing] = STATE(5),
    [sym_syntax_quote] = STATE(5),
    [sym_quasisyntax] = STATE(5),
    [sym_unsyntax] = STATE(5),
    [sym_unsyntax_splicing] = STATE(5),
    [aux_sym_program_repeat1] = STATE(5),
    [aux_sym__intertoken_token1] = ACTIONS(169),
    [sym_comment] = ACTIONS(169),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(169),
    [sym_boolean] = ACTIONS(169),
    [sym_number] = ACTIONS(169),
    [sym_character] = ACTIONS(169),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(171),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(173),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [11] = {
    [sym__intertoken] = STATE(28),
    [sym__datum] = STATE(35),
    [sym_block_comment] = STATE(28),
    [sym_sexp_comment] = STATE(28),
    [sym_string] = STATE(35),
    [sym_list] = STATE(35),
    [sym_vector] = STATE(35),
    [sym_byte_vector] = STATE(35),
    [sym_quote] = STATE(35),
    [sym_quasiquote] = STATE(35),
    [sym_unquote] = STATE(35),
    [sym_unquote_splicing] = STATE(35),
    [sym_syntax_quote] = STATE(35),
    [sym_quasisyntax] = STATE(35),
    [sym_unsyntax] = STATE(35),
    [sym_unsyntax_splicing] = STATE(35),
    [aux_sym_sexp_comment_repeat1] = STATE(28),
    [aux_sym__intertoken_token1] = ACTIONS(175),
    [sym_comment] = ACTIONS(175),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(175),
    [sym_boolean] = ACTIONS(177),
    [sym_number] = ACTIONS(177),
    [sym_character] = ACTIONS(177),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(179),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [12] = {
    [sym__intertoken] = STATE(20),
    [sym__datum] = STATE(31),
    [sym_block_comment] = STATE(20),
    [sym_sexp_comment] = STATE(20),
    [sym_string] = STATE(31),
    [sym_list] = STATE(31),
    [sym_vector] = STATE(31),
    [sym_byte_vector] = STATE(31),
    [sym_quote] = STATE(31),
    [sym_quasiquote] = STATE(31),
    [sym_unquote] = STATE(31),
    [sym_unquote_splicing] = STATE(31),
    [sym_syntax_quote] = STATE(31),
    [sym_quasisyntax] = STATE(31),
    [sym_unsyntax] = STATE(31),
    [sym_unsyntax_splicing] = STATE(31),
    [aux_sym_sexp_comment_repeat1] = STATE(20),
    [aux_sym__intertoken_token1] = ACTIONS(181),
    [sym_comment] = ACTIONS(181),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(181),
    [sym_boolean] = ACTIONS(183),
    [sym_number] = ACTIONS(183),
    [sym_character] = ACTIONS(183),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(185),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [13] = {
    [sym__intertoken] = STATE(21),
    [sym__datum] = STATE(33),
    [sym_block_comment] = STATE(21),
    [sym_sexp_comment] = STATE(21),
    [sym_string] = STATE(33),
    [sym_list] = STATE(33),
    [sym_vector] = STATE(33),
    [sym_byte_vector] = STATE(33),
    [sym_quote] = STATE(33),
    [sym_quasiquote] = STATE(33),
    [sym_unquote] = STATE(33),
    [sym_unquote_splicing] = STATE(33),
    [sym_syntax_quote] = STATE(33),
    [sym_quasisyntax] = STATE(33),
    [sym_unsyntax] = STATE(33),
    [sym_unsyntax_splicing] = STATE(33),
    [aux_sym_sexp_comment_repeat1] = STATE(21),
    [aux_sym__intertoken_token1] = ACTIONS(187),
    [sym_comment] = ACTIONS(187),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(187),
    [sym_boolean] = ACTIONS(189),
    [sym_number] = ACTIONS(189),
    [sym_character] = ACTIONS(189),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(191),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [14] = {
    [sym__intertoken] = STATE(22),
    [sym__datum] = STATE(34),
    [sym_block_comment] = STATE(22),
    [sym_sexp_comment] = STATE(22),
    [sym_string] = STATE(34),
    [sym_list] = STATE(34),
    [sym_vector] = STATE(34),
    [sym_byte_vector] = STATE(34),
    [sym_quote] = STATE(34),
    [sym_quasiquote] = STATE(34),
    [sym_unquote] = STATE(34),
    [sym_unquote_splicing] = STATE(34),
    [sym_syntax_quote] = STATE(34),
    [sym_quasisyntax] = STATE(34),
    [sym_unsyntax] = STATE(34),
    [sym_unsyntax_splicing] = STATE(34),
    [aux_sym_sexp_comment_repeat1] = STATE(22),
    [aux_sym__intertoken_token1] = ACTIONS(193),
    [sym_comment] = ACTIONS(193),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(193),
    [sym_boolean] = ACTIONS(195),
    [sym_number] = ACTIONS(195),
    [sym_character] = ACTIONS(195),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(197),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [15] = {
    [sym__intertoken] = STATE(23),
    [sym__datum] = STATE(36),
    [sym_block_comment] = STATE(23),
    [sym_sexp_comment] = STATE(23),
    [sym_string] = STATE(36),
    [sym_list] = STATE(36),
    [sym_vector] = STATE(36),
    [sym_byte_vector] = STATE(36),
    [sym_quote] = STATE(36),
    [sym_quasiquote] = STATE(36),
    [sym_unquote] = STATE(36),
    [sym_unquote_splicing] = STATE(36),
    [sym_syntax_quote] = STATE(36),
    [sym_quasisyntax] = STATE(36),
    [sym_unsyntax] = STATE(36),
    [sym_unsyntax_splicing] = STATE(36),
    [aux_sym_sexp_comment_repeat1] = STATE(23),
    [aux_sym__intertoken_token1] = ACTIONS(199),
    [sym_comment] = ACTIONS(199),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(199),
    [sym_boolean] = ACTIONS(201),
    [sym_number] = ACTIONS(201),
    [sym_character] = ACTIONS(201),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(203),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [16] = {
    [sym__intertoken] = STATE(24),
    [sym__datum] = STATE(37),
    [sym_block_comment] = STATE(24),
    [sym_sexp_comment] = STATE(24),
    [sym_string] = STATE(37),
    [sym_list] = STATE(37),
    [sym_vector] = STATE(37),
    [sym_byte_vector] = STATE(37),
    [sym_quote] = STATE(37),
    [sym_quasiquote] = STATE(37),
    [sym_unquote] = STATE(37),
    [sym_unquote_splicing] = STATE(37),
    [sym_syntax_quote] = STATE(37),
    [sym_quasisyntax] = STATE(37),
    [sym_unsyntax] = STATE(37),
    [sym_unsyntax_splicing] = STATE(37),
    [aux_sym_sexp_comment_repeat1] = STATE(24),
    [aux_sym__intertoken_token1] = ACTIONS(205),
    [sym_comment] = ACTIONS(205),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(205),
    [sym_boolean] = ACTIONS(207),
    [sym_number] = ACTIONS(207),
    [sym_character] = ACTIONS(207),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(209),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [17] = {
    [sym__intertoken] = STATE(25),
    [sym__datum] = STATE(39),
    [sym_block_comment] = STATE(25),
    [sym_sexp_comment] = STATE(25),
    [sym_string] = STATE(39),
    [sym_list] = STATE(39),
    [sym_vector] = STATE(39),
    [sym_byte_vector] = STATE(39),
    [sym_quote] = STATE(39),
    [sym_quasiquote] = STATE(39),
    [sym_unquote] = STATE(39),
    [sym_unquote_splicing] = STATE(39),
    [sym_syntax_quote] = STATE(39),
    [sym_quasisyntax] = STATE(39),
    [sym_unsyntax] = STATE(39),
    [sym_unsyntax_splicing] = STATE(39),
    [aux_sym_sexp_comment_repeat1] = STATE(25),
    [aux_sym__intertoken_token1] = ACTIONS(211),
    [sym_comment] = ACTIONS(211),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(211),
    [sym_boolean] = ACTIONS(213),
    [sym_number] = ACTIONS(213),
    [sym_character] = ACTIONS(213),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(215),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [18] = {
    [sym__intertoken] = STATE(26),
    [sym__datum] = STATE(40),
    [sym_block_comment] = STATE(26),
    [sym_sexp_comment] = STATE(26),
    [sym_string] = STATE(40),
    [sym_list] = STATE(40),
    [sym_vector] = STATE(40),
    [sym_byte_vector] = STATE(40),
    [sym_quote] = STATE(40),
    [sym_quasiquote] = STATE(40),
    [sym_unquote] = STATE(40),
    [sym_unquote_splicing] = STATE(40),
    [sym_syntax_quote] = STATE(40),
    [sym_quasisyntax] = STATE(40),
    [sym_unsyntax] = STATE(40),
    [sym_unsyntax_splicing] = STATE(40),
    [aux_sym_sexp_comment_repeat1] = STATE(26),
    [aux_sym__intertoken_token1] = ACTIONS(217),
    [sym_comment] = ACTIONS(217),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(217),
    [sym_boolean] = ACTIONS(219),
    [sym_number] = ACTIONS(219),
    [sym_character] = ACTIONS(219),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(221),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [19] = {
    [sym__intertoken] = STATE(27),
    [sym__datum] = STATE(42),
    [sym_block_comment] = STATE(27),
    [sym_sexp_comment] = STATE(27),
    [sym_string] = STATE(42),
    [sym_list] = STATE(42),
    [sym_vector] = STATE(42),
    [sym_byte_vector] = STATE(42),
    [sym_quote] = STATE(42),
    [sym_quasiquote] = STATE(42),
    [sym_unquote] = STATE(42),
    [sym_unquote_splicing] = STATE(42),
    [sym_syntax_quote] = STATE(42),
    [sym_quasisyntax] = STATE(42),
    [sym_unsyntax] = STATE(42),
    [sym_unsyntax_splicing] = STATE(42),
    [aux_sym_sexp_comment_repeat1] = STATE(27),
    [aux_sym__intertoken_token1] = ACTIONS(223),
    [sym_comment] = ACTIONS(223),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(223),
    [sym_boolean] = ACTIONS(225),
    [sym_number] = ACTIONS(225),
    [sym_character] = ACTIONS(225),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(227),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [20] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(51),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(51),
    [sym_list] = STATE(51),
    [sym_vector] = STATE(51),
    [sym_byte_vector] = STATE(51),
    [sym_quote] = STATE(51),
    [sym_quasiquote] = STATE(51),
    [sym_unquote] = STATE(51),
    [sym_unquote_splicing] = STATE(51),
    [sym_syntax_quote] = STATE(51),
    [sym_quasisyntax] = STATE(51),
    [sym_unsyntax] = STATE(51),
    [sym_unsyntax_splicing] = STATE(51),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(231),
    [sym_number] = ACTIONS(231),
    [sym_character] = ACTIONS(231),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(233),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [21] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(52),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(52),
    [sym_list] = STATE(52),
    [sym_vector] = STATE(52),
    [sym_byte_vector] = STATE(52),
    [sym_quote] = STATE(52),
    [sym_quasiquote] = STATE(52),
    [sym_unquote] = STATE(52),
    [sym_unquote_splicing] = STATE(52),
    [sym_syntax_quote] = STATE(52),
    [sym_quasisyntax] = STATE(52),
    [sym_unsyntax] = STATE(52),
    [sym_unsyntax_splicing] = STATE(52),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(235),
    [sym_number] = ACTIONS(235),
    [sym_character] = ACTIONS(235),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(237),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [22] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(53),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(53),
    [sym_list] = STATE(53),
    [sym_vector] = STATE(53),
    [sym_byte_vector] = STATE(53),
    [sym_quote] = STATE(53),
    [sym_quasiquote] = STATE(53),
    [sym_unquote] = STATE(53),
    [sym_unquote_splicing] = STATE(53),
    [sym_syntax_quote] = STATE(53),
    [sym_quasisyntax] = STATE(53),
    [sym_unsyntax] = STATE(53),
    [sym_unsyntax_splicing] = STATE(53),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(239),
    [sym_number] = ACTIONS(239),
    [sym_character] = ACTIONS(239),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(241),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [23] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(29),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(29),
    [sym_list] = STATE(29),
    [sym_vector] = STATE(29),
    [sym_byte_vector] = STATE(29),
    [sym_quote] = STATE(29),
    [sym_quasiquote] = STATE(29),
    [sym_unquote] = STATE(29),
    [sym_unquote_splicing] = STATE(29),
    [sym_syntax_quote] = STATE(29),
    [sym_quasisyntax] = STATE(29),
    [sym_unsyntax] = STATE(29),
    [sym_unsyntax_splicing] = STATE(29),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(243),
    [sym_number] = ACTIONS(243),
    [sym_character] = ACTIONS(243),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(245),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [24] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(54),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(54),
    [sym_list] = STATE(54),
    [sym_vector] = STATE(54),
    [sym_byte_vector] = STATE(54),
    [sym_quote] = STATE(54),
    [sym_quasiquote] = STATE(54),
    [sym_unquote] = STATE(54),
    [sym_unquote_splicing] = STATE(54),
    [sym_syntax_quote] = STATE(54),
    [sym_quasisyntax] = STATE(54),
    [sym_unsyntax] = STATE(54),
    [sym_unsyntax_splicing] = STATE(54),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(247),
    [sym_number] = ACTIONS(247),
    [sym_character] = ACTIONS(247),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(249),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [25] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(55),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(55),
    [sym_list] = STATE(55),
    [sym_vector] = STATE(55),
    [sym_byte_vector] = STATE(55),
    [sym_quote] = STATE(55),
    [sym_quasiquote] = STATE(55),
    [sym_unquote] = STATE(55),
    [sym_unquote_splicing] = STATE(55),
    [sym_syntax_quote] = STATE(55),
    [sym_quasisyntax] = STATE(55),
    [sym_unsyntax] = STATE(55),
    [sym_unsyntax_splicing] = STATE(55),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(251),
    [sym_number] = ACTIONS(251),
    [sym_character] = ACTIONS(251),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(253),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [26] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(56),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
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
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(255),
    [sym_number] = ACTIONS(255),
    [sym_character] = ACTIONS(255),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(257),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [27] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(30),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(30),
    [sym_list] = STATE(30),
    [sym_vector] = STATE(30),
    [sym_byte_vector] = STATE(30),
    [sym_quote] = STATE(30),
    [sym_quasiquote] = STATE(30),
    [sym_unquote] = STATE(30),
    [sym_unquote_splicing] = STATE(30),
    [sym_syntax_quote] = STATE(30),
    [sym_quasisyntax] = STATE(30),
    [sym_unsyntax] = STATE(30),
    [sym_unsyntax_splicing] = STATE(30),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(259),
    [sym_number] = ACTIONS(259),
    [sym_character] = ACTIONS(259),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(261),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
  [28] = {
    [sym__intertoken] = STATE(45),
    [sym__datum] = STATE(44),
    [sym_block_comment] = STATE(45),
    [sym_sexp_comment] = STATE(45),
    [sym_string] = STATE(44),
    [sym_list] = STATE(44),
    [sym_vector] = STATE(44),
    [sym_byte_vector] = STATE(44),
    [sym_quote] = STATE(44),
    [sym_quasiquote] = STATE(44),
    [sym_unquote] = STATE(44),
    [sym_unquote_splicing] = STATE(44),
    [sym_syntax_quote] = STATE(44),
    [sym_quasisyntax] = STATE(44),
    [sym_unsyntax] = STATE(44),
    [sym_unsyntax_splicing] = STATE(44),
    [aux_sym_sexp_comment_repeat1] = STATE(45),
    [aux_sym__intertoken_token1] = ACTIONS(229),
    [sym_comment] = ACTIONS(229),
    [anon_sym_POUND_PIPE] = ACTIONS(7),
    [anon_sym_POUND_SEMI] = ACTIONS(9),
    [sym_directive] = ACTIONS(229),
    [sym_boolean] = ACTIONS(263),
    [sym_number] = ACTIONS(263),
    [sym_character] = ACTIONS(263),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [sym_symbol] = ACTIONS(265),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_LBRACK] = ACTIONS(17),
    [anon_sym_POUND_LPAREN] = ACTIONS(19),
    [anon_sym_POUNDvu8_LPAREN] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_COMMA_AT] = ACTIONS(29),
    [anon_sym_POUND_SQUOTE] = ACTIONS(31),
    [anon_sym_POUND_BQUOTE] = ACTIONS(33),
    [anon_sym_POUND_COMMA] = ACTIONS(35),
    [anon_sym_POUND_COMMA_AT] = ACTIONS(37),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(269), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(267), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [31] = 2,
    ACTIONS(273), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(271), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [62] = 2,
    ACTIONS(277), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(275), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [93] = 2,
    ACTIONS(281), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(279), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [124] = 2,
    ACTIONS(285), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(283), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [155] = 2,
    ACTIONS(289), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(287), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [186] = 2,
    ACTIONS(293), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(291), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [217] = 2,
    ACTIONS(297), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(295), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [248] = 2,
    ACTIONS(301), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(299), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [279] = 2,
    ACTIONS(305), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(303), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [310] = 2,
    ACTIONS(309), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(307), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [341] = 2,
    ACTIONS(313), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(311), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [372] = 2,
    ACTIONS(317), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(315), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [403] = 2,
    ACTIONS(321), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(319), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [434] = 2,
    ACTIONS(325), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(323), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [465] = 2,
    ACTIONS(329), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(327), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [496] = 6,
    ACTIONS(334), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(337), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(331), 3,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
    ACTIONS(342), 3,
      sym_symbol,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    STATE(45), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_sexp_comment_repeat1,
    ACTIONS(340), 14,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [535] = 2,
    ACTIONS(346), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(344), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [566] = 2,
    ACTIONS(350), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(348), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [597] = 2,
    ACTIONS(354), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(352), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [628] = 2,
    ACTIONS(358), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(356), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [659] = 2,
    ACTIONS(362), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(360), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [690] = 2,
    ACTIONS(366), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(364), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [721] = 2,
    ACTIONS(370), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(368), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [752] = 2,
    ACTIONS(374), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(372), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [783] = 2,
    ACTIONS(378), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(376), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [814] = 2,
    ACTIONS(382), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(380), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [845] = 2,
    ACTIONS(386), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(384), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [876] = 2,
    ACTIONS(390), 4,
      sym_symbol,
      sym_dot,
      anon_sym_COMMA,
      anon_sym_POUND_COMMA,
    ACTIONS(388), 22,
      ts_builtin_sym_end,
      aux_sym__intertoken_token1,
      sym_comment,
      anon_sym_POUND_PIPE,
      anon_sym_POUND_SEMI,
      sym_directive,
      sym_boolean,
      sym_number,
      sym_character,
      anon_sym_DQUOTE,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_POUND_LPAREN,
      anon_sym_POUNDvu8_LPAREN,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA_AT,
      anon_sym_POUND_SQUOTE,
      anon_sym_POUND_BQUOTE,
      anon_sym_POUND_COMMA_AT,
  [907] = 5,
    ACTIONS(7), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(9), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(394), 1,
      anon_sym_RPAREN,
    ACTIONS(392), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(59), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [929] = 5,
    ACTIONS(399), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(402), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(405), 1,
      anon_sym_RPAREN,
    ACTIONS(396), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(59), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [951] = 5,
    ACTIONS(7), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(9), 1,
      anon_sym_POUND_SEMI,
    ACTIONS(409), 1,
      anon_sym_RPAREN,
    ACTIONS(407), 4,
      aux_sym__intertoken_token1,
      sym_comment,
      sym_directive,
      sym_number,
    STATE(58), 4,
      sym__intertoken,
      sym_block_comment,
      sym_sexp_comment,
      aux_sym_byte_vector_repeat1,
  [973] = 4,
    ACTIONS(411), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(413), 1,
      aux_sym_block_comment_token1,
    ACTIONS(415), 1,
      anon_sym_PIPE_POUND,
    STATE(63), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [987] = 4,
    ACTIONS(417), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(420), 1,
      aux_sym_block_comment_token1,
    ACTIONS(423), 1,
      anon_sym_PIPE_POUND,
    STATE(62), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1001] = 4,
    ACTIONS(411), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(425), 1,
      aux_sym_block_comment_token1,
    ACTIONS(427), 1,
      anon_sym_PIPE_POUND,
    STATE(62), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1015] = 4,
    ACTIONS(411), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(429), 1,
      aux_sym_block_comment_token1,
    ACTIONS(431), 1,
      anon_sym_PIPE_POUND,
    STATE(65), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1029] = 4,
    ACTIONS(411), 1,
      anon_sym_POUND_PIPE,
    ACTIONS(425), 1,
      aux_sym_block_comment_token1,
    ACTIONS(433), 1,
      anon_sym_PIPE_POUND,
    STATE(62), 2,
      sym_block_comment,
      aux_sym_block_comment_repeat1,
  [1043] = 3,
    ACTIONS(435), 1,
      anon_sym_DQUOTE,
    STATE(66), 1,
      aux_sym_string_repeat1,
    ACTIONS(437), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1054] = 3,
    ACTIONS(440), 1,
      anon_sym_DQUOTE,
    STATE(68), 1,
      aux_sym_string_repeat1,
    ACTIONS(442), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1065] = 3,
    ACTIONS(444), 1,
      anon_sym_DQUOTE,
    STATE(66), 1,
      aux_sym_string_repeat1,
    ACTIONS(446), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1076] = 2,
    ACTIONS(325), 1,
      aux_sym_block_comment_token1,
    ACTIONS(323), 2,
      anon_sym_POUND_PIPE,
      anon_sym_PIPE_POUND,
  [1084] = 2,
    ACTIONS(281), 1,
      aux_sym_block_comment_token1,
    ACTIONS(279), 2,
      anon_sym_POUND_PIPE,
      anon_sym_PIPE_POUND,
  [1092] = 1,
    ACTIONS(448), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(29)] = 0,
  [SMALL_STATE(30)] = 31,
  [SMALL_STATE(31)] = 62,
  [SMALL_STATE(32)] = 93,
  [SMALL_STATE(33)] = 124,
  [SMALL_STATE(34)] = 155,
  [SMALL_STATE(35)] = 186,
  [SMALL_STATE(36)] = 217,
  [SMALL_STATE(37)] = 248,
  [SMALL_STATE(38)] = 279,
  [SMALL_STATE(39)] = 310,
  [SMALL_STATE(40)] = 341,
  [SMALL_STATE(41)] = 372,
  [SMALL_STATE(42)] = 403,
  [SMALL_STATE(43)] = 434,
  [SMALL_STATE(44)] = 465,
  [SMALL_STATE(45)] = 496,
  [SMALL_STATE(46)] = 535,
  [SMALL_STATE(47)] = 566,
  [SMALL_STATE(48)] = 597,
  [SMALL_STATE(49)] = 628,
  [SMALL_STATE(50)] = 659,
  [SMALL_STATE(51)] = 690,
  [SMALL_STATE(52)] = 721,
  [SMALL_STATE(53)] = 752,
  [SMALL_STATE(54)] = 783,
  [SMALL_STATE(55)] = 814,
  [SMALL_STATE(56)] = 845,
  [SMALL_STATE(57)] = 876,
  [SMALL_STATE(58)] = 907,
  [SMALL_STATE(59)] = 929,
  [SMALL_STATE(60)] = 951,
  [SMALL_STATE(61)] = 973,
  [SMALL_STATE(62)] = 987,
  [SMALL_STATE(63)] = 1001,
  [SMALL_STATE(64)] = 1015,
  [SMALL_STATE(65)] = 1029,
  [SMALL_STATE(66)] = 1043,
  [SMALL_STATE(67)] = 1054,
  [SMALL_STATE(68)] = 1065,
  [SMALL_STATE(69)] = 1076,
  [SMALL_STATE(70)] = 1084,
  [SMALL_STATE(71)] = 1092,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [116] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [137] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [143] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [146] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [149] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [171] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [257] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 3, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax_splicing, 3, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax_splicing, 3, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 2, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 2, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 2, 0, 0),
  [281] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 2, 0, 0),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 2, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 2, 0, 0),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sexp_comment, 2, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sexp_comment, 2, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote_splicing, 2, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_syntax_quote, 2, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_syntax_quote, 2, 0, 0),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasisyntax, 2, 0, 0),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasisyntax, 2, 0, 0),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax, 2, 0, 0),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax, 2, 0, 0),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2, 0, 0),
  [317] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 2, 0, 0),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax_splicing, 2, 0, 0),
  [321] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax_splicing, 2, 0, 0),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_comment, 3, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_comment, 3, 0, 0),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sexp_comment, 3, 0, 0),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_sexp_comment, 3, 0, 0),
  [331] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [334] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [337] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_sexp_comment_repeat1, 2, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3, 0, 0),
  [350] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list, 3, 0, 0),
  [352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 2, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 2, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 3, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector, 3, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byte_vector, 3, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_byte_vector, 3, 0, 0),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 3, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quote, 3, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [370] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasiquote, 3, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquote, 3, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unquote, 3, 0, 0),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_syntax_quote, 3, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_syntax_quote, 3, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quasisyntax, 3, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quasisyntax, 3, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsyntax, 3, 0, 0),
  [386] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unsyntax, 3, 0, 0),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_byte_vector, 2, 0, 0),
  [390] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_byte_vector, 2, 0, 0),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [396] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [399] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [402] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_byte_vector_repeat1, 2, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [413] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [417] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [420] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_comment_repeat1, 2, 0, 0),
  [425] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [429] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [437] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [448] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
