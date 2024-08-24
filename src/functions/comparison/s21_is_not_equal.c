#include "../../s21_decimal.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  long_decimal val_1 = {}, val_2 = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  return !is_equal_long(val_1, val_2);
}
