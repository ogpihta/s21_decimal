#include "../../s21_decimal.h"
// decimal * -1
int s21_negate(s21_decimal value, s21_decimal *result) {
  int err = OK;
  if (!result)
    err = NOT_OK;
  else {
    long_decimal val = {{}, 0};
    to_long_decimal(value, &val);
    int sign = get_sign(val);
    set_sign(&val, 1 - sign);
    err = from_long_decimal(val, result);
  }
  return err;
}
