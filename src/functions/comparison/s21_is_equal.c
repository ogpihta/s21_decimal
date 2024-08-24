#include "../../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  long_decimal val_1 = {}, val_2 = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  return is_equal_long(val_1, val_2);
}

int is_equal_long(long_decimal val_1, long_decimal val_2) {
  int result = TRUE;
  to_same_exp(&val_1, &val_2);

  for (int i = 0; i < 6; i++) {
    if (val_1.bits[i] != val_2.bits[i]) {
      result = FALSE;
      break;
    }
  }
  return result;
}
