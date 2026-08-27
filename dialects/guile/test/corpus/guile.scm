===
Guile whitespace
===

a	b
(a
b)

---

(program
  (symbol)
  (symbol)
  (list
    (symbol)
    (symbol)))

===
Guile comments
===

#! /usr/bin/guile -s
!#
; line comment
#| outer #| nested |# comment |#
#| empty nested comments: #|||||||# and #||||||||# |#

---

(program
  (script_comment)
  (comment)
  (block_comment
    (block_comment))
  (block_comment
    (block_comment)
    (block_comment)))

===
Guile directives
===

#!fold-case #!no-fold-case #!r6rs

---

(program
  (directive)
  (directive)
  (directive))

===
Guile datum comments
===

#; (ignored datum)

---

(program
  (sexp_comment
    (list
      (symbol)
      (symbol))))

===
Guile booleans
===

#true #FALSE #t #F
(#f1 #fa #Fa #t1 #tr #Tr #TrUe #TRUE)

---

(program
  (boolean)
  (boolean)
  (boolean)
  (boolean)
  (list
    (boolean)
    (number)
    (boolean)
    (symbol)
    (boolean)
    (symbol)
    (boolean)
    (number)
    (boolean)
    (symbol)
    (boolean)
    (symbol)
    (boolean)
    (boolean)))

===
Guile numbers
===

#b101 #o17 #xFF #e1.5 1/2 1+2i +inf.0
+INF.0 +NaN.0 +nan.00 15## 1s2 1+inf.0i

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
  (number)
  (number)
  (number)
  (number))

===
Guile characters
===

#\space #\newline #\x41 #\λ
#\nul #\alarm #\backspace #\tab #\linefeed #\vtab #\page #\return #\esc #\delete #\soh
#\( #\19 #\not-a-name #\SPACE #\null #\escape

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
  (character)
  (character)
  (character)
  (character))

===
Guile string escapes
===

"bar: \| nul: \0 paren: \( hex: \x7f unicode: \u0100 wide: \U010402"
"continued\
line standard: \n r6rs: \x3bb;"

---

(program
  (string
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence))
  (string
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)))

===
Guile symbols
===

plain +foo .foo +.foo ->name
1+ 123abc .e5 foo'bar foo#bar 1.0|53 inf.0

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
  (symbol)
  (symbol)
  (symbol))

===
Guile keywords
===

#:type #:+foo :prefix postfix:
:foo:bar foo:bar: foo::
#:   foo
#:#|x|#bar

---

(program
  (keyword
    name: (symbol))
  (keyword
    name: (symbol))
  (keyword
    name: (symbol))
  (keyword)
  (keyword
    name: (symbol))
  (keyword)
  (keyword)
  (keyword
    name: (symbol))
  (keyword
    (block_comment)
    name: (symbol)))

===
Guile lists and vectors
===

(a . b) [a . b] #(a)

---

(program
  (list
    (symbol)
    (dot)
    (symbol))
  (list
    (symbol)
    (dot)
    (symbol))
  (vector
    (symbol)))

===
Guile byte vectors
===

#vu8(3 4) #vu8() #vu8(0 255 127 128)

---

(program
  (byte_vector
    (number)
    (number))
  (byte_vector)
  (byte_vector
    (number)
    (number)
    (number)
    (number)))

===
Guile abbreviations
===

'a `b ,c ,@d #'e #`f #,g #,@h

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
Guile square lists
===

[]

---

(program
  (list))

===
Guile extended symbols
===

#{foo bar}# #{}# #{}}# #{}}}# #{{}}# #{a\x20;b}#
|foo bar| @ @@ foo' \:

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
  (symbol)
  (keyword))

===
Guile special objects and bit vectors
===

#nil #nIL #nilly #n= #n# #NIL #*1010 #*

---

(program
  (special_object)
  (special_object)
  (special_object)
  (special_object)
  (special_object)
  (reader_extension)
  (symbol)
  (bit_vector)
  (bit_vector))

===
Guile array shapes
===

#2((0 0) (1 1)) #3(()) #3:0:1:0() #3f64:0:1:0() #f64:3(1 2 3)

---

(program
  (array
    prefix: (array_prefix)
    (list
      (number)
      (number))
    (list
      (number)
      (number)))
  (array
    prefix: (array_prefix)
    (list))
  (array
    prefix: (array_prefix))
  (array
    prefix: (array_prefix))
  (array
    prefix: (array_prefix)
    (number)
    (number)
    (number)))

===
Guile typed arrays
===

#u8(1 2) #s16(1 2 3) #0f64(99) #0(99) #u32(1 2)

---

(program
  (array
    prefix: (array_prefix)
    (number)
    (number))
  (array
    prefix: (array_prefix)
    (number)
    (number)
    (number))
  (array
    prefix: (array_prefix)
    (number))
  (array
    prefix: (array_prefix)
    (number))
  (array
    prefix: (array_prefix)
    (number)
    (number)))

===
Guile shaped arrays
===

#c32(1+2i) #@2(a b) #2u32@2@3((1 2) (3 4)) #2:0:2()

---

(program
  (array
    prefix: (array_prefix)
    (number))
  (array
    prefix: (array_prefix)
    (symbol)
    (symbol))
  (array
    prefix: (array_prefix)
    (list
      (number)
      (number))
    (list
      (number)
      (number)))
  (array
    prefix: (array_prefix)))

===
Guile rank-one arrays
===

#u8@2(1 2) #u8:2(1 2) #1(a b c d e f g h i j k l)

---

(program
  (array
    prefix: (array_prefix)
    (number)
    (number))
  (array
    prefix: (array_prefix)
    (number)
    (number))
  (array
    prefix: (array_prefix)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)
    (symbol)))

===
Guile curly infix and neoteric source forms
===

#!curly-infix {n <= 5} f(x) f[a] h{z}
#!curly-infix-and-bracket-lists [a b]

---

(program
  (directive)
  (curly_expression
    (symbol)
    (symbol)
    (number))
  (symbol)
  (list
    (symbol))
  (symbol)
  (list
    (symbol))
  (symbol)
  (curly_expression
    (symbol))
  (directive)
  (list
    (symbol)
    (symbol)))

===
Guile directives are not script comments
===

#!r6rs
(define x 1)
!#

---

(program
  (directive)
  (list
    (symbol)
    (symbol)
    (number))
  (symbol))

===
Guile byte strings
===

#u8"bytes: \x41;"

---

(program
  (byte_string
    (escape_sequence)))

===
Guile dynamic reader extensions
===

#y(a)

---

(program
  (reader_extension)
  (list
    (symbol)))

===
Unknown hash objects remain errors
===

#1#

---

(program
  (ERROR))
