#include "../../s21_test.h"

START_TEST(add_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(5, &value_1);
  s21_from_int_to_decimal(5, &value_2);
  s21_from_int_to_decimal(10, &supposed_result);

  s21_add(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(add_test_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 123;
  value_2.bits[0] = 123;

  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(246, result.bits[0]);
}
END_TEST

START_TEST(add_test_3) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{1, 0, 0, 28 << 16}};
  s21_decimal result = {0};

  ck_assert_uint_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_uint_eq(value_1.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_1.bits[1], result.bits[1]);
  ck_assert_uint_eq(value_1.bits[2], result.bits[2]);
  ck_assert_uint_eq(value_1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(add_test_4) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{1, 0, 0, 28 << 16}};
  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_uint_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_uint_eq(value_1.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_1.bits[1], result.bits[1]);
  ck_assert_uint_eq(value_1.bits[2], result.bits[2]);
  ck_assert_uint_eq(value_1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(add_test_5) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal result = {0};

  ck_assert_uint_eq(1, s21_add(value_1, value_2, &result));
  ck_assert_uint_eq(0, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

START_TEST(add_test_6) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 2147483648}};
  s21_decimal result = {0};

  ck_assert_uint_eq(0, s21_add(value_1, value_2, &result));
  ck_assert_uint_eq(0, result.bits[0]);
  ck_assert_uint_eq(0, result.bits[1]);
  ck_assert_uint_eq(0, result.bits[2]);
  ck_assert_uint_eq(0, result.bits[3]);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(-5, &value_1);
  s21_from_int_to_decimal(3, &value_2);
  s21_from_int_to_decimal(-2, &supposed_result);

  s21_add(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

Suite *test_add() {
  Suite *suite = suite_create("add");
  TCase *tcase = tcase_create("add_tcase");

  tcase_add_test(tcase, add_test_1);
  tcase_add_test(tcase, add_test_2);
  tcase_add_test(tcase, add_test_3);
  tcase_add_test(tcase, add_test_4);
  tcase_add_test(tcase, add_test_5);
  tcase_add_test(tcase, add_test_6);
  tcase_add_test(tcase, add_test_7);

  suite_add_tcase(suite, tcase);
  return suite;
}
