# Chez Scheme Reader Syntax

This document extracts the reader syntax needed by the maintained Chez Scheme
dialect parser. The target is Chez Scheme 10.4.0. Chez Scheme uses R6RS syntax
and adds the external representations listed below.

## Sources

- [Chez Scheme User's Guide 10.4, section 1.1](https://cisco.github.io/ChezScheme/csug/intro.html)
  is the main syntax reference.
- [Characters and strings](https://cisco.github.io/ChezScheme/csug/objects.html)
  specify the octal forms and extra names and escapes.
- [Vectors, fxvectors, flvectors, bytevectors, and stencil vectors](https://cisco.github.io/ChezScheme/csug/objects.html)
  specify their prefixes and explicit-length forms.
- [Symbols and gensyms](https://cisco.github.io/ChezScheme/csug/objects.html)
  specify extended identifiers and both gensym forms.
- [Records](https://cisco.github.io/ChezScheme/csug/objects.html)
  specifies the readable default record representation.
- [Scheme shell scripts](https://cisco.github.io/ChezScheme/csug/use.html)
  show the `#!` interpreter line used at the start of a script file.
- [R5RS numeric syntax](https://people.csail.mit.edu/jaffer/r5rs/Syntax-of-numerical-constants.html)
  specifies the legacy `#` digit placeholders that Chez mode still accepts.
- [Chez Scheme's implementation guide](https://github.com/cisco/ChezScheme/blob/v10.4.0/IMPLEMENTATION.md#compiled-files-and-boot-files)
  describes the internal `#!base-rtd` singleton used by Chez source and tests.
- R6RS chapter 4 supplies the base lexical and datum syntax
  (http://www.r6rs.org/).

## Extracted Syntax

The notation `datum*` means zero or more data with intertoken space and
comments allowed between them. `n` is a sequence of decimal digits unless the
entry says otherwise.

| Reader concept | Accepted syntax |
| --- | --- |
| Boolean | R6RS `#t` and `#f`, plus case-insensitive `#true` and `#false` |
| Identifier | R6RS identifiers plus delimited non-numbers such as `0abc`, `+++`, `..`, and names beginning with `@`; number-like Chez tokens containing `#` that are not valid numbers, such as `32/#`; `{` and `}`; single-character `\` escapes; `|...|` grouped escapes |
| Number | R6RS numbers; legacy R5RS `#` digit placeholders such as `98##` and `#e98##`; arbitrary radix `#nr` for 2 through 36; fractional and exponent notation in nondecimal radices |
| Character | R6RS characters; exactly three octal digits; names `bel`, `ls`, `nel`, `nul`, `rubout`, `vt`, and `vtab` |
| String escape | R6RS escapes plus `\'` and exactly three octal digits |
| Vector | `#(datum*)` or `#n(datum*)` |
| Bytevector | `#vu8(number*)` or `#nvu8(number*)` |
| Fxvector | `#vfx(number*)` or `#nvfx(number*)` |
| Flvector | `#vfl(number*)` or `#nvfl(number*)` |
| Stencil vector | `#nvs(datum*)`, where `n` is the required decimal mask |
| Box | `#&datum` |
| Record | `#[type-name field*]` |
| Gensym | `#:pretty-name` or `#{pretty-name unique-name}` |
| Shared structure | graph mark `#n=datum` and graph reference `#n#` |
| Primitive abbreviation | `#%name`, `#2%name`, or `#3%name`, where `name` is an identifier |
| Special object | `#!eof`, `#!bwp`, or the internal and otherwise undocumented `#!base-rtd` singleton |
| Comment directive | `#!chezscheme`, `#!r6rs`, `#!fold-case`, or `#!no-fold-case` |
| Shebang | `#!` followed by a space or `/`, then the rest of the line |
| Abbreviation | R6RS quote, quasiquote, unquote, syntax, quasisyntax, unsyntax, and splicing forms |
| Delimiter | R6RS delimiters plus `{`, `}`, `'`, backquote, and comma |

Chez accepts round and square lists. Braces are delimiter characters and the
one-character identifiers `{` and `}`; they are not list brackets.

## Parser Contract

The dialect exposes the same nodes as the R6RS parser when the reader concept
is shared. Chez-only nodes are `box`, `record`, `gensym`, `fx_vector`,
`fl_vector`, `stencil_vector`, `primitive`, and `special_object`. Existing
`datum_label` and `datum_reference` nodes represent graph notation. A
`shebang` node represents a Unix interpreter line. It is intertoken, not a
datum.

The parser accepts `#!base-rtd` because Chez's own source and test suite use
it, even though the Chez Scheme User's Guide does not expose it as public
reader syntax. The `special_object` node does not promise that application
code can use the singleton as a supported Chez API.

Tree-sitter builds a static syntax tree, while the Chez reader carries state.
The dialect therefore accepts the fixed union of R6RS and Chez lexical syntax
throughout a file. It represents reader directives as `directive` nodes but
does not disable Chez forms after `#!r6rs`, enable them after
`#!chezscheme`, or fold later names after the case directives.

The parser checks token shape, not runtime object constraints. It does not
check vector lengths, arbitrary-radix digit values, byte/fixnum/flonum element
ranges, stencil-mask bit counts, graph-label uniqueness, or whether a record
type exists in the current Chez process. These checks belong to the Chez reader
or evaluator. As with the other maintained dialects, incomplete editor input
may produce a useful tree instead of enforcing every delimiter rule.
