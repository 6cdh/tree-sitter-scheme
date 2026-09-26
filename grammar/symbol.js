const { anyCharacter } = require("./core");

const r6rsHexEscape = /\\x[0-9a-fA-F]+;/;

// R6RS constituent above ASCII. A positive `\p{Po}` class would also
// match ASCII `'` and `,`, which must stay quote/unquote marks.
// CLI 0.24 cannot name the unassigned Cn category, so unassigned scalar
// values still match.
// TODO: after upgrading past CLI 0.24, add `\p{Cn}` to this class so
// unassigned scalar values are excluded. CLI 0.25's regex tables include Cn.
const r6rsUnicodeInitial =
  /[^\x00-\x7F\p{Cc}\p{Cf}\p{Cs}\p{Mc}\p{Me}\p{Nd}\p{Pe}\p{Pf}\p{Pi}\p{Ps}\p{Zs}\p{Zl}\p{Zp}]/;
// Nd, Mc, and Me only. Other Unicode subsequent characters already match
// as r6rsInitial, and subsequent includes initial.
const r6rsUnicodeSubsequent = /[\p{Nd}\p{Mc}\p{Me}]/;

const r6rsInitial = choice(
  /[A-Za-z!$%&*\/:<=>?^_~]/,
  r6rsUnicodeInitial,
  r6rsHexEscape,
);
const r6rsSubsequent = choice(
  r6rsInitial,
  /[0-9+.@-]/,
  r6rsUnicodeSubsequent,
);

const r7rsInitial = /[A-Za-z!$%&*\/:<=>?^_~]/;
const r7rsSignSubsequent = choice(r7rsInitial, /[+\-@]/);
const r7rsDotSubsequent = choice(r7rsSignSubsequent, ".");
const r7rsSubsequent = choice(r7rsInitial, /[0-9+.@-]/);
const r7rsBareSymbolMembers = [
  seq(r7rsInitial, repeat(r7rsSubsequent)),
  seq(/[+-]/, optional(seq(r7rsSignSubsequent, repeat(r7rsSubsequent)))),
  seq(/[+-]/, ".", r7rsDotSubsequent, repeat(r7rsSubsequent)),
  seq(".", r7rsDotSubsequent, repeat(r7rsSubsequent)),
];
const r7rsBarSymbol = seq(
  "|",
  repeat(
    choice(
      /[^\|\\]+/,
      /\\[xX][0-9a-fA-F]+;/,
      /\\[abtnr]/,
      "\\|")),
  "|",
);
// Delimiter-terminated `#:` names. A digit may start the name (`#:1abc`).
// `|` opens the R7RS bar form.
const hashColonTokenChar =
  /[^ \r\n\t\f\v\p{Zs}\p{Zl}\p{Zp}#;"'`,\(\)\{\}\[\]\\\|]/;

const chezBarSymbolPart = seq(
  "|",
  repeat(/[^|]+/),
  "|",
);
const chezSymbolPart = choice(
  /[^\s\u{85}()\[\]{}"'`,;#\\|]+/,
  /\\x[0-9a-fA-F]+;/,
  /\\[^x]/,
  chezBarSymbolPart,
);
const chezSymbolStartPart = choice(
  /[^\s\u{85}()\[\]{}"'`,;#\\|0-9+\-.]+/,
  /\\x[0-9a-fA-F]+;/,
  /\\[^x]/,
  chezBarSymbolPart,
);
// Once Chez dispatches to the number-or-symbol reader, `#`, `|`, and `\` are
// ordinary non-delimiters. If numeric conversion fails, the complete token is
// a symbol. This separate shape keeps a `|` in 1.0|53 from opening a bar group
// that could consume whitespace and a later mantissa-width separator.
const chezNumberSymbolMember = /[^\s\u{85}()\[\]{}"'`,;]/;

const symbol = {
  r5rs:
    choice(
      seq(
        /[A-Za-z!$%&*\/:<=>?^_~]/,
        repeat(/[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/)),
      "+",
      "-",
      "..."),
  // R6RS identifier: initial subsequent* | peculiar identifier.
  r6rs:
    choice(
      seq(r6rsInitial, repeat(r6rsSubsequent)),
      "+",
      "-",
      "...",
      seq("->", repeat(r6rsSubsequent))),
  r7rs:
    choice(
      ...r7rsBareSymbolMembers,
      r7rsBarSymbol),
  // Chez accepts any delimited sequence that is not a number as an
  // identifier. A longer spelling such as 0abc wins as one identifier
  // instead of being split after the leading number. In Chez mode, a
  // number-like token may contain `#`; it becomes an identifier when the
  // complete token is not a number, as in 32/#. `|` is not a Chez
  // delimiter, so 32/#|foo| is one identifier.
  chez:
    choice(
      seq(/[0-9]/, repeat(chezNumberSymbolMember)),
      seq(/[+\-.]/, repeat1(chezNumberSymbolMember)),
      seq(chezSymbolStartPart, repeat(chezSymbolPart)),
      "+",
      "-",
      "{",
      "}"),
};

const chickenBarSymbol = seq(
  "|",
  repeat(choice(
    /[^|\\]+/,
    /\\[xX][0-9a-fA-F]+;/,
    /\\[abtnr|]/,
  )),
  "|",
);
const chickenInitial = /[A-Za-z!$%&*\/:<=>?^_~]/;
const chickenSubsequent = /[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/;
const chickenNonColonSubsequent = /[A-Za-z!$%&*\/<=>?^_~0-9+.@-]/;
const chickenSymbolTail = repeat(chickenSubsequent);
// Colon may appear inside an ordinary symbol, but not at the end. `foo:` is
// then only a suffix keyword, which is longer, so the lexer needs no prec.
const chickenOrdinaryTail = repeat(choice(
  chickenNonColonSubsequent,
  seq(repeat1(":"), chickenNonColonSubsequent),
));
const chickenBareSymbol = (initial, tail = chickenSymbolTail) => choice(
  seq(initial, tail),
  seq(
    /[+-]/,
    optional(seq(
      choice(initial, /[+\-@]/),
      tail))),
  seq(
    /[+-]/,
    ".",
    choice(initial, /[+\-@]/, "."),
    tail),
  seq(
    ".",
    choice(initial, /[+\-@]/, "."),
    tail),
);
// The default suffix style leaves :NAME as a symbol. A final colon belongs
// to the suffix keyword rule; names after #: keep colon in both positions.
symbol.chicken = choice(
  chickenBareSymbol(chickenInitial, chickenOrdinaryTail),
  chickenBarSymbol,
);
symbol.chickenKeywordName = choice(
  chickenBareSymbol(chickenInitial),
  chickenBarSymbol,
);
// Default Guile keeps R5RS identifiers and treats braces and vertical bar
// as ordinary symbol characters when optional reader modes are off.
symbol.guile = choice(
  seq(
    /[A-Za-z!$%&*\/:<=>?^_~{}|]/,
    repeat(/[A-Za-z!$%&*\/:<=>?^_~{}|0-9+.@-]/)),
  // A numeric-looking token with a brace or bar is a symbol, not a
  // number followed by punctuation: `{n + 1}` ends with `1}`.
  seq(
    /[0-9]/,
    repeat(/[A-Za-z!$%&*\/:<=>?^_~0-9+.@-]/),
    /[{}|]/,
    repeat(/[A-Za-z!$%&*\/:<=>?^_~{}|0-9+.@-]/)),
  "+",
  "-",
  "...",
);
// Guile's #{...}# form stops at the first }#. Do not wrap this in token():
// repeat(anyCharacter) would be greedy and take the last }#, and wrap(prec)
// inside token() does not compete with anyCharacter in the same token.
// Keep it structural, like block comments: }# stays here, wrap sets priority.
symbol.guileExtended = wrap => seq(
  "#{",
  repeat(anyCharacter),
  wrap("}#"),
);
const keyword = {
  // Marker then name, no atmosphere. The owning grammar supplies the name
  // node and any alias. Guile and CHICKEN use this; the default parser
  // does not.
  hashColon: name => seq("#:", field("name", name)),
  // Complete `#:name` token. Wrap at the owning grammar. Unlike hashColon,
  // the name is not a child node.
  hashColonToken: seq(
    "#:",
    choice(
      repeat1(hashColonTokenChar),
      r7rsBarSymbol)),
  chickenSuffix: seq(
    chickenBareSymbol(chickenInitial),
    ":",
  ),
};

module.exports = {
  keyword,
  symbol,
};
