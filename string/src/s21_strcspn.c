#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  int found = 0;

  while (*str1 != '\0' && !found) {
    const char *ptr = str2;
    int match = 0;
    while (*ptr != '\0' && !match) {
      if (*str1 == *ptr) {
        match = 1;
      }
      ptr++;
    }
    if (!match) {
      length++;
    } else {
      found = 1;
    }
    str1++;
  }

  return length;
}
