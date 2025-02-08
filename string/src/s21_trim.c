#include "s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = NULL;

  if (src != NULL) {
    size_t start = 0;
    size_t end = s21_strlen(src);

    if (trim_chars != NULL) {
      while (start < end && s21_strchr(trim_chars, src[start]) != NULL) {
        start++;
      }
      while (end > start && s21_strchr(trim_chars, src[end - 1]) != NULL) {
        end--;
      }
    }

    size_t new_len = end - start;
    new_str = (char *)malloc(new_len + 1);
    if (new_str != NULL) {
      s21_strncpy(new_str, src + start, new_len);
      new_str[new_len] = '\0';
    }
  }

  return new_str;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;

  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }

  dest[i] = '\0';

  return dest;
}
