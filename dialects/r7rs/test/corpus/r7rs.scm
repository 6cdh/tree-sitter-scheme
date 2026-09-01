==================
R7RS intertokens
==================

#!fold-case
#!no-fold-case
; line comment
#| outer #| nested |# comment |#
#; (ignored datum)

---

(program
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
R7RS identifiers
==================

lambda list->vector + - ... ++ -- +@ +! +!. +..!$ .+ ..
|two words| || |two\x20;words| |\|\a\b\t\n\r\X0AF;|

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
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol))

==================
R7RS literals
==================

#t #F #TruE #FaLse
#\. #\alarm #\escape #\X03BB
"abc" "\a\b\t\n\r\"\\" "\X41;bc" "before\
  after"

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
  (string)
  (string
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
    (escape_sequence)))

==================
R7RS numbers
==================

#b101 #o77 #x01af 1/2 0.0 .5 1e3
#I#d+inf.0 #i#D10/99+99/1I #i#D10/99-0123.0E+1i

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

==================
R7RS compound data and labels
==================

()
(a b . c)
#(a (b))
#u8(0 1 #xff)
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
  (vector
    (symbol)
    (list
      (symbol)))
  (byte_vector
    (number)
    (number)
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
R6RS square lists are not R7RS
==================

[a]

---

(program
  (ERROR))

==================
Nondecimal radix requires digits
==================

#b

---

(program
  (ERROR))
