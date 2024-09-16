#include "decimal_tests.h"

START_TEST(get_dec_bit_test) {
  decimal dec = {{10, 0, 0, 0}};

  ck_assert_int_eq(get_dec_bit(dec, 0), 0);
  ck_assert_int_eq(get_dec_bit(dec, 1), 1);
  ck_assert_int_eq(get_dec_bit(dec, 2), 0);
  ck_assert_int_eq(get_dec_bit(dec, 3), 1);
}
END_TEST

START_TEST(set_dec_bit_test) {
  decimal dec = {{0, 0, 0, 0}};

  set_dec_bit(&dec, 3, 1);
  ck_assert_int_eq(get_dec_bit(dec, 3), 1);
}
END_TEST

START_TEST(get_dec_scale_test) {
  decimal dec = {{0, 0, 0, 0}};
  set_dec_bit(&dec, 112, 1);

  ck_assert_int_eq(get_dec_scale(&dec), 1);
}
END_TEST

START_TEST(set_dec_scale_test) {
  decimal dec = {{0, 0, 0, 0}};
  set_dec_scale(&dec, 11);

  ck_assert_int_eq(get_dec_scale(&dec), 11);
}
END_TEST

START_TEST(get_bigdec_bit_test) {
  bigdecimal bdec = {{10, 0, 0, 0, 0, 0, 0, 0}};

  ck_assert_int_eq(get_bigdec_bit(bdec, 0), 0);
  ck_assert_int_eq(get_bigdec_bit(bdec, 1), 1);
  ck_assert_int_eq(get_bigdec_bit(bdec, 2), 0);
  ck_assert_int_eq(get_bigdec_bit(bdec, 3), 1);
}
END_TEST

START_TEST(set_bigdec_bit_test) {
  bigdecimal bdec = {{0, 0, 0, 0}};

  set_bigdec_bit(&bdec, 3, 1);
  ck_assert_int_eq(get_bigdec_bit(bdec, 3), 1);
}
END_TEST

START_TEST(bigdec_shift_bit_test) {
  bigdecimal bdec = {{0, 0, 0, 0, 0, 0, 0, 0}};

  set_bigdec_bit(&bdec, 3, 1);
  bigdec_shift_bit(&bdec, 1);
  ck_assert_int_eq(get_bigdec_bit(bdec, 4), 1);
}
END_TEST

START_TEST(get_bigdec_scale_test) {
  bigdecimal bdec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_bit(&bdec, 240, 1);

  ck_assert_int_eq(get_bigdec_scale(&bdec), 1);
}
END_TEST

START_TEST(set_bigdec_scale_test) {
  bigdecimal bdec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&bdec, 11);

  ck_assert_int_eq(get_bigdec_scale(&bdec), 11);
}
END_TEST

START_TEST(get_uint_bit_test) {
  unsigned int number = 10;

  ck_assert_int_eq(get_uint_bit(number, 0), 0);
  ck_assert_int_eq(get_uint_bit(number, 1), 1);
  ck_assert_int_eq(get_uint_bit(number, 2), 0);
  ck_assert_int_eq(get_uint_bit(number, 3), 1);
}
END_TEST

START_TEST(set_uint_bit_test) {
  unsigned int number = 0;

  set_uint_bit(&number, 1, 1);
  set_uint_bit(&number, 3, 1);
  ck_assert_int_eq(get_uint_bit(number, 0), 0);
  ck_assert_int_eq(get_uint_bit(number, 1), 1);
  ck_assert_int_eq(get_uint_bit(number, 2), 0);
  ck_assert_int_eq(get_uint_bit(number, 3), 1);
  ck_assert_int_eq(number, 10);
}
END_TEST

Suite* suite_bit_functions_tests(void) {
  Suite* s = suite_create("bit_functions_tests");
  TCase* tc = tcase_create("bit_functions_tests_tc");

  tcase_add_test(tc, get_dec_bit_test);
  tcase_add_test(tc, set_dec_bit_test);
  tcase_add_test(tc, get_dec_scale_test);
  tcase_add_test(tc, set_dec_scale_test);
  tcase_add_test(tc, get_bigdec_bit_test);
  tcase_add_test(tc, set_bigdec_bit_test);
  tcase_add_test(tc, bigdec_shift_bit_test);
  tcase_add_test(tc, get_bigdec_scale_test);
  tcase_add_test(tc, set_bigdec_scale_test);
  tcase_add_test(tc, get_uint_bit_test);
  tcase_add_test(tc, set_uint_bit_test);

  suite_add_tcase(s, tc);
  return s;
}