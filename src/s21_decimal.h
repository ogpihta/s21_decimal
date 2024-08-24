#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define TOO_LARGE_OR_INF 1
#define TOO_SMALL_OR_NEG_INF 2

#define OK 0
#define NOT_OK 1
#define TRUE 1
#define FALSE 0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  int exponent;
  int sign;
} info;

typedef struct {
  unsigned int bits[6];
  unsigned int stuff_bit;
} long_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void add_long(long_decimal val_1, long_decimal val_2, long_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void sub_long(long_decimal val_1, long_decimal val_2, long_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int is_less_long(long_decimal val_1, long_decimal val_2);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int is_greater_long(long_decimal val_1, long_decimal val_2);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int is_greater_or_equal_long(long_decimal val_1, long_decimal val_2);
int s21_is_equal(s21_decimal, s21_decimal);
int is_equal_long(long_decimal val_1, long_decimal val_2);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
void truncate_long(long_decimal val, long_decimal *res);
int s21_negate(s21_decimal value, s21_decimal *result);

// Функции хелперы
void set_exp(long_decimal *decimal, unsigned int value);
void set_zero(long_decimal *decimal);
void set_sign(long_decimal *src, unsigned int value);
void set_bit(long_decimal *src, unsigned int index, unsigned int value);

unsigned int get_exp(long_decimal value);
unsigned int get_bit(long_decimal value, unsigned int index);
unsigned int get_sign(long_decimal value);

int left_shift(long_decimal *value);

void mul_by_ten(long_decimal *value);
int div_by_ten(long_decimal *value);

int is_zero(long_decimal dec);
void decimal_copy(long_decimal *first, long_decimal second);

void to_long_decimal(s21_decimal src, long_decimal *result);
void to_same_exp(long_decimal *value_1, long_decimal *value_2);
int from_long_decimal(long_decimal src, s21_decimal *result);
#endif  // SRC_S21_DECIMAL_H_
