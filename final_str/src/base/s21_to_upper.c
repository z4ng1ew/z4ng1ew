#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *result_upper = s21_NULL;

  if (str != s21_NULL) {
    s21_size_t str_len = s21_strlen(str);

    result_upper = malloc((str_len + 1) * sizeof(char));

    s21_size_t index = 0;

    for (; index < str_len; index++) {
      if (str[index] >= 'a' && str[index] <= 'z') {
        result_upper[index] = str[index] - 32;

      } else {
        result_upper[index] = str[index];
      }
    }
    result_upper[index] = '\0';
  }
  return result_upper;
}