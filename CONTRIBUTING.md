# Contributing

```shell
npm install
```

Use `npx tree-sitter` so the project's CLI runs. Generation writes to
`src/` in the current working directory.

## Default parser

From the repository root:

```shell
npx tree-sitter generate
npx tree-sitter test
```

After changing token composition, rebuild the corpus cache with
`npx tree-sitter test -r`. The CLI can otherwise report stale expected
trees.

## Dialect parsers

Each directory under `dialects/` is a separate Tree-sitter project.
Generate and test inside that directory. Generating a dialect from the
repository root overwrites default `src/`.

```shell
cd dialects/r5rs
npx tree-sitter generate
npx tree-sitter test
```

From the repository root, the same steps are `npm run generate:r5rs`,
`npm run test:r5rs`, and `npm run parse:r5rs -- path/to/file.scm`.
Replace `r5rs` with `r6rs`, `r7rs`, `chez`, `guile`, or `chicken`.

After changing the CHICKEN external scanner, also run
`npm run test:chicken:incremental`. That check compares incremental
parses with fresh parses using the `tree-sitter` Node runtime, which the
CLI does not exercise. It needs a C compiler (`cc` by default; set `CC`
to use another).

## Grammar changes

The documents under `docs/` are mainly for LLM agents. Be careful about
writing a dialect or shared fragment yourself, that includes too much
tedious work.

Read [docs/design.md](docs/design.md) before changing `grammar.js`,
`grammar/`, a dialect grammar, or the matching tests and queries. Follow
[docs/dialect-workflow.md](docs/dialect-workflow.md) to add or change a
dialect. Agents start with [AGENTS.md](AGENTS.md).