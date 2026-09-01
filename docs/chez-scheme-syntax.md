# Chez Scheme Reader Syntax

This is the restart reference for a Chez Scheme dialect parser. The target is
Chez Scheme 10.4.0.

Chez Scheme is R6RS plus documented lexical extensions. Chapter 4 of R6RS is
the formal core. Chez Scheme User's Guide 10.4 section 1.1 lists the extra
spellings. Per-type chapters add detail. Form-level syntax (`lambda`, `if`,
and the rest of the Summary of Forms) is not datum syntax.

This document has two layers:

- **Published forms.** Names and spellings from CSUG 10.4 and R6RS chapter 4.
- **Token rules.** How `read` skips input, where a token ends, and how the
  first character chooses a reader. Those rules are extracted from Chez
  Scheme 10.4.0 `s/read.ss`. Number spellings that `read` hands to
  `$str->num` come from `s/strnum.ss`.

The token rules are behavior, not a copy of those files. Where CSUG and
`read` disagree, this document follows `read` and says so.

It describes what `read` accepts, not the current `dialects/chez/` grammar.

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

Productions describe default Chez mode unless a named directive is on.
Case in boolean names, number prefixes, and hex digits is not significant
except where a production says otherwise. Directive names and `#!eof` /
`#!bwp` / `#!base-rtd` are case-sensitive.

A parser that only checks token shape may accept text that later fails in
`$str->num`, `integer->char`, vector-length fill, record lookup, or graph
fixup.

## How `read` tokenizes

`read` does not match a context-free grammar of names. It skips atmosphere,
looks at the next character, and either reads a delimited token or enters a
nested reader (`(`, `"`, `#`, and so on).

### Skip

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

A line comment ends at newline, return, NEL (U+0085), or LS (U+2028). It
does not treat U+2029 as a line ending.

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

### Delimiters

A token ends at a delimiter or at end of input.

```text
<r6rs delimiter>  --> ( | ) | [ | ] | " | ; | #
                   |  <whitespace>
<chez delimiter>  --> <r6rs delimiter> | { | } | ' | ` | ,
```

Default Chez uses the Chez set. After `#!r6rs`, `{`, `}`, `'`, backtick,
and comma still terminate a token, but that termination is an error
(`delimiter ~a is not allowed in #!r6rs mode`).

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

### First character of a datum

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

### Hash dispatch

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

## Reader state

These flags are parameters of the grammar. Default Chez is case-sensitive
and not in R6RS-strict mode.

| Control | Default | Effect on syntax |
| --- | --- | --- |
| `#!r6rs` | off | reject Chez lexical extensions |
| `#!chezscheme` | off | clear the R6RS-strict flag |
| `#!fold-case` | off | fold later symbol and character names with `string-foldcase` |
| `#!no-fold-case` | off | keep written case |
| `(case-sensitive)` | `#t` | used only when neither fold directive has been seen |

`|...|` and a non-hex `\` escape set a slashed flag. That name is not
folded even after `#!fold-case`.

These directives are atmosphere, not data. `#!eof`, `#!bwp`, and
`#!base-rtd` are data (special objects). They must be delimited. Their
names are matched exactly.

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
<line comment>     --> ; <any character except newline, return, NEL, LS>*
<block comment>    --> #| <block comment body> |#
<block comment body> --> <block comment element>*
<block comment element> --> <block comment>
                       |  <character other than #| or |#>
<datum comment>    --> #; <intertoken space> <datum>
```

`#;` then one datum is on by default. End of input before that datum is an
error.

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
`( . x)` is an error (`unexpected dot`); unlike Guile, a leading dot is
not accepted as `(x)`.

`{` and `}` never bracket a list.

### Boolean

After `#t` or `#T`, if the next character is a letter, `read` must spell
the rest of `true` (any case). After `#f` or `#F`, it must spell the rest
of `false`. A mismatch or end of input in the middle is an error. After
`#t` / `#f` or the complete long name, a delimiter is required.

```text
<boolean> --> #t | #T | #f | #F
           |  #true | #TRUE | ...     ; any case; Chez extension
           |  #false | #FALSE | ...
```

`(#t foo)` is a list. `(#true)` is boolean true. `(#tfoo)` is an invalid
delimiter. `(#tru1)` is an invalid boolean. This is stricter than R7RS and
Guile, which may stop at `#t` and leave the extra letters.

`#true` and `#false` are Chez extensions (error after `#!r6rs`).

### Number and symbol

If a datum starts with a digit, or with `+` / `-` / `.` that is not a
peculiar identifier or dot, `read` takes one token and tries `$str->num`.
If that returns a number, the token is a number. If it returns `'!r6rs`
while the port is in R6RS-strict mode, that spelling is an error. If it
returns `'norep`, the value cannot be represented. Otherwise the same
token is a (nonstandard) symbol. So `0abc`, `+++`, `1-`, and `32/#` are
symbols in Chez mode.

A prefixed number (`#x`, `#e`, `#36r`, ...) is not this fallback. If
`$str->num` fails, `read` reports invalid number syntax, not a symbol.

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
`#36r+inf.0` is an integer.

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

`#:pretty` builds a gensym whose unique name is new. Atmosphere is not
skipped after `#:`; the next character starts the pretty name.

`#{pretty unique}` stores both names. After the pretty name, only space,
newline, and tab are skipped. Other atmosphere is not skipped there. The
closing `}` is required.

Both forms are Chez extensions.

### Keyword

Chez has no separate keyword datum. `#:name` is a gensym, not a keyword.
`:name` and `name:` are ordinary symbols.

### Character

After `#\`, `read` does this (`rd-token-char`). The first character selects a
branch; later branches do not run.

1. If that character is end of input, error.
2. If it is lowercase `x`, look at the next character:
   - End of input: the datum is the letter `x`.
   - A hex digit: take hex digits. There is no terminating `;`. A
     delimiter or end of input finishes a hex character whose value must
     be a Unicode scalar value. A non-hex non-delimiter switches to the name
     path for the whole token (`x` plus what was read).
   - Otherwise the datum is the letter `x`, and a delimiter is required.
     `#\xy` is not a name.
3. If it is an ASCII letter `a`–`w`, `y`–`z`, or `A`–`Z` (not the `x`
   branch above) and the following character is also an ASCII letter, take
   the whole non-delimited token and look up that name. Otherwise that one
   letter is the datum, and a delimiter is required.
4. If it is an octal digit `0`–`7` and the following character is also
   octal, require exactly three octal digits whose value is at most 255
   (Chez extension). Otherwise that one digit is the datum, and a
   delimiter is required.
5. Otherwise that one character is the datum, and a delimiter is required.

`#\x` followed by a delimiter is the letter `x`. `#\x41` is U+0041.
`#\X41` is not hex (`x` must be lowercase); `X` is a single character and
`4` is an invalid delimiter.

Because a name uses the whole token, `#\space` is space, not `#\s` plus
`pace`. `#\spaces` is an invalid name. `#\Alarm` is invalid unless names
have been folded.

Valid names in Chez mode (`char-name`; CSUG tables plus the R6RS set):

- R6RS: `nul`, `alarm`, `backspace`, `tab`, `linefeed`, `newline`, `vtab`,
  `page`, `return`, `esc`, `space`, `delete`
- Extra: `bel` (same as `alarm`), `ls`, `nel`, `rubout` (same as `delete`),
  `vt` (same as `vtab`)

After `#!r6rs`, only the R6RS names are accepted. `char-name` may add
other names at run time. The grammar follows the dispatch above for token
boundaries. It does not encode the name table, scalar-value checks, or
the octal upper bound. A two-letter name, or an `x` plus hex that later
becomes a name, is still one `character` node, so a custom `char-name`
Chez would accept stays one node. If Chez has committed to octal (two
octal digits already), the grammar keeps two or three octal digits as one
node even when the third digit is missing.

### String

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  \ <string escape>
<string escape> --> a | b | t | n | v | f | r | " | \
                 |  x <hex>+ ;
                 |  '                            ; Chez
                 |  <octal> <octal> <octal>      ; Chez
                  |  <intraline whitespace>* <line ending>
                    <intraline whitespace>*
<line ending> --> LF | CR | NEL | LS | CR LF | CR NEL
```

Intraline whitespace is tab or Unicode category Zs. `CR LF` and `CR NEL`
are consumed as one line ending; every accepted line ending is stored as
newline. Any other character after `\` is an error.

`\'` and exactly three octal digits (value at most 255) are Chez
extensions.

### Vector, bytevector, fxvector, flvector, stencil vector

```text
<vector>      --> #( <datum>* )
               |  #<n>( <datum>* )              ; Chez
<bytevector>  --> #vu8( <u8>* )
               |  #<n>vu8( <u8>* )              ; Chez
<fxvector>    --> #vfx( <number>* )             ; Chez
               |  #<n>vfx( <number>* )
<flvector>    --> #vfl( <number>* )             ; Chez
               |  #<n>vfl( <number>* )
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
`#vs(...)` is an error (`mask required`). The number of elements must equal
the number of bits set in the mask. There is no trailing-element fill.

Element type and range checks (octet, fixnum, flonum) are runtime, not
token shape.

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
<special object> --> #!eof | #!bwp | #!base-rtd
```

These names are delimited and case-sensitive. `#!EOF` and `#!eofx` are
invalid.

`#!eof` is the end-of-file object. If it appears outside any datum in a
file being loaded, `load` stops as at a true end of file.

`#!bwp` is the broken-weak-pointer object.

`#!base-rtd` is the boot singleton used by Chez source and tests. CSUG
does not document it as public reader syntax. The reader still accepts it.

All three are Chez extensions.

## Tree-sitter Restart Notes

A Tree-sitter grammar is static. Chez's reader is not. This dialect is an
independent Chez parser. It uses a fixed union of R6RS and Chez spellings:

- Accept default Chez forms throughout a file.
- Represent `#!r6rs`, `#!chezscheme`, `#!fold-case`, and `#!no-fold-case`
  as `directive` nodes. Do not disable Chez forms after `#!r6rs`, enable
  them after `#!chezscheme`, or fold later names after the case
  directives.
- Represent a Unix interpreter line `#!` plus space or `/` as a `shebang`
  node. It is intertoken, not a datum. `read` itself rejects that line;
  Chez source files still contain it because the script loader strips it.
- Check token shape, not runtime object constraints (vector lengths,
  arbitrary-radix digit values, whether `i` or inf/nan letters are digits
  in that radix, byte / fixnum / flonum ranges, stencil-mask bit counts,
  graph-label uniqueness, record-type existence, character name tables,
  hex scalar values, octal values above 255, or `#@` fasl payloads).
  Character tokens follow Chez `rd-token-char`: `#\x` plus hex (with a
  name fallback), two ASCII letters plus the rest of the token, two or
  three octal digits after Chez commits to octal, or one character.
  `#\X41` is `#\X` then `41`. `#\xy` is `#\x` then `y`.
- Do not treat `#u8(` as a bytevector. Chez uses `#vu8(`.
- Accept `#!base-rtd` because Chez's own source and tests use it. A
  `special_object` node does not promise that application code can use the
  singleton as a supported Chez API.

Shared concepts should reuse the same node names as the R6RS parser.
Chez-only nodes are `box`, `record`, `gensym`, `fx_vector`, `fl_vector`,
`stencil_vector`, `primitive`, `special_object`, and `shebang`. Existing
`datum_label` and `datum_reference` nodes represent graph notation.

As with the other maintained dialects, incomplete editor input may produce
a useful tree instead of enforcing every delimiter rule.

[csug-intro]: https://cisco.github.io/ChezScheme/csug/intro.html
[csug-objects]: https://cisco.github.io/ChezScheme/csug/objects.html
[csug-numeric]: https://cisco.github.io/ChezScheme/csug/numeric.html
[csug-scripts]: https://cisco.github.io/ChezScheme/csug/use.html
[chez-read]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/read.ss
[chez-strnum]: https://github.com/cisco/ChezScheme/blob/v10.4.0/s/strnum.ss
[impl-base-rtd]: https://github.com/cisco/ChezScheme/blob/v10.4.0/IMPLEMENTATION.md#compiled-files-and-boot-files
