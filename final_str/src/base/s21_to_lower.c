#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *res_lower = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t str_len = s21_strlen(str);

    res_lower = malloc((str_len + 1) * sizeof(char));

    s21_size_t index = 0;

    for (; index < str_len; index++) {
      if (str[index] >= 'A' && str[index] <= 'Z')
        res_lower[index] = str[index] + 32;
      else
        res_lower[index] = str[index];
    }
    res_lower[index] = '\0';
  }
  return res_lower;
}