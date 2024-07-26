#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *found_char_ptr = s21_NULL;

  int str1_length = s21_strlen(str1);
  int str2_length = s21_strlen(str2);
  int found = 0;

  for (int i = 0; i < str1_length && !found; i++) {
    for (int j = 0; j < str2_length && !found; j++) {
      if (str1[i] == str2[j]) {
        found_char_ptr = (char *)(str1 + i);
        found = 1;
      }
    }
  }
  return found_char_ptr;
}
