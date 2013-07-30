#include <stdlib.h>
#include <stdio.h>
#include "testlib.h"

#define SIZE (50)

int global_array[SIZE];
int* getArray() {
  // TODO: implement this function
  return NULL;
}

// Fill array with the values startNum ... startNum + len - 1. Array should be
// of size at least len, of which the first len elements are filled.
void fillArray(int *array, int startNum, int len) {
  for (int i = 0; i < len; i++) {
    array[startNum + i] = i;
  }
}

// Square each element of array assuming it is of size len
void squareArray(int *array, int len) {
  for (int i = 0; i < len; i++) {
    array[i] = array[0]*array[i];
  }
}

void TestSquareArray(CuTest *tc) {
  int *array = getArray();
  fillArray(array, 1000, SIZE);
  squareArray(array, SIZE);
  // These assertions have correct expected values
  CuAssertIntEquals(tc, 1000*1000, array[0]);
  CuAssertIntEquals(tc, 1026*1026, array[26]);
  CuAssertIntEquals(tc, 1049*1049, array[49]);
}
