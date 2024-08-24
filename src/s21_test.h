#ifndef SRC_S21_TEST_H
#define SRC_S21_TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

Suite *test_add();
Suite *test_sub();
Suite *test_mul();
Suite *test_div();

Suite *test_is_less();
Suite *test_is_less_or_equal();
Suite *test_is_greater();
Suite *test_is_greater_or_equal();
Suite *test_is_equal();
Suite *test_is_not_equal();

Suite *test_from_int_to_decimal();
Suite *test_from_float_to_decimal();
Suite *test_from_decimal_to_int();
Suite *test_from_decimal_to_float();

Suite *test_floor();
Suite *test_round();
Suite *test_truncate();
Suite *test_negate();

#endif  // SRC_S21_TEST_H
