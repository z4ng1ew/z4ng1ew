#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t byteIndex = 0; byteIndex < n; byteIndex++) {
    *((char *)dest + byteIndex) = *((char *)src + byteIndex);
  }

  return dest;
}
