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
  chez_nondecimal_number_base(2),
  chez_nondecimal_number_base(8),
  chez_nondecimal_number_base(16),
  chez_arbitrary_radix_number());

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

// Body after a Chez radix/exactness prefix. `#b`/`#o`/`#x` floats and `#nr`
// share this shape; only the digit class changes. strnum allows `|` plus
// decimal digits after an integer or float. A ratio has no mantissa width:
// `#x1/2|53` is invalid.
function chez_number_body(digit) {
  const sign = optional(/[+-]/);
  const uinteger = repeat1(digit);
  const exponent = optional(seq(/[eEsSfFdDlL]/, sign, uinteger));
  const mantissaWidth = optional(seq("|", repeat1(/[0-9]/)));
  const ureal = choice(
    seq(uinteger, "/", uinteger),
    seq(".", uinteger, exponent, mantissaWidth),
    seq(uinteger, ".", repeat(digit), exponent, mantissaWidth),
    seq(uinteger, exponent, mantissaWidth));
  const real = seq(sign, ureal);

  return choice(
    real,
    seq(real, "@", real),
    seq(optional(real), /[+-]/, optional(ureal), /[iI]/));
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

  return seq(prefix, chez_number_body(digit));
}

// The token has number syntax, while Chez checks whether each digit belongs
// to the selected radix. The parser still permits prefix splitting when a
// token is malformed, as documented by the Chez corpus.
function chez_arbitrary_radix_number() {
  const exactness = /#[iIeE]/;
  const radix = /#0*(?:[2-9]|[12][0-9]|3[0-6])[rR]/;
  const prefix = choice(
    seq(radix, optional(exactness)),
    seq(optional(exactness), radix));

  return seq(prefix, chez_number_body(/[0-9A-Za-z]/));
}

module.exports = { number };
