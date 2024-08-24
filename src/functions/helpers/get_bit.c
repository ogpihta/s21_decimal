#include "../../s21_decimal.h"
// Определяем значение выбранного бита
unsigned int get_bit(long_decimal value, unsigned int index) {
  // Находим бит
  int bit = 5 - index / 32;
  // Определяем позицию внутри бита
  int pos = 31 - index % 32;
  // Функция вернет единицу, если выбранный бит на выбранной позиции не равен
  // нулю
  return (value.bits[bit] & (1 << pos)) != 0;
}
