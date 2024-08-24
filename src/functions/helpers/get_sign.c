#include "../../s21_decimal.h"
// Поиска знака
unsigned int get_sign(long_decimal value) {
  // Возвращает 1 если число отрицательное и 0 соответсвенно
  return value.stuff_bit >> 31;
}
