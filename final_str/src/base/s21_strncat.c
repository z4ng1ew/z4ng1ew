#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *end_of_line = dest;

  while (*end_of_line != '\0') {
    end_of_line++;
  }

  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    *end_of_line++ = src[i];
  }

  *end_of_line = '\0';

  return dest;
}