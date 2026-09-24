// Round, square, and curly lists share one shape: delimiters around repeated
// contents. A dialect that allows dotted lists passes choice(token, dot).
const list = {
  round: token => seq("(", repeat(token), ")"),
  square: token => seq("[", repeat(token), "]"),
  curly: token => seq("{", repeat(token), "}"),
};

// Guile array prefix between `#` and `(`. The dialect keeps those delimiters
// in the same token so `#f32(` beats boolean `#f` and `#u8(` beats byte-string
// `#u8`. Length is enough; do not add prec(). `#(` is the vector rule, not an
// empty prefix. `#vu8(` is the bytevector rule. Bare `#a(` and `#b(` are
// unknown hash objects; ranked `#2a(` is an array.
function guile_array_prefix() {
  const rank = /[0-9]+/;
  const unsigned = /[0-9]+/;
  const uniformTag = choice(
    "u8", "u16", "u32", "u64",
    "s8", "s16", "s32", "s64",
    "f32", "f64", "c32", "c64",
  );
  // Ranked arrays also allow string/bit tags a and b (`#2a(`). Bare `#a(`
  // is not an array. Unranked forms use only uniformTag (`#u8(`).
  const vectag = choice(uniformTag, "a", "b");
  const dimension = choice(
    seq("@", optional(/[+-]/), unsigned, optional(seq(":", unsigned))),
    seq(":", unsigned),
  );
  return choice(
    seq(rank, optional(vectag), repeat(dimension)),
    seq(uniformTag, repeat(dimension)),
    repeat1(dimension),
  );
}

const vector = {
  hash: token => seq("#(", repeat(token), ")"),
  u8: token => seq("#u8(", repeat(token), ")"),
  vu8: token => seq("#vu8(", repeat(token), ")"),
  hashLength: (length, token) =>
    seq("#", optional(field("length", length)), "(", repeat(token), ")"),
  vu8Length: (length, token) =>
    seq("#", optional(field("length", length)), "vu8(", repeat(token), ")"),
  vfx: (length, token) =>
    seq("#", optional(field("length", length)), "vfx(", repeat(token), ")"),
  vfl: (length, token) =>
    seq("#", optional(field("length", length)), "vfl(", repeat(token), ")"),
  vs: (mask, token) =>
    seq("#", field("mask", mask), "vs(", repeat(token), ")"),
  // Literal `#` then `*`, then zero or more bit characters. `#*` is the
  // empty bitvector. This is not a regex "zero or more hashes".
  guileBitvector: seq("#", token(seq("*", /[01]*/))),
  guileArrayPrefix: guile_array_prefix(),
};

const numberVector = {
  // The tag follows a shared `#`. Keeping only the tag as one token lets
  // `f32` beat the shorter R7RS boolean name `f` before the parser sees `(`.
  chickenTag: token(choice(
    "u16", "u32", "u64",
    "s8", "s16", "s32", "s64",
    "f32", "f64", "c64", "c128",
  )),
};

const box = (intertoken, datum) =>
  seq("#&", repeat(intertoken), datum);

const record = (intertoken, token, typeName) =>
  seq(
    "#[",
    repeat(intertoken),
    field("name", typeName),
    repeat(token),
    "]");

module.exports = {
  box,
  list,
  numberVector,
  record,
  vector,
};
