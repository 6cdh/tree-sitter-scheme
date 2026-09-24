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
    /x[0-9a-fA-F]{2};/,
    /u[0-9a-fA-F]{4}/,
    /U[0-9a-fA-F]{8}/,
    /[0-7]{3}/,
    seq(
      repeat(intralineWhitespace.r7rs),
      lineEnding.r7rs,
      repeat(intralineWhitespace.r7rs)),
  ))),
  // The Guile parser accepts the union of default and option-controlled string
  // escapes. Published R6RS-style scalar escapes contain at most eight digits.
  guile: seq("\\", token(choice(
    /[|\\("0abfnrtv]/,
    /x[0-9a-fA-F]{2}/,
    /x[0-9a-fA-F]{1,8};/,
    /u[0-9a-fA-F]{4}/,
    /U[0-9a-fA-F]{6}/,
    seq("\n", repeat(/[\t\p{Zs}]/)),
  ))),
  // Published SRFI-207 byte-string escapes. Hungry continuation is newline
  // plus later non-newline whitespace.
  srfi207: seq("\\", token(choice(
    /[abtnr"|\\]/,
    /x0*[0-9a-fA-F]{1,2};/,
    seq("\n", repeat(/[^\S\n]/)),
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
  // `#u8"` then SRFI-207 bytes U+0020 through U+007E except `"` and `\`.
  srfi207: escape_sequence =>
    seq(
      '#u8"',
      repeat(
        choice(
          escape_sequence,
          /[\x20-\x21\x23-\x5b\x5d-\x7e]+/)),
      '"'),
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
