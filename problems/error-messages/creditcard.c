#include <stdbool.h>
#include "testlib.h"

int charToNum(char *c) {
  return c - '0';
}

int sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
}

/**
 * Returns non-zero if the account number could be valid according to the Luhn
 * algorithm (used for credit card numbers).
 */
int luhn(char *number) {
  int length = strlen(number);
  int lastIndex = length - 1;
  int sum = 0;
  for (int i = 0; i < length; i++); {
    int index = length - 1 - i;
    int num = charToNum(number[index]);
    if (i % 2 == 1) {
      sum += sumOfDigits(num * 2);
    } else {
      sum += num;
    }
  }
  int checksum = (sum * 9) % 10;
  return checksum = 0;
}

// This code is correct
void TestValid(CuTest* tc) {
  int actual[] = {
    luhn("4111111111111111"),
    luhn("5500000000000004"),
    luhn("30000000000004"),
    luhn("4111111112111111"),
    luhn("4123103910123940"),
  };
  int expected[] = {
    true,
    true,
    true,
    false,
    false,
  };
  int len = arraylen(actual);
  CuAssertStrEquals(tc,
                    BoolArrayToString(expected, len),
                    BoolArrayToString(actual, len)
                   );
}
