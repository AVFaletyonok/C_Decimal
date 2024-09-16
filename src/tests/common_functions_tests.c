#include "decimal_tests.h"

START_TEST(dec_reset_test) {
  decimal dec = {{10, 0, 0, 0}};
  set_dec_scale(&dec, 1);
  dec_reset(&dec);
  ck_assert_int_eq(get_dec_bit(dec, 1), 0);
  ck_assert_int_eq(get_dec_bit(dec, 3), 0);
  ck_assert_int_eq(get_dec_bit(dec, 112), 0);
}
END_TEST

START_TEST(dec_iszero_test) {
  decimal dec = {{10, 0, 0, 0}};
  ck_assert(!dec_iszero(dec));
  dec_reset(&dec);
  ck_assert(dec_iszero(dec));
}
END_TEST

START_TEST(dec_to_bigdec_test) {
  decimal dec = {{10, 0, 0, 0}};
  set_dec_scale(&dec, 1);
  bigdecimal bdec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  dec_to_bigdec(&bdec, dec);
  ck_assert_int_eq(get_bigdec_bit(bdec, 1), 1);
  ck_assert_int_eq(get_bigdec_bit(bdec, 3), 1);
  ck_assert_int_eq(get_bigdec_bit(bdec, 240), 1);
}
END_TEST

START_TEST(dec_cpy_test) {
  decimal dec = {{10, 0, 0, 0}};
  set_dec_scale(&dec, 1);
  decimal dst = {{10, 0, 0, 0}};
  dec_cpy(&dst, dec);
  ck_assert_int_eq(get_dec_bit(dst, 1), 1);
  ck_assert_int_eq(get_dec_bit(dst, 3), 1);
  ck_assert_int_eq(get_dec_bit(dst, 112), 1);
}
END_TEST

START_TEST(bigdec_reset_test) {
  bigdecimal bdec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec, 1);
  bigdec_reset(&bdec);
  ck_assert_int_eq(get_bigdec_bit(bdec, 1), 0);
  ck_assert_int_eq(get_bigdec_bit(bdec, 3), 0);
  ck_assert_int_eq(get_bigdec_bit(bdec, 240), 0);
}
END_TEST

START_TEST(bigdec_iszero_test) {
  bigdecimal bdec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  ck_assert(!bigdec_iszero(bdec));
  bigdec_reset(&bdec);
  ck_assert(bigdec_iszero(bdec));
}
END_TEST

START_TEST(bigdec_to_dec_test) {
  bigdecimal bdec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec, 1);
  decimal dec = {{0, 0, 0, 0}};
  bigdec_to_dec(&dec, bdec);
  ck_assert_int_eq(get_dec_bit(dec, 1), 1);
  ck_assert_int_eq(get_dec_bit(dec, 3), 1);
  ck_assert_int_eq(get_dec_bit(dec, 112), 1);
}
END_TEST

START_TEST(bigdec_cpy_test) {
  bigdecimal bdec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec, 1);
  bigdecimal bdst = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_cpy(&bdst, bdec);
  ck_assert_int_eq(get_bigdec_bit(bdst, 1), 1);
  ck_assert_int_eq(get_bigdec_bit(bdst, 3), 1);
  ck_assert_int_eq(get_bigdec_bit(bdst, 240), 1);
}
END_TEST

START_TEST(bigdecs_normalize_test) {
  bigdecimal bdec_1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec_1, 1);
  bigdecimal bdec_2 = {{11, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec_2, 2);
  bigdecimal bdec_1_expected = {{10, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec_1_expected, 2);
  bigdecs_normalize(&bdec_1, &bdec_2);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_1_expected), 0);
}
END_TEST

START_TEST(check_bigdec_overflow_test) {
  bigdecimal bdec_1 = {{0, 0, 0, 1, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{0, 0, 0, 0, 1, 0, 0, 0}};
  bigdecimal bdec_3 = {{0, 0, 0, 0, 0, 1, 0, 0}};
  bigdecimal bdec_4 = {{0, 0, 0, 0, 0, 0, 1, 0}};
  bigdecimal bdec_5 = {{0, 0, 0, 0, 0, 0, 0, 1}};
  ck_assert_int_eq(check_bigdec_overflow(bdec_1), 1);
  ck_assert_int_eq(check_bigdec_overflow(bdec_2), 1);
  ck_assert_int_eq(check_bigdec_overflow(bdec_3), 1);
  ck_assert_int_eq(check_bigdec_overflow(bdec_4), 1);
  ck_assert_int_eq(check_bigdec_overflow(bdec_5), 0);
}
END_TEST

START_TEST(bigdec_mult_mantissa_test) {
  bigdecimal bdec_1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{2, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_expected = {{20, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_mult_mantissa(&bdec_1, bdec_2);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_expected), 0);
}
END_TEST

START_TEST(bigdec_div_mantissa_test) {
  bigdecimal bdec_1 = {{2, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{20, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_expected = {{1, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec_expected, 1);
  bigdec_div_mantissa(&bdec_1, bdec_2);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_expected), 0);
}
END_TEST

START_TEST(bigdec_mod_mantissa_test) {
  bigdecimal bdec_1 = {{22, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{20, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_mod = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_expected = {{2, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_mod_mantissa(bdec_1, bdec_2, &bdec_mod);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_mod, bdec_expected), 0);
}
END_TEST

START_TEST(bigdec_div_intmantissa_test) {
  bigdecimal bdec_1 = {{20, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{2, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_zero = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_expected = {{10, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_div_intmantissa(&bdec_1, bdec_2, &bdec_result);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_zero), 0);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_result, bdec_expected), 0);
}
END_TEST

START_TEST(bigdec_add_mantissa_test) {
  bigdecimal bdec_1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_expected = {{11, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_add_mantissa(&bdec_1, bdec_2);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_expected), 0);
}
END_TEST

START_TEST(bigdec_sub_mantissa_test) {
  bigdecimal bdec_1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_expected = {{9, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_sub_mantissa(&bdec_1, bdec_2);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_expected), 0);
}
END_TEST

START_TEST(bigdec_cmp_mantissa_test) {
  bigdecimal bdec_1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_1), 0);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_1, bdec_2), 1);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec_2, bdec_1), -1);

  bigdecimal bdec1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_minus1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_bit(&bdec_minus1, 255, 1);
  ck_assert_int_eq(bigdec_cmp_mantissa(bdec1, bdec_minus1), 0);
}
END_TEST

Suite* suite_common_functions_tests(void) {
  Suite* s = suite_create("common_functions_tests");
  TCase* tc = tcase_create("common_functions_tests_tc");

  tcase_add_test(tc, dec_reset_test);
  tcase_add_test(tc, dec_iszero_test);
  tcase_add_test(tc, dec_to_bigdec_test);
  tcase_add_test(tc, dec_cpy_test);
  tcase_add_test(tc, bigdec_reset_test);
  tcase_add_test(tc, bigdec_iszero_test);
  tcase_add_test(tc, bigdec_to_dec_test);
  tcase_add_test(tc, bigdec_cpy_test);
  tcase_add_test(tc, bigdecs_normalize_test);
  tcase_add_test(tc, check_bigdec_overflow_test);
  tcase_add_test(tc, bigdec_mult_mantissa_test);
  tcase_add_test(tc, bigdec_div_mantissa_test);
  tcase_add_test(tc, bigdec_mod_mantissa_test);
  tcase_add_test(tc, bigdec_div_intmantissa_test);
  tcase_add_test(tc, bigdec_add_mantissa_test);
  tcase_add_test(tc, bigdec_sub_mantissa_test);
  tcase_add_test(tc, bigdec_cmp_mantissa_test);

  suite_add_tcase(s, tc);
  return s;
}
