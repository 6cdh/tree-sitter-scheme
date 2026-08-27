# Guile Scheme Reader Syntax

This is the restart reference for a Guile dialect parser. The target is GNU
Guile 3.0.11.

Guile does not publish one formal reader grammar. The manual node *Syntax
Summary* is special-form syntax (`lambda`, `if`, ...), not datum syntax. The
closest cited grammar is R5RS section 7.1. The rest is scattered through the
Reference Manual.

This document has two layers:

- **Published forms.** Names, options, and spellings from the Guile 3.0
  Reference Manual.
- **Token rules.** How `read` skips input, where a token ends, and how the
  first character chooses a reader. Those rules are extracted from Guile
  3.0.11 `ice-9/read.scm` (installed as `/usr/share/guile/3.0/ice-9/read.scm`).
  `libguile/read.c` is only `primitive-read`, used to bootstrap.

The token rules are behavior, not a copy of that file. Where the manual and
`read` disagree, this document follows `read` and says so.

It describes what `read` accepts, not the current `dialects/guile/` grammar.

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
boolean names, number prefixes, character names, and directives is not
significant except where a production says otherwise.

A parser that only checks token shape may accept text that later fails in
`list->typed-array`, `string->number`, or `integer->char` value checks.

## How `read` tokenizes

`read` does not match a context-free grammar of names. It skips atmosphere,
looks at the next character, and either reads a delimited token or enters a
nested reader (`(`, `"`, `#`, and so on).

### Skip

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

A `coding: NAME` declaration in a `;` comment or in the first `#!` block, in
the first 500 characters of a file, may select the source encoding. That scan
is `file-encoding` / `load`, not part of one `read` call.

### Delimiters

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

### First character of a datum

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

### Hash dispatch

After `#`, `read` first calls any `read-hash-extend` callback for that
character. Default Guile registers `#.` . Unless `read-eval?` is true, `#.`
is an error. Unknown `#` plus a character is an error.

The dispatch character is case-sensitive except where the table lists both
cases. `#nil` needs lowercase `n`. `#NIL` is an unknown `#` object even with
`case-insensitive`. `#F` is boolean false. `#f` followed by `3` or `6` is an
array.

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

## Read Options

These options are parameters of the grammar. Default `(read-options)` is:

```text
(square-brackets keywords #f positions)
```

| Option | Default | Effect on syntax |
| --- | --- | --- |
| `square-brackets` | yes | `[` and `]` are list delimiters |
| `keywords` | `#f` | only `#:NAME` is a keyword |
| `case-insensitive` | no | symbols keep written case |
| `r6rs-hex-escapes` | no | strings use `\xHH`, not `\xHHHH;` |
| `hungry-eol-escapes` | no | spaces after `\` newline stay in the string |
| `curly-infix` | no | `{` and `}` are ordinary symbol characters |
| `r7rs-symbols` | no | `\|...\|` is not bar notation |
| `bytestrings` | no | `#u8"..."` is not SRFI-207 |
| `positions` | yes | source properties; not token syntax |

`keywords` may be `'prefix` (`:NAME`) or `'postfix` (`NAME:`). Those two styles
are mutually exclusive.

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
<block comment>    --> #| <block comment body> |#
<block comment body> --> <empty | nested <block comment> | other characters>
<datum comment>    --> #; <intertoken space> <datum>
<script comment>   --> #! <script comment body> !#
```

`#;` then one datum is SRFI-62, on by default.

`#| ... |#` nests. `read-hash-extend` on `#\|` may override this.

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

A `.` token is an ordinary token that starts with `.` and reads as the symbol
whose name is `.`. That token starts an improper tail, even as the first
element: `( . x)` reads as `x`. `#{.}#` is the same symbol, but it starts with
`#`, so it is a list element, not an improper-tail marker.

Mismatched closers `)` `]` `}` are errors when that closer is a delimiter.

### Boolean

After `#t` or `#T`, `read` may consume the letters `rue` one by one, stopping
at the first mismatch. After `#f` (not `#F`), if the next character is `3` or
`6`, the form is an array. Otherwise `#f` and `#F` may consume `alse` the same
way. No delimiter is required after `#t` / `#f`.

```text
<boolean> --> #t <true tail>?
           |  #f <false tail>?     ; unless #f starts an array, below
<true tail>  --> rue               ; case-insensitive, optional
<false tail> --> alse              ; case-insensitive, optional
```

`(#tru1)` reads as `(#t ru1)`. `(#true1)` reads as `(#t 1)`. `(#fAlse)` reads
as `(#f Alse)`.

`(1 #f3)` is invalid array syntax. `(1 #f 3)` is a list. `#F64(1.0)` reads as
boolean `#f` and leaves `64(1.0)`.

### Number and symbol

If a datum starts with a digit, `+`, `-`, or `.`, `read` takes one token and
tries `string->number`. If that fails, the same token is a symbol. So `1+` and
`123abc` are symbols. `.e5` is a symbol (`string->number` rejects it).

The number spellings are R5RS 7.1 integers, rationals, reals, and complexes,
with optional prefixes `#b` `#o` `#d` `#x` and `#e` `#i` (any case), plus
signed inf/nan. This is not the union of R5RS, R6RS, and R7RS: there is no
mantissa width, so `1.0|53` is a symbol.

```text
<infinan> --> <sign> inf.0 | <sign> nan.0 <extra zeros>
<sign>    --> + | -
<extra zeros> --> (0 | #)*
```

`inf` and `nan` letters are not case-sensitive. `inf.0` is that spelling after
the sign. `nan.0` may continue with extra `0` and `#` marks (`+nan.00`,
`+nan.0#`). The sign is required; `inf.0` is a symbol. The manual shows only
lowercase `+inf.0` and `+nan.0`; `read` accepts the case variants.

Hash prefixes for numbers are also a `#` object. `read` takes `#` plus one
token and tries `string->number`. Failure is an unknown `#` object, not a
symbol.

```text
<prefixed number> --> # <exactness or radix> <number token>
<exactness or radix> --> i | e | b | o | d | x     ; any case
```

An ordinary symbol is one token. It need not match the R5RS `<identifier>`
production. The R5RS extended alphabetic set is still accepted:

```text
! $ % & * + - . / : < = > ? @ ^ _ ~
```

Guile also allows `'`, `\`, `#`, digits after the first character, and other
non-delimiters inside a symbol.

```text
<symbol> --> <ordinary symbol>
          |  <extended symbol>
          |  <r7rs symbol>              ; r7rs-symbols
<extended symbol> --> #{ <extended symbol body> }#
```

`#{...}#` ends at the first `}#`. A `}` that is not followed by `#` is part of
the name. `\x` inside the body is an R6RS hex character escape; any other
backslash is dropped and the next character is kept.

With `r7rs-symbols`, `|...|` uses string escapes, delimited by `|` instead of
`"`. R6RS `\xHHHH;` is used for `\x` in that form. Without that option, `|foo|`
is one ordinary symbol whose name is `|foo|`.

With `case-insensitive`, ordinary symbol characters are downcased.

### Keyword

```text
<keyword> --> #: <intertoken space>? <symbol>     ; always
           |  : <intertoken space>? <datum>       ; keywords 'prefix
           |  <ordinary symbol ending in :>       ; keywords 'postfix
```

`#:` skips atmosphere before the name (`#:   foo` and `#:#|x|#foo` are
`#:foo`). The name after `#:` must be a symbol.

Prefix `:NAME` uses the same skip. `: foo` is `#:foo`. A lone `:` is an error.
The current `read` comments mark that skip as unintended.

Default Guile reads `:NAME` and `NAME:` as symbols.

### Character

After `#\`, `read` does not try name productions first. It does this:

1. If the next character is end of input, error.
2. If it is a delimiter, that character is the datum (`#\(` is left
   parenthesis, `#\ ` is space).
3. Otherwise take one token (until a delimiter).
4. Classify that whole token, in order:
   - length 1: that character
   - length 2 and the second character is U+25CC (dotted circle): the first
     character; the dotted circle is ignored
   - the first character is `0`–`7` and the whole token is an octal number:
     that code point
   - the first character is lowercase `x`, the token is longer than `x`, and
     the rest is a hex number: that code point (`integer->char` may still
     fail)
   - else a case-insensitive name from the tables below
   - else error (`unknown character name`)

The manual writes combining characters as `#\` + U+25CC + the combining
character. `read` does the other order: combining character, then U+25CC, so
both stay in one token. `#\xHHHH` in the manual is one to eight hex digits.
`read` has no eight-digit cap; a value outside the Unicode range is a run-time
error.

Because classification uses the whole token, `#\19` is an error, not `#\1`
plus `9`. `#\not-a-name` is an error, not `#\n` plus a symbol. `#\spaces` is
an error, not `#\space` plus `s`. `#\X41` is an error (`x` hex is lowercase
only). `#\7` has length 1, so it is the digit character `7`, not octal 7.

Valid names (manual tables; `read` matches them case-insensitively):

- Long: `nul`, `alarm`, `backspace`, `tab`, `linefeed`, `newline`, `vtab`,
  `page`, `return`, `esc`, `escape`, `space`, `delete`
- C0 short: `nul` `soh` `stx` `etx` `eot` `enq` `ack` `bel` `bs` `ht` `lf`
  `vt` `ff` `cr` `so` `si` `dle` `dc1` `dc2` `dc3` `dc4` `nak` `syn` `etb`
  `can` `em` `sub` `esc` `fs` `gs` `rs` `us` `sp`
- Delete short: `del`
- Compatibility: `null` `nl` `np`

A shape-only parser can treat `#\` plus a delimiter character, or `#\` plus a
run of non-delimiters, as one character token. The name tables are a validity
list, not lexer alternatives.

### String

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  \ <string escape>
<string escape> --> \ | " | | | a | f | n | r | t | v | b | 0 | (
                 |  newline <hungry spaces>?
                 |  x <hex hex>                    ; default
                 |  x <hex>+ ;                     ; r6rs-hex-escapes
                 |  u <hex hex hex hex>
                 |  U <hex hex hex hex hex hex>
```

Any other letter after `\` is an error. `\|` is accepted. `\(` is a literal
`(`. A backslash-newline continues the string. With `hungry-eol-escapes`,
following tabs and Unicode `Zs` spaces are discarded.

Default `\x` is exactly two hex digits. With `r6rs-hex-escapes`, `\x` is hex
digits then `;`. `|...|` symbols always use the R6RS `\x` form for `\x`.

### Vector, bytevector, bitvector

```text
<vector>     --> #( <datum>* )
<bytevector> --> #vu8( <datum>* )
<bitvector>  --> #* <bit>*
<bit>        --> 0 | 1
```

`#u8(n*)` is a SRFI-4 uniform vector (a rank-1 array), not `#vu8`.
`#*` is the two characters `#` and `*`, then bits `0` and `1` with no
atmosphere in between. Zero bits is the empty bitvector `#*`. A later
non-bit does not need a delimiter: `#*10101010102` reads as `#*1010101010`
and leaves `2`. `#vu8` is lowercase `v`.

### Array

After `#` plus a digit, `@`, or a SRFI-4 tag start, `read` parses in this
order: rank, tag, shape, then `(` elements `)`.

```text
<array> --> # <rank> <vectag> <dimension>* ( <array elements> )
<rank>  --> <unsigned decimal> | empty
<vectag> --> empty | u8 | u16 | u32 | u64
          |  s8 | s16 | s32 | s64
          |  f32 | f64 | c32 | c64
          |  a | b
<dimension> --> @ <signed decimal>
             |  : <unsigned decimal>
             |  @ <signed decimal> : <unsigned decimal>
```

Empty rank means 1. The tag is the run of characters until `(`, `@`, or `:`.
If that run is empty, the array is untyped. Rank 0 is `#0<vectag>(<scalar>)`
and needs exactly one element. Shape `@lower` and `:length` may be omitted
when Guile can recover them from the nested lists.

`#(` is the vector production above. The array chapter still prints a rank-1
zero-origin unshared array that way.

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

Bare `#a(...)` and `#b(...)` are unknown `#` objects. Ranked string and bit
arrays use tags `a` and `b`, for example `#2a(...)` and `#2b(...)`. The
constructor may still reject those elements; the written shape is array
syntax.

`#vu8` is the separate bytevector production, not this array production.
Shaped `#vu8` is invalid.

`#n=` and `#n#` are not datum labels. They fail as incomplete arrays.

### Special object

```text
<special object> --> #nil
```

After `#n`, `read` takes an ordinary symbol token that starts with `n`. That
token must be `nil`. `case-insensitive` downcases the token, so `#nIL` works
when that option is on. `#nilly` is an error. `#NIL` never reaches this
reader: `N` is not the `#n` dispatch.

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

With `bytestrings`, if `#u` is followed by `8` then `"`, the form is SRFI-207.
Otherwise `#u` is a SRFI-4 array (`#u8(...)` unread the `8` and parses as an
array). `#vu8"..."` is not bytestring syntax.

CONTENT bytes are code points 20 through 127, or the escapes `\a` `\b` `\t`
`\n` `\r` `\"` `\\` `\|`, `\x` hex `;`, and a hungry line continuation.
Hungry continuation here uses whitespace other than newline, not only tab and
`Zs`. `#u8"A"` is the same datum as `#u8(65)`.

## Tree-sitter Restart Notes

A Tree-sitter grammar is static. Guile's reader is not. This dialect is an
independent Guile parser. It uses a fixed union of Guile spellings:

- Accept default Guile forms throughout a file.
- Also accept the optional spellings (prefix and postfix keywords, `|...|`,
  curly-infix, `#u8"..."`, both `[...]` list styles) as a union, without
  applying directive state changes.
- Represent directives as intertoken nodes. Do not fold later names after
  `#!fold-case`, do not enable braces only after `#!curly-infix`, and do not
  switch keyword style after `#!r6rs`.
- Represent unknown `#` plus one character as a reader-extension node. Do not
  run `read-hash-extend` callbacks. `#|` stays a block comment unless the
  grammar has a deliberate extension hook.
- Check token shape, not runtime object constraints (array element types,
  byte ranges, character code points, `#.` evaluation, unknown character
  names). A character token is `#\` plus one delimiter character, or `#\`
  plus a run of non-delimiters. Do not encode the name tables in the lexer.
- Do not treat `#n=` / `#n#` as R6RS/Chez datum labels.

Shared concepts should reuse the same node names as the R5RS, R6RS, and R7RS
dialects. Guile-only surfaces are arrays, bitvectors, `#nil`, `#{...}#`,
`#:` keywords, `script_comment`, curly-infix, byte strings, and
reader extensions.

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
