"use strict";

// Generate cases with CR-only lines and tags at the external scanner's
// serialization boundary. This keeps invisible control characters and
// thousand-column lines out of the checked-in corpus.

const fs = require("fs");
const path = require("path");

const largestAsciiTag = "a".repeat(1020);
const oversizedAsciiTag = "a".repeat(1021);
// 340 three-byte code points occupy 1020 tag bytes.
const largestUnicodeTag = "終".repeat(340);

const out = path.join(
  __dirname,
  "..",
  "dialects",
  "chicken",
  "test",
  "corpus",
  "generated-scanner.scm",
);

const corpus = `===
CR alone does not end a here-string line
===

#<#T\rx\rT\r(+ 1 2)\r

---

(program
  (interpolated_here_string))

===
CRLF here-strings keep CR in the tag and terminator
===

#<#T\r\nx\r\nT\r\n#<<U\r\ny\r\nU\r\n(+ 1 2)\r\n

---

(program
  (interpolated_here_string)
  (here_string)
  (list
    (symbol)
    (number)
    (number)))

===
Largest one-byte tag state is preserved
===

#<#${largestAsciiTag}
body
${largestAsciiTag}
(+ 1 2)

---

(program
  (interpolated_here_string)
  (list
    (symbol)
    (number)
    (number)))

===
An oversized tag is rejected before scanner state is lost
===

#<#${oversizedAsciiTag}
body
${oversizedAsciiTag}
(+ 1 2)

---

(program
  (ERROR)
  (symbol)
  (symbol)
  (list
    (symbol)
    (number)
    (number)))
===
Unicode tags use their encoded byte budget
===

#<#${largestUnicodeTag}
body
${largestUnicodeTag}
(+ 1 2)

---

(program
  (interpolated_here_string)
  (list
    (symbol)
    (number)
    (number)))

===
An oversized Unicode tag is rejected
===

#<#${largestUnicodeTag}a
body
${largestUnicodeTag}a
(+ 1 2)

---

(program
  (ERROR)
  (list
    (symbol)
    (number)
    (number)))

===
Opaque tags are not limited by serialized state
===

#<<${oversizedAsciiTag}
body
${oversizedAsciiTag}
(+ 1 2)

---

(program
  (here_string)
  (list
    (symbol)
    (number)
    (number)))
`;

function writeChickenScannerCorpus() {
  fs.mkdirSync(path.dirname(out), {recursive: true});
  fs.writeFileSync(out, corpus, "utf8");
}

if (require.main === module) {
  writeChickenScannerCorpus();
}

module.exports = writeChickenScannerCorpus;
