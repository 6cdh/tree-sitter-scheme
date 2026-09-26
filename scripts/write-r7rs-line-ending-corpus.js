"use strict";

// R7RS string continuations accept CR, LF, and CRLF, but not the extra
// Unicode line endings accepted by R6RS. Generate these easy-to-corrupt cases.

const fs = require("fs");
const path = require("path");

const lineSeparator = "\u2028";

const out = path.join(
  __dirname,
  "..",
  "dialects",
  "r7rs",
  "test",
  "corpus",
  "generated-line-endings.scm",
);

const corpus = `===
CRLF is an R7RS string continuation
===

"before\\\r\n  after"

---

(program
  (string
    (escape_sequence)))

===
Unicode line separator is not an R7RS string continuation
===

"before\\${lineSeparator}after"

---

(program
  (string
    (ERROR)))
`;

function writeR7rsLineEndingCorpus() {
  fs.mkdirSync(path.dirname(out), {recursive: true});
  fs.writeFileSync(out, corpus, "utf8");
}

if (require.main === module) {
  writeR7rsLineEndingCorpus();
}

module.exports = writeR7rsLineEndingCorpus;
