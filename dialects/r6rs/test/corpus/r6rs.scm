===
R6RS comments and directive
===

#!r6rs
; line comment
#| outer #| nested |# comment |#
#; (ignored datum)

---

(program
  (directive)
  (comment)
  (block_comment
    (block_comment))
  (sexp_comment
    (list
      (symbol)
      (symbol))))

===
R6RS identifiers
===

lambda list->vector ->- + - ...
H\x65;llo \x3BB; λ V17a

---

(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol))

===
R6RS characters
===

#\a #\A #\λ
#\nul #\alarm #\backspace #\tab
#\linefeed #\newline #\vtab #\page
#\return #\esc #\space #\delete
#\xFF #\xff #\x03BB

---

(program
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character))

===
R6RS strings
===

"abc"
"\a\b\t\n\v\f\r\"\\"
"\x41;bc"
"before\
  after"
"before \  
  after"

---

(program
  (string)
  (string
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence))
  (string
    (escape_sequence))
  (string
    (escape_sequence))
  (string
    (escape_sequence)))

===
R6RS numbers
===

#X01AF #b101 #o77 1/2
100000|10 +nan.0 -INF.0 +I -i
#E#D+10000.1098|100-1000i

---

(program
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number))

===
R6RS compound data
===

()
(a b . c)
[a b . c]
#(a [b])
#vu8(0 1 #xff)

---

(program
  (list)
  (list
    (symbol)
    (symbol)
    (dot)
    (symbol))
  (list
    (symbol)
    (symbol)
    (dot)
    (symbol))
  (vector
    (symbol)
    (list
      (symbol)))
  (byte_vector
    (number)
    (number)
    (number)))

===
R6RS abbreviations
===

'a `a ,a ,@a
#'a #`a #,a #,@a

---

(program
  (quote
    (symbol))
  (quasiquote
    (symbol))
  (unquote
    (symbol))
  (unquote_splicing
    (symbol))
  (syntax
    (symbol))
  (quasisyntax
    (symbol))
  (unsyntax
    (symbol))
  (unsyntax_splicing
    (symbol)))

===
Nondecimal radix requires digits
===

#b

---

(program
  (ERROR))
