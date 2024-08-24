#include "../../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  long_decimal val_1 = {}, val_2 = {}, res = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  int new_exp = get_exp(val_1) + get_exp(val_2);
  for (int i = 191; i >= 0; i--) {
    int shift = 191 - i;
    if (get_bit(val_2, i)) {
      long_decimal addition = {};
      decimal_copy(&addition, val_1);
      for (int j = 0; j < shift; j++) {
        left_shift(&addition);
      }
      add_long(addition, res, &res);
    }
  }
  set_exp(&res, new_exp);
  set_sign(&res, (get_sign(val_1) + get_sign(val_2)) == 1);
  return from_long_decimal(res, result);
}