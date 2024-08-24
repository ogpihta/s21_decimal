#include "../../s21_decimal.h"

void decimal_copy(long_decimal *first, long_decimal second) {
  for (int i = 0; i < 6; i++) {
    first->bits[i] = second.bits[i];
  }
  first->stuff_bit = second.stuff_bit;
}
