# Chez Scheme Reader Syntax

This is the reader syntax reference for Chez Scheme. The target is
Chez Scheme 10.4.0.

Chez Scheme is R6RS plus documented lexical extensions. Chapter 4 of R6RS is
the formal core. Chez Scheme User's Guide 10.4 section 1.1 lists the extra
spellings. Per-type chapters add detail. Form-level syntax (`lambda`, `if`,
and the rest of the Summary of Forms) is not datum syntax.

This document presents published R6RS and Chez Scheme syntax first. An
**Implementation Behavior** section records token-boundary details that the
published sources do not specify. Observed behavior is descriptive and does
not override published syntax. A separate compatibility note identifies a
known reader deviation from a clear R6RS rule.

It describes Chez reader syntax, not the current `dialects/chez/` grammar.

## Sources

- Token rules: Chez Scheme 10.4.0 [`s/read.ss`][chez-read]
- Number spellings: Chez Scheme 10.4.0 [`s/strnum.ss`][chez-strnum]
- [Chez Scheme User's Guide 10.4, section 1.1][csug-intro] is the main
  syntax summary
- Per-type chapters in [Operations on Objects][csug-objects]: characters
  (7.3), strings (7.4), vectors (7.5), fxvectors (7.6), flvectors (7.7),
  bytevectors (7.8), stencil vectors (7.9), boxes (7.10), symbols and
  gensyms (7.11), records (7.15 / 7.17)
- [Numbers][csug-numeric] (CSUG chapter 8 opening) for `#nr`, nondecimal
  floats, and inf/nan
- [Scheme shell scripts][csug-scripts] show the `#!` interpreter line used
  at the start of a script file. That skip is the script loader, not `read`.
- [Chez Scheme's implementation guide][impl-base-rtd] describes the
  internal `#!base-rtd` singleton
- Inherited formal core: R6RS chapter 4 in `docs/r6rs.txt`. R5RS section
  7.1.1 in `docs/r5rs.txt` documents the `#` digit placeholders that Chez
  mode still accepts.

## Notation

The grammar uses the R6RS BNF extensions. `<thing>*` is zero or more.
`<thing>+` is one or more. `empty` is the empty string. `datum*` in running
text means zero or more data with intertoken space between them.

The productions below give the inherited R6RS formal core. Chez extensions and
default-reader deviations are marked explicitly; named directives can change
which extensions the runtime reader accepts.
Case in boolean names, number prefixes, and hex digits is not significant
except where a production says otherwise. Directive names and `#!eof` /
`#!bwp` are case-sensitive. `<hex digit>` is `0`–`9` and `a`–`f`.
`<octal digit>` is `0`–`7`.

A parser that only checks token shape may accept text that later fails in
`$str->num`, `integer->char`, vector-length fill, record lookup, or graph
fixup.

## Published Reader State

These flags are parameters of the grammar. Default Chez is case-sensitive
and not in R6RS-strict mode.

| Control | Default | Effect on syntax |
| --- | --- | --- |
| `#!r6rs` | off | reject Chez lexical extensions |
| `#!chezscheme` | off | clear the R6RS-strict flag |
| `#!fold-case` | off | fold later symbol and character names with `string-foldcase` |
| `#!no-fold-case` | off | keep written case |
| `(case-sensitive)` | `#t` | used only when neither fold directive has been seen |

These directives are atmosphere, not data. `#!eof` and `#!bwp` are data
(special objects). They must be delimited. Their names are matched exactly.

```text
<directive> --> #!r6rs
             |  #!chezscheme
             |  #!fold-case
             |  #!no-fold-case
```

## Formal Syntax

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

`#;` then one datum is on by default. End of input before that datum is an
error.

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

A graph reference `#n#` is a simple use of a mark, not a new compound
shape. See Shared structure.

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

### Number and symbol

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

Chez also accepts:

- a delimited sequence that starts with a digit, `.`, `+`, or `-` when
  `$str->num` rejects it (`0abc`, `+++`, `..`)
- a name that begins with `@` (`@home`), except that `,@` is
  unquote-splicing
- `{` and `}` as one-character identifiers
- `\` then any character except that `\x` is a hex scalar value with a
  terminating `;`
- `|...|` as a group of literal characters up through the matching `|`

Inside `|...|`, backslash is ordinary. `\x` hex and single-character `\`
escapes apply outside the bars. A shape-only parser can treat a Chez
symbol as a run of non-delimiters, `<hex scalar escape>`, `\` plus one
character, and `|...|` groups.

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
`#vs(...)` is an error (`mask required for stencil vector`). The number of elements must equal
the number of bits set in the mask. There is no trailing-element fill.

Chez enforces octet, fixnum, and flonum constraints while constructing the
object during `read`. These are semantic rather than lexical constraints,
not token boundaries.

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

The name must be a symbol (including a gensym). `read` then looks up a
record type by `record-reader` or the type's uid. The field count must
match that type. Those lookups are runtime. A shape-only parser can treat
`#[` ... `]` as a record with a symbol or gensym name and datum fields.

Chez extension.

### Primitive abbreviation

```text
<primitive> --> #% <symbol>
             |  #2% <symbol>
             |  #3% <symbol>
```

`#%car` reads as `($primitive car)`, `#2%car` as `($primitive 2 car)`, and
`#3%car` as `($primitive 3 car)`. Atmosphere is not skipped after `%`.
`#20%` is an invalid prefix (`n` must be 2 or 3). Chez extension.

### Shared structure

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

## Implementation Behavior

The following notes describe Chez Scheme 10.4.0 `read` token boundaries and
other gaps in the published syntax. They are not normative when R6RS or CSUG
is clear.

### How `read` tokenizes

`read` does not match a context-free grammar of names. It skips atmosphere,
looks at the next character, and either reads a delimited token or enters a
nested reader (`(`, `"`, `#`, and so on).

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

A token ends at a delimiter or at end of input.

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

- `'` , backtick, and comma start abbreviations only as the first character
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

`|...|` and a non-hex `\` escape set an internal slashed flag, preventing
case folding of that name even after `#!fold-case`.

Boolean dispatch consumes the remainder of `true` or `false` when a letter
follows the short name; a mismatch is an error. Number-or-symbol tokens are
passed to `$str->num`, and a failed unprefixed number becomes a symbol. A
failed prefixed number is an error instead.

Atmosphere is not skipped after `#:`. Inside `#{pretty unique}`, only space,
newline, and tab separate the two names. `char-name` may extend the character
name table at run time.

Chez Scheme 10.4.0 also accepts empty symbol segments in `#:`, `#{a}`,
`#{}`, `#%`, and `#2%`. These forms are reader permissiveness, not
published Chez syntax.

`#!base-rtd` is an internal boot singleton accepted by Chez source and
tests. CSUG does not document it as public reader syntax.

## Non-normative Compatibility Note

R6RS says a line comment ends at U+2029 paragraph separator. Chez Scheme
10.4.0 `read` instead consumes U+2029 as line-comment text. This observed
deviation does not change the formal production above.

[csug-intro]: https://cisco.github.io/ChezScheme/csug/intro.html
[csug-objects]: https://cisco.github.io/ChezScheme/csug/objects.html
[csug-numeric]: https://cisco.github.io/ChezScheme/csug/numeric.html
[csug-scripts]: https://cisco.github.io/ChezScheme/csug/use.html
[chez-read]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss
[chez-strnum]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/strnum.ss
[impl-base-rtd]: https://github.com/cisco/ChezScheme/blob/v10.4.0/IMPLEMENTATION.md#compiled-files-and-boot-files
