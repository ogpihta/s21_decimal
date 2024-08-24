## Project Overview

Educational project **s21_decimal** from "School 21" by Sber. Implementation the `21_decimal.h` library in C. This library introduces a custom decimal type, essential for precise financial calculations where floating-point errors are unacceptable. The project involved understanding the binary representation of decimal numbers, implementing arithmetic operations, and ensuring accurate conversions and comparisons. Unit tests were conducted using the `Check` framework, with `Gcov` was employed to analyze test coverage.

## Key Results

- **Custom Decimal Type in C**: Implemented a decimal type with a 96-bit integer, a sign bit, and a scaling factor for precise financial calculations.
- **Arithmetic & Comparison Operators**: Developed key arithmetic operations (add, subtract, multiply, divide) and comparison operators for the decimal type.
- **Conversion Functions**: Created conversion functions between integers, floats, and the custom decimal type.
- **Bank Rounding**: Implemented bank rounding to handle cases where numbers exceed the decimal type's mantissa.
- **Unit Testing & Coverage**: Utilized the Check framework for unit testing and gcov for analyzing code coverage, ensuring the reliability of the implementation.

## Usage

**Build**:

1. clone this repository
2. `cd s21_decimmal/src`
3. `make all`

**Tests and coverage**:

1. clone this repository
2. `cd s21_decimmal/src`
3. `make test`
4. `make gcov_report`

## Binary representation

The binary representation of a Decimal number consists of a 1-bit sign, a 96-bit integer number, and a scaling factor that is used to divide the integer number and specify what portion of it is a decimal fraction. The scaling factor is implicitly the number 10 raised to an exponent between 0 and 28.

The Decimal number can be implemented as a four-element array of 32-bit signed integers (`int bits[4];`).

`bits[0]`, `bits[1]`, and `bits[2]` contain the low, middle, and high 32 bits of the 96-bit integer, respectively.

`bits[3]` contains the scaling factor and sign and consists of the following parts:
- Bits 0 through 15, the lower word, are unused and must be zero.
- Bits 16 to 23 must contain an exponent between 0 and 28, indicating the power of 10 to divide the integer.
- Bits 24 through 30 are unused and must be zero.
- Bit 31 contains the sign; 0 is positive and 1 is negative.


## Arithmetic Operators

| Operator name  | Operators | Function                                                                   |
| -------------- | --------- | -------------------------------------------------------------------------- |
| Addition       | +         | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Subtraction    | -         | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Multiplication | *         | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Division       | /         | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

The functions return the error code:
- 0 — OK;
- 1 — the number is too large or equal to infinity;
- 2 — the number is too small or equal to negative infinity;
- 3 — division by 0.

*Note on the numbers that do not fit into the mantissa:*
- *When getting numbers that do not fit into the mantissa during arithmetic operations, use bank rounding (for example, 79,228,162,514,264,337,593,543,950,335 — 0.6 = 79,228,162,514,264,337,593,543,950,334)*

## Comparison Operators

| Operator name            | Operators | Function                                              |
| ------------------------ | --------- | ----------------------------------------------------- |
| Less than                | <         | int s21_is_less(s21_decimal, s21_decimal)             |
| Less than or equal to    | <=        | int s21_is_less_or_equal(s21_decimal, s21_decimal)    |
| Greater than             | >         | int s21_is_greater(s21_decimal, s21_decimal)          |
| Greater than or equal to | >=        | int s21_is_greater_or_equal(s21_decimal, s21_decimal) |
| Equal to                 | ==        | int s21_is_equal(s21_decimal, s21_decimal)            |
| Not equal to             | !=        | int s21_is_not_equal(s21_decimal, s21_decimal)        |

## Convertors and parsers

| Convertor/parser | Function                                                   |
| ---------------- | ---------------------------------------------------------- |
| From int         | int s21_from_int_to_decimal(int src, s21_decimal *dst)     |
| From float       | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| To int           | int s21_from_decimal_to_int(s21_decimal src, int *dst)     |
| To float         | int s21_from_decimal_to_float(s21_decimal src, float *dst) |


## Other functions

| Description                                                                                                           | Function                                                 |
| --------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------- |
| Rounds a specified Decimal number to the closest integer toward negative infinity.                                    | int s21_floor(s21_decimal value, s21_decimal *result)    |
| Rounds a decimal value to the nearest integer.                                                                        | int s21_round(s21_decimal value, s21_decimal *result)    |
| Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Returns the result of multiplying the specified Decimal value by negative one.                                        | int s21_negate(s21_decimal value, s21_decimal *result)   |

