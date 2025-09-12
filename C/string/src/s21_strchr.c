#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

char *s21_strchr(const char *str, int c) {
  char *result = NULL;
  while (*str && result == NULL) {
    if (*str == (char)c) {
      result = (char *)str;
    }
    str++;
  }
  if (c == '\0') {
    result = (char *)str;
  }
  return result;
}