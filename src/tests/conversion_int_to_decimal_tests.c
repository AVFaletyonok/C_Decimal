#include "decimal_tests.h"

START_TEST(regular) {
  int num_int = 254;
  decimal expected_decimal = {{254, 0, 0, 0}};
  decimal result_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST

START_TEST(init_decimal_result_with_garbage) {
  int num_int = 254;
  decimal expected_decimal = {{254, 0, 0, 0}};
  decimal result_decimal = {{124, -2, 412, 777}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST

START_TEST(minus_int) {
  int num_int = -5;
  decimal expected_decimal = {{0x5, 0x0, 0x0, 0x80000000}};
  decimal result_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST

START_TEST(two_pow_30) {
  int num_int = 1073741824;
  decimal expected_decimal = {{0x40000000, 0x0, 0x0, 0x0}};
  decimal result_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST
START_TEST(minus_two_pow_30) {
  int num_int = -1073741824;
  decimal expected_decimal = {{0x40000000, 0x0, 0x0, 0x80000000}};
  decimal result_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST
START_TEST(two_pow_31) {
  int num_int = 2147483647;
  decimal expected_decimal = {{0x7fffffff, 0x0, 0x0, 0x0}};
  decimal result_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST
START_TEST(minus_two_pow_31) {
  int num_int = -2147483648;
  decimal expected_decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  decimal result_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(num_int, &result_decimal);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(expected_decimal.bits[i], result_decimal.bits[i]);
  }
}
END_TEST

START_TEST(error_1) {
  int num_int = -2147483648;
  decimal* wrong_pointer = NULL;
  int expected_error_code = 1;

  ck_assert_int_eq(from_int_to_decimal(num_int, wrong_pointer),
                   expected_error_code);
}
END_TEST

Suite* suite_from_int_to_decimal(void) {
  Suite* s = suite_create("from_int_to_decimal");
  TCase* tc = tcase_create("from_int_to_decimal_tc");

  tcase_add_test(tc, regular);
  tcase_add_test(tc, init_decimal_result_with_garbage);
  tcase_add_test(tc, minus_int);
  tcase_add_test(tc, two_pow_30);
  tcase_add_test(tc, minus_two_pow_30);
  tcase_add_test(tc, two_pow_31);
  tcase_add_test(tc, minus_two_pow_31);
  tcase_add_test(tc, error_1);

  suite_add_tcase(s, tc);
  return s;
}