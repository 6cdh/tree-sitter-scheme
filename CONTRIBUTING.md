# Contributing

Thank you for contributing to `tree-sitter-scheme`.

## Workflow

We recommend using the [Nix](https://nixos.org/) package manager:

```shell
nix-shell
npm install # if you have not installed the Node dependencies
```

Then run the `tree-sitter` commands:

```shell
tree-sitter generate
tree-sitter test
```

These commands regenerate and test the default parser from the root
`grammar.js`. Generation writes to `src/`.

Each maintained dialect is a separate project. Generate and test one in its
directory so default `src/` is not overwritten:

```shell
cd dialects/r5rs
tree-sitter generate
tree-sitter test
```

Or run the matching root scripts, such as `npm run generate:r5rs` and
`npm run test:r5rs`. Matching scripts exist for every maintained dialect.
To generate, build, and parse a file with one dialect, run:

```shell
npm run parse:r5rs -- path/to/file.scm
```

Replace `r5rs` with `r6rs`, `r7rs`, `chez`, `guile`, or `chicken` as needed.

After changing the CHICKEN scanner, also run `npm run test:chicken:incremental`.
This test compares incremental parses with fresh parses using the runtime from
the installed `tree-sitter` Node dependency. It covers older runtime behavior
that the CLI does not exercise. It requires npm dependencies and a C compiler
(`cc` by default; set `CC` to use another compiler).

See [docs/design.md](docs/design.md) to add or change a dialect or shared
fragment. Follow [docs/dialect-workflow.md](docs/dialect-workflow.md) for the
research, coverage, implementation, and review checklist. Agents should start
with [AGENTS.md](AGENTS.md).

If you do not use Nix, follow the [official setup](https://tree-sitter.github.io/tree-sitter/creating-parsers)
to configure the development environment.

Use the project's Tree-sitter CLI at `./node_modules/.bin/tree-sitter`.

## Todo

* check the tracking issues
* review the code to ensure it meets the standard
* improve queries
