#include "unit_tests.h"

START_TEST(s21_printf_e_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  long double num = 111.233000000000000000000000000;
  sprintf(str1, "%-30.20Le", num);
  s21_sprintf(str2, "%-30.20Le", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_2) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  long double num = 0.000000000000000000000000000000000000000000000000003;
  sprintf(str1, "%020.5Le", num);
  s21_sprintf(str2, "%020.5Le", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_3) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%0500e", 0.100000);
  s21_sprintf(str2, "%0500e", 0.100000);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_4) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%15.15e", 1112333333333.1);
  s21_sprintf(str2, "%15.15e", 1112333333333.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_5) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%e", 3.00);
  s21_sprintf(str2, "%e", 3.00);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_6) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%e", -3.5678999999999999);
  s21_sprintf(str2, "%e", -3.5678999999999999);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_7) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%e", 3.5115);
  s21_sprintf(str2, "%e", 3.5115);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_8) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(
      str1, "%.15e",
      3.123444444444444411111111111111111111111144444444441234444444444444111111111111111111111111444444444412344444444444441111111111111111111111114444444444123444444444444411111111111111111111111144444444445115);
  s21_sprintf(
      str2, "%.15e",
      3.123444444444444411111111111111111111111144444444441234444444444444111111111111111111111111444444444412344444444444441111111111111111111111114444444444123444444444444411111111111111111111111144444444445115);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_9) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  long double val = 4134121;
  sprintf(str1, "%.17Le", val);
  s21_sprintf(str2, "%.17Le", val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_10) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%e", 5.5115);
  s21_sprintf(str2, "%e", 5.5115);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_11) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+20e", -5.5115);
  s21_sprintf(str2, "%+20e", -5.5115);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_12) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+20e", 5.5115);
  s21_sprintf(str2, "%+20e", 5.5115);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_13) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 0;
  sprintf(str1, "%#e", num);
  s21_sprintf(str2, "%#e", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_14) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1200.;
  sprintf(str1, "%#e", num);
  s21_sprintf(str2, "%#e", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_15) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 0.01;
  sprintf(str1, "%#+.2e", num);
  s21_sprintf(str2, "%#+.2e", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_16) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1.0;
  sprintf(str1, "%#+.2e", num);
  s21_sprintf(str2, "%#+.2e", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_17) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 0.0;
  sprintf(str1, "%#e", num);
  s21_sprintf(str2, "%#e", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_e_18) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 0.0;
  sprintf(str1, "%#010e", num);
  s21_sprintf(str2, "%#010e", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+E", 1112333333333.1);
  s21_sprintf(str2, "%+E", 1112333333333.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_2) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%-E", -1.1);
  s21_sprintf(str2, "%-E", -1.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_3) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+10E%+10E%+10E", -1.1, 1112333333333.1, -2.23);
  s21_sprintf(str2, "%+10E%+10E%+10E", -1.1, 1112333333333.1, -2.23);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_4) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+100E% E%E", 0.566, 1112333333333.1, 0.523);
  s21_sprintf(str2, "%+100E% E%E", 0.566, 1112333333333.1, 0.523);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_5) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%010E%010E", -0.565, 0.565);
  s21_sprintf(str2, "%010E%010E", -0.565, 0.565);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_6) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%0100E", -2.1);
  s21_sprintf(str2, "%0100E", -2.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_7) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%100E", -2.1);
  s21_sprintf(str2, "%100E", -2.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_8) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%0100E", -1000.1);
  s21_sprintf(str2, "%0100E", -1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_9) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%0+100E", 1000.1);
  s21_sprintf(str2, "%0+100E", 1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_10) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+-100E", 1000.1);
  s21_sprintf(str2, "%+-100E", 1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_11) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%-+100.10E", 1000.1);
  s21_sprintf(str2, "%-+100.10E", 1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_12) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "% -100E", 1000.1);
  s21_sprintf(str2, "% -100E", 1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_E_13) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "% -100.0E", 0.1);
  s21_sprintf(str2, "% -100.0E", 0.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "-0.10%g", 1112333333333.1);
  s21_sprintf(str2, "-0.10%g", 1112333333333.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_2) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%g", 23.8);
  s21_sprintf(str2, "%g", 23.8);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_3) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.1g", 2.0);
  s21_sprintf(str2, "%.1g", 2.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_4) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%g%g", 2.3434343434, -1.2);
  s21_sprintf(str2, "%g%g", 2.3434343434, -1.2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_5) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.20g%g%e", 234343.43430,
          -12344444444444441111111111111111111111114444444444.44, 1.2131);
  s21_sprintf(str2, "%.20g%g%e", 234343.43430,
              -12344444444444441111111111111111111111114444444444.44, 1.2131);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_6) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%g%g%e", 0.23434343430, -0.3434343430, 1.2131);
  s21_sprintf(str2, "%g%g%e", 0.23434343430, -0.3434343430, 1.2131);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_7) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%g", 0.0000000000000002);
  s21_sprintf(str2, "%g", 0.0000000000000002);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_8) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%g", -1.123456);
  s21_sprintf(str2, "%g", -1.123456);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_9) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.20g", 23002.23);
  s21_sprintf(str2, "%.20g", 23002.23);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_10) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.10g%.10g%e", 0.23434343430, -0.3434343430, 1.2131);
  s21_sprintf(str2, "%.10g%.10g%e", 0.23434343430, -0.3434343430, 1.2131);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_11) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.2g", 0.0023434343430);
  s21_sprintf(str2, "%.2g", 0.0023434343430);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_12) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1.0;
  sprintf(str1, "%#g", num);
  s21_sprintf(str2, "%#g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_13) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1.0;
  sprintf(str1, "%#.10g", num);
  s21_sprintf(str2, "%#.10g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_14) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 3.12;
  sprintf(str1, "%.0G", num);
  s21_sprintf(str2, "%.0G", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_15) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12412121313133.21;
  sprintf(str1, "%#g", num);
  s21_sprintf(str2, "%#g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_16) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 13133.0;
  sprintf(str1, "%#g", num);
  s21_sprintf(str2, "%#g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_17) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313.;
  sprintf(str1, "%#g", num);
  s21_sprintf(str2, "%#g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_18) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000000.;
  sprintf(str1, "%#g", num);
  s21_sprintf(str2, "%#g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_19) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000000.1231;
  sprintf(str1, "%+#.4g", num);
  s21_sprintf(str2, "%+#.4g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_20) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000.0;
  sprintf(str1, "%+0#.4g", num);
  s21_sprintf(str2, "%+0#.4g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_g_21) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000.0;
  sprintf(str1, "%+0#20.4g", num);
  s21_sprintf(str2, "%+0#20.4g", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.5G", 1112333.3333331);
  s21_sprintf(str2, "%.5G", 1112333.3333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_2) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.2G", 11123.333333331);
  s21_sprintf(str2, "%.2G", 11123.333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_3) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.5G", 11123.333333331);
  s21_sprintf(str2, "%.5G", 11123.333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_4) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.2G", 0.001333333331);
  s21_sprintf(str2, "%.2G", 0.001333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_5) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.4G", 0.001333333331);
  s21_sprintf(str2, "%.4G", 0.001333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_6) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%G", 0.001333333331);
  s21_sprintf(str2, "%G", 0.001333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_7) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%G", -0.001333333331);
  s21_sprintf(str2, "%G", -0.001333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_8) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.1g", -0.0000130001);
  s21_sprintf(str2, "%.1g", -0.000013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_9) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.8g", 123456789.8548);
  s21_sprintf(str2, "%.8g", 123456789.8548);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_10) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%-20.3g", -0.00130001);
  s21_sprintf(str2, "%-20.3g", -0.0013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_11) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "% 20.3g", -0.00130001);
  s21_sprintf(str2, "% 20.3g", -0.0013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_G_12) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "% 20.3g", 0.00130001);
  s21_sprintf(str2, "% 20.3g", 0.0013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_1) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  long double num = 111.233000000000000000000000000;
  sprintf(str1, "%Lf", num);
  s21_sprintf(str2, "%Lf", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_2) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 111.233000000000000000000000000;
  sprintf(str1, "%f", num);
  s21_sprintf(str2, "%f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_3) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 111.233000000000000000000000000;
  sprintf(str1, "%.15f", num);
  s21_sprintf(str2, "%.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_4) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  long double num = 111.233000000000000000000000000;
  sprintf(str1, "%.15Lf", num);
  s21_sprintf(str2, "%.15Lf", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_5) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  long double num = -111.233000000000000000000000000;
  sprintf(str1, "%.15Lf", num);
  s21_sprintf(str2, "%.15Lf", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_6) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = -111.001;
  sprintf(str1, "%.15f", num);
  s21_sprintf(str2, "%.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_7) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 111.001;
  sprintf(str1, "%+.15f", num);
  s21_sprintf(str2, "%+.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_8) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 111.001;
  sprintf(str1, "%+30.15f", num);
  s21_sprintf(str2, "%+30.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_9) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 111.001;
  sprintf(str1, "%0+30.15f", num);
  s21_sprintf(str2, "%0+30.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_10) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12345678.01;
  sprintf(str1, "%+.15f", num);
  s21_sprintf(str2, "%+.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_11) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12345678.0;
  sprintf(str1, "%+.15f", num);
  s21_sprintf(str2, "%+.15f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_12) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12345678.005;
  sprintf(str1, "%-+10f", num);
  s21_sprintf(str2, "%-+10f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_13) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12345678.005;
  sprintf(str1, "%0 10f", num);
  s21_sprintf(str2, "%0 10f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_14) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12345678.005;
  sprintf(str1, "%-10f", num);
  s21_sprintf(str2, "%-10f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_15) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12345678.005;
  sprintf(str1, "%#10f", num);
  s21_sprintf(str2, "%#10f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_16) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1.0;
  sprintf(str1, "%#f", num);
  s21_sprintf(str2, "%#f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_17) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1.0;
  sprintf(str1, "%#.10f", num);
  s21_sprintf(str2, "%#.10f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_18) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 124.12;
  sprintf(str1, "%#.5f", num);
  s21_sprintf(str2, "%#.5f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_19) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 12412121313133.21;
  sprintf(str1, "%#f", num);
  s21_sprintf(str2, "%#f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_20) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 13133.0;
  sprintf(str1, "%#f", num);
  s21_sprintf(str2, "%#f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_21) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313.;
  sprintf(str1, "%#f", num);
  s21_sprintf(str2, "%#f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_22) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000000.;
  sprintf(str1, "%#f", num);
  s21_sprintf(str2, "%#f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_23) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000000.1231;
  sprintf(str1, "%+#.4f", num);
  s21_sprintf(str2, "%+#.4f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_24) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000.0;
  sprintf(str1, "%+0#.4f", num);
  s21_sprintf(str2, "%+0#.4f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_25) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  double num = 1313000.0;
  sprintf(str1, "%+0#20.4f", num);
  s21_sprintf(str2, "%+0#20.4f", num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_26) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%f", 0.001333333331);
  s21_sprintf(str2, "%f", 0.001333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_27) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%f", -0.001333333331);
  s21_sprintf(str2, "%f", -0.001333333331);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_28) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.1f", -0.0000130001);
  s21_sprintf(str2, "%.1f", -0.000013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_29) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.8f", 123456789.8548);
  s21_sprintf(str2, "%.8f", 123456789.8548);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_30) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%-20.3f", -0.00130001);
  s21_sprintf(str2, "%-20.3f", -0.0013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_31) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "% 20.3f", -0.00130001);
  s21_sprintf(str2, "% 20.3f", -0.0013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_32) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "% 20.3f", 0.00130001);
  s21_sprintf(str2, "% 20.3f", 0.0013000100011);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_33) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%+-100f", 1000.1);
  s21_sprintf(str2, "%+-100f", 1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_34) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%-+100.10f", 1000.1);
  s21_sprintf(str2, "%-+100.10f", 1000.1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_35) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%.1f", -100.2323323323256555678880);
  s21_sprintf(str2, "%.1f", -100.2323323323256555678880);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_printf_f_36) {
  char str1[S21_TEST_MAX_ARRAY_COUNT];
  char str2[S21_TEST_MAX_ARRAY_COUNT];
  sprintf(str1, "%#.0f", -100.2323323323256555678880);
  s21_sprintf(str2, "%#.0f", -100.2323323323256555678880);
  ck_assert_str_eq(str1, str2);
}
END_TEST

TCase *tests_s21_sprintf_2(void) {
  TCase *tc1_1 = tcase_create("tests_s21_sprintf_2");

  tcase_add_test(tc1_1, s21_printf_e_1);
  tcase_add_test(tc1_1, s21_printf_e_2);
  tcase_add_test(tc1_1, s21_printf_e_3);
  tcase_add_test(tc1_1, s21_printf_e_4);
  tcase_add_test(tc1_1, s21_printf_e_5);
  tcase_add_test(tc1_1, s21_printf_e_6);
  tcase_add_test(tc1_1, s21_printf_e_7);
  tcase_add_test(tc1_1, s21_printf_e_8);
  tcase_add_test(tc1_1, s21_printf_e_9);
  tcase_add_test(tc1_1, s21_printf_e_10);
  tcase_add_test(tc1_1, s21_printf_e_11);
  tcase_add_test(tc1_1, s21_printf_e_12);
  tcase_add_test(tc1_1, s21_printf_e_13);
  tcase_add_test(tc1_1, s21_printf_e_14);
  tcase_add_test(tc1_1, s21_printf_e_15);
  tcase_add_test(tc1_1, s21_printf_e_16);
  tcase_add_test(tc1_1, s21_printf_e_17);
  tcase_add_test(tc1_1, s21_printf_e_18);
  tcase_add_test(tc1_1, s21_printf_E_1);
  tcase_add_test(tc1_1, s21_printf_E_2);
  tcase_add_test(tc1_1, s21_printf_E_3);
  tcase_add_test(tc1_1, s21_printf_E_4);
  tcase_add_test(tc1_1, s21_printf_E_5);
  tcase_add_test(tc1_1, s21_printf_E_6);
  tcase_add_test(tc1_1, s21_printf_E_7);
  tcase_add_test(tc1_1, s21_printf_E_8);
  tcase_add_test(tc1_1, s21_printf_E_9);
  tcase_add_test(tc1_1, s21_printf_E_10);
  tcase_add_test(tc1_1, s21_printf_E_11);
  tcase_add_test(tc1_1, s21_printf_E_12);
  tcase_add_test(tc1_1, s21_printf_E_13);
  tcase_add_test(tc1_1, s21_printf_g_1);
  tcase_add_test(tc1_1, s21_printf_g_2);
  tcase_add_test(tc1_1, s21_printf_g_3);
  tcase_add_test(tc1_1, s21_printf_g_4);
  tcase_add_test(tc1_1, s21_printf_g_5);
  tcase_add_test(tc1_1, s21_printf_g_6);
  tcase_add_test(tc1_1, s21_printf_g_7);
  tcase_add_test(tc1_1, s21_printf_g_8);
  tcase_add_test(tc1_1, s21_printf_g_9);
  tcase_add_test(tc1_1, s21_printf_g_10);
  tcase_add_test(tc1_1, s21_printf_g_11);
  tcase_add_test(tc1_1, s21_printf_g_12);
  tcase_add_test(tc1_1, s21_printf_g_13);
  tcase_add_test(tc1_1, s21_printf_g_14);
  tcase_add_test(tc1_1, s21_printf_g_15);
  tcase_add_test(tc1_1, s21_printf_g_16);
  tcase_add_test(tc1_1, s21_printf_g_17);
  tcase_add_test(tc1_1, s21_printf_g_18);
  tcase_add_test(tc1_1, s21_printf_g_19);
  tcase_add_test(tc1_1, s21_printf_g_20);
  tcase_add_test(tc1_1, s21_printf_g_21);
  tcase_add_test(tc1_1, s21_printf_G_1);
  tcase_add_test(tc1_1, s21_printf_G_2);
  tcase_add_test(tc1_1, s21_printf_G_3);
  tcase_add_test(tc1_1, s21_printf_G_4);
  tcase_add_test(tc1_1, s21_printf_G_5);
  tcase_add_test(tc1_1, s21_printf_G_6);
  tcase_add_test(tc1_1, s21_printf_G_7);
  tcase_add_test(tc1_1, s21_printf_G_8);
  tcase_add_test(tc1_1, s21_printf_G_9);
  tcase_add_test(tc1_1, s21_printf_G_10);
  tcase_add_test(tc1_1, s21_printf_G_11);
  tcase_add_test(tc1_1, s21_printf_G_12);
  tcase_add_test(tc1_1, s21_printf_f_1);
  tcase_add_test(tc1_1, s21_printf_f_2);
  tcase_add_test(tc1_1, s21_printf_f_3);
  tcase_add_test(tc1_1, s21_printf_f_4);
  tcase_add_test(tc1_1, s21_printf_f_5);
  tcase_add_test(tc1_1, s21_printf_f_6);
  tcase_add_test(tc1_1, s21_printf_f_7);
  tcase_add_test(tc1_1, s21_printf_f_8);
  tcase_add_test(tc1_1, s21_printf_f_9);
  tcase_add_test(tc1_1, s21_printf_f_10);
  tcase_add_test(tc1_1, s21_printf_f_11);
  tcase_add_test(tc1_1, s21_printf_f_12);
  tcase_add_test(tc1_1, s21_printf_f_13);
  tcase_add_test(tc1_1, s21_printf_f_14);
  tcase_add_test(tc1_1, s21_printf_f_15);
  tcase_add_test(tc1_1, s21_printf_f_16);
  tcase_add_test(tc1_1, s21_printf_f_17);
  tcase_add_test(tc1_1, s21_printf_f_18);
  tcase_add_test(tc1_1, s21_printf_f_19);
  tcase_add_test(tc1_1, s21_printf_f_20);
  tcase_add_test(tc1_1, s21_printf_f_21);
  tcase_add_test(tc1_1, s21_printf_f_22);
  tcase_add_test(tc1_1, s21_printf_f_23);
  tcase_add_test(tc1_1, s21_printf_f_24);
  tcase_add_test(tc1_1, s21_printf_f_25);
  tcase_add_test(tc1_1, s21_printf_f_26);
  tcase_add_test(tc1_1, s21_printf_f_27);
  tcase_add_test(tc1_1, s21_printf_f_28);
  tcase_add_test(tc1_1, s21_printf_f_29);
  tcase_add_test(tc1_1, s21_printf_f_30);
  tcase_add_test(tc1_1, s21_printf_f_31);
  tcase_add_test(tc1_1, s21_printf_f_32);
  tcase_add_test(tc1_1, s21_printf_f_33);
  tcase_add_test(tc1_1, s21_printf_f_34);
  tcase_add_test(tc1_1, s21_printf_f_35);
  tcase_add_test(tc1_1, s21_printf_f_36);

  return tc1_1;
}
