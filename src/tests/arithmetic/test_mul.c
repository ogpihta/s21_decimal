#include "../../s21_test.h"

void test_mult(s21_decimal value_1, s21_decimal value_2,
               s21_decimal actual_result) {
  s21_decimal result;
  s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, actual_result), 1);
}

START_TEST(mul_test_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};
  s21_from_int_to_decimal(10, &value_1);
  s21_from_int_to_decimal(5, &value_2);
  s21_from_int_to_decimal(50, &supposed_result);

  s21_mul(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(mul_test_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};
  s21_from_int_to_decimal(0, &supposed_result);

  s21_mul(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(mul_test_3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(50, &value_1);
  s21_from_int_to_decimal(-10, &value_2);
  s21_from_int_to_decimal(-500, &supposed_result);

  s21_mul(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(mul_test_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_int_to_decimal(-50, &value_1);
  s21_from_int_to_decimal(10, &value_2);
  s21_from_int_to_decimal(-500, &supposed_result);

  s21_mul(value_1, value_2, &actual_result);

  ck_assert_uint_eq(supposed_result.bits[0], actual_result.bits[0]);
  ck_assert_uint_eq(supposed_result.bits[1], actual_result.bits[1]);
  ck_assert_uint_eq(supposed_result.bits[2], actual_result.bits[2]);
  ck_assert_uint_eq(supposed_result.bits[3], actual_result.bits[3]);
}
END_TEST

START_TEST(mul_test_5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal supposed_result = {0};
  s21_decimal actual_result = {0};

  s21_from_float_to_decimal(4.6, &value_1);
  s21_from_float_to_decimal(460, &value_2);
  s21_from_float_to_decimal(2116.0, &supposed_result);
  s21_mul(value_1, value_2, &actual_result);
  float bruh = 0;
  float bruh2 = 0;
  s21_from_decimal_to_float(actual_result, &bruh);
  s21_from_decimal_to_float(supposed_result, &bruh2);
  ck_assert_float_eq(bruh, bruh2);
}
END_TEST

START_TEST(mul_test_6) {
  // 79228162514264.1
  s21_decimal value_1 = {{0x70D42571, 0x2D093, 0x0, 0x10000}};
  // 78228162514264.5
  s21_decimal value_2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
  // 6197873572872410706900970254.4
  s21_decimal actual_result = {{0x7F6C2E90, 0x3FD777DD, 0xC8439BCC, 0x10000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_7) {
  // 79228162514265.1
  s21_decimal value_1 = {{0x70D4257B, 0x2D093, 0x0, 0x10000}};
  // 78228162514264.5
  s21_decimal value_2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
  // 6197873572872488935063484519.0
  s21_decimal actual_result = {{0xA1CDB406, 0x3FDA3F58, 0xC8439BCC, 0x10000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_8) {
  // 5.0
  s21_decimal value_1 = {{0x32, 0x0, 0x0, 0x10000}};
  // 4.5
  s21_decimal value_2 = {{0x2D, 0x0, 0x0, 0x10000}};
  // 22.50
  s21_decimal actual_result = {{0x8CA, 0x0, 0x0, 0x20000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_9) {
  // 79228162.5
  s21_decimal value_1 = {{0x2F394219, 0x0, 0x0, 0x10000}};
  // 78228162.5555555555555
  s21_decimal value_2 = {{0xB20798E3, 0x6856A1BC, 0x2A, 0xD0000}};
  // 6197873575027970.8333289317688
  s21_decimal actual_result = {{0x34C52538, 0x6AFC5902, 0xC8439BCD, 0xD0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_10) {
  // -7.000000000000025
  s21_decimal value_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -2.00000000000005
  s21_decimal value_2 = {{0x20F48005, 0xB5E6, 0x0, 0x800E0000}};
  // 14.000000000000400000000000001
  s21_decimal actual_result = {{0xF1E90001, 0xBD686F20, 0x2D3C8750, 0x1B0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_11) {
  // -7.000000000000025
  s21_decimal value_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.0000000000005
  s21_decimal value_2 = {{0x5, 0x0, 0x0, 0x800D0000}};
  // 0.0000000000035000000000000125
  s21_decimal actual_result = {{0x8723807D, 0x7C5850, 0x0, 0x1C0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_12) {
  // -7.000000000000025
  s21_decimal value_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.000000000000005
  s21_decimal value_2 = {{0x5, 0x0, 0x0, 0x800F0000}};
  // 0.0000000000000350000000000001
  s21_decimal actual_result = {{0xB9ABE001, 0x13E52, 0x0, 0x1C0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_13) {
  // 7.9228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.00000
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x50000}};
  // 0
  s21_decimal actual_result = {{0x0, 0x0, 0x0, 0x0}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_14) {
  // 7.9228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7.8228162514264337593543950335
  s21_decimal value_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x1C0000}};
  // 61.978735728724164262422454727
  s21_decimal actual_result = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x1B0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_15) {
  // 7.9228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.8228162514264337593543950335
  s21_decimal value_2 = {{0x4F63FFFF, 0xBB0D25CF, 0x1A962D2F, 0x801C0000}};
  // -6.5190219687391279469416894926
  s21_decimal actual_result = {
      {0x23B23CAE, 0xEC60363A, 0xD2A415FA, 0x801C0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_16) {
  // -7.000000000000025
  s21_decimal value_1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.00000000000005
  s21_decimal value_2 = {{0x5, 0x0, 0x0, 0x800E0000}};
  // 0.0000000000003500000000000012
  s21_decimal actual_result = {{0x40B6C00C, 0xC6F3B, 0x0, 0x1C0000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_17) {
  // -7922816251426.4337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // 78228162514264.337593543950335
  s21_decimal value_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xF0000}};
  // -619787357287241642624224547.27
  s21_decimal actual_result = {
      {0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80020000}};

  test_mult(value_1, value_2, actual_result);
}

START_TEST(mul_test_18) {
  // -79228162514264.337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // 782281625142643.37593543950335
  s21_decimal value_2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
  // -61978735728724164262422454727
  s21_decimal actual_result = {
      {0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80000000}};

  test_mult(value_1, value_2, actual_result);
}

Suite *test_mul() {
  Suite *suite = suite_create("mul");
  TCase *tcase = tcase_create("mul_tcase");

  tcase_add_test(tcase, mul_test_1);
  tcase_add_test(tcase, mul_test_2);
  tcase_add_test(tcase, mul_test_3);
  tcase_add_test(tcase, mul_test_4);
  tcase_add_test(tcase, mul_test_5);
  tcase_add_test(tcase, mul_test_6);
  tcase_add_test(tcase, mul_test_7);
  tcase_add_test(tcase, mul_test_8);
  tcase_add_test(tcase, mul_test_9);
  tcase_add_test(tcase, mul_test_10);
  tcase_add_test(tcase, mul_test_11);
  tcase_add_test(tcase, mul_test_12);
  tcase_add_test(tcase, mul_test_13);
  tcase_add_test(tcase, mul_test_14);
  tcase_add_test(tcase, mul_test_15);
  tcase_add_test(tcase, mul_test_16);
  tcase_add_test(tcase, mul_test_17);
  tcase_add_test(tcase, mul_test_18);

  suite_add_tcase(suite, tcase);
  return suite;
}
