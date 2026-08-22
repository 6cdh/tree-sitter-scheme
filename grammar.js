const {
  core,
  syntax,
} = require("./grammar/index");

// Frozen R5RS copy: dialects/r5rs/grammar.js. This default grammar may grow.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // R5RS 7.1.1 says identifiers, numbers, characters, and dot may be
  // terminated only by a delimiter: whitespace, (, ), ", or ;. This parser
  // does not enforce that. 123abc is a number then a symbol, which is useful
  // while editing. Formal syntax: docs/r5rs.pdf (section 7.1).

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

    // One lexical fragment is already a token. token(choice(...)) is for a
    // rule that composes several lexical fragments.
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
