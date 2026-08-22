const {
  core,
  syntax,
} = require("../../grammar/index");

// Frozen R5RS reader: section 7.1.1 tokens and 7.1.2 data, not 7.1.3
// expressions. Do not add R6RS, R7RS, or other extensions here. The default
// root grammar.js may grow. Formal syntax: docs/r5rs.pdf.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // R5RS 7.1.1 says identifiers, numbers, characters, and dot may be
  // terminated only by a delimiter: whitespace, (, ), ", or ;. This parser
  // does not enforce that. 123abc is a number then a symbol, which is useful
  // while editing.

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice(
      $._intertoken,
      $._datum,
    ),

    _intertoken: $ => choice(
      core.whitespace.r5rs,
      $.comment,
    ),

    _datum: $ => choice(
      $.boolean,
      $.number,
      $.character,
      $.string,
      $.symbol,
      $.list,
      $.vector,
      $.quote,
      $.quasiquote,
      $.unquote,
      $.unquote_splicing,
    ),

    comment: _ => syntax.comment.line.r5rs,

    boolean: _ => syntax.boolean.r5rs,
    number: _ => syntax.number.r5rs,
    character: _ => syntax.character.r5rs,

    string: $ => syntax.string($.escape_sequence),

    escape_sequence: _ => syntax.stringEscape.r5rs,
    symbol: _ => syntax.symbol.r5rs,

    // Dot is list punctuation, not a datum. Vectors keep only $._token.
    list: $ => syntax.list.round(choice($._token, $.dot)),
    dot: _ => ".",
    vector: $ => syntax.vector.hash($._token),

    quote: $ => syntax.abbrev.quote($._intertoken, $._datum),
    quasiquote: $ => syntax.abbrev.quasiquote($._intertoken, $._datum),
    unquote: $ => syntax.abbrev.unquote($._intertoken, $._datum),
    unquote_splicing: $ => syntax.abbrev.unquoteSplicing($._intertoken, $._datum),
  },
});
