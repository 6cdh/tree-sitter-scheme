"use strict";

// Compile and run incremental reuse checks against the Node-bundled tree-sitter runtime.
const {spawnSync} = require("child_process");
const fs = require("fs");
const os = require("os");
const path = require("path");

const root = path.join(__dirname, "..");
const runtime = path.join(
  path.dirname(require.resolve("tree-sitter/package.json")),
  "vendor", "tree-sitter", "lib",
);
const work = fs.mkdtempSync(path.join(os.tmpdir(), "chicken-incremental-"));

function run(command, args) {
  const result = spawnSync(command, args, {cwd: root, stdio: "inherit"});
  if (result.error) throw result.error;
  if (result.status !== 0) throw new Error(`${command} failed (${result.status})`);
}

try {
  run(process.execPath, ["scripts/run-dialect.js", "chicken", "generate"]);
  const executable = path.join(work, process.platform === "win32" ? "test.exe" : "test");
  run(process.env.CC || "cc", [
    // 0.25 vendor unicode.h uses le16toh, which glibc exposes under
    // _DEFAULT_SOURCE, not _POSIX_C_SOURCE.
    "-std=c11", "-O1", "-D_DEFAULT_SOURCE",
    `-I${path.join(runtime, "include")}`, `-I${path.join(runtime, "src")}`,
    "-Idialects/chicken/src", "dialects/chicken/test/incremental.c",
    "dialects/chicken/src/parser.c", "dialects/chicken/src/scanner.c",
    path.join(runtime, "src", "lib.c"), "-o", executable,
  ]);
  run(executable, []);
} finally {
  fs.rmSync(work, {recursive: true, force: true});
}
