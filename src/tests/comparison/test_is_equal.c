#include "../../s21_test.h"

START_TEST(is_equal_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(5, &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(is_equal_test_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(10, &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

Suite *test_is_equal() {
  Suite *suite = suite_create("is_equal");
  TCase *tcase = tcase_create("is_equal_tcase");

  tcase_add_test(tcase, is_equal_test_1);
  tcase_add_test(tcase, is_equal_test_2);

  suite_add_tcase(suite, tcase);
  return suite;
}
