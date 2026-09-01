const {anyCharacter} = require("./core");

const comment = {
  line: {
    // R5RS 2.2: the comment runs to the end of the line, and that line
    // break stays visible as whitespace. Stop at CR and LF so they match
    // core.whitespace.r5rs. Do not treat NEL, U+2028, or U+2029 as
    // R5RS line breaks.
    r5rs: token(seq(";", /[^\n\r]*/)),
    // R6RS 4.2.1: a line comment runs up to a line ending or paragraph
    // separator. This contains the R5RS form and adds Unicode line endings.
    // Leave those characters out so whitespace can consume them.
    r6rs: token(seq(";", /[^\n\r\u{85}\u{2028}\u{2029}]*/)),
    // Chez's reader stops a line comment at NEL and LS, but not at PS.
    // Keep this separate from the R6RS fragment, whose line endings include
    // paragraph separator.
    chez: token(seq(";", /[^\n\r\u{85}\u{2028}]*/)),
    // R7RS 7.1.1 names only CR and LF as line endings. Other Unicode line
    // separators remain part of the comment.
    r7rs: token(seq(";", /[^\n\r]*/)),
    // Guile skip-eol-comment stops only at newline. CR, NEL, and Unicode
    // separators stay in the comment.
    guile: token(seq(";", /[^\n]*/)),
  },
  datum: (intertoken, datum) => seq("#;", repeat(intertoken), datum),
  // Unix shebang. Require a space or slash after #! so this does not eat
  // #!r6rs, #!chezscheme, #!eof, or the other hash-bang tokens.
  shebang: token(choice(
    seq("#!", / +/, /[^\n\r]*/),
    seq("#!/", /[^\n\r]*/),
  )),
  // Guile treats every unknown #! name as a script comment ending at the
  // first !#. Keep this structural so the grammar's exact directive tokens
  // win at their longer opening spellings and the closing priority stops at
  // the first delimiter.
  guileScript: wrap => seq(
    "#!",
    repeat(anyCharacter),
    wrap("!#"),
  ),
  // The parser supplies the precedence wrapper because nested-comment and
  // closing-delimiter priorities belong to that parser's lexical domain.
  block: (self, wrap) =>
    seq("#|",
      repeat(
        choice(
          wrap(self),
          anyCharacter)),
      wrap("|#")),
};

const directive = {
  r6rs: token("#!r6rs"),
  r7rs: token(choice("#!fold-case", "#!no-fold-case")),
};
directive.guile = token(choice(
  directive.r6rs,
  directive.r7rs,
  "#!curly-infix",
  "#!curly-infix-and-bracket-lists",
));
directive.chez = token(choice(
  "#!chezscheme",
  directive.r6rs,
  directive.r7rs,
));

const specialObject = {
  // Guile dispatches only on lowercase n. The rest is case-insensitive when
  // that reader option is enabled, which the static dialect union accepts.
  guile: token(seq("#n", /[iI][lL]/)),
  chez: token(choice("#!eof", "#!bwp", "#!base-rtd")),
};

const label = {
  definition: {
    // R7RS 2.4: `#⟨n⟩=⟨datum⟩` with no atmosphere after `=`.
    r7rs: datum => seq("#", /[0-9]+/, "=", datum),
    // Chez: `#n=` is one token; intertoken may follow before the datum.
    chez: (label, intertoken, datum) =>
      seq(
        "#",
        field("label", label),
        "=",
        repeat(intertoken),
        datum),
  },
  reference: token(seq("#", /[0-9]+/, "#")),
  referenceWithField: label =>
    seq("#", field("label", label), "#"),
};

// Round, square, and curly lists share one shape: delimiters around repeated
// contents. A dialect that allows dotted lists passes choice(token, dot).
const list = {
  round: token => seq("(", repeat(token), ")"),
  square: token => seq("[", repeat(token), "]"),
  curly: token => seq("{", repeat(token), "}"),
};

const abbrev = {
  quote: (intertoken, datum) =>
    seq(
      "'",
      repeat(intertoken),
      datum),
  quasiquote: (intertoken, datum) =>
    seq(
      "`",
      repeat(intertoken),
      datum),
  unquote: (intertoken, datum) =>
    seq(
      ",",
      repeat(intertoken),
      datum),
  unquoteSplicing: (intertoken, datum) =>
    seq(
      ",@",
      repeat(intertoken),
      datum),
  syntax: (intertoken, datum) =>
    seq(
      "#'",
      repeat(intertoken),
      datum),
  quasisyntax: (intertoken, datum) =>
    seq(
      "#`",
      repeat(intertoken),
      datum),
  unsyntax: (intertoken, datum) =>
    seq(
      "#,",
      repeat(intertoken),
      datum),
  unsyntaxSplicing: (intertoken, datum) =>
    seq(
      "#,@",
      repeat(intertoken),
      datum),
};

// Guile array prefix between `#` and `(`. The dialect keeps those delimiters
// in the same token so `#f32(` beats boolean `#f` and `#u8(` beats byte-string
// `#u8`. Length is enough; do not add prec(). `#(` is the vector rule, not an
// empty prefix. `#vu8(` is the bytevector rule. Bare `#a(` and `#b(` are
// unknown hash objects; ranked `#2a(` is an array.
function guile_array_prefix() {
  const rank = /[0-9]+/;
  const unsigned = /[0-9]+/;
  const uniformTag = choice(
    "u8", "u16", "u32", "u64",
    "s8", "s16", "s32", "s64",
    "f32", "f64", "c32", "c64",
  );
  // Ranked arrays also allow string/bit tags a and b (`#2a(`). Bare `#a(`
  // is not an array. Unranked forms use only uniformTag (`#u8(`).
  const vectag = choice(uniformTag, "a", "b");
  const dimension = choice(
    seq("@", optional(/[+-]/), unsigned, optional(seq(":", unsigned))),
    seq(":", unsigned),
  );
  return choice(
    seq(rank, optional(vectag), repeat(dimension)),
    seq(uniformTag, repeat(dimension)),
    repeat1(dimension),
  );
}

const vector = {
  hash: token => seq("#(", repeat(token), ")"),
  u8: token => seq("#u8(", repeat(token), ")"),
  vu8: token => seq("#vu8(", repeat(token), ")"),
  hashLength: (length, token) =>
    seq("#", optional(field("length", length)), "(", repeat(token), ")"),
  vu8Length: (length, token) =>
    seq("#", optional(field("length", length)), "vu8(", repeat(token), ")"),
  vfx: (length, token) =>
    seq("#", optional(field("length", length)), "vfx(", repeat(token), ")"),
  vfl: (length, token) =>
    seq("#", optional(field("length", length)), "vfl(", repeat(token), ")"),
  vs: (mask, token) =>
    seq("#", field("mask", mask), "vs(", repeat(token), ")"),
  // Literal `#` then `*`, then zero or more bit characters. `#*` is the
  // empty bitvector. This is not a regex "zero or more hashes".
  guileBitvector: token(seq("#*", /[01]*/)),
  guileArrayPrefix: guile_array_prefix(),
};

const box = (intertoken, datum) =>
  seq("#&", repeat(intertoken), datum);

const record = (intertoken, token, typeName) =>
  seq(
    "#[",
    repeat(intertoken),
    field("name", typeName),
    repeat(token),
    "]");

// Chez's two-name gensym reader skips only these three characters between
// names. It does not skip comments or other atmosphere at that point.
const gensymSpace = token(repeat1(/[ \t\n]/));

const gensym = {
  pretty: symbol => seq("#:", symbol),
  unique: symbol =>
    seq(
      "#{",
      symbol,
      repeat1(gensymSpace),
      symbol,
      "}"),
};

const primitive = (prefix, symbol) =>
  seq(
    field("prefix", prefix),
    symbol);

module.exports = {
  abbrev,
  box,
  comment,
  directive,
  gensym,
  label,
  list,
  primitive,
  record,
  specialObject,
  vector,
};
