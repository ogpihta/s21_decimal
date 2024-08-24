#include "../../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  long_decimal val_1 = {}, val_2 = {}, res = {};
  to_long_decimal(value_1, &val_1);
  to_long_decimal(value_2, &val_2);
  add_long(val_1, val_2, &res);
  return from_long_decimal(res, result);
}

void add_long(long_decimal val_1, long_decimal val_2, long_decimal *result) {
  // Проверка на равенство знаков двух переменных
  if (get_sign(val_1) != get_sign(val_2)) {
    // Если 2 число отрицательное, меняем знак и вызываем функцию вычитания
    if (get_sign(val_2) == 1) {
      set_sign(&val_2, 0);
      sub_long(val_1, val_2, result);
      // Если 1 число отрицательное, меняем знак и вызываем функцию вычитания
    } else if (get_sign(val_1) == 1) {
      set_sign(&val_1, 0);
      sub_long(val_2, val_1, result);
    }
  } else {
    // Выравниваем экспоненты
    to_same_exp(&val_1, &val_2);
    int ost = 0;
    long mod = 1l << 32;
    // Пробегаем по битам, складываем числа(приводим их к long) и остаток типа
    // int
    for (int i = 0; i < 6; i++) {
      long sum = (long)val_1.bits[i] + (long)val_2.bits[i] + ost;
      // Вычисляем остаток
      ost = sum / mod;
      // Записываем результат деления суммы на модуль
      result->bits[i] = sum % mod;
    }
    // Устанавливаем экспоненты и знак для результата суммы
    set_exp(result, get_exp(val_1));
    set_sign(result, get_sign(val_1));
  }
}
