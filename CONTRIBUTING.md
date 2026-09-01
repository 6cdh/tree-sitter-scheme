# Contributing

Thank you to contribute `tree-sitter-scheme`.

## Workflow

It's recommended to use [nix](https://nixos.org/) package manager, and run

```shell
nix-shell
npm install # if you haven't install node modules
```

Then you can use `tree-sitter` command:

```shell
tree-sitter generate
tree-sitter test
```

That pair refreshes the default parser in `src/` from root `grammar.js`.

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

Replace `r5rs` with `r6rs`, `r7rs`, `chez`, or `guile` as needed.

How to add or change a dialect or a shared fragment is in
[docs/design.md](docs/design.md). Agents start from [AGENTS.md](AGENTS.md).


If you dont't use nix, you should follow the [official setup](https://tree-sitter.github.io/tree-sitter/creating-parsers) to configure the dev environment.

Also remember to use project specific tree-sitter `./node_modules/.bin/tree-sitter`.

## Todo

* check the tracking issues
* review the code to ensure it meets the standard
* improve queries
