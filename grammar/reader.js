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
  hashBang: (intertoken, symbol) => seq("#!", repeat(intertoken), symbol),
};

const label = {
  definition: datum => seq("#", /[0-9]+/, "=", datum),
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
};

module.exports = {
  abbrev,
  comment,
  directive,
  label,
  list,
  vector,
};
