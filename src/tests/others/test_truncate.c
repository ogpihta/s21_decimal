#include "../../s21_test.h"

START_TEST(truncate_test_1) {
  s21_decimal value = {{1011, 0, 0, 2 << 16}};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(10, &supposed_result);

  s21_truncate(value, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(truncate_test_2) {
  s21_decimal value = {0};
  s21_decimal *result = NULL;
  ck_assert_int_eq(s21_truncate(value, result), NOT_OK);
}
END_TEST

Suite *test_truncate() {
  Suite *suite = suite_create("truncate");
  TCase *tcase = tcase_create("truncate_tcase");

  tcase_add_test(tcase, truncate_test_1);
  tcase_add_test(tcase, truncate_test_2);
  suite_add_tcase(suite, tcase);
  return suite;
}