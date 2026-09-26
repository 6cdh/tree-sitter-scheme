"use strict";

const {spawnSync} = require("child_process");
const fs = require("fs");
const path = require("path");

const root = path.join(__dirname, "..");
const dialect = process.argv[2];
const action = process.argv[3] || "test";
const extraArgs = process.argv.slice(4);
const actions = new Set(["generate", "build", "test", "parse"]);

if (!dialect || !actions.has(action)) {
  console.error("usage: node scripts/run-dialect.js <dialect> generate|build|test|parse [file...]");
  process.exit(2);
}

const dir = path.join(root, "dialects", dialect);
if (!fs.existsSync(path.join(dir, "grammar.js"))) {
  console.error(`missing dialect grammar: ${dir}/grammar.js`);
  process.exit(2);
}

// Spawn the package binary. npm's .bin/tree-sitter.cmd is not a
// CreateProcess executable, so spawnSync of that shim fails on Windows.
const localBin = path.join(
  root,
  "node_modules",
  "tree-sitter-cli",
  process.platform === "win32" ? "tree-sitter.exe" : "tree-sitter",
);
const bin = fs.existsSync(localBin) ? localBin : "tree-sitter";

function run(args) {
  const result = spawnSync(bin, args, {cwd: dir, stdio: "inherit"});
  if (result.error) {
    console.error(result.error.message);
    process.exit(1);
  }
  if (result.status !== 0) {
    process.exit(result.status === null ? 1 : result.status);
  }
}

const corpusByDialect = {
  r6rs: "./write-r6rs-line-ending-corpus.js",
  chez: "./write-chez-line-ending-corpus.js",
  r7rs: "./write-r7rs-line-ending-corpus.js",
  guile: "./write-guile-whitespace-corpus.js",
  chicken: "./write-chicken-scanner-corpus.js",
};
const corpusScript = corpusByDialect[dialect];
if (corpusScript) {
  require(corpusScript)();
}

// Always generate in the dialect directory. The CLI writes src/ in cwd;
// generating from the repository root would overwrite the default parser.
run(["generate"]);

if (action === "generate") {
  process.exit(0);
}

if (action === "build") {
  run(["build"]);
  process.exit(0);
}

if (action === "parse") {
  if (extraArgs.length === 0) {
    console.error("usage: node scripts/run-dialect.js <dialect> parse <file> [file...]");
    process.exit(2);
  }
  run(["build"]);
  // Parse loads src/ from cwd. Keep that as the dialect directory, but
  // resolve file names from the caller's cwd.
  const parseArgs = extraArgs.map((arg) => {
    if (arg.startsWith("-")) {
      return arg;
    }
    return path.resolve(process.cwd(), arg);
  });
  run(["parse", ...parseArgs]);
  process.exit(0);
}

run(["test", ...extraArgs]);
