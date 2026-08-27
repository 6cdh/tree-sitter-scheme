# Dialect grammar design

This document defines how the default parser, dialect parsers, and shared
reader fragments fit together. It also defines tree-shape, generation, and
testing rules for changes in those areas.

Reader syntax belongs in the relevant standard or implementation notes:

- [GNU Guile 3.0.11](guile-scheme-syntax.md)
- [Chez Scheme 10.4](chez-scheme-syntax.md)
- [R5RS](https://schemers.org/Documents/Standards/R5RS/HTML/)
- [R6RS](http://www.r6rs.org/)
- [R7RS-small](https://small.r7rs.org/)

## Repository model

The root `grammar.js` defines the default `scheme` parser. It accepts the
union of R5RS, R6RS, and R7RS-small reader syntax. When two standards assign
different token boundaries to the same text, the default parser uses the R6RS
reading.

Each directory under `dialects/` defines a separate Tree-sitter language.
Dialect grammars select syntax explicitly in their own `grammar.js`; there is
no separate feature configuration. A dialect parser is not interchangeable
with the default parser and owns its queries under `dialects/<name>/queries/`.

Shared reader definitions live under `grammar/`:

```text
grammar.js                   # Default parser
grammar/                     # Shared reader fragments
dialects/<name>/grammar.js   # Dialect parser
src/                         # Generated default parser
```

Keep these compatibility rules:

- Do not copy a shared lexical definition into several dialect grammars.
- Keep structural rules in each owning `grammar.js`; shared modules provide
  fragments and small factories, not a hidden complete grammar.
- Keep the default parser compatible with the existing bindings.
- Do not commit generated `dialects/*/src/` directories.

## Shared reader fragments

Import shared definitions from `grammar/index.js` as `core` and `syntax`.
Their source of truth is `grammar/core.js`, `grammar/literals.js`, and
`grammar/reader.js`; do not duplicate a symbol catalog in this document.

Group fragments by reader concept, such as booleans, symbols, comments, and
vectors. Add another shared file only when an existing file becomes difficult
to navigate.

Keep handwritten Tree-sitter expressions when moving syntax into `grammar/`.
Do not replace a number grammar with a generic factory merely to reduce its
line count. Use a factory when the syntax must receive a grammar node or a
selected dialect fragment.

### Token boundaries

A reusable lexical fragment owns `token(...)` when it can be lexed as one
token. A dialect that selects one such fragment uses it directly:

```javascript
boolean: _ => syntax.boolean.r5rs,
```

When a dialect combines fragments into one lexical choice, wrap the complete
composition in `token(...)`:

```javascript
boolean: _ => token(choice(
  syntax.boolean.r7rs,
  syntax.boolean.r6rs,
  syntax.boolean.r5rs,
)),
```

Do not leave a `choice(...)` of tokenized fragments unwrapped. That produces
separate lexer alternatives and has caused larger generated parsers and token
selection regressions.

Raw expressions such as `core.anyCharacter` remain unwrapped when callers
must compose them inside a larger token. A factory that contains grammar
nodes, such as a list or datum comment, cannot be a token.

### Precedence

Shared fragments do not set `prec(...)`. Precedence depends on every rule in a
parser, so the owning `grammar.js` sets it:

```javascript
token(prec(1, syntax.keyword.guilePostfix))
syntax.comment.block($.block_comment, value => prec(100, value))
```

### Factories

A factory receives only the grammar nodes it uses, never the complete `$`
namespace:

```javascript
sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
```

Pass a recursive rule into its factory instead of hard-coding the public rule
name. Pass dialect-dependent syntax explicitly; for example, keyword syntax
should use the same symbol rule that the dialect exposes for ordinary symbols.

## Dialect grammar shape

Keep `program` first because Tree-sitter uses the first rule as the start rule.
A dialect grammar should make its main reader choices visible near the top:

```javascript
const { core, syntax } = require("../../grammar/index");

module.exports = grammar({
  name: "scheme",
  extras: _ => [],
  rules: {
    program: $ => repeat($._token),
    _token: $ => choice($._intertoken, $._datum),
    _intertoken: $ => choice(/* dialect choices */),
    _datum: $ => choice(/* dialect choices */),
    string: $ => syntax.string($.escape_sequence),
  },
});
```

Use the maintained dialect grammars as examples. Do not copy a complete
grammar into this document.

The root grammar must import `./grammar/index` explicitly. In Node resolution,
`require("./grammar")` finds the root `grammar.js` before the `grammar/`
directory.

## Syntax-tree shape

Use the same node name for the same reader concept across dialects. Different
boolean spellings still produce `boolean`; implementation-specific constructs
may use implementation-specific node names. Keep queries for those nodes with
their dialect.

The natural contents of a collection remain unnamed children. For example,
the symbols in `(a b c)` are direct children of `list`; an `elements` field
would repeat information already supplied by the node type and child order.

Use a named field when a child has a distinct role, such as a name, prefix,
rank, type, or target. A field must point to a syntax-tree node. If the field
must cover a lexical token, give that token a named rule or alias; a
`field(...)` nested inside `token(...)` is not exposed in the generated tree.

Dot is list punctuation rather than a datum:

```javascript
syntax.list.round(choice($._token, $.dot))
```

This representation intentionally accepts some invalid dotted lists, such as
`(.)`. The R5RS parser also accepts `123abc` as a number followed by a symbol
instead of enforcing implicit token termination. These choices support useful
trees while source is being edited; a validator can enforce stricter rules.

Some readers change behavior through directives or callbacks. A static grammar
can represent one mode or a documented permissive union, but it cannot execute
reader state changes. Use an external scanner only when serialized scanner
state can model the required incremental behavior. State known limits in the
dialect documentation and tests.

## Generated parsers

Only the default parser keeps generated files in `src/`; the language bindings
need them. Tree-sitter CLI 0.24 writes generated files to `src/` under the
current directory, so generate a dialect from its own directory:

```sh
cd dialects/guile
npx tree-sitter generate
npx tree-sitter test
```

The equivalent root commands are `npm run generate:guile` and
`npm run test:guile`. Matching commands exist for `r5rs`, `r6rs`, `r7rs`, and
`chez`. `npm run parse:<dialect> -- path/to/file.scm` generates, builds, and
parses with that dialect.

Never generate a dialect by passing its `grammar.js` to the CLI from the
repository root; doing so overwrites the default parser's `src/` files.

## Tests

Every maintained dialect must generate and pass its corpus tests in CI.
Include positive dialect syntax, syntax shared with other parsers, and negative
cases for syntax the dialect rejects. Generation itself is a required check
because it exposes lexer and parser conflicts.

Every exported fragment must be selected by at least one maintained parser.
Share corpus cases where practical instead of copying identical cases between
dialects.

Scripts generate corpus cases whose bytes are easy to damage in an editor:

- R6RS line endings: `scripts/write-r6rs-line-ending-corpus.js`
- Guile whitespace: `scripts/write-guile-whitespace-corpus.js`

Do not copy those generated cases into handwritten corpus files. After
changing the default grammar, regenerate its checked-in `src/` files and
verify that the generated diff is intentional.
