#include "../../s21_test.h"

START_TEST(div_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(5, &value_2);
  s21_from_int_to_decimal(2, &supposed_result);

  s21_div(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(div_test_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};
  s21_from_int_to_decimal(0, &supposed_result);

  s21_div(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(div_test_3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(50, &value_1);
  s21_from_int_to_decimal(-10, &value_2);
  s21_from_int_to_decimal(-5, &supposed_result);

  s21_div(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(div_test_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(-50, &value_1);
  s21_from_int_to_decimal(10, &value_2);
  s21_from_int_to_decimal(-5, &supposed_result);

  s21_div(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(div_test_5) {
  s21_decimal value_1 = {{100, 0, 0, 1 << 16}};
  s21_decimal value_2 = {{100, 0, 0, 1 << 16}};
  s21_decimal actual_result = {0};
  s21_decimal supposed_result = {0};
  s21_from_int_to_decimal(1, &supposed_result);

  s21_div(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(div_test_6) {
  s21_decimal value_1 = {{101, 0, 0, (1 << 16) + (1 << 31)}};
  s21_decimal value_2 = {0};
  s21_decimal actual_result = {0};
  s21_div(value_1, value_2, &actual_result);

  ck_assert_int_eq(s21_div(value_1, value_2, &actual_result), 3);
}
END_TEST

START_TEST(div_test_7) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal result = {0};

  ck_assert_uint_eq(0, s21_div(value_1, value_2, &result));
  ck_assert_uint_eq(1, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

START_TEST(div_test_8) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  s21_from_float_to_decimal(1e-28, &value_2);
  ck_assert_uint_eq(1, s21_div(value_1, value_2, &result));
  ck_assert_uint_eq(0, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

Suite *test_div() {
  Suite *suite = suite_create("div");
  TCase *tcase = tcase_create("div_tcase");

  tcase_add_test(tcase, div_test_1);
  tcase_add_test(tcase, div_test_2);
  tcase_add_test(tcase, div_test_3);
  tcase_add_test(tcase, div_test_4);
  tcase_add_test(tcase, div_test_5);
  tcase_add_test(tcase, div_test_6);
  tcase_add_test(tcase, div_test_7);
  tcase_add_test(tcase, div_test_8);

  suite_add_tcase(suite, tcase);
  return suite;
}
