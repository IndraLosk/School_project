
#include "s21_string.h"
char *s21_strerror(int errnum) {
  char *result = S21_NULL;

  if (errnum >= 0 && errnum < ERROR_COUNT) {
    const char *errors[] = ERRORS;
    result = (char *)errors[errnum];
  } else {
    const char *unknown_error =
#if defined(__APPLE__)
        "Unknown error: ";
#elif defined(__linux__)
        "Unknown error ";
#else
#error "Unsupported platform"
#endif
    s21_size_t unknown_error_len = s21_strlen(unknown_error);

    int num = errnum, num_len = 1;
    if (num < 0) {
      num_len++;
      num = -num;
    }
    int temp = num;
    while (temp >= 10) {
      num_len++;
      temp /= 10;
    }

    s21_size_t buffer_size = unknown_error_len + num_len + 1;
    result = (char *)malloc(buffer_size);
    if (result != S21_NULL) {
      s21_strcpy(result, unknown_error);
      char *num_str = result + unknown_error_len;
      if (errnum < 0) {
        *num_str = '-';
        num_str++;
        errnum = -errnum;
      }
      char buffer[20];
      int index = 0;
      do {
        buffer[index++] = '0' + (errnum % 10);
        errnum /= 10;
      } while (errnum > 0);

      for (int i = index - 1; i >= 0; --i) {
        *num_str++ = buffer[i];
      }
      *num_str = '\0';
    }
  }
  return result;
}
