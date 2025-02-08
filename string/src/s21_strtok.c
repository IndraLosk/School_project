
#include "s21_string.h"
char *s21_strtok(char *str, const char *delim) {
  static char *saveptr = S21_NULL;
  char *token = S21_NULL;

  if (str != S21_NULL) {
    saveptr = str;
  }

  if (saveptr == S21_NULL) {
    token = S21_NULL;
  } else {
    while (*saveptr && s21_strchr(delim, *saveptr)) {
      saveptr++;
    }

    if (*saveptr == '\0') {
      saveptr = S21_NULL;
      token = S21_NULL;
    } else {
      token = saveptr;

      while (*saveptr && !strchr(delim, *saveptr)) {
        saveptr++;
      }

      if (*saveptr) {
        *saveptr = '\0';
        saveptr++;
      } else {
        saveptr = S21_NULL;
      }
    }
  }
  return token;
}
