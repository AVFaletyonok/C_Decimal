#include "decimal_tests.h"

START_TEST(mul_1) {
  // 323
  decimal dec_1 = {{0x143, 0x0, 0x0, 0x0}};
  // 655
  decimal dec_2 = {{0x28f, 0x0, 0x0, 0x0}};
  // 211565
  decimal dec_check = {{0x33a6d, 0x0, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_2) {
  // 42154
  decimal dec_1 = {{0xa4aa, 0x0, 0x0, 0x0}};
  // 715
  decimal dec_2 = {{0x2cb, 0x0, 0x0, 0x0}};
  // 30140110
  decimal dec_check = {{0x1cbe6ce, 0x0, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_3) {
  // 745929467730
  decimal dec_1 = {{0xacdc6752, 0xad, 0x0, 0x0}};
  // -61054.1669667576011486803
  decimal dec_2 = {{0xf956f653, 0x87bd4e41, 0x8149, 0x80130000}};
  // -45542102268212046.028766732771
  decimal dec_check = {{0xf31c61e3, 0xf0084176, 0x93278b46, 0x800c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_4) {
  // -64822
  decimal dec_1 = {{0xfd36, 0x0, 0x0, 0x80000000}};
  // 190185977193
  decimal dec_2 = {{0x47f7b569, 0x2c, 0x0, 0x0}};
  // -12328235413604646
  decimal dec_check = {{0xfc890926, 0x2bcc76, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_5) {
  // -178469090
  decimal dec_1 = {{0xaa338e2, 0x0, 0x0, 0x80000000}};
  // -6077802061833351126
  decimal dec_2 = {{0xeb6afd6, 0x5458b0c6, 0x0, 0x80000000}};
  // 1084699803175521907107695340
  decimal dec_check = {{0x45000aec, 0x27a5e341, 0x3813e1e, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_6) {
  // 0.743355415436
  decimal dec_1 = {{0x136f7b8c, 0xad, 0x0, 0xc0000}};
  // -0.3
  decimal dec_2 = {{0x3, 0x0, 0x0, 0x80010000}};
  // -0.2230066246308
  decimal dec_check = {{0x3a4e72a4, 0x207, 0x0, 0x800d0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_8) {
  // 8
  decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
  // 8866
  decimal dec_2 = {{0x22a2, 0x0, 0x0, 0x0}};
  // 70928
  decimal dec_check = {{0x11510, 0x0, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_9) {
  // 0.74
  decimal dec_1 = {{0x4a, 0x0, 0x0, 0x20000}};
  // 5
  decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 3.70
  decimal dec_check = {{0x172, 0x0, 0x0, 0x20000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_10) {
  // 9
  decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 594032952142.6764631114
  decimal dec_2 = {{0xe07f8c4a, 0x6a1f285, 0x142, 0xa0000}};
  // 5346296569284.0881680026
  decimal dec_check = {{0xe47bee9a, 0x3bb186b4, 0xb52, 0xa0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_11) {
  // -0.5642537087264482306770497355
  decimal dec_1 = {{0xe30a6f4b, 0x6ac7a97d, 0x123b65b4, 0x801c0000}};
  // 5
  decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // -2.8212685436322411533852486775
  decimal dec_check = {{0x6f342c77, 0x15e64f75, 0x5b28fc86, 0x801c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_12) {
  // -570
  decimal dec_1 = {{0x23a, 0x0, 0x0, 0x80000000}};
  // 3109302910217376040
  decimal dec_2 = {{0xe6985128, 0x2b267685, 0x0, 0x0}};
  // -1772302658823904342800
  decimal dec_check = {{0x6f24b310, 0x13a3e623, 0x60, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_13) {
  // -6534957292963058331578.958
  decimal dec_1 = {{0x58be724e, 0xbea51642, 0x567d4, 0x80030000}};
  // 4
  decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -26139829171852233326315.832
  decimal dec_check = {{0x62f9c938, 0xfa945909, 0x159f52, 0x80030000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_14) {
  // 324110
  decimal dec_1 = {{0x4f20e, 0x0, 0x0, 0x0}};
  // 0.024
  decimal dec_2 = {{0x18, 0x0, 0x0, 0x30000}};
  // 7778.640
  decimal dec_check = {{0x76b150, 0x0, 0x0, 0x30000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_15) {
  // -6737284144340160917
  decimal dec_1 = {{0xce445195, 0x5d7fa43b, 0x0, 0x80000000}};
  // 88043219.43994362979491685
  decimal dec_2 = {{0x3e411f65, 0x3fbafe00, 0x74863, 0x110000}};
  // -593172186349393639531422716.84
  decimal dec_check = {{0xccc20ec4, 0x7d6d0e3f, 0xbfaa0da1, 0x80020000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_16) {
  // -2
  decimal dec_1 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -14817
  decimal dec_2 = {{0x39e1, 0x0, 0x0, 0x80000000}};
  // 29634
  decimal dec_check = {{0x73c2, 0x0, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_17) {
  // 539383186406515
  decimal dec_1 = {{0xef393c73, 0x1ea90, 0x0, 0x0}};
  // 2631
  decimal dec_2 = {{0xa47, 0x0, 0x0, 0x0}};
  // 1419117163435540965
  decimal dec_check = {{0x953c41e5, 0x13b1b78a, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_18) {
  // -65874828213
  decimal dec_1 = {{0x56721bb5, 0xf, 0x0, 0x80000000}};
  // -0.820188969947692224328
  decimal dec_2 = {{0xb9bb4f48, 0x7668929e, 0x2c, 0x80150000}};
  // 54029807497.501644873402859366
  decimal dec_check = {{0xb316bf66, 0x6363f4a7, 0xae9468c5, 0x120000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_19) {
  // 2
  decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // -68952
  decimal dec_2 = {{0x10d58, 0x0, 0x0, 0x80000000}};
  // -137904
  decimal dec_check = {{0x21ab0, 0x0, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_20) {
  // 383518620269.7040
  decimal dec_1 = {{0xdf425d50, 0xda014, 0x0, 0x40000}};
  // 4047173.1
  decimal dec_2 = {{0x2698cb3, 0x0, 0x0, 0x10000}};
  // 1552166243304660773.76240
  decimal dec_check = {{0x4c3efef0, 0x4f606fa3, 0x20de, 0x50000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_21) {
  // -421328136211.1945581422
  decimal dec_1 = {{0x6079236e, 0x670653eb, 0xe4, 0x800a0000}};
  // 103720958736.6
  decimal dec_2 = {{0x7e824ea6, 0xf1, 0x0, 0x10000}};
  // -43700558230529895028061.595755
  decimal dec_check = {{0x4c73686b, 0x9e555f6b, 0x8d344128, 0x80060000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_22) {
  // 417991632627322192660597885
  decimal dec_1 = {{0x32810c7d, 0xcf0b3dc7, 0x159c12b, 0x0}};
  // -1.06655
  decimal dec_2 = {{0x1a09f, 0x0, 0x0, 0x80050000}};
  // -445808975778670484582160674.25
  decimal dec_check = {{0x9608d161, 0x438c6210, 0x900c7444, 0x80020000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_23) {
  // -31481828
  decimal dec_1 = {{0x1e05fe4, 0x0, 0x0, 0x80000000}};
  // -2.203
  decimal dec_2 = {{0x89b, 0x0, 0x0, 0x80030000}};
  // 69354467.084
  decimal dec_check = {{0x25d92f0c, 0x10, 0x0, 0x30000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_24) {
  // 204.94
  decimal dec_1 = {{0x500e, 0x0, 0x0, 0x20000}};
  // 401657.160942075617803
  decimal dec_2 = {{0x5451a20b, 0xc61ce3ce, 0x15, 0xf0000}};
  // 82315618.56346897711254682
  decimal dec_check = {{0x1f1a4c9a, 0xdcc4efa2, 0x6cf19, 0x110000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_25) {
  // 0
  decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 809420101599253852799694
  decimal dec_2 = {{0xd30742ce, 0xc06ad906, 0xab66, 0x0}};
  // 0
  decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_26) {
  // 2198068235761104764
  decimal dec_1 = {{0x209c377c, 0x1e811b6a, 0x0, 0x0}};
  // -0.9
  decimal dec_2 = {{0x9, 0x0, 0x0, 0x80010000}};
  // -1978261412184994287.6
  decimal dec_check = {{0x257df35c, 0x1289f6bb, 0x1, 0x80010000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_27) {
  // -9.6034339131
  decimal dec_1 = {{0x5c17b93b, 0x16, 0x0, 0x800a0000}};
  // -33264.4798510830
  decimal dec_2 = {{0xe70d36ee, 0x12e89, 0x0, 0x800a0000}};
  // 319453.23390352211996288730
  decimal dec_check = {{0x441fa6da, 0x73769c22, 0x1a6caf, 0x140000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_28) {
  // 13802
  decimal dec_1 = {{0x35ea, 0x0, 0x0, 0x0}};
  // -79564922823519710344668
  decimal dec_2 = {{0x8e65f5dc, 0x391daaf6, 0x10d9, 0x80000000}};
  // -1098155064810219042177107736
  decimal dec_check = {{0x45194718, 0x598350d9, 0x38c5f61, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_29) {
  // -9587.108
  decimal dec_1 = {{0x9249a4, 0x0, 0x0, 0x80030000}};
  // 8678288708349202907
  decimal dec_2 = {{0xc77011db, 0x786f7999, 0x0, 0x0}};
  // -83199691102124309983322.956
  decimal dec_check = {{0xe7c8e34c, 0x4aca7e4c, 0x44d238, 0x80030000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_30) {
  // -796733.80523
  decimal dec_1 = {{0x8ce74eab, 0x12, 0x0, 0x80050000}};
  // 713.81606362897
  decimal dec_2 = {{0xd34a6f11, 0x40eb, 0x0, 0xb0000}};
  // -568721388.6094090709655131
  decimal dec_check = {{0x54e65e5b, 0x7b876400, 0x4b450, 0x80100000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_31) {
  // -8888
  decimal dec_1 = {{0x22b8, 0x0, 0x0, 0x80000000}};
  // 8589911651772546730127.7
  decimal dec_2 = {{0xc3cfd59d, 0x99b63fd8, 0x1230, 0x10000}};
  // -76347134760954395337374997.6
  decimal dec_check = {{0x57c062d8, 0xaf78adce, 0x2778758, 0x80010000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_32) {
  // -349734995202758107907
  decimal dec_1 = {{0x57576303, 0xf58c4d29, 0x12, 0x80000000}};
  // -0.7817259478403015411893345277
  decimal dec_2 = {{0xb2811bfd, 0x77e7430d, 0x19424915, 0x801c0000}};
  // 273396920617799394392.24991859
  decimal dec_check = {{0xfba6b073, 0x6c5f0f8e, 0x5856dcfc, 0x80000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_33) {
  // -29.56
  decimal dec_1 = {{0xb8c, 0x0, 0x0, 0x80020000}};
  // -47
  decimal dec_2 = {{0x2f, 0x0, 0x0, 0x80000000}};
  // 1389.32
  decimal dec_check = {{0x21eb4, 0x0, 0x0, 0x20000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_34) {
  // 8610.327
  decimal dec_1 = {{0x836217, 0x0, 0x0, 0x30000}};
  // -57314.883
  decimal dec_2 = {{0x36a8e43, 0x0, 0x0, 0x80030000}};
  // -493499884.596741
  decimal dec_check = {{0xe5516e05, 0x1c0d5, 0x0, 0x80060000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_35) {
  // 365
  decimal dec_1 = {{0x16d, 0x0, 0x0, 0x0}};
  // -4906967963019
  decimal dec_2 = {{0x7e15158b, 0x476, 0x0, 0x80000000}};
  // -1791043306501935
  decimal dec_check = {{0xc40fb72f, 0x65cf1, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_36) {
  // 6514285374.99986407777787637
  decimal dec_1 = {{0xe3625ef5, 0xc76134ef, 0x21ad95b, 0x110000}};
  // -2748786096140
  decimal dec_2 = {{0x6b380c, 0x280, 0x0, 0x80000000}};
  // -17906377065087772331385.670113
  decimal dec_check = {{0xf55dc9e1, 0xc400e581, 0x39dbced5, 0x80060000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_37) {
  // -64998.907119283204927824
  decimal dec_1 = {{0xcc2e3150, 0x990a6e04, 0xdc3, 0x80120000}};
  // 852.1
  decimal dec_2 = {{0x2149, 0x0, 0x0, 0x10000}};
  // -55385568.7563412189189988304
  decimal dec_check = {{0x2d875fd0, 0xfc27fdb0, 0x1ca2380, 0x80130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_38) {
  // 1825139952592
  decimal dec_1 = {{0xf2d18bd0, 0x1a8, 0x0, 0x0}};
  // -68937864
  decimal dec_2 = {{0x41be888, 0x0, 0x0, 0x80000000}};
  // -125821249832753743488
  decimal dec_check = {{0xe4f6c680, 0xd21ee017, 0x6, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_39) {
  // -74
  decimal dec_1 = {{0x4a, 0x0, 0x0, 0x80000000}};
  // 57448790.8
  decimal dec_2 = {{0x223dfd64, 0x0, 0x0, 0x10000}};
  // -4251210519.2
  decimal dec_check = {{0xe5eb3ee8, 0x9, 0x0, 0x80010000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_40) {
  // 100249243.49155814
  decimal dec_1 = {{0x96bb49e6, 0x239d9d, 0x0, 0x80000}};
  // -74.7802
  decimal dec_2 = {{0xb691a, 0x0, 0x0, 0x80040000}};
  // -7496658478.147416020828
  decimal dec_check = {{0x4d36d75c, 0x65091ee0, 0x196, 0x800c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_41) {
  // 400012.9
  decimal dec_1 = {{0x3d0981, 0x0, 0x0, 0x10000}};
  // -1058332821114603817
  decimal dec_2 = {{0xf0ac4929, 0xeaff417, 0x0, 0x80000000}};
  // -423346780939233905189239.3
  decimal dec_check = {{0xc4284ea9, 0xbff33093, 0x38078, 0x80010000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_42) {
  // 3203771625105183
  decimal dec_1 = {{0x35a7e71f, 0xb61d0, 0x0, 0x0}};
  // 0.5374753090410767228001975
  decimal dec_2 = {{0xe062deb7, 0xf2e87a43, 0x47225, 0x190000}};
  // 1721948144300440.8293861308678
  decimal dec_check = {{0xfd573906, 0x7a9d264f, 0x37a39f07, 0xd0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_43) {
  // -76
  decimal dec_1 = {{0x4c, 0x0, 0x0, 0x80000000}};
  // 462.12987029387982463
  decimal dec_2 = {{0x3867b67f, 0x815582db, 0x2, 0x110000}};
  // -35121.87014233486667188
  decimal dec_check = {{0xbeca2db4, 0x6562d914, 0xbe, 0x80110000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_44) {
  // -0.681995
  decimal dec_1 = {{0xa680b, 0x0, 0x0, 0x80060000}};
  // 7170132028425854235
  decimal dec_2 = {{0x42f95d1b, 0x63816d17, 0x0, 0x0}};
  // -4889994192726290458.998825
  decimal dec_check = {{0xd197f829, 0x1dc9c0f2, 0x40b7f, 0x80060000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_45) {
  // -75940
  decimal dec_1 = {{0x128a4, 0x0, 0x0, 0x80000000}};
  // 159337299102.29199473934
  decimal dec_2 = {{0x942fcd0e, 0xc4ec34d5, 0x35f, 0xb0000}};
  // -12100074493828054.08050547960
  decimal dec_check = {{0x33b78cf8, 0x4468cc2a, 0x3e8e50b, 0x800b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_46) {
  // -4101.4
  decimal dec_1 = {{0xa036, 0x0, 0x0, 0x80010000}};
  // 6844885649245932100
  decimal dec_2 = {{0x73790a44, 0x5efdeb3b, 0x0, 0x0}};
  // -28073614001817265914940.0
  decimal dec_check = {{0x1f2aa58, 0xbc94c6b6, 0x3b72, 0x80010000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_47) {
  // 0.232507557513457844533002
  decimal dec_1 = {{0x805eb70a, 0x428c00a7, 0x313c, 0x180000}};
  // -603
  decimal dec_2 = {{0x25b, 0x0, 0x0, 0x80000000}};
  // -140.202057180615080253400206
  decimal dec_check = {{0x5f19248e, 0xbfc58a8b, 0x73f8f0, 0x80180000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_48) {
  // 1612287268526
  decimal dec_1 = {{0x63cf56ae, 0x177, 0x0, 0x0}};
  // 855202335431776
  decimal dec_2 = {{0x4f6a1c60, 0x309cd, 0x0, 0x0}};
  // 1378831837430354155865082176
  decimal dec_check = {{0xb1478940, 0xae84729f, 0x4748aff, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_49) {
  // 2361.244786674
  decimal dec_1 = {{0xc5281ff2, 0x225, 0x0, 0x90000}};
  // 30
  decimal dec_2 = {{0x1e, 0x0, 0x0, 0x0}};
  // 70837.343600220
  decimal dec_check = {{0x1ab3be5c, 0x406d, 0x0, 0x90000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_50) {
  // -150575
  decimal dec_1 = {{0x24c2f, 0x0, 0x0, 0x80000000}};
  // 4046017
  decimal dec_2 = {{0x3dbcc1, 0x0, 0x0, 0x0}};
  // -609229009775
  decimal dec_check = {{0xd8e0f36f, 0x8d, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_mul_1) {
  // -76908386688732265.5402547863
  decimal dec_1 = {{0xb94da97, 0xf7135ff5, 0x27c2bd7, 0x800a0000}};
  // -72300252012090952495415
  decimal dec_2 = {{0x1e83b137, 0x678e4dd8, 0xf4f, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_2) {
  // -22634920045391081199
  decimal dec_1 = {{0x38e76eef, 0x3a1f63db, 0x1, 0x80000000}};
  // -5628124561630351424899269
  decimal dec_2 = {{0x91b248c5, 0x3e6c18e3, 0x4a7cd, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_3) {
  // -9722600497183782024092
  decimal dec_1 = {{0xbb9b339c, 0x102fc7a4, 0x20f, 0x80000000}};
  // 60750360238724
  decimal dec_2 = {{0x8ba45a84, 0x3740, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_4) {
  // 519613162
  decimal dec_1 = {{0x1ef8aaea, 0x0, 0x0, 0x0}};
  // 39179118356223644860874
  decimal dec_2 = {{0xb09b01ca, 0xe77db51e, 0x84b, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_5) {
  // -4287197588542.81393
  decimal dec_1 = {{0x66b358b1, 0x5f31e59, 0x0, 0x80050000}};
  // -2743845602930966259915429486
  decimal dec_2 = {{0x126a166e, 0x2ee173a1, 0x8dda7e8, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_6) {
  // 3179489958489744830415
  decimal dec_1 = {{0x2eb96fcf, 0x5c497796, 0xac, 0x0}};
  // -2648523842648
  decimal dec_2 = {{0xa852a458, 0x268, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_7) {
  // -5930865841818996600903204
  decimal dec_1 = {{0x50b69624, 0xe1ab5c6a, 0x4e7e8, 0x80000000}};
  // -2183908363629526789
  decimal dec_2 = {{0xfc247f05, 0x1e4ecd15, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_8) {
  // -4658935322280502056684
  decimal dec_1 = {{0x515d56ec, 0x8fb73f84, 0xfc, 0x80000000}};
  // 2788148916869268649212
  decimal dec_2 = {{0x82e234fc, 0x2556cba5, 0x97, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_9) {
  // -8360458349737706775688325
  decimal dec_1 = {{0xf2d4b485, 0x5af427ae, 0x6ea65, 0x80000000}};
  // -4598476
  decimal dec_2 = {{0x462acc, 0x0, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_10) {
  // -63174606368206944340451548
  decimal dec_1 = {{0x7b6a0dc, 0x46052a82, 0x3441be, 0x80000000}};
  // 51375035219019.506969
  decimal dec_2 = {{0xc8d72519, 0xc8f8ca55, 0x2, 0x60000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_11) {
  // -61713460015105594129647083055
  decimal dec_1 = {{0xb3571e2f, 0xffad69b8, 0xc7682d7a, 0x80000000}};
  // -28875097
  decimal dec_2 = {{0x1b89959, 0x0, 0x0, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_12) {
  // -9332900763625843
  decimal dec_1 = {{0x4abd6973, 0x212839, 0x0, 0x80000000}};
  // 9844064770090280
  decimal dec_2 = {{0xefc46528, 0x22f91f, 0x0, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_13) {
  // 6050442817.8
  decimal dec_1 = {{0x16584e92, 0xe, 0x0, 0x10000}};
  // -5456714823605659803770877662
  decimal dec_2 = {{0x4f3af6de, 0x51c14a47, 0x11a1b04f, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_14) {
  // -61435414038846428322502571
  decimal dec_1 = {{0x438c97ab, 0x77ea9500, 0x32d174, 0x80000000}};
  // -64136479129306861261708023
  decimal dec_2 = {{0x75a25af7, 0x8018ca94, 0x350d6d, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_15) {
  // -930968.7
  decimal dec_1 = {{0x8e0df7, 0x0, 0x0, 0x80010000}};
  // 79228162514264337592073309481
  decimal dec_2 = {{0xa857cd29, 0xffffffff, 0xffffffff, 0x0}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 2;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_mul_16) {
  // -11684397037.721510498716
  decimal dec_1 = {{0x1120519c, 0x69952f38, 0x279, 0x800c0000}};
  // -6233300238250783348155666659
  decimal dec_2 = {{0xd9ded0e3, 0xd7fabb, 0x142410ab, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  // overflow
  int check = 1;
  int return_value = mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite* suite_mul(void) {
  Suite* c = suite_create("mul_cases");
  TCase* tc = tcase_create("mul_tc");

  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, mul_13);
  tcase_add_test(tc, mul_14);
  tcase_add_test(tc, mul_15);
  tcase_add_test(tc, mul_16);
  tcase_add_test(tc, mul_17);
  tcase_add_test(tc, mul_18);
  tcase_add_test(tc, mul_19);
  tcase_add_test(tc, mul_20);
  tcase_add_test(tc, mul_21);
  tcase_add_test(tc, mul_22);
  tcase_add_test(tc, mul_23);
  tcase_add_test(tc, mul_24);
  tcase_add_test(tc, mul_25);
  tcase_add_test(tc, mul_26);
  tcase_add_test(tc, mul_27);
  tcase_add_test(tc, mul_28);
  tcase_add_test(tc, mul_29);
  tcase_add_test(tc, mul_30);
  tcase_add_test(tc, mul_31);
  tcase_add_test(tc, mul_32);
  tcase_add_test(tc, mul_33);
  tcase_add_test(tc, mul_34);
  tcase_add_test(tc, mul_35);
  tcase_add_test(tc, mul_36);
  tcase_add_test(tc, mul_37);
  tcase_add_test(tc, mul_38);
  tcase_add_test(tc, mul_39);
  tcase_add_test(tc, mul_40);
  tcase_add_test(tc, mul_41);
  tcase_add_test(tc, mul_42);
  tcase_add_test(tc, mul_43);
  tcase_add_test(tc, mul_44);
  tcase_add_test(tc, mul_45);
  tcase_add_test(tc, mul_46);
  tcase_add_test(tc, mul_47);
  tcase_add_test(tc, mul_48);
  tcase_add_test(tc, mul_49);
  tcase_add_test(tc, mul_50);
  tcase_add_test(tc, fail_mul_1);
  tcase_add_test(tc, fail_mul_2);
  tcase_add_test(tc, fail_mul_3);
  tcase_add_test(tc, fail_mul_4);
  tcase_add_test(tc, fail_mul_5);
  tcase_add_test(tc, fail_mul_6);
  tcase_add_test(tc, fail_mul_7);
  tcase_add_test(tc, fail_mul_8);
  tcase_add_test(tc, fail_mul_9);
  tcase_add_test(tc, fail_mul_10);
  tcase_add_test(tc, fail_mul_11);
  tcase_add_test(tc, fail_mul_12);
  tcase_add_test(tc, fail_mul_13);
  tcase_add_test(tc, fail_mul_14);
  tcase_add_test(tc, fail_mul_15);
  tcase_add_test(tc, fail_mul_16);

  suite_add_tcase(c, tc);
  return c;
}
