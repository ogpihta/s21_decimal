#include "../../s21_decimal.h"
// Установка экспоненты
void set_exp(long_decimal *decimal, unsigned int value) {
  // Побитовый сдвиг на 16, чтобы оказаться в окрестности битов экспоненты
  // (16-23)
  value <<= 16;
  // Получение знака из decimal. И сложение его с степенью экспоненты (value)
  decimal->stuff_bit = (get_sign(*decimal) << 31) + value;
}
