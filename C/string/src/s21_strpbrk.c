#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *res = S21_NULL;
  int found = 0;

  while (*str1 != '\0' && !found) {
    const char *ptr = str2;
    while (*ptr != '\0' && !found) {
      if (*str1 == *ptr) {
        res = str1;
        found = 1;
      }
      ptr++;
    }
    str1++;
  }

  return (char *)res;
}
