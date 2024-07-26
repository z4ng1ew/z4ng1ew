#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int found_ind = -1;

  for (s21_size_t cur_ind = 0; cur_ind < n && found_ind == -1; cur_ind++) {
    if (*((char *)str + cur_ind) == c) {
      found_ind = cur_ind;
    }
  }

  if (found_ind == -1) {
    str = s21_NULL;
  } else {
    str = (char *)str + found_ind;
  }

  return (void *)(str);
}