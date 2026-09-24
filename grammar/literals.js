const { anyCharacter } = require("./core");

// Reusable fragments expose their composition. The owning grammar wraps a
// complete fragment in token(...) when the lexer needs one leaf. Within a
// fragment, token(...) wraps only a contextual body after a shared prefix,
// such as an R7RS boolean name after `#`.

const r6rsHexEscape = /\\x[0-9a-fA-F]+;/;

// R6RS constituent above ASCII. A positive `\p{Po}` class would also
// match ASCII `'` and `,`, which must stay quote/unquote marks.
// CLI 0.24 cannot name the unassigned Cn category, so unassigned scalar
// values still match.
// TODO: after upgrading past CLI 0.24, add `\p{Cn}` to this class so
// unassigned scalar values are excluded. CLI 0.25's regex tables include Cn.
const r6rsUnicodeInitial =
  /[^\x00-\x7F\p{Cc}\p{Cf}\p{Cs}\p{Mc}\p{Me}\p{Nd}\p{Pe}\p{Pf}\p{Pi}\p{Ps}\p{Zs}\p{Zl}\p{Zp}]/;
// Nd, Mc, and Me only. Other Unicode subsequent characters already match
// as r6rsInitial, and subsequent includes initial.
const r6rsUnicodeSubsequent = /[\p{Nd}\p{Mc}\p{Me}]/;

const r6rsInitial = choice(
  /[A-Za-z!$%&*\/:<=>?^_~]/,
  r6rsUnicodeInitial,
  r6rsHexEscape,
);
const r6rsSubsequent = choice(
  r6rsInitial,
  /[0-9+.@-]/,
  r6rsUnicodeSubsequent,
);

const r7rsInitial = /[A-Za-z!$%&*\/:<=>?^_~]/;
const r7rsSignSubsequent = choice(r7rsInitial, /[+\-@]/);
const r7rsDotSubsequent = choice(r7rsSignSubsequent, ".");
const r7rsSubsequent = choice(r7rsInitial, /[0-9+.@-]/);
const r7rsBareSymbolMembers = [
  seq(r7rsInitial, repeat(r7rsSubsequent)),
  seq(/[+-]/, optional(seq(r7rsSignSubsequent, repeat(r7rsSubsequent)))),
  seq(/[+-]/, ".", r7rsDotSubsequent, repeat(r7rsSubsequent)),
  seq(".", r7rsDotSubsequent, repeat(r7rsSubsequent)),
];

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

const number = {
  r5rs:
    choice(
      r5rs_number_base(2),
      r5rs_number_base(8),
      r5rs_number_base(10),
      r5rs_number_base(16)),
  r6rs:
    choice(
      r6rs_number_base(2),
      r6rs_number_base(8),
      r6rs_number_base(10),
      r6rs_number_base(16)),
  r7rs:
    choice(
      r7rs_number_base(2),
      r7rs_number_base(8),
      r7rs_number_base(10),
      r7rs_number_base(16)),
};
// Published Guile numbers are R5RS 7.1 plus signed inf/nan. They are not the
// R6RS/R7RS union: no mantissa width, and inf/nan cannot use #e.
//
// Do not use choice(number.r5rs, inf.0, nan.0). inf.0 and nan.0 can be a
// component inside a larger number, so Guile needs one number definition
// that forks the R5RS number rules.
number.guile = choice(
  guile_number_base(2),
  guile_number_base(8),
  guile_number_base(10),
  guile_number_base(16));
number.chez = choice(
  number.r6rs,
  // Chez mode keeps the R5RS `#` digit placeholders that R6RS removed.
  number.r5rs,
  chez_nondecimal_number_base(2),
  chez_nondecimal_number_base(8),
  chez_nondecimal_number_base(16),
  chez_arbitrary_radix_number());

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
  // After #\ , Guile takes one delimiter character, or one token until a
  // delimiter. Names, octal, and hex classify that token; they are not
  // lexer alternatives. docs/guile-scheme-syntax.md Character.
  guile:
    seq(
      "#\\",
      token(choice(
        /[ \t\f\r\n()\[\]{}";]/,
        /[^ \t\f\r\n()\[\]{}";]+/,
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

const chezBarSymbolPart = seq(
  "|",
  repeat(/[^|]+/),
  "|",
);
const chezSymbolPart = choice(
  /[^\s\u{85}()\[\]{}"'`,;#\\|]+/,
  /\\x[0-9a-fA-F]+;/,
  /\\[^x]/,
  chezBarSymbolPart,
);
const chezSymbolStartPart = choice(
  /[^\s\u{85}()\[\]{}"'`,;#\\|0-9+\-.]+/,
  /\\x[0-9a-fA-F]+;/,
  /\\[^x]/,
  chezBarSymbolPart,
);
// Once Chez dispatches to the number-or-symbol reader, `#`, `|`, and `\` are
// ordinary non-delimiters. If numeric conversion fails, the complete token is
// a symbol. This separate shape keeps a `|` in 1.0|53 from opening a bar group
// that could consume whitespace and a later mantissa-width separator.
const chezNumberSymbolMember = /[^\s\u{85}()\[\]{}"'`,;]/;

const symbol = {
  r5rs:
    choice(
      seq(
        /[A-Za-z!$%&*\/:<=>?^_~]/,
        repeat(/[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/)),
      "+",
      "-",
      "..."),
  // R6RS identifier: initial subsequent* | peculiar identifier.
  r6rs:
    choice(
      seq(r6rsInitial, repeat(r6rsSubsequent)),
      "+",
      "-",
      "...",
      seq("->", repeat(r6rsSubsequent))),
  r7rs:
    choice(
      ...r7rsBareSymbolMembers,
      seq(
        "|",
        repeat(
          choice(
            /[^\|\\]+/,
            /\\[xX][0-9a-fA-F]+;/,
            /\\[abtnr]/,
            "\\|")),
        "|")),
  // Chez accepts any delimited sequence that is not a number as an
  // identifier. A longer spelling such as 0abc wins as one identifier
  // instead of being split after the leading number. In Chez mode, a
  // number-like token may contain `#`; it becomes an identifier when the
  // complete token is not a number, as in 32/#. `|` is not a Chez
  // delimiter, so 32/#|foo| is one identifier.
  chez:
    choice(
      seq(/[0-9]/, repeat(chezNumberSymbolMember)),
      seq(/[+\-.]/, repeat1(chezNumberSymbolMember)),
      seq(chezSymbolStartPart, repeat(chezSymbolPart)),
      "+",
      "-",
      "{",
      "}"),
};

const chickenBarSymbol = seq(
  "|",
  repeat(choice(
    /[^|\\]+/,
    /\\[xX][0-9a-fA-F]+;/,
    /\\[abtnr|]/,
  )),
  "|",
);
const chickenInitial = /[A-Za-z!$%&*\/<=>?^_~]/;
const chickenInitialWithColon = /[A-Za-z!$%&*\/:<=>?^_~]/;
const chickenSubsequent = /[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/;
const chickenNonColonSubsequent = /[A-Za-z!$%&*\/<=>?^_~0-9+.@-]/;
const chickenSymbolTail = repeat(chickenSubsequent);
// Colon may appear inside an ordinary symbol, but not at the end. `foo:` is
// then only a suffix keyword, which is longer, so the lexer needs no prec.
const chickenOrdinaryTail = repeat(choice(
  chickenNonColonSubsequent,
  seq(repeat1(":"), chickenNonColonSubsequent),
));
const chickenBareSymbol = (initial, tail = chickenSymbolTail) => choice(
  seq(initial, tail),
  seq(
    /[+-]/,
    optional(seq(
      choice(initial, /[+\-@]/),
      tail))),
  seq(
    /[+-]/,
    ".",
    choice(initial, /[+\-@]/, "."),
    tail),
  seq(
    ".",
    choice(initial, /[+\-@]/, "."),
    tail),
);
// Ordinary symbols omit a leading colon so :NAME can be a prefix keyword.
// A lone : remains a symbol. Keyword names after #: keep colon in both
// positions.
symbol.chicken = choice(
  chickenBareSymbol(chickenInitial, chickenOrdinaryTail),
  chickenBarSymbol,
  ":",
);
symbol.chickenKeywordName = choice(
  chickenBareSymbol(chickenInitialWithColon),
  chickenBarSymbol,
);
// Published ordinary Guile symbols inherit the R5RS identifier grammar.
// Leave colon out of the initial class so the static option union can expose
// :NAME as a prefix keyword; colon remains valid after the first character.
symbol.guile = seq(
  choice(
    seq(
      /[A-Za-z!$%&*\/<=>?^_~]/,
      repeat(/[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/)),
    "+",
    "-",
    "..."));
// Guile's #{...}# form stops at the first }#. Do not wrap this in token():
// repeat(anyCharacter) would be greedy and take the last }#, and wrap(prec)
// inside token() does not compete with anyCharacter in the same token.
// Keep it structural, like block comments: }# stays here, wrap sets priority.
symbol.guileExtended = wrap => seq(
  "#{",
  repeat(anyCharacter),
  wrap("}#"),
);
// Optional r7rs-symbols: |...| with string-style escapes. Do not reuse
// symbol.r7rs; that identifier grammar treats : as initial and would
// steal prefix keywords.
symbol.guileVertical = seq(
  "|",
  repeat(choice(
    /[^|\\]+/,
    /\\x[0-9a-fA-F]{1,8};/,
    /\\u[0-9a-fA-F]{4}/,
    /\\U[0-9a-fA-F]{6}/,
    /\\[|\\("0abfnrtv]/,
  )),
  "|",
);

const keyword = {
  // Marker then name, no atmosphere. The owning grammar supplies the name
  // node and any alias.
  hashColon: name => seq("#:", field("name", name)),
  colon: name => seq(":", field("name", name)),
  // Published postfix keywords are R5RS identifiers ending in colon.
  guilePostfix: seq(
    /[A-Za-z!$%&*\/<=>?^_~]/,
    repeat(/[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/),
    ":",
  ),
  chickenSuffix: seq(
    chickenBareSymbol(chickenInitialWithColon),
    ":",
  ),
  chickenPrefix: seq(
    ":",
    choice(chickenBareSymbol(chickenInitialWithColon), chickenBarSymbol),
  ),
};

// number {{{

function r5rs_number_base(n) {
  const radixn = {
    2: choice("#b", "#B"),
    8: choice("#o", "#O"),
    10: optional(choice("#d", "#D")),
    16: choice("#x", "#X"),
  };
  const digitsn = {
    2: /[01]/,
    8: /[0-7]/,
    10: /[0-9]/,
    16: /[0-9a-fA-F]/,
  };

  const exactness =
    optional(
      choice("#i", "#e", "#I", "#E"));
  const radix = radixn[n];
  const prefix =
    choice(
      seq(radix, exactness),
      seq(exactness, radix));

  const sign = optional(/[+-]/);
  const digits = digitsn[n];

  const exponent = /[eEsSfFdDlL]/;
  const suffix =
    optional(
      seq(
        exponent,
        sign,
        repeat1(digitsn[10])));

  const uinteger =
    seq(
      repeat1(digits),
      repeat("#"));
  const decimal10 = choice(
    seq(uinteger, suffix),
    seq(".", repeat1(digits), repeat("#"), suffix),
    seq(repeat1(digits), ".", repeat(digits), repeat("#"), suffix),
    seq(repeat1(digits), repeat1("#"), ".", repeat("#"), suffix)
  );
  const ureal =
    n === 10
      ? choice(
        uinteger,
        seq(uinteger, "/", uinteger),
        decimal10)
      : choice(
        uinteger,
        seq(uinteger, "/", uinteger));
  const real = seq(sign, ureal);
  const complex = choice(
    real,
    seq(real, "@", real),
    seq(optional(real), /[+-]/, optional(ureal), /[iI]/)
  );

  return seq(prefix, complex);
}

function guile_number_base(n) {
  const radixn = {
    2: choice("#b", "#B"),
    8: choice("#o", "#O"),
    10: optional(choice("#d", "#D")),
    16: choice("#x", "#X"),
  };
  const digitsn = {
    2: /[01]/,
    8: /[0-7]/,
    10: /[0-9]/,
    16: /[0-9a-fA-F]/,
  };

  const finiteExactness =
    optional(
      choice("#i", "#e", "#I", "#E"));
  const infnanExactness = optional(choice("#i", "#I"));
  const radix = radixn[n];
  const finitePrefix =
    choice(
      seq(radix, finiteExactness),
      seq(finiteExactness, radix));
  const infnanPrefix =
    choice(
      seq(radix, infnanExactness),
      seq(infnanExactness, radix));

  const sign = optional(/[+-]/);
  const digits = digitsn[n];

  const exponent = /[eEsSfFdDlL]/;
  const suffix =
    optional(
      seq(
        exponent,
        sign,
        repeat1(digitsn[10])));

  const uinteger =
    seq(
      repeat1(digits),
      repeat("#"));
  const decimal10 = choice(
    seq(uinteger, suffix),
    seq(".", repeat1(digits), repeat("#"), suffix),
    seq(repeat1(digits), ".", repeat(digits), repeat("#"), suffix),
    seq(repeat1(digits), repeat1("#"), ".", repeat("#"), suffix)
  );
  const ureal =
    n === 10
      ? choice(
        uinteger,
        seq(uinteger, "/", uinteger),
        decimal10)
      : choice(
        uinteger,
        seq(uinteger, "/", uinteger));
  const finiteReal = seq(sign, ureal);
  const finiteComplex = choice(
    finiteReal,
    seq(finiteReal, "@", finiteReal),
    seq(
      optional(finiteReal),
      /[+-]/,
      optional(ureal),
      /[iI]/)
  );

  const unsignedInfnan = choice("inf.0", "nan.0");
  const infnanReal = seq(/[+-]/, unsignedInfnan);
  const anyReal = choice(finiteReal, infnanReal);
  const infnanComplex = choice(
    infnanReal,
    seq(infnanReal, "@", anyReal),
    seq(finiteReal, "@", infnanReal),
    seq(optional(anyReal), /[+-]/, unsignedInfnan, /[iI]/),
    seq(infnanReal, /[+-]/, optional(ureal), /[iI]/),
  );

  return choice(
    seq(finitePrefix, finiteComplex),
    seq(infnanPrefix, infnanComplex),
  );
}

function r6rs_number_base(n) {
  const radixn = {
    2: choice("#b", "#B"),
    8: choice("#o", "#O"),
    10: optional(choice("#d", "#D")),
    16: choice("#x", "#X"),
  };
  const digitsn = {
    2: /[01]/,
    8: /[0-7]/,
    10: /[0-9]/,
    16: /[0-9a-fA-F]/,
  };

  const exactness =
    optional(
      choice("#i", "#e", "#I", "#E"));
  const radix = radixn[n];
  const prefix =
    choice(
      seq(radix, exactness),
      seq(exactness, radix));

  const sign = optional(/[+-]/);
  const digits = digitsn[n];
  const digits10 = digitsn[10];

  const exponent = /[eEsSfFdDlL]/;
  const suffix =
    optional(
      seq(
        exponent,
        sign,
        repeat1(digits10)));

  const uinteger = repeat1(digits);
  const decimal10 =
    choice(
      seq(uinteger, suffix),
      seq(".", repeat1(digits), suffix),
      seq(repeat1(digits), ".", repeat(digits), suffix),
      seq(repeat1(digits), ".", suffix));
  const decimal = {
    2: "",
    8: "",
    10: decimal10,
    16: "",
  }[n];

  const mantissa_width =
    optional(
      seq("|", repeat1(digits10)));

  const naninf = choice(
    /[nN][aA][nN]\.0/,
    /[iI][nN][fF]\.0/);

  const ureal =
    n === 10
      ? choice(
        uinteger,
        seq(uinteger, "/", uinteger),
        seq(decimal, mantissa_width))
      : choice(
        uinteger,
        seq(uinteger, "/", uinteger));
  const real =
    choice(
      seq(sign, ureal),
      seq(/[+-]/, naninf));
  const complex =
    choice(
      real,
      seq(real, "@", real),
      seq(
        optional(real),
        /[+-]/,
        optional(choice(ureal, naninf)),
        /[iI]/));

  return seq(prefix, complex);
}

function r7rs_number_base(n) {
  const infnan =
    choice(
      /[+-][iI][nN][fF]\.0/,
      /[+-][nN][aA][nN]\.0/);

  const exponent_marker = /[eE]/;
  const sign = optional(/[+-]/);
  const exactness = optional(/#[ieIE]/);
  const radix =
    {
      2: /#[bB]/,
      8: /#[oO]/,
      10: optional(/#[dD]/),
      16: /#[xX]/,
    }[n];
  const digit =
    {
      2: /[01]/,
      8: /[0-7]/,
      10: /[0-9]/,
      16: /[0-9a-fA-F]/,
    }[n];

  const suffix =
    optional(
      seq(exponent_marker, sign, repeat1(digit)));

  const prefix =
    choice(
      seq(radix, exactness),
      seq(exactness, radix));

  const uinteger = repeat1(digit);

  const rational = seq(uinteger, "/", uinteger);
  const decimal =
    choice(
      seq(uinteger, suffix),
      seq(".", repeat1(digit), suffix),
      seq(repeat1(digit), ".", repeat(digit), suffix));

  const ureal =
    n === 10
      ? choice(uinteger, rational, decimal)
      : choice(uinteger, rational);

  const real =
    choice(
      seq(sign, ureal),
      infnan);

  const complex =
    choice(
      real,
      seq(real, "@", real),
      seq(real, /[+-]/, ureal, /[iI]/),
      seq(real, /[+-]/, /[iI]/),
      seq(real, infnan, /[iI]/),
      seq(/[+-]/, ureal, /[iI]/),
      seq(infnan, /[iI]/),
      seq(/[+-]/, /[iI]/));

  const num =
    seq(
      prefix,
      complex);

  return num;
}

// Chez extends the ordinary radix prefixes with fractional and exponent
// notation. The digit class is still radix-specific, so a hexadecimal e is a
// digit before it is considered as an exponent marker.
function chez_nondecimal_number_base(n) {
  const radix = {
    2: /#[bB]/,
    8: /#[oO]/,
    16: /#[xX]/,
  }[n];
  const digit = {
    2: /[01]/,
    8: /[0-7]/,
    16: /[0-9a-fA-F]/,
  }[n];
  const exactness = optional(/#[iIeE]/);
  const prefix = choice(
    seq(radix, exactness),
    seq(exactness, radix));
  const sign = optional(/[+-]/);
  const exponent = optional(seq(/[eEsSfFdDlL]/, sign, repeat1(digit)));
  // strnum allows `|` plus decimal digits after an integer or float in any
  // radix. A ratio has no mantissa width: `#x1/2|53` is invalid.
  const mantissaWidth = optional(seq("|", repeat1(/[0-9]/)));
  const uinteger = repeat1(digit);
  const ureal = choice(
    seq(uinteger, "/", uinteger),
    seq(".", repeat1(digit), exponent, mantissaWidth),
    seq(uinteger, ".", repeat(digit), exponent, mantissaWidth),
    seq(uinteger, exponent, mantissaWidth));
  const real = seq(sign, ureal);

  return seq(prefix, choice(
    real,
    seq(real, "@", real),
    seq(optional(real), /[+-]/, optional(ureal), /[iI]/)));
}

// Digit validity for #nr depends on n and cannot be encoded by Tree-sitter's
// regular lexer without listing 35 number towers. Chez performs that semantic
// check. Keep the prefix valued 2 through 36, including leading zeros, and
// consume the complete number-like token so `#16r1+1i` stays one node. A
// letter that is a digit in that radix is not classified here as `i` or inf.
function chez_arbitrary_radix_number() {
  const exactness = /#[iIeE]/;
  const radix = /#0*(?:[2-9]|[12][0-9]|3[0-6])[rR]/;
  const prefix = choice(
    seq(radix, optional(exactness)),
    seq(optional(exactness), radix));

  return seq(prefix, /[0-9A-Za-z+\-.\/@|#]+/);
}

// number }}}

module.exports = {
  boolean,
  byteString,
  character,
  intralineWhitespace,
  keyword,
  lineEnding,
  number,
  string,
  stringEscape,
  symbol,
};
