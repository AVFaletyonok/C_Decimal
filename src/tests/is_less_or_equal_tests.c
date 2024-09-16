#include "decimal_tests.h"

START_TEST(test_less_or_equal_positive_values) {
  decimal a = {{1, 0, 0, 0}};  // 1
  decimal b = {{1, 0, 0, 0}};  // 1
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  a.bits[0] = 2;  // 2
  ck_assert_int_eq(is_less_or_equal(a, b), 0);

  b.bits[0] = 3;  // 3
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(test_less_or_equal_negative_values) {
  decimal a = {{1, 0, 0, 0x80000000}};  // -1
  decimal b = {{1, 0, 0, 0x80000000}};  // -1
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  a.bits[0] = 2;  // -2
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  b.bits[0] = 3;  // -3
  ck_assert_int_eq(is_less_or_equal(a, b), 0);
}
END_TEST

START_TEST(test_less_or_equal_different_signs) {
  decimal a = {{1, 0, 0, 0}};           // 1
  decimal b = {{1, 0, 0, 0x80000000}};  // -1
  ck_assert_int_eq(is_less_or_equal(a, b), 0);

  a.bits[3] = 0x80000000;  // -1
  b.bits[3] = 0;           // 1
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(test_less_or_equal_zero_values) {
  decimal a = {{0, 0, 0, 0}};  // 0
  decimal b = {{0, 0, 0, 0}};  // 0
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  a.bits[3] = 0x80000000;  // -0
  b.bits[3] = 0x80000000;  // -0
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  b.bits[3] = 0;                                // 0
  ck_assert_int_eq(is_less_or_equal(a, b), 1);  // 0 == -0
}
END_TEST

START_TEST(test_less_or_equal_different_scales) {
  decimal a = {{1, 0, 0, 0x00010000}};   // 0.1
  decimal b = {{10, 0, 0, 0x00020000}};  // 0.10
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  a.bits[0] = 1;
  a.bits[3] = 0x00020000;  // 0.01
  ck_assert_int_eq(is_less_or_equal(a, b), 1);

  a.bits[0] = 100;
  a.bits[3] = 0x00030000;  // 0.1
  b.bits[0] = 10;
  b.bits[3] = 0x00020000;  // 0.10
  ck_assert_int_eq(is_less_or_equal(a, b), 1);
}
END_TEST

Suite *suite_is_less_or_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_less_or_equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_less_or_equal_positive_values);
  tcase_add_test(tc_core, test_less_or_equal_negative_values);
  tcase_add_test(tc_core, test_less_or_equal_different_signs);
  tcase_add_test(tc_core, test_less_or_equal_zero_values);
  tcase_add_test(tc_core, test_less_or_equal_different_scales);
  suite_add_tcase(s, tc_core);

  return s;
}
