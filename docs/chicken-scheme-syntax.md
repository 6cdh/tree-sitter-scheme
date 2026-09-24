# CHICKEN Scheme Reader Syntax

This document describes the reader syntax of CHICKEN Scheme 6.0.0.

CHICKEN 6 inherits R7RS-small reader syntax and adds the lexical extensions
documented in its User's Manual. Chapter 7 of R7RS-small supplies the formal
core; *Extensions to the standard* and *Deviations from the standard* describe
CHICKEN-specific spellings. Language forms such as `lambda` and `if` are
outside the scope of reader syntax.

This reference describes published CHICKEN reader syntax. Observed `read`
behavior does not override clear published rules. The **Documentation gaps and
implementation evidence** section investigates questions the manuals leave
unanswered. **Known deviations from published syntax** records cases where
the pinned interpreter contradicts a clear rule. Neither section changes the
documented syntax.

## Scope and sources

### Target, inheritance, and default reader

The inherited standard is R7RS-small. Default CHICKEN 6.0.0 `read` is
case-sensitive, uses suffix keywords, treats `[...]` and `{...}` as
lists, and allows vertical-line identifiers. Those defaults come from
[Module (chicken base)][chicken-base]:

| Control | Default | Flag | Effect on syntax |
| --- | --- | --- | --- |
| `case-sensitive` | `#t` | `-case-insensitive` (`-i` in csi) | identifiers keep written case |
| `keyword-style` | `#:suffix` | `-keyword-style STYLE` (`-K STYLE` in csi) | selects `NAME:`, `:NAME`, or neither |
| `parentheses-synonyms` | `#t` | `-no-parentheses-synonyms` | `[...]` and `{...}` are lists |
| `symbol-escape` | `#t` | none in the manuals | enables R7RS vertical-line identifiers |

`#:NAME` is a keyword in every `keyword-style` setting. Suffix and
prefix styles are mutually exclusive. Any `keyword-style` other than
`#:suffix` or `#:prefix`, such as `#:none`, leaves only `#:NAME`.

`-r7rs-syntax` (compiler and csi) "disables the CHICKEN extensions to
R7RS syntax" and "does not disable non-standard read syntax." The
manuals do not list which parameters it changes. See Optional reader
syntax and Documentation gaps.

### Sources

- Inherited formal core: [R7RS-small][r7rs] chapter 7 (also `docs/r7rs.pdf`)
- [Extensions to the R7RS standard][chicken-ext] is the main CHICKEN
  syntax summary
- [Deviations from the R7RS standard][chicken-dev]
- Parameters: [Module (chicken base)][chicken-base] (`keyword-style`,
  `parentheses-synonyms`, `symbol-escape`, `case-sensitive`), plus the
  `char-name` procedure
- [Module (chicken keyword)][chicken-keyword], [Module (chicken
  read-syntax)][chicken-rs-mod], [Module (chicken
  number-vector)][chicken-nv]
- Interpreter and compiler flags: [Using the interpreter][chicken-csi],
  [Using the compiler][chicken-csc]
- Implementation aid only: CHICKEN 6.0.0 [`library.scm`][chicken-library]
  (`##sys#read`) at commit `2e30c07e470c808cc2939f2864e6165c795717ee`;
  this pinned source is not normative when the published syntax is clear

### Notation

The productions use the R5RS BNF extensions. `<thing>*` is zero or more.
`<thing>+` is one or more. `empty` is the empty string. `datum*` in running
text means zero or more data with intertoken space between them.

Adjacent literal prefixes and nonterminals are adjacent in the input. For
example, `#:<symbol>` has no intertoken space. Productions omit optional
intertoken space between tokens unless they show `<intertoken space>`.
`<end of input>` is a boundary, not input text.

Each production is one of:

- **quoted:** copied from a named published grammar
- **adapted:** an inherited production with CHICKEN terminals added or
  removed
- **reconstructed:** derived from published prose that is not a formal
  grammar

R7RS 7.1: case is not significant except in `<letter>`, `<character name>`,
and `<mnemonic escape>`. `#\space` and `#\Space` are distinct. CHICKEN
identifiers are case-sensitive by default ([Deviations][chicken-dev]).
Number prefixes follow R7RS. Boolean names follow R7RS in the published
syntax; the pinned reader is narrower. See Known deviations.

Productions describe token shape. A reader may still reject a form or
its value because of constraints such as byte ranges, character names,
SRFI-10 constructors, graph labels, or homogeneous-vector element types.

## Default reader syntax

These rules are the default CHICKEN 6.0.0 reader: R7RS-small plus the
CHICKEN extensions that are on without loading another module or changing
a parameter. Unchanged R7RS productions are cited, not copied.

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
`#!fold-case` and `#!no-fold-case` are R7RS atmosphere, not data. They
toggle case folding of later identifiers and character names on that
port. Default CHICKEN is case-sensitive, which is `#!no-fold-case`
behavior.

### Delimiters and tokens

Adapted from R7RS 7.1.1. Brackets and braces are delimiters because
`parentheses-synonyms` defaults to on.

```text
<token>     --> <identifier> | <keyword> | <boolean> | <number> | <character>
             |  <string> | ( | ) | #( | #u8( | ' | ` | , | ,@ | .
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
reconstructed from [Extensions][chicken-ext] and [Module (chicken
base)][chicken-base].

```text
<datum> --> <simple datum> | <compound datum>
         |  <label>=<datum> | <label>#
<simple datum> --> <boolean> | <number> | <character> | <string>
                |  <symbol> | <keyword> | <special object>
                |  <dsssl marker>
                |  <bytevector> | <bytevector string>
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
structure. Homogeneous vectors other than `#u8` are optional; see
Optional reader syntax.

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
name. Prefix `:NAME` is optional; see Optional reader syntax.

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
or remove names. `#\uXXXX` and `#\UXXXXXXXX` are extra hex forms. The
published spellings use four and eight hexadecimal digits.

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
                  |  <inline hex escape>
                  |  \v | \f | \| | \'
                  |  \u <hex digit> <hex digit> <hex digit> <hex digit>
                  |  \U <hex digit> <hex digit> <hex digit> <hex digit>
                     <hex digit> <hex digit> <hex digit> <hex digit>
                  |  \ <octal> <octal> <octal>
<mnemonic escape> --> \a | \b | \t | \n | \r
<inline hex escape> --> \x <hex digit> <hex digit> ;
<hex digit> --> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
             |  a | b | c | d | e | f
<hex scalar value> --> <hex digit>+
<octal> --> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
```

CHICKEN extra escapes: `\v`, `\f`, `\uXXXX`, `\UXXXXXXXX`, three octal
digits, `\|`, and `\'`. The published CHICKEN `\x` form is exactly two
hexadecimal digits followed by `;`, and represents an 8-bit character
code.

### Vector, bytevector, and bytevector string

`<vector>` and `<bytevector>` are quoted from R7RS 7.1.2.
`<bytevector string>` is reconstructed from [Extensions][chicken-ext],
*Bytevector strings*. Character and string elements inside `#u8(...)`
are reconstructed from [Module (chicken number-vector)][chicken-nv].
`#u8(...)` is both the R7RS bytevector spelling and the CHICKEN
`u8vector` spelling. It is built into the default reader.

```text
<vector>            --> #( <datum>* )
<bytevector>        --> #u8( <u8 element>* )
<bytevector string> --> #u8" <string element>* "
<u8 element>        --> <number> | <character> | <string>
```

`#u8"..."` is the same data as `#u8("...")`. Characters and strings in
`#u8(...)` expand to character codes: a character becomes its UTF-8
bytes, and a string becomes the codes of its contents in the encoding of
the input. Element types and ranges are value constraints.

Other homogeneous-vector tags (`#u16`, `#s8`, `#f32`, and the rest) are
not syntax of the otherwise-default reader. See Optional reader syntax.

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
                |  #{ <datum> <characters other than }>* }
                |  # <datum>
```

The tag is the rest of the line after `#<<` or `#<#`. Content runs until
a line equal to that tag, or end of input. The terminator line is not
part of the string. In the production, a `<here line>` is any line that
is not equal to the tag.

`#<#` substitution: `#` then a datum, or `#{` then a datum then
characters up to `}`. `##` is a literal `#`. The result is an expression that prints to a string, rather than a string
literal.

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

`#$` and `#+` are listed as `[read]` forms. `#>...<#` is also listed as
`[read]`. See Known deviations for the compiler-only hook and the extra
`declare` wrapper.

### Special object and bang tokens

Reconstructed from [Extensions][chicken-ext], *Bang*, and [Module
(chicken base)][chicken-base] for `#!bwp`.

```text
<special object> --> #!eof | #!bwp
<dsssl marker>   --> #!optional | #!rest | #!key
```

- `#!` plus whitespace or `/`: script comment (atmosphere)
- `#!eof`: end-of-file object
- `#!optional` / `#!rest` / `#!key`: symbols whose names include `#!`
- any other `#!NAME`: a read-mark handler (`set-read-syntax!` with a
  symbol), or a read error

`#!bwp` is the broken-weak-pointer object. `#!fold-case` and
`#!no-fold-case` are directives, not data.

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

**Activation:** `(keyword-style #:prefix)`, `(keyword-style #:none)`, or
another non-suffix value. Flags: `-keyword-style prefix` / `-K prefix`,
and `-keyword-style none` in csi. **Default:** `#:suffix`.

**Changed production** (reconstructed from [Extensions][chicken-ext] and
[Module (chicken base)][chicken-base]):

```text
<keyword> --> #:<symbol>                          ; always
           |  :<identifier>                       ; keyword-style #:prefix
```

With `#:prefix`, `:NAME` is a keyword and `NAME:` is not. With any other
value such as `#:none`, only `#:NAME` remains. Suffix and prefix are
never both on. `#:NAME` does not depend on this parameter.

`-r7rs-syntax` sets `keyword-style` to `#:none`. See `-r7rs-syntax`
below.

### Parentheses synonyms off

**Activation:** `(parentheses-synonyms #f)` or `-no-parentheses-synonyms`.
**Default:** `#t`.

When off, `[` `]` `{` `}` no longer delimit CHICKEN lists. R7RS still
reserves these characters. `-r7rs-syntax`
turns this parameter off.

### Vertical-line identifiers off

**Activation:** `(symbol-escape #f)`. **Default:** `#t`.

When off, the R7RS `<vertical line> <symbol element>* <vertical line>`
identifier form is not allowed. The manuals do not document a flag for
this parameter. See Documentation gaps for `-no-symbol-escape`.

### Case-insensitive identifiers

**Activation:** `(case-sensitive #f)`, `-case-insensitive` / `-i`, or
`#!fold-case` on the port. **Default:** `case-sensitive` is `#t`.

Folding applies to later identifiers and character names on that port.
`#!no-fold-case` restores written case. `-r7rs-syntax` turns
`case-sensitive` off. The R7RS `#t` / `#true` / `#f` / `#false` names
remain case-insensitive in the published syntax.

### `-r7rs-syntax`

**Activation:** `-r7rs-syntax` on `csi` or `csc`. **Default:** off.

The manuals say this "disables the CHICKEN extensions to R7RS syntax"
and "does not disable non-standard read syntax." They do not list the
parameters. The pinned `csi.scm` / `batch-driver.scm` turn
`case-sensitive` off, set `keyword-style` to `#:none`, and turn
`parentheses-synonyms` off. `#:NAME`, `#<<`, `#;`, and other
non-standard `#` forms stay enabled. See Documentation gaps.

### Homogeneous number vectors other than `#u8`

**Activation:** load `(chicken number-vector)`. **Default:** not
registered. `#u8(...)` remains in the default reader.

**Changed productions** (reconstructed from [Module (chicken
number-vector)][chicken-nv]):

```text
<number vector>     --> #<number vector tag>( <nv element>* )
<number vector tag> --> u16 | u32 | u64
                     |  s8 | s16 | s32 | s64
                     |  f32 | f64 | c64 | c128
<nv element>        --> <number> | <character> | <string>
```

The external representation has the form `#XXX( ...elements... )`. Characters and
strings expand as for `#u8(...)`. `u8` is not repeated here. Element
types and ranges are value constraints.

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

## Documentation gaps and implementation evidence

This section records implementation evidence for token boundaries and
other questions that published sources leave unresolved. The evidence comes
from CHICKEN 6.0.0 at revision `2e30c07e`, including `##sys#read` in
`library.scm` and code in `support.scm`, `csi.scm`, and `csc.scm`. These
observations are not published syntax. Conclusions drawn from them are
identified as interpretations; unresolved questions remain explicit.

### Token characters the manuals do not list

- **Question:** Are `#`, `'`, `` ` ``, and `,` identifier characters,
  delimiters, or neither when they appear inside a name?
- **Published rule or gap:** R7RS identifiers do not include those
  characters, and they are not R7RS delimiters. CHICKEN manuals do not
  restate the token alphabet. CHICKEN source uses `#` inside names such
  as `##sys#read`.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `foo#bar`, `` foo`bar ``, `foo'bar`, `##sys#read`
- **Location:** `##sys#read` / `r-token` in `library.scm`; terminating
  characters are `,` `;` `(` `)` `'` `"` `[` `]` `{` `}`
- **Observation:** `read` takes one run of non-delimiters as a token, so
  `foo#bar` is one symbol and `` foo`bar `` is one symbol. A leading `#`
  is hash syntax, so `##` plus a run of non-delimiters is one symbol
  whose name starts with `##`. `'` and `,` end a preceding token
  (`foo'bar` is `foo` then `'bar`). Backtick does not.
- **Conclusion:** working interpretation of an unpublished token
  alphabet. Not a published rule.

### Extra whitespace characters

- **Question:** Does CHICKEN skip only R7RS `<whitespace>`, or every
  `char-whitespace?` character?
- **Published rule or gap:** default whitespace is cited from R7RS
  7.1.1. CHICKEN manuals do not list extra skip characters.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** a formfeed or vertical tab between two symbols
- **Location:** `r-spaces` in `##sys#read`, which tests `char-whitespace?`
- **Observation:** any `char-whitespace?` character is skipped as
  atmosphere, so the skip set can be larger than R7RS `<whitespace>`.
- **Conclusion:** working interpretation of an unpublished skip set.
  The default production stays the R7RS set.

### Keyword name after `#:`

- **Question:** Is an empty name after `#:` allowed? Is a lone `:` a
  keyword?
- **Published rule or gap:** the manuals write `#:SYMBOL` and do not
  define an empty name.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `#:`, `#:||`, `:`
- **Location:** `#\:` branch of hash dispatch in `##sys#read`
- **Observation:** an empty name is an error unless the next character
  is `|` (`#:||` is the empty keyword). A lone `:` is the symbol `:`,
  not a keyword.
- **Conclusion:** working interpretation of the empty-name gap.

### Character token after `#\`

- **Question:** How do CHICKEN `#\u` / `#\U` share one `#\` token with
  `#\x`, a name, and a single character?
- **Published rule or gap:** R7RS decides `#\space` and `#\x` plus a
  delimiter. [Extensions][chicken-ext] adds `#\uXXXX` and `#\UXXXXXXXX`
  without a disambiguation algorithm.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `#\space`, `#\x`, `#\u03bb`, `#\U0001f600`
- **Location:** `r-char` in `##sys#read`
- **Observation:** `read` takes the whole `#\` token, then classifies
  it: `x` / `u` / `U` plus hex; else the UTF-8 bytes of one character;
  else `char-name`; else an error. Hex after `#\u` and `#\U` is
  variable-length in this reader.
- **Conclusion:** the classification order is a working interpretation
  of the gap. Variable-length `#\u` / `#\U` contradicts the published
  four- and eight-digit forms; see Known deviations.

### Embedded vertical-line segments

- **Question:** With `symbol-escape` on, may `|` open an escaped segment
  inside an otherwise unquoted identifier, as well as wrap a whole
  identifier?
- **Published rule or gap:** R7RS 7.1.1 has the wrapping form only.
  CHICKEN 6 manuals do not restate the CHICKEN 5 "Escapes in symbols"
  examples such as `|abc|xyz|def|`.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `a|Bc|`
- **Location:** `#\|` branch of `r-xtoken` in `##sys#read`
- **Observation:** `a|Bc|` reads as the single symbol `aBc`.
- **Conclusion:** unpublished extra identifier syntax in 6.0.0 manuals.
  Not added to the default productions.

### Here-document tag and terminator

- **Question:** Is a missing tag, or a tag with trailing space, an
  error? The manuals already allow a missing terminator (end of file).
- **Published rule or gap:** [Extensions][chicken-ext] says content runs
  until a line equal to `TAG` or end of file. It does not define a
  missing or space-padded tag.
- **Version:** CHICKEN 6.0.0
- **Example:** `#<<` at end of line with no tag text; a tag with
  trailing spaces
- **Location:** here-string reader used by `##sys#read`
- **Observation:** `read` warns and continues.
- **Conclusion:** warning-and-continue is observed behavior, not a
  published production.

### Here-document line endings

- **Question:** Does a carriage return end a here-document line?
- **Published rule or gap:** [Extensions][chicken-ext] speaks of lines
  without defining a line ending for here-documents.
- **Version:** CHICKEN 6.0.0
- **Example:** `#<#T` followed by CR-only lines; the same text with CRLF
- **Location:** here-string reader used by `##sys#read`
- **Observation:** only LF ends a line. With CR-only lines the rest of the
  input is the tag and `read` warns about an unterminated here-doc. With
  CRLF the tag is `T` plus CR and the terminator line `T` plus CR equals it.
- **Conclusion:** a here-document line ends at LF; CR is an ordinary
  character in the tag and the lines.

### Nested lists in `#u8(...)`

- **Question:** May a `#u8(...)` element be a nested list or another
  number vector?
- **Published rule or gap:** [Module (chicken number-vector)][chicken-nv]
  names numbers, characters, and strings as elements. It does not say
  that lists or embedded vectors splice.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `#u8(1 (2))`, `#u8(#u16(1))`
- **Location:** `##sys#canonicalize-number-list!` in `library.scm`
- **Observation:** characters and strings expand. Nested lists and
  embedded number vectors are passed through and then rejected by the
  constructor.
- **Conclusion:** nested lists and embedded vectors are unpublished.
  Rejection is observed constructor behavior, not a contradiction of a
  published splice rule.

### Hexadecimal `#u8{...}`

- **Question:** Is `#u8{deadbeef}` published CHICKEN 6.0.0 read syntax?
- **Published rule or gap:** [Extensions][chicken-ext] documents
  `#u8(...)` and `#u8"..."`. [Module (chicken number-vector)][chicken-nv]
  documents `#XXX( ...elements... )`. Neither page specifies brace hex
  contents.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `#u8{deadbeef}`
- **Location:** `##sys#read-numvector-data` in `library.scm`
- **Observation:** after `#u8`, only `(` and `"` are accepted. `{`
  raises `invalid numeric vector syntax`.
- **Conclusion:** `#u8{...}` is not published 6.0.0 syntax. It is not a
  default production. A later chicken-core revision implements brace hex
  literals; that revision is outside this 6.0.0 reference and does not
  make the form published 6.0.0 syntax.

### Unpublished syntax-case hash dispatch

- **Question:** Does CHICKEN 6.0.0 publish `#'` / `` #` `` syntax-case
  abbreviations?
- **Published rule or gap:** [Extensions][chicken-ext] does not list
  them. R7RS-small does not include them.
- **Version:** CHICKEN 6.0.0, `library.scm` at `2e30c07e`
- **Example:** `` #`x ``
- **Location:** `#\`` branch of hash dispatch in `##sys#read`
- **Observation:** `` #` `` reads as `(quasisyntax ...)`.
- **Conclusion:** extra unpublished hash syntax. Not added to the
  default productions.

### `-no-symbol-escape`

- **Question:** Does a documented flag turn `symbol-escape` off?
- **Published rule or gap:** [Module (chicken base)][chicken-base]
  defines the parameter and does not name a flag. `csc -help` lists
  `-no-symbol-escape`. The interpreter and compiler manual pages do not.
- **Version:** CHICKEN 6.0.0, `csc.scm` / `csi.scm` at `2e30c07e`
- **Example:** `csc -no-symbol-escape` / `csi -no-symbol-escape`
- **Location:** option tables in `csc.scm` and `csi.scm`; no assignment
  of `(symbol-escape #f)`
- **Observation:** the flag is accepted and has no effect on the reader.
- **Conclusion:** help-text discrepancy, not a published syntax rule.
  The parameter table above lists no flag for `symbol-escape`.

### `-r7rs-syntax` parameters

- **Question:** Which reader parameters does `-r7rs-syntax` change?
- **Published rule or gap:** [Using the interpreter][chicken-csi] and
  [Using the compiler][chicken-csc] state the two sentences quoted under
  Optional reader syntax and do not list parameters.
- **Version:** CHICKEN 6.0.0, `csi.scm` / `batch-driver.scm` at `2e30c07e`
- **Example:** `csi -r7rs-syntax`
- **Location:** `-r7rs-syntax` handling in `csi.scm` and
  `batch-driver.scm`
- **Observation:** `case-sensitive` is turned off, `keyword-style` is
  `#:none`, and `parentheses-synonyms` is turned off. Non-standard `#`
  forms remain.
- **Conclusion:** working interpretation of an underspecified flag. The
  Optional reader syntax section uses this observation.

## Known deviations from published syntax

The following CHICKEN 6.0.0 behaviors contradict clear published rules. They do not change the productions above.

### Boolean dispatch case

R7RS 7.1.1 makes `#t`, `#f`, `#true`, and `#false` case-insensitive.
With default reader settings, the pinned dispatch reader recognizes the
lowercase spellings `#t`, `#f`, `#true`, and `#false`. Uppercase
spellings such as `#T` produce `invalid sharp-sign read syntax`.
Location: `##sys#user-read-hook` in `library.scm` at `2e30c07e`.

### `#\u` / `#\U` digit count

[Extensions][chicken-ext] specifies `#\uXXXX` and `#\UXXXXXXXX`. The
pinned `r-char` accepts a variable-length hexadecimal run after `#\u`
and `#\U`. That is implementation over-acceptance, not additional
formal syntax.

### String `\x` terminator and length

[Extensions][chicken-ext] specifies `\xXX;` as two hexadecimal digits
and a semicolon. The pinned string reader accepts a longer hex run and
can warn and continue when `;` is missing. Location: `r-xsequence` in
`library.scm` at `2e30c07e`.

### Here-document terminators after nested substitutions

[Extensions][chicken-ext] says here-document content ends at a line equal
to the opening tag. After a nested here-document in an interpolated
here-string, the pinned reader also accepts the tag immediately after the
substitution's closing `)` or `}`, as in `)OUTER` or `}END`. It treats the
tag suffix as a terminator even though the complete line is not equal to the
tag. Location: the here-string reader used by `##sys#read` in `library.scm`
at `2e30c07e`.

### Suffix keywords on non-identifiers

[Extensions][chicken-ext] writes `SYMBOL:`. [Module (chicken
base)][chicken-base] says suffix style "recognizes symbols ending with a
colon as keywords." The pinned `r-xtoken` also treats nonempty unquoted
tokens such as `42:` and `.:` as keywords. Example: `42:` at
`library.scm` `2e30c07e`.

### Foreign declare hook and wrapper

[Extensions][chicken-ext] lists `#>...<#` as `[read]` and calls it an
abbreviation for `(foreign-declare "...")`. In the pinned 6.0.0 tree,
the form is installed by compiler support in `support.scm`, not by
`library.scm` `read`. That hook returns `(declare (foreign-declare
"..."))`. Runtime `read` without that support does not accept the
published form.

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
