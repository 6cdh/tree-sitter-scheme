===
identifier
===

foo
list->vector
+
-
...

---
(program
  (symbol)
  (symbol)
  (symbol)
  (symbol)
  (symbol))

===
identifier alphabet
===

a ! $ % & * / : < = > ? ^ _ ~
a0 a+ a- a. a@

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
  (symbol)
  (symbol)
  (symbol)
  (symbol))

===
dotted list
===

(a . b)
(a b . c)
((a) . #(b))

---
(program
  (list
    (symbol)
    (dot)
    (symbol))
  (list
    (symbol)
    (symbol)
    (dot)
    (symbol))
  (list
    (list
      (symbol))
    (dot)
    (vector
      (symbol))))

===
proper lists and vectors
===

()
(a b)
#()
#(a (b))

---
(program
  (list)
  (list
    (symbol)
    (symbol))
  (vector)
  (vector
    (symbol)
    (list
      (symbol))))

===
R5RS abbreviations
===

'a
`a
,a
,@a

---
(program
  (quote
    (symbol))
  (quasiquote
    (symbol))
  (unquote
    (symbol))
  (unquote_splicing
    (symbol)))

===
R5RS number tower
===

0 #d10 #e10 #i#x10 #b101 #o77 #xAf
1/2 #xA/B
1. 1.2 .5 1e2 1s-2
1+2i 1-2I +i -I 1@2
1## 1##.##

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
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number)
  (number))

===
nondecimal radix requires digits
===

#b

---
(program
  (ERROR))

===
adjacent number and identifier
===

123abc

---
(program
  (number)
  (symbol))

===
adjacent character and identifier
===

#\spaceX

---
(program
  (character)
  (symbol))

===
adjacent dot and datum
===

(a .b)

---
(program
  (list
    (symbol)
    (dot)
    (symbol)))
