"use strict";

// Compile against the runtime bundled with the installed Node dependency.
// CLI 0.24 passes some column-dependent reuse cases that fail with the
// supported 0.21 runtime.
const {spawnSync} = require("child_process");
const fs = require("fs");
const path = require("path");

const root = path.join(__dirname, "..");
const runtime = path.join(
  path.dirname(require.resolve("tree-sitter/package.json")),
  "vendor", "tree-sitter", "lib",
);
const scratch = path.join(root, ".agent-scratch");
fs.mkdirSync(scratch, {recursive: true});
const work = fs.mkdtempSync(path.join(scratch, "chicken-incremental-"));

function run(command, args) {
  const result = spawnSync(command, args, {cwd: root, stdio: "inherit"});
  if (result.error) throw result.error;
  if (result.status !== 0) throw new Error(`${command} failed (${result.status})`);
}

try {
  run(process.execPath, ["scripts/run-dialect.js", "chicken", "generate"]);
  const executable = path.join(work, process.platform === "win32" ? "test.exe" : "test");
  run(process.env.CC || "cc", [
    "-std=c11", "-O1", "-D_POSIX_C_SOURCE=200112L",
    `-I${path.join(runtime, "include")}`, `-I${path.join(runtime, "src")}`,
    "-Idialects/chicken/src", "dialects/chicken/test/incremental.c",
    "dialects/chicken/src/parser.c", "dialects/chicken/src/scanner.c",
    path.join(runtime, "src", "lib.c"), "-o", executable,
  ]);
  run(executable, []);
} finally {
  fs.rmSync(work, {recursive: true, force: true});
}
