const { anyCharacter } = require("./core");

// A plain lexical fragment owns token(...). A grammar uses one fragment
// directly or wraps a composition of several fragments in one token(...).
// string stays a factory because it has child nodes.

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

const boolean = {
  r5rs: token(seq("#", /[tTfF]/)),
  r6rs: token(seq("#", /[tTfF]/)),
  r7rs:
    token(seq(
      "#",
      choice(
        /[tTfF]/,
        /[tT][rR][uU][eE]/,
        /[fF][aA][lL][sS][eE]/))),
};

const number = {
  r5rs:
    token(choice(
      r5rs_number_base(2),
      r5rs_number_base(8),
      r5rs_number_base(10),
      r5rs_number_base(16))),
  r6rs:
    token(choice(
      r6rs_number_base(2),
      r6rs_number_base(8),
      r6rs_number_base(10),
      r6rs_number_base(16))),
  r7rs:
    token(choice(
      r7rs_number_base(2),
      r7rs_number_base(8),
      r7rs_number_base(10),
      r7rs_number_base(16))),
};
number.chez = token(choice(
  number.r6rs,
  // Chez mode keeps the R5RS `#` digit placeholders that R6RS removed.
  number.r5rs,
  chez_nondecimal_number_base(2),
  chez_nondecimal_number_base(8),
  chez_nondecimal_number_base(16),
  chez_arbitrary_radix_number(),
));

const character = {
  r5rs:
    token(seq(
      "#\\",
      choice(
        /[sS][pP][aA][cC][eE]/,
        /[nN][eE][wW][lL][iI][nN][eE]/,
        anyCharacter))),
  r6rs:
    token(seq(
      "#\\",
      choice(
        "nul", "alarm", "backspace", "tab",
        "linefeed", "newline", "vtab", "page",
        "return", "esc", "space", "delete",
        /x[0-9a-fA-F]+/,
        anyCharacter))),
  r7rs:
    token(seq(
      "#\\",
      choice(
        "alarm", "backspace", "delete",
        "escape", "newline", "null",
        "return", "space", "tab",
        /[xX][0-9a-fA-F]+/,
        anyCharacter))),
  // `/u[0-9a-fA-F]+/` needs at least one hex digit, so `#\u` is still
  // the letter u.
  steelScheme:
    token(seq("#\\", /u[0-9a-fA-F]+/)),
};
character.chez = token(choice(
  character.r6rs,
  seq("#\\", choice(
    /[0-7]{3}/,
    "bel", "ls", "nel", "rubout", "vt",
  )),
));

// String line continuations use dialect-specific whitespace and endings.
const intralineWhitespace = {
  r6rs: /[\t\p{Zs}]/,
  r7rs: /[ \t]/,
};

const lineEnding = {
  r6rs: /[\n\r\u{2028}\u{0085}]|(\r\n)|(\r\u{0085})/,
  r7rs: /(\r\n)|[\r\n]/,
};

const stringEscape = {
  r5rs:
    token(choice(
      "\\\"",
      "\\\\")),
  r6rs:
    token(seq(
      "\\",
      choice(
        /[abtnvfr"\\]/,
        /x[0-9a-fA-F]+;/,
        seq(
          repeat(intralineWhitespace.r6rs),
          lineEnding.r6rs,
          repeat(intralineWhitespace.r6rs))))),
  r7rs:
    token(seq(
      "\\",
      choice(
        /[abtnr"\\]/,
        seq(
          repeat(intralineWhitespace.r7rs),
          lineEnding.r7rs,
          repeat(intralineWhitespace.r7rs)),
        /[xX][0-9a-fA-F]+;/))),
};
stringEscape.chez = token(choice(
  stringEscape.r6rs,
  /\\'/,
  /\\[0-7]{3}/,
));

const string = escape_sequence =>
  seq(
    '"',
    repeat(
      choice(
        escape_sequence,
        /[^"\\]+/)),
    '"');

const symbol = {
  r5rs:
    token(choice(
      seq(
        /[A-Za-z!$%&*\/:<=>?^_~]/,
        repeat(/[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/)),
      "+",
      "-",
      "...")),
  // R6RS identifier: initial subsequent* | peculiar identifier.
  r6rs:
    token(choice(
      seq(r6rsInitial, repeat(r6rsSubsequent)),
      "+",
      "-",
      "...",
      seq("->", repeat(r6rsSubsequent)))),
  r7rs:
    token(choice(
      seq(r7rsInitial, repeat(r7rsSubsequent)),
      seq(/[+-]/, optional(seq(r7rsSignSubsequent, repeat(r7rsSubsequent)))),
      seq(/[+-]/, ".", r7rsDotSubsequent, repeat(r7rsSubsequent)),
      seq(".", r7rsDotSubsequent, repeat(r7rsSubsequent)),
      seq(
        "|",
        repeat(
          choice(
            /[^\|\\]+/,
            /\\[xX][0-9a-fA-F]+;/,
            /\\[abtnr]/,
            "\\|")),
        "|"))),
  // Chez accepts any delimited sequence that is not a number as an
  // identifier. A longer spelling such as 0abc wins as one identifier
  // instead of being split after the leading number. In Chez mode, a
  // number-like token may contain `#`; it becomes an identifier when the
  // complete token is not a number, as in 32/#. `|` is not a Chez
  // delimiter, so 32/#|foo| is one identifier.
  chez:
    token(choice(
      /[0-9+\.\-][0-9A-Za-z+\.\-\/@|#]*#[0-9A-Za-z+\.\-\/@|#]*/,
      repeat1(choice(
        /[^\s()\[\]{}"'`,;#\\|]+/,
        /\\x[0-9a-fA-F]+;/,
        /\\[^x\r\n]/,
        seq(
          "|",
          repeat(choice(/[^|\\]+/, /\\./)),
          "|"))),
      "{",
      "}")),
};

const keyword = {
  prefix: symbol => token(seq("#:", symbol)),
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
  const uinteger = repeat1(digit);
  const ureal = choice(
    uinteger,
    seq(uinteger, "/", uinteger),
    seq(".", repeat1(digit), exponent),
    seq(uinteger, ".", repeat(digit), exponent),
    seq(uinteger, exponent));
  const real = seq(sign, ureal);

  return seq(prefix, choice(
    real,
    seq(real, "@", real),
    seq(optional(real), /[+-]/, optional(ureal), /[iI]/)));
}

// Digit validity for #nr depends on n and cannot be encoded by Tree-sitter's
// regular lexer without listing 35 number towers. Chez performs that semantic
// check. Keep the token bounded to the documented radix range and number
// punctuation so editor input remains one number node.
function chez_arbitrary_radix_number() {
  const exactness = /#[iIeE]/;
  const radix = /#(?:[2-9]|[12][0-9]|3[0-6])[rR]/;
  const prefix = choice(
    seq(radix, optional(exactness)),
    seq(optional(exactness), radix));

  return seq(prefix, /[+\-]?[0-9A-Za-z.\/@|#]+/);
}

// number }}}

module.exports = {
  boolean,
  character,
  intralineWhitespace,
  keyword,
  lineEnding,
  number,
  string,
  stringEscape,
  symbol,
};
