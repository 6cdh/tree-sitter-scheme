// Tree-sitter `.` does not match line breaks. Character constants and
// nested block comments need every Unicode scalar, including those.
const anyCharacter = /.|[\r\n\u{85}\u{2028}\u{2029}]/;

const whitespace = {
  // R5RS 7.1.1 names space and newline. CR is included so CRLF files
  // still separate tokens.
  r5rs: repeat1(/[ \r\n]/),
  // R6RS 4.2 whitespace. U+0085 NEXT LINE is Cc, not Zs/Zl/Zp.
  r6rs: repeat1(/[ \r\n\t\f\v\u{85}\p{Zs}\p{Zl}\p{Zp}]/),
  // R7RS 7.1.1 names space, tab, newline, and return.
  r7rs: repeat1(/[ \t\r\n]/),
  // Scheme Read discards whitespace and does not list the characters.
  // The verified set is space, tab, formfeed, return, and newline.
  guile: repeat1(/[ \t\f\r\n]/),
};

module.exports = {
  anyCharacter,
  whitespace,
};
