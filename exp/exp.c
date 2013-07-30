#include <stdlib.h>
#include "testlib.h"

// Compute the factorial of n, where n must be >= 0.
int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// Compute e^x, where e is the base of the natural logarithm.
// Note: this algorithm for computing e^x is pretty bad, so it won't give
// accurate results when |x| > 2. An actual algorithm would operate on the
// IEEE-754 representation itself and compute 2^(x / ln(2)) instead of e^x
// directly. See http://schraudolph.org/pubs/Schraudolph99.pdf for details.
double exponential(double x) {
  // accumulator to hold the result so far
  double accum = 0.0;
  // x^degree
  double powx = 1.0;
  // 10 iterations should be enough since 10! is very large; too much beyond
  // that and dividing by a very large value will give unexpected results.
  for (int degree = 0; degree < 10; degree++) {
    accum += powx / (double) factorial(degree);
    powx *= x;
  }
  return accum;
}

void TestFactorial(CuTest* tc) {
  int expected[] = {1,1,2,6,24,120};
  int actual[arraylen(expected)];
  int len = arraylen(expected);
  for (int i = 0; i < len; i++) {
    actual[i] = factorial(i);
  }
  CuAssertStrEquals(tc,
                       IntArrayToString(expected, len),
                       IntArrayToString(actual, len));
}

// As noted above, exponential() is inaccurate for large values, so make sure
// |x| < 2.
void TestExponential(CuTest* tc) {
  double tolerance = 0.001;
  CuAssertDblEquals(tc,
                    1.2214027581601699,
                    exponential(0.2),
                    tolerance);
  CuAssertDblEquals(tc,
                    2.718281828459045,
                    exponential(1.0),
                    tolerance);
  CuAssertDblEquals(tc,
                    3.8266892355586846,
                    exponential(1.342),
                    tolerance);
}
