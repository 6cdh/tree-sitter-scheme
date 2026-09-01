["(" ")" "[" "]" "{" "}"] @punctuation.bracket
(dot) @punctuation.delimiter

(number) @number
(character) @constant.builtin
(boolean) @constant.builtin
(special_object) @constant.builtin
(bit_vector) @constant.builtin
(array prefix: (array_prefix) @constant.builtin)
(symbol) @variable
(keyword) @constant
(keyword name: (symbol) @constant)

(string) @string
(byte_string) @string
(escape_sequence) @escape

[
  (comment)
  (block_comment)
  (sexp_comment)
  (script_comment)
  (directive)
] @comment
