#ifndef ADVANCED_H
#define ADVANCED_H

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>

#include "../s21_string.h"

#define MAX_ARRAY_COUNT 4096

#define MD_10 20
#define MD_16 16
#define MD_8 23

typedef struct {
  int minus;
  int plus;
  int probel;
  int reshetka;
  int zero;
  int shirina;
  int vkl_tochnost;
  int tochnost;
  char dlina;
  char specifikator;
} flags;

#define S21_ISDIGIT(x) ((x) >= '0' && (x) <= '9')
#define S21_ISSPACE(c)                                                       \
  ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r' || (c) == '\f' || \
   (c) == '\v')
#define S21_ISXDIGIT(c) \
  (S21_ISDIGIT(c) || ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))

void parse_sign_and_base(const char **src, int *sign, int *detected_base,
                         int *width);

void int_to_str(int num, char *result);
int scientific_notaion(long double *num);
void add_zero(char *buf, int e);
void ptr_to_str(unsigned long int *ptr, char str[]);
unsigned long int str_to_ptr(char **str, int *err);
int s21_atoi(const char *str);
int s21_isdigit(int c, int base);
void get_format_length(long long *arg, va_list args, char dlina);
void get_format_length_unsign(long long *arg, va_list args, char dlina);
const char *find_flags(const char *format, flags *full_flags);
const char *find_shirina(const char *format, flags *full_flags, va_list args);
const char *find_tochnost(const char *format, flags *full_flags, va_list args);
const char *find_dlina(const char *format, flags *full_flags);
const char *get_full_flags(const char *format, flags *full_flags, va_list args);
void transform_char(const flags full_flags, char *buffer, va_list args);
void transform_int(const flags full_flags, char *buffer, va_list args);
void transform_string(const flags full_flags, char *buffer, va_list args);
void transform_unsign(const flags full_flags, char *buffer, va_list args);
void print_feEgG(va_list args, char *buf, const flags full_flags);
void format_tochnost(const flags full_flags, char *buffer,
                     const int flg_negative);
void format_flags(const flags full_flags, char *buffer);
void format_shirina(const flags full_flags, char *buffer);
void read_text_with_flags(const flags full_flags, char **str, va_list args,
                          int *counter, char *p_start_str);
void write_text_with_flags(const flags full_flags, char *buffer, va_list args,
                           char *str, char *counter);
void double_to_str(long double num, char *str, int simple_notation,
                   const flags full_flags);
#endif
