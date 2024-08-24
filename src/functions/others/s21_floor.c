#include "../../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int err = OK;
  if (!result)
    err = NOT_OK;
  else {
    long_decimal val = {}, res = {};
    to_long_decimal(value, &val);
    set_zero(&res);
    long_decimal subt = {{1}, 0};
    truncate_long(val, &res);

    if (get_sign(val)) {
      set_sign(&res, 0);
      add_long(res, subt, &res);
      set_sign(&res, 1);
    }
    err = from_long_decimal(res, result);
  }
  return err;
}
