["(" ")" "[" "]" "{" "}"] @punctuation.bracket
(dot) @punctuation.delimiter

(number) @number
(number_vector_tag) @type
(datum_label_id) @number
(character) @constant.builtin
(boolean) @constant.builtin
(special_object) @constant.builtin
(dsssl_marker) @constant.builtin
(symbol) @variable
(keyword) @constant
(keyword name: (symbol) @constant)
(datum_reference) @variable

[
  (string)
  (byte_string)
  (here_string)
  (interpolated_here_string)
  (here_string_format)
  (foreign_declare)
] @string
[
  (escape_sequence)
  (here_string_escape)
] @escape

[
  (comment)
  (block_comment)
  (sexp_comment)
  (script_comment)
  (directive)
] @comment
