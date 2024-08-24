#include "../../s21_decimal.h"
// Возвращает целые цифры числа типа s21_decimal
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int err = OK;
  if (!result)
    err = NOT_OK;
  else {
    long_decimal val = {}, res = {};
    to_long_decimal(value, &val);
    truncate_long(val, &res);
    err += from_long_decimal(res, result);
  }
  return err;
}

void truncate_long(long_decimal val, long_decimal *res) {
  // Сохраняем значение экспоненты
  int exp = get_exp(val);
  set_zero(res);
  decimal_copy(res, val);
  // Делим число на 10 пока экспонента > 0
  while (exp-- > 0) div_by_ten(res);
  set_exp(res, 0);
  set_sign(res, get_sign(val));
}
