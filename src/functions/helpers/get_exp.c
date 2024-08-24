#include "../../s21_decimal.h"
// Поиск экспоненты
unsigned int get_exp(long_decimal value) {
  // В value.stuff_bit хранится экспонента числа
  unsigned int exp = value.stuff_bit;
  // Установка знака и переход биту от 16, так как 16-23 дожны хранить степень
  // экспоненты
  exp -= get_sign(value) << 31;
  exp >>= 16;
  return exp;
}
