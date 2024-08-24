#include "../../s21_decimal.h"
// Установка знака
void set_sign(long_decimal *src, unsigned int value) {
  // Если value = 1, то сдвиг 1 на 31 и побитовая ИЛИ
  if (value == 1) {
    src->stuff_bit |= (1u << 31);
  }
  // Если value = 0, то сдвиг не(1) на 31 и побитовая И
  if (value == 0) {
    src->stuff_bit &= ~(1u << 31);
  }
}
