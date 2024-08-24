#include "../../s21_decimal.h"
void exp_low(long_decimal *value);
// Функция приведения exp к одному виду
void to_same_exp(long_decimal *value_1, long_decimal *value_2) {
  // Приводим экспоненты к допустимому диапозону
  exp_low(value_1);
  exp_low(value_2);
  // Вычисляем разницу экспонент
  int diff = get_exp(*value_1) - get_exp(*value_2);
  // По стандарту *tmp = value_2
  long_decimal *tmp = value_2;
  // Если экспонента первого числа меньше второго
  if (diff < 0) {
    // Избавляемся от отрициалеьного diff
    diff *= -1;
    // Меняем tmp на другое число
    tmp = value_1;
  }
  // Приводим степени экспоненты к одному виду путем умножения меньшего числа на
  // 10 diff раз
  for (int i = 0; i < diff; i++) mul_by_ten(tmp);
  // Выставляем равные значения экспоненты
  set_exp(tmp, get_exp(*tmp) + diff);
}
// Функция понижения степени exp для long_decimal до нормального диапозона
void exp_low(long_decimal *value) {
  // Разница между экспонентой из *value и максимально допустимой степенью
  int diff = get_exp(*value) - 28;
  //
  if (diff > 0) {
    // Разница вне допустимого диапозона
    if (diff > 30) {
      set_zero(value);
      set_exp(value, 0);
    } else {
      // Если разница в пределах от 0 до 30 большее число делим diff раз
      for (int i = 0; i < diff; i++) {
        div_by_ten(value);
      }
      // Устанавливаем выровненное значение экспоненты
      set_exp(value, get_exp(*value) - diff);
    }
  }
}
