#include "advanced.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *counter = str;
  while (*format != '\0') {
    flags full_flags = {0};
    full_flags.tochnost = -1;
    if (*format != '%') {
      *str++ = *format++;
    } else {
      format = get_full_flags(format, &full_flags, args);
      char buffer[MAX_ARRAY_COUNT] = {'\0'};
      write_text_with_flags(full_flags, buffer, args, str, counter);
      for (int i = 0; buffer[i]; i++, str++) *str = buffer[i];
    }
  }
  *str = '\0';
  va_end(args);
  return str - counter;
}

const char *get_full_flags(const char *format, flags *full_flags,
                           va_list args) {
  format++;
  format = find_flags(format, full_flags);
  format = find_shirina(format, full_flags, args);
  format = find_tochnost(format, full_flags, args);
  format = find_dlina(format, full_flags);
  full_flags->specifikator = *format;
  format++;

  return format;
}

const char *find_flags(const char *format, flags *full_flags) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    switch (*format) {
      case '-':
        full_flags->minus = 1;
        break;
      case '+':
        full_flags->plus = 1;
        break;
      case ' ':
        full_flags->probel = 1;
        break;
      case '#':
        full_flags->reshetka = 1;
        break;
      case '0':
        full_flags->zero = 1;
        break;
    }
    format++;
  }
  return format;
}

const char *find_shirina(const char *format, flags *full_flags, va_list args) {
  if (*format == '*') {
    format++;
    full_flags->shirina = va_arg(args, int);
  } else if (s21_isdigit(*format, 10)) {
    char buffer[MAX_ARRAY_COUNT] = {'\0'};
    for (int i = 0; s21_isdigit(*format, 10); i++, format++)
      buffer[i] = *format;
    full_flags->shirina = s21_atoi(buffer);
  }
  return format;
}

const char *find_tochnost(const char *format, flags *full_flags, va_list args) {
  if (*format == '.') {
    format++;
    if (*format == '*') {
      format++;
      full_flags->tochnost = va_arg(args, int);
      full_flags->vkl_tochnost = 1;
    } else if (s21_isdigit(*format, 10)) {
      char buffer[MAX_ARRAY_COUNT] = {'\0'};
      for (int i = 0; s21_isdigit(*format, 10); i++, format++)
        buffer[i] = *format;
      full_flags->tochnost = s21_atoi(buffer);
      full_flags->vkl_tochnost = 1;
    }
  }
  return format;
}

const char *find_dlina(const char *format, flags *full_flags) {
  switch (*format) {
    case 'h':
      full_flags->dlina = 'h';
      format++;
      break;
    case 'l':
      full_flags->dlina = 'l';
      format++;
      break;
    case 'L':
      full_flags->dlina = 'L';
      format++;
  }
  if (*format == 'l') {
    full_flags->dlina = 'L';
    format++;
  }
  return format;
}

void write_text_with_flags(const flags full_flags, char *buffer, va_list args,
                           char *str, char *counter) {
  switch (full_flags.specifikator) {
    case 'c': {
      transform_char(full_flags, buffer, args);
      break;
    }
    case 'd':
    case 'i':
      transform_int(full_flags, buffer, args);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      print_feEgG(args, buffer, full_flags);
      break;
    case 's':
      transform_string(full_flags, buffer, args);
      break;
    case 'u':
    case 'x':
    case 'X':
    case 'o':
      transform_unsign(full_flags, buffer, args);
      break;
    case '%':
      buffer[0] = '%';
      break;
    case 'p': {
      void *ptr = va_arg(args, void *);
      ptr_to_str(ptr, buffer);
      break;
    }
    case 'n': {
      int *num = va_arg(args, int *);
      s21_size_t length = (s21_size_t)(str - counter);
      *(num) = length;
      break;
    }
  }
}

void transform_char(const flags full_flags, char *buffer, va_list args) {
  char c = (char)va_arg(args, int);
  if (!full_flags.minus && full_flags.shirina) {
    for (int i = 0; i < full_flags.shirina; i++) {
      buffer[i] = ' ';
      if (i == full_flags.shirina - 1) buffer[i] = c;
    }
  } else if (full_flags.shirina) {
    buffer[0] = c;
    for (int i = 1; i < full_flags.shirina; i++) buffer[i] = ' ';
  } else {
    buffer[0] = c;
  }
}

void transform_int(const flags full_flags, char *buffer, va_list args) {
  long long int temp_int;
  get_format_length(&temp_int, args, full_flags.dlina);
  char tmp_buffer[MAX_ARRAY_COUNT] = {'\0'};
  int idx = MAX_ARRAY_COUNT - 2;
  int flg_negative = 0;
  if (temp_int < 0) {
    flg_negative = 1;
    temp_int = -1 * temp_int;
  }
  if (temp_int == 0)
    buffer[0] = '0';
  else {
    while (temp_int > 0) {
      idx--;
      tmp_buffer[idx] = "0123456789"[temp_int % 10];
      temp_int /= 10;
    }
    for (int j = 0; tmp_buffer[idx]; idx++, j++) {
      if (flg_negative && j == 0) buffer[j++] = '-';
      buffer[j] = tmp_buffer[idx];
    }
  }
  format_tochnost(full_flags, buffer, flg_negative);
  format_flags(full_flags, buffer);
  format_shirina(full_flags, buffer);
}
void transform_string(const flags full_flags, char *buffer, va_list args) {
  char *temp_str = va_arg(args, char *);
  s21_strcpy(buffer, temp_str);
  format_tochnost(full_flags, buffer, 0);
  format_flags(full_flags, buffer);
  format_shirina(full_flags, buffer);
}
void transform_unsign(const flags full_flags, char *buffer, va_list args) {
  long long int temp_unsign;
  get_format_length_unsign(&temp_unsign, args, full_flags.dlina);
  char tmp_buffer[MAX_ARRAY_COUNT] = {'\0'};
  int idx = MAX_ARRAY_COUNT - 1;
  int razriad = 10;
  int count = 0;
  if (full_flags.specifikator == 'x' || full_flags.specifikator == 'X') {
    razriad = 16;
    if (full_flags.reshetka) {
      buffer[0] = '0';
      buffer[1] = 'x';
      count = 2;
    }
  } else if (full_flags.specifikator == 'o') {
    if (full_flags.reshetka) {
      buffer[0] = '0';
      count = 1;
    }
    razriad = 8;
  }
  if (temp_unsign == 0)
    buffer[count] = '0';
  else {
    while (temp_unsign > 0) {
      idx--;
      tmp_buffer[idx] = "0123456789abcdef"[temp_unsign % razriad];
      temp_unsign /= razriad;
    }
    for (; tmp_buffer[idx]; idx++, count++) {
      buffer[count] = tmp_buffer[idx];
    }
  }
  format_tochnost(full_flags, buffer, 0);
  format_flags(full_flags, buffer);
  format_shirina(full_flags, buffer);
  if (full_flags.specifikator == 'X') {
    char *tmp = s21_to_upper(buffer);
    s21_strcpy(buffer, tmp);
    free(tmp);
  }
}

void print_feEgG(va_list args, char *buf, const flags full_flags) {
  char eg_case = full_flags.specifikator;
  long double num, original_num = 0;
  int acc = full_flags.tochnost;
  if (full_flags.dlina == 'L')
    num = va_arg(args, long double);
  else
    num = va_arg(args, double);
  original_num = num;
  int e = 0;
  e = scientific_notaion(&num);
  double_to_str(num, buf, 0, full_flags);
  char degree[500];
  int_to_str(e, degree);
  if (e >= 0) {
    if (eg_case == 'e' ||
        (eg_case == 'g' &&
         ((e > 5 && acc == -1) || (acc != -1 && acc <= e && acc != 0)))) {
      s21_strcat(buf, "e+");
      add_zero(buf, e);
      s21_strcat(buf, degree);
    } else if (eg_case == 'E' ||
               (eg_case == 'G' && ((e > 5 && acc == -1) ||
                                   (acc != -1 && acc <= e && acc != 0)))) {
      s21_strcat(buf, "E+");
      add_zero(buf, e);
      s21_strcat(buf, degree);
    } else if (((eg_case == 'g' || eg_case == 'G') &&
                ((e <= 5 && acc == -1) || (acc != -1 && acc > e))) ||
               eg_case == 'f') {
      double_to_str(original_num, buf, 1, full_flags);
    }
  } else {
    if (eg_case == 'e' || (eg_case == 'g' && e < -4)) {
      s21_strcat(buf, "e-");
      add_zero(buf, e);
      s21_strcat(buf, degree);
    } else if (eg_case == 'E' || (eg_case == 'G' && e < -4)) {
      s21_strcat(buf, "E-");
      add_zero(buf, e);
      s21_strcat(buf, degree);
    } else if (((eg_case == 'g' || eg_case == 'G') && e >= -4) ||
               eg_case == 'f') {
      double_to_str(original_num, buf, 1, full_flags);
    }
  }
  format_flags(full_flags, buf);
  format_shirina(full_flags, buf);
}

int find_n(const flags full_flags, int i, char *str, int simple_notation,
           long double fraction_part) {
  int n = 6;
  char g_e_f = full_flags.specifikator;
  if (full_flags.tochnost != -1) {
    n = full_flags.tochnost;
  }
  if (n != 0) {
    if ((g_e_f == 'g' || g_e_f == 'G') && str[i - 1] == '.') {
      if (str[0] == '-')
        n = n - i + 2;
      else
        n = n - i + 1;
      long double fraction_part_x = fraction_part;
      for (int i = 0;
           !full_flags.reshetka && simple_notation && i < n && i < 15; i++) {
        fraction_part_x *= 10;
        if (fraction_part_x < 1) n++;
      }
    }
  }
  return n;
}

void print_Decimal(const flags full_flags, int *i, int n, char *str,
                   int simple_notation, long double fraction_part) {
  int decimals = 0;
  char g_e_f = full_flags.specifikator;
  if (!simple_notation || (str[*i - 1] == '.' && simple_notation)) {
    while (decimals < n) {
      fraction_part *= 10;
      decimals++;
    }
    if (fmodl(fabsl(fraction_part) * 10, 10.0) >= 5)
      fraction_part = roundl(fraction_part);
    if ((g_e_f == 'g' || g_e_f == 'G') && !full_flags.reshetka) {
      while ((long)fraction_part % 10 == 0 && (long)fraction_part != 0) {
        fraction_part /= 10;
        decimals--;
      }
      if ((long)fraction_part == 0) {
        decimals = 0;
        *i -= 1;
      }
    }
    decimals -= 1;
    for (; decimals >= 0; decimals--) {
      long long digit = (long long)(fraction_part / pow(10, decimals)) % 10;
      str[(*i)++] = '0' + digit;
      fraction_part -= digit * pow(10, decimals);
    }
  }
}

void double_to_str(long double num, char *str, int simple_notation,
                   const flags full_flags) {
  char g_e_f = full_flags.specifikator;
  long long integr_num = (long long)num;
  long double fraction_part = num - integr_num;
  int i = 0;
  if (num < 0) {
    str[i++] = '-';
    integr_num = labs(integr_num);
    fraction_part = fabsl(fraction_part);
  }
  if (fraction_part + 0.000000000000001 >= 1) {
    fraction_part = 0;
    integr_num += 1;
  }
  if (integr_num == 0) str[i++] = '0';
  while (integr_num != 0) {
    str[i++] = '0' + (integr_num % 10);
    integr_num /= 10;
  }
  int start = (num < 0) ? 1 : 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
  if (!simple_notation || fraction_part != 0 || full_flags.reshetka ||
      g_e_f == 'f')
    str[i++] = '.';
  int n = find_n(full_flags, i, str, simple_notation, fraction_part);
  if (n != 0) {
    if (str[0] == '0' && str[1] == '.' && simple_notation && g_e_f != 'f' &&
        n != 0)
      n += 1;
    if (str[0] == '-' && str[1] == '0' && str[2] == '.' && simple_notation &&
        g_e_f != 'f' && n != 0)
      n += 1;
    print_Decimal(full_flags, &i, n, str, simple_notation, fraction_part);
  } else if (g_e_f != 'f') {
    i -= 1;
  }
  str[i] = '\0';
}

void int_to_str(int num, char *result) {
  int temp = num;
  if (temp < 0) {
    temp *= -1;
    num *= -1;
  }
  int count = 0;
  while (temp != 0) {
    temp = temp / 10;
    count++;
  }
  for (int i = count - 1; i >= 0; i--) {
    result[i] = num % 10 + '0';
    num = num / 10;
  }
  result[count] = '\0';
}

int scientific_notaion(long double *num) {
  int k = 0;
  if (fabsl(*num) > 1) {
    while (fabsl(*num) > 9.99999999) {
      *num = *num / 10;
      k++;
    }
  } else {
    while (fabsl(*num) < 0.99999999) {
      if (*num == 0) {
        break;
      }
      *num = *num * 10;
      k++;
    }
    k *= -1;
  }
  return k;
}

void add_zero(char *buf, int e) {
  if (e < 10 && e != 0 && e > -10) {
    s21_strcat(buf, "0");
  } else if (e == 0) {
    s21_strcat(buf, "00");
  }
}

void ptr_to_str(unsigned long int *ptr, char str[]) {
  int count = 0;
  if (ptr == s21_NULL) {
    char *nil_str = "(nil)";
    s21_strcat(str, nil_str);
    count += s21_strlen(nil_str);
  } else {
    str[count++] = '0';
    str[count++] = 'x';
    unsigned long decimal_number = (unsigned long)ptr;
    if (decimal_number == 0) {
      str[count++] = '0';
    } else {
      char tmp_buffer[sizeof(ptr) * 2];
      int j = 0;
      while (decimal_number != 0) {
        int digit = decimal_number % 16;
        int ascii_code = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
        tmp_buffer[j++] = ascii_code;
        decimal_number /= 16;
      }

      while (j > 0) {
        str[count++] = tmp_buffer[--j];
      }
    }
  }
}

void format_tochnost(const flags full_flags, char *buffer,
                     const int flg_negative) {
  char temp_buffer[MAX_ARRAY_COUNT] = {'\0'};
  s21_size_t dlina_buffera = s21_strlen(buffer);
  if (flg_negative) {
    temp_buffer[0] = '-';
    dlina_buffera--;
  }
  if (full_flags.tochnost > (int)dlina_buffera &&
      full_flags.specifikator != 's') {
    int sshchetchik = flg_negative;
    for (;
         sshchetchik < full_flags.tochnost - (int)dlina_buffera + flg_negative;
         sshchetchik++)
      temp_buffer[sshchetchik] = '0';

    for (int count = flg_negative; buffer[count]; count++, sshchetchik++)
      temp_buffer[sshchetchik] = buffer[count];
    s21_strcpy(buffer, temp_buffer);
  }
  if (full_flags.tochnost < (int)dlina_buffera &&
      full_flags.specifikator == 's' && full_flags.vkl_tochnost) {
    for (int count = 0; count < full_flags.tochnost; count++)
      temp_buffer[count] = buffer[count];
    s21_strcpy(buffer, temp_buffer);
  }

  if (full_flags.tochnost == -1 && full_flags.vkl_tochnost) buffer[0] = '\0';
}

void format_flags(const flags full_flags, char *buffer) {
  char temp_buffer[MAX_ARRAY_COUNT + 1] = {'\0'};

  if (full_flags.plus && full_flags.specifikator != 'u' &&
      full_flags.specifikator != 'o' && full_flags.specifikator != 'x' &&
      full_flags.specifikator != 'X') {
    temp_buffer[0] = buffer[0] == '-' ? buffer[0] : '+';
    s21_strcpy(temp_buffer + 1, buffer[0] == '-' ? buffer + 1 : buffer);
    s21_strcpy(buffer, temp_buffer);
  } else if (full_flags.probel && buffer[0] != '-' &&
             full_flags.specifikator != 'u' && full_flags.specifikator != 'o' &&
             full_flags.specifikator != 'x' && full_flags.specifikator != 'X') {
    temp_buffer[0] = ' ';
    s21_strcpy(temp_buffer + 1, buffer);
    s21_strcpy(buffer, temp_buffer);
  }
}

void format_shirina(const flags full_flags, char *buffer) {
  s21_size_t dlina_buffera = s21_strlen(buffer);
  int flag_minus_plus = 0;
  if ((buffer[0] == '-' || buffer[0] == '+') && full_flags.zero &&
      full_flags.shirina > (int)dlina_buffera) {
    if (buffer[0] == '-')
      flag_minus_plus = 1;
    else
      flag_minus_plus = 2;
    buffer[0] = '0';
  }
  char temp_buffer[MAX_ARRAY_COUNT + 1] = {'\0'};
  if (full_flags.shirina > (int)dlina_buffera) {
    char symbol = full_flags.zero ? '0' : ' ';
    int sshchetchik = full_flags.shirina - dlina_buffera;
    if (!full_flags.minus) {
      s21_memset(temp_buffer, symbol, sshchetchik);
      s21_strcpy(temp_buffer + sshchetchik, buffer);
    } else {
      s21_strcpy(temp_buffer, buffer);
      s21_memset(temp_buffer + dlina_buffera, symbol, sshchetchik);
    }
    s21_strcpy(buffer, temp_buffer);

    if (flag_minus_plus == 1)
      buffer[0] = '-';
    else if (flag_minus_plus == 2)
      buffer[0] = '+';
  }
}

void get_format_length(long long *arg, va_list args, char dlina) {
  if (dlina == 'h') {
    *arg = (short int)va_arg(args, int);
  } else if (dlina == 'l') {
    *arg = va_arg(args, long int);
  } else if (dlina == 'L') {
    *arg = va_arg(args, long long int);
  } else {
    *arg = va_arg(args, int);
  }
}

void get_format_length_unsign(long long *arg, va_list args, char dlina) {
  if (dlina == 'h') {
    *arg = (unsigned short int)va_arg(args, int);
  } else if (dlina == 'l') {
    *arg = va_arg(args, unsigned long int);
  } else if (dlina == 'L') {
    *arg = va_arg(args, unsigned long long int);
  } else {
    *arg = va_arg(args, unsigned int);
  }
}

int s21_atoi(const char *str) {
  int res = 0;
  for (int i = 0; str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'); i++) {
    res = res * 10 + (str[i] - '0');
  }
  return res;
}

int s21_isdigit(int c, int base) {
  int res = 0;
  if (base == 10 && c >= '0' && c <= '9') {
    res = 1;
  } else if (base == 8 && c >= '0' && c <= '7') {
    res = 1;
  } else if (base == 16 &&
             ((c >= '0' && c <= '9') || ((c >= 'A' && c <= 'A' + base - 11) ||
                                         (c >= 'a' && c <= 'a' + base - 11)))) {
    res = 1;
  }
  return res;
}