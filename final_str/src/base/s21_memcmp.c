#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int compare_res = 0;

  const unsigned char *ptr_byte1 = str1;
  const unsigned char *ptr_byte2 = str2;

  for (s21_size_t i = 0; i < n && compare_res == 0; i++) {
    if (ptr_byte1[i] != ptr_byte2[i]) {
      compare_res = ptr_byte1[i] - ptr_byte2[i];
    };
  }

  return compare_res;
}
