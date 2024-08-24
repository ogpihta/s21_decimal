#include "../../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  long_decimal val_1 = {}, val_2 = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  return is_less_long(val_1, val_2);
}

int is_less_long(long_decimal val_1, long_decimal val_2) {
  to_same_exp(&val_1, &val_2);
  int result = FALSE;
  int sign_1 = get_sign(val_1), sign_2 = get_sign(val_2);
  if (sign_1 != sign_2 && !(is_zero(val_1) && is_zero(val_2)))
    result = sign_1;
  else {
    int idx = 5;
    while (idx >= 0 && val_1.bits[idx] == val_2.bits[idx]) idx--;
    if (idx >= 0) {
      result = val_1.bits[idx] < val_2.bits[idx];
      if (sign_1 && sign_2) result = 1 - result;
    }
  }
  return result;
}
