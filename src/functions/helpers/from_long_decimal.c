#include <stdio.h>
#include <string.h>

#include "../../s21_decimal.h"

long get_upper_bit_sum(long_decimal src);
// Функция перехода из переменной типа long_decimal в тип decimal
int from_long_decimal(long_decimal src, s21_decimal *result) {
  // Изначально ошибка = 0, берем знак и экспоненту из long_decimal
  int error = OK, sign = get_sign(src), exp = get_exp(src), ost = 5;
  // Устанавливаем положительный знак для удобства обработки
  set_sign(&src, 0);
  // Если сумма старших битов и эксп больше нуля или экспонента больше 28
  while ((get_upper_bit_sum(src) > 0 && exp > 0) || exp > 28) {
    // Делим число на 10 и записываем остаток, уменьшая экспоненту
    ost = div_by_ten(&src);
    exp--;
    // Проверка на нечетность младшего бита
    if (ost >= 5 && src.bits[0] % 2 == 1) {
      long_decimal one = {{1, 0, 0, 0, 0, 0}, exp};
      add_long(src, one, &src);
    }
  }
  // Если старших битов не осталось заполняем переменную типа s21_decimal
  if (get_upper_bit_sum(src) == 0) {
    for (int i = 0; i < 3; i++) result->bits[i] = src.bits[i];
    set_sign(&src, sign);
    set_exp(&src, exp);
    result->bits[3] = src.stuff_bit;
  } else {
    // Если ошибка заполянем переменную нулями и возвращаем ошибку
    error = 1 + sign;
    for (int i = 0; i < 4; i++) result->bits[i] = 0;
  }
  return error;
}
// Функция суммы старших битов из переменной long_decimal
long get_upper_bit_sum(long_decimal src) {
  long tmp = 0;
  for (int i = 3; i < 6; i++) tmp += src.bits[i];
  // Возвращаем сумму старших битов
  return tmp;
}
