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
-nan.0 #i+inf.0 #x-inf.0 #i#x+nan.0 15## 1s2 1+inf.0i

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

plain lambda <= foo:bar abc123 + - ...

---

(program
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

#:type #:+ :prefix postfix:
:foo:bar foo:bar: foo:: #:: :|bar baz| :#{two words}#

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
    name: (symbol))
  (keyword
    name: (symbol)))

===
Guile keyword names are contiguous
===

#: name

---

(program
  (ERROR))

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

#vu8(3 4) #vu8() #vu8(#t "x" (a))

---

(program
  (byte_vector
    (number)
    (number))
  (byte_vector)
  (byte_vector
    (boolean)
    (string)
    (list
      (symbol))))

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
|foo bar| |\0\f\v\(\u0041\U000041\x41;|

---

(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol))

===
Guile special objects and bit vectors
===

#nil #nIL #*1010 #*

---

(program
  (special_object)
  (special_object)
  (bit_vector)
  (bit_vector))

===
Guile special-object dispatch is lowercase
===

#NIL

---

(program
  (ERROR))

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

#u8@2(1 2) #u8:2(1 2) #2u8@+1:2(1 2) #1(a b c d e f g h i j k l)

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
Guile script comments and directives
===

#!unknown-name
script body
!#
#!r6rs
(define x 1)

---

(program
  (script_comment)
  (directive)
  (list
    (symbol)
    (symbol)
    (number)))

===
Guile byte strings
===

#u8"bytes: \a\b\t\n\r\"\|\x00041;\
  continued"

---

(program
  (byte_string
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)))

===
Guile byte strings reject non-SRFI-207 content
===

#u8"\0" #u8"é"

---

(program
  (byte_string
    (ERROR))
  (byte_string
    (ERROR)))

===
Reader extensions need runtime registration
===

#y(a)

---

(program
  (ERROR)
  (list
    (symbol)))

===
Unknown hash objects remain errors
===

#1#

---

(program
  (ERROR))
