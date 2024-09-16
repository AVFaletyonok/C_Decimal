#include "decimal_tests.h"

START_TEST(test_greater_zero_and_zero) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_positive_and_negative) {
  decimal a = {{1, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(test_greater_negative_and_positive) {
  decimal a = {{1, 0, 0, 0x80000000}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_with_scale) {
  decimal a = {{1000000, 0, 0, 0x00060000}};  // 1.000000 (scale 6)
  decimal b = {{1, 0, 0, 0}};                 // 1
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_negative_values) {
  decimal a = {{2, 0, 0, 0x80000000}};
  decimal b = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_same_values) {
  decimal a = {{1, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_large_numbers) {
  decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  decimal b = {{UINT32_MAX - 1, UINT32_MAX, UINT32_MAX, 0}};
  ck_assert_int_eq(is_greater(a, b), 1);
}
END_TEST

START_TEST(test_greater_with_different_scales) {
  decimal a = {{10, 0, 0, 0x00010000}};  // 1.0 (scale 1)
  decimal b = {{1, 0, 0, 0}};            // 1
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_max_negative_and_min_positive) {
  decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_min_negative_and_max_positive) {
  decimal a = {{1, 0, 0, 0x80000000}};
  decimal b = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_with_zero) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

START_TEST(test_greater_with_negative_zero) {
  decimal a = {{0, 0, 0, 0x80000000}};
  decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_greater(a, b), 0);
}
END_TEST

Suite *suite_is_greater_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_greater");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_greater_zero_and_zero);
  tcase_add_test(tc_core, test_greater_positive_and_negative);
  tcase_add_test(tc_core, test_greater_negative_and_positive);
  tcase_add_test(tc_core, test_greater_with_scale);
  tcase_add_test(tc_core, test_greater_negative_values);
  tcase_add_test(tc_core, test_greater_same_values);
  tcase_add_test(tc_core, test_greater_large_numbers);
  tcase_add_test(tc_core, test_greater_with_different_scales);
  tcase_add_test(tc_core, test_greater_max_negative_and_min_positive);
  tcase_add_test(tc_core, test_greater_min_negative_and_max_positive);
  tcase_add_test(tc_core, test_greater_with_zero);
  tcase_add_test(tc_core, test_greater_with_negative_zero);

  suite_add_tcase(s, tc_core);

  return s;
}
