#include "decimal_tests.h"

void test_truncate(decimal decimal_res, decimal decimal_check) {
  decimal result = {0};

  int is_error = truncate(decimal_res, &result);
  int sign_check = get_dec_bit(decimal_check, 127);
  int sign_result = get_dec_bit(result, 127);

  ck_assert_int_eq(is_error, 0);
  ck_assert_int_eq(is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(trun_1) {
  decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000011010011;  // 21.1
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000010101;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(trun_2) {
  decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000010000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(trun_3) {
  decimal dec1;
  dec1.bits[0] =
      0b11111111111111111111111111111111;  // 7922816251426433759354395033.5
  dec1.bits[1] = 0b11111111111111111111111111111111;
  dec1.bits[2] = 0b11111111111111111111111111111111;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  decimal result;
  result.bits[0] = 0b10011001100110011001100110011001;
  result.bits[1] = 0b10011001100110011001100110011001;
  result.bits[2] = 0b00011001100110011001100110011001;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(trun_4) {
  decimal dec1;
  dec1.bits[0] = 0b10000000000000000000000010100101;  // 214.7483813
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  float num = 0.0;
  from_decimal_to_float(dec1, &num);
  decimal result;
  result.bits[0] = 0b00000000000000000000000011010110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_1) {
  decimal dec1;

  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_2) {
  decimal dec1;

  dec1.bits[3] = 0b10000000000011000000000000000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  decimal result;
  result.bits[3] = 0b10000000000000000000000000000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x1197998;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_3) {
  decimal dec1;

  dec1.bits[3] = 0x80000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  decimal result;
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0xFFFFFFFF;
  result.bits[0] = 0xFFFFFFFF;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_4) {
  decimal dec1;

  dec1.bits[0] = 0b00000000000000000000000001101101;
  dec1.bits[1] = 0b00000000000011000110010101011011;
  dec1.bits[2] = 0b00000000000000000011000000111001;
  dec1.bits[3] = 0b00000000000011100000000000000000;
  decimal result;
  result.bits[0] = 0b10000111101111000001011000011110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_5) {
  decimal dec1;

  dec1.bits[0] = 0b11011110101001001000000010110110;
  dec1.bits[1] = 0b01011111101001011101111110100000;
  dec1.bits[2] = 0b00011111111010011010111101100000;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  decimal result;
  result.bits[0] = 0b00110100101011011100000100111110;
  result.bits[1] = 0b10001001000100001000011110111001;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate_6) {
  decimal dec1;

  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  decimal result;
  truncate(dec1, &result);
  decimal res1;

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0;
  res1.bits[1] = 0x4;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncate_7) {
  decimal dec1;

  dec1.bits[0] = 0b11010000101000110011000001101101;
  dec1.bits[1] = 0b00011111100110100110101101011000;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  decimal result;
  truncate(dec1, &result);
  decimal result_origin;
  result_origin.bits[3] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b10000111101111000001011000011110;
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncate_8) {
  decimal dec1;

  dec1.bits[0] = 0b01111000101001111011110011000110;
  dec1.bits[1] = 0b10011111111111001111101010000100;
  dec1.bits[2] = 0b00011111111010011010111101101101;
  dec1.bits[3] = 0b00000000000111000000000000000000;
  decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  decimal res1;
  truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncateTest1) {
  // 6766
  decimal src1, origin;
  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest2) {
  // 6787
  decimal src1, origin;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest3) {
  // 6808
  decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest4) {
  // 6829
  decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest5) {
  // 6850
  decimal src1, origin;
  // src1 = -9878798789;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b01001100110100101000000111000101;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest6) {
  // 6871
  decimal src1, origin;
  // src1 = -545454512454545.35265454545645;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest7) {
  // 6892
  decimal src1, origin;
  // src1 = -5.492654545456454545645464;

  src1.bits[0] = 0b00000111100110110001111110011000;
  src1.bits[1] = 0b01100110010010001001000110100011;
  src1.bits[2] = 0b00000000000001001000101100011101;
  src1.bits[3] = 0b10000000000110000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest8) {
  // 6913
  decimal src1, origin;
  // src1 = 7961327845421.879754123131254;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest9) {
  // 6934
  decimal src1, origin;
  // src1 = -12345677.187654345678987654346;

  src1.bits[0] = 0b01111000100010101111010011001010;
  src1.bits[1] = 0b01100010000010101110010010000111;
  src1.bits[2] = 0b00100111111001000001101011010101;
  src1.bits[3] = 0b10000000000101010000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest10) {
  // 6955
  decimal src1 = {{0, 0, 0, 0}}, origin = {{0, 0, 0, 0}};
  // src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(truncateTest11) {
  // 6976
  decimal src1 = {{0, 0, 0, 0}}, origin = {{0, 0, 0, 0}};
  // src1 = 1;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  decimal result = {{0, 0, 0, 0}};
  truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_truncate_1) {
  // 79228162514264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_2) {
  // -79228162514264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_3) {
  // 7922816251426433759354395033.5
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_4) {
  // -7922816251426433759354395033.5
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_5) {
  // 792281625142643375935439503.35
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_6) {
  // -792281625142643375935439503.35
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_7) {
  // 79228162514264337593543950.335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_8) {
  // -79228162514264337593543950.335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_9) {
  // 7922816251426433759354395.0335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_10) {
  // -7922816251426433759354395.0335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_11) {
  // 792281625142643375935439.50335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_12) {
  // -792281625142643375935439.50335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_13) {
  // 79228162514264337593543.950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_14) {
  // -79228162514264337593543.950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_15) {
  // 7922816251426433759354.3950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_16) {
  // -7922816251426433759354.3950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_17) {
  // 792281625142643375935.43950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_18) {
  // -792281625142643375935.43950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_19) {
  // 79228162514264337593.543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_20) {
  // -79228162514264337593.543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_21) {
  // 7922816251426433759.3543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_22) {
  // -7922816251426433759.3543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_23) {
  // 792281625142643375.93543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_24) {
  // -792281625142643375.93543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_25) {
  // 79228162514264337.593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_26) {
  // -79228162514264337.593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_27) {
  // 7922816251426433.7593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_28) {
  // -7922816251426433.7593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_29) {
  // 792281625142643.37593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_30) {
  // -792281625142643.37593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_31) {
  // 79.228162514264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_32) {
  // -79.228162514264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_33) {
  // 7.9228162514264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_34) {
  // -7.9228162514264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7
  decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_35) {
  // 52818775009509558395695966890
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 52818775009509558395695966890
  decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_36) {
  // -52818775009509558395695966890
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -52818775009509558395695966890
  decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_37) {
  // 5281877500950955839569596689.0
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839569596689
  decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_38) {
  // -5281877500950955839569596689.0
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839569596689
  decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_39) {
  // 5281877500950955.8395695966890
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // 5281877500950955
  decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_40) {
  // -5281877500950955.8395695966890
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // -5281877500950955
  decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_41) {
  // 5.2818775009509558395695966890
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // 5
  decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_42) {
  // -5.2818775009509558395695966890
  decimal decimal_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // -5
  decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_43) {
  // 2.863311530
  decimal decimal_res = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  // 2
  decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_44) {
  // -2.863311530
  decimal decimal_res = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  // -2
  decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_45) {
  // 2.6409387504754779196416327680
  decimal decimal_res = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  // 2
  decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_46) {
  // -2.6409387504754779196416327680
  decimal decimal_res = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  // -2
  decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_47) {
  // 2640938749860586.4506611466240
  decimal decimal_res = {{0x0, 0x0, 0x55555555, 0xD0000}};
  // 2640938749860586
  decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_48) {
  // -2640938749860586.4506611466240
  decimal decimal_res = {{0x0, 0x0, 0x55555555, 0x800D0000}};
  // -2640938749860586
  decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_49) {
  // 143165576.5
  decimal decimal_res = {{0x55555555, 0x0, 0x0, 0x10000}};
  // 143165576
  decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_50) {
  // -143165576.5
  decimal decimal_res = {{0x55555555, 0x0, 0x0, 0x80010000}};
  // -143165576
  decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_51) {
  // 1
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x0}};
  // 1
  decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_52) {
  // -1
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x80000000}};
  // -1
  decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_53) {
  // 0.1
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x10000}};
  // 0
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_54) {
  // -0.1
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x80010000}};
  // 0
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_55) {
  // 0.0000000000000000000000000001
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_56) {
  // -0.0000000000000000000000000001
  decimal decimal_res = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 0
  decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal_res, decimal_check);
}

START_TEST(test_truncate_fail1) {
  // 792281625.14264337593543950335
  decimal decimal_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // result is NULL
  int is_error = truncate(decimal_res, NULL);

  ck_assert_int_eq(is_error, 1);
}

START_TEST(test_truncate_fail2) {
  decimal decimal_res = {{0, 0, 0, 1000000000}};
  decimal result;

  int is_error = truncate(decimal_res, &result);

  ck_assert_int_eq(is_error, 1);
}
END_TEST

START_TEST(test_truncate_fail3) {
  decimal decimal_res = {{-1, 0, 0, 0x1D0000}};
  decimal result;

  int is_error = truncate(decimal_res, &result);

  ck_assert_int_eq(is_error, 1);
}
END_TEST

START_TEST(test_truncate_fail4) {
  decimal decimal_res = {{0, 0, 0, 0x1D0000}};
  decimal result;

  int is_error = truncate(decimal_res, &result);

  ck_assert_int_eq(is_error, 1);
}
END_TEST

START_TEST(test_truncate_fail5) {
  decimal decimal_res = {{-1, 0, 0, 0x1C0001}};
  decimal result;

  int is_error = truncate(decimal_res, &result);

  ck_assert_int_eq(is_error, 1);
}
END_TEST

START_TEST(test_truncate_fail6) {
  decimal decimal_res = {{-1, 0, 0, 0x11C0000}};
  decimal result;

  int is_error = truncate(decimal_res, &result);

  ck_assert_int_eq(is_error, 1);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("truncate");
  tc = tcase_create("case_truncate");
  tcase_add_test(tc, trun_1);
  tcase_add_test(tc, trun_2);
  tcase_add_test(tc, trun_3);
  tcase_add_test(tc, trun_4);
  tcase_add_test(tc, truncate_1);
  tcase_add_test(tc, truncate_2);
  tcase_add_test(tc, truncate_3);
  tcase_add_test(tc, truncate_4);
  tcase_add_test(tc, truncate_5);
  tcase_add_test(tc, truncate_6);
  tcase_add_test(tc, truncate_7);
  tcase_add_test(tc, truncate_8);
  tcase_add_test(tc, truncateTest1);
  tcase_add_test(tc, truncateTest2);
  tcase_add_test(tc, truncateTest3);
  tcase_add_test(tc, truncateTest4);
  tcase_add_test(tc, truncateTest5);
  tcase_add_test(tc, truncateTest6);
  tcase_add_test(tc, truncateTest7);
  tcase_add_test(tc, truncateTest8);
  tcase_add_test(tc, truncateTest9);
  tcase_add_test(tc, truncateTest10);
  tcase_add_test(tc, truncateTest11);
  tcase_add_test(tc, test_truncate_1);
  tcase_add_test(tc, test_truncate_2);
  tcase_add_test(tc, test_truncate_3);
  tcase_add_test(tc, test_truncate_4);
  tcase_add_test(tc, test_truncate_5);
  tcase_add_test(tc, test_truncate_6);
  tcase_add_test(tc, test_truncate_7);
  tcase_add_test(tc, test_truncate_8);
  tcase_add_test(tc, test_truncate_9);
  tcase_add_test(tc, test_truncate_10);
  tcase_add_test(tc, test_truncate_11);
  tcase_add_test(tc, test_truncate_12);
  tcase_add_test(tc, test_truncate_13);
  tcase_add_test(tc, test_truncate_14);
  tcase_add_test(tc, test_truncate_15);
  tcase_add_test(tc, test_truncate_16);
  tcase_add_test(tc, test_truncate_17);
  tcase_add_test(tc, test_truncate_18);
  tcase_add_test(tc, test_truncate_19);
  tcase_add_test(tc, test_truncate_20);
  tcase_add_test(tc, test_truncate_21);
  tcase_add_test(tc, test_truncate_22);
  tcase_add_test(tc, test_truncate_23);
  tcase_add_test(tc, test_truncate_24);
  tcase_add_test(tc, test_truncate_25);
  tcase_add_test(tc, test_truncate_26);
  tcase_add_test(tc, test_truncate_27);
  tcase_add_test(tc, test_truncate_28);
  tcase_add_test(tc, test_truncate_29);
  tcase_add_test(tc, test_truncate_30);
  tcase_add_test(tc, test_truncate_31);
  tcase_add_test(tc, test_truncate_32);
  tcase_add_test(tc, test_truncate_33);
  tcase_add_test(tc, test_truncate_34);
  tcase_add_test(tc, test_truncate_35);
  tcase_add_test(tc, test_truncate_36);
  tcase_add_test(tc, test_truncate_37);
  tcase_add_test(tc, test_truncate_38);
  tcase_add_test(tc, test_truncate_39);
  tcase_add_test(tc, test_truncate_40);
  tcase_add_test(tc, test_truncate_41);
  tcase_add_test(tc, test_truncate_42);
  tcase_add_test(tc, test_truncate_43);
  tcase_add_test(tc, test_truncate_44);
  tcase_add_test(tc, test_truncate_45);
  tcase_add_test(tc, test_truncate_46);
  tcase_add_test(tc, test_truncate_47);
  tcase_add_test(tc, test_truncate_48);
  tcase_add_test(tc, test_truncate_49);
  tcase_add_test(tc, test_truncate_50);
  tcase_add_test(tc, test_truncate_51);
  tcase_add_test(tc, test_truncate_52);
  tcase_add_test(tc, test_truncate_53);
  tcase_add_test(tc, test_truncate_54);
  tcase_add_test(tc, test_truncate_55);
  tcase_add_test(tc, test_truncate_56);
  tcase_add_test(tc, test_truncate_fail1);
  tcase_add_test(tc, test_truncate_fail2);
  tcase_add_test(tc, test_truncate_fail3);
  tcase_add_test(tc, test_truncate_fail4);
  tcase_add_test(tc, test_truncate_fail5);
  tcase_add_test(tc, test_truncate_fail6);
  suite_add_tcase(s, tc);
  return s;
}
