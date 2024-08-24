#include "../../s21_decimal.h"
// DOES NOT WORK

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  long_decimal val_1 = {}, val_2 = {}, res = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  unsigned int sign = get_sign(val_1) != get_sign(val_2), error = 0;
  unsigned int exp = get_exp(val_2);
  set_sign(&val_1, 0);
  set_sign(&val_2, 0);
  set_exp(&val_2, 0);

  int addition_power = 0;

  while (addition_power < 28) {
    mul_by_ten(&val_1);
    addition_power++;
  }

  long_decimal tmp = {};
  for (int i = 0; i < 192; i++) {
    left_shift(&res);
    left_shift(&tmp);
    set_bit(&tmp, 191, get_bit(val_1, i));

    if (is_greater_or_equal_long(tmp, val_2)) {
      long_decimal buffer = {};
      sub_long(tmp, val_2, &buffer);
      res.bits[0] += 1;
      decimal_copy(&tmp, buffer);
    }
  }

  long_decimal res1 = {};
  decimal_copy(&res1, res);

  while (div_by_ten(&res) == 0 && addition_power > 0) {
    addition_power--;
    decimal_copy(&res1, res);
  }

  int x = (get_exp(val_1) + addition_power - exp) * -1;
  for (int i = 0; i < x; i++) {
    mul_by_ten(&res1);
    set_exp(&res1, 0);
  }
  if (x < 0) set_exp(&res1, get_exp(val_1) + addition_power - exp);
  set_sign(&res1, sign);
  decimal_copy(&res, res1);

  if (is_zero(val_2)) {
    error = 3;
    for (int i = 0; i < 4; i++) result->bits[i] = 0;
  } else
    error = from_long_decimal(res, result);
  return error;
}