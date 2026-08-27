const {
  core,
  syntax,
} = require("../../grammar/index");

// R6RS reader: chapter 4 lexical syntax and datum syntax. The default root
// grammar.js also selects these rules as part of its R5RS and R6RS union.
// Formal syntax: docs/r6rs.pdf.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // Like the default parser, this dialect favors useful editor trees over
  // strict delimiter validation for identifiers and other lexical data.

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice(
      $._intertoken,
      $._datum,
    ),

    _intertoken: $ => choice(
      core.whitespace.r6rs,
      $.comment,
      $.block_comment,
      $.sexp_comment,
      $.directive,
    ),

    _datum: $ => choice(
      $.boolean,
      $.number,
      $.character,
      $.string,
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

    comment: _ => syntax.comment.line.r6rs,
    block_comment: $ => syntax.comment.block(
      $.block_comment,
      value => prec(100, value),
    ),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    directive: _ => syntax.directive.r6rs,

    boolean: _ => syntax.boolean.r6rs,
    number: _ => syntax.number.r6rs,
    character: _ => syntax.character.r6rs,

    string: $ => syntax.string($.escape_sequence),

    escape_sequence: _ => syntax.stringEscape.r6rs,
    symbol: _ => syntax.symbol.r6rs,

    list: $ => choice(
      syntax.list.round(choice($._token, $.dot)),
      syntax.list.square(choice($._token, $.dot)),
    ),
    dot: _ => ".",
    vector: $ => syntax.vector.hash($._token),
    byte_vector: $ => syntax.vector.vu8(choice($._intertoken, $.number)),

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
