# Dialect parser workflow

Use this workflow to add, rewrite, or review a dialect parser. For an
existing parser, record available evidence and investigate only the gaps.

Published reader syntax defines the baseline. Real usage informs optional
coverage. The parser implements an explicit selection of that syntax, with
documented limits for editing and static parsing.

[design.md](design.md) owns grammar structure, shared fragments, tree shape,
and parser verification rules. This document owns the work process.

## 1. Establish the documented baseline

Create or update `docs/<dialect>-scheme-syntax.md` using the
[dialect syntax document structure](design.md#dialect-syntax-document-structure)
with:

- Target release, inherited standard, and default reader configuration.
- Published rules for whitespace, comments, directives, identifiers,
  booleans, numbers, characters, strings, collections, abbreviations,
  labels, and implementation-specific reader forms.
- Precise source sections and versions. Reuse inherited productions by
  reference when the dialect does not change them.
- Explicit gaps or contradictions in the published rules.

Use formal productions where available. Otherwise summarize the published
reader rules and identify any derived productions as a reconstruction.
Verify extracted text against the source, especially escapes, Unicode,
and production names. Special-form semantics are outside this inventory.

Keep the default baseline separate from optional syntax. Record controls
that change syntax, their defaults, and how optional forms are enabled.
Keep evidence about published gaps separate from known deviations, as
described in [design.md](design.md). Neither overrides clear published rules.

Done: every reader category has a cited rule, an inherited rule, an explicit
absence, or a recorded unresolved gap.

## 2. Survey real usage

Before searching, name a small sample and a search budget. A useful starting
sample is the implementation's source, one major ecosystem project, and two
independent libraries. Adjust this to the dialect's ecosystem and record why.

For each optional syntax candidate, record repository, revision, file,
example, and the reader configuration or extension that enables it. Distinguish
ordinary source from fixtures, generated files, and embedded text. Record
independent projects using a feature; occurrence counts alone do not establish
broad use. Describe findings as evidence from the sample, not ecosystem-wide
prevalence.

Done: the declared sample has been searched and candidates have evidence.
Expand research only to answer a named question that could change coverage.

## 3. Decide parser coverage

Keep a short work record in the dialect's tracking issue or review description.
Use the table below to connect syntax evidence to implementation and tests.
Group inherited rules when a shared test group covers them.

| Reader feature | Source / usage evidence | Default or optional | Decision and reason | Grammar rule / corpus case |
| --- | --- | --- | --- | --- |
| Feature name | Section or pinned file | Default / optional | Include / exclude / defer | Rule and case, or pending |

Default syntax is the baseline. For each optional candidate, decide whether
usage justifies support and whether it can coexist with the baseline.
Popularity alone does not resolve a token or tree-shape conflict.

For example, a distinct dispatch prefix may fit a static union. A keyword
mode that changes `name:` from a symbol to a keyword needs an explicit choice
of interpretation. Check token boundaries as well as accepted spellings.

Record unresolved gaps that affect included syntax before implementing it.
State deliberate permissiveness and limits on reader state or callbacks.
Put durable parser decisions in the owning grammar's comments and tests;
keep syntax reference documents independent of the parser's implementation.

Done: every candidate has a decision, and included features have defined
interpretations and expected tree shapes. Deferred features remain visible.

## 4. Implement by reader category

Select existing shared fragments before adding new definitions. Do not add
a dialect-named fragment that is only an alias of an unchanged inherited
spelling. Follow [design.md](design.md) for fragment naming, node names,
fields, precedence, and scanner use. Implement one reader category at a
time with its corpus expectations.

Derive expectations from documented syntax and the parser's stated contract.
Adapt useful upstream reader tests with source revision and attribution;
preserve applicable license notices. Convert reader value assertions into
tree expectations only where they test reader syntax.

Cover accepted forms, nearby rejected forms, token boundaries, and feature
interactions. Negative cases must respect deliberate editor permissiveness.
For stateful scanners, check incremental edits that change scanner state.

Done: included features are connected to grammar rules and meaningful tests;
any remaining limit is explicit.

## 5. Verify and review

Use the repository commands in [CONTRIBUTING.md](../CONTRIBUTING.md).
Generate a dialect from its own directory. Run its corpus tests, validate its
queries, and inspect representative trees. When shared fragments change,
generate and test all affected parsers. Follow [design.md](design.md) for default generated files and dialect
artifacts.

Parse the sampled real files. Classify failures as implementation defects,
excluded syntax, invalid input, or unresolved coverage questions. A parse without errors is useful evidence, but does not establish that the
tree has the intended shape.

Review against the coverage decisions, syntax sources, and design contract.
Fix in-scope defects and rerun affected checks. Record new coverage proposals
separately so a discovered extension does not silently expand the task.

Done: required checks pass, review findings are resolved or explicitly deferred,
and the work record reports remaining exclusions and verification limits.

## Reusable checklist

- [ ] Target version, inherited standard, defaults, and syntax sources recorded.
- [ ] Reader categories covered; published gaps identified.
- [ ] Bounded usage survey completed with pinned examples and activation details.
- [ ] Coverage table decides default and optional features and conflicts.
- [ ] Included syntax mapped to grammar rules and corpus cases.
- [ ] Tree shape, queries, and deliberate permissiveness checked.
- [ ] Generation and tests pass for every affected parser.
- [ ] Sampled files parsed and failures classified.
- [ ] Review completed; remaining limits and deferred work recorded.
