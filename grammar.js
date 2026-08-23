const {
  core,
  syntax,
} = require("./grammar/index");

// The default parser accepts the union of R5RS, R6RS, and R7RS reader syntax.
// Standard-specific parsers live under dialects/.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // Identifiers follow R5RS/R6RS/R7RS lexical syntax, so they cannot start
  // with a digit. R5RS 7.1.1 also requires a delimiter after a number; this
  // parser does not. 123app123 is therefore a number then a symbol, not one
  // identifier and not an error. Formal syntax: docs/r5rs.pdf (section 7.1).

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice(
      $._intertoken,
      $._datum,
    ),

    _intertoken: $ => choice(
      token(choice(
        core.whitespace.r6rs,
        core.whitespace.r7rs,
        core.whitespace.r5rs,
      )),
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
      $.syntax_quote,
      $.quasisyntax,
      $.unsyntax,
      $.unsyntax_splicing,
      $.datum_label,
      $.datum_reference,
    ),

    // R6RS line comments include the common R5RS/R7RS form and also stop at
    // the Unicode line endings recognized by the default whitespace rule.
    comment: _ => syntax.comment.line.r6rs,
    block_comment: $ => syntax.comment.block($.block_comment),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    directive: _ => token(choice(
      syntax.directive.r7rs,
      syntax.directive.r6rs,
    )),

    boolean: _ => token(choice(
      syntax.boolean.r7rs,
      syntax.boolean.r6rs,
      syntax.boolean.r5rs,
    )),
    number: _ => token(choice(
      syntax.number.r6rs,
      syntax.number.r7rs,
      syntax.number.r5rs,
    )),
    character: _ => token(choice(
      syntax.character.r6rs,
      syntax.character.r7rs,
      syntax.character.r5rs,
      syntax.character.steelScheme,
    )),

    string: $ => syntax.string($.escape_sequence),

    escape_sequence: _ => token(choice(
      syntax.stringEscape.r6rs,
      syntax.stringEscape.r7rs,
      syntax.stringEscape.r5rs,
    )),

    // R6RS identifiers contain the R5RS forms. This intentionally gives the
    // R6RS reading priority where the standards disagree: ->name is one R6RS
    // identifier, not the R5RS tokens - and >name.
    symbol: _ => token(choice(
      syntax.symbol.r6rs,
      syntax.symbol.r7rs,
      syntax.symbol.r5rs,
    )),

    // Dot is list punctuation, not a datum. Vectors keep only $._token.
    list: $ => choice(
      syntax.list.round(choice($._token, $.dot)),
      syntax.list.square(choice($._token, $.dot)),
    ),
    dot: _ => ".",
    vector: $ => syntax.vector.hash($._token),
    byte_vector: $ => choice(
      syntax.vector.vu8(choice($._intertoken, $.number)),
      syntax.vector.u8(choice($._intertoken, $.number)),
    ),

    quote: $ => syntax.abbrev.quote($._intertoken, $._datum),
    quasiquote: $ => syntax.abbrev.quasiquote($._intertoken, $._datum),
    unquote: $ => syntax.abbrev.unquote($._intertoken, $._datum),
    unquote_splicing: $ => syntax.abbrev.unquoteSplicing($._intertoken, $._datum),
    // `syntax` would make the Node binding generate a SyntaxNode subclass
    // that shadows its SyntaxNode base class during initialization.
    syntax_quote: $ => syntax.abbrev.syntax($._intertoken, $._datum),
    quasisyntax: $ => syntax.abbrev.quasisyntax($._intertoken, $._datum),
    unsyntax: $ => syntax.abbrev.unsyntax($._intertoken, $._datum),
    unsyntax_splicing: $ => syntax.abbrev.unsyntaxSplicing($._intertoken, $._datum),

    datum_label: $ => syntax.label.definition($._datum),
    datum_reference: _ => syntax.label.reference,
  },
});
