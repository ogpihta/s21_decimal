#include "../../s21_test.h"

START_TEST(is_greater_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(5, &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(is_greater_test_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(10, &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(is_greater_test_3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_from_int_to_decimal(5, &value_1);
  s21_from_int_to_decimal(10, &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

Suite *test_is_greater() {
  Suite *suite = suite_create("is_greater");
  TCase *tcase = tcase_create("is_greater_tcase");

  tcase_add_test(tcase, is_greater_test_1);
  tcase_add_test(tcase, is_greater_test_2);
  tcase_add_test(tcase, is_greater_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}