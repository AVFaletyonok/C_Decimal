#include "decimal_tests.h"

// Div tests:
START_TEST(div_1) {
  // 43275163157541830.43
  decimal dec_1 = {{0x383c3983, 0x3c0e6d29, 0x0, 0x20000}};
  // 598900237697303
  decimal dec_2 = {{0x53ec8117, 0x220b2, 0x0, 0x0}};
  // 72.257715782397174843307171358
  decimal dec_check = {{0x66639e1e, 0x81794888, 0xe97a2e7d, 0x1b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_2) {
  // -49602691395915219137819672
  decimal dec_1 = {{0x760d7418, 0x49e39681, 0x2907c7, 0x80000000}};
  // -72949
  decimal dec_2 = {{0x11cf5, 0x0, 0x0, 0x80000000}};
  // 679963966550812473616.08345556
  decimal dec_check = {{0x43f667d4, 0xbb33c640, 0xdbb54d10, 0x80000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_3) {
  // -79228162514264337593445784316
  decimal dec_1 = {{0xfa261afc, 0xffffffff, 0xffffffff, 0x80000000}};
  // -254.4570517
  decimal dec_2 = {{0x97ab1095, 0x0, 0x0, 0x80070000}};
  // 311361630518586793770690318.49
  decimal dec_check = {{0xc6f341a9, 0x2f3514bc, 0x649b3afd, 0x20000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_4) {
  // 86919275181527.6498843
  decimal dec_1 = {{0x6dd20f9b, 0x1e78fa98, 0x2f, 0x70000}};
  // 19676559
  decimal dec_2 = {{0x12c3d8f, 0x0, 0x0, 0x0}};
  // 4417402.2084617361137330973368
  decimal dec_check = {{0x554e6ab8, 0x9407849e, 0x8ebbe507, 0x160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_5) {
  decimal dec_1 = {{10, 0, 0, 0}};  // 0.1
  set_dec_scale(&dec_1, 1);
  decimal dec_2 = {{50, 0, 0, 0}};  // -0.5
  set_dec_scale(&dec_2, 1);
  set_dec_bit(&dec_2, 127, 1);

  decimal dec_check = {{2, 0, 0, 0}};
  set_dec_scale(&dec_check, 1);
  set_dec_bit(&dec_check, 127, 1);
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_6) {
  // 45261705.212386921663
  decimal dec_1 = {{0x78c4ccbf, 0x7421e115, 0x2, 0xc0000}};
  // 2.6
  decimal dec_2 = {{0x1a, 0x0, 0x0, 0x10000}};
  // 17408348.158610354485769230769
  decimal dec_check = {{0xb88f59b1, 0xa5c084cb, 0x383fd91c, 0x150000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_7) {
  // 236151598792626
  decimal dec_1 = {{0x5428bfb2, 0xd6c7, 0x0, 0x0}};
  // -820368029
  decimal dec_2 = {{0x30e5d29d, 0x0, 0x0, 0x80000000}};
  // -287860.55824297121651970179350
  decimal dec_check = {{0xc9028116, 0x197f3698, 0x5d03446d, 0x80170000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_9) {
  // -7393131868
  decimal dec_1 = {{0xb8aa3d5c, 0x1, 0x0, 0x80000000}};
  // 6897025424
  decimal dec_2 = {{0x9b184190, 0x1, 0x0, 0x0}};
  // -1.0719304937275811903691193353
  decimal dec_check = {{0x5a5a7c09, 0x6c585c7, 0x22a2cd1d, 0x801c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_10) {
  // 79228162514264337591706824603
  decimal dec_1 = {{0x927faf9b, 0xffffffff, 0xffffffff, 0x0}};
  // -24333978469557104302
  decimal dec_2 = {{0xb9f46eae, 0x51b3a87d, 0x1, 0x80000000}};
  // -3255865563.1828684873044051906
  decimal dec_check = {{0x8163c7c2, 0x7638bc28, 0x6933e382, 0x80130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_11) {
  // -13430974181486911990608159
  decimal dec_1 = {{0x84cd311f, 0x91be2f56, 0xb1c1e, 0x80000000}};
  // 63636794001266514835.174301102
  decimal dec_2 = {{0xd5939dae, 0x4f2d3595, 0xcd9f1f4b, 0x90000}};
  // -211056.73835830896038561998793
  decimal dec_check = {{0xc69067c9, 0x3a9a432a, 0x44323447, 0x80170000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_13) {
  // 5300099092.451597
  decimal dec_1 = {{0x7bae110d, 0x12d469, 0x0, 0x60000}};
  // -996900.4813
  decimal dec_2 = {{0x5232f10d, 0x2, 0x0, 0x80040000}};
  // -5316.5779251506085113974555767
  decimal dec_check = {{0x317d0477, 0x518186c1, 0xabc9b3ac, 0x80190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_14) {
  // 554255712268612078736666
  decimal dec_1 = {{0xea79151a, 0x432a87ae, 0x755e, 0x0}};
  // 29054
  decimal dec_2 = {{0x717e, 0x0, 0x0, 0x0}};
  // 19076743727838234967.187512907
  decimal dec_check = {{0x74e1de4b, 0xaefe8ecd, 0x3da3e99d, 0x90000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_15) {
  // -19548294043336
  decimal dec_1 = {{0x711f56c8, 0x11c7, 0x0, 0x80000000}};
  // 97467.8
  decimal dec_2 = {{0xedf56, 0x0, 0x0, 0x10000}};
  // -200561560.26232253113335891443
  decimal dec_check = {{0xe00545f3, 0xc4786c89, 0x40ce103c, 0x80140000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_16) {
  // -2018259817598477358.72
  decimal dec_1 = {{0x38312240, 0xf0e5ed17, 0xa, 0x80020000}};
  // 304893.0730032967
  decimal dec_2 = {{0x811bbf47, 0xad4fc, 0x0, 0xa0000}};
  // -6619565993146.2419138344766012
  decimal dec_check = {{0xe7edca3c, 0x5714c42c, 0xd5e3c43b, 0x80100000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_18) {
  // 39076786
  decimal dec_1 = {{0x25443b2, 0x0, 0x0, 0x0}};
  // -345.878092176210991705157
  decimal dec_2 = {{0xa77eec45, 0x16c54597, 0x493e, 0x80150000}};
  // -112978.49411084396612021597746
  decimal dec_check = {{0x4ef73632, 0xcbabb838, 0x24815cab, 0x80170000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_19) {
  decimal dec_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x0}};
  decimal dec_2 = {{0xa77eec45, 0x0, 0x0, 0x80150000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(div_20) {
  // -3747902512650818001537882
  decimal dec_1 = {{0x37038b5a, 0x33cb815d, 0x319a6, 0x80000000}};
  // -168
  decimal dec_2 = {{0xa8, 0x0, 0x0, 0x80000000}};
  // 22308943527683440485344.535714
  decimal dec_check = {{0x6450e4a2, 0xedb4dc56, 0x4815868b, 0x60000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_21) {
  // -4333957121378
  decimal dec_1 = {{0x13f98562, 0x3f1, 0x0, 0x80000000}};
  // -223679
  decimal dec_2 = {{0x369bf, 0x0, 0x0, 0x80000000}};
  // 19375789.061011538857022787119
  decimal dec_check = {{0x96e90e2f, 0xadb0cec9, 0x3e9b46ed, 0x150000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_22) {
  // -67033825843600339
  decimal dec_1 = {{0xd157dbd3, 0xee26e8, 0x0, 0x80000000}};
  // -19680475212.39969182338
  decimal dec_2 = {{0xb4663282, 0xb0255967, 0x6a, 0x800b0000}};
  // 3406108.0903862345946854647549
  decimal dec_check = {{0xc80e6fd, 0xa89a4951, 0x6e0eaa6f, 0x160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_23) {
  // -65381311009921061922265
  decimal dec_1 = {{0xc0f8a5d9, 0x53f5f67d, 0xdd8, 0x80000000}};
  // 173724538017219508.786403
  decimal dec_2 = {{0x5ccd54e3, 0xa0468e9c, 0x24c9, 0x60000}};
  // -376350.46698722831975072830391
  decimal dec_check = {{0x4cea93b7, 0x9e103d7a, 0x799afb21, 0x80170000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_24) {
  // -8972950
  decimal dec_1 = {{0x88ea96, 0x0, 0x0, 0x80000000}};
  // -707883
  decimal dec_2 = {{0xacd2b, 0x0, 0x0, 0x80000000}};
  // 12.675752913970246495536691798
  decimal dec_check = {{0x63ac3a56, 0x5c5d676c, 0x28f52316, 0x1b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_25) {
  // 4561604.77
  decimal dec_1 = {{0x1b3074dd, 0x0, 0x0, 0x20000}};
  // -0.91118174
  decimal dec_2 = {{0x56e5a5e, 0x0, 0x0, 0x80080000}};
  // -5006251.2995486498664909593118
  decimal dec_check = {{0x714f5a1e, 0x7d50b968, 0xa1c2bd7b, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_26) {
  // -945698.1561020
  decimal dec_1 = {{0xe006cebc, 0x899, 0x0, 0x80070000}};
  // -173.305177
  decimal dec_2 = {{0xa546d59, 0x0, 0x0, 0x80060000}};
  // 5456.8373113400992054611271076
  decimal dec_check = {{0x971fdda4, 0xed6d2ed6, 0xb051e679, 0x190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_27) {
  // -815376080.9
  decimal dec_1 = {{0xe6008429, 0x1, 0x0, 0x80010000}};
  // 433.279544855078
  decimal dec_2 = {{0xc15c0a26, 0x18a10, 0x0, 0xc0000}};
  // -1881870.7012183657683677820606
  decimal dec_check = {{0x227336be, 0x4c83c927, 0x3cce7837, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_28) {
  // -9511894198945507026555408326
  decimal dec_1 = {{0x3908fc6, 0xbf58d60d, 0x1ebc0df1, 0x80000000}};
  // -4064191861789489650553.6246571
  decimal dec_2 = {{0x85fdf32b, 0xf99bf2b0, 0x83523506, 0x80070000}};
  // 2340414.6562011369269558682241
  decimal dec_check = {{0xb62ea281, 0x62958203, 0x4b9f74cf, 0x160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_29) {
  // 588.894056537673286124874
  decimal dec_1 = {{0xc35d854a, 0x2c20694, 0x7cb4, 0x150000}};
  // 267
  decimal dec_2 = {{0x10b, 0x0, 0x0, 0x0}};
  // 2.2055957173695628693815505618
  decimal dec_check = {{0x682532d2, 0x32ca7eff, 0x4744429a, 0x1c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_30) {
  // 146329733317719891839425.5
  decimal dec_1 = {{0x242e618f, 0x81e3bb1e, 0x135dd, 0x10000}};
  // 45811755346054363859361
  decimal dec_2 = {{0x70c5c9a1, 0x75d1de27, 0x9b3, 0x0}};
  // 3.1941525098169558661295009580
  decimal dec_check = {{0xc67c6f2c, 0x3260811c, 0x67356909, 0x1c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_31) {
  // 269073.793236796203166
  decimal dec_1 = {{0xb624609e, 0x96262555, 0xe, 0xf0000}};
  // -4242
  decimal dec_2 = {{0x1092, 0x0, 0x0, 0x80000000}};
  // -63.430880065251344452145214521
  decimal dec_check = {{0xdec57439, 0x787c765e, 0xccf4cb52, 0x801b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_32) {
  // -5374350863799186
  decimal dec_1 = {{0x92229392, 0x1317f1, 0x0, 0x80000000}};
  // -9880362
  decimal dec_2 = {{0x96c32a, 0x0, 0x0, 0x80000000}};
  // 543942708.15170395578623536263
  decimal dec_check = {{0xad432c87, 0x6dbabd15, 0xafc1e2e1, 0x140000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_33) {
  // 66.36
  decimal dec_1 = {{0x19ec, 0x0, 0x0, 0x20000}};
  // 0.262007044
  decimal dec_2 = {{0xf9de904, 0x0, 0x0, 0x90000}};
  // 253.27563330701902808384037186
  decimal dec_check = {{0x585c6142, 0x5876a01c, 0x51d67827, 0x1a0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_34) {
  // -5664431014523019498085782693
  decimal dec_1 = {{0x78d994a5, 0x978dbaf5, 0x124d81ec, 0x80000000}};
  // 62629440171938783906003
  decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // -90443.583703961902005283502731
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(div_35) {
  // 3782468153993765.194519846000
  decimal dec_1 = {{0x6ec49c70, 0x7ef0ede0, 0xc38c8c9, 0xc0000}};
  // -3038547373
  decimal dec_2 = {{0xb51c8dad, 0x0, 0x0, 0x80000000}};
  // -1244827.7711922858326026322579
  decimal dec_check = {{0x76ab8293, 0xf2cfbd86, 0x2838f956, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_36) {
  // 786414159735776946492
  decimal dec_1 = {{0xcc49293c, 0xa1b057ad, 0x2a, 0x0}};
  // -62261.5322113872260704114988
  decimal dec_2 = {{0x4d32192c, 0x3e30bbe7, 0x20303ec, 0x80160000}};
  // -12630819252340001.876971130099
  decimal dec_check = {{0xf2248cf3, 0xaed50a6c, 0x28cff803, 0x800c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_37) {
  // -271155612376876.564331
  decimal dec_1 = {{0x113dbf6b, 0xb30a40d0, 0xe, 0x80060000}};
  // -87452
  decimal dec_2 = {{0x1559c, 0x0, 0x0, 0x80000000}};
  // 3100622197.0552596204889539404
  decimal dec_check = {{0x5fb3834c, 0xd52d4cd, 0x642fbee5, 0x130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_38) {
  // 110791758516466883
  decimal dec_1 = {{0x726a34c3, 0x1899c84, 0x0, 0x0}};
  // 99385.6408864500530266067
  decimal dec_2 = {{0x145fbfd3, 0x105a8955, 0xd275, 0x130000}};
  // 1114766253236.2047344716464103
  decimal dec_check = {{0x4642bfe7, 0xc93e7a3b, 0x2405215c, 0x100000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_39) {
  // 669956133690611930475
  decimal dec_1 = {{0xb09156b, 0x51825203, 0x24, 0x0}};
  // -509281357245869
  decimal dec_2 = {{0x4e63adad, 0x1cf30, 0x0, 0x80000000}};
  // -1315493.1437381732917375160680
  decimal dec_check = {{0xdacc5168, 0x2a54d160, 0x2a818116, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_40) {
  // 578380870.86123
  decimal dec_1 = {{0x7aa2a02b, 0x349a, 0x0, 0x50000}};
  // 5656
  decimal dec_2 = {{0x1618, 0x0, 0x0, 0x0}};
  // 102259.70135453147100424328147
  decimal dec_check = {{0x70c653d3, 0xd4ddce99, 0x210ab967, 0x170000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_41) {
  // 79228162514264337593213201802
  decimal dec_1 = {{0xec492d8a, 0xffffffff, 0xffffffff, 0x0}};
  // -6663470252316270436442
  decimal dec_2 = {{0x35d6a05a, 0x3a39e9e7, 0x169, 0x80000000}};
  // -11889925.146244039355538476380
  decimal dec_check = {{0x2a3e0d5c, 0xb65f3ebd, 0x266b1d95, 0x80150000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_42) {
  // 251108673425397
  decimal dec_1 = {{0xcb478ff5, 0xe461, 0x0, 0x0}};
  // -1097829767108
  decimal dec_2 = {{0x9bc0d7c4, 0xff, 0x0, 0x80000000}};
  // -228.73188626219310400943349969
  decimal dec_check = {{0x98cee0d1, 0x2c961da, 0x49e84218, 0x801a0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_43) {
  // 507922970386960797081
  decimal dec_1 = {{0xc80ccd99, 0x88d8e279, 0x1b, 0x0}};
  // -1.9685019802954965772
  decimal dec_2 = {{0xfa9230c, 0x112f3d37, 0x1, 0x80130000}};
  // -258025125436102053442.19729253
  decimal dec_check = {{0x655f0d65, 0xc4b17bb9, 0x535f568f, 0x80080000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_44) {
  // -1314195068725676723330
  decimal dec_1 = {{0x2407cc82, 0x3e1ecc1a, 0x47, 0x80000000}};
  // 664442688295930515581.34
  decimal dec_2 = {{0xe5a370f6, 0xf376bfb0, 0xe11, 0x20000}};
  // -1.9778907825686818067307408499
  decimal dec_check = {{0x6351ac73, 0xb333d517, 0x3fe8baa5, 0x801c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_45) {
  // -73946382543831486649
  decimal dec_1 = {{0x8e38d0b9, 0x2365323, 0x4, 0x80000000}};
  // 7160299975
  decimal dec_2 = {{0xaac981c7, 0x1, 0x0, 0x0}};
  // -10327274388.225821034683676084
  decimal dec_check = {{0x8cf1b5b4, 0x60dff304, 0x215e856a, 0x80120000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_47) {
  // -6097707508866882967.20548440
  decimal dec_1 = {{0xddbe4258, 0xa4379716, 0x1f863fa, 0x80080000}};
  // 900091208.49301
  decimal dec_2 = {{0xe1acbd95, 0x51dc, 0x0, 0x50000}};
  // -6774544014.3516711505196337904
  decimal dec_check = {{0xbb71caf0, 0xfab8644b, 0xdae5b6f4, 0x80130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_48) {
  // -982608770665282731.06080916
  decimal dec_1 = {{0xd4161494, 0xd1bd307e, 0x51478c, 0x80080000}};
  // -3983060464619.639
  decimal dec_2 = {{0x881cd077, 0xe2692, 0x0, 0x80030000}};
  // 246696.92549071474372844674118
  decimal dec_check = {{0x7ae75c46, 0xd0090667, 0x4fb64a98, 0x170000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_49) {
  // -252630400081789733
  decimal dec_1 = {{0xa8570325, 0x3818602, 0x0, 0x80000000}};
  // -5597.691782
  decimal dec_2 = {{0x4da5ff86, 0x1, 0x0, 0x80060000}};
  // 45131173690940.051297022269670
  decimal dec_check = {{0x565058e6, 0x207c02eb, 0x91d3a1c4, 0xf0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_50) {
  // -939500084285486646559188568
  decimal dec_1 = {{0xf4972658, 0x9f23459e, 0x30922e1, 0x80000000}};
  // -719786672740807095
  decimal dec_2 = {{0x4ec6b1b7, 0x9fd322a, 0x0, 0x80000000}};
  // 1305247957.2983114350557777838
  decimal dec_check = {{0x1365cfae, 0x77b13b4d, 0x2a2cc20f, 0x130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_51) {
  // 19544731717348689.765183
  decimal dec_1 = {{0x7f04e33f, 0x85a3b880, 0x423, 0x60000}};
  // -673175064988
  decimal dec_2 = {{0xbc5c519c, 0x9c, 0x0, 0x80000000}};
  // -29033.653701503476825305526909
  decimal dec_check = {{0x90ee327d, 0xeb0832b3, 0x5dd01350, 0x80180000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_52) {
  // -7090414069683
  decimal dec_1 = {{0xdd9ca7b3, 0x672, 0x0, 0x80000000}};
  // 3587242854895
  decimal dec_2 = {{0x385609ef, 0x343, 0x0, 0x0}};
  // -1.9765637166181042376750098635
  decimal dec_check = {{0xef7368cb, 0xce82f58d, 0x3fddc079, 0x801c0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_53) {
  // 44055327263753
  decimal dec_1 = {{0x6e21cc09, 0x2811, 0x0, 0x0}};
  // 18.721916687687627086652
  decimal dec_2 = {{0x6ee09b3c, 0xeac9827c, 0x3f6, 0x150000}};
  // 2353141935127.0674665122189162
  decimal dec_check = {{0x2d4a4f6a, 0x1da222b8, 0x4c08bbdf, 0x100000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_54) {
  // 1111130522177738
  decimal dec_1 = {{0x3c12d0ca, 0x3f291, 0x0, 0x0}};
  // -89.400530
  decimal dec_2 = {{0x55424d2, 0x0, 0x0, 0x80060000}};
  // -12428679362166.398789805832247
  decimal dec_check = {{0x8f367837, 0x47820cd1, 0x2828c33a, 0x800f0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_55) {
  // 69498191722
  decimal dec_1 = {{0x2e6a3f6a, 0x10, 0x0, 0x0}};
  // -0.3349266230533
  decimal dec_2 = {{0xcfd2ed05, 0x30b, 0x0, 0x800d0000}};
  // -207502739222.19704821571290058
  decimal dec_check = {{0x19fa83ca, 0x4e97445a, 0x430c396b, 0x80110000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_57) {
  // -23015468395831171591232888
  decimal dec_1 = {{0xfae8dd78, 0xab1deb9, 0x1309b7, 0x80000000}};
  // 2126769062407733523435977
  decimal dec_2 = {{0x6c0ad1c9, 0x61c3aa69, 0x1c25c, 0x0}};
  // -10.821799509240162694924828527
  decimal dec_check = {{0xe37f7f6f, 0xe7f212ee, 0x22f7952e, 0x801b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_59) {
  // 27444167462495432913726163
  decimal dec_1 = {{0x9fcc2ad3, 0x4c9b4c95, 0x16b387, 0x0}};
  // 9
  decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // 3049351940277270323747351.4444
  decimal dec_check = {{0x90cf33cc, 0x29271085, 0x6287a5e7, 0x40000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_60) {
  // -98.5
  decimal dec_1 = {{0x3d9, 0x0, 0x0, 0x80010000}};
  // -3
  decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 32.833333333333333333333333333
  decimal dec_check = {{0xc1555555, 0x7f3dc7cf, 0x6a1718c6, 0x1b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_61) {
  // 563.53
  decimal dec_1 = {{0xdc21, 0x0, 0x0, 0x20000}};
  // -0.4096173
  decimal dec_2 = {{0x3e80ad, 0x0, 0x0, 0x80070000}};
  // -1375.7475575372426897008500373
  decimal dec_check = {{0xe7a1e95, 0x563569b8, 0x2c73eac5, 0x80190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_64) {
  // -254279127451949894204.2216
  decimal dec_1 = {{0x7117d068, 0xfdbf51ea, 0x21a74, 0x80040000}};
  // 9413224420
  decimal dec_2 = {{0x311267e4, 0x2, 0x0, 0x0}};
  // -27012967725.670126348078887086
  decimal dec_check = {{0xf47330ae, 0xac30b721, 0x57489a6a, 0x80120000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_65) {
  // -852843361383576343468
  decimal dec_1 = {{0xde2993ac, 0x3b94469e, 0x2e, 0x80000000}};
  // -44582872689626705206
  decimal dec_2 = {{0x43a9ed36, 0x6ab62e80, 0x2, 0x80000000}};
  // 19.129394539486711726784477354
  decimal dec_check = {{0x9cd78aa, 0xe6f60cca, 0x3dcf76db, 0x1b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_66) {
  // -984550
  decimal dec_1 = {{0xf05e6, 0x0, 0x0, 0x80000000}};
  // 0.6251
  decimal dec_2 = {{0x186b, 0x0, 0x0, 0x40000}};
  // -1575027.9955207166853303471445
  decimal dec_check = {{0x24cf8d55, 0x3c09d7be, 0x32e45383, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_67) {
  // 22131.1
  decimal dec_1 = {{0x3607f, 0x0, 0x0, 0x10000}};
  // -387.1833724
  decimal dec_2 = {{0xe6c77e7c, 0x0, 0x0, 0x80070000}};
  // -57.159221127751094509553375645
  decimal dec_check = {{0xfc68d99d, 0x36dfe891, 0xb8b0ffe2, 0x801b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_68) {
  // -333479254346
  decimal dec_1 = {{0xa4e9994a, 0x4d, 0x0, 0x80000000}};
  // 85.90
  decimal dec_2 = {{0x218e, 0x0, 0x0, 0x20000}};
  // -3882179910.8963911525029103609
  decimal dec_check = {{0x4d3c7f9, 0xafcd2fe9, 0x7d70a3ba, 0x80130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_69) {
  // 7202791154122484460
  decimal dec_1 = {{0x84cbeaec, 0x63f57464, 0x0, 0x0}};
  // -934893331897
  decimal dec_2 = {{0xabfc25b9, 0xd9, 0x0, 0x80000000}};
  // -7704398.8959759074913217141992
  decimal dec_check = {{0xb453dce8, 0x5b22d77f, 0xf8f14b42, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_70) {
  // 1850354199923853549245524615
  decimal dec_1 = {{0xf53f6a87, 0x2bd76e6a, 0x5fa93be, 0x0}};
  // 99873170022.1
  decimal dec_2 = {{0x890c57fd, 0xe8, 0x0, 0x10000}};
  // 18527039839772843.585384791248
  decimal dec_check = {{0xafe8bcd0, 0x334ad28a, 0x3bdd354a, 0xc0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_71) {
  // -9332542099
  decimal dec_1 = {{0x2c434a93, 0x2, 0x0, 0x80000000}};
  // 0.798
  decimal dec_2 = {{0x31e, 0x0, 0x0, 0x30000}};
  // -11694914911.027568922305764411
  decimal dec_check = {{0xdefc1c3b, 0xadaf965f, 0x25c9ce8f, 0x80120000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_72) {
  // -569694617635.0760
  decimal dec_1 = {{0xa5255a28, 0x143d57, 0x0, 0x80040000}};
  // 0.90252495
  decimal dec_2 = {{0x56124cf, 0x0, 0x0, 0x80000}};
  // -631223123122.60841099185125021
  decimal dec_check = {{0x2aa0769d, 0x10265df0, 0xcbf58d8f, 0x80110000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_73) {
  // -427749023236760
  decimal dec_1 = {{0x14954298, 0x18509, 0x0, 0x80000000}};
  // 0.6604824401
  decimal dec_2 = {{0x89ad9f51, 0x1, 0x0, 0xa0000}};
  // -647631181794926.87469557451449
  decimal dec_check = {{0x2bee0ab9, 0x5b6910f0, 0xd142cbb7, 0x800e0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_74) {
  // 15717466727393151
  decimal dec_1 = {{0xe50e277f, 0x37d6f3, 0x0, 0x0}};
  // -6678481283707
  decimal dec_2 = {{0xf4812a7b, 0x612, 0x0, 0x80000000}};
  // -2353.4492438779306802136474609
  decimal dec_check = {{0x46fbe3f1, 0x85fe3437, 0x4c0b469f, 0x80190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_75) {
  // 37841724249862.03035508
  decimal dec_1 = {{0xc3289774, 0x23f1231e, 0xcd, 0x80000}};
  // -483.49749472
  decimal dec_2 = {{0x41dea0e0, 0xb, 0x0, 0x80080000}};
  // -78266639771.891040492794055402
  decimal dec_check = {{0x43068aea, 0xb0f49e0b, 0xfce4a5a3, 0x80120000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_76) {
  // 4671486509.536
  decimal dec_1 = {{0xaa4b41e0, 0x43f, 0x0, 0x30000}};
  // -9788508.546346
  decimal dec_2 = {{0x1093252a, 0x8e7, 0x0, 0x80060000}};
  // -477.24190947147325495351008031
  decimal dec_check = {{0x466d5b1f, 0x4021566b, 0x9a348687, 0x801a0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_77) {
  // -9501762904059
  decimal dec_1 = {{0x4d33dffb, 0x8a4, 0x0, 0x80000000}};
  // 302159241
  decimal dec_2 = {{0x12029589, 0x0, 0x0, 0x0}};
  // -31446.209861438591580258834447
  decimal dec_check = {{0x40c2180f, 0x690c16db, 0x659bb1f4, 0x80180000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_79) {
  // 8578521603506084967.398642
  decimal dec_1 = {{0x8e08bcf2, 0x9684a963, 0x71892, 0x60000}};
  // 4.3891227
  decimal dec_2 = {{0x29dba1b, 0x0, 0x0, 0x70000}};
  // 1954495736358904928.1758839870
  decimal dec_check = {{0x595b443e, 0xbcab641e, 0x3f2735b5, 0xa0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_80) {
  // -468227949850749460732042359
  decimal dec_1 = {{0xc95ddc77, 0x5b778fa, 0x1834f20, 0x80000000}};
  // -60803113131115339.5
  decimal dec_2 = {{0xaa2e20f3, 0x8702917, 0x0, 0x80010000}};
  // 7700723297.5237059191634176380
  decimal dec_check = {{0xa1f4a97c, 0x7145b271, 0xf8d2e3e0, 0x130000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_81) {
  // 24017590417556158490830937495
  decimal dec_1 = {{0x946f9d97, 0x6dd7995b, 0x4d9ae299, 0x0}};
  // 5838421859944
  decimal dec_2 = {{0x5d0f9e68, 0x54f, 0x0, 0x0}};
  // 4113712745277116.1014676072066
  decimal dec_check = {{0xb755a682, 0xb493b624, 0x84ebd593, 0xd0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_82) {
  // 310653381120315187
  decimal dec_1 = {{0xadf34f33, 0x44fa99a, 0x0, 0x0}};
  // -7789431
  decimal dec_2 = {{0x76db77, 0x0, 0x0, 0x80000000}};
  // -39881395845.256885515771306017
  decimal dec_check = {{0x6a71e021, 0xdbed9a60, 0x80dd1e10, 0x80120000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_83) {
  // -483396566
  decimal dec_1 = {{0x1cd00bd6, 0x0, 0x0, 0x80000000}};
  // -23874708
  decimal dec_2 = {{0x16c4c94, 0x0, 0x0, 0x80000000}};
  // 20.247224217360061534574579928
  decimal dec_check = {{0x5d90d8, 0x29c3db83, 0x416c1c80, 0x1b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_84) {
  // -522165187
  decimal dec_1 = {{0x1f1f9bc3, 0x0, 0x0, 0x80000000}};
  // 491192.690002
  decimal dec_2 = {{0x5d5da552, 0x72, 0x0, 0x60000}};
  // -1063.0556961217681977469095959
  decimal dec_check = {{0x14f0d017, 0x9aa9f1ed, 0x225963ff, 0x80190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_85) {
  // 491939402026660335462
  decimal dec_1 = {{0x912b0f66, 0xab07d7bc, 0x1a, 0x0}};
  // 4275
  decimal dec_2 = {{0x10b3, 0x0, 0x0, 0x0}};
  // 115073544333721715.89754385965
  decimal dec_check = {{0x9731762d, 0xcfa6e6ce, 0x252ea915, 0xb0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_86) {
  // 884979533
  decimal dec_1 = {{0x34bfb74d, 0x0, 0x0, 0x0}};
  // -6062988.28977248369382
  decimal dec_2 = {{0x5c337ae6, 0xde1624a5, 0x20, 0x800e0000}};
  // -145.96424909691013881025760576
  decimal dec_check = {{0x4c7b8d40, 0xe163a1a8, 0x2f29e133, 0x801a0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_87) {
  // 5799357489691093491443574656
  decimal dec_1 = {{0xaa382780, 0x7797aed2, 0x12bd1db7, 0x0}};
  // 4017905178.2866896
  decimal dec_2 = {{0x7cee07d0, 0x8ebea2, 0x0, 0x70000}};
  // 1443378385590485410.7609785484
  decimal dec_check = {{0x44fe648c, 0xb01b037e, 0x2ea3589e, 0xa0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_88) {
  // 32969406056025020154
  decimal dec_1 = {{0xe8fbd6fa, 0xc98adc20, 0x1, 0x0}};
  // 7103527805152659
  decimal dec_2 = {{0xf37a6d93, 0x193c9e, 0x0, 0x0}};
  // 4641.2721904333403510455656892
  decimal dec_check = {{0xd553e1bc, 0xfb70eac9, 0x95f7b427, 0x190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_89) {
  // 6259921.677402707
  decimal dec_1 = {{0x97e74253, 0x163d5d, 0x0, 0x90000}};
  // -4.8704056794853980127818
  decimal dec_2 = {{0x798e424a, 0x4090c9c4, 0xa50, 0x80160000}};
  // -1285297.7943439249190298564828
  decimal dec_check = {{0xa19bb8dc, 0x7591c072, 0x2987bbf2, 0x80160000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_90) {
  // -7515341178174353280570420
  decimal dec_1 = {{0x96739434, 0x762c8d7d, 0x6376f, 0x80000000}};
  // 212528009165.30402466
  decimal dec_2 = {{0xd7e414a2, 0x26f11dd4, 0x1, 0x80000}};
  // -35361650484049.517148287017927
  decimal dec_check = {{0xfe4023c7, 0xdfbd1310, 0x724278c1, 0x800f0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_91) {
  // 535020964418324285243
  decimal dec_1 = {{0xd520473b, 0xe84c79, 0x1d, 0x0}};
  // -337386624556524640.32134
  decimal dec_2 = {{0x35797986, 0xf9ff9c52, 0x724, 0x80050000}};
  // -1585.7800086816679379757015152
  decimal dec_check = {{0x2665a070, 0x3f956355, 0x333d43c9, 0x80190000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_93) {
  // 918607624492849020
  decimal dec_1 = {{0x79dc977c, 0xcbf8cc4, 0x0, 0x0}};
  // -0.4596
  decimal dec_2 = {{0x11f4, 0x0, 0x0, 0x80040000}};
  // -1998711106381307702.3498694517
  decimal dec_check = {{0x64a7ef75, 0xdad18cf1, 0x4094f365, 0x800a0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_94) {
  // -7.4209444387
  decimal dec_1 = {{0x473a4223, 0x11, 0x0, 0x800a0000}};
  // 0.5196121361
  decimal dec_2 = {{0x35b68511, 0x1, 0x0, 0xa0000}};
  // -14.281699604629384636884350092
  decimal dec_check = {{0x5464748c, 0xe7fe854e, 0x2e258b86, 0x801b0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_95) {
  // -7662113510356019709322821848
  decimal dec_1 = {{0x7f1180d8, 0xb01bf471, 0x18c1f3a5, 0x80000000}};
  // 0.54
  decimal dec_2 = {{0x36, 0x0, 0x0, 0x20000}};
  // -14189099093251888350597818237
  decimal dec_check = {{0x40a5277d, 0x2033c4ac, 0x2dd8f29b, 0x80000000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_96) {
  // -5755478090
  decimal dec_1 = {{0x570da04a, 0x1, 0x0, 0x80000000}};
  // 477.90
  decimal dec_2 = {{0xbaae, 0x0, 0x0, 0x20000}};
  // -12043268.654530236451140405943
  decimal dec_check = {{0xd1280ab7, 0xf412e01d, 0x26e9f555, 0x80150000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_97) {
  // -73454393160027209775
  decimal dec_1 = {{0xa74e002f, 0xfb626d66, 0x3, 0x80000000}};
  // -2617531.240
  decimal dec_2 = {{0x9c045b68, 0x0, 0x0, 0x80030000}};
  // 28062470482693.153941115904313
  decimal dec_check = {{0x84e82139, 0x21df4394, 0x5aacbb45, 0xf0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_99) {
  // -985307961564234400609579030
  decimal dec_1 = {{0x7ba7b016, 0x9ff04b34, 0x32f0713, 0x80000000}};
  // 93922182947372
  decimal dec_2 = {{0xf659e22c, 0x556b, 0x0, 0x0}};
  // -10490684209462.402818992892931
  decimal dec_check = {{0xaf59ec03, 0x89b57f7b, 0x21e5b0ca, 0x800f0000}};
  decimal result = {{0, 0, 0, 0}};
  int return_value = dec_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// 12 / 2 = 6
START_TEST(div_test_1) {
  int value_1 = 12, value_2 = 2, result = 0, expected = 6;
  decimal value_1_decimal = {{0, 0, 0, 0}}, value_2_decimal = {{0, 0, 0, 0}},
          value_3_decimal = {{0, 0, 0, 0}};

  from_int_to_decimal(value_1, &value_1_decimal);
  from_int_to_decimal(value_2, &value_2_decimal);

  dec_div(value_1_decimal, value_2_decimal, &value_3_decimal);
  from_decimal_to_int(value_3_decimal, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

// 0.6 / 0.6 = 1.0
START_TEST(div_test_2) {
  float value_1 = 0.6f, value_2 = 0.6f, result = 0.0f, expected = 1.0f;
  decimal value_1_decimal = {{0, 0, 0, 0}}, value_2_decimal = {{0, 0, 0, 0}},
          value_3_decimal = {{0, 0, 0, 0}};

  from_float_to_decimal(value_1, &value_1_decimal);
  from_float_to_decimal(value_2, &value_2_decimal);

  dec_div(value_1_decimal, value_2_decimal, &value_3_decimal);
  from_decimal_to_float(value_3_decimal, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

// 0.4 / 2.0 = 0.2
START_TEST(div_test_3) {
  float value_1 = 40e-2, value_2 = 20e-1, result = 0.0f, expected = 0.2;
  decimal value_1_decimal = {{0, 0, 0, 0}}, value_2_decimal = {{0, 0, 0, 0}},
          value_3_decimal = {{0, 0, 0, 0}};

  from_float_to_decimal(value_1, &value_1_decimal);
  from_float_to_decimal(value_2, &value_2_decimal);

  dec_div(value_1_decimal, value_2_decimal, &value_3_decimal);
  from_decimal_to_float(value_3_decimal, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

// -0.6 / 0.3 = -2.0
START_TEST(div_test_4) {
  float result = 0.0f, expected = -2.0f;

  decimal d_1 = {{60, 0, 0, 0}}, d_2 = {{3, 0, 0, 0}};
  set_dec_scale(&d_1, 2);
  set_dec_scale(&d_2, 1);

  set_dec_bit(&d_1, 127, 1);

  decimal d_3 = {{0, 0, 0, 0}};
  dec_div(d_1, d_2, &d_3);
  from_decimal_to_float(d_3, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

// -0.6 / 0.3 = -2.0
START_TEST(div_test_5) {
  float v_1 = -0.6f, v_2 = 0.3f, result = 0.0f, expected = -2.0f;

  decimal d_1 = {{0, 0, 0, 0}}, d_2 = {{0, 0, 0, 0}};
  from_float_to_decimal(v_1, &d_1);
  from_float_to_decimal(v_2, &d_2);

  decimal d_3 = {{0, 0, 0, 0}};

  dec_div(d_1, d_2, &d_3);
  from_decimal_to_float(d_3, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

// -0.3 / -0.2 = 1.5
START_TEST(div_test_6) {
  float result = 0.0f, expected = 1.5f;

  decimal d_1 = {{30, 0, 0, 0}}, d_2 = {{2, 0, 0, 0}};
  set_dec_scale(&d_1, 2);
  set_dec_scale(&d_2, 1);

  set_dec_bit(&d_1, 127, 1);
  set_dec_bit(&d_2, 127, 1);

  decimal d_3 = {{0, 0, 0, 0}};
  dec_div(d_1, d_2, &d_3);
  from_decimal_to_float(d_3, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

// -0.3 / -0.2 = 1.5
START_TEST(div_test_7) {
  float v_1 = -0.3f, v_2 = -0.2f, result = 0.0f, expected = 1.5f;

  decimal d_1 = {{0, 0, 0, 0}}, d_2 = {{0, 0, 0, 0}};
  from_float_to_decimal(v_1, &d_1);
  from_float_to_decimal(v_2, &d_2);

  decimal d_3 = {{0, 0, 0, 0}};
  dec_div(d_1, d_2, &d_3);
  from_decimal_to_float(d_3, &result);
  ck_assert_float_eq_tol(result, expected, 0.001);
}
END_TEST

START_TEST(div_test_8) {
  decimal d_1 = {{-1, -1, -1, 0}}, d_2 = {{1, 0, 0, 0}};
  set_dec_scale(&d_2, 1);

  decimal d_3 = {{0, 0, 0, 0}};
  int code = dec_div(d_1, d_2, &d_3);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite* suite_div(void) {
  Suite* c = suite_create("div_cases");
  TCase* tc = tcase_create("div_tc");

  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);
  tcase_add_test(tc, div_16);
  tcase_add_test(tc, div_18);
  tcase_add_test(tc, div_19);
  tcase_add_test(tc, div_20);
  tcase_add_test(tc, div_21);
  tcase_add_test(tc, div_22);
  tcase_add_test(tc, div_23);
  tcase_add_test(tc, div_24);
  tcase_add_test(tc, div_25);
  tcase_add_test(tc, div_26);
  tcase_add_test(tc, div_27);
  tcase_add_test(tc, div_28);
  tcase_add_test(tc, div_29);
  tcase_add_test(tc, div_30);
  tcase_add_test(tc, div_31);
  tcase_add_test(tc, div_32);
  tcase_add_test(tc, div_33);
  tcase_add_test(tc, div_34);
  tcase_add_test(tc, div_35);
  tcase_add_test(tc, div_36);
  tcase_add_test(tc, div_37);
  tcase_add_test(tc, div_38);
  tcase_add_test(tc, div_39);
  tcase_add_test(tc, div_40);
  tcase_add_test(tc, div_41);
  tcase_add_test(tc, div_42);
  tcase_add_test(tc, div_43);
  tcase_add_test(tc, div_44);
  tcase_add_test(tc, div_45);
  tcase_add_test(tc, div_47);
  tcase_add_test(tc, div_48);
  tcase_add_test(tc, div_49);
  tcase_add_test(tc, div_50);
  tcase_add_test(tc, div_51);
  tcase_add_test(tc, div_52);
  tcase_add_test(tc, div_53);
  tcase_add_test(tc, div_54);
  tcase_add_test(tc, div_55);
  tcase_add_test(tc, div_57);
  tcase_add_test(tc, div_59);
  tcase_add_test(tc, div_60);
  tcase_add_test(tc, div_61);
  tcase_add_test(tc, div_64);
  tcase_add_test(tc, div_65);
  tcase_add_test(tc, div_66);
  tcase_add_test(tc, div_67);
  tcase_add_test(tc, div_68);
  tcase_add_test(tc, div_69);
  tcase_add_test(tc, div_70);
  tcase_add_test(tc, div_71);
  tcase_add_test(tc, div_72);
  tcase_add_test(tc, div_73);
  tcase_add_test(tc, div_74);
  tcase_add_test(tc, div_75);
  tcase_add_test(tc, div_76);
  tcase_add_test(tc, div_77);
  tcase_add_test(tc, div_79);
  tcase_add_test(tc, div_80);
  tcase_add_test(tc, div_81);
  tcase_add_test(tc, div_82);
  tcase_add_test(tc, div_83);
  tcase_add_test(tc, div_84);
  tcase_add_test(tc, div_85);
  tcase_add_test(tc, div_86);
  tcase_add_test(tc, div_87);
  tcase_add_test(tc, div_88);
  tcase_add_test(tc, div_89);
  tcase_add_test(tc, div_90);
  tcase_add_test(tc, div_91);
  tcase_add_test(tc, div_93);
  tcase_add_test(tc, div_94);
  tcase_add_test(tc, div_95);
  tcase_add_test(tc, div_96);
  tcase_add_test(tc, div_97);
  tcase_add_test(tc, div_99);

  tcase_add_test(tc, div_test_1);
  tcase_add_test(tc, div_test_2);
  tcase_add_test(tc, div_test_3);
  tcase_add_test(tc, div_test_4);
  tcase_add_test(tc, div_test_5);
  tcase_add_test(tc, div_test_6);
  tcase_add_test(tc, div_test_7);
  tcase_add_test(tc, div_test_8);

  suite_add_tcase(c, tc);
  return c;
}
