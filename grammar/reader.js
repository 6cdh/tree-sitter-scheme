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
    seq("#!", /[ \t]+/, /[^\n\r]*/),
    seq("#!/", /[^\n\r]*/),
  )),
  // Guile script comment: #! then a character that cannot start a
  // directive name, through the first !#. Directives all start with a
  // letter, so requiring a non-letter keeps #!r6rs from swallowing a
  // later !#. Split the body at `!` so a later !# does not enlarge this
  // token. Unknown letter names such as #!foo ... !# still need a later
  // !# in Guile; Tree-sitter cannot express that without eating
  // directives.
  guileShebang: token(seq(
    "#!",
    /[ \t\f\r\n/]/,
    repeat(choice(/[^!]+/, /![^#]/)),
    "!#",
  )),
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
  chezscheme: token("#!chezscheme"),
  hashBang: (intertoken, symbol) => seq("#!", repeat(intertoken), symbol),
};
directive.guile = token(choice(
  directive.r6rs,
  directive.r7rs,
  "#!curly-infix",
  "#!curly-infix-and-bracket-lists",
));
directive.chez = token(choice(
  directive.chezscheme,
  directive.r6rs,
  directive.r7rs,
));

const specialObject = {
  // After #n, read takes one token starting with n. Shape keeps that
  // token; it should be nil. docs/guile-scheme-syntax.md Special object.
  guile: token(seq("#n", /[^ \t\f\r\n()\[\]{}";]*/)),
  chez: token(choice("#!eof", "#!bwp", "#!base-rtd")),
};

const label = {
  definition: {
    // R7RS 2.4: `#⟨n⟩=⟨datum⟩` with no atmosphere after `=`.
    r7rs: datum => seq("#", /[0-9]+/, "=", datum),
    // Chez: `#n=` is one token; intertoken may follow before the datum.
    chez: (intertoken, datum) =>
      seq("#", /[0-9]+/, "=", repeat(intertoken), datum),
  },
  reference: token(seq("#", /[0-9]+/, "#")),
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
// in the same token so `#f32(` beats boolean `#f`, `#u8(` beats byte-string
// `#u8`, and `#0(` beats a one-character hash extension. Length is enough;
// do not add prec(). `#(` is the vector rule, not an empty prefix. `#vu8(` is
// the bytevector rule. Bare `#a(` and `#b(` are unknown hash objects; ranked
// `#2a(` is an array.
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
    seq("@", optional("-"), unsigned, optional(seq(":", unsigned))),
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
  hashLength: token => seq("#", optional(/[0-9]+/), "(", repeat(token), ")"),
  vu8Length: token => seq("#", optional(/[0-9]+/), "vu8(", repeat(token), ")"),
  vfx: token => seq("#", optional(/[0-9]+/), "vfx(", repeat(token), ")"),
  vfl: token => seq("#", optional(/[0-9]+/), "vfl(", repeat(token), ")"),
  vs: token => seq("#", /[0-9]+/, "vs(", repeat(token), ")"),
  // Literal `#` then `*`, then zero or more bit characters. `#*` is the
  // empty bitvector. This is not a regex "zero or more hashes".
  guileBitvector: token(seq("#*", /[01]*/)),
  guileArrayPrefix: guile_array_prefix(),
};

// An installed read-hash-extend callback is selected by one character after #.
// Keep only that dispatch prefix here. The callback may consume the remaining
// input, so the static grammar must not claim to know the extension payload.
// Exclude Guile delimiters, not Unicode whitespace: vertical tab can follow #.
// Digits after # start an array, so they are not extension prefixes.
const readerExtension = token(/#[^ \t\f\r\n()\[\]{};"'`,#0-9]/);

const box = (intertoken, datum) =>
  seq("#&", repeat(intertoken), datum);

const record = (intertoken, token, typeName) =>
  seq(
    "#[",
    repeat(intertoken),
    typeName,
    repeat(token),
    "]");

const gensym = {
  pretty: symbol => seq("#:", symbol),
  unique: (intertoken, symbol) =>
    seq(
      "#{",
      repeat(intertoken),
      symbol,
      repeat1(intertoken),
      symbol,
      repeat(intertoken),
      "}"),
};

const primitive = symbol =>
  seq(token(seq("#", optional(/[23]/), "%")), symbol);

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
  readerExtension,
  specialObject,
  vector,
};
