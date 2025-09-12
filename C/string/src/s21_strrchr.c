#include "s21_string.h"
char *s21_strrchr(const char *str, int c) {
  const char *result = S21_NULL;
  const char *ptr = str;

  while (*ptr != '\0') {
    ptr++;
  }

  while (ptr != str && result == S21_NULL) {
    if (*ptr == c) {
      result = ptr;
    }
    ptr--;
  }

  return (char *)result;
}