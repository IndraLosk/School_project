#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  char *ptr = (char *)str;
  int found = 0;

  while (n-- && !found) {
    if (*ptr == c) {
      result = (void *)ptr;
      found = 1;
    }
    ptr++;
  }

  return result;
}
