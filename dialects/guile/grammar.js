const {
  core,
  syntax,
} = require("../../grammar/index");

// GNU Guile 3.0.11 reader syntax extracted in
// docs/guile-scheme-syntax.md.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // Guile reader options and directives change reader behavior. This static
  // language accepts the published option-controlled syntax as a union for
  // the whole file. Runtime state and value checks stay in Guile.

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice(
      $._intertoken,
      $._datum,
    ),

    _intertoken: $ => choice(
      core.whitespace.guile,
      $.comment,
      $.block_comment,
      $.sexp_comment,
      $.script_comment,
      $.directive,
    ),

    _datum: $ => choice(
      $.array,
      $.bit_vector,
      $.byte_string,
      $.special_object,
      $.boolean,
      // Equal-length number and symbol tokens (123, 15##, +inf.0) are a
      // lexer tie. Tree-sitter prefers the token discovered first, so
      // number must stay before symbol here. Parse prec() on the number
      // rule does not set that preference.
      $.number,
      $.character,
      $.string,
      $.keyword,
      $.symbol,
      $.list,
      $.curly_expression,
      $.vector,
      $.byte_vector,
      $.quote,
      $.quasiquote,
      $.unquote,
      $.unquote_splicing,
      $.syntax,
      $.quasisyntax,
      $.unsyntax,
      $.unsyntax_splicing,
    ),

    comment: _ => syntax.comment.line.guile,
    block_comment: $ => syntax.comment.block(
      $.block_comment,
      value => prec(100, value),
    ),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    script_comment: _ => syntax.comment.guileScript(
      value => prec(100, value),
    ),
    directive: _ => syntax.directive.guile,

    boolean: _ => syntax.boolean.r7rs,
    number: _ => syntax.number.guile,
    character: _ => syntax.character.guile,

    string: $ => syntax.string($.escape_sequence),
    escape_sequence: _ => syntax.stringEscape.guile,
    symbol: _ => choice(
      syntax.symbol.guile,
      syntax.symbol.guileVertical,
      syntax.symbol.guileExtended(value => prec(100, value)),
    ),
    // Prefix names use r5rs identifiers so a leading colon is allowed.
    // Ordinary symbols omit colon from initial so :NAME can be a prefix
    // keyword. Postfix is one leaf token.
    keyword: $ => choice(
      syntax.keyword.hashColon(alias($._keyword_symbol, $.symbol)),
      syntax.keyword.colon(alias($._keyword_symbol, $.symbol)),
      token(prec(1, syntax.keyword.guilePostfix)),
    ),
    _keyword_symbol: _ => choice(
      syntax.symbol.r5rs,
      syntax.symbol.guileVertical,
      syntax.symbol.guileExtended(value => prec(100, value)),
    ),

    list: $ => choice(
      syntax.list.round(choice($._token, $.dot)),
      syntax.list.square(choice($._token, $.dot)),
    ),
    curly_expression: $ =>
      syntax.list.curly(choice($._token, $.dot)),
    dot: _ => ".",

    vector: $ => syntax.vector.hash($._token),
    byte_vector: $ => syntax.vector.vu8($._token),
    // Keep the complete opening syntax in one token so `#f32(` beats `#f`
    // and `#u8(` beats `#u8"`. The prefix field covers that complete token.
    array: $ => seq(
      field("prefix", alias(
        token(seq("#", syntax.vector.guileArrayPrefix, "(")),
        $.array_prefix,
      )),
      repeat(choice($._intertoken, $._datum)),
      ")",
    ),
    bit_vector: _ => syntax.vector.guileBitvector,
    byte_string: $ => syntax.byteString.srfi207(
      alias(syntax.stringEscape.srfi207, $.escape_sequence),
    ),
    special_object: _ => syntax.specialObject.guile,

    quote: $ => syntax.abbrev.quote($._intertoken, $._datum),
    quasiquote: $ => syntax.abbrev.quasiquote($._intertoken, $._datum),
    unquote: $ => syntax.abbrev.unquote($._intertoken, $._datum),
    unquote_splicing: $ => syntax.abbrev.unquoteSplicing($._intertoken, $._datum),
    syntax: $ => syntax.abbrev.syntax($._intertoken, $._datum),
    quasisyntax: $ => syntax.abbrev.quasisyntax($._intertoken, $._datum),
    unsyntax: $ => syntax.abbrev.unsyntax($._intertoken, $._datum),
    unsyntax_splicing: $ => syntax.abbrev.unsyntaxSplicing($._intertoken, $._datum),
  },
});
