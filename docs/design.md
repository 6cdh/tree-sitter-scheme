# Dialect grammar design

This contract covers parsers, shared fragments, and syntax trees. See the
[dialect workflow](dialect-workflow.md) for the work process, the
[lexer and parser model](mental_model.md), and
[setup](../CONTRIBUTING.md).

## Syntax authority and parser coverage

Collect documented or published reader syntax, write a formal dialect
specification, then implement it. Published prose and formal productions
have equal authority. Specifications describe the dialect independently
of this parser. Grammar comments and tests own coverage, tree shape, and
parser limits.

References: [Guile 3.0.11](guile-scheme-syntax.md),
[Chez 10.4.0](chez-scheme-syntax.md), [CHICKEN 6.0.0](chicken-scheme-syntax.md),
[R5RS](https://schemers.org/Documents/Standards/R5RS/HTML/),
[R6RS](http://www.r6rs.org/), and [R7RS-small](https://small.r7rs.org/).

### Dialect syntax document structure

Write `docs/<dialect>-scheme-syntax.md` with:

1. **Scope and sources:** target release, inherited standard, reader defaults,
   precise references, and notation.
2. **Default syntax:** productions grouped by reader concept, including
   extensions enabled by default, token boundaries, and documented constraints.
3. **Optional syntax:** extensions disabled by default, their activation,
   changed productions, and mode interactions.

Give productions stable names or anchors and source citations. Mark them
as quoted, adapted, or reconstructed from published prose. Reference
unchanged inherited rules. Record source ambiguities beside affected
productions.

Explore implementation behavior only for a specific published rule already
marked unclear or ambiguous in the specification:

1. Cite the rule and the question.
2. Consult related documentation.
3. Make a bounded interpreter check if needed.
4. Record the interpretation, evidence, checked release, and reader
   configuration.

Observations cannot override clear published rules. A missing source
alone does not justify a check. Ask the user about unresolved blockers
and defer affected rules. Complete the selected syntax specification
before implementation.

### Default and dialect parsers

The root `grammar.js` defines the default `scheme` parser. It accepts the
union of R5RS, R6RS, and R7RS-small reader syntax. When standards assign
different token boundaries to the same text, it uses the R6RS reading.
Keep the default parser compatible with the existing bindings.

Each directory under `dialects/` defines a separate Tree-sitter language.
Each dialect's `grammar.js` selects syntax explicitly; there is no
separate feature configuration. A dialect parser is not interchangeable
with the default parser. It owns its queries under
`dialects/<name>/queries/`.

### Optional modes and reader state

Support documented default syntax, including extensions enabled by
default. Exclude extensions disabled by default. Exceptions require an
explicit user request and a recorded decision in the owning grammar and
tests. Resolve unclear defaults through the specification's ambiguity
procedure.

For requested unions of modes, define and test conflicting token
boundaries or node meanings. A union does not imply simultaneous
interpreter support. Static grammars cannot execute reader callbacks.
Recognizing a directive does not implement its effect. Use an external
scanner only when serialized state can model the required incremental
behavior. Record limits in grammar comments and tests.

### Editor permissiveness

These parsers serve editors. They do not perform complete syntax or
value validation. Record deliberate departures in grammar comments and
tests. For example, `syntax.list.round(choice($._token, $.dot))` treats
dot as punctuation, not a datum, but accepts invalid dotted lists such
as `(.)`. The R5RS parser accepts `123abc` as a number followed by a
symbol without implicit token termination. These exceptions do not
authorize arbitrary over-acceptance.

Do not add an external scanner solely to reject a malformed token that the
static grammar recovers as a valid prefix followed by another datum. Accept
that token-boundary limit and record representative cases in grammar comments
and corpus tests.

## Grammar ownership and shape

```text
grammar.js                   # Default parser
grammar/                     # Shared reader fragments
queries/                     # Default parser queries
src/                         # Generated default parser
dialects/<name>/grammar.js   # Dialect parser
dialects/<name>/queries/     # Dialect queries
```

Keep structural rules and explicit syntax choices in the owning
`grammar.js`. Shared modules provide fragments and small factories, not
complete grammars. Reuse shared lexical definitions. Keep `program` first
(Tree-sitter's start rule) and main reader choices near the top. Use
maintained dialect grammars as examples.

Import `core` and `syntax` from `grammar/index.js`. The root grammar must
use `require("./grammar/index")`: `require("./grammar")` resolves to
`grammar.js`.

### Rule formatting

- Keep a short rule on the same line as its node name.
- For longer rules, break after `=>`.
- Keep a rule on one line or break after each opening `(`.
- Keep closing `)` on the preceding line.
- Short nested rules stay on one line. Multi-line nested rules follow
  these same bullets.

## Shared fragment contracts

`grammar/index.js` exports reader-concept groups:

- `core.js` owns characters and whitespace
- `literals.js`, `number.js`, `string.js`, and `symbol.js` own literals
- `intertoken.js`, `collections.js`, `abbreviations.js`, and
  `hash-forms.js` own reader syntax

Export fragments in named groups, not as bare factories. Put variants
inside the group object. Attach a variant afterward only when it reads a
sibling key. Add a file only when an existing one becomes hard to
navigate. Every exported fragment must be selected by a maintained
parser, directly or through another fragment.

### Naming and selection

Prefer an SRFI name for a fragment variant when the spelling is a SRFI,
as in `byteString.srfi207` or `constructor.srfi10`. The tree node still
uses the reader concept, such as `byte_string` or `srfi10_constructor`.
Otherwise name a fragment after the spelling it defines, not the parser
that selects it. Select an existing fragment when a dialect inherits that
spelling unchanged. Add a dialect-named fragment only when the accepted
spelling differs. Do not export an identity alias. Independent sources
may keep parallel fragments for the same spelling. A sibling composition
is a new fragment.

### Lexical tokens

Keep complete exported spellings and raw expressions such as
`core.anyCharacter` unwrapped so callers can compose them. The owning
grammar uses `token(...)` for complete lexical spellings whenever
boundaries need no parser nodes or contextual tokenization. This avoids
large parser-rule expansions:

```javascript
number: _ => token(syntax.number.r7rs),
symbol: _ => token(syntax.symbol.chicken),
```

When all selected fragments are raw, the grammar may wrap the complete
`choice(...)`. Never wrap across a contextual token or tokenize a factory
containing grammar nodes, such as a list or datum comment.

A fragment may tokenize a context-local body while leaving its shared
delimiter visible to the parser:

```javascript
r7rs: seq("#", token(choice(
  /[tTfF]/,
  /[tT][rR][uU][eE]/,
  /[fF][aA][lL][sS][eE]/,
))),
```

The `#` remains visible so other hash-dispatch forms can compete. Internal
whitespace or opaque bodies may also be tokenized when their boundaries
belong to the factory and cannot compete as standalone nodes.

### Precedence and factories

The owning grammar sets precedence because precedence depends on its
competing rules. Shared fragments do not choose `prec(...)` values. They
may receive a precedence wrapper from the caller:

```javascript
syntax.comment.block($.block_comment, value => prec(100, value))
```

Pass a factory only the grammar nodes and dialect fragments it uses,
never the complete `$` namespace:

```javascript
sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
keyword: $ => syntax.keyword.hashColon(alias($._keyword_symbol, $.symbol)),
```

Pass recursive rules into factories instead of hard-coding public rule
names. Pass dialect-dependent syntax explicitly. For example, keyword
names should use the dialect's selected symbol syntax.

Preserve handwritten Tree-sitter expressions when moving them into shared
modules. Use a factory when syntax needs a grammar node or a selected
fragment; do not replace a number grammar with a generic factory merely
to reduce lines.

## Syntax-tree contract

Use the same node name for the same reader concept across dialects.
Different boolean spellings still produce `boolean`. Implementation-specific
constructs may use implementation-specific names, with queries owned by
the dialect.

Collection contents are direct children without fields for ordinary
positions: `(a b c)` has three named `symbol` children of `list`, without
an `elements` field. A child without a field is not necessarily unnamed.

Use fields for distinct roles such as name, prefix, rank, type, or
target. Fields must point to nodes: expose lexical tokens through named
rules or aliases. A `field(...)` inside `token(...)` is not exposed in
the tree.

Keep rules, expected trees, and queries aligned when names or fields
change. Shared node names do not make dialect trees or queries
interchangeable.

## Generated files and verification

Only the default parser tracks generated files in `src/`; its bindings
need those files. Do not commit generated files under `dialects/*/src/`.
A dialect may track a handwritten external scanner there while ignoring
generated files.

Generate each dialect from its own directory, using the repository's CLI.
Never pass a dialect `grammar.js` to generation from the repository root:
that overwrites default `src/`. Root `npm run generate:<dialect>`,
`test:<dialect>`, and `parse:<dialect>` commands handle the working
directory; see [CONTRIBUTING.md](../CONTRIBUTING.md).

Every maintained dialect must generate and pass its corpus tests in CI.
Generation is itself a required check because it exposes lexer and parser
conflicts. Changes to shared fragments require generation and tests for
every parser that selects the affected fragments.

Corpus tests cover positive dialect syntax, shared syntax, rejected
syntax, token boundaries, and deliberate permissiveness. Check expected
node names and fields as well as acceptance, and validate the affected
queries. Share corpus cases where practical instead of copying identical
cases between dialects.

Scripts own corpus cases whose bytes are easy to damage in an editor:

- R6RS line endings: `scripts/write-r6rs-line-ending-corpus.js`
- R7RS line endings: `scripts/write-r7rs-line-ending-corpus.js`
- Chez line endings: `scripts/write-chez-line-ending-corpus.js`
- Guile whitespace: `scripts/write-guile-whitespace-corpus.js`

Change those scripts rather than hand-editing or copying their generated
cases. After changing the default grammar or its selected fragments,
regenerate the checked-in `src/` files and verify that the generated
diff is intentional.
