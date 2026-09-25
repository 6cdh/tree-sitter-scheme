# Dialect parser workflow

Collect published syntax, formalize it, then implement it. For existing parsers,
reuse established sources and productions; fill specification gaps before
changing the affected grammar. [design.md](design.md) owns the contracts.

## 1. Collect sources

Establish the target release, inherited standard, and reader defaults. Collect
precise document sections for whitespace, comments, directives, identifiers,
literals, collections, abbreviations, labels, and dialect reader forms.
Include extension defaults and activation controls; exclude special-form
semantics. Verify extracted escapes, Unicode, and production names against
the sources. Resolve missing sources through documentation or ask the user
about blockers.

Done: each applicable reader category has a cited or inherited rule, with
remaining source gaps explicit.

## 2. Write the specification

Create or update `docs/<dialect>-scheme-syntax.md` using the
[required structure](design.md#dialect-syntax-document-structure). Formalize
published prose, cite each production, and reference unchanged inherited rules.
Specify boundaries and constraints. Separate default syntax, including enabled
extensions, from optional syntax for disabled extensions.

Only investigate interpreter behavior for a specific published rule already
marked unclear or ambiguous in the specification. Follow the design's ambiguity
procedure; missing documentation alone is insufficient. Keep parser decisions
out of the syntax specification.

Done: collected rules are formalized or inherited; unresolved questions are
explicit, raised with the user when blocking, and affected rules deferred.

## 3. Implement the specification

Support default syntax and extensions enabled by default. Exclude extensions
disabled by default unless the user explicitly requests otherwise. Record
coverage in the tracking issue or review description:

| Specification production | Default setting | Decision and reason | Grammar / corpus case |
| --- | --- | --- | --- |
| Name and link | Enabled / disabled | Include / exclude / defer | Rule and case |

Group inherited rules when they share tests. Before coding, define included
features' tree shapes and resolve conflicts in any requested combination of
modes. Record coverage exceptions, editor permissiveness, and reader-state
limits in grammar comments and tests.

Implement one reader category with its corpus expectations at a time. Reuse
fragments and follow the design contracts. Derive positive, negative, boundary,
and interaction cases from the specification and parser contract; account for
editor permissiveness. Check state-changing incremental edits for scanners.
Adapt upstream tests only for specified reader syntax, retaining revision,
attribution, and license notices; translate value assertions into tree
expectations where appropriate.

Return to sources and update the specification before implementing any newly
identified syntax requirement.

Done: included productions map to grammar rules and meaningful tests; exclusions
and parser limits are explicit.

## 4. Verify and review

Follow [generation and verification rules](design.md#generated-files-and-verification)
and [repository commands](../CONTRIBUTING.md). Generate each dialect from its own
directory, run corpus tests, validate queries, and inspect tree shapes. Generate
and test every parser affected by shared-fragment changes.

Review the trace from sources to specification to grammar and tests. Acceptance
alone does not establish correct tree shape. Fix in-scope defects and rerun
affected checks; route syntax additions through steps 1 and 2.

Done: required checks pass; review findings are resolved or explicitly deferred;
the work record states remaining exclusions and verification limits.
