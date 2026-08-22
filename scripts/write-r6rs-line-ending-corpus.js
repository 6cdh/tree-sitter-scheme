"use strict";

// R6RS 4.2 treats NEL, line separator, and paragraph separator as line
// endings or whitespace. Those characters look like ordinary spaces in an
// editor, so this script writes the corpus cases instead of storing them
// in dialects/r6rs/test/corpus/r6rs.scm.

const fs = require("fs");
const path = require("path");

const nel = "\u0085";
const lineSeparator = "\u2028";
const paragraphSeparator = "\u2029";

const out = path.join(
  __dirname,
  "..",
  "dialects",
  "r6rs",
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
Line comment ends at paragraph separator
===

;cmt${paragraphSeparator}next

---

(program
  (comment)
  (symbol))
`;

function writeR6rsLineEndingCorpus() {
  fs.mkdirSync(path.dirname(out), {recursive: true});
  fs.writeFileSync(out, corpus, "utf8");
}

if (require.main === module) {
  writeR6rsLineEndingCorpus();
}

module.exports = writeR6rsLineEndingCorpus;
