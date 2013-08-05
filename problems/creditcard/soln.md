# **Solution:** creditcard
- `charToNum` should take a `char`, not a `char*`
- `sumOfDigits` should return `sum`
- `#include <string.h>` needed (error message says this)
- the loop has a semicolon at the end (error message does point this out, among
  a few other irrelevant errors)
- `lastIndex` is unused (you can either remove it or use it in the definition
  of `index`)
- only non-compiler error: `luhn` should be returning `checkum == 0`, not `checksum = 0`

???

Hopefully the compiler messages for each of these problems made sense. If not,
re-read them carefully. Eventually you'll build an intuition for how error
messages map to problems in the code.

The last error is noteworthy for being a nasty issue in C programs. The code
`return checksum = 0;` sets `checksum` to 0 and then returns its value, which
shows up in the tests as every value being false. `clang` tries to help avoid
this issue by triggering a warning if you write

        if (checksum = 0) {
          // something

but the example avoids that with a return.

One way to avoid this issue is to always write comparisons with constant values
with the constant on the left, writing `return 0 == checksum;`. Then the
single-equals version doesn't compile. This is a technique recommended and
practiced by Professor Lumetta: very experienced C users develop this habit to
avoid this issue from sneaking into code unnoticed.

 A note on `gcc`: many of these error messages are either harder to understand
 (for example, `gcc` does not point out that `<string.h>` would solve the issue
 with `strlen` not being defined) or entirely absent (`gcc` does not care if
 you have an empty `for` loop body, since this is perfectly valid C). Use
 `clang` until you have a good reason to use `gcc`.
