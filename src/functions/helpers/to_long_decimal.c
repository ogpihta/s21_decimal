#include "../../s21_decimal.h"
// Функция перехода из типа decimal в long_decimal
void to_long_decimal(s21_decimal src, long_decimal *result) {
  // Зануляем переменную result
  set_zero(result);
  // Заполянем массив типа long_decimal битами из переменной типа decimal
  result->stuff_bit = src.bits[3];
  for (int i = 0; i < 3; i++) result->bits[i] = src.bits[i];
}
