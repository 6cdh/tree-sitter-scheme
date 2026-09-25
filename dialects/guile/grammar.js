const {
  core,
  syntax,
} = require("../../grammar/index");

// GNU Guile 3.0.11 default reader syntax from
// docs/guile-scheme-syntax.md.
//
// The grammar selects default read options. It recognizes directives but does
// not apply their later state changes or run read-hash-extend callbacks.
// `#(` is the vector production, not a rank-1 array.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice(
      $._intertoken,
      $._datum,
    ),

    _intertoken: $ => choice(
      token(core.whitespace.guile),
      $.comment,
      $.block_comment,
      $.sexp_comment,
      $.script_comment,
      $.directive,
    ),

    _datum: $ => choice(
      $.array,
      $.bit_vector,
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

    comment: _ => token(syntax.comment.line.r5rs),
    block_comment: $ => syntax.comment.block(
      $.block_comment,
      value => prec(100, value),
    ),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    script_comment: _ => syntax.comment.guileScript(
      value => prec(100, value),
    ),
    directive: _ => syntax.directive.guile,

    // `#` stays outside the boolean name so `#f32(` can be an array.
    boolean: _ => syntax.boolean.r7rs,
    number: _ => token(syntax.number.guile),
    // A malformed long character name or overlong hex escape can recover as
    // a shorter character followed by another datum; lexical lookahead would
    // require a scanner, which this dialect does not use.
    character: _ => syntax.character.guile,
    string: $ => syntax.string($.escape_sequence),
    escape_sequence: _ => syntax.stringEscape.guile,
    // `#{...}#` stays structural: a token would take the last `}#`.
    symbol: $ => choice(
      token(syntax.symbol.guile),
      $._guile_extended_symbol,
    ),
    keyword: $ => syntax.keyword.hashColon(alias($._keyword_symbol, $.symbol)),
    _keyword_symbol: $ => choice(
      token(syntax.symbol.guile),
      $._guile_extended_symbol,
    ),
    _guile_extended_symbol: _ =>
      syntax.symbol.guileExtended(value => prec(100, value)),

    list: $ => choice(
      syntax.list.round(choice($._token, $.dot)),
      syntax.list.square(choice($._token, $.dot)),
    ),
    dot: _ => ".",

    vector: $ => syntax.vector.hash($._token),
    byte_vector: $ => syntax.vector.vu8($._token),
    // Keep the complete opening syntax in one token so `#f32(` beats `#f`.
    // The prefix field covers that complete token.
    array: $ => seq(
      field("prefix", alias(
        token(seq("#", syntax.vector.guileArrayPrefix, "(")),
        $.array_prefix,
      )),
      repeat(choice($._intertoken, $._datum)),
      ")",
    ),
    bit_vector: _ => syntax.vector.guileBitvector,
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
