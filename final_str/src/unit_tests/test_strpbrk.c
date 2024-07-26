#include "unit_tests.h"

// Функция-тест, проверяющая работу s21_strpbrk с полным совпадением строк
START_TEST(strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// Функция-тест, проверяющая работу s21_strpbrk с символом в конце строки
START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// Функция-тест, проверяющая работу s21_strpbrk с пустой строкой в качестве
// первого аргумента
START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// Функция-тест, проверяющая работу s21_strpbrk с первой строкой заканчивающейся
// на нулевой символ
START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// Функция-тест, проверяющая работу s21_strpbrk с обеими пустыми строками
START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// Функция-тест, проверяющая работу s21_strpbrk с строкой цифр и подстрокой из
// них
START_TEST(strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// Функция, создающая тест-кейс и добавляющая все тесты
TCase *test_strpbrk(void) {
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);

  return tc;  // Возвращаем TCase, который будет использоваться для добавления в
              // Suite в другом месте
}
