# Guile Scheme Reader Syntax

## Scope and sources

This document specifies GNU Guile 3.0.11 reader syntax as compact formal
productions. It does not catalog implementation behavior. Special forms
such as `lambda` and `if` are not reader syntax. See
[Syntax Summary][syntax-summary].

Guile inherits the R5RS reader. The formal core is R5RS section 7.1.
The Reference Manual documents additional datum syntax but does not
publish a single reader grammar. Remaining rules are reconstructed
from the pages named under Sources.

When published wording is unclear, GNU Guile 3.0.11 `read` was used
once to verify it, and that interpretation is written into the
productions.

### Target, inheritance, and default reader

The inherited standard is R5RS. Default `(read-options)` is:

```text
(square-brackets keywords #f positions)
```

| Option | Default | Effect on the default reader |
| --- | --- | --- |
| `square-brackets` | on | `[` and `]` are list delimiters |
| `keywords` | `#f` | only `#:NAME` is a keyword |
| `case-insensitive` | off | ordinary symbol characters keep their case |
| `r6rs-hex-escapes` | off | string `\x` is exactly two hex digits |
| `hungry-eol-escapes` | off | a backslash-newline keeps the following spaces |
| `curly-infix` | off | `{` and `}` are ordinary symbol characters |
| `r7rs-symbols` | off | `\|` is an ordinary symbol character |
| `bytestrings` | off | `#u8"..."` is not a byte string |
| `positions` | on | source properties; no token syntax |

`keywords` may also be `'prefix` or `'postfix`. Those two styles are
mutually exclusive. See [Optional reader syntax](#optional-reader-syntax).

`bytestrings` is a GNU Guile 3.0.11 addition. NEWS,
[Scheme Read][scheme-read], and [SRFI-207][srfi-207] document it.

[Scheme Read][scheme-read] documents these per-port directives:
`#!fold-case`, `#!no-fold-case`, `#!curly-infix`, and
`#!curly-infix-and-bracket-lists`. They are atmosphere, not datums.

### Sources

- Inherited formal core: R5RS section 7.1 in `docs/r5rs.txt`
- [Scheme Read][scheme-read]: read options and per-port directives
- Reader pages: [expression syntax][expression-syntax],
  [comments][comments], [block comments][block-comments],
  [case sensitivity][case-sensitivity], [keyword syntax][keywords],
  [reader extensions][reader-extensions]
- Datum type pages: [booleans][booleans], [symbols][symbols],
  [strings][strings], [characters][characters], [numbers][numbers],
  [vectors][vectors], [bit vectors][bit-vectors], [arrays][arrays],
  [SRFI-4][uniform-vectors], [bytevectors][bytevectors], [Nil][nil]
- Optional syntax: [SRFI-88][srfi-88], [SRFI-105][srfi-105],
  [SRFI-62][srfi-62], [SRFI-207][srfi-207]
- GNU Guile 3.0.11 NEWS: `bytestrings`
- Manual menu: [Scheme Syntax][scheme-syntax]

Unclear published wording was also checked against GNU Guile 3.0.11
`ice-9/read.scm` at `f7e1255dbdcb755b4c8e7e0331384e4668ceb78f`. Extra
forms that `ice-9/read.scm` accepts are not syntax.

### Notation

Productions use R5RS BNF notation. `<thing>*` is zero or more.
`<thing>+` is one or more. `empty` is the empty string. `datum*` in
running text means zero or more datums with intertoken space between
them.

Concatenation in a production means concatenation in the input. For
example, `#:<symbol>` has no intertoken space. A production shows
`<intertoken space>` only where space is part of that form.

A section note marks each production as one of:

- **quoted:** copied from a named published grammar
- **adapted:** an inherited production with Guile terminals added or
  removed
- **reconstructed:** derived from published prose that is not a formal
  grammar

Productions describe the default reader unless a named option is on.
Default Guile symbols retain case. Boolean names and number prefixes
are case-insensitive. Character names use the lowercase spellings in
the [Characters][characters] tables. `<hex digit>` is `0`–`9` and
`a`–`f` in any case.

## Default reader syntax

Unchanged R5RS number and identifier productions are cited, not copied.

### Intertoken space

Adapted from R5RS 7.1.1. Nested `#|...|#` and `#!...!#` are
reconstructed from [Block Comments][block-comments] (SRFI-30). Datum
comments are SRFI-62. Directives are reconstructed from
[Scheme Read][scheme-read].

[Scheme Read][scheme-read] discards whitespace before a token but does
not list the characters. The verified set is space, tab, formfeed,
return, and newline.

```text
<intertoken space> --> <atmosphere>*
<atmosphere>       --> <whitespace> | <comment> | <directive>
<whitespace>       --> space | tab | formfeed | return | newline
<comment>          --> <line comment>
                    |  <block comment>
                    |  <datum comment>
                    |  <script comment>
<line comment>     --> ; <any character except newline or return>*
<block comment>    --> #| <nested block-comment body> |#
<datum comment>    --> #; <intertoken space> <datum>
<script comment>   --> #! <script comment body> !#
<directive>        --> #!fold-case
                    |  #!no-fold-case
                    |  #!curly-infix
                    |  #!curly-infix-and-bracket-lists
```

Datum comments are on by default: `#;` plus one datum. A block-comment
body may contain balanced nested block comments.

Directive names are the lowercase spellings printed in
[Scheme Read][scheme-read]. After the name, reading continues at the
next character. `#!fold-case` and `#!no-fold-case` toggle
`case-insensitive`. `#!curly-infix` turns `curly-infix` on.
`#!curly-infix-and-bracket-lists` turns `curly-infix` on and
`square-brackets` off.

If `#!` is followed by one of those names, the directive is atmosphere
and does not need `!#`. Any other text after `#!` is a script comment
and must end at `!#`.

### Delimiters and tokens

Adapted from R5RS 7.1.1. Square brackets are delimiters because
`square-brackets` is on by default.

```text
<delimiter> --> <whitespace> | ( | ) | [ | ] | " | ;
```

As in R5RS, a token that needs implicit termination (identifier,
number, character, or dot) may end at any `<delimiter>`, and need not
end at any other character. Default `{`, `}`, and `|` are ordinary
symbol characters.

### Datum

Reconstructed. `<byte string>` and `<curly infix>` are optional and are
omitted here.

```text
<datum> --> <simple datum> | <compound datum>
<simple datum> --> <boolean> | <number> | <character> | <string>
                |  <symbol> | <keyword> | <special object>
                |  <bitvector>
<compound datum> --> <list> | <vector> | <bytevector> | <array>
                  |  <abbreviation>
<abbreviation> --> <abbrev prefix> <intertoken space> <datum>
<abbrev prefix> --> ' | ` | , | ,@ | #' | #` | #, | #,@
```

`#'datum` reads as `(syntax datum)`, `` #`datum `` as `(quasisyntax
datum)`, `#,datum` as `(unsyntax datum)`, and `#,@datum` as
`(unsyntax-splicing datum)`.

Guile does not publish R6RS datum labels (`#n=` / `#n#`) or R6RS
mantissa-width syntax.

### Lists

Adapted from R5RS 7.1.2. Square brackets are included because
`square-brackets` is on by default.

```text
<list> --> ( <datum>* )
        |  ( <datum>+ . <datum> )
        |  [ <datum>* ]
        |  [ <datum>+ . <datum> ]
```

### Boolean

Reconstructed from [Booleans][booleans] (`#true` / `#false` as in
R7RS). The names are case-insensitive.

```text
<boolean> --> #t | #f | #true | #false
```

### Number

Finite numbers use the R5RS 7.1 integer, rational, real, and complex
productions. Optional prefixes are `#b`, `#o`, `#d`, `#x`, `#e`, and
`#i`, in any case, in either order.

Signed infinities and NaNs are reconstructed from
[Number Syntax][numbers]:

```text
<infnan> --> +inf.0 | -inf.0 | +nan.0 | -nan.0
```

The published spellings are those four signed forms, with exactly one
`0` after the point. They are numbers, not identifiers. They do not
take `#e`. A radix prefix follows the same prefix rules.

### Symbol

Ordinary symbols use the R5RS 7.1 identifier syntax. The extended form
is reconstructed from [Symbol Read Syntax][symbols]. That page does
not define the body; it runs to the first `}#`.

```text
<symbol> --> <r5rs identifier> | <extended symbol>
<extended symbol> --> #{ <extended symbol body> }#
```

An R5RS identifier may begin with `:`. With default `keywords` `#f`,
`:NAME` is a symbol.

### Keyword

Reconstructed from [Keyword Read Syntax][keywords]. With `keywords` at
`#f`, the only keyword spelling is `#:NAME`. There is no intertoken
space after `#:`.

```text
<keyword> --> #:<symbol>
```

`<symbol>` here is the default symbol syntax. The name after `#:` may
contain colons.

### Character

Reconstructed from [Characters][characters].

```text
<character> --> #\<any character>
             |  #\<character name>
             |  #\x<hex scalar digits>
             |  #\<octal digit>+
             |  #\<dotted circle><combining character>
```

The dotted circle is U+25CC and precedes the combining character.
`#\x` uses a lowercase `x` and one through eight hexadecimal digits.

Names from [Characters][characters]:

- Long: `nul`, `alarm`, `backspace`, `tab`, `linefeed`, `newline`,
  `vtab`, `page`, `return`, `esc`, `space`, `delete`
- R7RS alias: `escape`
- Remaining C0 short names: `soh`, `stx`, `etx`, `eot`, `enq`, `ack`,
  `bel`, `bs`, `ht`, `lf`, `vt`, `ff`, `cr`, `so`, `si`, `dle`, `dc1`,
  `dc2`, `dc3`, `dc4`, `nak`, `syn`, `etb`, `can`, `em`, `sub`, `fs`,
  `gs`, `rs`, `us`, `sp`
- Delete short: `del`
- Compatibility: `null`, `nl`, `np`

`nul` is also a C0 short name. `newline` and `linefeed` are the same
code point.

### String

Reconstructed from [String Syntax][strings]. This is the default
escape set. `r6rs-hex-escapes` and `hungry-eol-escapes` are optional.

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  \ <string escape>
<string escape> --> \ | " | <vertical line> | a | f | n | r | t | v | b | 0 | (
                 |  newline
                 |  x <hex digit> <hex digit>
                 |  u <hex digit> <hex digit> <hex digit> <hex digit>
                 |  U <hex digit> <hex digit> <hex digit> <hex digit> <hex digit> <hex digit>
<vertical line> --> |
```

Any other letter after `\` is an error. `\|` is a literal vertical
line. `\(` is a literal `(`. A backslash at the end of a line continues
the string. Default `\x` is exactly two hex digits.

### Vector, bytevector, and bitvector

Reconstructed from [Vector Syntax][vectors],
[Bytevectors][bytevectors], and [Bit Vectors][bit-vectors].

```text
<vector>     --> #( <datum>* )
<bytevector> --> #vu8( <datum>* )
<bitvector>  --> #* <bit>*
<bit>        --> 0 | 1
```

`#vu8` uses a lowercase `v`. `#*` is the two characters `#` and `*`,
then the bits, with no atmosphere inside the token. `#*` alone is the
empty bitvector. `#u8(...)` is a SRFI-4 array, not a `#vu8` bytevector.

### Array

Reconstructed from [Array Syntax][arrays] and the
[SRFI-4 Overview][uniform-vectors].

```text
<array>          --> <ranked array> | <unranked array> | <shaped array>
<ranked array>   --> # <rank> <array tag> <dimension>* ( <array elements> )
<unranked array> --> # <array tag> <dimension>* ( <array elements> )
<shaped array>   --> # <dimension>+ ( <array elements> )
<rank>           --> <unsigned decimal>
<array tag>      --> empty | <uniform tag> | a | b
<uniform tag>    --> u8 | u16 | u32 | u64
                  |  s8 | s16 | s32 | s64
                  |  f32 | f64 | c32 | c64
<dimension>      --> @ <signed decimal>
                  |  : <unsigned decimal>
                  |  @ <signed decimal> : <unsigned decimal>
<signed decimal> --> <sign>? <unsigned decimal>
<sign>           --> + | -
```

Rank is omitted for a rank-1, unshared, zero-origin array. An empty tag
is an untyped array. Tag `a` denotes strings. Tag `b` denotes bitvectors.

Rank 0 has the form `#0<array tag>(<scalar>)` and needs one element.
Written dimensions must match the rank. Dimensions may be omitted when
the nested lists determine them.

`#(` is the vector production. The array chapter also writes `#(` for a
rank-1, zero-origin, unshared array. Both descriptions are published.

Examples from the manual: `#@2(1 2 3)`, `#2((1 2 3) (4 5 6))`,
`#u8(0 1 2)`, `#2u32@2@3((1 2) (2 3))`, `#2()`, `#2:0:2()`, `#0(12)`.

### Special object

Reconstructed from [Nil][nil]: the external representation is `#nil`.

```text
<special object> --> #nil
```

## Optional reader syntax

Each read-option mode below is off by default.

### Prefix and postfix keywords

**Activation:** `keywords` set to `'prefix` or `'postfix`.
**Default:** `#f`, so only `#:NAME` is a keyword.

**Changed production** (reconstructed from
[Keyword Read Syntax][keywords]):

```text
<keyword> --> #:<symbol>
           |  :<symbol>                     ; keywords 'prefix
           |  <ordinary symbol ending in :> ; keywords 'postfix
```

There is no intertoken space in these tokens. Colon is not a
delimiter, so under `'postfix` the name `foo:bar:` is one keyword. The
two styles are mutually exclusive.

### Case insensitivity

**Activation:** `case-insensitive`, or `#!fold-case`.
**Default:** off. `#!no-fold-case` turns it off.

**Change:** ordinary symbol characters are downcased.

### R6RS string hex escapes

**Activation:** `r6rs-hex-escapes`.
**Default:** off.

**Change:** string `\x` takes one through eight hex digits followed by
`;`, instead of exactly two hex digits. [Scheme Read][scheme-read] also
says this option affects character hex escapes, but
[Characters][characters] does not specify a replacement production.
That interaction is unresolved.

**Interaction:** `|...|` symbols under `r7rs-symbols` always use this
`\x` form, whether or not `r6rs-hex-escapes` is on.

### Hungry end-of-line escapes

**Activation:** `hungry-eol-escapes`.
**Default:** off.

**Change:** after a backslash-newline, leading whitespace on the next
line is discarded. [String Syntax][strings] does not list the
characters. The verified set is tab and Unicode `Zs` spaces.

### R7RS vertical-line symbols

**Activation:** `r7rs-symbols`.
**Default:** off, so `|` is an ordinary symbol character.

**Changed production:**

```text
<symbol> --> <r5rs identifier> | <extended symbol> | <r7rs symbol>
```

`|...|` is an identifier. The body uses string escapes, with `|` as the
delimiter instead of `"`. The escapes include `\0`, `\f`, `\v`, `\(`,
`\uXXXX`, and `\UXXXXXX`. `\x` in this body takes one through eight hex
digits followed by `;`, independent of `r6rs-hex-escapes`.

### Curly-infix

**Activation:** `curly-infix`, `#!curly-infix`, or
`#!curly-infix-and-bracket-lists`.
**Default:** off, so `{n + 1}` reads as the symbol `{n`, then `+`, then
the symbol `1}`.

**Changed production** (reconstructed from [SRFI-105][srfi-105]):

```text
<curly infix> --> { <datum>* }
               |  { <datum>+ . <datum> }
```

The reader rewrites the written list: `{}` → `()`, `{x}` → `x`,
`{x y}` → `(x y)`; a repeated operator becomes n-ary; otherwise
`$nfx$`. Inside a curly list, neoteric application needs no space
before `(`, `[`, or `{`. Outside a curly list, `f(x)` is still the
symbol `f` followed by a list.

`#!curly-infix-and-bracket-lists` also turns `square-brackets` off.
With `square-brackets` off and `curly-infix` on, `[a b]` reads as
`($bracket-list$ a b)`.

### Byte strings

**Activation:** `bytestrings`, documented by 3.0.11 NEWS and
[SRFI-207][srfi-207].
**Default:** off.

**Change:** `#u8"..."` is a SRFI-207 byte string. `#u8(...)` remains a
SRFI-4 array. `#vu8(` remains the bytevector production.

Published SRFI-207 content bytes are U+0020 through U+007E. Escapes
are `\a`, `\b`, `\t`, `\n`, `\r`, `\"`, `\\`, `\|`; `\x` with optional
leading zeroes, one or two hex digits, and `;`; and a hungry line
continuation.

### Reader extensions

**Activation:** `read-hash-extend` from
[reader extensions][reader-extensions].
**Default:** no user callback. Callback syntax is not part of this
fixed formal syntax. An unknown `#` plus a character is an error when
no callback is installed.

[scheme-syntax]: https://www.gnu.org/software/guile/manual/html_node/Scheme-Syntax.html
[syntax-summary]: https://www.gnu.org/software/guile/manual/html_node/Syntax-Summary.html
[expression-syntax]: https://www.gnu.org/software/guile/manual/html_node/Expression-Syntax.html
[scheme-read]: https://www.gnu.org/software/guile/manual/html_node/Scheme-Read.html
[comments]: https://www.gnu.org/software/guile/manual/html_node/Comments.html
[block-comments]: https://www.gnu.org/software/guile/manual/html_node/Block-Comments.html
[srfi-62]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d62.html
[case-sensitivity]: https://www.gnu.org/software/guile/manual/html_node/Case-Sensitivity.html
[strings]: https://www.gnu.org/software/guile/manual/html_node/String-Syntax.html
[symbols]: https://www.gnu.org/software/guile/manual/html_node/Symbol-Read-Syntax.html
[keywords]: https://www.gnu.org/software/guile/manual/html_node/Keyword-Read-Syntax.html
[characters]: https://www.gnu.org/software/guile/manual/html_node/Characters.html
[booleans]: https://www.gnu.org/software/guile/manual/html_node/Booleans.html
[numbers]: https://www.gnu.org/software/guile/manual/html_node/Number-Syntax.html
[vectors]: https://www.gnu.org/software/guile/manual/html_node/Vector-Syntax.html
[bit-vectors]: https://www.gnu.org/software/guile/manual/html_node/Bit-Vectors.html
[arrays]: https://www.gnu.org/software/guile/manual/html_node/Array-Syntax.html
[uniform-vectors]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d4-Overview.html
[bytevectors]: https://www.gnu.org/software/guile/manual/html_node/Bytevectors.html
[nil]: https://www.gnu.org/software/guile/manual/html_node/Nil.html
[srfi-88]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d88.html
[srfi-105]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d105.html
[srfi-207]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d207-External-Notation.html
[reader-extensions]: https://www.gnu.org/software/guile/manual/html_node/Reader-Extensions.html
