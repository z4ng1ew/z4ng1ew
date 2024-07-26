#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

#define S21_TEST_MAX_ARRAY_COUNT 1024

Suite *s21_string_suite(void);

void run_tests(void);

TCase *tests_s21_string_1(void);
TCase *tests_s21_string_2(void);
TCase *tests_s21_string_3(void);
TCase *tests_s21_sprintf_1(void);
TCase *tests_s21_sprintf_2(void);
TCase *tests_s21_sprintf_3(void);
TCase *tests_s21_sscanf_1(void);
TCase *test_strpbrk(void);
#endif
