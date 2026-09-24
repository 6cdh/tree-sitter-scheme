const specialObject = {
  // Guile dispatches only on lowercase n. The rest is case-insensitive when
  // that reader option is enabled, which the static dialect union accepts.
  guile: seq("#", token(seq("n", /[iI][lL]/))),
  chez: seq("#!", token(choice("eof", "bwp", "base-rtd"))),
  chicken: seq("#!", token(choice("eof", "bwp"))),
};

const dssslMarker = {
  chicken: seq("#!", token(choice("optional", "rest", "key"))),
};

const label = {
  definition: {
    // R7RS 2.4: `#⟨n⟩=⟨datum⟩` with no atmosphere after `=`.
    r7rs: (label, datum) =>
      seq("#", field("label", label), "=", datum),
    // Chez: `#n=` is one token; intertoken may follow before the datum.
    chez: (label, intertoken, datum) =>
      seq(
        "#",
        field("label", label),
        "=",
        repeat(intertoken),
        datum),
  },
  reference: label =>
    seq("#", field("label", label), "#"),
};

const foreignDeclare = {
  // A run of `<` belongs to the body unless followed by `#`; then its last
  // `<` starts the closer. Pairing `<` with any non-`#` would hide `<<#`.
  chicken:
    seq(
      "#>",
      token(
        seq(
          repeat(
            choice(
              /[^<]+/,
              seq(repeat1("<"), /[^<#]/))),
          repeat1("<"),
          "#"))),
};

const locationExpr = {
  // CHICKEN Extensions: `#$<datum>` with no atmosphere after `#$`.
  chicken: datum =>
    seq(
      "#$",
      field("target", datum)),
};

const condExpand = {
  // CHICKEN Extensions: `#+<datum> <datum>` with no atmosphere after `#+`.
  chicken: (intertoken, datum) =>
    seq(
      "#+",
      field("feature", datum),
      repeat(intertoken),
      field("body", datum)),
};

const constructor = {
  srfi10: (intertoken, name, token) =>
    seq(
      "#,(",
      repeat(intertoken),
      field("name", name),
      repeat(token),
      ")"),
};

// Chez's two-name gensym reader skips only these three characters between
// names. It does not skip comments or other atmosphere at that point.
const gensymSpace = token(repeat1(/[ \t\n]/));

const gensym = {
  pretty: symbol => seq("#:", symbol),
  unique: symbol =>
    seq(
      "#{",
      symbol,
      repeat1(gensymSpace),
      symbol,
      "}"),
};

const primitive = (prefix, symbol) =>
  seq(
    field("prefix", prefix),
    symbol);

module.exports = {
  condExpand,
  constructor,
  dssslMarker,
  foreignDeclare,
  gensym,
  label,
  locationExpr,
  primitive,
  specialObject,
};
