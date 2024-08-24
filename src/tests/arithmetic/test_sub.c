#include "../../s21_test.h"

START_TEST(sub_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(5, &value_2);
  s21_from_int_to_decimal(5, &supposed_result);

  s21_sub(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(sub_test_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX}};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(0, &supposed_result);

  s21_sub(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(sub_test_3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(50, &value_1);
  s21_from_int_to_decimal(-10, &value_2);
  s21_from_int_to_decimal(60, &supposed_result);

  s21_sub(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(sub_test_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(-50, &value_1);
  s21_from_int_to_decimal(10, &value_2);
  s21_from_int_to_decimal(-60, &supposed_result);

  s21_sub(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(sub_test_5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(5000, &value_1);
  s21_from_int_to_decimal(10, &value_2);
  s21_from_int_to_decimal(4990, &supposed_result);

  s21_sub(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

Suite *test_sub() {
  Suite *suite = suite_create("sub");
  TCase *tcase = tcase_create("sub_tcase");

  tcase_add_test(tcase, sub_test_1);
  tcase_add_test(tcase, sub_test_2);
  tcase_add_test(tcase, sub_test_3);
  tcase_add_test(tcase, sub_test_4);
  tcase_add_test(tcase, sub_test_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
