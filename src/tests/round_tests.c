#include "decimal_tests.h"

START_TEST(test_round_1) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_2) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);

  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_3) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_4) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_5) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_6) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_7) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_8) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_9) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_10) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_11) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_12) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_13) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_14) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_15) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_16) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_17) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_18) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_19) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_20) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_21) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_22) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_23) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_24) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_25) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_26) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_27) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_28) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_29) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_30) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_31) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_32) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_33) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_34) {
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_35) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_36) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_37) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_38) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_39) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_40) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_41) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_42) {
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_43) {
  decimal decimal_res = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_44) {
  decimal decimal_res = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_45) {
  decimal decimal_res = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_46) {
  decimal decimal_res = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_47) {
  decimal decimal_res = {{0x55555555, 0x0, 0x0, 0x10000}};

  decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_48) {
  decimal decimal_res = {{0x55555555, 0x0, 0x0, 0x80010000}};
  decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_49) {
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x0}};
  decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_50) {
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x80000000}};
  decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_51) {
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x10000}};
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_52) {
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x80010000}};
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_53) {
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x1B0000}};
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_54) {
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x801B0000}};
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  decimal result = {0};
  int is_error = dec_round(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

Suite* dec_round_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("dec_round_suite");
  tc = tcase_create("Core");
  tcase_add_test(tc, test_round_1);
  tcase_add_test(tc, test_round_2);
  tcase_add_test(tc, test_round_3);
  tcase_add_test(tc, test_round_4);
  tcase_add_test(tc, test_round_5);
  tcase_add_test(tc, test_round_6);
  tcase_add_test(tc, test_round_7);
  tcase_add_test(tc, test_round_8);
  tcase_add_test(tc, test_round_9);
  tcase_add_test(tc, test_round_10);
  tcase_add_test(tc, test_round_11);
  tcase_add_test(tc, test_round_12);
  tcase_add_test(tc, test_round_13);
  tcase_add_test(tc, test_round_14);
  tcase_add_test(tc, test_round_15);
  tcase_add_test(tc, test_round_16);
  tcase_add_test(tc, test_round_17);
  tcase_add_test(tc, test_round_18);
  tcase_add_test(tc, test_round_19);
  tcase_add_test(tc, test_round_20);
  tcase_add_test(tc, test_round_21);
  tcase_add_test(tc, test_round_22);
  tcase_add_test(tc, test_round_23);
  tcase_add_test(tc, test_round_24);
  tcase_add_test(tc, test_round_25);
  tcase_add_test(tc, test_round_26);
  tcase_add_test(tc, test_round_27);
  tcase_add_test(tc, test_round_28);
  tcase_add_test(tc, test_round_29);
  tcase_add_test(tc, test_round_30);
  tcase_add_test(tc, test_round_31);
  tcase_add_test(tc, test_round_32);
  tcase_add_test(tc, test_round_33);
  tcase_add_test(tc, test_round_34);
  tcase_add_test(tc, test_round_35);
  tcase_add_test(tc, test_round_36);
  tcase_add_test(tc, test_round_37);
  tcase_add_test(tc, test_round_38);
  tcase_add_test(tc, test_round_39);
  tcase_add_test(tc, test_round_40);
  tcase_add_test(tc, test_round_41);
  tcase_add_test(tc, test_round_42);
  tcase_add_test(tc, test_round_43);
  tcase_add_test(tc, test_round_44);
  tcase_add_test(tc, test_round_45);
  tcase_add_test(tc, test_round_46);
  tcase_add_test(tc, test_round_47);
  tcase_add_test(tc, test_round_48);
  tcase_add_test(tc, test_round_49);
  tcase_add_test(tc, test_round_50);
  tcase_add_test(tc, test_round_51);
  tcase_add_test(tc, test_round_52);
  tcase_add_test(tc, test_round_53);
  tcase_add_test(tc, test_round_54);
  suite_add_tcase(s, tc);
  return s;
}