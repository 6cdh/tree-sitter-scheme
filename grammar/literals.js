const { anyCharacter } = require("./core");

const boolean = {
  r5rs: seq("#", /[tTfF]/),
  r6rs: seq("#", /[tTfF]/),
  // Keep `#` visible to the parser. The following name then competes with
  // other hash-dispatch bodies, such as CHICKEN's `f32` number-vector tag.
  r7rs: seq("#", token(choice(
    /[tTfF]/,
    /[tT][rR][uU][eE]/,
    /[fF][aA][lL][sS][eE]/,
  ))),
};

// Chez rd-token-delimiter / rd-token-to-delimiter plus char-whitespace?.
const chezNonDelimiter =
  /[^\t\n\r\f\v\u{85}\p{Zs}\p{Zl}\p{Zp}\(\)\[\]\{\}"'`,;#]/;

const character = {
  r5rs:
    seq(
      "#\\",
      token(choice(
        /[sS][pP][aA][cC][eE]/,
        /[nN][eE][wW][lL][iI][nN][eE]/,
        anyCharacter))),
  r6rs:
    seq(
      "#\\",
      token(choice(
        "nul", "alarm", "backspace", "tab",
        "linefeed", "newline", "vtab", "page",
        "return", "esc", "space", "delete",
        /x[0-9a-fA-F]+/,
        anyCharacter))),
  r7rs:
    seq(
      "#\\",
      token(choice(
        "alarm", "backspace", "delete",
        "escape", "newline", "null",
        "return", "space", "tab",
        /[xX][0-9a-fA-F]+/,
        anyCharacter))),
  // CHICKEN adds exact-width u/U escapes and five character names to R7RS.
  // The dialect accepts case-folded character names as part of its static
  // reader-mode union. The u/U prefixes remain case-sensitive.
  chicken:
    seq(
      "#\\",
      token(choice(
        /[aA][lL][aA][rR][mM]/,
        /[bB][aA][cC][kK][sS][pP][aA][cC][eE]/,
        /[dD][eE][lL][eE][tT][eE]/,
        /[eE][sS][cC][aA][pP][eE]/,
        /[nN][eE][wW][lL][iI][nN][eE]/,
        /[nN][uU][lL][lL]/,
        /[rR][eE][tT][uU][rR][nN]/,
        /[sS][pP][aA][cC][eE]/,
        /[tT][aA][bB]/,
        /[lL][iI][nN][eE][fF][eE][eE][dD]/,
        /[vV][tT][aA][bB]/,
        /[nN][uU][lL]/,
        /[pP][aA][gG][eE]/,
        /[eE][sS][cC]/,
        /[xX][0-9a-fA-F]+/,
        /u[0-9a-fA-F]{4}/,
        /U[0-9a-fA-F]{8}/,
        anyCharacter))),
  // `/u[0-9a-fA-F]+/` requires a hex digit, so `#\u` remains the
  // character u.
  steelScheme:
    seq("#\\", /u[0-9a-fA-F]+/),
  // Published Guile character spellings from the Characters page. Names are
  // the listed lowercase tables. docs/guile-scheme-syntax.md Character.
  guile:
    seq(
      "#\\",
      token(choice(
        "backspace", "linefeed", "newline", "delete", "escape",
        "alarm", "space", "null", "page", "return", "tab",
        "vtab", "nul", "esc", "soh", "stx", "etx", "eot",
        "enq", "ack", "bel", "bs", "ht", "lf", "vt", "ff",
        "cr", "so", "si", "dle", "dc1", "dc2", "dc3", "dc4",
        "nak", "syn", "etb", "can", "em", "sub", "fs", "gs",
        "rs", "us", "sp", "del", "nl", "np",
        /x[0-9a-fA-F]{1,8}/,
        /[0-7]+/,
        seq("\u{25CC}", anyCharacter),
        anyCharacter,
      ))),
  // Chez rd-token-char. Lowercase x plus a hex digit starts hex; a later
  // non-hex non-delimiter sends the complete token to character-name lookup.
  // Two ASCII letters start that same name path. Two initial octal digits
  // commit to exactly three octal digits. Otherwise one character is read.
  // A static grammar cannot enforce the final delimiter or runtime name,
  // scalar-value, and octal-range checks, so malformed forms recover as a
  // character plus any following tokens. docs/chez-scheme-syntax.md Character.
  chez:
    seq(
      "#\\",
      token(choice(
        seq("x", /[0-9a-fA-F]+/, repeat(chezNonDelimiter)),
        seq(/[a-wyzA-Z]/, /[a-zA-Z]/, repeat(chezNonDelimiter)),
        /[0-7]{3}/,
        anyCharacter))),
};

module.exports = {
  boolean,
  character,
};
