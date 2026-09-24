const {
  core,
  syntax,
} = require("../../grammar/index");

// CHICKEN Scheme 6.0.0 reader syntax from
// docs/chicken-scheme-syntax.md.
//
// As in the other maintained dialects, lexical fragments do not consume
// following delimiters. During editing, a malformed fixed-name token may parse
// as a known token followed by another datum. The corpus records this limit.

module.exports = grammar({
  name: "scheme",

  extras: _ => [],

  // Reader parameters control keywords, symbol escapes, case sensitivity,
  // and list brackets. This static grammar accepts the union of their
  // published modes throughout the file. It also accepts number vectors
  // registered by (chicken number-vector). CHICKEN performs value and
  // constructor checks at runtime.
  externals: $ => [
    // `#<<` is one named token. `#<#` start/content/hash/end are hidden so
    // interpolations remain grammar nodes while the scanner tracks exact line
    // boundaries. A nested here string is a datum inside an interpolation.
    // Open tags must fit Tree-sitter's 1024-byte serialized scanner state;
    // an opener that would overflow the complete nested stack is rejected.
    $.here_string,
    $._here_string_start,
    $._here_string_content,
    $._here_string_hash,
    $._here_string_hash_brace,
    $._here_string_end,
  ],

  rules: {
    // Keep the start rule first. Tree-sitter uses the first rule as the start.
    program: $ => repeat($._token),

    _token: $ => choice($._intertoken, $._datum),

    _intertoken: $ =>
      choice(
        token(core.whitespace.r7rs),
        $.comment,
        $.block_comment,
        $.sexp_comment,
        $.script_comment,
        $.directive),

    _datum: $ =>
      choice(
        $.boolean,
        $.number,
        $.character,
        $.string,
        $.symbol,
        $.keyword,
        $.special_object,
        $.dsssl_marker,
        $.list,
        $.vector,
        $.byte_vector,
        $.byte_string,
        $.number_vector,
        $.quote,
        $.quasiquote,
        $.unquote,
        $.unquote_splicing,
        $.datum_label,
        $.datum_reference,
        $.here_string,
        $.interpolated_here_string,
        $.foreign_declare,
        $.location_expr,
        $.cond_expand,
        $.srfi10_constructor),

    comment: _ => token(syntax.comment.line.r7rs),
    block_comment: $ =>
      syntax.comment.block(
        $.block_comment,
        value => prec(100, value)),
    sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
    script_comment: _ => syntax.comment.chickenShebang,
    directive: _ => syntax.directive.r7rs,

    // Both fragments expose `#` to the parser. Their tokenized bodies decide
    // whether `#f32(` starts a number vector or `#f` is a boolean.
    boolean: _ => syntax.boolean.r7rs,
    number: _ => token(syntax.number.r7rs),
    character: _ => syntax.character.chicken,

    string: $ => syntax.string($.escape_sequence),
    escape_sequence: _ => syntax.stringEscape.chicken,

    symbol: _ => token(syntax.symbol.chicken),
    keyword: $ =>
      choice(
        syntax.keyword.hashColon(alias($._keyword_symbol, $.symbol)),
        token(
          choice(
            syntax.keyword.chickenPrefix,
            syntax.keyword.chickenSuffix))),
    _keyword_symbol: _ => token(syntax.symbol.chickenKeywordName),

    special_object: _ => syntax.specialObject.chicken,
    dsssl_marker: _ => syntax.dssslMarker.chicken,

    list: $ =>
      choice(
        syntax.list.round(choice($._token, $.dot)),
        syntax.list.square(choice($._token, $.dot)),
        syntax.list.curly(choice($._token, $.dot))),
    dot: _ => ".",

    vector: $ => syntax.vector.hash($._token),
    byte_vector: $ =>
      syntax.vector.u8(
        choice(
          $._intertoken,
          $.number,
          $.character,
          $.string)),
    byte_string: $ => syntax.byteString.chicken($.escape_sequence),
    // The tag uses the published name. Keep `#` and `(` separate; see boolean.
    number_vector: $ =>
      seq(
        "#",
        field("tag", $.number_vector_tag),
        "(",
        repeat(
          choice(
            $._intertoken,
            $.number,
            $.character,
            $.string)),
        ")"),
    number_vector_tag: _ => syntax.numberVector.chickenTag,

    quote: $ => syntax.abbrev.quote($._intertoken, $._datum),
    quasiquote: $ => syntax.abbrev.quasiquote($._intertoken, $._datum),
    unquote: $ => syntax.abbrev.unquote($._intertoken, $._datum),
    unquote_splicing: $ => syntax.abbrev.unquoteSplicing($._intertoken, $._datum),

    datum_label: $ =>
      syntax.label.definition.r7rs(
        alias(/[0-9]+/, $.datum_label_id),
        $._datum),
    datum_reference: $ => syntax.label.reference(alias(/[0-9]+/, $.datum_label_id)),

    interpolated_here_string: $ =>
      seq(
        $._here_string_start,
        repeat(
          choice(
            $._here_string_content,
            $.here_string_escape,
            $.here_interpolation)),
        $._here_string_end),
    here_string_escape: $ => seq($._here_string_hash, "#"),
    here_interpolation: $ =>
      choice(
        seq(
          $._here_string_hash_brace,
          field("expression", $._datum),
          optional(field("format", $.here_string_format)),
          "}"),
        seq(
          $._here_string_hash,
          field("expression", $._datum))),
    // Includes a nested here-string's trailing LF: closing tags leave that
    // newline outside the datum so the enclosing context owns the line break.
    here_string_format: _ => token(/[^}]+/),

    foreign_declare: _ => syntax.foreignDeclare.chicken,
    location_expr: $ => syntax.locationExpr.chicken($._datum),
    cond_expand: $ => syntax.condExpand.chicken($._intertoken, $._datum),
    srfi10_constructor: $ => syntax.constructor.srfi10($._intertoken, $.symbol, $._token),
  },
});
