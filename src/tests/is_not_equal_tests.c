#include "decimal_tests.h"

START_TEST(test_not_equal_zero) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_not_equal(a, b), 1);
}
END_TEST

START_TEST(test_equal_zero) {
  decimal a = {{0, 0, 0, 0}};
  decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_not_equal_max_values) {
  decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(is_not_equal(a, b), 1);
}
END_TEST

START_TEST(test_equal_max_values) {
  decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  decimal b = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_not_equal_with_different_scale) {
  decimal a = {{1, 0, 0, 0x00010000}};  // 1e-1
  decimal b = {{1, 0, 0, 0}};           // 1
  ck_assert_int_eq(is_not_equal(a, b), 1);
}
END_TEST

START_TEST(test_equal_with_scale) {
  decimal a = {{1000000, 0, 0, 0x00060000}};  // 1.000000 (scale 6)
  decimal b = {{1, 0, 0, 0}};                 // 1
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_equal_negative_values) {
  decimal a = {{1, 0, 0, 0x80000000}};
  decimal b = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_not_equal_negative_and_positive_values) {
  decimal a = {{1, 0, 0, 0x80000000}};
  decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(is_not_equal(a, b), 1);
}
END_TEST

START_TEST(test_equal_negative_with_scale) {
  decimal a = {{1000000, 0, 0, 0x80060000}};  // -1.000000 (scale 6)
  decimal b = {{1, 0, 0, 0x80000000}};        // -1
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_equal_different_representation_same_value) {
  decimal a = {{5000, 0, 0, 0x00020000}};   // 50.00 (scale 2)
  decimal b = {{50000, 0, 0, 0x00030000}};  // 50.000 (scale 3)
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_equal_with_scale_different_representation) {
  decimal a = {{500000, 0, 0, 0x00050000}};  // 5.00000 (scale 5)
  decimal b = {{5, 0, 0, 0}};                // 5
  ck_assert_int_eq(is_not_equal(a, b), 0);
}
END_TEST

START_TEST(test_not_equal_large_scale_difference) {
  decimal a = {{1, 0, 0, 0x001C0000}};  // 1e-28
  decimal b = {{1, 0, 0, 0}};           // 1
  ck_assert_int_eq(is_not_equal(a, b), 1);
}
END_TEST

Suite *suite_is_not_equal_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_not_equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_not_equal_zero);
  tcase_add_test(tc_core, test_equal_zero);
  tcase_add_test(tc_core, test_not_equal_max_values);
  tcase_add_test(tc_core, test_equal_max_values);
  tcase_add_test(tc_core, test_not_equal_with_different_scale);
  tcase_add_test(tc_core, test_equal_with_scale);
  tcase_add_test(tc_core, test_equal_negative_values);
  tcase_add_test(tc_core, test_not_equal_negative_and_positive_values);
  tcase_add_test(tc_core, test_equal_negative_with_scale);
  tcase_add_test(tc_core, test_equal_different_representation_same_value);
  tcase_add_test(tc_core, test_equal_with_scale_different_representation);
  tcase_add_test(tc_core, test_not_equal_large_scale_difference);

  suite_add_tcase(s, tc_core);

  return s;
}
