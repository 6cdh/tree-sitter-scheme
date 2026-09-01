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
Chez character dispatch
===

#\space #\x41 #\X41 #\a4 #\000 #\( #\12 #\xy #\x41g

---

(program
  (character)
  (character)
  (character)
  (number)
  (character)
  (number)
  (character)
  (character)
  (character)
  (character)
  (symbol)
  (character))

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
#16r1+1i #02r10 #x1|53

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
    length: (vector_length)
    (symbol)
    (symbol))
  (byte_vector
    (number)
    (number))
  (byte_vector
    length: (vector_length)
    (number))
  (fx_vector
    (number)
    (number))
  (fx_vector
    length: (vector_length)
    (number))
  (fl_vector
    (number)
    (number))
  (fl_vector
    length: (vector_length)
    (number))
  (stencil_vector
    mask: (stencil_mask)
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
    value: (number))
  (record
    name: (symbol)
    (number)
    (number))
  (record
    name: (gensym
      pretty: (symbol)
      unique: (symbol))
    (symbol))
  (gensym
    pretty: (symbol))
  (gensym
    pretty: (symbol)
    unique: (symbol))
  (quote
    (list
      (datum_label
        label: (datum_label_id)
        value: (list
          (symbol)))
      (dot)
      (datum_reference
        label: (datum_label_id))))
  (datum_label
    label: (datum_label_id)
    value: (list
      (symbol)
      (dot)
      (datum_reference
        label: (datum_label_id))))
  (primitive
    prefix: (primitive_prefix)
    name: (symbol))
  (primitive
    prefix: (primitive_prefix)
    name: (symbol))
  (primitive
    prefix: (primitive_prefix)
    name: (symbol))
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
    label: (datum_label_id)
    value: (list
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

===
Chez reader cases borrowed from upstream mats
===

#{pretty	unique} #{bar baz}
#\foo #\new #\bugsbunny #\x41 #\X41 #\401
.. ... .foo .5 @home foo'bar foo#t
#e#36rZZ #36r#eZZ #16r1+1i #36r1@1
#5(one two three) #8vfx(5 7 9) #2vfl(5.0 7.0) #5vs(x y)
'(#0=#[#{record uid} #1=(a b) #1#] . #0#)

---

(program
  (gensym
    pretty: (symbol)
    unique: (symbol))
  (gensym
    pretty: (symbol)
    unique: (symbol))
  (character)
  (character)
  (character)
  (character)
  (character)
  (number)
  (character)
  (symbol)
  (symbol)
  (symbol)
  (number)
  (symbol)
  (symbol)
  (quote
    (symbol))
  (symbol)
  (boolean)
  (number)
  (number)
  (number)
  (number)
  (vector
    length: (vector_length)
    (symbol)
    (symbol)
    (symbol))
  (fx_vector
    length: (vector_length)
    (number)
    (number)
    (number))
  (fl_vector
    length: (vector_length)
    (number)
    (number))
  (stencil_vector
    mask: (stencil_mask)
    (symbol)
    (symbol))
  (quote
    (list
      (datum_label
        label: (datum_label_id)
        value: (record
          name: (gensym
            pretty: (symbol)
            unique: (symbol))
          (datum_label
            label: (datum_label_id)
            value: (list
              (symbol)
              (symbol)))
          (datum_reference
            label: (datum_label_id))))
      (dot)
      (datum_reference
        label: (datum_label_id)))))

===
Chez reader rejects invalid two-name gensym spacing
===

#{ pretty unique}

---

(program
  (ERROR)
  (symbol)
  (symbol))

===
Backslash is ordinary inside bar groups
===

|a\| |\| |a\|\|

---

(program
  (symbol)
  (symbol)
  (symbol))

===
Number-like symbols keep the complete Chez token
===

1#% 1#λ 1#\q 1#|x| 32/#|foo| 1.0|53abc

---

(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol))

===
Adjacent mantissa-width numbers stay separate
===

1.0|53 #16r1|53

---

(program
  (number)
  (number))
