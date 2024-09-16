#include "decimal_tests.h"

START_TEST(test_less_zero_and_non_zero) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_negative_and_positive) {
  decimal a = {{1, 0, 0, 0x80000000}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_equal_values) {
  decimal a = {{1, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_less(a, b), 0);
}
END_TEST

START_TEST(test_less_with_scale) {
  decimal a = {{1, 0, 0, 0x00010000}};  // 0.1
  decimal b = {{2, 0, 0, 0}};           // 2
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_with_normalized_scale) {
  decimal a = {{1000000, 0, 0, 0x00060000}};  // 1.000000 (scale 6)
  decimal b = {{2, 0, 0, 0}};                 // 2
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_negative_values) {
  decimal a = {{2, 0, 0, 0x80000000}};  // -2
  decimal b = {{1, 0, 0, 0x80000000}};  // -1
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_equal_values_with_different_scale) {
  decimal a = {{1000, 0, 0, 0x00030000}};  // 1.000 (scale 3)
  decimal b = {{1, 0, 0, 0}};              // 1
  ck_assert_int_eq(is_less(a, b), 0);
}
END_TEST

START_TEST(test_less_negative_and_positive_with_scale) {
  decimal a = {{100, 0, 0, 0x00020000}};  // 1.00 (scale 2)
  decimal b = {{1, 0, 0, 0x80000000}};    // -1
  ck_assert_int_eq(is_less(a, b), 0);
}
END_TEST

START_TEST(test_less_min_values) {
  decimal a = {{1, 0, 0, 0x80000000}};
  decimal b = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_max_values) {
  decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  decimal b = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  ck_assert_int_eq(is_less(a, b), 0);
}
END_TEST

START_TEST(test_less_with_scale_larger_value) {
  decimal a = {{1, 0, 0, 0x00010000}};  // 0.1 (scale 1)
  decimal b = {{2, 0, 0, 0}};           // 2
  ck_assert_int_eq(is_less(a, b), 1);
}
END_TEST

START_TEST(test_less_with_scale_smaller_value) {
  decimal a = {{20, 0, 0, 0x00010000}};  // 2.0 (scale 1)
  decimal b = {{1, 0, 0, 0}};            // 1
  ck_assert_int_eq(is_less(a, b), 0);
}
END_TEST

START_TEST(test_less_with_scale_equal_value) {
  decimal a = {{500, 0, 0, 0x00020000}};  // 5.00 (scale 2)
  decimal b = {{50, 0, 0, 0x00010000}};   // 5.0 (scale 1)
  ck_assert_int_eq(is_less(a, b), 0);
}
END_TEST

Suite *suite_is_less_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_less");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_less_zero_and_non_zero);
  tcase_add_test(tc_core, test_less_negative_and_positive);
  tcase_add_test(tc_core, test_less_equal_values);
  tcase_add_test(tc_core, test_less_with_scale);
  tcase_add_test(tc_core, test_less_with_normalized_scale);
  tcase_add_test(tc_core, test_less_negative_values);
  tcase_add_test(tc_core, test_less_equal_values_with_different_scale);
  tcase_add_test(tc_core, test_less_negative_and_positive_with_scale);
  tcase_add_test(tc_core, test_less_min_values);
  tcase_add_test(tc_core, test_less_max_values);
  tcase_add_test(tc_core, test_less_with_scale_larger_value);
  tcase_add_test(tc_core, test_less_with_scale_smaller_value);
  tcase_add_test(tc_core, test_less_with_scale_equal_value);
  tcase_add_test(tc_core, test_less_negative_and_positive_with_scale);
  tcase_add_test(tc_core, test_less_negative_and_positive_with_scale);

  suite_add_tcase(s, tc_core);

  return s;
}