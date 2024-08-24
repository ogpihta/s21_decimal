#include "../../s21_decimal.h"
// Округляет Decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal *result) {
  int err = OK;
  if (!result)
    err = NOT_OK;
  else {
    long_decimal val = {}, res = {};
    to_long_decimal(value, &val);
    int sign = get_sign(val);

    long_decimal num1 = {{1}, 0};
    long_decimal num2 = {{5}, 0};
    set_exp(&num2, 1);

    long_decimal fract_value = {};
    set_sign(&val, 0);
    truncate_long(val, &res);
    sub_long(val, res, &fract_value);
    set_sign(&fract_value, 0);

    int check = is_greater_or_equal_long(fract_value, num2);
    if (check) add_long(res, num1, &res);
    set_sign(&res, sign);
    err = from_long_decimal(res, result);
  }
  return err;
}