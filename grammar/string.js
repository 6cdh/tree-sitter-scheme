// String line continuations use dialect-specific whitespace and endings.
const intralineWhitespace = {
  r6rs: /[\t\p{Zs}]/,
  r7rs: /[ \t]/,
};

const lineEnding = {
  r6rs: /[\n\r\u{2028}\u{0085}]|(\r\n)|(\r\u{0085})/,
  r7rs: /(\r\n)|[\r\n]/,
};

const r6rsStringEscapeBody = choice(
  /[abtnvfr"\\]/,
  /x[0-9a-fA-F]+;/,
  seq(
    repeat(intralineWhitespace.r6rs),
    lineEnding.r6rs,
    repeat(intralineWhitespace.r6rs)),
);

const stringEscape = {
  r5rs: seq("\\", /["\\]/),
  r6rs: seq("\\", token(r6rsStringEscapeBody)),
  r7rs: seq("\\", token(choice(
    /[abtnr"\\]/,
    seq(
      repeat(intralineWhitespace.r7rs),
      lineEnding.r7rs,
      repeat(intralineWhitespace.r7rs)),
    /[xX][0-9a-fA-F]+;/,
  ))),
  chicken: seq("\\", token(choice(
    /[abtnrvf"\\|']/,
    // The formal syntax inherits R7RS case-insensitivity for `x`; the
    // CHICKEN 6.0.0 reader itself warns on uppercase `X`.
    /[xX][0-9a-fA-F]{2};/,
    /u[0-9a-fA-F]{4}/,
    /U[0-9a-fA-F]{8}/,
    /[0-7]{3}/,
    seq(
      repeat(intralineWhitespace.r7rs),
      lineEnding.r7rs,
      repeat(intralineWhitespace.r7rs)),
  ))),
  // Guile's default escapes. Optional R6RS hex and hungry line modes are
  // excluded; directives are recognized without changing later tokenization.
  guile: seq("\\", token(choice(
    /[|\\("0abfnrtv]/,
    /x[0-9a-fA-F]{2}/,
    /u[0-9a-fA-F]{4}/,
    /U[0-9a-fA-F]{6}/,
    "\n",
  ))),
  chez: seq("\\", token(choice(
    r6rsStringEscapeBody,
    "'",
    /[0-7]{3}/,
  ))),
};

const string = escape_sequence =>
  seq(
    '"',
    repeat(
      choice(
        escape_sequence,
        /[^"\\]+/)),
    '"');

const byteString = {
  chicken: escape_sequence =>
    seq(
      '#u8"',
      repeat(
        choice(
          escape_sequence,
          /[^"\\]+/)),
      '"'),
};

module.exports = {
  byteString,
  intralineWhitespace,
  lineEnding,
  string,
  stringEscape,
};
