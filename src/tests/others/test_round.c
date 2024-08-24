#include "../../s21_test.h"

START_TEST(round_test_1) {
  s21_decimal value = {{100, 0, 0, 1 << 16}};
  s21_decimal actual_result = {0};
  s21_decimal supposed_result = {0};
  s21_from_int_to_decimal(10, &supposed_result);

  s21_round(value, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(round_test_2) {
  s21_decimal value = {{101, 0, 0, (1 << 16) + (1 << 31)}};
  s21_decimal actual_result = {0};
  s21_decimal supposed_result = {{10, 0, 0, 1 << 31}};

  s21_round(value, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(round_test_3) {
  s21_decimal origin = {0};
  s21_decimal *result = NULL;
  ck_assert_int_eq(s21_round(origin, result), NOT_OK);
}
END_TEST

Suite *test_round() {
  Suite *suite = suite_create("round");
  TCase *tcase = tcase_create("round_tcase");

  tcase_add_test(tcase, round_test_1);
  tcase_add_test(tcase, round_test_2);
  tcase_add_test(tcase, round_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}