["(" ")"] @punctuation.bracket
(dot) @punctuation.delimiter

(number) @number
(character) @constant.builtin
(boolean) @constant.builtin
(symbol) @variable

(string) @string

(escape_sequence) @escape

(list
  .
  (symbol) @function)

((symbol) @operator
 (#match? @operator "^(\\+|-|\\*|/|=|>|<|>=|<=)$"))

(list
  .
  (symbol) @keyword
  (#match? @keyword
   "^(define-syntax|define|syntax-rules|letrec-syntax|let-syntax|letrec|let\\*|let|lambda|if|set!|begin|cond|case|else|=>|and|or|do|delay|quote|quasiquote|unquote-splicing|unquote)$"
   ))

(list
  .
  (symbol) @function.builtin
  (#match? @function.builtin
   "^(caar|cadr|call-with-input-file|call-with-output-file|cdar|cddr|list|open-input-file|open-output-file|with-input-from-file|with-output-to-file|\\*|\\+|-|/|<|<=|=|>|>=|abs|acos|angle|append|apply|asin|assoc|assq|assv|atan|boolean\\?|caaaar|caaadr|caaar|caadar|caaddr|caadr|cadaar|cadadr|cadar|caddar|cadddr|caddr|call-with-current-continuation|call-with-values|car|cdaaar|cdaadr|cdaar|cdadar|cdaddr|cdadr|cddaar|cddadr|cddar|cdddar|cddddr|cdddr|cdr|ceiling|char->integer|char-alphabetic\\?|char-ci<=\\?|char-ci<\\?|char-ci=\\?|char-ci>=\\?|char-ci>\\?|char-downcase|char-lower-case\\?|char-numeric\\?|char-ready\\?|char-upcase|char-upper-case\\?|char-whitespace\\?|char<=\\?|char<\\?|char=\\?|char>=\\?|char>\\?|char\\?|close-input-port|close-output-port|complex\\?|cons|cos|current-input-port|current-output-port|denominator|display|dynamic-wind|eof-object\\?|eq\\?|equal\\?|eqv\\?|eval|even\\?|exact->inexact|exact\\?|exp|expt|floor|for-each|force|gcd|imag-part|inexact->exact|inexact\\?|input-port\\?|integer->char|integer\\?|interaction-environment|lcm|length|list->string|list->vector|list-ref|list-tail|list\\?|load|log|magnitude|make-polar|make-rectangular|make-string|make-vector|map|max|member|memq|memv|min|modulo|negative\\?|newline|not|null-environment|null\\?|number->string|number\\?|numerator|odd\\?|output-port\\?|pair\\?|peek-char|positive\\?|procedure\\?|quotient|rational\\?|rationalize|read|read-char|real-part|real\\?|remainder|reverse|round|scheme-report-environment|set-car!|set-cdr!|sin|sqrt|string|string->list|string->number|string->symbol|string-append|string-ci<=\\?|string-ci<\\?|string-ci=\\?|string-ci>=\\?|string-ci>\\?|string-copy|string-fill!|string-length|string-ref|string-set!|string<=\\?|string<\\?|string=\\?|string>=\\?|string>\\?|string\\?|substring|symbol->string|symbol\\?|tan|transcript-off|transcript-on|truncate|values|vector|vector->list|vector-fill!|vector-length|vector-ref|vector-set!|vector\\?|write|write-char|zero\\?)$"
   ))

(quote
  _ @constant)

(quote
  (_ _* @constant))

(quote
  (_ (_ _* @constant)))

(quote
  (_ (_ (_ _* @constant))))

(comment) @comment
