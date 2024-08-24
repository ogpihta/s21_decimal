#include "../../s21_decimal.h"
// Проверка числа на ноль
int is_zero(long_decimal dec) {
  int z = 1;
  for (int i = 0; i < 6; i++) {
    if (dec.bits[i] != 0) {
      z = 0;
      break;
    }
  }
  // Возврат 0, если переменная ненулевая, 1 - нулевая.
  return z;
}
