#include "unit_tests.h"

START_TEST(s21_printf_c_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "meeseeks %c", '!');
  s21_sprintf(str2, "meeseeks %c", '!');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_c_2) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  for (int i = 33; i < 127; i++) {
    int count1 = sprintf(str1, "meeseeks %c", (char)i);
    int count2 = s21_sprintf(str2, "meeseeks %c", (char)i);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(count1, count2);
  }
}
END_TEST

START_TEST(s21_printf_c_3) {
  char *str = "%c %c %c %c %c %c %c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  for (char i = '0'; i <= '9'; i += 1) {
    int count1 = sprintf(str1, str, i, i, i, i, i, i, i);
    int count2 = s21_sprintf(str2, str, i, i, i, i, i, i, i);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(count1, count2);
  }
}
END_TEST

START_TEST(s21_printf_c_4) {
  char *str = "%4c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_5) {
  char *str = "%-5c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_6) {
  char *str = "%.1c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_7) {
  char *str = "%10.2c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_8) {
  char *str = "%+c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_10) {
  char *str = "%-3c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_11) {
  char *str = "%*c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 3, 'a');
  int count2 = s21_sprintf(str2, str, 3, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_12) {
  char *str = "%-10.3c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 3, 'a');
  int count2 = s21_sprintf(str2, str, 3, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_13) {
  char *str = "%+10c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 3, 'a');
  int count2 = s21_sprintf(str2, str, 3, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "meeseeks want %d", 100);
  s21_sprintf(str2, "meeseeks want %d", 100);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_d_2) {
  char *str = "%d %d %d %d %d %d %d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  for (int i = -100000; i <= 100000; i += 100) {
    int count1 = sprintf(str1, str, i, i, i, i, i, i, i);
    int count2 = s21_sprintf(str2, str, i, i, i, i, i, i, i);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(count1, count2);
  }
}
END_TEST

START_TEST(s21_printf_d_3) {
  char *str = "%hd %hd %hd";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -32767, 0, 32767);
  int count2 = s21_sprintf(str2, str, -32767, 0, 32767);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_4) {
  char *str = "%ld %ld %ld";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -2147483646L, 0, 2147483647L);
  int count2 = s21_sprintf(str2, str, -2147483646L, 0, 2147483647L);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_5) {
  char *str = "%5d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -123);
  int count2 = s21_sprintf(str2, str, -123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_6) {
  char *str = "%-8d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_7) {
  char *str = "%.3d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_8) {
  char *str = "%10.2d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -98765);
  int count2 = s21_sprintf(str2, str, -98765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_9) {
  char *str = "%+d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 10000);
  int count2 = s21_sprintf(str2, str, 10000);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_10) {
  char *str = "%08d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 10000);
  int count2 = s21_sprintf(str2, str, 10000);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_11) {
  char *str = "%*d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 10, 123);
  int count2 = s21_sprintf(str2, str, 10, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_d_12) {
  char *str = "%-10.5d";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 10000);
  int count2 = s21_sprintf(str2, str, 10000);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_1) {
  char *str = "%hi %hi %hi";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -32767, 0, 32767);
  int count2 = s21_sprintf(str2, str, -32767, 0, 32767);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_2) {
  char *str = "%li %li %li";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -2147483646L, 0, 2147483647L);
  int count2 = s21_sprintf(str2, str, -2147483646L, 0, 2147483647L);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_3) {
  char *str = "%5i";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -123);
  int count2 = s21_sprintf(str2, str, -123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_4) {
  char *str = "%-8i";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_5) {
  char *str = "%.3i";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_6) {
  char *str = "%10.2i";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, -98765);
  int count2 = s21_sprintf(str2, str, -98765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_i_7) {
  char *str = "%-10.5i";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 10000);
  int count2 = s21_sprintf(str2, str, 10000);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_1) {
  char *str = "%s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "Hello_Meeseeks");
  int count2 = s21_sprintf(str2, str, "Hello_Meeseeks");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_2) {
  char *str = "%10s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "meeseeks");
  int count2 = s21_sprintf(str2, str, "meeseeks");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_3) {
  char *str = "%-10s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "meeseeks");
  int count2 = s21_sprintf(str2, str, "meeseeks");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_4) {
  char *str = "%.4s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "meeseeks");
  int count2 = s21_sprintf(str2, str, "meeseeks");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_5) {
  char *str = "%10.4s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "meeseeks");
  int count2 = s21_sprintf(str2, str, "meeseeks");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_6) {
  char *str = "%10.*s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4, "meeseeks");
  int count2 = s21_sprintf(str2, str, 4, "meeseeks");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_7) {
  char *str = "%10s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "");
  int count2 = s21_sprintf(str2, str, "");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_8) {
  char *str = "%10.4s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "");
  int count2 = s21_sprintf(str2, str, "");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_s_9) {
  char *str = "%10.0s";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, "123");
  int count2 = s21_sprintf(str2, str, "123");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_1) {
  char *str = "%u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_2) {
  char *str = "Unsigned number: %u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_3) {
  char *str = "%20u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_4) {
  char *str = "%+20u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_5) {
  char *str = "%-20u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_6) {
  char *str = "%5.2u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_7) {
  char *str = "%+5.2u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_8) {
  char *str = "%u";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_9) {
  char *str = "%5.2hu";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_10) {
  char *str = "%5.2lu";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_1) {
  char *str = "%o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_2) {
  char *str = "Unsigned number: %o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_3) {
  char *str = "%20o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 12345);
  int count2 = s21_sprintf(str2, str, 12345);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_4) {
  char *str = "%+20o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_5) {
  char *str = "%-20o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_6) {
  char *str = "%5.2o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_7) {
  char *str = "%+5.2o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_8) {
  char *str = "%o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_9) {
  char *str = "%5.2ho";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_10) {
  char *str = "%5.2lo";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

#ifdef __APPLE__
//
#else

START_TEST(s21_printf_u_11) {
  char *str = "%5.2Lu";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_u_12) {
  char *str = "%*.*Lu";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 2, 2, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_11) {
  char *str = "%5.2Lo";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_o_12) {
  char *str = "%*.*Lo";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 2, 2, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_c_9) {
  char *str = "%08c";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 'a');
  int count2 = s21_sprintf(str2, str, 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x11) {
  char *str = "%5.2Lx";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x12) {
  char *str = "%*.*Lx";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 2, 2, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_11) {
  char *str = "%5.2LX";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_12) {
  char *str = "%*.*LX";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 2, 2, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

#endif

START_TEST(s21_printf_o_13) {
  char *str = "%#o";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 0123);
  int count2 = s21_sprintf(str2, str, 2, 2, 0123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x1) {
  char *str = "%x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x2) {
  char *str = "Unsigned number: %x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x3) {
  char *str = "%20x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 12345);
  int count2 = s21_sprintf(str2, str, 12345);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x4) {
  char *str = "%+20x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0X123F);
  int count2 = s21_sprintf(str2, str, 0X123F);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x5) {
  char *str = "%-20x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x6) {
  char *str = "%5.2x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x7) {
  char *str = "%+5.2x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x8) {
  char *str = "%x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x9) {
  char *str = "%5.2hx";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x10) {
  char *str = "%5.2lx";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_x13) {
  char *str = "%#x";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 0X123);
  int count2 = s21_sprintf(str2, str, 2, 2, 0X123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_1) {
  char *str = "%X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_2) {
  char *str = "Unsigned number: %X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0);
  int count2 = s21_sprintf(str2, str, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_3) {
  char *str = "%20X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 12345);
  int count2 = s21_sprintf(str2, str, 12345);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_4) {
  char *str = "%+20X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 0X123F);
  int count2 = s21_sprintf(str2, str, 0X123F);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_5) {
  char *str = "%-20X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_6) {
  char *str = "%5.2X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_7) {
  char *str = "%+5.2X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 123);
  int count2 = s21_sprintf(str2, str, 123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_8) {
  char *str = "%X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_9) {
  char *str = "%5.2hX";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_10) {
  char *str = "%5.2lX";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 4294967222296222244);
  int count2 = s21_sprintf(str2, str, 4294967222296222244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(s21_printf_X_13) {
  char *str = "%#X";
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  int count1 = sprintf(str1, str, 2, 2, 0X123);
  int count2 = s21_sprintf(str2, str, 2, 2, 0X123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

TCase *tests_s21_sprintf_3(void) {
  TCase *tc1_1 = tcase_create("tests_s21_sprintf_3");

  tcase_add_test(tc1_1, s21_printf_c_1);
  tcase_add_test(tc1_1, s21_printf_c_2);
  tcase_add_test(tc1_1, s21_printf_c_3);
  tcase_add_test(tc1_1, s21_printf_c_4);
  tcase_add_test(tc1_1, s21_printf_c_5);
  tcase_add_test(tc1_1, s21_printf_c_6);
  tcase_add_test(tc1_1, s21_printf_c_7);
  tcase_add_test(tc1_1, s21_printf_c_8);
  tcase_add_test(tc1_1, s21_printf_c_10);
  tcase_add_test(tc1_1, s21_printf_c_11);
  tcase_add_test(tc1_1, s21_printf_c_12);
  tcase_add_test(tc1_1, s21_printf_c_13);
  tcase_add_test(tc1_1, s21_printf_d_1);
  tcase_add_test(tc1_1, s21_printf_d_2);
  tcase_add_test(tc1_1, s21_printf_d_3);
  tcase_add_test(tc1_1, s21_printf_d_4);
  tcase_add_test(tc1_1, s21_printf_d_5);
  tcase_add_test(tc1_1, s21_printf_d_6);
  tcase_add_test(tc1_1, s21_printf_d_7);
  tcase_add_test(tc1_1, s21_printf_d_8);
  tcase_add_test(tc1_1, s21_printf_d_9);
  tcase_add_test(tc1_1, s21_printf_d_10);
  tcase_add_test(tc1_1, s21_printf_d_11);
  tcase_add_test(tc1_1, s21_printf_d_12);
  tcase_add_test(tc1_1, s21_printf_i_1);
  tcase_add_test(tc1_1, s21_printf_i_2);
  tcase_add_test(tc1_1, s21_printf_i_3);
  tcase_add_test(tc1_1, s21_printf_i_4);
  tcase_add_test(tc1_1, s21_printf_i_5);
  tcase_add_test(tc1_1, s21_printf_i_6);
  tcase_add_test(tc1_1, s21_printf_i_7);
  tcase_add_test(tc1_1, s21_printf_s_1);
  tcase_add_test(tc1_1, s21_printf_s_2);
  tcase_add_test(tc1_1, s21_printf_s_3);
  tcase_add_test(tc1_1, s21_printf_s_4);
  tcase_add_test(tc1_1, s21_printf_s_5);
  tcase_add_test(tc1_1, s21_printf_s_6);
  tcase_add_test(tc1_1, s21_printf_s_7);
  tcase_add_test(tc1_1, s21_printf_s_8);
  tcase_add_test(tc1_1, s21_printf_s_9);
  tcase_add_test(tc1_1, s21_printf_u_1);
  tcase_add_test(tc1_1, s21_printf_u_2);
  tcase_add_test(tc1_1, s21_printf_u_3);
  tcase_add_test(tc1_1, s21_printf_u_4);
  tcase_add_test(tc1_1, s21_printf_u_5);
  tcase_add_test(tc1_1, s21_printf_u_6);
  tcase_add_test(tc1_1, s21_printf_u_7);
  tcase_add_test(tc1_1, s21_printf_u_8);
  tcase_add_test(tc1_1, s21_printf_u_9);
  tcase_add_test(tc1_1, s21_printf_u_10);
  tcase_add_test(tc1_1, s21_printf_o_1);
  tcase_add_test(tc1_1, s21_printf_o_2);
  tcase_add_test(tc1_1, s21_printf_o_3);
  tcase_add_test(tc1_1, s21_printf_o_4);
  tcase_add_test(tc1_1, s21_printf_o_5);
  tcase_add_test(tc1_1, s21_printf_o_6);
  tcase_add_test(tc1_1, s21_printf_o_7);
  tcase_add_test(tc1_1, s21_printf_o_8);
  tcase_add_test(tc1_1, s21_printf_o_9);
  tcase_add_test(tc1_1, s21_printf_o_10);
  tcase_add_test(tc1_1, s21_printf_o_13);
  tcase_add_test(tc1_1, s21_printf_x1);
  tcase_add_test(tc1_1, s21_printf_x2);
  tcase_add_test(tc1_1, s21_printf_x3);
  tcase_add_test(tc1_1, s21_printf_x4);
  tcase_add_test(tc1_1, s21_printf_x5);
  tcase_add_test(tc1_1, s21_printf_x6);
  tcase_add_test(tc1_1, s21_printf_x7);
  tcase_add_test(tc1_1, s21_printf_x8);
  tcase_add_test(tc1_1, s21_printf_x9);
  tcase_add_test(tc1_1, s21_printf_x10);
  tcase_add_test(tc1_1, s21_printf_x13);
  tcase_add_test(tc1_1, s21_printf_X_1);
  tcase_add_test(tc1_1, s21_printf_X_2);
  tcase_add_test(tc1_1, s21_printf_X_3);
  tcase_add_test(tc1_1, s21_printf_X_4);
  tcase_add_test(tc1_1, s21_printf_X_5);
  tcase_add_test(tc1_1, s21_printf_X_6);
  tcase_add_test(tc1_1, s21_printf_X_7);
  tcase_add_test(tc1_1, s21_printf_X_8);
  tcase_add_test(tc1_1, s21_printf_X_9);
  tcase_add_test(tc1_1, s21_printf_X_10);
  tcase_add_test(tc1_1, s21_printf_X_13);

#ifdef __APPLE__
  //
#else
  tcase_add_test(tc1_1, s21_printf_c_9);
  tcase_add_test(tc1_1, s21_printf_o_11);
  tcase_add_test(tc1_1, s21_printf_o_12);
  tcase_add_test(tc1_1, s21_printf_u_11);
  tcase_add_test(tc1_1, s21_printf_u_12);
  tcase_add_test(tc1_1, s21_printf_x11);
  tcase_add_test(tc1_1, s21_printf_x12);
  tcase_add_test(tc1_1, s21_printf_X_11);
  tcase_add_test(tc1_1, s21_printf_X_12);
#endif

  return tc1_1;
}