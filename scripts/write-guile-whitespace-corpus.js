"use strict";

// Guile skips only space, tab, formfeed, CR, and LF. Vertical tab, NEL, and
// Unicode spaces stay inside tokens. Those characters look like ordinary
// spaces in an editor, so this script writes the corpus cases instead of
// storing them in dialects/guile/test/corpus/guile.scm.

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
  (symbol))

===
NEL is not whitespace
===

foo${nel}bar

---

(program
  (symbol))

===
Unicode space is not whitespace
===

foo${nbsp}bar

---

(program
  (symbol))

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
