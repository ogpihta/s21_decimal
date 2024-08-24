#include "../../s21_decimal.h"
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  long_decimal dst_1 = {};
  if (src < 0) {
    // Устанавливаем знак
    set_sign(&dst_1, 1);
    src = (-1) * src;
  }
  // Заполняем переменную типа long_decimal и конвертируем ее в s21_decimal
  dst_1.bits[0] = src;
  from_long_decimal(dst_1, dst);
  return 0;
}