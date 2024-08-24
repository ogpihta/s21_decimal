#include "../../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  long_decimal val_1 = {}, val_2 = {}, res = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  sub_long(val_1, val_2, &res);
  return from_long_decimal(res, result);
}

void sub_long(long_decimal val_1, long_decimal val_2, long_decimal *result) {
  // Если знак 2 числа отриц, меняем и вызываем сумму
  if (get_sign(val_2) == 1) {
    set_sign(&val_2, 0);
    add_long(val_1, val_2, result);
    // Если знак 1 числа отриц, меняем и вызываем сумму и возвращаем исходный
    // знак
  } else if (get_sign(val_1) == 1) {
    set_sign(&val_1, 0);
    add_long(val_2, val_1, result);
    set_sign(result, 1);
  } else {
    // Выравниваем экспоненты
    to_same_exp(&val_1, &val_2);
    // Если val2 > val1 меняем числа местами
    if (is_greater_long(val_2, val_1)) {
      long_decimal buf = val_1;
      val_1 = val_2;
      val_2 = buf;
      set_sign(result, 1);
    }
    // Аналогично сумме
    long ost = 0;
    for (int i = 0; i < 6; i++) {
      long diff = (long)val_1.bits[i] - (long)val_2.bits[i] - ost;
      if (diff < 0) {
        diff += UINT_MAX + 1;
        ost = 1;
      } else
        ost = 0;
      result->bits[i] = diff;
    }
    set_exp(result, get_exp(val_1));
  }
}
