===
Chez comments and directives
===

#!chezscheme #!r6rs #!fold-case #!no-fold-case
; line comment
#| outer #| nested |# comment |#
#; (ignored datum)

---

(program
  (directive)
  (directive)
  (directive)
  (directive)
  (comment)
  (block_comment
    (block_comment))
  (sexp_comment
    (list
      (symbol)
      (symbol))))

===
Chez booleans, characters, and strings
===

#true #FALSE #t #F
#\000 #\044 #\bel #\ls #\nel #\rubout #\vt #\vtab
"quote: \' octal: \141 standard: \x3bb;"

---

(program
  (boolean)
  (boolean)
  (boolean)
  (boolean)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (character)
  (string
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)))

===
Chez extended identifiers
===

0abc +++ .. @home { } |hit me!| escaped\|pipe a\ b \x3bb; 32/#

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
  (symbol))

===
Chez numbers
===

#36rZZ #2r1010 #o1.4 #b1e10 #x1e20
1/2 1.25 +nan.0 -inf.0 98## #e98##

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
  (number))

===
Chez vectors
===

#(a b) #3(a b) #vu8(1 2) #3vu8(1)
#vfx(1 2) #10vfx(2) #vfl(1.0 2.0) #10vfl(2.0)
#21vs(x y z)

---

(program
  (vector
    (symbol)
    (symbol))
  (vector
    (symbol)
    (symbol))
  (byte_vector
    (number)
    (number))
  (byte_vector
    (number))
  (fx_vector
    (number)
    (number))
  (fx_vector
    (number))
  (fl_vector
    (number)
    (number))
  (fl_vector
    (number))
  (stencil_vector
    (symbol)
    (symbol)
    (symbol)))

===
Chez compound and graph data
===

#&17 #[point 10 20] #[#{marble uid} blue]
#:pretty #{pretty unique}
'(#1=(a) . #1#) #0=(a . #0#)
#%car #2%car #3%car
#!eof #!bwp #!base-rtd
#! /usr/bin/scheme --script
#!/usr/bin/env scheme

---

(program
  (box
    (number))
  (record
    (symbol)
    (number)
    (number))
  (record
    (gensym
      (symbol)
      (symbol))
    (symbol))
  (gensym
    (symbol))
  (gensym
    (symbol)
    (symbol))
  (quote
    (list
      (datum_label
        (list
          (symbol)))
      (dot)
      (datum_reference)))
  (datum_label
    (list
      (symbol)
      (dot)
      (datum_reference)))
  (primitive
    (symbol))
  (primitive
    (symbol))
  (primitive
    (symbol))
  (special_object)
  (special_object)
  (special_object)
  (shebang)
  (shebang))

===
Graph mark allows intertoken before the datum
===

#1= (a)

---

(program
  (datum_label
    (list
      (symbol))))

===
Number-like identifiers may contain vertical bar
===

32/#|foo|

---

(program
  (symbol))

===
R7RS #u8 bytevectors are not Chez
===

#u8(1)

---

(program
  (vector
    (ERROR)
    (number)))

===
R6RS syntax abbreviations remain available
===

'a `a ,a ,@a #'a #`a #,a #,@a

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
