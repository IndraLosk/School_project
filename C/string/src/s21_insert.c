#include "s21_string.h"
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;

  if (src != S21_NULL && str != S21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t new_len = src_len + str_len + 1;

    new_str = (char *)malloc(new_len);

    if (new_str) {
      s21_strncpy(new_str, src, start_index);
      s21_strcpy(new_str + start_index, str);
      s21_strcpy(new_str + start_index + str_len, src + start_index);
    }
  }

  return new_str;
}
