const { anyCharacter } = require("./core");

const comment = {
  line: {
    // R5RS 2.2: the comment runs to the end of the line, and that line
    // break stays visible as whitespace. Stop at CR and LF so they match
    // core.whitespace.r5rs. Do not treat NEL, U+2028, or U+2029 as
    // R5RS line breaks.
    r5rs: seq(";", /[^\n\r]*/),
    // R6RS 4.2.1: a line comment runs up to a line ending or paragraph
    // separator. This contains the R5RS form and adds Unicode line endings.
    // Leave those characters out so whitespace can consume them.
    r6rs: seq(";", /[^\n\r\u{85}\u{2028}\u{2029}]*/),
    // Chez's reader stops a line comment at NEL and LS, but not at PS.
    // Keep this separate from the R6RS fragment, whose line endings include
    // paragraph separator.
    chez: seq(";", /[^\n\r\u{85}\u{2028}]*/),
    // R7RS 7.1.1 names only CR and LF as line endings. Other Unicode line
    // separators remain part of the comment.
    r7rs: seq(";", /[^\n\r]*/),
    // Guile skip-eol-comment stops only at newline. CR, NEL, and Unicode
    // separators stay in the comment.
    guile: seq(";", /[^\n]*/),
  },
  datum: (intertoken, datum) => seq("#;", repeat(intertoken), datum),
  // Unix shebang. Require a space or slash after #! so this does not eat
  // #!r6rs, #!chezscheme, #!eof, or the other hash-bang tokens.
  shebang: seq("#!", token(choice(
    seq(/ +/, /[^\n\r]*/),
    seq("/", /[^\n\r]*/),
  ))),
  chickenShebang: seq("#!", token(choice(
    seq(/[ \t\/]/, /[^\n\r]*/),
    /\r\n|[\r\n]/,
  ))),
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
  r6rs: seq("#!", "r6rs"),
  r7rs: seq("#!", token(choice("fold-case", "no-fold-case"))),
};
directive.guile = seq("#!", token(choice(
  "r6rs",
  "fold-case",
  "no-fold-case",
  "curly-infix",
  "curly-infix-and-bracket-lists",
)));
directive.chez = seq("#!", token(choice(
  "chezscheme",
  "r6rs",
  "fold-case",
  "no-fold-case",
)));

module.exports = {
  comment,
  directive,
};
