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

#!fold-case #!no-fold-case #!curly-infix

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
#\( #\10 #\null #\escape

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
  (character))

===
Guile string escapes
===

"bar: \| nul: \0 paren: \( hex: \x7f unicode: \u0100 wide: \U010402"
"continued\
line standard: \n hex: \x3b"

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

#:type #:+ #:foo:bar #:: #:|

---

(program
  (keyword
    name: (symbol))
  (keyword
    name: (symbol))
  (keyword
    name: (symbol))
  (keyword
    name: (symbol))
  (keyword
    name: (symbol)))

===
Default Guile colon forms are symbols
===

: :prefix postfix: :foo:bar foo:bar:

---

(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol))

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
Guile extended symbols and ordinary bars
===

#{foo bar}# #{}# #{}}# #{}}}# #{{}}# #{a\x20;b}#
| |foo bar|

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
  (symbol))

===
Guile special objects and bit vectors
===

#nil #*1010 #*

---

(program
  (special_object)
  (bit_vector)
  (bit_vector))

===
Guile special-object dispatch is lowercase
===

#NIL #nIL

---

(program
  (ERROR)
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

#u8@2(1 2) #u8:2(1 2) #2u8@+1:2(1 2) #1(a b c d e f g h i j k l) #a("x")

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
    (symbol))
  (array
    prefix: (array_prefix)
    (string)))

===
Default Guile braces stay inside symbols
===

{n + 1} f(x) f[a] h{z}

---

(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (list
    (symbol))
  (symbol)
  (list
    (symbol))
  (symbol))

===
Reader directives do not change this static grammar
===

#!curly-infix {n + 1}

---

(program
  (directive)
  (symbol)
  (symbol)
  (symbol))

===
Guile character boundary limitation
===

#\garbage #\x123456789

---

(program
  (character)
  (symbol)
  (character)
  (number))

===
Guile script comments
===

#!unknown-name
script body
!#

---

(program
  (script_comment))

===
Default Guile rejects byte-string prefixes
===

#u8"abc"

---

(program
  (ERROR)
  (string))

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

===
Unpublished hash-bang names are not directives
===

#!r6rs

---

(program
  (script_comment
    (MISSING "!#")))
