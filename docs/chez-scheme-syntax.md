# Chez Scheme 10.4.0 reader syntax

## Scope and sources

This reference describes data accepted by the Chez Scheme 10.4.0
reader in its default and documented optional modes. Chez inherits the R6RS lexical grammar and adds the forms listed in
[CSUG 10.4, §1.1][csug-intro] and its chapters on objects and numbers. The
default reader is case-sensitive and has R6RS-strict mode off. This document
covers external representations, not the syntax or meaning of forms such as
`lambda` and `if`.

The published sources are [R6RS, chapter 4][r6rs-lexical], [R5RS,
§7.1.1][r5rs-lexical] for the retained `#` digit placeholder, and these
sections of the Chez Scheme User's Guide 10.4:

- [§1.1][csug-intro] summarizes Chez lexical extensions.
- [Chapter 7][csug-objects] covers characters (§7.3), strings (§7.4), vectors
  (§7.5), fxvectors (§7.6), flvectors (§7.7), bytevectors (§7.8), stencil
  vectors (§7.9), boxes (§7.10), symbols and gensyms (§7.11), and records
  (§§7.15 and 7.17).
- [Chapter 8][csug-numeric] covers arbitrary radices, nondecimal floats,
  infinities, and NaNs.
- [Scheme shell scripts][csug-scripts] describes the interpreter line handled
  by the script loader.

The productions below are **adapted** from R6RS when they restate an inherited
rule. Productions for Chez extensions are **reconstructed** from the cited
CSUG prose unless a paragraph gives another source. None is a verbatim quote.
Where the published sources leave token boundaries unclear, the later
[implementation-evidence section](#documentation-gaps-and-implementation-evidence)
records an observation from Chez Scheme 10.4.0 [`s/read.ss`][chez-read] or
[`s/strnum.ss`][chez-strnum]. Those observations do not replace a clear
published rule. This reference describes the reader independently of the
Tree-sitter parser.

### Notation

`<thing>*` means zero or more; `<thing>+` means one or more. `empty` is the
empty string. `datum*` in prose means zero or more data separated by
intertoken space. `<hex digit>` is `0`–`9` or `a`–`f`; `<octal digit>` is
`0`–`7`. Unless stated otherwise, case is insignificant in boolean names,
number prefixes, and hexadecimal digits. Directive and special-object names
are case-sensitive.

Reader construction also checks values that token syntax alone cannot decide,
such as Unicode scalar validity, numeric conversion, vector lengths, record
types, and graph references. Those restrictions are identified where relevant.

## Default reader syntax

### Intertoken space

```text
<intertoken space> --> <atmosphere>*
<atmosphere>       --> <whitespace> | <comment> | <directive>
<whitespace>       --> space | tab | newline | formfeed | return
                    |  <other char-whitespace?>
<comment>          --> <line comment>
                    |  <block comment>
                    |  <datum comment>
<line comment>     --> ; <any character except newline, return, NEL, LS, PS>*
<block comment>    --> #| <nested block-comment body> |#
<datum comment>    --> #; <intertoken space> <datum>
```

`#;` comments out exactly one following datum in the default mode. If
no datum follows, `read` reports an error.

The block-comment body may contain balanced nested block comments.

### Datum

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

`#'datum` reads as `(syntax datum)`, `` #`datum `` as `(quasisyntax datum)`,
`#,datum` as `(unsyntax datum)`, and `#,@datum` as `(unsyntax-splicing datum)`.

A graph reference `#n#` is itself a datum. It refers to a mark described
under [Graph marks and references](#graph-marks-and-references).

### Lists

```text
<list> --> ( <datum>* )
        |  ( <datum>+ . <datum> )
        |  [ <datum>* ]
        |  [ <datum>+ . <datum> ]
```

Matching brackets are equivalent to matching parentheses. A closer of the
other kind is an error (`parenthesized list terminated by bracket`, and the
reverse).

`.` as a whole token is the improper-tail marker. It is not a datum.
`..` and `...` are symbols, so they do not start an improper tail.
`( . x)` is an error (`unexpected dot (.)`); unlike Guile, a leading dot is
not accepted as `(x)`.

`{` and `}` never bracket a list.

### Boolean

Boolean names are case-insensitive and must be delimited.

```text
<boolean> --> #t | #T | #f | #F
           |  #true | #TRUE | ...     ; any case; Chez extension
           |  #false | #FALSE | ...
```

`(#t foo)` is a list. `(#true)` is boolean true. `(#tfoo)` and `(#tru1)`
are invalid booleans. `(#truex)` is an invalid delimiter after a complete
boolean name. This is stricter than R7RS and Guile, which may stop at `#t`
and leave the extra letters.

`#true` and `#false` are Chez extensions (error after `#!r6rs`).

### Number

The number spellings are R6RS section 4.2.8 (including mantissa width
`x|p`, `+inf.0`, `-inf.0`, and `+nan.0` / `-nan.0`), plus Chez extensions
below. Case is not significant in number syntax. The sign is required on
inf/nan; `inf.0` is a symbol. `#e+inf.0` cannot be represented.

Chez mode also accepts:

```text
<chez number extra> --> <arbitrary radix>
                     |  <nondecimal float or exponent>
                     |  <nondecimal mantissa width>
                     |  <r5rs hash placeholder>
<arbitrary radix>   --> #<n>r <chez number body>
                     |  #e#<n>r <chez number body>
                     |  #<n>r#e <chez number body>     ; same for #i
```

`<n>` is decimal digits whose value is 2 through 36. Leading zeros are
allowed (`#02r10`). `#nr` / `#nR` is a Chez extension. The body is the same
number syntax as that radix: integers, ratios, floats, exponents, polar
`@`, rectangular `+` / `-` / `i`, inf/nan, mantissa width, and `#`
placeholders. Digit letters `a`–`z` (any case) are values 10 through 35.

Digits take precedence over exponent markers, the imaginary suffix, and
inf/nan names. `#x1e20` is a hexadecimal integer, not an exponent.
`#16r1+1i` is rectangular because `i` is not a hex digit. `#36r1+2i` is
invalid because `i` is a digit in radix 36. `#16r+inf.0` is infinity;
`#36r+inf.0` is the inexact real `24171.0`, because `i`, `n`, and `f` are
radix-36 digits.

`#o1.4` and `#b1e10` are nondecimal floats. Those `.` and exponent forms in
a non-decimal radix are Chez extensions. Exponent digits use the current
radix, so `#b1e10` is valid and `#o1e8` is not.

Mantissa width `|` plus decimal digits is allowed after an integer or float
in any radix (`1.0|53`, `#x1|53`, `#16r1|53`). It is not allowed after a
ratio (`#x1/2|53` is invalid). R6RS writes this form only for radix 10.

R5RS `#` placeholders such as `98##` and `#e98##` remain in Chez mode.
R6RS removed them. After `#!r6rs` they are an error.

### Symbol

```text
<symbol> --> <r6rs identifier>
          |  <delimited non-number>          ; Chez
          |  { | }                           ; Chez
          |  <escaped symbol>                ; Chez
```

An R6RS identifier is `<initial> <subsequent>*` or a peculiar identifier
(`+`, `-`, `...`, `-> <subsequent>*`). `<initial>` includes letters, the
extended alphabet `! $ % & * / : < = > ? ^ _ ~`, inline
`<hex scalar escape>`, and Unicode constituents (R6RS 4.2.1).
`<hex scalar escape>` is `\x` followed by one or more hexadecimal digits and
`;`, naming a Unicode scalar value. `<subsequent>` adds digits, `+ - . @`,
and Unicode Nd / Mc / Me.

CSUG §§1.1 and 7.11 publish these extensions:

- A sequence may begin with a digit, period, plus sign, or minus sign if it
  cannot be parsed as a number. CSUG gives `0abc`, `+++`, and `..` as examples.
- `{` and `}` are one-character identifiers.
- `\` escapes one following character, except that `\x` starts a hex scalar
  escape. A `|...|` group quotes characters through the matching bar.

Inside a bar group, backslash is ordinary. Ordinary runs and escaped parts may
be combined in one symbol. CSUG does not specify every token boundary for
these forms; see the [reader evidence](#how-read-tokenizes).

### Gensym

```text
<gensym> --> #: <symbol>
          |  #{ <symbol> <gensym space>+ <symbol> }
<gensym space> --> space | newline | tab
```

`#:pretty` builds a gensym whose unique name is new. `#{pretty unique}`
stores both names.

Both forms are Chez extensions.

### Keyword

Chez has no separate keyword datum. `#:name` is a gensym, not a keyword.
`:name` and `name:` are ordinary symbols.

### Character

R6RS and CSUG publish these character forms:

```text
<character> --> #\<any character>
             |  #\<character name>
             |  #\x<hex scalar value>
             |  #\<octal digit> <octal digit> <octal digit> ; Chez
```

The three-octal-digit spelling is a Chez extension and its value must be at
most 255. The hexadecimal value must name a Unicode scalar value. These are
semantic constraints rather than token boundaries.

Valid names in Chez mode (`char-name`; CSUG tables plus the R6RS set):

- R6RS: `nul`, `alarm`, `backspace`, `tab`, `linefeed`, `newline`, `vtab`,
  `page`, `return`, `esc`, `space`, `delete`
- Extra: `bel` (same as `alarm`), `ls`, `nel`, `rubout` (same as `delete`),
  `vt` (same as `vtab`)

After `#!r6rs`, only the R6RS names are accepted.

### String

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  \ <string escape>
<string escape> --> a | b | t | n | v | f | r | " | \
                 |  x <hex digit>+ ;
                 |  '                                          ; Chez
                 |  <octal digit> <octal digit> <octal digit>  ; Chez
                 |  <intraline whitespace>* <line ending>
                    <intraline whitespace>*
<line ending> --> LF | CR | NEL | LS | CR LF | CR NEL
```

Intraline whitespace is tab or Unicode category Zs. An unescaped line ending
in a string is stored as newline; `CR LF` and `CR NEL` are consumed as one
line ending. A backslash continuation consumes the line ending and following
intraline whitespace without storing a newline. Any other character after
`\` is an error.

`\'` and exactly three octal digits (value at most 255) are Chez
extensions.

### Vector, bytevector, fxvector, flvector, stencil vector

```text
<vector>      --> #( <datum>* )
               |  #<n>( <datum>* )              ; Chez
<bytevector>  --> #vu8( <u8>* )
               |  #<n>vu8( <u8>* )              ; Chez
<fxvector>    --> #vfx( <fixnum>* )             ; Chez
               |  #<n>vfx( <fixnum>* )
<flvector>    --> #vfl( <flonum>* )             ; Chez
               |  #<n>vfl( <flonum>* )
<stencil vector> --> #<n>vs( <datum>* )         ; Chez; n is the mask
<u8>          --> <number>                      ; exact integer 0 through 255
```

`#vu8` is lowercase `vu8`. `#u8(` is not Chez; it is an invalid `#u`
prefix.

When `<n>` is present on a vector, bytevector, fxvector, or flvector, it is
the length. Extra elements are an error. Fewer elements are filled by
repeating the last printed element (`#100(0)`, `#3(a b)`). Empty
`#n()` does not fill; the remaining slots are unspecified.

A stencil vector's `<n>` is a mask, not a length, and is required.
`#vs(...)` is an error (`mask required for stencil vector`). The number of
elements must equal the number of bits set in the mask. There is no trailing-element fill.

Chez checks octet, fixnum, and flonum values while constructing each object.
These value checks do not change token boundaries.

### Box

```text
<box> --> #& <intertoken space> <datum>
```

`#&17` is a box holding 17. Atmosphere is allowed after `#&`. Chez
extension.

### Record

```text
<record> --> #[ <intertoken space> <record name> <datum>* ]
<record name> --> <symbol> | <gensym>
```

The name is a symbol, possibly a gensym. `read` looks up its record type
through `record-reader` or the type's UID, then checks the field count.
Those checks happen after the reader recognizes the `#[` ... `]` form. This
form is a Chez extension.

### Primitive abbreviation

```text
<primitive> --> #% <symbol>
             |  #2% <symbol>
             |  #3% <symbol>
```

`#%car` reads as `($primitive car)`, `#2%car` as `($primitive 2 car)`, and
`#3%car` as `($primitive 3 car)`. Atmosphere is not skipped after `%`.
`#20%` is an invalid prefix (`n` must be 2 or 3). Chez extension.

### Graph marks and references

```text
<graph mark>      --> #<n>= <intertoken space> <datum>
<graph reference> --> #<n>#
```

`#n=` marks the following datum. Atmosphere is allowed after `=`. `#n#`
refers to that mark. Duplicate marks and a reference with no mark are
errors at `read` time. Chez extension (R7RS has a similar form; R6RS does
not).

Examples: `'(#1=(a) . #1#)` is a pair whose car and cdr share one list.
`#0=(a . #0#)` is a cyclic list.

### Special object

```text
<special object> --> #!eof | #!bwp
```

These names are delimited and case-sensitive. `#!EOF` and `#!eofx` are
invalid.

`#!eof` is the end-of-file object. If it appears outside any datum in a
file being loaded, `load` stops as at a true end of file.

`#!bwp` is the broken-weak-pointer object.

`#!eof` and `#!bwp` are Chez extensions.

## Optional reader syntax and controls

The following controls alter Chez reader state. They are atmosphere, not data.
Their names are lowercase and case-sensitive. `#!eof` and `#!bwp` are data,
not controls. Chez Scheme 10.4.0 `s/read.ss`, `rd-token-hash-bang`, documents
the dispatch behavior; CSUG §1.1 describes the published mode controls.

```text
<directive> --> #!r6rs | #!chezscheme | #!fold-case | #!no-fold-case
```

| Control | Default | Activation and effect | Interaction |
| --- | --- | --- | --- |
| `#!r6rs` | Off | Encountering it enables R6RS-strict reader syntax for following data. | Chez extensions below are rejected until `#!chezscheme`. |
| `#!chezscheme` | Off | Encountering it clears R6RS-strict mode for following data. | Restores the default Chez extensions. |
| `#!fold-case` | Off | Encountering it folds later symbol and character names with `string-foldcase`. | Overrides `(case-sensitive)` until `#!no-fold-case`. It changes values, not token productions. |
| `#!no-fold-case` | Off | Encountering it preserves written case in later names. | Overrides `(case-sensitive)` until `#!fold-case`. It changes values, not token productions. |
| `(case-sensitive)` | `#t` | A reader parameter used before either fold directive. | Does not change the set of accepted tokens. |

R6RS-strict mode uses the inherited R6RS productions in place of these
Chez-default extensions:

| Reader concept | Chez-default production removed by `#!r6rs` |
| --- | --- |
| Booleans | Long `#true` and `#false` spellings. |
| Numbers | Arbitrary `#nr` radices, nondecimal floats and mantissa widths, and R5RS `#` placeholders. |
| Identifiers | Non-R6RS delimited names, brace names, and Chez escapes or bar groups. |
| Characters and strings | Chez character names and octal spellings; octal and `\'` string escapes. |
| Collections | Sized vectors and sized bytevectors, fxvectors, flvectors, stencil vectors, boxes, and records. |
| Other hash forms | Gensyms, primitive abbreviations, graph marks and references, and special objects. |

`#!r6rs` also disallows Chez-only delimiters `{`, `}`, quote, backtick, and
comma where the strict reader would otherwise see them after a token. The
reader still finds that boundary and then reports an error. The published
sources do not specify every resulting tokenization detail; the evidence below
records the observed interpretation.
## Documentation gaps and implementation evidence

The following notes describe Chez Scheme 10.4.0 `read` token boundaries and
other gaps in the published syntax. They are not normative when R6RS or CSUG
is clear.

### How `read` tokenizes

**Question:** How does Chez divide adjacent forms when CSUG gives a spelling
without a complete lexer algorithm? **Published gap:** CSUG §1.1 lists the
forms but does not specify every boundary. **Evidence:** Chez Scheme 10.4.0
[`s/read.ss`, `rd-token`][chez-read-token],
[`rd-token-delimiter`][chez-read-delimiter], and
[`rd-token-to-delimiter`][chez-read-to-delimiter]. For example, the code paths for
`foo#t` yield a symbol followed by a boolean, while `32/#` stays one
number-or-symbol token. These examples are inferences from the cited source,
not quoted CSUG rules. **Conclusion:** The following dispatch and delimiter
tables describe this implementation. They are implementation observations, not additional published
productions. CSUG leaves the exact adjacency of number-or-symbol tokens
unspecified; the source code supports only a Chez 10.4.0 interpretation.

The reader skips atmosphere, examines the first character, then reads a token
or enters a nested form such as a list, string, or hash dispatch.

#### Skip

Before a datum, `read` loops on the next character:

| Character | Action |
| --- | --- |
| space, tab, newline | skip |
| formfeed, return | skip |
| other `char-whitespace?` | skip |
| `;` | skip a line comment, then skip again |
| `#` then `;` | skip one datum, then skip again |
| `#` then `\|` | nested `#\| ... \|#`, then skip again |
| `#` then `!` then `r6rs` / `fold-case` / `no-fold-case` / `chezscheme` | set port flags, then skip again |
| other `#` | that `#` starts a hash object |
| anything else | that character starts a datum |

`#!r6rs`, `#!fold-case`, `#!no-fold-case`, and `#!chezscheme` need not be
followed by a delimiter. `#!r6rsfoo` is the `#!r6rs` directive, then the
symbol `foo`. Those four names are matched exactly, in lowercase.

A `#!` interpreter line is not this skip. `read` itself treats `#!/...` and
`#! ...` as invalid `#!` syntax. The script loader ignores the first line of
a loaded script when that line begins with `#!` followed by a space or `/`.
`compile-program` copies that line into the object file.

Libraries loaded by `import`, and RNRS top-level programs loaded by
`--program`, `scheme-script`, or `load-program`, are treated as if they
begin with `#!r6rs`. That prefix is the loader, not one `read` call.

#### Delimiters

Ordinary tokens end at a delimiter or at end of input. Some reader branches
use narrower boundaries, described below.

```text
<r6rs delimiter>  --> ( | ) | [ | ] | " | ; | #
                   |  <whitespace>
<chez delimiter>  --> <r6rs delimiter> | { | } | ' | ` | ,
```

Default Chez uses the Chez set. After `#!r6rs`, `{`, `}`, `'`, backtick,
and comma still end the token, and the reader then reports an error
(`delimiter ~a is not allowed in #!r6rs mode`) instead of reading on.

These are not delimiters: `|`, `\`, `.`, `:`, `@`, and the R6RS identifier
punctuation `! $ % & * + / < = > ? ^ _ ~`.

- Quote, backtick, and comma start abbreviations only as the first character
  of a datum. As Chez delimiters they also end a preceding token, so
  `foo'bar` is the symbol `foo` then `'bar`.
- `#` starts a hash object only as the first character of a datum. It also
  ends an ordinary symbol, so `foo#t` is `foo` then `#t`.
- In Chez mode, a token that already went through the number-or-symbol
  reader may contain `#`. `32/#` is one token. After `#!r6rs`, `#` ends
  that token instead.
- `|` is not a delimiter. It starts a `|...|` group inside a symbol, and it
  is an ordinary character inside a number-or-symbol token, so `32/#|foo|`
  is one identifier.
- `{` and `}` are delimiters and also the one-character identifiers `{` and
  `}`. They are not list brackets.

#### First character of a datum

| First character | Reader |
| --- | --- |
| `(` | list to `)` |
| `[` | list to `]` |
| `{` `}` | the identifier `{` or `}` (error after `#!r6rs`) |
| `"` | string |
| `'` `` ` `` `,` `,@` | abbreviation, then one datum |
| `#` | hash dispatch |
| `)` `]` | error |
| `0`–`9` | one token; `$str->num`, else a (nonstandard) symbol |
| `+` `-` `.` | peculiar identifier, dot, or number-or-symbol (see below) |
| letter, or R6RS constituent | symbol |
| `\|` `\` | symbol (bar group or escape) |
| other non-delimiter | symbol (nonstandard) |

`+` and `-` as a whole token are the identifiers `+` and `-`. `->` starts a
symbol. `.` as a whole token is the dotted-list marker. `..` is a
nonstandard symbol. `...` is the identifier `...`. Any other continuation
after `+`, `-`, or `.` is one number-or-symbol token.

#### Hash dispatch

After `#`, the next character selects a reader. Unknown `#` plus a
character is an error (`invalid sharp-sign prefix`). There is no
`read-hash-extend` callback.

The dispatch character is case-sensitive except where the table lists both
cases. `#v` is lowercase `v` only. `#Vu8(` is an invalid prefix. `#t` /
`#T` / `#f` / `#F` and the radix / exactness letters accept both cases.

| After `#` | Production |
| --- | --- |
| `t` `T` `f` `F` | boolean |
| `\` | character |
| `(` | vector |
| `'` `` ` `` `,` `,@` | syntax abbreviations |
| `0`–`9` | sized vector, `#nr` number, graph mark/ref, sized `#v...`, or `#2%` / `#3%` |
| `[` | record |
| `{` | gensym `#{pretty unique}` |
| `&` | box |
| `;` | datum comment (atmosphere) |
| `!` | directive or special object |
| `x` `X` `o` `O` `b` `B` `d` `D` `i` `I` `e` `E` | prefixed number |
| `v` | `#vu8(` / `#vfx(` / `#vfl(` / `#vs(` |
| `%` | `#%name` primitive |
| `:` | `#:pretty` gensym |
| `\|` | block comment (atmosphere) |
| `@` | old fasl; `read` always errors |

After `#` plus decimal digits `n`:

| Suffix | Production |
| --- | --- |
| `(` | `#n(datum*)` vector |
| `r` `R` | `#nr` prefixed number, radix 2 through 36 |
| `#` | graph reference `#n#` |
| `=` | graph mark `#n=` |
| `vu8(` | `#nvu8(number*)` |
| `vfx(` | `#nvfx(number*)` |
| `vfl(` | `#nvfl(number*)` |
| `vs(` | `#nvs(datum*)` stencil vector |
| `%` | `#2%name` or `#3%name` only (`n` must be 2 or 3) |
| `q` `Q` | error (outdated object file format) |

`#vu8(` is standard R6RS. The length prefix, fxvector, flvector, stencil
vector, box, record, gensym, graph, primitive, `#true` / `#false`, and
`#nr` forms are Chez extensions (error after `#!r6rs` until `#!chezscheme`).

### Character token boundaries

**Question:** Which character branch wins when a name starts with `x`, letters,
or octal digits? **Published gap:** R6RS §4.2.6 and CSUG §7.3 list spellings
but not the complete first-character dispatch. **Evidence:** Chez Scheme
10.4.0 [`s/read.ss`, `rd-token-char` and `rd-token-char-hex`][chez-read-char].
For example, `#\x41` reads U+0041, while `#\X41` is rejected after the
single-character path. **Conclusion:** The branch order below is observed
10.4.0 behavior; the published valid spellings remain the baseline.

After `#\`, `read` chooses one branch from the first character:

- Lowercase `x` followed by one or more hex digits reads a hex character
  without a terminating `;`. If a non-hex, non-delimiter follows that hex
  run, Chez tries the complete token as a character name; a name-table lookup
  failure is a read error.
- Two initial ASCII letters, except lowercase `x`, select the name path for
  the complete token.
- Two initial octal digits commit to exactly three octal digits.
- Otherwise one character is read and must be followed by a delimiter.

Thus `#\x` followed by a delimiter is the letter `x`, while `#\x41` is
U+0041. Chez rejects `#\X41` and `#\xy` because the one-character branch
requires a delimiter.

### Other reader permissiveness

The following observations come from Chez Scheme 10.4.0
[`s/read.ss`][chez-read]. The named source locations provide the evidence; the examples can be passed
to `read` through a string input port. Where the cited code alone establishes
a behavior, the observation is source inspection and the example is an
inference from that code. CSUG does not publish these permissive empty-name spellings or the internal `#!base-rtd`
object. They remain implementation evidence, not public syntax.

| Question and example | Source observation | Conclusion |
| --- | --- | --- |
| Does `#!fold-case |MiX|` fold the escaped name? | [`maybe-fold/intern`][chez-read-fold] checks a slashed flag before folding. | The code implies that escaped symbol parts retain their case. |
| Is `0abc` a read error? | [`rd-token-number-or-symbol`][chez-read-number-symbol] passes the complete token to numeric conversion, then falls back to a symbol. | A failed unprefixed number may become a symbol; a failed prefixed number is an error. |
| Does `#truex` become `#true` then `x`? | [`rd-token-boolean`][chez-read-boolean] consumes the long name and [`rd-token-delimiter`][chez-read-delimiter] checks the next character. | The complete input is a read error. |
| Is `#: a` accepted, and may a comment separate names in `#{a b}`? | [`rd-token-gensym`][chez-read-gensym] reads a name immediately after `#:`; between two names it skips only space, newline, and tab. | General atmosphere is not accepted at those positions. |
| Are `#:`, `#{a}`, `#{}`, `#%`, and `#2%` accepted? | [`rd-token-gensym` and hash dispatch][chez-read-hash] permit empty name segments. | These are 10.4.0 reader permissiveness, not published spellings. |
| Can `(char-name 'snowman #\x2603)` make `#\snowman` readable? | [`char-name`][chez-read-char-name] adds the name to the table used by `rd-token-charname`. This is a source-based inference; the document does not claim an interpreter run. | Accepted character names can change at runtime. |
| What is `#!base-rtd`? | [`rd-token-hash-bang2`][chez-read-bang] accepts this internal singleton; the [implementation guide][impl-base-rtd] mentions it. | It is internal implementation syntax, not a published public object. |

CSUG explicitly names `0abc`, `+++`, and `..` as identifiers. Source
inspection supplies the narrower tokenization details: `@home` begins a
symbol, and `rd-token-symbol` and `rd-token-number-or-symbol` select the
complete token around `\` and `|...|` segments. The empty-name forms and internal object are observations,
not additions to the published grammar. Their behavior outside Chez Scheme
10.4.0 is unresolved.

## Known deviations from published syntax

**Question and published rule:** R6RS §4.2.1 ends a line comment at U+2029
paragraph separator. **Evidence:** Chez Scheme 10.4.0
[`s/read.ss`, `rd-token-comment`][chez-read-comment]. Reading `;x`
followed by U+2029 and `y` consumes `y` as comment text. **Conclusion:** This is a reader deviation, not a change to the
published production above.

[r6rs-lexical]: https://r6rs.org/final/html/r6rs/r6rs-Z-H-7.html
[r5rs-lexical]: https://www.cs.cornell.edu/courses/cs212/1999FA/r5rs-html/r5rs_72.html
[csug-intro]: https://cisco.github.io/ChezScheme/csug/intro.html
[csug-objects]: https://cisco.github.io/ChezScheme/csug/objects.html
[csug-numeric]: https://cisco.github.io/ChezScheme/csug/numeric.html
[csug-scripts]: https://cisco.github.io/ChezScheme/csug/use.html
[chez-read]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss
[chez-read-token]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L318
[chez-read-delimiter]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L504
[chez-read-to-delimiter]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L792
[chez-read-char]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L594
[chez-read-fold]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L194
[chez-read-number-symbol]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L930
[chez-read-hash]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L438
[chez-read-bang]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L695
[chez-read-boolean]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L479
[chez-read-gensym]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L513
[chez-read-char-name]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L1864
[chez-read-comment]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss#L431
[chez-strnum]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/strnum.ss
[impl-base-rtd]: https://github.com/cisco/ChezScheme/blob/v10.4.0/IMPLEMENTATION.md#compiled-files-and-boot-files
