# tree-sitter-scheme

[![Build/test](https://github.com/6cdh/tree-sitter-scheme/workflows/Build/test/badge.svg)](https://github.com/6cdh/tree-sitter-scheme/actions/workflows/test.yml) [![Crates.io Version](https://img.shields.io/crates/v/tree-sitter-scheme)](https://crates.io/crates/tree-sitter-scheme) [![NPM Version](https://img.shields.io/npm/v/%406cdh%2Ftree-sitter-scheme)](https://www.npmjs.com/package/@6cdh/tree-sitter-scheme)

Scheme parser for tree-sitter.

## Recent News

* Maintained parsers for R5RS, R6RS, R7RS-small, Chez Scheme, Guile, and
  CHICKEN Scheme live under `dialects/`. The default `scheme` parser accepts
  all three standards. Reusable reader fragments live under `grammar/`. See
  [docs/design.md](docs/design.md) to add or change a dialect.

## Status

The maintained R5RS parser is `dialects/r5rs/` (language name `scheme`).
It selects the R5RS token forms and external representations from sections
7.1.1 and 7.1.2.

The default `scheme` parser accepts the union of R5RS, R6RS, and R7RS reader
syntax. Where the standards assign different token boundaries to the same
text, the default parser chooses the longest complete token. For example,
`#\XFF` is one R7RS hexadecimal character, while `#\nul` remains one R6RS
named character. Line comments use R6RS line endings, including NEL, U+2028,
and U+2029. Use a standard-specific parser when those parse-tree differences
matter.

The R6RS parser is `dialects/r6rs/` (language name `scheme`). It selects
the lexical syntax and datum syntax from chapter 4 of R6RS
(http://www.r6rs.org/).

The R7RS-small parser is `dialects/r7rs/` (language name `scheme`). It selects
the lexical syntax and external representations from sections 7.1.1 and 7.1.2
(https://small.r7rs.org/). The parser recognizes `#!fold-case`
and `#!no-fold-case`, but a static syntax tree does not normalize later
identifiers according to that reader state.

The Chez Scheme parser is `dialects/chez/` (language name `scheme`). It accepts
R6RS reader syntax plus the Chez Scheme 10.4 external representations extracted
in `docs/chez-scheme-syntax.md`. It represents reader directives but accepts a
fixed R6RS/Chez union; a static syntax tree cannot apply state changes from
`#!r6rs`, `#!chezscheme`, or the case-folding directives.

The Guile parser is `dialects/guile/` (language name `scheme`). It
accepts the default GNU Guile 3.0.11 reader syntax in
`docs/guile-scheme-syntax.md`, including symbols and keywords, arrays
and uniform vectors, bitvectors, `#nil`, default string escapes, and
`#! ... !#` script comments. It recognizes reader directives but does
not apply their state changes, run `read-hash-extend` callbacks, or
match unpublished `read` quirks.

The CHICKEN parser is `dialects/chicken/` (language name `scheme`). It accepts
the CHICKEN Scheme 6.0.0 reader syntax documented in
`docs/chicken-scheme-syntax.md`, including keywords, alternative list brackets,
number vectors, here-documents, and hash dispatch forms. It accepts a fixed
union of reader parameter modes but does not apply parameter changes or run
application-defined reader callbacks. Its here-document scanner matches closing
tags exactly. `#<<` produces `here_string`; `#<#` produces
`interpolated_here_string`, with interpolations and `##` as children.

The frozen R5RS parser is a separate Tree-sitter project in `dialects/r5rs/`.
It is not a drop-in for the default parser or its queries. Build it in that
directory:

```sh
cd dialects/r5rs
npx tree-sitter generate
npx tree-sitter test
npx tree-sitter build
```

Or from the repository root: `npm run generate:r5rs`, `npm run test:r5rs`,
`npm run build:r5rs`. To parse a file with that dialect (generate, build,
then parse):

```sh
npm run parse:r5rs -- path/to/file.scm
```

Use the matching `generate:r6rs`, `test:r6rs`, `build:r6rs`, and
`parse:r6rs` scripts for the R6RS parser. Use `generate:r7rs`, `test:r7rs`,
`build:r7rs`, and `parse:r7rs` for the R7RS-small parser. Use `generate:chez`,
`test:chez`, `build:chez`, and `parse:chez` for the Chez Scheme parser. Use
`generate:guile`, `test:guile`, `build:guile`, and `parse:guile` for Guile.
Use `generate:chicken`, `test:chicken`, `build:chicken`, and `parse:chicken`
for CHICKEN Scheme.

Do not pass a dialect `grammar.js` to `npx tree-sitter generate` from the
repository root. CLI 0.24 would overwrite the default `src/` files.

Identifiers follow R5RS, R6RS, and R7RS lexical syntax, so they cannot
start with a digit. The parser still does not require a delimiter after a
number. `123abc` is a `number` followed by a `symbol`, not one identifier
and not an error.

## Implementation

* [ ] Support for implementation
  * [x] Chez Scheme ([#1](https://github.com/6cdh/tree-sitter-scheme/issues/1))
  * [x] Chicken Scheme ([#3](https://github.com/6cdh/tree-sitter-scheme/issues/3))
  * [x] Guile Scheme ([#7](https://github.com/6cdh/tree-sitter-scheme/issues/7))
  * [ ] Steel Scheme ([#17](https://github.com/6cdh/tree-sitter-scheme/issues/17))

## Usage

See [nodes.md](./nodes.md) for all visible nodes.

This parser doesn't parse language constructs. Instead, it parses code as lists.

If you want language constructs support, use custom queries (see [#5](https://github.com/6cdh/tree-sitter-scheme/issues/5)), also see [thchha/tree-sitter-scheme](https://gitlab.com/thchha/tree-sitter-scheme).

## Query

The queries here are too simple and not intended to be useful in an editor.
Please open an issue if you have suggestions.

## Reference

Scheme

* [R5RS](https://schemers.org/Documents/Standards/R5RS/)
* [R6RS](http://www.r6rs.org/)
* [R7RS](https://small.r7rs.org/)
* [The Scheme Programming Language](https://www.scheme.com/tspl4/)
* [Chez Scheme User's Guide](https://cisco.github.io/ChezScheme/csug/)
* [GNU Guile Reference Manual](https://www.gnu.org/software/guile/manual/)
* [CHICKEN Scheme User's Manual](https://wiki.call-cc.org/man/6/The%20User%27s%20Manual)

Tree-sitter

* [official documents](https://tree-sitter.github.io/tree-sitter)
* [Guide to your first Tree-sitter grammar](https://gist.github.com/Aerijo/df27228d70c633e088b0591b8857eeef)
* [tree-sitter-clojure](https://github.com/sogaiu/tree-sitter-clojure)
* [tree-sitter-commonlisp](https://github.com/theHamsta/tree-sitter-commonlisp)
* [tree-sitter-fennel](https://github.com/TravonteD/tree-sitter-fennel)
