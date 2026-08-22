// Tree-sitter `.` does not match line breaks. Character constants and
// nested block comments need every Unicode scalar, including those.
const anyCharacter = /.|[\r\n\u{85}\u{2028}\u{2029}]/;

const whitespace = {
  // R5RS 7.1.1 names space and newline. CR is included so CRLF files
  // still separate tokens.
  r5rs: token(repeat1(/[ \r\n]/)),
  // R6RS 4.2 whitespace. U+0085 NEXT LINE is Cc, not Zs/Zl/Zp.
  r6rs: token(repeat1(/[ \r\n\t\f\v\u{85}\p{Zs}\p{Zl}\p{Zp}]/)),
  // R7RS 7.1.1 names space, tab, newline, and return.
  r7rs: token(repeat1(/[ \t\r\n]/)),
};

module.exports = {
  anyCharacter,
  whitespace,
};
