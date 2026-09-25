# Tree-sitter mental model

This note explains how Tree-sitter grammars tokenize and parse input.
See the official [Grammar DSL](https://tree-sitter.github.io/tree-sitter/creating-parsers/2-the-grammar-dsl.html)
and [Writing the Grammar](https://tree-sitter.github.io/tree-sitter/creating-parsers/3-writing-the-grammar.html).

## Two machines

Tree-sitter is a context-aware lexer plus a GLR parser.

1. The **lexer** emits one token.
2. The **parser** builds nodes from tokens it already has.

The lexer only considers tokens the parser will accept next. It does not
compare finished nodes. "This rule covers more source, so it should win"
is the wrong model.

## What is a token?

Each string literal and each regex literal is its own token. The lexer
matches that literal and returns one leaf.

```javascript
"if"        // one token, text if
/[0-9]+/    // one token, a run of digits
seq("(", ")")           // two tokens: "(" then ")"
seq("#", /f32/, "(")    // three tokens: "#", f32, "("
```

`token(...)` combines strings and regexes into **one** token. It accepts
only terminals: `token($.foo)` is invalid.

```javascript
token(seq("#", /f32/, "("))   // one token, text #f32(
token(choice("true", "false")) // one token, two spellings
```

That merge moves work from the parser to the lexer. Parsing can get
faster, and the generated parser smaller. Combining the wrong expressions
can hide children, consume another spelling, or select the wrong first
token.

`token.immediate(...)` is also one token. Extras (usually whitespace)
cannot appear immediately before it.

```javascript
seq("foo", token.immediate("("))  // "(" only if it follows foo with no extra
```

A named rule whose body is a string, a regex, or `token(...)` is still one
token. The name only changes the tree: a named leaf instead of an anonymous
one.

```javascript
number: _ => /[0-9]+/   // one token, named number
```

These do **not** make a token. They join tokens, or they change only the
tree:

- `seq`, `choice`, `repeat`, `repeat1`, `optional`
- `prec`, `prec.left`, `prec.right`, `prec.dynamic` (parser precedence,
  unless wrapped in `token(...)`)
- `field`, `alias`
- `$.other_rule` (a symbol; that rule's body decides)

Two copies of the same string are the same token. `"#"` in two rules is
one `"#"` token. `"#"` and `/#/` are different tokens.

## The lexer picks a token

The lexer chooses one token, in this order. GLR does not run here. It
does not join competing matches into a larger token, and it does not vote
for the rule that would cover more source.

1. Higher `token(prec(N, ...))` wins, even if it is shorter.
2. Otherwise the longest match wins.
3. Otherwise a string literal beats a regex of the same length.
4. Otherwise the token that appears earlier in the grammar wins.

After that, the parser runs. Parser `prec` and `conflicts` rank
shift/reduce among those tokens. They cannot take a token apart.

Suppose two rules are both valid at the start of a datum:

```javascript
boolean: _ => token(/#[tf]/),           // matches "#f"
vector:  $ => seq("#", /f32|f64/, "("), // first token is "#"
```

On input `#f32(`, the lexer sees `#f` (length 2) and `"#"` (length 1).
Longest match wins, so it emits `#f`. The parser now has a complete
`boolean`. The leftover is `32(`. Nothing can split `#f` back into `#`
plus `f32`.

Parser `prec` on `vector` does not change this. The lexer has already
chosen a token before the parser ranks rules.

## A token is a leaf

A `field` names a child node. A `field` inside `token(...)` is not a node.

```javascript
// The tag field never appears. The leaf text is "#f32(".
vector: $ => seq(
  field("tag", token(seq("#", /f32|f64/, "("))),
  ")",
)
```

To put only `f32` in a field, `f32` must be its own token, not a piece of a
larger leaf.

## Shared prefixes

When two spellings share a prefix, change the **first token**. Parser `prec`
does not help. For `#f` versus `#f32(`:

- Share `"#"`, then let `f` and `f32` compete. The tag can be its own field.
- Or make `#f32(` one token. It beats `#f` by length. The leaf is the whole
  opener.
- Or use an external scanner when sharing `"#"` would steal other `#` tokens,
  or when the match is not a regex.

Lexical `prec` on `"#"` can beat `#f` even though `"#"` is shorter. Then
`#f` also starts with `"#"`, so it is no longer a boolean unless that
rule shares `"#"` too.
