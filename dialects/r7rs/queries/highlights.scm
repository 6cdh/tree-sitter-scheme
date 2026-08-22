["(" ")"] @punctuation.bracket
(dot) @punctuation.delimiter

(number) @number
(character) @constant.builtin
(boolean) @constant.builtin
(symbol) @variable
(datum_reference) @variable

(string) @string
(escape_sequence) @escape

[
  (comment)
  (block_comment)
  (sexp_comment)
  (directive)
] @comment
