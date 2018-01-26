#include "ctvalue.hpp"
#include <cassert>
#include <cstddef>

// convert single char to corresponding int value at compile time:
constexpr int toInt(char c) {
  // hexadecimal letters:
  if (c >= 'A' && c <= 'F') {
    return static_cast<int>(c) - static_cast<int>('A') + 10;
  }
  if (c >= 'a' && c <= 'f') {
    return static_cast<int>(c) - static_cast<int>('a') + 10;
  }
  // other (disable '.' for floating-point literals):
  assert(c >= '0' && c <= '9');
  return static_cast<int>(c) - static_cast<int>('0');
}

// parse array of chars to corresponding int value at compile time:
template<std::size_t N>
constexpr int parseInt(char const (&arr)[N]) {
  int base = 10;       // to handle base (default: decimal)
  int offset = 0;      // to skip prefixes like 0x
  if (N > 2 && arr[0] == '0') {
    switch (arr[1]) {
      case 'x':        // prefix 0x or 0X, so hexadecimal
      case 'X':
        base = 16;
        offset = 2;
        break;
      case 'b':        // prefix 0b or 0B (since C++14), so binary
      case 'B':
        base = 2;
        offset = 2;
        break;
      default:         // prefix 0, so octal
        base = 8;
        offset = 1;
        break;
    }
  }
  // iterate over all digits and compute resulting value:
  int value = 0;
  int multiplier = 1;
  for (std::size_t i = 0; i < N - offset; ++i) {
    if (arr[N-1-i] != '\'') { // ignore separating single quotes (e.g. in 1'000)
      value += toInt(arr[N-1-i]) * multiplier;
      multiplier *= base;
    }
  }
  return value;
}

// literal operator: parse integral literals with suffix _c as sequence of chars:
template<char... cs>
constexpr auto operator"" _c() {
  return CTValue<int, parseInt<sizeof...(cs)>({cs...})>{};
}
