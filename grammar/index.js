const core = require("./core");
const literals = require("./literals");
const reader = require("./reader");

module.exports = {
  core,
  syntax: {
    ...literals,
    ...reader,
  },
};
