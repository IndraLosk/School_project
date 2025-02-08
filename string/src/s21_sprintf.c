
#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...);

void s21_reverse_str(char num_str[]) {
  int len = s21_strlen(num_str);
  for (int i = 0; i < len / 2; i++) {
    char temp = num_str[i];
    num_str[i] = num_str[len - i - 1];
    num_str[len - i - 1] = temp;
  }
}

void s21_int_to_str(long long int num, char *str) {
  int i = 0;
  if (num == 0) {
    str[i++] = '0';
  } else {
    int is_negative = 0;
    if (num < 0) {
      is_negative = 1;
      num = -num;
    }
    while (num != 0) {
      int rem = num % 10;
      str[i++] = rem + '0';
      num = num / 10;
    }
    if (is_negative) str[i++] = '-';
  }
  str[i] = '\0';
  s21_reverse_str(str);
}

double s21_round(double num, int signs) {
  double res = roundl(num * powl(10.0L, signs)) / powl(10.0L, signs);
  double res_floor = floor(num * powl(10.0L, signs)) / powl(10.0L, signs);
  if (res == floor(res)) {
    if (!(fmod(res, 2.0) == 0.0)) res = res_floor;
  }
  return res;
}

void s21_double_to_str(double num, char *str, int signs) {
  int is_negative = 0;
  long double mantis, right = 0.0L, pow = 1.0L, pow_t = 1.0L;
  char num1_str[500] = "", *p1 = num1_str;
  char num2_str[500] = "", *p2 = num2_str;
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }
  num = s21_round(num, signs);
  mantis = modfl(fabsl(num), &right);
  while (truncl(right / pow) > 0) {
    int digit;
    digit = (int)truncl(fmodl(truncl(right), pow * 10.0L) / pow);
    *(p1++) = (char)(digit + '0');
    pow *= 10.0L;
  }
  if (is_negative) *(p1++) = '-';
  *p1 = '\0';
  for (int i = 0; i < signs; i++) pow_t *= 10;
  mantis = roundl(mantis * pow_t);
  pow = 1.0L;
  while (pow < pow_t) {
    int digit;
    digit = (int)truncl(fmodl(truncl(mantis), pow * 10.0L) / pow);
    *(p2++) = (char)(digit + '0');
    pow *= 10.0L;
  }
  *p2 = '\0';
  s21_reverse_str(num1_str);
  if (s21_strlen(num1_str) == 0) s21_strncat(str, "0", 1);
  s21_strncat(str, num1_str, s21_strlen(num1_str));
  if (signs > 0) {
    s21_strncat(str, ".", 1);
    s21_reverse_str(num2_str);
    s21_strncat(str, num2_str, s21_strlen(num2_str));
  }
}

void s21_double_to_str_e(double num, char *str, int signs, int flag_hash,
                         char flag_e) {
  int exponent = 0;
  double mantissa = 0;
  if (num != 0.0) {
    exponent = (int)log10(fabs(num));
    mantissa = num / pow(10, exponent);
  }
  if (fabsl(mantissa) < 1 && exponent != 0) {
    s21_double_to_str(mantissa * 10, str, signs);
    exponent--;
  } else
    s21_double_to_str(mantissa, str, signs);
  char *add_exponent = str + s21_strlen(str);
  if (flag_hash && signs == 0) {
    *add_exponent = '.';
    add_exponent++;
  }
  if (flag_e == 'E')
    *add_exponent = 'E';
  else
    *add_exponent = 'e';
  add_exponent++;
  if (exponent < 0) {
    *add_exponent = '-';
    exponent *= -1;
  } else
    *add_exponent = '+';
  add_exponent++;
  if (exponent < 10) {
    *add_exponent = '0';
    add_exponent++;
    *add_exponent = exponent + '0';
  } else
    s21_int_to_str(exponent, add_exponent);
}

char *s21_delete_zero(char buffer[], int flag_total) {
  s21_reverse_str(buffer);
  char *buf_ptr = buffer;
  int count = 0;
  while (*buf_ptr == '0') {
    count++;
    buf_ptr++;
  }
  s21_reverse_str(buffer);
  if (count != 0 && !flag_total) {
    int len = s21_strlen(buffer) - count;
    char buffer_res[len + 1];
    s21_strncpy(buffer_res, buffer, len);
    buffer_res[len] = '\0';
    s21_strncpy(buffer, buffer_res, len);
    buffer[len] = '\0';
  }
  return buffer;
}

int s21_flag_width_char(const char **format) {
  (*format)++;
  return '0';
}

int s21_flag_width(const char **format) {
  int width = 0;
  while (**format >= '0' && **format <= '9') {
    width = width * 10 + (**format - '0');
    (*format)++;
  }
  return width;
}

void s21_flag_width_do(int width, char num_str[], int flag_minus,
                       int flag_width_char) {
  int len = s21_strlen(num_str);
  int total_len = len + width;
  if (flag_minus) {
    for (int i = 0; i < width; i++) {
      num_str[len + i] = flag_width_char;
    }
    num_str[total_len] = '\0';
  } else {
    for (int i = total_len; i >= width; i--) {
      num_str[i] = num_str[i - width];
    }
    for (int i = 0; i < width; i++) {
      num_str[i] = flag_width_char;
    }
  }
}

int s21_flag(const char **format) {
  (*format)++;
  return 1;
}

void s21_flag_space_plus(FormatFlags *flags) {
  if (flags->flag_space) flags->flag_space = 0;
  flags->flag_plus = 2;
}

int s21_flag_precision(const char **format, int *flag_width_double) {
  (*format)++;
  int width = s21_flag_width(format);
  if (width <= 0) *flag_width_double = 1;
  return width;
}

void s21_flag_precision_do(int precision, char num_str[], int *len) {
  for (int i = 0; i < precision; i++) num_str[*len + i] = '0';
  num_str[*len + precision] = '\0';
  s21_reverse_str(num_str);
  *len = s21_strlen(num_str);
}

void s21_flag_arg_width(const char **format, va_list args, int *flag_width) {
  (*format)++;
  int arg = va_arg(args, int);
  *flag_width = arg;
}

void s21_flags_do_paste_str(char **str, const char num_str[], int len) {
  s21_strncpy(*str, num_str, len);
  *str += len;
}

void s21_flag_plus_do(int flag_plus, char num_str[], int *len) {
  if (flag_plus == 1) {
    for (int i = *len; i > 0; i--) {
      num_str[i] = num_str[i - 1];
    }
    num_str[0] = '+';
  } else {
    for (int i = *len; i > 0; i--) {
      num_str[i] = num_str[i - 1];
    }
    num_str[0] = '-';
  }
  num_str[*len + 1] = '\0';
  *len = s21_strlen(num_str);
}

void s21_flags_do(int flag_hash, int flag_width, int flag_width_char,
                  int flag_precision, int flag_minus, int flag_plus,
                  int flag_space, char num_str[], char **str) {
  int len = s21_strlen(num_str);
  if (flag_precision && flag_precision > len) {
    s21_flag_precision_do(flag_precision - len, num_str, &len);
  }
  if (flag_plus && flag_minus) {
    s21_flag_plus_do(flag_plus, num_str, &len);
  }
  if (flag_width && flag_width > len && flag_width > flag_precision) {
    if (flag_plus && flag_width_char == '0') flag_width--;
    if (flag_space) flag_width--;
    if (!flag_minus) {
      if (flag_plus && flag_width_char == ' ') {
        s21_flag_plus_do(flag_plus, num_str, &len);
      }
      s21_flag_width_do(flag_width - len, num_str, flag_minus, flag_width_char);
      len = s21_strlen(num_str);
      if (flag_plus && flag_width_char == '0') {
        s21_flag_plus_do(flag_plus, num_str, &len);
      }
    }
    if (flag_minus) {
      s21_flag_width_do(flag_width - len, num_str, flag_minus, flag_width_char);
      len = s21_strlen(num_str);
    }
  } else if (flag_plus && !flag_minus) {
    s21_flag_plus_do(flag_plus, num_str, &len);
  }
  if (flag_space && !flag_plus) {
    s21_reverse_str(num_str);
    num_str[len] = ' ';
    len++;
    num_str[len] = '\0';
    s21_reverse_str(num_str);
  }
  s21_flags_do_paste_str(str, num_str, len);
  if (flag_hash == 4) {
    **str = '.';
    (*str)++;
  }
}

int s21_zero_e(char buffer[], int exponent) {
  char exponennt_str[20];
  s21_int_to_str(exponent, exponennt_str);
  int i = s21_strlen(exponennt_str) + 2;
  s21_reverse_str(buffer);
  while (buffer[i] == '0') i++;
  return i - (s21_strlen(exponennt_str) + 2);
}

long double s21_arg_double(va_list args, FormatFlags flags) {
  long double arg;
  if (flags.lenght_double_l)
    arg = va_arg(args, long double);
  else
    arg = (double)va_arg(args, double);
  return arg;
}

void s21_specificator_d(char **str, va_list args, FormatFlags flags) {
  long int arg;
  if (flags.lenght_l)
    arg = va_arg(args, long int);
  else if (flags.lenght_h)
    arg = (short int)va_arg(args, int);
  else
    arg = (int)va_arg(args, int);
  char num_str[20] = "";
  if (arg < 0) {
    s21_flag_space_plus(&flags);
    arg *= -1;
  }
  s21_int_to_str(arg, num_str);
  if (flags.flag_width_double && flags.flag_precision == 0 && arg == 0) {
    num_str[0] = '\0';
  }
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, flags.flag_precision,
               flags.flag_minus, flags.flag_plus, flags.flag_space, num_str,
               str);
}

void s21_specificator_u(char **str, va_list args, FormatFlags flags) {
  unsigned long int arg;
  if (flags.lenght_l)
    arg = va_arg(args, unsigned long int);
  else if (flags.lenght_h)
    arg = (unsigned short int)va_arg(args, int);
  else
    arg = (unsigned int)va_arg(args, unsigned int);
  char num_str[20];
  s21_int_to_str(arg, num_str);
  if (flags.flag_width_double && flags.flag_precision == 0 && arg == 0) {
    num_str[0] = '\0';
  }
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, flags.flag_precision,
               flags.flag_minus, 0, 0, num_str, str);
}

void s21_specificator_c(char **str, va_list args, FormatFlags flags) {
  char arg = (char)va_arg(args, int);
  int len = 1;
  char num_str[len + 1];
  num_str[0] = arg;
  num_str[1] = '\0';
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, 0, flags.flag_minus,
               0, 0, num_str, str);
}

void s21_specificator_f(char **str, va_list args, FormatFlags flags,
                        int signs) {
  long double arg = s21_arg_double(args, flags);
  char num_str[500] = "";
  if (arg < 0) {
    s21_flag_space_plus(&flags);
    arg *= -1;
  }
  if (flags.flag_precision)
    signs = flags.flag_precision;
  else if (flags.flag_width_double)
    signs = 0;
  if (flags.flag_hash && signs == 0)
    flags.flag_hash = 4;
  else if (flags.flag_hash)
    flags.flag_hash = 0;
  s21_double_to_str(arg, num_str, signs);
  s21_flags_do(flags.flag_hash, flags.flag_width, flags.flag_width_char, 0,
               flags.flag_minus, flags.flag_plus, flags.flag_space, num_str,
               str);
}

void s21_specificator_s(char **str, va_list args, FormatFlags flags) {
  const char *arg = va_arg(args, char *);
  int len = s21_strlen(arg);
  if (flags.flag_precision && flags.flag_precision < len) {
    len = flags.flag_precision;
  }
  char num_str[len + 1];
  s21_strncpy(num_str, arg, len);
  num_str[len] = '\0';
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, 0, flags.flag_minus,
               0, 0, num_str, str);
}

void s21_specificator_ls(char **str, va_list args, FormatFlags flags) {
  wchar_t *arg = va_arg(args, wchar_t *);
  int len = 0;
  while (arg[len] != L'\0') {
    len++;
  }
  if (flags.flag_precision && flags.flag_precision < len) {
    len = flags.flag_precision;
  }
  char num_str[len * 256 + 1];
  int i = 0;
  while (i < len && arg[i] != L'\0') {
    num_str[i] = (char)arg[i];
    i++;
  }
  num_str[i] = '\0';
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, 0, flags.flag_minus,
               0, 0, num_str, str);
}

void s21_specificator_percent(char **str) {
  **str = '%';
  (*str)++;
}

void s21_specificator_e(char **str, va_list args, FormatFlags flags, int signs,
                        char flag_e) {
  long double arg = s21_arg_double(args, flags);
  unsigned long long arg_bits;
  double arg_noll = arg;
  s21_memcpy(&arg_bits, &arg_noll, sizeof(arg_bits));
  if (arg_noll < 0.0 || (arg_noll == 0.0 && (arg_bits >> 63) == 1)) {
    s21_flag_space_plus(&flags);
    arg *= -1;
  }
  char num_str[500] = "";
  if (flags.flag_precision)
    signs = flags.flag_precision;
  else if (flags.flag_width_double)
    signs = 0;
  if (flags.flag_hash && signs == 0)
    flags.flag_hash = 4;
  else if (flags.flag_hash)
    flags.flag_hash = 0;
  s21_double_to_str_e(arg, num_str, signs, flags.flag_hash, flag_e);
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, 0, flags.flag_minus,
               flags.flag_plus, flags.flag_space, num_str, str);
}

void s21_specificator_g(char **str, va_list args, FormatFlags flags, int signs,
                        char flag_g) {
  long double arg = s21_arg_double(args, flags);
  char buffer[256];
  int flag_total = 0, exponent = (int)log10(fabsl(arg));
  if (arg < 0) {
    s21_flag_space_plus(&flags);
    arg *= -1;
  }
  if (!flags.flag_precision) {
    flags.flag_precision = 6;
    signs = 6;
  }
  if (flags.flag_precision) signs = flags.flag_precision;
  if (flags.flag_width_double && !flags.is_flag_precision) {
    flags.flag_precision = 0;
    signs = 0;
  }
  if (arg != 0.0 && (exponent <= -4 || exponent > flags.flag_precision ||
                     exponent == flags.flag_precision)) {
    if (signs != 0) signs--;
    const char *format = "%.*Le";
    if (flag_g == 'g')
      format = flags.flag_hash ? "%#.*Le" : "%.*Le";
    else if (flag_g == 'G')
      format = flags.flag_hash ? "%#.*LE" : "%.*LE";
    s21_sprintf(buffer, format, signs, arg);
    signs -= s21_zero_e(buffer, exponent);
    s21_sprintf(buffer, format, signs, arg);
  } else {
    if (!flag_total) {
      char arg_str[20];
      s21_int_to_str((int)arg, arg_str);
      signs = flags.flag_precision - s21_strlen(arg_str);
      if (arg < 0) signs++;
    }
    if (arg - (int)arg == 0 && !flags.flag_hash) {
      signs = 0;
      flag_total = 1;
    }
    s21_sprintf(buffer, "%.*Lf", signs, arg);
  }
  if (!flags.flag_hash) {
    const char *buffer_zero = s21_delete_zero(buffer, flag_total);
    s21_strncpy(buffer, buffer_zero, s21_strlen(buffer_zero));
  }
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, 0, flags.flag_minus,
               flags.flag_plus, flags.flag_space, buffer, str);
}

void s21_specificator_x(char **str, va_list args, FormatFlags flags,
                        char flag_base) {
  unsigned long int arg;
  if (flags.lenght_l)
    arg = va_arg(args, unsigned long int);
  else if (flags.lenght_h)
    arg = (unsigned short int)va_arg(args, int);
  else
    arg = (unsigned int)va_arg(args, unsigned int);
  char chars[17] = "", num_str[20] = "";
  int base = 0, index = 0;
  if (flag_base == 'x') {
    base = 16;
    s21_strncpy(chars, "0123456789abcdef", 16);
  } else if (flag_base == 'X') {
    base = 16;
    s21_strncpy(chars, "0123456789ABCDEF", 16);
  } else {
    base = 8;
    s21_strncpy(chars, "012345678", 8);
  }
  if (arg == 0 && !flags.flag_width_double) {
    num_str[index++] = '0';
    flags.flag_hash = 0;
  }
  if (flags.flag_hash) {
    **str = '0';
    (*str)++;
    if (flag_base == 'x') **str = 'x';
    if (flag_base == 'X') **str = 'X';
    if (flag_base != 'o') (*str)++;
  }
  while (arg != 0) {
    int arg_char = arg % base;
    num_str[index++] = chars[arg_char];
    arg /= base;
  }
  s21_reverse_str(num_str);
  s21_flags_do(flags.flag_hash, flags.flag_width, flags.flag_width_char,
               flags.flag_precision, flags.flag_minus, 0, flags.flag_space,
               num_str, str);
}

void s21_specificator_p(char **str, va_list args, FormatFlags flags) {
  void *arg = va_arg(args, void *);
  char num_str[256];

  s21_sprintf(num_str, "%#.*lx", flags.flag_precision, (unsigned long)arg);
  s21_flags_do(0, flags.flag_width, flags.flag_width_char, 0, flags.flag_minus,
               flags.flag_plus, flags.flag_space, num_str, str);
}

void s21_init_format_flags(FormatFlags *flags) {
  flags->flag_hash = 0;
  flags->flag_width = 0;
  flags->flag_width_char = ' ';
  flags->flag_width_double = 0;
  flags->flag_minus = 0;
  flags->flag_plus = 0;
  flags->flag_space = 0;
  flags->flag_precision = 0;
  flags->is_flag_precision = 0;
  flags->lenght_l = 0;
  flags->lenght_double_l = 0;
  flags->lenght_h = 0;
}

void process_format(const char **format, va_list args, FormatFlags *flags,
                    char **str) {
  while (**format == '-' || **format == '+' || **format == '#' ||
         **format == ' ' || **format == '0') {
    if (**format == '-') flags->flag_minus = s21_flag(format);
    if (**format == '+') flags->flag_plus = s21_flag(format);
    if (**format == '#') flags->flag_hash = s21_flag(format);
    if (**format == ' ') flags->flag_space = s21_flag(format);
    if (**format == '0') flags->flag_width_char = s21_flag_width_char(format);
  }
  if (**format >= '0' && **format <= '9')
    flags->flag_width = s21_flag_width(format);
  if (**format == '*') s21_flag_arg_width(format, args, &flags->flag_width);
  if (**format == '.')
    flags->flag_precision =
        s21_flag_precision(format, &flags->flag_width_double);
  if (**format == '*') {
    s21_flag_arg_width(format, args, &flags->flag_precision);
    flags->is_flag_precision = 1;
  }

  while (**format == 'l' || **format == 'h' || **format == 'L') {
    if (**format == 'l') flags->lenght_l = s21_flag(format);
    if (**format == 'h') flags->lenght_h = s21_flag(format);
    if (**format == 'L') flags->lenght_double_l = s21_flag(format);
  }

  if (**format == 'd') s21_specificator_d(str, args, *flags);
  if (**format == 'c') s21_specificator_c(str, args, *flags);
  if (**format == 'f') s21_specificator_f(str, args, *flags, 6);
  if (**format == 's' && !flags->lenght_l)
    s21_specificator_s(str, args, *flags);
  if (**format == 's' && flags->lenght_l)
    s21_specificator_ls(str, args, *flags);
  if (**format == 'u') s21_specificator_u(str, args, *flags);
  if (**format == '%') s21_specificator_percent(str);
  if (**format == 'g' || **format == 'G')
    s21_specificator_g(str, args, *flags, 6, **format);
  if (**format == 'e' || **format == 'E')
    s21_specificator_e(str, args, *flags, 6, **format);
  if (**format == 'x' || **format == 'X' || **format == 'o')
    s21_specificator_x(str, args, *flags, **format);
  if (**format == 'p') s21_specificator_p(str, args, *flags);
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  FormatFlags flags;
  s21_init_format_flags(&flags);
  const char *ptr = str;
  while (*format != '\0') {
    if (*format != '%') {
      *str = *format;
      str++;
    } else {
      format++;
      process_format(&format, args, &flags, &str);
      s21_init_format_flags(&flags);
    }
    format++;
  }
  *str = '\0';
  va_end(args);
  return str - ptr;
}
