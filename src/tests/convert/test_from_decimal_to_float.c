#include "../../s21_test.h"

START_TEST(from_decimal_to_float_test_1) {
  s21_decimal value = {0};
  float num = 0;
  s21_from_float_to_decimal(5.5, &value);
  s21_from_decimal_to_float(value, &num);
  ck_assert_float_eq(5.5, num);
}
END_TEST

START_TEST(from_decimal_to_float_test_2) {
  s21_decimal value = {0};
  float num = 0;
  s21_from_float_to_decimal(-5.5, &value);
  s21_from_decimal_to_float(value, &num);
  ck_assert_float_eq(-5.5, num);
}
END_TEST

Suite *test_from_decimal_to_float() {
  Suite *suite = suite_create("decimal_to_float");
  TCase *tcase = tcase_create("decimal_to_float_tcase");

  tcase_add_test(tcase, from_decimal_to_float_test_1);
  tcase_add_test(tcase, from_decimal_to_float_test_2);

  suite_add_tcase(suite, tcase);
  return suite;
}
