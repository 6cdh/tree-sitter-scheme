const {
  core,
  syntax,
} = require("../../grammar/index");

// R7RS-small reader: sections 7.1.1 tokens and 7.1.2 data, not 7.1.3
// expressions. Formal syntax: docs/r7rs.pdf.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // Case-folding directives are represented in the tree. A static parser
  // cannot apply their stateful normalization to later identifiers.
  // Like the other dialects, this parser favors useful editor trees over
  // strict delimiter and byte-range validation.

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice(
      $._intertoken,
      $._datum,
    ),

    _intertoken: $ => choice(
      core.whitespace.r7rs,
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
      $.datum_label,
      $.datum_reference,
    ),

    comment: _ => syntax.comment.line.r5rs,
    block_comment: $ => syntax.comment.block($.block_comment),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    directive: _ => syntax.directive.r7rs,

    boolean: _ => syntax.boolean.r7rs,
    number: _ => syntax.number.r7rs,
    character: _ => syntax.character.r7rs,

    string: $ => syntax.string($.escape_sequence),

    escape_sequence: _ => syntax.stringEscape.r7rs,
    symbol: _ => syntax.symbol.r7rs,

    list: $ => syntax.list.round(choice($._token, $.dot)),
    dot: _ => ".",
    vector: $ => syntax.vector.hash($._token),
    byte_vector: $ => syntax.vector.u8(choice($._intertoken, $.number)),

    quote: $ => syntax.abbrev.quote($._intertoken, $._datum),
    quasiquote: $ => syntax.abbrev.quasiquote($._intertoken, $._datum),
    unquote: $ => syntax.abbrev.unquote($._intertoken, $._datum),
    unquote_splicing: $ => syntax.abbrev.unquoteSplicing($._intertoken, $._datum),

    datum_label: $ => syntax.label.definition($._datum),
    datum_reference: _ => syntax.label.reference,
  },
});
