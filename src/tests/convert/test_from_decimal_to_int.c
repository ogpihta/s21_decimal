#include "../../s21_test.h"

START_TEST(from_decimal_to_int_test_1) {
  s21_decimal value = {0};
  int num = 0;
  s21_from_int_to_decimal(5, &value);
  s21_from_decimal_to_int(value, &num);
  ck_assert_int_eq(5, num);
}
END_TEST

START_TEST(from_decimal_to_int_test_2) {
  s21_decimal value = {{0, 1, 0, 0}};
  int num;
  ck_assert_int_eq(1, s21_from_decimal_to_int(value, &num));
}
END_TEST

Suite *test_from_decimal_to_int() {
  Suite *suite = suite_create("decimal_to_int");
  TCase *tcase = tcase_create("decimal_to_int_tcase");

  tcase_add_test(tcase, from_decimal_to_int_test_1);
  tcase_add_test(tcase, from_decimal_to_int_test_2);

  suite_add_tcase(suite, tcase);
  return suite;
}
