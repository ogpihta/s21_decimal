#include "../../s21_decimal.h"
// Умножение числа на 10
void mul_by_ten(long_decimal *value) {
  // Инициализируем 3 переменные
  long_decimal tmp1 = {}, tmp2 = {}, result = {};
  // Копируем в tmp1 и tmp2 значения исходного числа value
  decimal_copy(&tmp1, *value);
  decimal_copy(&tmp2, *value);
  // Дважды сдвигаем tmp1 влево, что означает умножение числа tmp1 на 4
  left_shift(&tmp1);
  left_shift(&tmp1);
  // Складываем tmp1 и tmp2
  add_long(tmp1, tmp2, &result);
  // Сдвигаем результат суммы влево (умножаем его на 2)
  left_shift(&result);
  // Допустим tmp1 = 1, tmp2 = 1, tmp1 * 4 = 4, tmp2 + tmp1 = 5(result), result
  // * 2 = 10 Общий вид tmp1 * 10 = 2 * (tmp1 * 4 + tmp2)
  decimal_copy(value, result);
}
