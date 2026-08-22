const {common} = require("./core");

const comment = {
  line: token(/;.*/),
  datum: (intertoken, datum) => seq("#;", repeat(intertoken), datum),
  block: self =>
    seq("#|",
      repeat(
        choice(
          prec(100, self),
          common.any_char)),
      prec(100, "|#")),
};

const directive = {
  hashBang: (intertoken, symbol) => seq("#!", repeat(intertoken), symbol),
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
  vu8: token => seq("#vu8(", repeat(token), ")"),
};

module.exports = {
  abbrev,
  comment,
  directive,
  list,
  vector,
};
