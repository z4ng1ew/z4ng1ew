#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length_before_first_match = 0;
  int match_indicator = 0;

  while (*str1) {
    const char *scanPtr = str2;

    while (*scanPtr != '\0') {
      if (*str1 == *scanPtr) {
        match_indicator = 1;
      }
      scanPtr++;
    }

    if (!match_indicator) {
      length_before_first_match++;
    }

    str1++;
  }

  return length_before_first_match;
}
