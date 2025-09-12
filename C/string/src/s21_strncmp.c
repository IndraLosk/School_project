#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  int reached_null = 0;

  while (n > 0 && !reached_null) {
    if (*str1 != *str2) {
      result = (unsigned char)*str1 - (unsigned char)*str2;
      reached_null = 1;
    }
    if (*str1 == '\0') {
      reached_null = 1;
    }
    str1++;
    str2++;
    n--;
  }

  return result;
}
