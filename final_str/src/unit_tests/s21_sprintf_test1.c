#include "unit_tests.h"

START_TEST(test_ptr_to_str_1) {
  long long int x = 48000000000000;
  long long int *ptr = &x;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "Адрес x: %p. long long int", ptr);
  int written2 = sprintf(buffer2, "Адрес x: %p. long long int", ptr);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_ptr_to_str_2) {
  char x = 97;
  void *ptr = &x;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "Адрес x: %p. char", ptr);
  int written2 = sprintf(buffer2, "Адрес x: %p. char", ptr);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_ptr_to_str_3) {
  void *ptr = s21_NULL;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "Адрес s21_NULL: %p !!!", ptr);
  int written2 = sprintf(buffer2, "Адрес s21_NULL: %p !!!", ptr);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_ptr_to_str_4) {
  char *x[] = {"Hello", "Autotest", "Passed", "!"};
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "Адрес массива строк x: %p", x);
  int written2 = sprintf(buffer2, "Адрес массива строк x: %p", x);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_ptr_to_str_5) {
  void *x = s21_NULL;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "NULL x: %p", x);
  int written2 = sprintf(buffer2, "NULL x: %p", x);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_n_1) {
  int count_char;
  char buffer1[100];
  char buffer2[100];
  int written1 =
      s21_sprintf(buffer1, "подсчет символов в этой строке%n!", &count_char);
  int written2 =
      sprintf(buffer2, "подсчет символов в этой строке%n!", &count_char);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_n_2) {
  int count_char;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "тестовая\tcтрока%n", &count_char);
  int written2 = sprintf(buffer2, "тестовая\tcтрока%n", &count_char);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_n_3) {
  long long int x = 48000000000000;
  char buffer1[100];
  char buffer2[100];
  int y1 = 0;
  int y2 = 0;
  int y3 = 0;
  int y4 = 0;
  int written1 = s21_sprintf(buffer1, "! x:%n %lli !%n ", &y1, x, &y2);
  int written2 = sprintf(buffer2, "! x:%n %lli !%n ", &y3, x, &y4);
  ck_assert_int_eq(y1, y3);
  ck_assert_int_eq(y2, y4);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_dlina_1) {
  long long int x = 48000000000000;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "x: %lli !!!", x);
  int written2 = sprintf(buffer2, "x: %lli !!!", x);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_dlina_2) {
  long long int x = 48000000000000;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "x: %Ld !!!", x);
  int written2 = sprintf(buffer2, "x: %lld !!!", x);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_dlina_3) {
  long int x = 48000000000000;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "x: %li !!!", x);
  int written2 = sprintf(buffer2, "x: %li !!!", x);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_specifier_dlina_4) {
  char x = 97;
  char buffer1[100];
  char buffer2[100];
  int written1 = s21_sprintf(buffer1, "x char: %hi !!!", x);
  int written2 = sprintf(buffer2, "x char: %hi !!!", x);
  ck_assert_int_eq(written1, written2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_strerror_existing_error_code) {
  errno = ENOENT;
  char *error_message = s21_strerror(errno);
  ck_assert_str_eq(error_message, strerror(errno));
}
END_TEST

START_TEST(test_strerror_nonexistent_error_code) {
  errno = 9999;
  char *error_message = s21_strerror(errno);
  ck_assert_str_eq(error_message, strerror(errno));
}
END_TEST

START_TEST(test_strerror_success_error_code) {
  errno = 0;
  char *error_message = s21_strerror(errno);
  ck_assert_str_eq(error_message, strerror(errno));
}
END_TEST

START_TEST(test_strerror_all_code) {
  for (int i = -10; i < 300; i++) {
    errno = i;
    char *error_message = s21_strerror(errno);
    ck_assert_str_eq(error_message, strerror(errno));
  }
}
END_TEST

TCase *tests_s21_sprintf_1(void) {
  TCase *tc_core = tcase_create("tests_s21_sprintf_1");

  tcase_add_test(tc_core, test_ptr_to_str_1);
  tcase_add_test(tc_core, test_ptr_to_str_2);
  tcase_add_test(tc_core, test_ptr_to_str_3);
  tcase_add_test(tc_core, test_ptr_to_str_4);
  tcase_add_test(tc_core, test_ptr_to_str_5);
  tcase_add_test(tc_core, test_specifier_n_1);
  tcase_add_test(tc_core, test_specifier_n_2);
  tcase_add_test(tc_core, test_specifier_n_3);
  tcase_add_test(tc_core, test_specifier_dlina_1);
  tcase_add_test(tc_core, test_specifier_dlina_2);
  tcase_add_test(tc_core, test_specifier_dlina_3);
  tcase_add_test(tc_core, test_specifier_dlina_4);
  tcase_add_test(tc_core, test_strerror_existing_error_code);
  tcase_add_test(tc_core, test_strerror_nonexistent_error_code);
  tcase_add_test(tc_core, test_strerror_success_error_code);
  tcase_add_test(tc_core, test_strerror_all_code);

  return tc_core;
}