#include <stdlib.h>
#include <stdio.h>

char* IntArrayToString(int *array, int len) {
  char *regularFormat = "%d, ";
  char *lastFormat = "%d";
  char *buf = malloc(1024);
  int pos = 0;
  for (int i = 0; i < len; i++) {
    char *format;
    if (i == len - 1) {
      format = lastFormat;
    } else {
      format = regularFormat;
    }
    pos += sprintf(buf + pos, format, array[i]);
  }
  return buf;
}

char* BoolArrayToString(int *array, int len) {
  char *buf = malloc(len);
  int pos = 0;
  for (int i = 0; i < len; i++) {
    pos += sprintf(buf + pos, "%s", array[i] ? "T" : "F");
  }
  return buf;
}
