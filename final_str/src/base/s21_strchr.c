#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;

  if (str != s21_NULL) {
    s21_size_t str_length = s21_strlen(str) + 1;

    for (s21_size_t i = 0; i < str_length && result == s21_NULL; i++) {
      if (str[i] == c) {
        result = (char *)(str + i);
      }
    }
  }

  return result;
}
