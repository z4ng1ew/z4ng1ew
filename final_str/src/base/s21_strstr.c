#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *matching_word = s21_NULL;

  if (haystack != matching_word) {
    int len_needle = s21_strlen(needle);

    if (len_needle == 0) {
      matching_word = (char *)haystack;

    } else {
      while (*haystack != '\0' && matching_word == s21_NULL) {
        if (*haystack == *needle) {
          const char *h = haystack;
          const char *n = needle;

          while (*h != '\0' && *n != '\0' && (*h == *n)) {
            h++;
            n++;
          }

          if (*n == '\0') {
            matching_word = (char *)haystack;
          }
        }
        haystack++;
      }
    }
  }

  return matching_word;
}
