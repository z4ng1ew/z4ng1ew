#include "advanced.h"

unsigned long long s21_strtoull(const char *str, char **endptr, int base) {
  const char *i = str;
  unsigned long long accum_res = 0;
  int num_sign = 1;
  while (S21_ISSPACE((unsigned char)*i)) {
    i++;
  }
  if (*i == '-') {
    num_sign = -1;
    i++;
  } else if (*i == '+') {
    i++;
  }
  if (i[0] == '0' && (i[1] == 'x' || i[1] == 'X')) {
    i += 2;
  }
  int is_valid_symbol = 1;

  while (is_valid_symbol != 0) {
    int current_num;

    if (S21_ISDIGIT(*i)) {
      current_num = *i - '0';
    } else if (*i >= 'a' && *i <= 'f') {
      current_num = *i - 'a' + 10;
    } else if (*i >= 'A' && *i <= 'F') {
      current_num = *i - 'A' + 10;
    } else {
      is_valid_symbol = 0;
      continue;
    }
    if (current_num >= base) {
      is_valid_symbol = 0;
      continue;
    }
    accum_res = accum_res * base + current_num;
    i++;
  }
  if (endptr != NULL) {
    *endptr = (char *)i;
  }
  return num_sign * accum_res;
}

long double s21_strtold(const char *nptr, char **endptr) {
  const char *s = nptr;
  long double result = 0.0, factor = 1.0;
  int exponent = 0, sign = 1, exp_sign = 1, seen_digit = 0;
  while (S21_ISSPACE(*s)) s++;
  if (*s == '-') {
    sign = -1;
    s++;
  } else if (*s == '+')
    s++;
  while (S21_ISDIGIT(*s)) {
    result = result * 10.0 + (*s - '0');
    s++;
    seen_digit = 1;
  }
  if (*s == '.') {
    s++;
    long double frac = 0.0, scale = 1.0;
    while (S21_ISDIGIT(*s)) {
      frac = frac * 10.0 + (*s - '0');
      scale *= 10.0;
      s++;
      seen_digit = 1;
    }
    result += frac / scale;
  }
  if (*s == 'e' || *s == 'E') {
    s++;
    if (*s == '-') {
      exp_sign = -1;
      s++;
    } else if (*s == '+')
      s++;
    while (S21_ISDIGIT(*s)) {
      exponent = exponent * 10 + (*s - '0');
      s++;
    }
  }
  if (exp_sign == -1)
    factor = powl(10, -exponent);
  else
    factor = powl(10, exponent);
  result = result * factor * sign;
  if (endptr != s21_NULL) *endptr = (char *)(seen_digit ? s : nptr);
  return result;
}

double s21_strtod(const char *nptr, char **endptr) {
  const char *s = nptr;
  double result = 0.0, factor = 1.0;
  int exponent = 0, sign = 1, exp_sign = 1, seen_digit = 0;
  while (S21_ISSPACE(*s)) s++;
  if (*s == '-') {
    sign = -1;
    s++;
  } else if (*s == '+')
    s++;
  while (S21_ISDIGIT(*s)) {
    result = result * 10.0 + (*s - '0');
    s++;
    seen_digit = 1;
  }
  if (*s == '.') {
    s++;
    double frac = 0.0, scale = 1.0;
    while (S21_ISDIGIT(*s)) {
      frac = frac * 10.0 + (*s - '0');
      scale *= 10.0;
      s++;
      seen_digit = 1;
    }
    result += frac / scale;
  }
  if (*s == 'e' || *s == 'E') {
    s++;
    if (*s == '-') {
      exp_sign = -1;
      s++;
    } else if (*s == '+')
      s++;
    while (S21_ISDIGIT(*s)) {
      exponent = exponent * 10 + (*s - '0');
      s++;
    }
  }
  if (exp_sign == -1)
    factor = pow(10, -exponent);
  else
    factor = pow(10, exponent);

  result = result * factor * sign;

  if (endptr != s21_NULL) *endptr = (char *)(seen_digit ? s : nptr);
  return result;
}

float s21_strtof(const char *nptr, char **endptr) {
  const char *s = nptr;
  float result = 0.0f, factor = 1.0f;
  int exponent = 0, sign = 1, exp_sign = 1, seen_digit = 0;
  while (S21_ISSPACE((unsigned char)*s)) s++;
  if (*s == '-') {
    sign = -1;
    s++;
  } else if (*s == '+')
    s++;
  while (S21_ISDIGIT((unsigned char)*s)) {
    result = result * 10.0f + (*s - '0');
    s++;
    seen_digit = 1;
  }
  if (*s == '.') {
    s++;
    float frac = 0.0f;
    float scale = 1.0f;
    while (S21_ISDIGIT((unsigned char)*s)) {
      frac = frac * 10.0f + (*s - '0');
      scale *= 10.0f;
      s++;
      seen_digit = 1;
    }
    result += frac / scale;
  }
  if (*s == 'e' || *s == 'E' || *s == 'p' || *s == 'P') {
    s++;
    if (*s == '-') {
      exp_sign = -1;
      s++;
    } else if (*s == '+')
      s++;
    while (S21_ISDIGIT((unsigned char)*s)) {
      exponent = exponent * 10 + (*s - '0');
      s++;
    }
  }
  if (exp_sign == -1)
    factor = powf(10, -exponent);
  else
    factor = powf(10, exponent);
  result = result * factor * sign;
  if (endptr != s21_NULL) *endptr = (char *)(seen_digit ? s : nptr);
  return result;
}

static void s21_read_integer(const char **src, int width, int suppress,
                             int base, int length, va_list *args,
                             int *num_converted) {
  unsigned long long tmp = 0;
  int sign = 1, detected_base = base;
  int stop = 0;
  parse_sign_and_base(src, &sign, &detected_base, &width);
  while (!stop &&
         (detected_base == 10
              ? S21_ISDIGIT(**src)
              : (detected_base == 8
                     ? S21_ISDIGIT(**src) && **src < '8'
                     : S21_ISDIGIT(**src) || (**src >= 'a' && **src <= 'f') ||
                           (**src >= 'A' && **src <= 'F'))) &&
         (width-- != 0)) {
    int digit;
    if (S21_ISDIGIT(**src))
      digit = *(*src)++ - '0';
    else if (**src >= 'a' && **src <= 'f')
      digit = *(*src)++ - 'a' + 10;
    else
      digit = *(*src)++ - 'A' + 10;

    if (digit >= detected_base) {
      stop = 1;
    } else {
      tmp = tmp * detected_base + digit;
    }
  }
  tmp *= sign;
  if (!suppress) switch (length) {
      case 'h':
        *va_arg(*args, short *) = (short)tmp;
        break;
      case 'l':
        *va_arg(*args, long *) = (long)tmp;
        break;
      case 'L':
        *va_arg(*args, long long *) = (long long)tmp;
        break;
      default:
        *va_arg(*args, int *) = (int)tmp;
    }
  (*num_converted)++;
}

void parse_sign_and_base(const char **src, int *sign, int *detected_base,
                         int *width) {
  if (**src == '-') {
    *sign = -1;
    (*src)++;
    (*width)--;
  } else if (**src == '+') {
    (*src)++;
    (*width)--;
  }

  if (*detected_base == 0)
    if (**src == '0') {
      if (*(*src + 1) == 'x' || *(*src + 1) == 'X') {
        *detected_base = 16;
        *src += 2;
        *width -= 2;
      } else {
        *detected_base = 8;
        (*src)++;
        (*width)--;
      }
    } else
      *detected_base = 10;
  else if (*detected_base == 16 && **src == '0' &&
           (*(*src + 1) == 'x' || *(*src + 1) == 'X')) {
    *src += 2;
    *width -= 2;
  }
}

static void s21_read_float(const char **src, int width, int suppress,
                           int length, va_list *args, int *num_converted) {
  char buffer[256] = {0};
  char *buf_ptr = buffer;

  while ((width-- != 0) && (buf_ptr < buffer + 255) &&
         (**src == '.' || **src == '-' || **src == '+' ||
          S21_ISDIGIT((unsigned char)**src) || **src == 'e' || **src == 'E')) {
    *buf_ptr++ = *(*src)++;
  }
  *buf_ptr = '\0';

  if (!suppress) {
    if (length == 'L') {
      *va_arg(*args, long double *) = s21_strtold(buffer, s21_NULL);
    } else if (length == 'l') {
      *va_arg(*args, double *) = s21_strtod(buffer, s21_NULL);
    } else {
      *va_arg(*args, float *) = s21_strtof(buffer, s21_NULL);
    }
    (*num_converted)++;
  }
}

static void s21_process_specifier(char specifier, const char **src,
                                  const char *start, int width, int suppress,
                                  int length, va_list *args,
                                  int *num_converted) {
  while (S21_ISSPACE((unsigned char)**src)) (*src)++;
  if (specifier == 'c') {
    if (!suppress) {
      *va_arg(*args, char *) = *(*src)++;
      (*num_converted)++;
    } else {
      (*src)++;
    }
  } else if (specifier == 'd' || specifier == 'i') {
    s21_read_integer(src, width, suppress, 0, length, args, num_converted);
  } else if (specifier == 'u') {
    s21_read_integer(src, width, suppress, 10, length, args, num_converted);
  } else if (specifier == 'x' || specifier == 'X') {
    s21_read_integer(src, width, suppress, 16, length, args, num_converted);
  } else if (specifier == 'o') {
    s21_read_integer(src, width, suppress, 8, length, args, num_converted);
  } else if (specifier == 'f' || specifier == 'g' || specifier == 'G' ||
             specifier == 'e' || specifier == 'E') {
    s21_read_float(src, width, suppress, length, args, num_converted);
  } else if (specifier == 's') {
    char *ptr = suppress ? s21_NULL : va_arg(*args, char *);
    while (**src && !S21_ISSPACE((unsigned char)**src) && (width-- != 0)) {
      if (!suppress) {
        *ptr++ = *(*src)++;
      } else {
        (*src)++;
      }
    }
    if (!suppress) {
      *ptr = '\0';
      (*num_converted)++;
    }
  } else if (specifier == 'p') {
    if (!suppress) {
      *va_arg(*args, void **) = (void *)s21_strtoull(*src, (char **)src, 16);
      (*num_converted)++;
    }
  } else if (specifier == '%') {
    if (**src == '%') {
      (*src)++;
    }
  } else if (specifier == 'n') {
    if (!suppress) {
      *va_arg(*args, int *) = *src - start;
    }
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *p = format;
  const char *s = str;
  int num_converted = 0;
  const char *start = str;
  int mismatch = 0;
  while (*p && *s && !mismatch) {
    if (*p == '%') {
      p++;
      int suppress = 0;
      int width = -1;
      char length = 0;
      char specifier = 0;
      if (*p == '*') {
        suppress = 1;
        p++;
      }
      if (S21_ISDIGIT((unsigned char)*p)) {
        width = 0;
        while (S21_ISDIGIT((unsigned char)*p)) {
          width = width * 10 + (*p - '0');
          p++;
        }
      }
      if (*p == 'h' || *p == 'l' || *p == 'L') {
        length = *p;
        p++;
      }
      specifier = *p++;
      s21_process_specifier(specifier, &s, start, width, suppress, length,
                            &args, &num_converted);
    } else {
      if (*p == *s) {
        p++;
        s++;
      } else {
        mismatch = 1;
      }
    }
  }
  va_end(args);
  return num_converted;
}
