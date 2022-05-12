const INTRA_WHITERPACE = /[ \n\t\p{Zs}]/;
const LINE_ENDING = /\n|\r|(\r\n)|(\r\u{85})|\u2028|\u{85}|/;

const PREC = {
  first: 100,
  block_comment: 2,
  symbol: -1,
};

module.exports = grammar({
  name: "scheme",

  extras: $ => [
    // Unicode whitespace
    /[\r\n\t\f\v ]|\p{Zs}|\p{Zl}|\p{Zp}/,
    $.comment,

    // `block_comment` have to be placed here.
    // It's a workaround for 'no entry found for key' error,
    // see https://github.com/tree-sitter/tree-sitter/issues/768
    //
    // We also removed it from `$.comment` to avoid conflict.
    // Finally, we can't hide `block_comment`.
    // It means we have two comment now: `comment` and `block_comment`.
    $.block_comment,
    $.directive,
  ],

  rules: {
    program: $ => repeat($._datum),
    _datum: $ => choice($._simple_datum, $._compound_datum),

    comment: $ =>
      choice(
        token(seq(";", /.*/)),
        seq("#;", $._datum)),

    directive: $ =>
      seq("#!", $.symbol),

    block_comment: $ =>
      prec(PREC.block_comment,
        seq("#|",
          repeat(/./),
          prec(PREC.first, "|#"))),

    // simple datum {{{

    _simple_datum: $ =>
      choice(
        $.boolean,
        $.number,
        $.character,
        $.string,
        $.symbol),

    boolean: _ => choice("#t", "#f", "#T", "#F"),

    character: _ =>
      token(
        choice(
          "#\\space", "#\\newline",
          "#\\alarm", "#\\backspace",
          "#\\delete", "#\\esc",
          "#\\linefeed", "#\\page",
          "#\\return", "#\\space", "#\\tab", "#\\vtab",
          "#\\nul",
          seq("#\\x", /[0-9a-fA-F]+/),
          /#\\./)),

    string: $ =>
      seq(
        '"',
        repeat(
          choice(
            $.escape_sequence,
            token.immediate(prec(1, /[^"\\]/)))),
        '"'),
    escape_sequence: _ =>
      token.immediate(
        choice(
          seq("\\", /["\\abfnrtv]/),
          seq("\\", repeat(INTRA_WHITERPACE), LINE_ENDING, repeat(INTRA_WHITERPACE)),
          seq("\\x", /[0-9a-fA-F]+/, ";"))),

    number: _ =>
      token(
        choice(
          number_base(2),
          number_base(8),
          number_base(10),
          number_base(16))),

    symbol: _ => {
      const initial =
        choice(
          /[a-zA-Z!$%&*/:<=>?^_~]/,
          /\p{Co}/,
          /\p{Ll}|\p{Lm}|\p{Lo}|\p{Lt}|\p{Lu}/,
          /\p{Mn}|\p{Nl}|\p{No}/,
          /\p{Pc}|\p{Pd}/,
          /\p{Sc}|\p{Sk}|\p{Sm}|\p{So}/,
          /\p{Po}/,

          // codepoint range but tree-sitter doesn't support.
          // See https://unicode.org/Public/14.0.0/ucd/UnicodeData.txt
          // and search "first>".
          //
          // The codepoint range should not exceed \u{FFFF} because
          // tree-sitter doesn't support it.
          //
          // See Also https://github.com/tree-sitter/tree-sitter/issues/1432

          /[\u3400-\u4DBF]/, // Lo: CJK Ideograph Extension A
          /[\u4E00-\u9FFF]/, // Lo: CJK Ideograph
          /[\uAC00-\uD7A3]/, // Lo: Hangul Syllable
          /[\uE000-\uF8FF]/, // Co: Private Use

          seq("\\x", /[0-9a-fA-F]+/, ";"));

      const subsequent =
        choice(
          initial,
          /[0-9.@+-]/,
          /\p{Mc}|\p{Me}|\p{Nd}/);

      return token(prec(PREC.symbol,
        choice(
          "...",
          "+",
          "-",
          seq("->", repeat(subsequent)),
          seq(
            initial,
            repeat(subsequent)))));
    },

    // simple datum }}}

    // compound datum {{{

    _compound_datum: $ =>
      choice(
        $._special_form,
        $.abbreviation,
        $.list),

    list: $ =>
      choice(
        par(repeat($._datum)),
        par(seq(repeat1($._datum), /\\./, $._datum))),


    abbreviation: $ => choice(seq($._abbreviation_prefix, $._datum)),
    _abbreviation_prefix: _ => choice("'", "`", ",", ",@", "#'", "#`", "#,", "#,@"),

    _special_form: $ =>
      choice(
        $.vector,
        $.byte_vector),

    vector: $ => seq("#(", repeat($._datum), ")"),

    byte_vector: $ => seq("#vu8(", repeat($.number), ")"),
    // compound datum }}}
  },
});

function par(rule) {
  return choice(
    seq('(', rule, ')'),
    seq('[', rule, ']'),
    seq('{', rule, '}'));
}

function number_base(n) {
  const radixn = {
    2: choice("#b", "#B"),
    8: choice("#o", "#O"),
    10: choice("#d", "#D", ""),
    16: choice("#x", "#X"),
  };
  const digitsn = {
    2: /[01]/,
    8: /[0-7]/,
    10: /[0-9]/,
    16: /[0-9a-fA-F]/,
  };

  const exactness = optional(choice("#i", "#e", "#I", "#E"));
  const radix = radixn[n];
  const prefix = choice(seq(radix, exactness), seq(exactness, radix));

  const sign = optional(/[+-]/);
  const digits = digitsn[n];

  const exponent = /[eEsSfFdDlL]/;
  const suffix = optional(choice(
    seq(exponent, sign, repeat1(digitsn[10])),
    seq("|", repeat1(digitsn[10])),
  ));
  const uinteger = seq(repeat1(digits), repeat("#"));
  const decimal10 = choice(
    seq(uinteger, suffix),
    seq(".", repeat1(digits), repeat("#"), suffix),
    seq(repeat1(digits), ".", repeat(digits), repeat("#"), suffix),
    seq(repeat1(digits), repeat1("#"), ".", repeat("#"), suffix)
  );
  const decimal = {
    2: "",
    8: "",
    10: decimal10,
    16: "",
  };

  const ureal =
    seq(
      choice(
        uinteger,
        seq(uinteger, "/", uinteger),
        decimal[n]),
      suffix);
  const imag = choice("i", seq(ureal, "i"), "inf.0i", "nan.0i");
  const real = choice(seq(sign, ureal), "+nan.0", "-nan.0", "+inf.0", "-inf.0");
  const complex = choice(
    real,
    seq(real, "@", real),
    seq(optional(real), /[+-]/, imag)
  );

  return seq(prefix, complex);
}
