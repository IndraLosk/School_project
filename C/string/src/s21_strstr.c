#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  const char *hay = haystack;
  const char *need = needle;

  if (*need == '\0') {
    result = (char *)hay;
  } else {
    int found = 0;
    while (*hay != '\0' && !found) {
      const char *h = hay;
      const char *n = need;
      int match = 1;

      while (*h != '\0' && *n != '\0' && match) {
        if (*h != *n) {
          match = 0;
        }
        h++;
        n++;
      }

      if (*n == '\0' && match) {
        result = (char *)hay;
        found = 1;
      }

      hay++;
    }
  }

  return result;
}
