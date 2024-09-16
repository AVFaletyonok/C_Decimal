#include "decimal_tests.h"

START_TEST(int_to_decimal_test) {
  int min = INT_MIN;
  int zero = 0;
  int minus5 = -5;
  int max = INT_MAX;
  decimal dec_min = {{0, 0, 0, 0}};
  decimal dec_zero = {{0, 0, 0, 0}};
  decimal dec_minus5 = {{5, 0, 0, 0}};
  set_dec_bit(&dec_minus5, 127, 1);
  decimal dec_max = {{0, 0, 0, 0}};

  from_int_to_decimal(min, &dec_min);
  from_int_to_decimal(zero, &dec_zero);
  from_int_to_decimal(minus5, &dec_minus5);
  from_int_to_decimal(max, &dec_max);

  bigdecimal bigdec_min = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bigdec_zero = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bigdec_minus5 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bigdec_max = {{0, 0, 0, 0, 0, 0, 0, 0}};

  dec_to_bigdec(&bigdec_min, dec_min);
  dec_to_bigdec(&bigdec_zero, dec_zero);
  dec_to_bigdec(&bigdec_minus5, dec_minus5);
  dec_to_bigdec(&bigdec_max, dec_max);

  bigdecimal bigdec_min_expected = {{INT_MIN, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bigdec_zero_expected = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bigdec_minus5_expected = {{5, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_bit(&bigdec_minus5_expected, 255, 1);
  bigdecimal bigdec_max_expected = {{INT_MAX, 0, 0, 0, 0, 0, 0, 0}};

  ck_assert_int_eq(bigdec_cmp_mantissa(bigdec_min, bigdec_min_expected), 0);
  ck_assert_int_eq(bigdec_cmp_mantissa(bigdec_zero, bigdec_zero_expected), 0);
  ck_assert_int_eq(bigdec_cmp_mantissa(bigdec_minus5, bigdec_minus5_expected),
                   0);
  ck_assert_int_eq(bigdec_cmp_mantissa(bigdec_max, bigdec_max_expected), 0);
}
END_TEST

START_TEST(decimal_to_int_test) {
  bigdecimal bigdec_min = {{INT_MAX, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bigdec1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_add_mantissa(&bigdec_min, bigdec1);
  set_bigdec_bit(&bigdec_min, 255, 1);  // bigdec_min = INT_MIN

  decimal dec_min = {{0, 0, 0, 0}};
  bigdec_to_dec(&dec_min, bigdec_min);
  decimal dec_zero = {{0, 0, 0, 0}};
  decimal dec_max = {{INT_MAX, 0, 0, 0}};

  int min = 0;
  int zero = 1;
  int max = 0;
  ck_assert_int_eq(from_decimal_to_int(dec_min, &min), 0);
  ck_assert_int_eq(from_decimal_to_int(dec_zero, &zero), 0);
  ck_assert_int_eq(from_decimal_to_int(dec_max, &max), 0);

  ck_assert_int_eq(min, INT_MIN);
  ck_assert_int_eq(zero, 0);
  ck_assert_int_eq(max, INT_MAX);

  bigdecimal bigdec_max = {{INT_MAX, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_add_mantissa(&bigdec_min, bigdec1);  // bigdec_min < INT_MIN
  bigdec_add_mantissa(&bigdec_max, bigdec1);  // bigdec_max > INT_MAX
  bigdec_to_dec(&dec_min, bigdec_min);
  bigdec_to_dec(&dec_max, bigdec_max);

  ck_assert_int_eq(from_decimal_to_int(dec_min, &min), 1);
  ck_assert_int_eq(from_decimal_to_int(dec_max, &max), 1);

  decimal dec2 = {{20, 0, 0, 0}};
  set_dec_scale(&dec2, 1);
  int num2 = 0;
  ck_assert_int_eq(from_decimal_to_int(dec2, &num2), 0);
  ck_assert_int_eq(num2, 2);
}
END_TEST

START_TEST(float_to_decimal_test) {
  float zero = 0.0f;
  float minus_zero = -0.0f;
  float max = 7.922816e+28f;
  float overflow_max = 7.922817e+28f;
  float min = 1e-28f;
  float overflow_min = 1e-29f;
  float nan_number = NAN;
  float infinity_number = INFINITY;
  float minus_infinity_number = -INFINITY;
  float exp_minus1 = 1.000000e-1f;

  // zero
  decimal temp_dec = {{0, 0, 0, 0}};
  ck_assert_int_eq(from_float_to_decimal(zero, &temp_dec), 0);
  bigdecimal temp_bigdec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  dec_to_bigdec(&temp_bigdec, temp_dec);
  bigdecimal zero_bigdec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  ck_assert_int_eq(bigdec_cmp_mantissa(temp_bigdec, zero_bigdec), 0);

  // minus_zero
  ck_assert_int_eq(from_float_to_decimal(minus_zero, &temp_dec), 0);
  dec_to_bigdec(&temp_bigdec, temp_dec);
  ck_assert_int_eq(bigdec_cmp_mantissa(temp_bigdec, zero_bigdec), 0);

  // max
  ck_assert_int_eq(from_float_to_decimal(max, &temp_dec), 0);
  dec_to_bigdec(&temp_bigdec, temp_dec);
  bigdecimal max_bigdec = {{536870912, 3012735514, 4294967159, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&max_bigdec, 28);
  ck_assert_int_eq(bigdec_cmp_mantissa(temp_bigdec, max_bigdec), 0);

  // overflow_max
  ck_assert_int_eq(from_float_to_decimal(overflow_max, &temp_dec), 1);

  // min
  ck_assert_int_eq(from_float_to_decimal(min, &temp_dec), 0);
  dec_to_bigdec(&temp_bigdec, temp_dec);
  bigdecimal min_bigdec = {{1, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&min_bigdec, 28);
  ck_assert_int_eq(bigdec_cmp_mantissa(temp_bigdec, min_bigdec), 0);
  ck_assert_int_eq(get_dec_scale(&temp_dec), 28);

  // overflow_min
  ck_assert_int_eq(from_float_to_decimal(overflow_min, &temp_dec), 1);
  dec_to_bigdec(&temp_bigdec, temp_dec);
  ck_assert_int_eq(bigdec_cmp_mantissa(temp_bigdec, zero_bigdec), 0);

  // nan_number
  ck_assert_int_eq(from_float_to_decimal(nan_number, &temp_dec), 1);
  // infinity_number
  ck_assert_int_eq(from_float_to_decimal(infinity_number, &temp_dec), 1);
  // minus_infinity_number
  ck_assert_int_eq(from_float_to_decimal(minus_infinity_number, &temp_dec), 1);

  // exp_minus1
  ck_assert_int_eq(from_float_to_decimal(exp_minus1, &temp_dec), 0);
  dec_to_bigdec(&temp_bigdec, temp_dec);
  bigdecimal exp_minus1_bigdec = {{1, 0, 0, 0, 0, 0, 0, 0}};
  set_bigdec_scale(&exp_minus1_bigdec, 1);
  ck_assert_int_eq(bigdec_cmp_mantissa(temp_bigdec, exp_minus1_bigdec), 0);
  ck_assert_int_eq(get_dec_scale(&temp_dec), 1);
}
END_TEST

START_TEST(decimal_to_float_test) {
  decimal dec_max = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  decimal dec_minus_max = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  set_dec_bit(&dec_minus_max, 127, 1);
  decimal dec_zero = {{0, 0, 0, 0}};
  decimal dec_minus_zero = {{0, 0, 0, 0}};
  set_dec_bit(&dec_minus_zero, 127, 1);

  float max = 0.0f;
  float minus_max = 0.0f;
  float zero = 0.0f;
  float minus_zero = 0.0f;
  ck_assert_int_eq(from_decimal_to_float(dec_max, &max), 0);
  ck_assert_int_eq(from_decimal_to_float(dec_minus_max, &minus_max), 0);
  ck_assert_int_eq(from_decimal_to_float(dec_zero, &zero), 0);
  ck_assert_int_eq(from_decimal_to_float(dec_minus_zero, &minus_zero), 0);
}
END_TEST

Suite* suite_conversion_functions_tests(void) {
  Suite* s = suite_create("conversion_functions_tests");
  TCase* tc = tcase_create("conversion_functions_tests_tc");

  tcase_add_test(tc, int_to_decimal_test);
  tcase_add_test(tc, decimal_to_int_test);

  tcase_add_test(tc, float_to_decimal_test);
  tcase_add_test(tc, decimal_to_float_test);

  suite_add_tcase(s, tc);
  return s;
}
