
#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "s21_errorlist.h"

#define S21_NULL ((void *)0)
#define s21_size_t unsigned long

typedef struct {
  int flag_hash;
  int flag_width;
  char flag_width_char;
  int flag_width_double;
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_precision;
  int is_flag_precision;
  int lenght_l;
  int lenght_double_l;
  int lenght_h;
} FormatFlags;

typedef struct {
  int minus;
  int plus;
  int width;
  int percision;
  int space;
  int flagSize;
  int l;
  int h;
  int L;
  int tag;
  int zero;
  int isHex;
} flags_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcpy(char *dest, const char *src);

int s21_sscanf(const char *str, const char *format, ...);

char *ftoa(long double num, int percision);
char *s21_intToHexOrOct(long long int num, int flagFont, int flagBase);
char *doubleToExp(long double number, int precision, int flagCase);
char *doubleToFormat(long double number, int precision, int flagCase);
char *s21_itoa(long long int n);
char *s21_utoa(unsigned long long int value);
int callPutsNumFunc(char format, char *str, flags_t flags, va_list *ap);
int checkFormat(char *str, char format, va_list *ap, flags_t flags);
int countNum(char *str);
int numFromFormat(int *changeValue, int *flagSize, char *format);
int numUtil(char *str, char *numStr, flags_t flags, long long int num);
int putZeros(char *str, int percision, char *numStr);
int s21_puthex(char *str, long long int num, int flagCase, flags_t flags,
               int flagBase);
int s21_putchar(char *str, int ap);
int s21_putnbr(char *str, long long int num, flags_t flags);
int s21_putEFG(char *str, long double num, flags_t flags, int flagCase,
               int format);
int s21_putunbr(char *str, unsigned long long int num, flags_t flags);
int s21_putstr(char *str, char *ap, flags_t flags);
int subAtoi(char *str, int count);
int widthFlags(char *str, char *strNum, int countSpace, int *i, int percision);
flags_t parseFlags(char *format, va_list *ap);

#endif
