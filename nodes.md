## Nodes

This page contains all visible nodes in yaml format.

```yaml
- comment
- block_comment # nested `#| ... |#` comment
- sexp_comment # `#;` followed by one datum
- directive # `#!r6rs`
- boolean
- character
- string
- escape_sequence # `\"` or `\\` in a string
- number
- symbol # R5RS or R6RS identifier

- list # `()` or `[]` list; may contain `dot`
- dot # `.` inside a list
- quote # '
- quasiquote # `
- unquote # ,
- unquote_splicing # ,@
- syntax_quote # #'
- quasisyntax # #`
- unsyntax # #,
- unsyntax_splicing # #,@

- vector
- byte_vector # `#vu8(...)`
```
