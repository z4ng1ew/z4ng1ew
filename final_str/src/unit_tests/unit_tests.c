#include "unit_tests.h"

void run_tests(void) {
  Suite *s = s21_string_suite();

  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  if (failed_count != 0) {
    exit(EXIT_FAILURE);
  }
}

Suite *s21_string_suite(void) {
  Suite *s = suite_create("s21_string");

  suite_add_tcase(s, tests_s21_string_1());
  suite_add_tcase(s, tests_s21_string_2());
  suite_add_tcase(s, tests_s21_string_3());
  suite_add_tcase(s, tests_s21_sprintf_1());
  suite_add_tcase(s, tests_s21_sprintf_2());
  suite_add_tcase(s, tests_s21_sprintf_3());
  suite_add_tcase(s, tests_s21_sscanf_1());
  suite_add_tcase(s, test_strpbrk());
  return s;
}

int main(void) {
  run_tests();
  return EXIT_SUCCESS;
}