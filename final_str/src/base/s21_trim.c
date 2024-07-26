#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res_s = s21_NULL;

  if (src != s21_NULL && trim_chars != s21_NULL) {
    s21_size_t str_len = s21_strlen(src);

    int start_index = 0, trimmed_length = str_len, found_first_char = 0;

    for (s21_size_t i = 0; i < str_len && found_first_char == 0; i++) {
      if (s21_strchr(trim_chars, src[i]) == s21_NULL) {
        start_index = i;

        found_first_char = 1;
      } else {
        trimmed_length--;
      }
    }

    found_first_char = 0;

    for (int x = str_len - 1; x > start_index && found_first_char == 0; x--) {
      if (s21_strchr(trim_chars, src[x]) == s21_NULL) {
        found_first_char = 1;
      } else {
        trimmed_length--;
      }
    }

    if (trimmed_length < 0) {
      trimmed_length = 0;
    }

    res_s = (char *)malloc(sizeof(char) * (trimmed_length + 1));

    s21_memcpy(res_s, src + start_index, trimmed_length);

    res_s[trimmed_length] = '\0';
  }
  return res_s;
}
