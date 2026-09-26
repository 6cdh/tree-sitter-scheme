"use strict";

// Chez line comments stop at NEL and line separator, but not paragraph
// separator. Generate these easy-to-corrupt cases instead of storing the
// Unicode characters in dialects/chez/test/corpus/chez.scm.

const fs = require("fs");
const path = require("path");

const nel = "\u0085";
const lineSeparator = "\u2028";
const paragraphSeparator = "\u2029";

const out = path.join(
  __dirname,
  "..",
  "dialects",
  "chez",
  "test",
  "corpus",
  "generated-line-endings.scm",
);

const corpus = `===
NEL is whitespace
===

a${nel}b

---

(program
  (symbol)
  (symbol))

===
Line comment ends at NEL
===

;cmt${nel}next

---

(program
  (comment)
  (symbol))

===
Line comment ends at line separator
===

;cmt${lineSeparator}next

---

(program
  (comment)
  (symbol))

===
Paragraph separator stays in Chez line comment
===

;cmt${paragraphSeparator}next
after

---

(program
  (comment)
  (symbol))
`;

function writeChezLineEndingCorpus() {
  fs.mkdirSync(path.dirname(out), {recursive: true});
  fs.writeFileSync(out, corpus, "utf8");
}

if (require.main === module) {
  writeChezLineEndingCorpus();
}

module.exports = writeChezLineEndingCorpus;
