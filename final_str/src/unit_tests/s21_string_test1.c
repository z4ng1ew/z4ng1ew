

#include "unit_tests.h"

START_TEST(test_s21_to_upper) {
  char *test_strings[] = {"hello, world!", "THIS IS A TEST", "123abc456DEF", "",
                          NULL};

  char *expected_strings[] = {"HELLO, WORLD!", "THIS IS A TEST", "123ABC456DEF",
                              "", NULL};
  char *expected_strings_lower[] = {"hello, world!", "this is a test",
                                    "123abc456def", "", NULL};
  char str1[100];

  for (int i = 0; test_strings[i] != NULL; i++) {
    strcpy(str1, test_strings[i]);
    char *str2 = s21_to_upper(str1);
    ck_assert_str_eq(str2, expected_strings[i]);
    free(str2);
    char *str3 = s21_to_lower(str1);
    ck_assert_str_eq(str3, expected_strings_lower[i]);
    free(str3);
  }
}
END_TEST

START_TEST(test_s21_strtok) {
  const char *test_strings[] = {"qwerty/asd/zxczxc", "apple/banana||orange",
                                "hello$world$$$test$", "", NULL};

  const char *delims[] = {"/", "/|\\", "$", "/", NULL};

  for (int i = 0; test_strings[i] != NULL; i++) {
    char str1[100];
    char str2[100];
    strcpy(str1, test_strings[i]);
    strcpy(str2, test_strings[i]);

    char *t1 = s21_strtok(str1, delims[i]);
    char *t2 = strtok(str2, delims[i]);
    ck_assert_pstr_eq(t1, t2);

    while (t1 && t2) {
      t1 = s21_strtok(s21_NULL, delims[i]);
      t2 = strtok(NULL, delims[i]);
      ck_assert_pstr_eq(t1, t2);
    }
  }
}
END_TEST

START_TEST(test_s21_strrchr) {
  char *str1 = "qqwwweerr\rrrtttyyyyyyy\tyyyyyyy";
  char *str2 = "\0";
  char *str3 = "\n";

  for (int ch = 0; ch < 255; ch++) {
    ck_assert_ptr_eq(s21_strrchr(str1, ch), strrchr(str1, ch));

    ck_assert_ptr_eq(s21_strrchr(str2, ch), strrchr(str2, ch));

    ck_assert_ptr_eq(s21_strrchr(str3, ch), strrchr(str3, ch));
  }
}
END_TEST

START_TEST(test_s21_strstr) {
  char *str1 = "qqwwweerrrr\nrrrtt tyyyyyyy\tyyyyyyy";

  const char *test_strings[] = {"tty", "qqwwweerrrr\nrrrtttyyyyyyy\tyyyyyyy",
                                "\0",  "\n",
                                "t",   "eee",
                                "ee",  NULL};

  for (int i = 0; test_strings[i] != NULL; i++) {
    char *result1 = s21_strstr(str1, test_strings[i]);
    char *result2 = strstr(str1, test_strings[i]);
    ck_assert_ptr_eq(result1, result2);
  }
}
END_TEST

TCase *tests_s21_string_1(void) {
  TCase *tc_core = tcase_create("tests_s21_string_1");

  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strtok);
  tcase_add_test(tc_core, test_s21_to_upper);

  return tc_core;
}
