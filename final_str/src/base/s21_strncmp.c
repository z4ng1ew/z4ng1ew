#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int comparisonResult = 0;
  s21_size_t index = 0;

  while (index != n) {
    if (*(str1 + index) != *(str2 + index)) {
      comparisonResult = *(str1 + index) - *(str2 + index);
      index = n;

    } else {
      index++;
    }
  }

  return comparisonResult;
}
