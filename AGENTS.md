# Agent notes

This repository is a Tree-sitter grammar for Scheme. The default parser is at
the repository root. Dialect parsers live under `dialects/`. Reusable reader
fragments live under `grammar/`.

## Dialect and fragment work

Read [docs/design.md](docs/design.md) before changing `grammar.js`,
`grammar/`, a dialect `grammar.js`, or the matching tests and queries. That
file is the contract for human contributors and agents.

Reader syntax for one implementation is not defined in `docs/design.md`. Use
the notes named in that file, such as `docs/guile-scheme-syntax.md`. The
R5RS, R6RS, and R7RS-small parsers cite the published reports linked there;
do not write `docs/r5rs-scheme-syntax.md` (or r6/r7).

## Commands

See [CONTRIBUTING.md](CONTRIBUTING.md). Generate a dialect from its own
directory. Generating a dialect `grammar.js` from the repository root
overwrites default `src/`.
