"use strict";

const {spawnSync} = require("child_process");
const fs = require("fs");
const path = require("path");

const root = path.join(__dirname, "..");
const dialect = process.argv[2];
const action = process.argv[3] || "test";
const actions = new Set(["generate", "build", "test"]);

if (!dialect || !actions.has(action)) {
  console.error("usage: node scripts/run-dialect.js <dialect> generate|build|test");
  process.exit(2);
}

const dir = path.join(root, "dialects", dialect);
if (!fs.existsSync(path.join(dir, "grammar.js"))) {
  console.error(`missing dialect grammar: ${dir}/grammar.js`);
  process.exit(2);
}

const bin = path.join(root, "node_modules", ".bin", "tree-sitter");

function run(args) {
  const result = spawnSync(bin, args, {cwd: dir, stdio: "inherit"});
  const status = result.status === null ? 1 : result.status;
  if (status !== 0) {
    process.exit(status);
  }
}

// Always generate in the dialect directory. CLI 0.24 writes src/ in cwd;
// generating from the repository root would overwrite the default parser.
run(["generate"]);

if (action === "generate") {
  process.exit(0);
}

if (action === "build") {
  run(["build"]);
  process.exit(0);
}

run(["test"]);
