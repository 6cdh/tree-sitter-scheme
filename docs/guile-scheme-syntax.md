# Guile Scheme Reader Syntax

This is the reader syntax reference for Guile. The target is GNU
Guile 3.0.11.

Guile does not publish one formal reader grammar. The manual node *Syntax
Summary* is special-form syntax (`lambda`, `if`, ...), not datum syntax. The
closest cited grammar is R5RS section 7.1. The rest is scattered through the
Reference Manual.

This document presents published Guile 3.0 and inherited R5RS syntax first.
An **Implementation Behavior** section records Guile 3.0.11 token boundaries
and published-syntax gaps. Observed acceptance does not enlarge the formal
grammar or override published syntax. A separate compatibility note identifies
known reader deviations from clear published rules.

It describes Guile reader syntax, not the current `dialects/guile/` grammar.

## Sources

- Token rules: GNU Guile 3.0.11 `ice-9/read.scm`
- [Scheme Syntax][scheme-syntax] is only a menu. Reader forms live in
  [expression syntax][expression-syntax], [comments][comments],
  [block comments][block-comments], [case sensitivity][case-sensitivity],
  [keyword syntax][keywords], and [reader extensions][reader-extensions]
- [Scheme Read][scheme-read] lists read options and per-port directives
- Per-type nodes: [symbols][symbols], [strings][strings], [characters][characters],
  [numbers][numbers], [vectors][vectors], [bit vectors][bit-vectors],
  [arrays][arrays], [SRFI-4][uniform-vectors], [bytevectors][bytevectors]
- Optional: [SRFI-88][srfi-88], [SRFI-105][srfi-105], [SRFI-62][srfi-62],
  [SRFI-207][srfi-207]
- Encoding sniff: [character encoding of source files][encoding]
- Inherited formal core: R5RS section 7.1 in `docs/r5rs.txt`. Guile's symbol
  node says the standard identifier syntax is taken from that section.

## Notation

The grammar uses the R5RS BNF extensions. `<thing>*` is zero or more.
`<thing>+` is one or more. `empty` is the empty string. `datum*` in running
text means zero or more data with intertoken space between them.

Productions describe the default reader unless a named option is on. Case in
boolean names, number prefixes, and character names is not significant except
where a production says otherwise. Directive names are case-sensitive and
lowercase. `<hex digit>` is `0`–`9` and `a`–`f` in any case.

A parser that only checks token shape may accept text that later fails in
`list->typed-array`, `string->number`, or `integer->char` value checks.

## Published Reader Options

These options are parameters of the grammar. Default `(read-options)` is:

```text
(square-brackets keywords #f positions)
```

| Option | Default | Effect when on |
| --- | --- | --- |
| `square-brackets` | yes | `[` and `]` are list delimiters |
| `keywords` | `#f` | `'prefix` also reads `:NAME`, `'postfix` also reads `NAME:` |
| `case-insensitive` | no | ordinary symbol characters are downcased |
| `r6rs-hex-escapes` | no | string `\x` is `\xHHHH;` instead of `\xHH` |
| `hungry-eol-escapes` | no | spaces after a `\` newline are discarded |
| `curly-infix` | no | `{...}` is a curly-infix list |
| `r7rs-symbols` | no | R7RS vertical-line identifiers |
| `bytestrings` | no | `#u8"..."` is SRFI-207 |
| `positions` | yes | source properties; not token syntax |

`keywords` may be `'prefix` (`:NAME`) or `'postfix` (`NAME:`). Those two styles
are mutually exclusive. With the default `#f`, only `#:NAME` is a keyword.

These directives set per-port options while reading. They are atmosphere, not
data. A directive name is letters, digits, and `-`. The character after the
name is the next skip/dispatch character.

```text
<directive> --> #!r6rs
             |  #!fold-case
             |  #!no-fold-case
             |  #!curly-infix
             |  #!curly-infix-and-bracket-lists
```

`#!r6rs` is implemented by `read` and is not listed in the Scheme Read node. It
turns off `case-insensitive`, turns on `r6rs-hex-escapes`, `square-brackets`,
and `hungry-eol-escapes`, and sets `keywords` to `#f`.

`#!fold-case` / `#!no-fold-case` toggle `case-insensitive`.
`#!curly-infix` turns `curly-infix` on.
`#!curly-infix-and-bracket-lists` turns `curly-infix` on and `square-brackets`
off.

If the text after `#!` is not one of those names, `read` treats it as a SCSH
comment and requires a later `!#`. End of input before `!#` is an error.

## Formal Syntax

### Intertoken space

```text
<intertoken space> --> <atmosphere>*
<atmosphere>       --> <whitespace> | <comment> | <directive>
<whitespace>       --> space | tab | formfeed | return | newline
<comment>          --> <line comment>
                    |  <block comment>
                    |  <datum comment>
                    |  <script comment>
<line comment>     --> ; <any character except newline>*
<block comment>    --> #| <nested block-comment body> |#
<datum comment>    --> #; <intertoken space> <datum>
<script comment>   --> #! <script comment body> !#
```

`#;` then one datum is SRFI-62, on by default.

R5RS 7.1.1 lists only space and newline as `<whitespace>`. Tab, formfeed,
and return are the wider set that Guile's reader skips.

The block-comment body may contain balanced nested block comments.

### Datum

```text
<datum> --> <simple datum> | <compound datum>
<simple datum> --> <boolean> | <number> | <character> | <string>
                |  <symbol> | <keyword> | <special object>
                |  <bitvector> | <byte string>
<compound datum> --> <list> | <vector> | <bytevector> | <array>
                  |  <abbreviation> | <curly infix>
<abbreviation> --> <abbrev prefix> <intertoken space> <datum>
<abbrev prefix> --> ' | ` | , | ,@ | #' | #` | #, | #,@
```

`#'datum` reads as `(syntax datum)`, `` #`datum `` as `(quasisyntax datum)`,
`#,datum` as `(unsyntax datum)`, and `#,@datum` as `(unsyntax-splicing datum)`.

### Lists

```text
<list> --> ( <datum>* )
        |  ( <datum>+ . <datum> )
        |  [ <datum>* ]                  ; square-brackets
        |  [ <datum>+ . <datum> ]        ; square-brackets
```

Square brackets are list delimiters when `square-brackets` is enabled.

### Boolean

The published boolean spellings are case-insensitive.

```text
<boolean> --> #t | #f | #true | #false
```

### Number and symbol

Finite number spellings are R5RS 7.1 integers, rationals, reals, and
complexes, with optional prefixes `#b` `#o` `#d` `#x` and `#e` `#i` (any
case). Guile also accepts the following signed infinity and NaN spellings;
these may use a radix prefix and/or `#i`, but not `#e`:

```text
<infnan> --> +inf.0 | -inf.0 | +nan.0 | -nan.0
```

The sign is required. An `<infnan>` is a `<number>`, not an identifier.
Guile does not publish R6RS mantissa-width syntax.

Finite hash-prefixed numbers use the same inherited number syntax:

```text
<prefixed number> --> #<exactness> <number body>
                  |  #<radix> <number body>
                  |  #<exactness>#<radix> <number body>
                  |  #<radix>#<exactness> <number body>
<exactness>       --> i | e                       ; any case
<radix>           --> b | o | d | x               ; any case
```

`<number body>` is an inherited R5RS integer, rational, real, or complex
without its optional radix and exactness prefixes. Guile accepts the two
prefixes in either order.

Published ordinary symbols use the R5RS identifier syntax. Guile also
publishes an extended-symbol notation and optionally enables R7RS bar
notation:

```text
<symbol> --> <r5rs identifier>
          |  <extended symbol>
          |  <r7rs symbol>              ; r7rs-symbols
<extended symbol> --> #{ <extended symbol body> }#
```

With `r7rs-symbols`, `|...|` uses string escapes, delimited by `|` instead of
`"`. It accepts the string escapes listed below, including `\0`, `\f`, `\v`,
`\(`, `\uXXXX`, and `\UXXXXXX`. R6RS `\xHHHH;` is used for `\x` in that form.

With `case-insensitive`, ordinary symbol characters are downcased.

### Keyword

Published keyword spellings are contiguous tokens.

```text
<keyword> --> #:<symbol>                         ; always
           |  :<symbol>                         ; keywords 'prefix
           |  <ordinary symbol ending in :>     ; keywords 'postfix
```

Default Guile reads `:NAME` and `NAME:` as symbols.

### Character

The Reference Manual publishes these forms:

```text
<character> --> #\<any character>
             |  #\<character name>
             |  #\x<hex scalar digits>
             |  #\<octal digit>+
             |  #\<dotted circle><combining character>
```

The dotted circle is U+25CC and precedes the combining character in the
published notation. Hexadecimal character values use lowercase `x` and one
through eight hexadecimal digits.

Valid names from the manual tables:

- Long: `nul`, `alarm`, `backspace`, `tab`, `linefeed`, `newline`, `vtab`,
  `page`, `return`, `esc`, `space`, `delete`
- R7RS: `escape` (the R7RS name for the same character as `esc`)
- C0 short: `nul` `soh` `stx` `etx` `eot` `enq` `ack` `bel` `bs` `ht` `lf`
  `vt` `ff` `cr` `so` `si` `dle` `dc1` `dc2` `dc3` `dc4` `nak` `syn` `etb`
  `can` `em` `sub` `esc` `fs` `gs` `rs` `us` `sp`
- Delete short: `del`
- Compatibility: `null` `nl` `np`

### String

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  \ <string escape>
<string escape> --> \ | " | <vertical line> | a | f | n | r | t | v | b | 0 | (
                 |  newline <hungry spaces>?
                 |  x <hex digit> <hex digit>      ; default
                 |  x <hex scalar digits> ;        ; r6rs-hex-escapes
                 |  u <hex digit> <hex digit> <hex digit> <hex digit>
                 |  U <hex digit> <hex digit> <hex digit> <hex digit>
                      <hex digit> <hex digit>
<vertical line> --> |
```

Any other letter after `\` is an error. `\|` is accepted. `\(` is a literal
`(`. A backslash-newline continues the string. With `hungry-eol-escapes`,
following tabs and Unicode `Zs` spaces are discarded.

Default `\x` is exactly two hex digits. With `r6rs-hex-escapes`, `\x` is
one through eight hex digits followed by `;`. `|...|` symbols always use
the R6RS `\x` form for `\x`.

### Vector, bytevector, bitvector

```text
<vector>     --> #( <datum>* )
<bytevector> --> #vu8( <datum>* )
<bitvector>  --> #* <bit>*
<bit>        --> 0 | 1
```

`#u8(n*)` is a SRFI-4 uniform vector (a rank-1 array), not `#vu8`.
`#*` is the two characters `#` and `*`, then bits `0` and `1` with no
atmosphere in between. Zero bits is the empty bitvector `#*`. `#vu8` is
lowercase `v`.

### Array

The published array notation writes rank, tag, shape, then `(` elements `)`.

```text
<array>          --> <ranked array> | <unranked array> | <shaped array>
<ranked array>   --> # <rank> <ranked tag> <dimension>* ( <array elements> )
<unranked array> --> # <uniform tag> <dimension>* ( <array elements> )
<shaped array>   --> # <dimension>+ ( <array elements> )
<rank>           --> <unsigned decimal>
<ranked tag>     --> empty | <uniform tag> | a | b
<uniform tag>    --> u8 | u16 | u32 | u64
                  |  s8 | s16 | s32 | s64
                  |  f32 | f64 | c32 | c64
<dimension> --> @ <signed decimal>
             |  : <unsigned decimal>
             |  @ <signed decimal> : <unsigned decimal>
<signed decimal> --> <sign>? <unsigned decimal>
<sign> --> + | -
```

An unranked uniform tag is a rank-1 array. An empty tag in a ranked array is
an untyped array. Rank 0 is `#0<vectag>(<scalar>)` and needs exactly one
element. `a` and `b` are ranked tags; bare `#a(...)` and `#b(...)` are not
array syntax. Explicit dimensions must match the rank; dimensions may be
omitted when Guile can recover them from nested lists.

`#(` is the vector production above, not an array prefix. The array chapter
still prints a rank-1 zero-origin unshared array that way.

Examples:

```text
#@2(1 2 3)
#2((1 2 3) (4 5 6))
#u8(0 1 2)
#2u32@2@3((1 2) (2 3))
#2()
#2:0:2()
#0(12)
```

Ranked string and bit arrays use tags `a` and `b`, for example `#2a(...)`
and `#2b(...)`. The constructor may still reject those elements; the written
shape is array syntax. `#vu8` is the separate bytevector production.

### Special object

```text
<special object> --> #nil
```

The dispatch letter in `#nil` is lowercase `n`. After `#n`, the reader takes
one ordinary token and requires it to be `nil`; with `case-insensitive` on,
`#nIL` is downcased and accepted. `#nilly` is an error, and `#NIL` never
reaches the `#nil` reader because its dispatch letter is uppercase.

### Curly-infix (optional)

With `curly-infix`:

```text
<curly infix> --> { <datum>* }
               |  { <datum>+ . <datum> }
```

The reader then rewrites the list:

| Written | Reads as |
| --- | --- |
| `{}` | `()` |
| `{x}` | `x` |
| `{x y}` | `(x y)` |
| `{x + y + z}` (same operator) | `(+ x y z)` |
| other `{...}` | `($nfx$ ...)` |

Inside a curly list, neoteric forms apply with no space between the function
and the opener:

| Written | Reads as |
| --- | --- |
| `e(...)` | `(e ...)` |
| `e[...]` | `($bracket-apply$ e ...)` |
| `e{}` | `(e)` |
| `e{...}` | `(e <rewritten {...}>)` |

Neoteric application is not used at top level. With `curly-infix` on, `f(x)`
outside braces still reads as the symbol `f` and then a list.

With `#!curly-infix-and-bracket-lists` (`curly-infix` on and `square-brackets`
off), `[a b]` reads as `($bracket-list$ a b)`.

### Byte string (optional)

With `bytestrings`, if `#u` is followed by `8` and then `"`, the form is
SRFI-207. Otherwise `#u` starts a SRFI-4 array: the reader puts the `8` back
and parses `#u8(...)` as an array. `#vu8"..."` is not bytestring syntax.

Published SRFI-207 content bytes are U+0020 through U+007E. Escapes are
`\a` `\b` `\t` `\n` `\r` `\"` `\\` `\|`, `\x` followed by zero or more
leading zeroes, one or two hexadecimal digits, and `;`, plus a hungry line
continuation. `#u8"A"` is the same datum as `#u8(65)`.

## Implementation Behavior

The following notes describe Guile 3.0.11 `read` token boundaries and
reader behavior. They are not normative when the published syntax above is
clear.

### How `read` tokenizes

`read` does not match a context-free grammar of names. It skips atmosphere,
looks at the next character, and either reads a delimited token or enters a
nested reader (`(`, `"`, `#`, and so on).

#### Skip

Before a datum, `read` loops on the next character:

| Character | Action |
| --- | --- |
| space, tab, formfeed, return, newline | skip |
| `;` | skip a line comment, then skip again |
| `#` then `!` | directive or SCSH comment, then skip again |
| `#` then `;` | skip one datum, then skip again |
| `#` then `\|` | nested `#\| ... \|#`, unless `read-hash-extend` is set on `\|` |
| other `#` | that `#` starts a hash object |
| anything else | that character starts a datum |

Vertical tab, NEL, and Unicode separators are not skipped. They are not
delimiters.

#### Delimiters

A token is the first character plus every following character until a
delimiter or end of input.

```text
<always delimiter> --> ( | ) | " | ;
                    |  space | tab | formfeed | return | newline
<bracket delimiter> --> [ | ]     ; when square-brackets or curly-infix
<brace delimiter>   --> { | }     ; when curly-infix
```

These are not delimiters in default Guile: `'`, `` ` ``, `,`, `#`, `:`, `{`,
`}`, `|`, and `.`.

- `'` , backquote, and comma start abbreviations only as the first character
  of a datum. Inside a token they are ordinary, so `foo'bar` is one symbol.
- `#` starts a hash object only as the first character of a datum. `foo#bar`
  is one symbol.
- `{` and `}` are ordinary symbol characters until `curly-infix` is on.
  Default Guile reads `{n + 1}` as the symbol `{n`, then `+`, then `1}`.
- Colon is not a delimiter. With postfix keywords, `foo:bar:` is one keyword
  whose name is `foo:bar`.

#### First character of a datum

| First character | Reader |
| --- | --- |
| `(` | list to `)` |
| `[` | list to `]` if `square-brackets`; `$bracket-list$` list if only `curly-infix`; else a symbol |
| `{` | curly list if `curly-infix`; else a symbol |
| `"` | string |
| `\|` | `|...|` symbol if `r7rs-symbols`; else a symbol whose name includes the bars |
| `'` `` ` `` `,` `,@` | abbreviation, then one datum |
| `#` | hash dispatch |
| `)` | error |
| `]` | error if `square-brackets`; else a symbol |
| `}` | error if `curly-infix`; else a symbol |
| `:` | prefix keyword if `keywords` is `'prefix`; else a symbol |
| `0`–`9` `+` `-` `.` | one token; `string->number`, else a symbol |
| other | one token; postfix keyword if that style is on and the token ends in `:`; else a symbol |

#### Hash dispatch

After `#`, `read` first calls any `read-hash-extend` callback for that
character. Default Guile registers `#.` . Unless `read-eval?` is true, `#.`
is an error. Unknown `#` plus a character is an error.

The dispatch character is case-sensitive except where the table lists both
cases. `#nil` needs lowercase `n`. `#NIL` is an unknown `#` object even with
`case-insensitive`. `#F` is boolean false. `#f32(` and `#f64(` are arrays.
Lowercase `#f` reads boolean false after opportunistically consuming a matching
`alse` tail. If the next character mismatches, it remains for the next datum;
if it is `3` or `6`, lowercase `#f` instead starts an array. Uppercase `#F`
always reads boolean false.

Built-in dispatch when no extension is installed:

| After `#` | Production |
| --- | --- |
| `\` | character |
| `(` | vector |
| `u` | SRFI-4 array, or SRFI-207 `#u8"..."` if `bytestrings` |
| `s` `c` | SRFI-4 array |
| `f` | `#f32`/`#f64` array, else boolean false |
| `v` | `#vu8(` bytevector |
| `*` | bitvector |
| `t` `T` `F` | boolean |
| `:` | keyword |
| `0`–`9` `@` | array |
| `i` `e` `b` `o` `d` `x` (any case) | prefixed number |
| `{` | extended symbol |
| `'` `` ` `` `,` `,@` | syntax abbreviations |
| `n` | `#nil` |

## Source Loading Note

A `coding: NAME` declaration in a `;` comment or in the first `#!` block, in
the first 500 characters of a file, may select the source encoding. That scan
belongs to `file-encoding` / `load`, not to one `read` call.

## Non-normative Compatibility Notes

These observed Guile 3.0.11 differences are not published syntax:

- Directive names are case-sensitive. For example, `#!FOLD-CASE` starts an
  unterminated SCSH comment rather than enabling case folding.
- Boolean readers can stop after `#t` or `#f` when a long spelling
  mismatches, so `#tru1` reads as `#t` followed by `ru1`.
- A leading `.` token starts an improper list tail even before any element:
  `( . x)` reads as `x`. Mismatched list closers are errors.
- Number-or-symbol tokens that fail `string->number` become symbols. The
  reader also accepts case variants and extra zero or `#` suffixes on some
  signed infinity and NaN spellings.
- `#:` and prefix `:` skip atmosphere before the following name. The
  source comments mark this skip as unintended.
- `#{...}#` ends at the first `}#`. Inside it, `\x` starts an R6RS hex
  escape; another backslash drops itself and keeps the next character.
- Character classification uses the whole non-delimited token. Guile 3.0.11
  accepts a combining character followed by U+25CC, the reverse of the
  published order, and does not enforce the published eight-hex-digit cap.
- R6RS string hex escapes likewise accept additional leading zeroes beyond
  the published eight-digit form.
- An array lower bound accepts an optional `-` but rejects an explicit `+`.
- Array dispatch accepts only the published tag set. Bare `#a(...)` and
  `#b(...)`, shaped `#vu8`, and R6RS-style `#n=` / `#n#` forms fail.
- A bitvector stops at the first non-bit without requiring a delimiter.
  For example, `#*10102` leaves the final `2` for the next datum.
- `#nil` dispatches only on lowercase `n`; case folding applies after that
  dispatch.
- The SRFI-207 byte-string reader tests decimal code points 20 through 127
  inclusive, rather than the published U+0020 through U+007E range.

A shape-only parser may treat a character as `#\` plus one delimiter
character or one run of non-delimiters. Name tables and scalar-value checks
remain semantic constraints.

[scheme-syntax]: https://www.gnu.org/software/guile/manual/html_node/Scheme-Syntax.html
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
[numbers]: https://www.gnu.org/software/guile/manual/html_node/Number-Syntax.html
[vectors]: https://www.gnu.org/software/guile/manual/html_node/Vector-Syntax.html
[bit-vectors]: https://www.gnu.org/software/guile/manual/html_node/Bit-Vectors.html
[arrays]: https://www.gnu.org/software/guile/manual/html_node/Array-Syntax.html
[uniform-vectors]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d4-Overview.html
[bytevectors]: https://www.gnu.org/software/guile/manual/html_node/Bytevectors.html
[srfi-88]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d88.html
[srfi-105]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d105.html
[srfi-207]: https://www.gnu.org/software/guile/manual/html_node/SRFI_002d207-External-Notation.html
[reader-extensions]: https://www.gnu.org/software/guile/manual/html_node/Reader-Extensions.html
[encoding]: https://www.gnu.org/software/guile/manual/html_node/Character-Encoding-of-Source-Files.html
