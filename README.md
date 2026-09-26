# tree-sitter-scheme

[![Test](https://github.com/6cdh/tree-sitter-scheme/actions/workflows/test.yml/badge.svg)](https://github.com/6cdh/tree-sitter-scheme/actions/workflows/test.yml) [![Build](https://github.com/6cdh/tree-sitter-scheme/actions/workflows/build.yml/badge.svg)](https://github.com/6cdh/tree-sitter-scheme/actions/workflows/build.yml) [![Crates.io Version](https://img.shields.io/crates/v/tree-sitter-scheme)](https://crates.io/crates/tree-sitter-scheme) [![NPM Version](https://img.shields.io/npm/v/%406cdh%2Ftree-sitter-scheme)](https://www.npmjs.com/package/@6cdh/tree-sitter-scheme)

Scheme parser for tree-sitter.

## Recent News

* Maintained parsers for R5RS, R6RS, R7RS-small, Chez Scheme, Guile, and
  CHICKEN Scheme live under `dialects/`. The default `scheme` parser accepts
  all three standards plus some extensions.
  Reusable reader fragments live under `grammar/`. See
  [docs/design.md](docs/design.md) to add, change, or make yourself a dialect.

* The reusable-fragments design refactor is a breaking change. The default
  parser is not compatible with the previous one. See
  [nodes.md](./nodes.md).

  * `syntax` is now `syntax_quote`
  * `#;` is `sexp_comment`, not `comment`
  * New nodes: `dot`, `datum_label`, `datum_label_id`, `datum_reference`
  * `list` is `()` or `[]` only; `.` is a child `dot`
  * `byte_vector` also matches `#u8(...)`
  * Dropped extensions: `{}` lists, symbols that start with a digit,
    `\` + any character in strings, extra character names (`#\bel`,
    `#\ls`, `#\nel`, `#\rubout`, `#\vt`)

## Status

The default `scheme` parser accepts the union of R5RS, R6RS, and R7RS-small
reader syntax, plus Steel Scheme `#\u` characters and `#:` keywords. When
the standards disagree on a token boundary, it uses the R6RS reading.

Separate parsers live under `dialects/`. Each is its own Tree-sitter
language named `scheme`, not a drop-in for the default parser:

- `dialects/r5rs/` — R5RS
- `dialects/r6rs/` — R6RS
- `dialects/r7rs/` — R7RS-small
- `dialects/chez/` — Chez Scheme 10.4
- `dialects/guile/` — GNU Guile 3.0.11
- `dialects/chicken/` — CHICKEN Scheme 6.0.0

See each dialect `grammar.js` for coverage. Chez, Guile, and CHICKEN also
have notes in `docs/`. Generate a dialect from its own directory; see
[CONTRIBUTING.md](CONTRIBUTING.md). Feel free to open issues for new
syntax.

## Implementation

* [ ] Support for implementation
  * [x] Chez Scheme ([#1](https://github.com/6cdh/tree-sitter-scheme/issues/1))
  * [x] Chicken Scheme ([#3](https://github.com/6cdh/tree-sitter-scheme/issues/3))
  * [x] Guile Scheme ([#7](https://github.com/6cdh/tree-sitter-scheme/issues/7))
  * [ ] Steel Scheme ([#17](https://github.com/6cdh/tree-sitter-scheme/issues/17))

## Usage

See [nodes.md](./nodes.md) for the default parser's visible nodes.

This parser doesn't parse language constructs. Instead, it parses code as lists.

If you want language constructs support, use custom queries (see [#5](https://github.com/6cdh/tree-sitter-scheme/issues/5)), also see [thchha/tree-sitter-scheme](https://gitlab.com/thchha/tree-sitter-scheme).

To use a dialect parser, clone this repository, generate and build that
dialect with the tree-sitter CLI, then copy the compiled library to the
location your editor requires:

```shell
npm install
cd dialects/r5rs
npx tree-sitter generate
npx tree-sitter build
```

Replace `r5rs` with `r6rs`, `r7rs`, `chez`, `guile`, or `chicken`.
Generate from the dialect directory; generating from the repository
root overwrites default `src/`. See [CONTRIBUTING.md](CONTRIBUTING.md).

If you want to make your own parser, look at the reusable fragments in
[`grammar/`](grammar/) and the notes in
[docs/design.md](docs/design.md) and
[docs/dialect-workflow.md](docs/dialect-workflow.md).

## Query

The queries here are too simple and not intended to be useful in an editor.
You need to write by yourself, according to the grammar files.

## Reference

Scheme

* [R5RS](https://schemers.org/Documents/Standards/R5RS/HTML/)
* [R6RS](http://www.r6rs.org/)
* [R7RS-small](https://small.r7rs.org/)
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
