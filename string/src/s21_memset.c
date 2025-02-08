#include "s21_string.h"
void *s21_memset(void *str, int c, s21_size_t n) {
  char *result = str;
  for (s21_size_t i = 0; i < n; i++) {
    result[i] = c;
  }

  return result;
}