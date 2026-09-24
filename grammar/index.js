const core = require("./core");
const literals = require("./literals");
const numbers = require("./number");
const strings = require("./string");
const symbols = require("./symbol");
const intertoken = require("./intertoken");
const collections = require("./collections");
const abbreviations = require("./abbreviations");
const hashForms = require("./hash-forms");

module.exports = {
  core,
  syntax: {
    boolean: literals.boolean,
    byteString: strings.byteString,
    character: literals.character,
    intralineWhitespace: strings.intralineWhitespace,
    keyword: symbols.keyword,
    lineEnding: strings.lineEnding,
    number: numbers.number,
    string: strings.string,
    stringEscape: strings.stringEscape,
    symbol: symbols.symbol,
    abbrev: abbreviations.abbrev,
    box: collections.box,
    comment: intertoken.comment,
    condExpand: hashForms.condExpand,
    constructor: hashForms.constructor,
    directive: intertoken.directive,
    dssslMarker: hashForms.dssslMarker,
    foreignDeclare: hashForms.foreignDeclare,
    gensym: hashForms.gensym,
    label: hashForms.label,
    list: collections.list,
    locationExpr: hashForms.locationExpr,
    numberVector: collections.numberVector,
    primitive: hashForms.primitive,
    record: collections.record,
    specialObject: hashForms.specialObject,
    vector: collections.vector,
  },
};
