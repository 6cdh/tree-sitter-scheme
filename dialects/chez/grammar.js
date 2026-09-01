const {
  core,
  syntax,
} = require("../../grammar/index");

// Chez Scheme 10.4 reader: R6RS plus the external representations extracted
// in docs/chez-scheme-syntax.md.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // Chez directives change reader state. A static Tree-sitter language
  // represents the directives but accepts the R6RS/Chez union throughout the
  // file. Runtime-only length, range, graph, and record checks are also left
  // to Chez Scheme.

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
      $.shebang,
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
      $.fx_vector,
      $.fl_vector,
      $.stencil_vector,
      $.box,
      $.record,
      $.gensym,
      $.special_object,
      $.quote,
      $.quasiquote,
      $.unquote,
      $.unquote_splicing,
      $.syntax,
      $.quasisyntax,
      $.unsyntax,
      $.unsyntax_splicing,
      $.primitive,
      $.datum_label,
      $.datum_reference,
    ),

    comment: _ => syntax.comment.line.chez,
    block_comment: $ => syntax.comment.block(
      $.block_comment,
      value => prec(100, value),
    ),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    directive: _ => syntax.directive.chez,
    shebang: _ => syntax.comment.shebang,

    boolean: _ => syntax.boolean.r7rs,
    number: _ => syntax.number.chez,
    character: _ => syntax.character.chez,

    string: $ => syntax.string($.escape_sequence),
    escape_sequence: _ => syntax.stringEscape.chez,
    // When the complete number and identifier spellings are equally long,
    // this dialect lists number before symbol.
    symbol: _ => syntax.symbol.chez,

    list: $ => choice(
      syntax.list.round(choice($._token, $.dot)),
      syntax.list.square(choice($._token, $.dot)),
    ),
    dot: _ => ".",

    vector: $ => syntax.vector.hashLength(
      alias(/[0-9]+/, $.vector_length),
      $._token,
    ),
    byte_vector: $ => syntax.vector.vu8Length(
      alias(/[0-9]+/, $.vector_length),
      choice($._intertoken, $.number),
    ),
    fx_vector: $ => syntax.vector.vfx(
      alias(/[0-9]+/, $.vector_length),
      choice($._intertoken, $.number),
    ),
    fl_vector: $ => syntax.vector.vfl(
      alias(/[0-9]+/, $.vector_length),
      choice($._intertoken, $.number),
    ),
    stencil_vector: $ => syntax.vector.vs(
      alias(/[0-9]+/, $.stencil_mask),
      $._token,
    ),

    box: $ => syntax.box($._intertoken, $._datum),
    record: $ => syntax.record(
      $._intertoken,
      $._token,
      choice($.symbol, $.gensym),
    ),
    gensym: $ => choice(
      syntax.gensym.pretty($.symbol),
      syntax.gensym.unique($.symbol),
    ),
    special_object: _ => syntax.specialObject.chez,

    quote: $ => syntax.abbrev.quote($._intertoken, $._datum),
    quasiquote: $ => syntax.abbrev.quasiquote($._intertoken, $._datum),
    unquote: $ => syntax.abbrev.unquote($._intertoken, $._datum),
    unquote_splicing: $ => syntax.abbrev.unquoteSplicing($._intertoken, $._datum),
    syntax: $ => syntax.abbrev.syntax($._intertoken, $._datum),
    quasisyntax: $ => syntax.abbrev.quasisyntax($._intertoken, $._datum),
    unsyntax: $ => syntax.abbrev.unsyntax($._intertoken, $._datum),
    unsyntax_splicing: $ => syntax.abbrev.unsyntaxSplicing($._intertoken, $._datum),
    primitive: $ => syntax.primitive(
      alias(token(seq("#", optional(/[23]/), "%")), $.primitive_prefix),
      $.symbol,
    ),

    datum_label: $ => syntax.label.definition.chez(
      alias(/[0-9]+/, $.datum_label_id),
      $._intertoken,
      $._datum,
    ),
    datum_reference: $ => syntax.label.referenceWithField(
      alias(/[0-9]+/, $.datum_label_id),
    ),
  },
});
