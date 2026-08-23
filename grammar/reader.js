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
  },
  datum: (intertoken, datum) => seq("#;", repeat(intertoken), datum),
  // Unix shebang. Require a space or slash after #! so this does not eat
  // #!r6rs, #!chezscheme, #!eof, or the other hash-bang tokens.
  shebang: token(choice(
    seq("#!", /[ \t]+/, /[^\n\r]*/),
    seq("#!/", /[^\n\r]*/),
  )),
  block: self =>
    seq("#|",
      repeat(
        choice(
          prec(100, self),
          anyCharacter)),
      prec(100, "|#")),
};

const directive = {
  r6rs: token("#!r6rs"),
  r7rs: token(choice("#!fold-case", "#!no-fold-case")),
  chezscheme: token("#!chezscheme"),
  hashBang: (intertoken, symbol) => seq("#!", repeat(intertoken), symbol),
};
directive.chez = token(choice(
  directive.chezscheme,
  directive.r6rs,
  directive.r7rs,
));

const specialObject = {
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

const vector = {
  hash: token => seq("#(", repeat(token), ")"),
  u8: token => seq("#u8(", repeat(token), ")"),
  vu8: token => seq("#vu8(", repeat(token), ")"),
  hashLength: token => seq("#", optional(/[0-9]+/), "(", repeat(token), ")"),
  vu8Length: token => seq("#", optional(/[0-9]+/), "vu8(", repeat(token), ")"),
  vfx: token => seq("#", optional(/[0-9]+/), "vfx(", repeat(token), ")"),
  vfl: token => seq("#", optional(/[0-9]+/), "vfl(", repeat(token), ")"),
  vs: token => seq("#", /[0-9]+/, "vs(", repeat(token), ")"),
};

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
  specialObject,
  vector,
};
