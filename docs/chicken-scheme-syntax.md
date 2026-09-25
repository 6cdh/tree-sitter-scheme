# CHICKEN Scheme Reader Syntax

## Scope and sources

This document specifies CHICKEN Scheme 6.0.0 reader syntax as compact formal
productions. It does not catalog implementation behavior. Special forms
such as `lambda` and `if` are not reader syntax.

CHICKEN inherits the R7RS-small reader. The formal core is R7RS chapter 7.
[Extensions to the R7RS standard][chicken-ext] and
[Deviations from the R7RS standard][chicken-dev] document additional
spellings. Remaining rules are reconstructed from the pages named under
Sources.

When published wording is unclear, CHICKEN 6.0.0 `read` was used once to
verify it, and that interpretation is written into the productions.

### Target, inheritance, and default reader

The inherited standard is R7RS-small. Default CHICKEN 6.0.0 `read` is
case-sensitive, uses suffix keywords, treats `[...]` and `{...}` as
lists, and allows vertical-line identifiers. Those defaults come from
[Module (chicken base)][chicken-base]:

| Control | Default | Flag | Effect on the default reader |
| --- | --- | --- | --- |
| `case-sensitive` | `#t` | `-case-insensitive` (`-i` in csi) | identifiers keep written case |
| `keyword-style` | `#:suffix` | csc `-keyword-style` `prefix`/`suffix`/`none`; csi `-K` `prefix`/`suffix` only | suffix `NAME:` (`#:NAME` always) |
| `parentheses-synonyms` | `#t` | `-no-parentheses-synonyms` | `[...]` and `{...}` are lists |
| `symbol-escape` | `#t` | none in the manuals | R7RS vertical-line identifiers |

`#:NAME` is a keyword in every `keyword-style` setting. Suffix and
prefix styles are mutually exclusive. [Module (chicken base)][chicken-base]
says any `keyword-style` other than `#:prefix` or `#:suffix` disables
the alternative syntaxes, leaving only `#:NAME`. [Using the
compiler][chicken-csc] documents `-keyword-style none` for that setting.
[Using the interpreter][chicken-csi] accepts `-K` / `-keyword-style` as
`prefix` or `suffix` and ignores any other value.

`-r7rs-syntax` (compiler and csi) "disables the CHICKEN extensions to
R7RS syntax" and "does not disable non-standard read syntax." The
manuals do not list which parameters it changes. See
[Optional reader syntax](#optional-reader-syntax).

### Sources

- Inherited formal core: [R7RS-small][r7rs] chapter 7 (also `docs/r7rs.pdf`)
- [Extensions to the R7RS standard][chicken-ext]: CHICKEN read syntax
- [Deviations from the R7RS standard][chicken-dev]
- [Module (chicken base)][chicken-base]: `keyword-style`,
  `parentheses-synonyms`, `symbol-escape`, `case-sensitive`, `char-name`,
  and the broken-weak-pointer value
- [Module (chicken keyword)][chicken-keyword],
  [Module (chicken read-syntax)][chicken-rs-mod],
  [Module (chicken number-vector)][chicken-nv]
- [Using the interpreter][chicken-csi],
  [Using the compiler][chicken-csc]

Unclear published wording was also checked against the CHICKEN 6.0.0
reader in [`library.scm`][chicken-library] at commit
`2e30c07e470c808cc2939f2864e6165c795717ee`. Extra forms that
the reader accepts are not syntax.

### Notation

Productions use R5RS BNF notation. `<thing>*` is zero or more.
`<thing>+` is one or more. `empty` is the empty string. `datum*` in
running text means zero or more datums with intertoken space between
them.

Concatenation in a production means concatenation in the input. For
example, `#:<symbol>` has no intertoken space. A production shows
`<intertoken space>` only where space is part of that form.
`<end of input>` is a boundary, not input text.

A section note marks each production as one of:

- **quoted:** copied from a named published grammar
- **adapted:** an inherited production with CHICKEN terminals added or
  removed
- **reconstructed:** derived from published prose that is not a formal
  grammar

Productions describe the default reader unless a named option is off.
R7RS 7.1: case is not significant except in `<letter>`, `<character
name>`, and `<mnemonic escape>`. `#\space` and `#\Space` are distinct.
CHICKEN identifiers are case-sensitive by default
([Deviations][chicken-dev]). Number prefixes follow R7RS. Boolean names
follow R7RS. `<hex digit>` is `0`–`9` and `a`–`f` in any case.

Productions describe token shape. A reader may still reject a form or
its value because of constraints such as byte ranges, character names,
SRFI-10 constructors, graph labels, or homogeneous-vector element types.

## Default reader syntax

These rules are the default CHICKEN 6.0.0 source syntax: R7RS-small plus
the CHICKEN extensions that are on without changing a reader parameter.
Unchanged R7RS productions are cited, not copied. Homogeneous number
vectors other than `#u8` are default source syntax; runtime `read`
registers those tags when `(chicken number-vector)` is loaded.

### Intertoken space

Adapted from R7RS 7.1.1. The script-comment alternative is reconstructed
from [Extensions][chicken-ext], *Bang*.

```text
<intertoken space> --> <atmosphere>*
<atmosphere>       --> <whitespace> | <comment> | <directive>
<whitespace>       --> <intraline whitespace> | <line ending>
<intraline whitespace> --> <space or tab>
<line ending>      --> <newline> | <return> <newline> | <return>
<comment>          --> <line comment>
                    |  <nested comment>
                    |  <datum comment>
                    |  <script comment>
<line comment>     --> ; <all subsequent characters up to a line ending>
<nested comment>   --> #| <comment text> <comment cont>* |#
<comment text>     --> <character sequence not containing #| or |#>
<comment cont>     --> <nested comment> <comment text>
<datum comment>    --> #; <intertoken space> <datum>
<directive>        --> #!fold-case | #!no-fold-case
<script comment>   --> #! <script comment start>
                       <any character except newline>*
<script comment start> --> <whitespace> | /
```

R7RS: a `<directive>` must be followed by a `<delimiter>` or end of
input. `#;` then one datum is SRFI-62 (R7RS and CHICKEN). `#| ... |#`
nests (SRFI-30 / R7RS).

`#!` followed by whitespace or `/` is a Unix interpreter line
([Extensions][chicken-ext], *Bang*). The rest of the line is comment.
`#!fold-case` and `#!no-fold-case` are R7RS atmosphere, not datums. They
toggle case folding of later identifiers and character names on that
port. Default CHICKEN is case-sensitive, which is `#!no-fold-case`
behavior.

### Delimiters and tokens

Adapted from R7RS 7.1.1. Brackets and braces are delimiters because
`parentheses-synonyms` defaults to on.

```text
<token>     --> <identifier> | <keyword> | <boolean> | <number> | <character>
             |  <string> | ( | ) | #( | #u8( | #<number vector tag>(
             |  ' | ` | , | ,@ | .
             |  [ | ] | { | }
<delimiter> --> <whitespace> | <vertical line> | ( | ) | " | ;
             |  [ | ] | { | }
<vertical line> --> |
```

R7RS reserves `[` `]` `{` `}` for future use. CHICKEN provides them as
list syntax ([Extensions][chicken-ext], *Brackets and braces*).

Identifiers that do not begin with an unescaped `|` end at a delimiter or
end of input. So do dot, numbers, characters, and booleans. An identifier
that begins with an unescaped `|` ends at the next unescaped `|`.

The dispatch forms below begin with prefixes such as `#;`, `#,`, `#$`,
`#+`, `#>`, `#<<`, `#<#`, and `#!`. These prefixes are part of their
respective productions; they are not additional standalone `<token>` forms.

### Datum

Adapted from R7RS 7.1.2. CHICKEN simple and compound alternatives are
reconstructed from [Extensions][chicken-ext], [Module (chicken
base)][chicken-base], and [Module (chicken number-vector)][chicken-nv].

```text
<datum> --> <simple datum> | <compound datum>
         |  <label>=<datum> | <label>#
<simple datum> --> <boolean> | <number> | <character> | <string>
                |  <symbol> | <keyword> | <special object>
                |  <dsssl marker>
                |  <bytevector> | <bytevector string>
                |  <number vector>
                |  <here string>
<compound datum> --> <list> | <vector>
                  |  <abbreviation> | <srfi-10> | <location>
                  |  <cond-expand> | <foreign declare>
                  |  <interpolated here string>
<abbreviation> --> <abbrev prefix> <datum>
<abbrev prefix> --> ' | ` | , | ,@
<label> --> #<uinteger 10>
```

`<label>=<datum>` and `<label>#` are inherited R7RS 7.1.2 / 2.4 shared
structure.

### Lists

Adapted from R7RS 7.1.2. Bracket and brace lists are reconstructed from
[Extensions][chicken-ext], *Brackets and braces*. They are default
syntax because `parentheses-synonyms` defaults to on.

```text
<list> --> ( <datum>* )
        |  ( <datum>+ . <datum> )
        |  [ <datum>* ]
        |  [ <datum>+ . <datum> ]
        |  { <datum>* }
        |  { <datum>+ . <datum> }
```

Matching brackets and braces are equivalent to matching parentheses.

### Boolean

Quoted from R7RS 7.1.1.

```text
<boolean> --> #t | #f | #true | #false
```

R7RS: case is not significant in these names.

### Number

R7RS 7.1.1 is unchanged: `<num 2>` `<num 8>` `<num 10>` `<num 16>`, with
prefixes `#b` `#o` `#d` `#x` and `#e` `#i` in either order. Decimal point
and exponent exist only in radix 10. Alphabetic characters in number
syntax may be either case. `+i`, `-i`, and `<infnan>` are numbers, not
peculiar identifiers.

### Identifier and symbol

Quoted from R7RS 7.1.1, with CHICKEN case and `symbol-escape` notes.

```text
<symbol>     --> <identifier>
<identifier> --> <initial> <subsequent>*
              |  <vertical line> <symbol element>* <vertical line>
              |  <peculiar identifier>
```

`<initial>`, `<subsequent>`, `<peculiar identifier>`, and
`<symbol element>` are R7RS 7.1.1. The vertical-line form needs
`symbol-escape`, which is on by default. R7RS may also allow extra
Unicode identifier characters.

Default CHICKEN is case-sensitive ([Deviations][chicken-dev]).

### Keyword

Reconstructed from [Extensions][chicken-ext], *Keyword*, and the default
`keyword-style` `#:suffix` in [Module (chicken base)][chicken-base].
Keywords are a distinct type from symbols ([Module (chicken
keyword)][chicken-keyword]).

```text
<keyword> --> #:<symbol>                          ; always
           |  <identifier ending in :>            ; default keyword-style
```

The manuals write `#:SYMBOL` and `SYMBOL:`. They do not define an empty
name. Prefix `:NAME` is optional; see
[Optional reader syntax](#optional-reader-syntax).

[Extensions][chicken-ext] writes `SYMBOL:`. [Module (chicken
base)][chicken-base] says suffix style "recognizes symbols ending with a
colon as keywords." Non-identifier tokens ending in `:` are not this
production.

### Character

Adapted from R7RS 7.1.1. Extra names and `#\u` / `#\U` are reconstructed
from [Extensions][chicken-ext], *User defined character names*.

```text
<character> --> #\<any character>
             |  #\<character name>
             |  #\x<hex scalar value>
             |  #\u<hex digit> <hex digit> <hex digit> <hex digit>
             |  #\U<hex digit> <hex digit> <hex digit> <hex digit>
                  <hex digit> <hex digit> <hex digit> <hex digit>
<character name> --> alarm | backspace | delete | escape | newline
                  |  null | return | space | tab
                  |  linefeed | vtab | nul | page | esc
```

R7RS 7.1: `<character name>` is case-significant. `#\space` is space;
`#\Space` is not that name. R7RS 6.6: `#\<character>` is
case-significant; if that character is alphabetic, a delimiter must
follow, so `#\space` is the name, not `#\s` plus `pace`. Names must not
be readable as `x` plus hex digits. `#\x` plus a delimiter is the letter
`x`.

CHICKEN extra names: `linefeed` (same as `newline`), `nul` (same as
`null`), `esc` (same as `escape`), `vtab`, `page`. `char-name` may add
or remove names; see [Optional reader syntax](#optional-reader-syntax).
The published `#\u` and `#\U` spellings use four and eight hexadecimal
digits. [Extensions][chicken-ext] does not give a disambiguation
algorithm among `#\u` / `#\U`, `#\x`, a name, and a single character.
The CHICKEN 6.0.0 reader accepts a variable-length hexadecimal run after
`#\u` and `#\U`; that is not additional formal syntax.

### String

Adapted from R7RS 7.1.1. Extra escapes are reconstructed from
[Extensions][chicken-ext], *String escape sequences*.

```text
<string> --> " <string element>* "
<string element> --> <any character other than " or \>
                  |  <mnemonic escape>
                  |  \" | \\
                  |  \ <intraline whitespace>* <line ending>
                     <intraline whitespace>*
                  |  <string hex escape>
                  |  \v | \f | \| | \'
                  |  \u <hex digit> <hex digit> <hex digit> <hex digit>
                  |  \U <hex digit> <hex digit> <hex digit> <hex digit>
                     <hex digit> <hex digit> <hex digit> <hex digit>
                  |  \ <octal> <octal> <octal>
<mnemonic escape> --> \a | \b | \t | \n | \r
<string hex escape> --> \x <hex digit> <hex digit> ;
<hex digit> --> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
             |  a | b | c | d | e | f
<hex scalar value> --> <hex digit>+
<octal> --> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
```

CHICKEN extra escapes: `\v`, `\f`, `\uXXXX`, `\UXXXXXXXX`, three octal
digits, `\|`, and `\'`. The published CHICKEN `\x` form is exactly two
hexadecimal digits followed by `;`, and represents an 8-bit character
code. R7RS `<inline hex escape>` in vertical-line identifiers still
permits one or more hexadecimal digits before `;`. The CHICKEN 6.0.0 string
reader may accept a longer hex run or a missing `;`; that is not
additional formal syntax.

### Vector, bytevector, bytevector string, and number vector

`<vector>` is quoted from R7RS 7.1.2. `<bytevector>` is adapted from
R7RS 7.1.1 with character and string elements from [Module (chicken
number-vector)][chicken-nv]. `<bytevector string>` is reconstructed
from [Extensions][chicken-ext], *Bytevector strings*.
`<number vector>` is reconstructed from [Module (chicken
number-vector)][chicken-nv]. `#u8(...)` is both the R7RS bytevector
spelling and the CHICKEN `u8vector` spelling.

```text
<vector>            --> #( <datum>* )
<bytevector>        --> #u8( <u8 element>* )
<bytevector string> --> #u8" <string element>* "
<u8 element>        --> <number> | <character> | <string>
<number vector>     --> #<number vector tag>( <nv element>* )
<number vector tag> --> u16 | u32 | u64
                     |  s8 | s16 | s32 | s64
                     |  f32 | f64 | c64 | c128
<nv element>        --> <number> | <character> | <string>
```

`#u8"..."` is the same data as `#u8("...")`. Characters and strings in
`#u8(...)` and other number vectors expand to character codes: a
character becomes its UTF-8 bytes, and a string becomes the codes of its
contents in the encoding of the input. Element types and ranges are value
constraints. `u8` is not a `<number vector tag>`.

[Module (chicken number-vector)][chicken-nv] requires this external
representation for `read`, `write`, and the program parser. CHICKEN 6.0.0
`read` without loading that module rejects tags other than `u8`. The
compiler accepts the literals without an import. This specification
follows the published program-parser requirement: the tags are default
source syntax. Runtime `read` still registers them when the module is
loaded.

### Here-document

Reconstructed from [Extensions][chicken-ext], *Multiline String Constant*
and *Multiline String Constant with Embedded Expressions*.

```text
<here string> --> #<< <tag line>
                  <here line>*
                  <tag line>
                | #<< <tag line>
                  <here line>*
                  <characters other than newline>*
                  <end of input>
<interpolated here string> --> #<# <tag line>
                               <here element>*
                               <tag line>
                             | #<# <tag line>
                               <here element>*
                               <end of input>
<tag line> --> <characters other than newline>* newline
<here line> --> <characters other than newline>* newline
<here element> --> <any character other than # or newline>
                |  newline
                |  ##
                |  #{ <datum> }
                |  # <datum>
```

The tag is the rest of the line after `#<<` or `#<#`. Content runs until
a line equal to that tag, or end of input. The terminator line is not
part of the string. In the production, a `<here line>` is any line that
is not equal to the tag.

[Extensions][chicken-ext] speaks of lines without defining a line ending.
The verified reading (CHICKEN 6.0.0 here-string reader) is that a
here-document line ends at newline (LF). A carriage return is an
ordinary character in the tag and the body.

`#<#` substitution: `#` then a datum, or `#{` then a datum then `}`.
`##` is a literal `#`. The result is an expression that prints to a
string, rather than a string literal.

After a nested here-document in an interpolated here-string, the
CHICKEN 6.0.0 reader also treats a tag glued to a closing `)` or `}` as a terminator.
That is not additional formal syntax: the published rule is a line equal
to the tag.

### Foreign declare, location, cond-expand

Reconstructed from [Extensions][chicken-ext], *Foreign Declare*,
*Location Expression*, and *Conditional Expansion*.

```text
<foreign declare>  --> #> <foreign text> <#
<location>         --> #$<datum>
<cond-expand>      --> #+ <datum> <datum>
```

`<foreign text>` ends immediately before the first literal `<#`.
`#>` ... `<#` abbreviates `(foreign-declare "...")`.
`#$EXPRESSION` is `(location EXPRESSION)`.
`#+FEATURE EXPR` is `(cond-expand (FEATURE EXPR) (else))`.

`#$`, `#+`, and `#>...<#` are listed as `[read]` forms.

### Special object and bang tokens

Reconstructed from [Extensions][chicken-ext], *Bang*, and [Module
(chicken base)][chicken-base] for `#!bwp`.

```text
<special object> --> #!eof | #!bwp
<dsssl marker>   --> #!optional | #!rest | #!key
```

[Extensions][chicken-ext], *Bang*, lists these recognized `#!` cases.
Any other case is a read error unless a read mark is registered:

- `#!` plus whitespace or `/`: script comment (atmosphere)
- `#!eof`: end-of-file object
- `#!optional` / `#!rest` / `#!key`: symbols whose names include `#!`

`#!fold-case` and `#!no-fold-case` are R7RS directives, not data. They
are not named in *Bang*; they are inherited atmosphere.

`#!bwp` is the broken-weak-pointer object in [Module (chicken
base)][chicken-base]. *Bang* does not list `bwp` among the recognized
`#!` cases. The CHICKEN 6.0.0 reader accepts it; this production
follows the published spelling in *Module (chicken base)*.

### SRFI-10

Reconstructed from [Extensions][chicken-ext], *External Representation*.

```text
<srfi-10> --> #,( <constructor> <datum>* )
<constructor> --> <symbol>
```

The constructor is a symbol registered with `define-reader-ctor`.

## Optional reader syntax

Each entry states how the syntax is turned on, the default, what
productions change, and how it interacts with other modes.

### Prefix and disabled keyword styles

**Activation:** `(keyword-style #:prefix)`, or any other value that is
not `#:suffix` or `#:prefix`. Compiler flag: `-keyword-style prefix` or
`-keyword-style none`. Interpreter flag: `-keyword-style prefix` /
`-K prefix` only; any other `-K` value is ignored.
**Default:** `#:suffix`.

**Changed production** (reconstructed from [Extensions][chicken-ext] and
[Module (chicken base)][chicken-base]):

```text
<keyword> --> #:<symbol>                          ; always
           |  :<identifier>                       ; keyword-style #:prefix
```

With `#:prefix`, `:NAME` is a keyword and `NAME:` is not. With any other
value, only `#:NAME` remains. Suffix and prefix are never both on.
`#:NAME` does not depend on this parameter.

### Parentheses synonyms off

**Activation:** `(parentheses-synonyms #f)` or `-no-parentheses-synonyms`.
**Default:** `#t`.

When off, `[` `]` `{` `}` no longer delimit CHICKEN lists. R7RS still
reserves these characters.

### Vertical-line identifiers off

**Activation:** `(symbol-escape #f)`. **Default:** `#t`.

When off, the R7RS `<vertical line> <symbol element>* <vertical line>`
identifier form is not allowed. The manuals do not document a flag for
this parameter.

### Case-insensitive identifiers

**Activation:** `(case-sensitive #f)`, `-case-insensitive` / `-i`, or
`#!fold-case` on the port. **Default:** `case-sensitive` is `#t`.

Folding applies to later identifiers and character names on that port.
`#!no-fold-case` restores written case. The R7RS `#t` / `#true` / `#f` /
`#false` names remain case-insensitive in the published syntax.

### `-r7rs-syntax`

**Activation:** `-r7rs-syntax` on `csi` or `csc`. **Default:** off.

The manuals say this "disables the CHICKEN extensions to R7RS syntax"
and "does not disable non-standard read syntax." They do not list the
parameters it changes. That interaction is unresolved.

### User-defined character names

**Activation:** `(char-name SYMBOL CHAR)` from [Module (chicken
base)][chicken-base]. **Default:** the R7RS and CHICKEN names listed
under Character.

Added names become extra `<character name>` spellings. `(char-name
SYMBOL #f)` removes a name.

### User-defined read syntax

**Activation:** `set-read-syntax!`, `set-sharp-read-syntax!`,
`set-parameterized-read-syntax!`, and `define-reader-ctor` from [Module
(chicken read-syntax)][chicken-rs-mod]. **Default:** none beyond the
fixed forms above.

Their concrete syntax is user-defined and is not part of this fixed
formal syntax. `#!NAME` read marks use `set-read-syntax!` with a symbol.

[r7rs]: https://small.r7rs.org/
[chicken-library]: https://code.call-cc.org/gitweb/?p=chicken-core.git;a=blob;f=library.scm;hb=2e30c07e470c808cc2939f2864e6165c795717ee
[chicken-ext]: https://wiki.call-cc.org/man/6/Extensions%20to%20the%20standard
[chicken-dev]: https://wiki.call-cc.org/man/6/Deviations%20from%20the%20standard
[chicken-base]: https://wiki.call-cc.org/man/6/Module%20(chicken%20base)
[chicken-keyword]: https://wiki.call-cc.org/man/6/Module%20(chicken%20keyword)
[chicken-rs-mod]: https://wiki.call-cc.org/man/6/Module%20(chicken%20read-syntax)
[chicken-nv]: https://wiki.call-cc.org/man/6/Module%20(chicken%20number-vector)
[chicken-csi]: https://wiki.call-cc.org/man/6/Using%20the%20interpreter
[chicken-csc]: https://wiki.call-cc.org/man/6/Using%20the%20compiler
