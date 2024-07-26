#include "unit_tests.h"

START_TEST(s21_insert_test1) {
  const char s1[20] = "scol 21";
  const char s2[5] = "ho";
  char *result = s21_insert(s1, s2, 2);
  ck_assert_mem_eq(result, "school 21", 9);
  free(result);
}
END_TEST

START_TEST(s21_insert_test2) {
  const char s1[20] = "scol \n21";
  const char s2[5] = "ho\n";
  char *result = s21_insert(s1, s2, 2);
  ck_assert_mem_eq(result, "scho\nol \n21", 10);
  free(result);
}
END_TEST

START_TEST(s21_insert_test3) {
  const char s1[20] = "scol \n21";
  const char s2[5] = "";
  char *result = s21_insert(s1, s2, 2);
  ck_assert_mem_eq(result, "scol \n21", 8);
  free(result);
}
END_TEST

START_TEST(s21_insert_test4) {
  const char s1[20] = "abc  gh";
  const char s2[5] = "def";
  char *result = s21_insert(s1, s2, 4);
  ck_assert_mem_eq(result, "abc def gh", 10);
  free(result);
}
END_TEST

START_TEST(s21_insert_test5) {
  const char s1[20] = "";
  const char s2[5] = "21";
  char *result = s21_insert(s1, s2, 0);
  ck_assert_mem_eq(result, "21", 2);
  free(result);
}
END_TEST

START_TEST(s21_strcspn_test1) {
  const char s1[20] = "scol 21";
  const char s2[5] = "21";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_test2) {
  const char s1[20] = "scol 21";
  const char s2[5] = "";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_test3) {
  const char s1[20] = "";
  const char s2[5] = "";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_test4) {
  const char s1[20] = "";
  const char s2[5] = "qwer";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_test5) {
  const char s1[20] = "qwer";
  const char s2[5] = "qwer";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strncmp_test1) {
  const char s1[20] = "qwerrty";
  const char s2[10] = "qwerrty";
  ck_assert_int_eq(s21_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
}
END_TEST

START_TEST(s21_strncmp_test2) {
  const char s1[20] = "qwerrty";
  const char s2[5] = "qwer";
  ck_assert_int_eq(s21_strncmp(s1, s2, 0), strncmp(s1, s2, 0));
}
END_TEST

START_TEST(s21_strncmp_test3) {
  const char s1[20] = "qwer";
  const char s2[5] = "";
  ck_assert_int_eq(s21_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
}
END_TEST

START_TEST(s21_strncmp_test4) {
  const char s1[20] = "";
  const char s2[5] = "qwer";
  ck_assert_int_eq(s21_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
}
END_TEST

START_TEST(s21_strncmp_test5) {
  const char s1[20] = "";
  const char s2[5] = "";
  ck_assert_int_eq(s21_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
}
END_TEST

START_TEST(s21_strncpy_test1) {
  char s1[20] = "21212121";
  const char s2[5] = "21";
  ck_assert_str_eq(s21_strncpy(s1, s2, 4), strncpy(s1, s2, 4));
}
END_TEST

START_TEST(s21_strncpy_test2) {
  char s1[20] = "";
  const char s2[5] = "21";
  ck_assert_str_eq(s21_strncpy(s1, s2, 4), strncpy(s1, s2, 4));
}
END_TEST

START_TEST(s21_strncpy_test3) {
  char s1[20] = "";
  const char s2[20] = "ABCDEFGabcdefg";
  ck_assert_str_eq(s21_strncpy(s1, s2, 10), strncpy(s1, s2, 10));
}
END_TEST

START_TEST(s21_strncpy_test4) {
  char s1[20] = "ABCDEFGabcdefg";
  const char s2[20] = "";
  ck_assert_str_eq(s21_strncpy(s1, s2, 10), strncpy(s1, s2, 10));
}
END_TEST

START_TEST(s21_strncpy_test5) {
  char s1[20] = "ABCDEFGabcdefg";
  const char s2[20] = "ABCDEFGabcdefg1234";
  ck_assert_str_eq(s21_strncpy(s1, s2, 10), strncpy(s1, s2, 10));
}
END_TEST

TCase *tests_s21_string_3(void) {
  TCase *tc1_1 = tcase_create("tests_s21_string_3");

  tcase_add_test(tc1_1, s21_insert_test1);
  tcase_add_test(tc1_1, s21_insert_test2);
  tcase_add_test(tc1_1, s21_insert_test3);
  tcase_add_test(tc1_1, s21_insert_test4);
  tcase_add_test(tc1_1, s21_insert_test5);
  tcase_add_test(tc1_1, s21_strcspn_test1);
  tcase_add_test(tc1_1, s21_strcspn_test2);
  tcase_add_test(tc1_1, s21_strcspn_test3);
  tcase_add_test(tc1_1, s21_strcspn_test4);
  tcase_add_test(tc1_1, s21_strcspn_test5);
  tcase_add_test(tc1_1, s21_strncmp_test1);
  tcase_add_test(tc1_1, s21_strncmp_test2);
  tcase_add_test(tc1_1, s21_strncmp_test3);
  tcase_add_test(tc1_1, s21_strncmp_test4);
  tcase_add_test(tc1_1, s21_strncmp_test5);
  tcase_add_test(tc1_1, s21_strncpy_test1);
  tcase_add_test(tc1_1, s21_strncpy_test2);
  tcase_add_test(tc1_1, s21_strncpy_test3);
  tcase_add_test(tc1_1, s21_strncpy_test4);
  tcase_add_test(tc1_1, s21_strncpy_test5);

  return tc1_1;
}
