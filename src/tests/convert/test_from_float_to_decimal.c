#include "../../s21_test.h"

START_TEST(from_float_to_decimal_test_1) {
  s21_decimal value = {0};
  float a = 10.1, a_bits = 1010000;

  s21_from_float_to_decimal(a, &value);

  ck_assert_uint_eq(value.bits[0], a_bits);
}
END_TEST

START_TEST(from_float_to_decimal_test_2) {
  s21_decimal value = {0};
  float a = 1e-29, a_bits = 0;

  s21_from_float_to_decimal(a, &value);

  ck_assert_uint_eq(value.bits[0], a_bits);
}
END_TEST

START_TEST(from_float_to_decimal_test_3) {
  s21_decimal value = {0};
  float a = -10.1, a_bits = 1010000;

  s21_from_float_to_decimal(a, &value);

  ck_assert_uint_eq(value.bits[0], a_bits);
  ck_assert_uint_eq(value.bits[3] >> 31, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_4) {
  s21_decimal value = {0};
  float a = 1e7, a_bits = 10000000;
  s21_from_float_to_decimal(a, &value);
  s21_from_decimal_to_float(value, &a);

  ck_assert_uint_eq(value.bits[0], a_bits);
}
END_TEST

Suite *test_from_float_to_decimal() {
  Suite *suite = suite_create("from_float_to_decimal");
  TCase *tcase = tcase_create("from_float_to_decimal_tcase");

  tcase_add_test(tcase, from_float_to_decimal_test_1);
  tcase_add_test(tcase, from_float_to_decimal_test_2);
  tcase_add_test(tcase, from_float_to_decimal_test_3);
  tcase_add_test(tcase, from_float_to_decimal_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}
