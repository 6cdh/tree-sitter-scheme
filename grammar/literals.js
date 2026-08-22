const {common} = require("./core");

// Lexical fragments are already token(...). Dialects select them without a
// second token() wrapper. string stays a factory because it has child nodes.

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

const character = {
  r5rs:
    token(seq(
      "#\\",
      choice(
        /[sS][pP][aA][cC][eE]/,
        /[nN][eE][wW][lL][iI][nN][eE]/,
        common.any_char))),
  r6rs:
    token(seq(
      "#\\",
      choice(
        "nul", "alarm", "backspace", "tab",
        "linefeed", "newline", "vtab", "page",
        "return", "esc", "space", "delete",
        /x[0-9a-fA-F]+/,
        /u[0-9a-fA-F]+/,
        common.any_char))),
  r7rs:
    token(seq(
      "#\\",
      choice(
        "alarm", "backspace", "delete",
        "escape", "newline", "null",
        "return", "space", "tab",
        /[xX][0-9a-fA-F]+/,
        common.any_char))),
  extension:
    token(seq(
      "#\\",
      choice("bel", "ls", "nel", "rubout", "vt"))),
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
          common.intra_whitespace,
          common.line_ending,
          common.intra_whitespace)))),
  r7rs:
    token(seq(
      "\\",
      choice(
        /[abtnr"\\]/,
        seq(
          repeat(common.intra_whitespace),
          common.line_ending,
          repeat(common.intra_whitespace)),
        /[xX][0-9a-fA-F]+;/))),
  permissive: token(/\\./),
};

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
  permissive: token(repeat1(common.symbol_element)),
  r7rs:
    token(seq(
      "|",
      repeat(
        choice(
          /[^\|\\]+/,
          /\\[xX][0-9a-fA-F]+;/,
          /\\[abtnr]/,
          "\\|")),
      "|")),
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

  const naninf = choice("nan.0", "inf.0");

  const ureal =
    seq(
      choice(
        uinteger,
        seq(uinteger, "/", uinteger),
        seq(decimal, mantissa_width)));
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
        "i"));

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

  const decimal =
    {
      2: "",
      8: "",
      10:
        choice(
          seq(uinteger, suffix),
          seq(".", repeat1(digit), suffix),
          seq(repeat1(digit), ".", repeat(digit), suffix)),
      16: "",
    }[n];

  const ureal =
    choice(
      uinteger,
      seq(uinteger, "/", uinteger),
      decimal);

  const real =
    choice(
      seq(sign, ureal),
      infnan);

  const complex =
    choice(
      real,
      seq(real, "@", real),
      seq(real, /[+-]/, ureal, "i"),
      seq(real, /[+-]/, "i"),
      seq(real, infnan, "i"),
      seq(/[+-]/, ureal, "i"),
      seq(infnan, "i"),
      seq(/[+-]/, "i"));

  const num =
    seq(
      prefix,
      complex);

  return num;
}

// number }}}

module.exports = {
  boolean,
  character,
  keyword,
  number,
  string,
  stringEscape,
  symbol,
};
