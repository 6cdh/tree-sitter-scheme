## Nodes

This page contains all visible nodes in yaml format.

```yaml
- comment
- block_comment # nested `#| ... |#` comment
- sexp_comment # `#;` followed by one datum
- directive # `#!r6rs`, `#!fold-case`, or `#!no-fold-case`
- boolean
- character
- string
- escape_sequence # `\"` or `\\` in a string
- number
- symbol # R5RS, R6RS, or R7RS identifier
- datum_label # `#0=` followed by one datum
- datum_reference # `#0#`

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
- byte_vector # `#vu8(...)` or `#u8(...)`
```
