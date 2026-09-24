==================
CHICKEN intertokens
==================

#! /usr/bin/csi -s
#!fold-case #!no-fold-case
; line comment
#| outer #| nested |# comment |#
#; (ignored datum)

---

(program
  (script_comment)
  (directive)
  (directive)
  (comment)
  (block_comment
    (block_comment))
  (sexp_comment
    (list
      (symbol)
      (symbol))))

==================
CHICKEN R7RS literals and numbers
==================

#t #F #TruE #FaLse
#b101 #o17 #xFF #e1.5 1/2 1+2i +inf.0 -nan.0

---

(program
  (boolean)
  (boolean)
  (boolean)
  (boolean)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number))

==================
CHICKEN characters and string escapes
==================

#\space #\Space #\linefeed #\LINEFEED #\nul #\vtab #\page #\esc
#\x3bb #\X3bb #\u03bb #\U0001f600
"\a\b\t\n\r\"\\\v\f\|\'\x41;\u03bb\U0001f600\101"
"before\
  after"

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
  (string
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
    (escape_sequence)
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
    (escape_sequence)))

==================
CHICKEN symbols and keyword modes
==================

plain foo:bar |quoted symbol| + - ...
#:always suffix: :prefix : #:|| :|prefix name|

---

(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (keyword
    name: (symbol))
  (keyword)
  (keyword)
  (symbol)
  (keyword
    name: (symbol))
  (keyword))

==================
CHICKEN lists, vectors, abbreviations, and labels
==================

() [a b . c] {d e}
#(a 1)
'a `(1 ,2 ,@3)
#0=(a . #0#)

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
    (symbol))
  (vector
    (symbol)
    (number))
  (quote
    (symbol))
  (quasiquote
    (list
      (number)
      (unquote
        (number))
      (unquote_splicing
        (number))))
  (datum_label
    label: (datum_label_id)
    (list
      (symbol)
      (dot)
      (datum_reference
        label: (datum_label_id)))))

==================
CHICKEN byte and number vectors
==================

#u8(1 #\A "BC")
#u8"ABC\x41;"
#f #u16(1 2) #s8(3) #f32(1.0) #c128(3+4i)
#u32() #u64() #s16() #s32() #s64() #f64() #c64()

---

(program
  (byte_vector
    (number)
    (character)
    (string))
  (byte_string
    (escape_sequence))
  (boolean)
  (number_vector
    tag: (number_vector_tag)
    (number)
    (number))
  (number_vector
    tag: (number_vector_tag)
    (number))
  (number_vector
    tag: (number_vector_tag)
    (number))
  (number_vector
    tag: (number_vector_tag)
    (number))
  (number_vector
    tag: (number_vector_tag))
  (number_vector
    tag: (number_vector_tag))
  (number_vector
    tag: (number_vector_tag))
  (number_vector
    tag: (number_vector_tag))
  (number_vector
    tag: (number_vector_tag))
  (number_vector
    tag: (number_vector_tag))
  (number_vector
    tag: (number_vector_tag)))

==================
CHICKEN boolean and number-vector shared prefix
==================

#f #false #f32(1.0) #f32()

---

(program
  (boolean)
  (boolean)
  (number_vector
    tag: (number_vector_tag)
    (number))
  (number_vector
    tag: (number_vector_tag)))

==================
CHICKEN special objects and hash dispatch forms
==================

#!eof #!bwp #!optional #!rest #!key
#>int x = 1;<#
#$(foreign-value)
#+feature (enabled)
#,(point 1 2)

---

(program
  (special_object)
  (special_object)
  (dsssl_marker)
  (dsssl_marker)
  (dsssl_marker)
  (foreign_declare)
  (location_expr
    target: (list
      (symbol)))
  (cond_expand
    feature: (symbol)
    body: (list
      (symbol)))
  (srfi10_constructor
    name: (symbol)
    (number)
    (number)))

==================
CHICKEN here-documents use their opening tags
==================

#<<END
plain text
not END
END
#<#DONE
value: #(+ 1 2)
DONE

---

(program
  (here_string)
  (interpolated_here_string
    (here_interpolation
      expression: (list
        (symbol)
        (number)
        (number)))))

==================
CHICKEN interpolated here-strings parse substitutions
==================

#<#EOF
This is a simple string with an embedded `##' character
and substituted expressions: (+ three 99) ==> #(+ three 99)
(three is "#{three}")
EOF
#<#FMT
#{x ~A}
FMT
#<#EMPTY
EMPTY
#<#END
#(x)END
END

---

(program
  (interpolated_here_string
    (here_string_escape)
    (here_interpolation
      expression: (list
        (symbol)
        (symbol)
        (number)))
    (here_interpolation
      expression: (symbol)))
  (interpolated_here_string
    (here_interpolation
      expression: (symbol)
      format: (here_string_format)))
  (interpolated_here_string)
  (interpolated_here_string
    (here_interpolation
      expression: (list
        (symbol)))))

==================
CHICKEN here-document may end at EOF
==================

#<<MISSING
text without a terminator

---

(program
  (here_string))

==================
CHICKEN interpolated here-document may end at EOF
==================

#<#MISSING
no terminator

---

(program
  (interpolated_here_string))

==================
CHICKEN interpolated here-string may contain a nested here-document
==================

#<#OUTER
#{#<<INNER
hello
INNER
}
OUTER
#<#WRAP
#(#<#INNER
#x
INNER
)
WRAP

---

(program
  (interpolated_here_string
    (here_interpolation
      expression: (here_string)
      format: (here_string_format)))
  (interpolated_here_string
    (here_interpolation
      expression: (list
        (interpolated_here_string
          (here_interpolation
            expression: (symbol)))))))

==================
Nested here-document closers do not start terminator lines
==================

#<#OUTER
#(#<<INNER
x
INNER
)OUTER
(+ 1 2)
OUTER
#<#END
#{#<<I
x
I
}END
(+ 3 4)
END

---

(program
  (interpolated_here_string
    (here_interpolation
      expression: (list
        (here_string))))
  (interpolated_here_string
    (here_interpolation
      expression: (here_string)
      format: (here_string_format))))

==================
Terminator-like prefixes preserve interpolation boundaries
==================

#<#X
#fooX
X
#<##T
#X
#T
#<#ab#c
ab#x
ab#c

---

(program
  (interpolated_here_string
    (here_interpolation
      expression: (symbol)))
  (interpolated_here_string
    (here_interpolation
      expression: (symbol)))
  (interpolated_here_string
    (here_interpolation
      expression: (symbol))))

==================
Hex bytevectors are rejected
==================

#u8{deadbeef}

---

(program
  (ERROR)
  (list
    (symbol)))

==================
Embedded vertical-line segments do not form one symbol
==================

a|two words|z

---

(program
  (symbol)
  (symbol)
  (symbol))

==================
Nested number-vector elements are rejected
==================

#u8((2) #s16(4) #u8(5))

---

(program
  (byte_vector
    (ERROR))
  (number_vector
    tag: (number_vector_tag)
    (number))
  (byte_vector
    (number))
  (ERROR))

==================
Unknown bang token is rejected
==================

#!unknown

---

(program
  (ERROR))

==================
Fixed-name token boundaries use editor recovery
==================

#!eofx #\spacefoo

---

(program
  (special_object)
  (symbol)
  (character)
  (symbol))

==================
Quoted nested here-strings preserve the outer terminator line
==================

#<#OUTER
#'#<<INNER
x
INNER
OUTER
(+ 1 2)
#<#OUTER
#'#<#INNER
x
INNER
OUTER
(+ 3 4)

---

(program
  (interpolated_here_string
    (here_interpolation
      expression: (quote
        (here_string))))
  (list (symbol) (number) (number))
  (interpolated_here_string
    (here_interpolation
      expression: (quote
        (interpolated_here_string))))
  (list (symbol) (number) (number)))

==================
Empty nested tags preserve the outer terminator line
==================

#<#OUTER
#'#<#
x

OUTER
(+ 1 2)

---

(program
  (interpolated_here_string
    (here_interpolation
      expression: (quote
        (interpolated_here_string))))
  (list (symbol) (number) (number)))

==================
Foreign declarations stop at overlapping closing markers
==================

#><<#
(+ 1 2)
#><<<#
(+ 3 4)
#>a << b < c<#
(+ 5 6)

---

(program
  (foreign_declare)
  (list (symbol) (number) (number))
  (foreign_declare)
  (list (symbol) (number) (number))
  (foreign_declare)
  (list (symbol) (number) (number)))

==================
Empty outer tags close before following forms
==================

#<#
body

(+ 1 2)
#<#
#'#<<INNER
x
INNER

(+ 3 4)

---

(program
  (interpolated_here_string)
  (list (symbol) (number) (number))
  (interpolated_here_string
    (here_interpolation
      expression: (quote
        (here_string))))
  (list (symbol) (number) (number)))
