"use strict";

// Scheme Read discards whitespace and does not list the characters. The
// verified set is space, tab, formfeed, return, and newline. Vertical tab,
// NEL, and Unicode spaces are not intertoken whitespace. Since they look like
// ordinary spaces in an editor, this script writes the corpus cases
// instead of storing them in dialects/guile/test/corpus/guile.scm.

const fs = require("fs");
const path = require("path");

const vtab = "\u000b";
const nel = "\u0085";
const nbsp = "\u00a0";
const formfeed = "\u000c";

const out = path.join(
  __dirname,
  "..",
  "dialects",
  "guile",
  "test",
  "corpus",
  "generated-whitespace.scm",
);

const corpus = `===
Vertical tab is not whitespace
===

foo${vtab}bar

---

(program
  (symbol)
  (ERROR))

===
NEL is not whitespace
===

foo${nel}bar

---

(program
  (symbol)
  (ERROR))

===
Unicode space is not whitespace
===

foo${nbsp}bar

---

(program
  (symbol)
  (ERROR))

===
Formfeed is whitespace
===

foo${formfeed}bar

---

(program
  (symbol)
  (symbol))

===
Line comment does not end at NEL
===

;cmt${nel}next
after

---

(program
  (comment)
  (symbol))
`;

function writeGuileWhitespaceCorpus() {
  fs.mkdirSync(path.dirname(out), {recursive: true});
  fs.writeFileSync(out, corpus, "utf8");
}

if (require.main === module) {
  writeGuileWhitespaceCorpus();
}

module.exports = writeGuileWhitespaceCorpus;
