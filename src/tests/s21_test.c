#include "../s21_test.h"

void print_info(Suite *suite) {
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    printf("\033[31mFAILED\n");
  } else {
    printf("\033[32mSUCCESS\n");
  }
}

int main() {
  Suite *suites[] = {test_add(),
                     test_sub(),
                     test_mul(),
                     test_div(),

                     test_is_equal(),
                     test_is_greater_or_equal(),
                     test_is_greater(),
                     test_is_less_or_equal(),
                     test_is_less(),
                     test_is_not_equal(),

                     test_from_int_to_decimal(),
                     test_from_float_to_decimal(),
                     test_from_decimal_to_int(),
                     test_from_decimal_to_float(),

                     test_floor(),
                     test_round(),
                     test_truncate(),
                     test_negate(),
                     NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    printf("\033[0m");
    print_info(suites[i]);
  }
  printf("\033[0m");
  return 0;
}
