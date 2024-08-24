#include "../../s21_decimal.h"
// Тот же преобразователь в инт(без проверки на INT_MAX)
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  long_decimal src_1 = {};
  to_long_decimal(src, &src_1);
  int flag = 0, exp = get_exp(src_1);
  double buffer = 0;
  for (int i = 191; i >= 0; i--) {
    buffer += get_bit(src_1, i) * pow(2, 191 - i);
  }
  buffer /= pow(10, exp);
  if (get_sign(src_1)) {
    buffer *= (-1);
  }
  *dst = buffer;
  return flag;
}