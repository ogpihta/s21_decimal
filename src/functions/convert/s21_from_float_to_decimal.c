#include "../../s21_decimal.h"

#define D_MIN 1e-28
#define D_MAX 79228162514264337593543950335.0

int get_string_exp(char *str);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  long_decimal dst_1 = {};

  int flag = 0, sign = 0;

  if (src < 0.0) {
    sign = 1;
    src *= -1;
  }
  // Если число NaN или бесконечность или находится вне допустимых пределов, то
  // флаг ошибки и зануление битов если число очень маленькое
  if ((isnan(src)) || (isinf(src)) || (src >= D_MAX) || (src < D_MIN)) {
    flag = 1;
    if (src < D_MIN)
      for (int i = 0; i < 4; i++) dst->bits[i] = 0;
  } else {
    // В противном случае преобразуем число в формате экспоненциальной записи,
    // например, (1.88е-23)
    char string[100];
    sprintf(string, "%e", src);
    // Проходимся по полученой строке и если символ не равен точки заполняем
    // число типа long_decimal
    for (int j = 0; j < 8; j++) {
      if (string[j] != '.') {
        mul_by_ten(&dst_1);
        long_decimal addition = {{string[j] - '0'}, 0};
        add_long(dst_1, addition, &dst_1);
      }
    }
    // Вычитаем из дефолтной экспоненты текущую
    int exp = get_string_exp(string), normal_exp = 6;

    normal_exp -= exp;
    // Если норм эксп меньше нуля, понижаем степень экспоненты и после цикла
    // устанавливаем ее равной нулю
    if (normal_exp < 0) {
      normal_exp *= -1;
      for (int i = 0; i < normal_exp; i++) {
        mul_by_ten(&dst_1);
      }
      normal_exp = 0;
    }
    // Устанавливаем у переменной типа long_decimal знак и экспоненту и
    // переводим в тип decimal
    set_sign(&dst_1, sign);
    set_exp(&dst_1, normal_exp);
    flag = from_long_decimal(dst_1, dst);
  }
  // Возвращаем флаг ошибки
  return flag;
}
// Поиск степень экспоненты из стринговой переменной (хранится в виде 1.12e-23)
int get_string_exp(char *str) {
  int result = 0, sign = 0, idx = 0;
  // Ходим по строке пока не находим символ е, если находим записываем знак и
  // степень экспоненты
  while (str[idx] != 'e') idx++;
  idx++;
  if (str[idx] == '-') sign = 1;
  result = (str[idx + 1] - '0') * 10 + (str[idx + 2] - '0');
  if (sign == 1) result *= -1;
  return result;
}
