# Chez Scheme 10.4.0 reader syntax

## Scope and sources

This document specifies Chez Scheme 10.4.0 reader syntax as compact
formal productions. It does not catalog implementation behavior.
Special forms such as `lambda` and `if` are not reader syntax. This
document describes the reader independently of the Tree-sitter parser.

Chez inherits the R6RS reader. The formal core is R6RS chapter 4.
The Chez Scheme User's Guide documents additional datum syntax but
does not publish a single reader grammar. Remaining rules are
reconstructed from the pages named under Sources.

When published wording is unclear, Chez Scheme 10.4.0
[`s/read.ss`][chez-read] was used to verify it, and that
interpretation is written into the productions. Extra forms that
`s/read.ss` accepts are not syntax.

### Target, inheritance, and default reader

The inherited standard is R6RS. The default reader is case-sensitive
and has R6RS-strict mode off.

| Control | Default | Effect on the default reader |
| --- | --- | --- |
| `#!r6rs` | off | later data use R6RS-strict syntax |
| `#!chezscheme` | off | later data leave R6RS-strict mode |
| `#!fold-case` | off | later symbol and character names are folded |
| `#!no-fold-case` | off | later names keep their written case |
| `(case-sensitive)` | `#t` | names keep their case until a fold directive |

`#!r6rs`, `#!chezscheme`, `#!fold-case`, and `#!no-fold-case` are
atmosphere, not datums. See [Optional reader syntax](#optional-reader-syntax).

Each library loaded implicitly via `import`, and each RNRS top-level
program loaded via `--program`, `scheme-script`, or `load-program`, is
treated as if it begins with `#!r6rs`. That prefix is the loader, not
one `read` call.

The script loader, not `read`, ignores the first line of a loaded
script when that line begins with `#!` followed by a space or `/`.
`compile-script` copies that line into the object file.
`compile-program` copies a leading `#!` line for an RNRS top-level
program. `read` itself treats `#!/...` and `#! ...` as invalid `#!`
syntax.

### Sources

- Inherited formal core: R6RS chapter 4 in `docs/r6rs.txt`
- [CSUG §1.1][csug-intro]: Chez lexical extensions and mode controls
- [CSUG Chapter 7][csug-objects]: characters (§7.3), strings (§7.4),
  vectors (§7.5), fxvectors (§7.6), flvectors (§7.7), bytevectors
  (§7.8), stencil vectors (§7.9), boxes (§7.10), symbols and gensyms
  (§7.11), and records (§§7.15 and 7.17)
- [CSUG Chapter 8][csug-numeric]: arbitrary radices, nondecimal
  floats, infinities, and NaNs
- [Scheme shell scripts][csug-scripts]: interpreter line handled by
  the script loader

Unclear published wording was also checked against Chez Scheme 10.4.0
[`s/read.ss`][chez-read] and [`s/strnum.ss`][chez-strnum]. Extra forms
that those files accept are not syntax.

### Notation

Productions use R6RS BNF notation. `<thing>*` is zero or more.
`<thing>+` is one or more. `empty` is the empty string. `datum*` in
running text means zero or more datums with intertoken space between
them.

Concatenation in a production means concatenation in the input. For
example, `#:<symbol>` has no intertoken space. A production shows
`<intertoken space>` only where space is part of that form.

A section note marks each production as one of:

- **quoted:** copied from a named published grammar
- **adapted:** an inherited production with Chez terminals added or
  removed
- **reconstructed:** derived from published prose that is not a formal
  grammar

Productions describe the default reader unless a named control is on.
Default Chez symbols retain case. Boolean names, number prefixes, and
hexadecimal digits are case-insensitive. Directive and special-object
names are the lowercase spellings in CSUG. `<hex digit>` is `0`–`9`
and `a`–`f` in any case. `<octal digit>` is `0`–`7`.

Reader construction also checks values that token syntax alone cannot
decide, such as Unicode scalar validity, numeric conversion, vector
lengths, record types, and graph references. Those restrictions are
identified where relevant.

## Default reader syntax

Unchanged R6RS number and identifier productions are cited, not copied.

### Intertoken space

Adapted from R6RS 4.2.1 and 4.2.3. Nested `#|...|#` is R6RS.
Directives are reconstructed from [CSUG §1.1][csug-intro].

```text
<intertoken space> --> <atmosphere>*
<atmosphere>       --> <whitespace> | <comment> | <directive>
<whitespace>       --> <character tabulation> | <linefeed> | <line tabulation>
                    |  <form feed> | <carriage return> | <next line>
                    |  <any character whose category is Zs, Zl, or Zp>
<comment>          --> <line comment>
                    |  <block comment>
                    |  <datum comment>
<line comment>     --> ; <any character except a line ending or paragraph separator>*
<block comment>    --> #| <nested block-comment body> |#
<datum comment>    --> #; <intertoken space> <datum>
<directive>        --> #!r6rs
                    |  #!chezscheme
                    |  #!fold-case
                    |  #!no-fold-case
```

R6RS 4.2.3 ends a line comment at U+2029 paragraph separator. Chez
Scheme 10.4.0 [`rd-token-comment`][chez-read-comment] does not; that
is a reader deviation, not a change to this production.

Datum comments are on by default: `#;` plus one datum. If no datum
follows, `read` reports an error. A block-comment body may contain
balanced nested block comments.

Directive names are the lowercase spellings in [CSUG §1.1][csug-intro].
After the name, reading continues at the next character. `#!r6rsfoo`
is the `#!r6rs` directive, then the symbol `foo`. `#!eof` and `#!bwp`
are data, not directives. See [Special object](#special-object).

### Delimiters and tokens

Adapted from R6RS 4.2.1. Braces, quote, backtick, and comma are Chez
delimiters reconstructed from [CSUG §1.1][csug-intro].

```text
<delimiter> --> <whitespace> | ( | ) | [ | ] | " | ; | #
             |  { | } | ' | ` | ,
```

As in R6RS, a token that needs implicit termination (identifier,
number, character, or dot) may end at any `<delimiter>`, and need not
end at any other character.

These are not delimiters: `|`, `\`, `.`, `:`, `@`, and the R6RS
identifier punctuation `! $ % & * + / < = > ? ^ _ ~`.

`{` and `}` are delimiters and also the one-character identifiers `{`
and `}`. They are not list brackets.

Quote, backtick, and comma start abbreviations only as the first
character of a datum. As Chez delimiters they also end a preceding
token, so `foo'bar` is the symbol `foo` then `'bar`. `#` starts a hash
object only as the first character of a datum. It also ends an
ordinary symbol, so `foo#t` is `foo` then `#t`.

R6RS terminates numbers at `#`. Chez Scheme 10.4.0
[`rd-token-number-or-symbol`][chez-read-number-symbol] may keep `#`
inside an unprefixed number-or-symbol token, so `32/#` is one token.
That is a reader deviation, not a change to this production. After
`#!r6rs`, `#` ends that token.

### Datum

Reconstructed. Graph marks, boxes, records, gensyms, and the other
Chez hash forms below are default syntax because those extensions are
on by default.

```text
<datum> --> <simple datum> | <compound datum>
<simple datum> --> <boolean> | <number> | <character> | <string>
                |  <symbol> | <gensym> | <special object>
                |  <graph reference>
<compound datum> --> <list> | <vector> | <bytevector>
                  |  <fxvector> | <flvector> | <stencil vector>
                  |  <box> | <record> | <abbreviation>
                  |  <primitive> | <graph mark>
<abbreviation> --> <abbrev prefix> <intertoken space> <datum>
<abbrev prefix> --> ' | ` | , | ,@ | #' | #` | #, | #,@
```

`#'datum` reads as `(syntax datum)`, `` #`datum `` as `(quasisyntax
datum)`, `#,datum` as `(unsyntax datum)`, and `#,@datum` as
`(unsyntax-splicing datum)`.

A graph reference `#n#` is itself a datum. It refers to a mark
described under [Graph marks and references](#graph-marks-and-references).

### Lists

Adapted from R6RS 4.3.2. Square brackets are included because matching
brackets are equivalent to matching parentheses.

```text
<list> --> ( <datum>* )
        |  ( <datum>+ . <datum> )
        |  [ <datum>* ]
        |  [ <datum>+ . <datum> ]
```

A closer of the other kind is an error (`parenthesized list terminated
by bracket`, and the reverse).

`.` as a whole token is the improper-tail marker. It is not a datum.
`..` and `...` are symbols, so they do not start an improper tail.
`( . x)` is an error (`unexpected dot (.)`).

### Boolean

Adapted from R6RS 4.2.5. The long names are reconstructed from
[CSUG §1.1][csug-intro]. The names are case-insensitive.

R6RS and CSUG list the spellings but not every adjacency. A boolean
is a complete name followed by a delimiter or end of input.

```text
<boolean> --> #t | #f | #true | #false
```

`#true` and `#false` are Chez extensions (error after `#!r6rs`).
`#tfoo` and `#tru1` are invalid booleans. `#truex` is an invalid
delimiter after a complete boolean name. `#true` is boolean true.
`(#true)` is a list of one boolean. `(#t foo)` is a list of boolean
true and the symbol `foo`.

### Number

Finite numbers use the R6RS 4.2.8 integer, rational, real, and complex
productions, including mantissa width `|` plus decimal digits after a
decimal real, and signed infinities and NaNs. Optional prefixes are
`#b`, `#o`, `#d`, `#x`, `#e`, and `#i`, in any case, in either order.

The sign is required on inf/nan; `inf.0` is a symbol.

Chez extensions are reconstructed from [CSUG §1.1][csug-intro] and
[Chapter 8][csug-numeric]:

```text
<arbitrary radix> --> #<n>r <number body>
                   |  #e#<n>r <number body>
                   |  #<n>r#e <number body>     ; same for #i
```

`<n>` is a decimal integer from 2 through 36. `#nr` / `#nR` is a Chez
extension. Digit letters `a`–`z` (any case) are values 10 through 35.
The body is the number syntax of that radix: integers, ratios, floats,
exponents, polar `@`, and rectangular `+` / `-` / `i`.

Digits take precedence over exponent markers. `#x1e20` is a
hexadecimal integer, not an exponent. `#x3.2e5` is a hexadecimal
float, not a decimal exponent.

Nondecimal `.` and exponent forms are Chez extensions. Exponent digits
use the current radix, so `#o1.4` and `#b1e10` are valid and `#o1e8`
is not.

R6RS writes mantissa width only for radix 10.

### Symbol

Ordinary symbols use the R6RS 4.2.4 identifier syntax. The Chez
extensions are reconstructed from [CSUG §1.1][csug-intro] and
[§7.11][csug-objects].

```text
<symbol> --> <r6rs identifier> | <chez identifier>
<chez identifier> --> <non-number>
                   |  { | }
                   |  <escaped symbol>
```

An R6RS identifier is `<initial> <subsequent>*` or a peculiar
identifier (`+`, `-`, `...`, `-> <subsequent>*`). `<initial>` includes
letters, the extended alphabet `! $ % & * / : < = > ? ^ _ ~`, inline
`<hex scalar escape>`, and Unicode constituents. `<hex scalar escape>`
is `\x` followed by one or more hexadecimal digits and `;`, naming a
Unicode scalar value. `<subsequent>` adds digits, `+ - . @`, and
Unicode Nd / Mc / Me.

A Chez `<non-number>` may begin with a digit, period, plus sign, or
minus sign if the complete token cannot be parsed as a number. CSUG
gives `0abc`, `+++`, and `..` as examples. A failed unprefixed number
may become a symbol; a failed prefixed number is an error.

`{` and `}` are one-character identifiers.

`\` escapes one following character, except that `\x` starts a hex
scalar escape. A `|...|` group quotes characters through the matching
bar. Inside a bar group, backslash is ordinary.

### Gensym

Reconstructed from [CSUG §1.1][csug-intro] and [§7.11][csug-objects].
There is no intertoken space after `#:`. The published `#{...}` form
has whitespace between the two names.

```text
<gensym> --> #:<symbol>
          |  #{<symbol><whitespace>+<symbol>}
```

`#:pretty` builds a gensym whose unique name is new. `#{pretty unique}`
stores both names. Both forms are Chez extensions.

### Keyword

Reconstructed from the absence of a keyword datum in CSUG. `#:name` is
a gensym, not a keyword. `:name` and `name:` are ordinary symbols.

### Character

Adapted from R6RS 4.2.6. Octal digits and extra names are reconstructed
from [CSUG §1.1][csug-intro] and [§7.3][csug-objects]. R6RS and CSUG list spellings
but not the first-character dispatch. The branch order below is the
verified Chez 10.4.0 interpretation.

```text
<character> --> #\<any character>
             |  #\<character name>
             |  #\x<hex scalar value>
             |  #\<octal digit> <octal digit> <octal digit>
```

After `#\`:

- Lowercase `x` followed by one or more hex digits is the hex scalar
  form, with no terminating `;`. `#\x` followed by a delimiter is the
  letter `x`. `#\x41` is U+0041.
- Two initial ASCII letters, except lowercase `x`, select the name
  path for the complete token. `#\xy` is an invalid character name.
- Two initial octal digits commit to exactly three octal digits.
- Otherwise one character is read and must be followed by a delimiter.
  `#\X41` is an error because `#\X` takes this branch and `4` is not a
  delimiter.

The three-octal-digit spelling is a Chez extension. Its value must be
at most 255. The hexadecimal value must name a Unicode scalar value.

Valid names in Chez mode:

- R6RS: `nul`, `alarm`, `backspace`, `tab`, `linefeed`, `newline`,
  `vtab`, `page`, `return`, `esc`, `space`, `delete`
- Extra: `bel` (same as `alarm`), `ls`, `nel`, `rubout` (same as
  `delete`), `vt` (same as `vtab`)

After `#!r6rs`, only the R6RS names are accepted.
[CSUG §7.3][csug-objects] documents that `char-name` may change the
set of extra names.

### String

Adapted from R6RS 4.2.7. `\'` and octal escapes are reconstructed from
[CSUG §7.4][csug-objects].

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  \ <string escape>
<string escape> --> a | b | t | n | v | f | r | " | \
                 |  x <hex digit>+ ;
                 |  '
                 |  <octal digit> <octal digit> <octal digit>
                 |  <intraline whitespace>* <line ending>
                    <intraline whitespace>*
<line ending> --> LF | CR | NEL | LS | CR LF | CR NEL
```

Intraline whitespace is tab or Unicode category Zs. An unescaped line
ending in a string is stored as newline; `CR LF` and `CR NEL` are
consumed as one line ending. A backslash continuation consumes the
line ending and following intraline whitespace without storing a
newline. Any other character after `\` is an error.

`\'` and exactly three octal digits (value at most 255) are Chez
extensions.

### Vector, bytevector, fxvector, flvector, stencil vector

`#vu8(` is R6RS. The other forms are reconstructed from
[CSUG §1.1][csug-intro] and [Chapter 7][csug-objects].

```text
<vector>         --> #( <datum>* )
                  |  #<n>( <datum>* )
<bytevector>     --> #vu8( <u8>* )
                  |  #<n>vu8( <u8>* )
<fxvector>       --> #vfx( <fixnum>* )
                  |  #<n>vfx( <fixnum>* )
<flvector>       --> #vfl( <flonum>* )
                  |  #<n>vfl( <flonum>* )
<stencil vector> --> #<n>vs( <datum>* )
<u8>             --> <number>           ; exact integer 0 through 255
```

`#vu8` is lowercase `vu8`. `#u8(` is not Chez; it is an invalid `#u`
prefix. `#v` is lowercase `v` only.

When `<n>` is present on a vector, bytevector, fxvector, or flvector,
it is the length. Extra elements are an error. Fewer elements are
filled by repeating the last printed element (`#100(0)`, `#3(a b)`).

A stencil vector's `<n>` is a mask, not a length, and is required.
`#vs(...)` is an error. The number of elements must equal the number
of bits set in the mask. There is no trailing-element fill.

Chez checks octet, fixnum, and flonum values while constructing each
object. These value checks do not change token boundaries.

### Box

Reconstructed from [CSUG §1.1][csug-intro] and [§7.10][csug-objects].

```text
<box> --> #& <intertoken space> <datum>
```

`#&17` is a box holding 17. Chez extension.

### Record

Reconstructed from [CSUG §1.1][csug-intro] and [§§7.15 and 7.17][csug-objects].

```text
<record> --> #[ <intertoken space> <record name> <datum>* ]
<record name> --> <symbol> | <gensym>
```

The name is a symbol, possibly a gensym. `read` looks up its record
type through `record-reader` or the type's UID, then checks the field
count. Those checks happen after the reader recognizes the `#[` ... `]`
form. This form is a Chez extension.

### Primitive abbreviation

Reconstructed from [CSUG §1.1][csug-intro]. There is no intertoken
space after `%`.

```text
<primitive> --> #%<symbol>
             |  #2%<symbol>
             |  #3%<symbol>
```

`#%car` reads as `($primitive car)`, `#2%car` as `($primitive 2 car)`,
and `#3%car` as `($primitive 3 car)`. `#20%` is an invalid prefix:
`n` must be 2 or 3. Chez extension.

### Graph marks and references

Reconstructed from [CSUG §1.1][csug-intro].

```text
<graph mark>      --> #<n>= <intertoken space> <datum>
<graph reference> --> #<n>#
```

`#n=` marks the following datum. `#n#` refers to that mark. Duplicate
marks and a reference with no mark are errors at `read` time. Chez
extension.

Examples: `'(#1=(a) . #1#)` is a pair whose car and cdr share one
list. `#0=(a . #0#)` is a cyclic list.

### Special object

Reconstructed from [CSUG §1.1][csug-intro]. These names are delimited
and case-sensitive.

```text
<special object> --> #!eof | #!bwp
```

`#!EOF` and `#!eofx` are invalid.

`#!eof` is the end-of-file object. If it appears outside any datum in
a file being loaded, `load` stops as at a true end of file.

`#!bwp` is the broken-weak-pointer object.

`#!eof` and `#!bwp` are Chez extensions.

## Optional reader syntax

These controls are off by default. `#!r6rs` disables default Chez
extensions. Fold-case changes name values, not token productions.

### R6RS-strict mode

**Activation:** encountering `#!r6rs`, or loading a library or RNRS
top-level program as described under [Target, inheritance, and default
reader](#target-inheritance-and-default-reader).
**Default:** off.

**Change:** later data use the inherited R6RS productions in place of
these Chez-default extensions:

| Reader concept | Chez-default production removed by `#!r6rs` |
| --- | --- |
| Booleans | Long `#true` and `#false` spellings. |
| Numbers | Arbitrary `#nr` radices and nondecimal floats. |
| Identifiers | Non-R6RS names, brace names, and Chez escapes or bar groups. |
| Characters and strings | Extra character names and octal spellings; octal and `\'` string escapes. |
| Collections | Sized vectors and sized bytevectors, fxvectors, flvectors, stencil vectors, boxes, and records. |
| Other hash forms | Gensyms, primitive abbreviations, graph marks and references, and special objects. |
| Delimiters | `{`, `}`, `'`, backtick, and comma as extra delimiters. |

**Interaction:** `#!chezscheme` clears R6RS-strict mode and restores
the default Chez extensions. After `#!r6rs`, a Chez-only delimiter
still ends the preceding token, then `read` reports an error
(`delimiter ~a is not allowed in #!r6rs mode`).

### Restoring Chez extensions

**Activation:** encountering `#!chezscheme`.
**Default:** off as a directive. The default reader is already Chez
mode.
**Change:** clears R6RS-strict mode for following data.

### Case folding

**Activation:** `#!fold-case`, or `(case-sensitive)` set to `#f`.
**Default:** off. `#!no-fold-case` turns folding off. Either fold
directive overrides `(case-sensitive)` until the other directive.

**Change:** later symbol and character names are folded as if by
`string-foldcase`. It changes values, not token productions.

[r6rs-lexical]: https://r6rs.org/final/html/r6rs/r6rs-Z-H-7.html
[csug-intro]: https://cisco.github.io/ChezScheme/csug/intro.html
[csug-objects]: https://cisco.github.io/ChezScheme/csug/objects.html
[csug-numeric]: https://cisco.github.io/ChezScheme/csug/numeric.html
[csug-scripts]: https://cisco.github.io/ChezScheme/csug/use.html
[chez-read]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss
[chez-strnum]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/strnum.ss
[chez-read-comment]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L431
[chez-read-number-symbol]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L930
