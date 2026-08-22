const common = {
  whitespace: /[ \r\n\t\f\v\p{Zs}\p{Zl}\p{Zp}]/,
  intra_whitespace: /[\t\p{Zs}]/,
  line_ending: /[\n\r\u{2028}\u{0085}]|(\r\n)|(\r\u{0085})/,
  any_char: /.|[\r\n\u{85}\u{2028}\u{2029}]/,

  symbol_element:
    /[^ \r\n\t\f\v\p{Zs}\p{Zl}\p{Zp}#;"'`,\(\)\{\}\[\]\\\|]/,
};

const whitespace = {
  // R5RS names only space and newline as portable whitespace.
  r5rs: token(repeat1(/[ \r\n]/)),
  extended: token(repeat1(common.whitespace)),
};

module.exports = {
  common,
  whitespace,
};
