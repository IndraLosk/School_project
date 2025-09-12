#include "s21_string.h"
void *s21_to_upper(const char *str) {
  char *upper_str = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str) + 1;
    upper_str = (char *)malloc(len);

    if (upper_str != S21_NULL) {
      for (s21_size_t i = 0; i < len - 1; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          upper_str[i] = str[i] - 32;
        } else {
          upper_str[i] = str[i];
        }
      }
      upper_str[len - 1] = '\0';
    }
  }

  return upper_str;
}
