#include "decimal_tests.h"

START_TEST(regular_to_int) {
  int num_int = 0;
  decimal num_decimal = {{254, 0, 0, 0}};
  int expected_int = 254;

  from_decimal_to_int(num_decimal, &num_int);
  ck_assert_int_eq(num_int, expected_int);
}
END_TEST

START_TEST(error_2) {
  int num_int = 0;
  decimal num_decimal = {{1234, 0, 0, 0x3241571}};
  int expected_int = 1;

  ck_assert_int_eq(from_decimal_to_int(num_decimal, &num_int), expected_int);
}
END_TEST

START_TEST(error_3) {
  int num_int = 0;
  decimal num_decimal = {{0x90000000, 0x0, 0x0, 0x80000000}};
  int expected_int = 1;

  ck_assert_int_eq(from_decimal_to_int(num_decimal, &num_int), expected_int);
}
END_TEST

START_TEST(error_4) {
  int num_int = 0;
  decimal num_decimal = {{0x7FFFFFFF, 0xF, 0x0, 0x0}};
  int expected_int = 1;

  ck_assert_int_eq(from_decimal_to_int(num_decimal, &num_int), expected_int);
}
END_TEST

Suite* suite_from_decimal_to_int(void) {
  Suite* s = suite_create("from_decimal_to_int");
  TCase* tc = tcase_create("from_decimal_to_int_tc");

  tcase_add_test(tc, regular_to_int);
  tcase_add_test(tc, error_2);
  tcase_add_test(tc, error_3);
  tcase_add_test(tc, error_4);

  suite_add_tcase(s, tc);
  return s;
}
