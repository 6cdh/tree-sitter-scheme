# Dialect grammar design

This document defines the design contract for the default parser, dialect
parsers, shared reader fragments, and their syntax trees. For related guidance,
see the [lexer and parser model](mental_model.md), the
[dialect workflow](dialect-workflow.md), and the
[setup instructions](../CONTRIBUTING.md).

Design principles:

- Each grammar makes its accepted reader syntax visible.
- Shared fragments reuse reader concepts without hiding a complete grammar.
- Tokenize complete lexical spellings in the owning `grammar.js` whenever their
  boundaries allow it; keep reusable fragments composable.
- Trees serve editor tools, with explicit limits on validation and reader state.
- Prefer an SRFI name for a reusable fragment variant when the syntax comes from an SRFI.
- Prefer a named group for a reusable fragment.

## Syntax authority and parser coverage

Reader syntax belongs in the relevant standard or implementation notes:

- [GNU Guile 3.0.11](guile-scheme-syntax.md)
- [Chez Scheme 10.4.0](chez-scheme-syntax.md)
- [CHICKEN Scheme 6.0.0](chicken-scheme-syntax.md)
- [R5RS](https://schemers.org/Documents/Standards/R5RS/HTML/)
- [R6RS](http://www.r6rs.org/)
- [R7RS-small](https://small.r7rs.org/)

Syntax references describe published reader rules, inherited syntax, defaults,
optional modes, and gaps. Published prose and formal productions are equally
authoritative. Observed interpreter behavior must not override clear published
syntax or silently resolve ambiguous prose.

A syntax reference describes the dialect independently of this parser. The
owning `grammar.js`, queries, and tests describe the parser's syntax selection,
tree shape, conflict resolutions, and deliberate limits.

### Dialect syntax document structure

Organize `docs/<dialect>-scheme-syntax.md` in this order:

1. **Scope and sources.** Target release, inherited standard, default reader
   configuration, precise references, and notation. Identify productions as
   quoted, adapted, or reconstructed from published prose.
2. **Default reader syntax.** Group rules by reader concept. Include token
   boundaries and documented restrictions; reference unchanged inherited rules
   instead of copying them. Preserve any ambiguity in the published rules.
3. **Optional reader syntax.** State each extension's activation mechanism,
   default setting, changed productions, and interactions with other modes.
4. **Documentation gaps and implementation evidence.** Record questions left
   unclear by published sources and any evidence used to investigate them.
   An existing `Implementation Behavior` section serves this purpose.
5. **Known deviations from published syntax.** When an interpreter contradicts
   a clear published rule, record the discrepancy separately. Omit this section
   when there are no known deviations.

For each implementation-evidence entry, record the question, relevant published
rule or gap, interpreter version or source revision, minimal example, invocation
or source location, observation, and conclusion. Distinguish observed behavior
from inference, and leave unresolved questions explicit. Evidence about a gap
may support a working interpretation; it does not become a published rule.
Known deviations likewise do not change the documented syntax.

Reader defaults, flags, and documented extensions belong in this reference.
Tree-sitter precedence, node names, scanners, and permissive acceptance belong
with the parser. Keep usage surveys and parser coverage tables in the tracking
issue or review record, as described in [dialect-workflow.md](dialect-workflow.md).

### Default and dialect parsers

The root `grammar.js` defines the default `scheme` parser. It accepts the union
of R5RS, R6RS, and R7RS-small reader syntax. When standards assign different
token boundaries to the same text, it uses the R6RS reading. Keep the default
parser compatible with the existing bindings.

Each directory under `dialects/` defines a separate Tree-sitter language.
Each dialect's `grammar.js` selects syntax explicitly; there is no separate
feature configuration. A dialect parser is not interchangeable with the default parser
and owns its queries under `dialects/<name>/queries/`.

### Optional modes and reader state

Default reader syntax is the baseline for coverage decisions. Optional syntax
requires an explicit selection and interpretation in the owning grammar.
Existing dialects may accept a documented union of modes. A union does not
imply that the interpreter accepts all those modes simultaneously.

When modes assign different token boundaries or node meanings to the same
text, define which interpretation the parser uses and test that decision.
Accepting both spellings alone does not resolve the conflict.

A static grammar can represent a mode or a permissive union; it cannot execute
runtime reader callbacks. Recognizing a directive does not by itself implement
its effect on later input. Use an external scanner only when serialized scanner
state can model the required incremental behavior. State known limits in the
owning grammar's comments and tests.

### Editor permissiveness

These parsers produce useful trees while source is being edited. They are not
complete validators of reader syntax or values. Keep deliberate departures
from published rules explicit in the owning grammar and tests.

For example, dot is list punctuation rather than a datum:

```javascript
syntax.list.round(choice($._token, $.dot))
```

This representation intentionally accepts some invalid dotted lists, such as
`(.)`. The R5RS parser also accepts `123abc` as a number followed by a symbol
instead of enforcing implicit token termination. A validator can enforce
stricter rules. These exceptions do not make arbitrary over-acceptance part of
the contract.

## Grammar ownership and shape

```text
grammar.js                   # Default parser
grammar/                     # Shared reader fragments
queries/                     # Default parser queries
src/                         # Generated default parser
dialects/<name>/grammar.js   # Dialect parser
dialects/<name>/queries/     # Dialect queries
```

Keep structural rules in the owning `grammar.js`. Shared modules provide
fragments and small factories. Do not copy shared lexical definitions into
several dialect grammars or hide the dialect's choices in a complete shared
grammar.

Keep `program` first because Tree-sitter uses the first rule as the start rule.
Make the main reader choices visible near the top. This sketch shows the shape;
use maintained dialect grammars for complete examples:

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

The root grammar must import `./grammar/index` explicitly. In Node resolution,
`require("./grammar")` finds the root `grammar.js` before the `grammar/`
directory.

### Rule formatting

- Keep a short rule on the same line as its node name.
- For longer rules, break after `=>`.
- Keep a rule on one line or break after each opening `(`.
- Keep closing `)` on the preceding line.
- Short nested rules stay on one line. Multi-line nested rules follow
  these same bullets.

## Shared fragment contracts

Import `core` and `syntax` from `grammar/index.js`. The index maps each
fragment group to its definition in `grammar/`. `core.js` owns shared
characters and whitespace; `literals.js`, `number.js`, `string.js`, and
`symbol.js` own literal syntax; `intertoken.js`, `collections.js`,
`abbreviations.js`, and `hash-forms.js` own reader syntax.

Group fragments by reader concept, such as booleans, symbols, comments, and
vectors. Put a reusable fragment in such a group rather than exporting a bare
factory. Named variants sit in the group object's body. Attach a variant after
the object only when it reads a sibling key. Add another shared file only when
an existing file becomes difficult to navigate.

Every exported fragment must be selected by at least one maintained parser,
either directly or through another selected fragment.

### Naming and selection

Prefer an SRFI name for a fragment variant when the spelling is a SRFI, as
in `byteString.srfi207` or `constructor.srfi10`. The tree node still uses
the reader concept, such as `byte_string` or `srfi10_constructor`. Otherwise name
a fragment after the spelling it defines, not the parser that selects it.
Select an existing fragment when a dialect inherits that spelling
unchanged. Add a dialect-named fragment only when the accepted spelling
differs. Do not export an identity alias. Independent sources may keep
parallel fragments for the same spelling; a sibling composition is a new
fragment.

### Lexical tokens

A reusable fragment exposes its top-level composition. In the owning
`grammar.js`, prefer `token(...)` for each complete lexical spelling, including
numbers, symbols, whitespace runs, and comments, when its boundary can be
recognized without parser nodes or contextual tokenization. This keeps large
lexical expressions out of parser-rule expansion and can make generation much
faster:

```javascript
number: _ => token(syntax.number.r7rs),
symbol: _ => token(syntax.symbol.chicken),
```

Keep complete exported reader spellings unwrapped in reusable fragments.
The consuming grammar chooses the token boundary, so another grammar can
compose the same fragment into a larger lexical choice without nested tokens.

A fragment may still contain `token(...)` when the token is a context-local
part of the reader spelling. Keep the shared delimiter visible to the parser,
then tokenize only the body whose alternatives must compete in that context:

```javascript
r7rs: seq("#", token(choice(
  /[tTfF]/,
  /[tT][rR][uU][eE]/,
  /[fF][aA][lL][sS][eE]/,
))),
```

CHICKEN boolean names and number-vector tags both follow `"#"`. After the
parser shifts that delimiter, the tokenized `f32` tag beats the shorter `f`
boolean name. A contextual fragment such as `numberVector.chickenTag` may
itself be a token because its contract is the body after that shared prefix,
not a complete reader spelling. Internal whitespace or opaque bodies may also
be tokenized when their boundary is intrinsic to the surrounding factory and
cannot compete as a standalone grammar node.

Wrap a complete spelling at its owning grammar rule whenever the lexical
boundary permits it. When every selected fragment is raw at that level,
wrapping the complete call-site `choice(...)` can also shrink the lexer and
stabilize token selection. Do not wrap across a fragment's contextual token.
The grammar owns that decision because only the grammar knows all competing
nodes.

Raw expressions such as `core.anyCharacter` stay unwrapped so callers can
compose them. A factory containing grammar nodes, such as a list or datum
comment, cannot be a token.

### Precedence and factories

The owning grammar sets precedence because precedence depends on its competing
rules. Shared fragments do not choose `prec(...)` values. They may receive a
precedence wrapper from the caller:

```javascript
token(prec(1, syntax.keyword.guilePostfix))
syntax.comment.block($.block_comment, value => prec(100, value))
```

Pass a factory only the grammar nodes and dialect fragments it uses,
never the complete `$` namespace:

```javascript
sexp_comment: $ => syntax.comment.datum($._intertoken, $._datum),
keyword: $ => syntax.keyword.hashColon(alias($._keyword_symbol, $.symbol)),
```

Pass recursive rules into factories instead of hard-coding public rule names.
Pass dialect-dependent syntax explicitly. For example, keyword names should
use the dialect's selected symbol syntax.

Preserve handwritten Tree-sitter expressions when moving them into shared
modules. Use a factory when syntax needs a grammar node or a selected fragment;
do not replace a number grammar with a generic factory merely to reduce lines.

## Syntax-tree contract

Use the same node name for the same reader concept across dialects. Different
boolean spellings still produce `boolean`. Implementation-specific constructs
may use implementation-specific names, with queries owned by the dialect.

Collection contents are direct children without fields for their ordinary
positions. In `(a b c)`, the three named `symbol` nodes are direct children of
`list`. An `elements` field would repeat information supplied by the node type
and child order. A child without a field is not necessarily an unnamed node.

Use a field when a child has a distinct role, such as a name, prefix, rank,
type, or target. A field must point to a syntax-tree node. To expose a lexical
token through a field, give the token a named rule or alias. A `field(...)`
nested inside `token(...)` is not exposed in the generated tree.

Keep grammar rules, expected trees, and queries aligned when changing node
names or fields. Sharing a node name does not make complete dialect trees or
queries interchangeable.

## Generated files and verification

Only the default parser tracks generated files in `src/`; its bindings need
those files. Do not commit generated files under `dialects/*/src/`. A dialect
may track a handwritten external scanner there while ignoring generated files.

Generate each dialect from its own directory, using the repository's CLI.
Never pass a dialect `grammar.js` to generation from the repository root:
that overwrites default `src/`. Root `npm run generate:<dialect>`,
`test:<dialect>`, and `parse:<dialect>` commands handle the working directory;
see [CONTRIBUTING.md](../CONTRIBUTING.md).

Every maintained dialect must generate and pass its corpus tests in CI.
Generation is itself a required check because it exposes lexer and parser
conflicts. Changes to shared fragments require generation and tests for every
parser that selects the affected fragments.

Corpus tests cover positive dialect syntax, shared syntax, rejected syntax,
token boundaries, and deliberate permissiveness. Check expected node names and
fields as well as acceptance, and validate the affected queries. Share corpus
cases where practical instead of copying identical cases between dialects.

Scripts own corpus cases whose bytes are easy to damage in an editor:

- R6RS line endings: `scripts/write-r6rs-line-ending-corpus.js`
- R7RS line endings: `scripts/write-r7rs-line-ending-corpus.js`
- Chez line endings: `scripts/write-chez-line-ending-corpus.js`
- Guile whitespace: `scripts/write-guile-whitespace-corpus.js`

Change those scripts rather than hand-editing or copying their generated cases.
After changing the default grammar or its selected fragments, regenerate the
checked-in `src/` files and verify that the generated diff is intentional.
