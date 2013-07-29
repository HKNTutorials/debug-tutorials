#include <stdlib.h>
#include <stdio.h>
#include "CuTest.h"

#define SIZE (50)

int global_array[SIZE];
int* getArray() {
  return global_array;
}

// Fill array with the values startNum ... startNum + len - 1. Array should be
// of size at least len, of which the first len elements are filled.
void fillArray(int *array, int startNum, int len) {
  for (int i = 0; i < len; i++) {
    array[i] = startNum + i;
  }
}

// Square each element of array assuming it is of size len
void squareArray(int *array, int len) {
  for (int i = 0; i < len; i++) {
    array[i] = array[0]*array[i];
  }
}

// This test case passes, indicating startNum is being treated incorrectly
void TestFillArrayFromZero(CuTest *tc) {
  int *array = getArray();
  fillArray(array, 0, SIZE);
  CuAssertIntEquals(tc, 0, array[0]);
  CuAssertIntEquals(tc, 3, array[3]);
  CuAssertIntEquals(tc, SIZE - 1, array[SIZE - 1]);
}

// Before fixing the bug in fillArray, if you disabled TestSquareArray (to
// avoid the segfault) you would find this test doesn't segfault but fails.
void TestFillArrayFromSmallValue(CuTest *tc) {
  int *array = getArray();
  fillArray(array, 10, SIZE);
  CuAssertIntEquals(tc, 10, array[0]);
  CuAssertIntEquals(tc, 10 + SIZE - 1, array[SIZE - 1]);
}

// It's a good idea to try special values like 0
void TestSquareArrayFromZero(CuTest *tc) {
  int *array = getArray();
  fillArray(array, 0, SIZE);
  squareArray(array, SIZE);
  CuAssertIntEquals(tc, 0, array[0]);
  CuAssertIntEquals(tc, 10*10, array[10]);
  CuAssertIntEquals(tc, (SIZE-1)*(SIZE-1), array[SIZE - 1]);
}

void TestSquareArray(CuTest *tc) {
  int *array = getArray();
  fillArray(array, 1000, SIZE);
  squareArray(array, SIZE);
  // These assertions have correct expected values
  CuAssertIntEquals(tc, 1000*1000, array[0]);
  CuAssertIntEquals(tc, 1026*1026, array[26]);
  CuAssertIntEquals(tc, 1049 * 1049, array[49]);
}
