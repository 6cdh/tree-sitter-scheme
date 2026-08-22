# tree-sitter-scheme

[![Build/test](https://github.com/6cdh/tree-sitter-scheme/workflows/Build/test/badge.svg)](https://github.com/6cdh/tree-sitter-scheme/actions/workflows/test.yml) [![Crates.io Version](https://img.shields.io/crates/v/tree-sitter-scheme)](https://crates.io/crates/tree-sitter-scheme) [![NPM Version](https://img.shields.io/npm/v/%406cdh%2Ftree-sitter-scheme)](https://www.npmjs.com/package/@6cdh/tree-sitter-scheme)

Scheme parser for tree-sitter.

## Recent News

* Maintained R5RS and R6RS dialects: `dialects/r5rs/` and `dialects/r6rs/`.
  The default `scheme` parser accepts both standards. Reusable reader
  fragments live under `grammar/`.

## Status

The maintained R5RS parser is `dialects/r5rs/` (language name `scheme`).
It selects the R5RS token forms and external representations from sections
7.1.1 and 7.1.2.

The default `scheme` parser accepts the union of R5RS and R6RS reader syntax.
Where the standards assign different token boundaries to the same text, the
default parser prefers R6RS: `#\xFF` is one hexadecimal character, and an
identifier such as `->name` is one symbol. Use a standard-specific parser when
those parse-tree differences matter.

The R6RS parser is `dialects/r6rs/` (language name `scheme`). It selects
the lexical syntax and datum syntax from chapter 4 of R6RS. The local reference
is `docs/r6rs.pdf`, with searchable text in `docs/r6rs.txt`.

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
`npm run build:r5rs`.

Use the matching `generate:r6rs`, `test:r6rs`, and `build:r6rs` scripts for
the R6RS parser.

Do not pass a dialect `grammar.js` to `npx tree-sitter generate` from the
repository root. CLI 0.24 would overwrite the default `src/` files.

The parser intentionally allows implicit-termination tokens to end without an
R5RS delimiter. This loose behavior is useful while editing incomplete code.
For example, `123abc` becomes a `number` followed by a `symbol` instead of an
error.

## Implementation

* [ ] Support for implementation
  * [ ] Chez Scheme ([#1](https://github.com/6cdh/tree-sitter-scheme/issues/1))
  * [ ] Chicken Scheme ([#3](https://github.com/6cdh/tree-sitter-scheme/issues/3))
  * [ ] Guile Scheme ([#7](https://github.com/6cdh/tree-sitter-scheme/issues/7))
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

Tree-sitter

* [official documents](https://tree-sitter.github.io/tree-sitter)
* [Guide to your first Tree-sitter grammar](https://gist.github.com/Aerijo/df27228d70c633e088b0591b8857eeef)
* [tree-sitter-clojure](https://github.com/sogaiu/tree-sitter-clojure)
* [tree-sitter-commonlisp](https://github.com/theHamsta/tree-sitter-commonlisp)
* [tree-sitter-fennel](https://github.com/TravonteD/tree-sitter-fennel)
