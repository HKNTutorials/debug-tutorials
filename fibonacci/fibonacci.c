#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "test-lib.h"

// define fibonacci number f_0 = 0, f_1 = 1, f_n = f_{n-1} + f_{n-2}

int fibonacciRecursive(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
  if (n <= 1) {
    return n;
  }
  int prev = 0;
  int curr = 1;
  for (int i = 2; i <= n; i++) {
    int old = curr;
    curr = curr + prev;
    prev = old;
  }
  return curr;
}

double phi = 1.618033988749894848204586834;
double negativePhiInverse = -0.6180339887498948482045868345;
double sqrtFive = 2.236067977499789696409173669;

int fibonacciClosedForm(int n) {
  double fn = (pow(phi, n) - pow(negativePhiInverse, n)) / sqrtFive;
  return round(fn);
}

void TestFibonacciRecursive(CuTest *tc) {
  int expected[] = {0, 1, 1, 2, 3, 5};
  int actual[arraylen(expected)];
  int len = arraylen(expected);
  for (int i = 0; i < len; i++) {
    actual[i] = fibonacciRecursive(i);
  }
  CuAssertStrEquals(tc,
                    IntArrayToString(expected, len),
                    IntArrayToString(actual, len));
}

void TestFibonacciIterative(CuTest *tc) {
  int tests[] = {0,1,2,3,4,5,10,40};
  int expected[arraylen(tests)];
  int actual[arraylen(expected)];
  int len = arraylen(tests);
  for (int i = 0; i < len; i++) {
    int num = tests[i];
    expected[i] = fibonacciRecursive(num);
    actual[i] = fibonacciIterative(num);
  }
  CuAssertStrEquals(tc,
                    IntArrayToString(expected, len),
                    IntArrayToString(actual, len));
}

void TestFibonacciClosedForm(CuTest *tc) {
  int tests[] = {0,1,2,3,4,5,10,40};
  int expected[arraylen(tests)];
  int actual[arraylen(expected)];
  int len = arraylen(tests);
  for (int i = 0; i < len; i++) {
    int num = tests[i];
    expected[i] = fibonacciRecursive(num);
    actual[i] = fibonacciClosedForm(num);
  }
  CuAssertStrEquals(tc,
                    IntArrayToString(expected, len),
                    IntArrayToString(actual, len));
}
