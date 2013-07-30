#include <stdlib.h>
#include "testlib.h"

float sumRange(float start, float end, float increment) {
  float sum = 0.0;
  for (float f = start; f < end; f += increment) {
    sum += f;
  }
  return sum;
}

void TestSumRangeIntegers(CuTest *tc) {
  float tolerance = 0.00001;
  CuAssertDblEquals(tc, 101*50.0, sumRange(1.0, 101.0, 1.0),
                    tolerance);
}

void TestSumRange(CuTest *tc) {
  float tolerance = 0.000001;
  CuAssertDblEquals(tc, 4.5, sumRange(0, 1, 0.1),
                    tolerance);
}
