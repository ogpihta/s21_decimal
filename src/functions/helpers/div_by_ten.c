#include "../../s21_decimal.h"
// Функция деления на 10
int div_by_ten(long_decimal *value) {
  long_decimal result = {};
  unsigned int tmp = 0;
  // Проходимся по всем битам long_decimal
  for (int i = 0; i < 192; i++) {
    tmp <<= 1;
    tmp += get_bit(*value, i);
    left_shift(&result);
    // Если tmp больше 10, присваиваем tmp = 0 и
    if (tmp >= 10) {
      tmp -= 10;
      result.bits[0] += 1;
    }
  }
  decimal_copy(value, result);
  // Возвращаем остаток от деления
  return tmp;
}
