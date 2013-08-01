#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "testlib.h"

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

// multiply 2x2 matrices
void multiply(int *op1, int *op2, int *result) {
  int a = op1[0];
  int b = op1[1];
  int c = op1[2];
  int d = op1[3];
  
  int e = op2[0];
  int f = op2[1];
  int g = op2[2];
  int h = op2[3];

  result[0] = a*e + b*g;
  result[1] = a*f + b*h;
  result[2] = c*e + d*g;
  result[3] = c*f + d*h;
}

// square a 2x2 matrix
void square(int *op1, int *result) {
  int a = op1[0];
  int b = op1[1];
  int c = op1[2];
  int d = op1[3];

  result[0] = a*a + b*c;
  int trace = a + d;
  result[1] = b * trace;
  result[2] = c * trace;
  result[3] = b*c + d*d;
}

// take a matrix to a power
void powerIterative(int *mat, int n, int *result) {
  if (n == 0) {
    result[0] = result[3] = 1;
    result[1] = result[2] = 0;
    return;
  }

  result[0] = mat[0];
  result[1] = mat[1];
  result[2] = mat[2];
  result[3] = mat[3];

  for (int i = 0; i < n-1; i++) {
    multiply(result, mat, result);
  }
}

// take a matrix to a power
void power(int *mat, int n, int *result) {
  if (n == 0) {
    result[0] = result[3] = 1;
    result[1] = result[2] = 0;
    return;
  }
  if (n == 1) {
    result[0] = mat[0];
    result[1] = mat[1];
    result[2] = mat[2];
    result[3] = mat[3];
    return;
  }
  int halfPower[4];
  power(mat, n / 2, halfPower);
  square(halfPower, result);
  // left out one power
  if (n % 2 == 1) {
    multiply(result, mat, result);
  }
}

int fibonacciExponent(int n) {
  if (n <= 1) {
    return n;
  }
  int kernel[] = {0, 1, 1, 1};
  int matResult[4];
  power(kernel, n-2, matResult);
  return matResult[2] + matResult[3];
}

// helper for matrix tests
#define AssertMatEquals(tc, ep, ac) CuAssertStrEquals(tc, IntArrayToString((ep), 4), IntArrayToString((ac), 4))

void TestMultiply(CuTest *tc) {
  int mat1[4] = {3,1,-4,3};
  int mat2[4] = {1,4,3,2};
  int expectedProduct[4] = {6, 14, 5, -10};
  int result[4];
  multiply(mat1, mat2, result);
  AssertMatEquals(tc, expectedProduct, result);
  //multiply(mat2, mat1, result);
  //AssertMatEquals(tc, expectedProduct, result);
}

void TestPower(CuTest *tc) {
  int mat[4] = {3,-2,4,5};
  int iterative[4];
  int recursive[4];
  // Computed with MATLAB, correct value of mat^3
  int expectedCube[] = {-61, -82, 164, 21};
  for (int i = 0; i < 10; i++) {
    powerIterative(mat, i, iterative);
    power(mat, i, recursive);
    AssertMatEquals(tc, iterative, recursive);
    if (i == 3) {
      AssertMatEquals(tc, expectedCube, iterative);
    }
  }
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
  int tests[] = {0,1,2,3,4,5,10,12};
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
    expected[i] = fibonacciIterative(num);
    actual[i] = fibonacciClosedForm(num);
  }
  CuAssertStrEquals(tc,
                    IntArrayToString(expected, len),
                    IntArrayToString(actual, len));
}

void TestFibonacciExponent(CuTest *tc) {
  int tests[] = {0,1,2,3,4,5,10,40,45};
  int expected[arraylen(tests)];
  int actual[arraylen(expected)];
  int len = arraylen(tests);
  for (int i = 0; i < len; i++) {
    int num = tests[i];
    expected[i] = fibonacciClosedForm(num);
    actual[i] = fibonacciExponent(num);
  }
  CuAssertStrEquals(tc,
                    IntArrayToString(expected, len),
                    IntArrayToString(actual, len));
}
