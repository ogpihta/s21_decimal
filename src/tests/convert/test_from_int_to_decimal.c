#include "../../s21_test.h"

START_TEST(from_int_to_decimal_test_1) {
  s21_decimal value = {0};
  int a = -10;

  s21_from_int_to_decimal(a, &value);

  ck_assert_uint_eq(value.bits[0], -a);
  ck_assert_uint_eq(value.bits[3] >> 31, 1);
}
END_TEST

START_TEST(from_int_to_decimal_test_2) {
  s21_decimal value = {0};
  int a = 10;

  s21_from_int_to_decimal(a, &value);

  ck_assert_uint_eq(value.bits[0], a);
  ck_assert_uint_eq(value.bits[3] >> 31, 0);
}
END_TEST

START_TEST(from_int_to_decimal_test_3) {
  s21_decimal value = {0};
  int res = 0;
  int tmp = -10;
  s21_from_int_to_decimal(tmp, &value);
  s21_from_decimal_to_int(value, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

Suite *test_from_int_to_decimal() {
  Suite *suite = suite_create("from_int_to_decimal");
  TCase *tcase = tcase_create("from_int_to_decimal_tcase");

  tcase_add_test(tcase, from_int_to_decimal_test_1);
  tcase_add_test(tcase, from_int_to_decimal_test_2);
  tcase_add_test(tcase, from_int_to_decimal_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}
