#include "decimal.h"

// returns
// 0 — FALSE
// 1 — TRUE
int is_less(decimal first, decimal second) {
  if (!is_dec_ok(first) || !is_dec_ok(second)) return 0;
  // returns 0 - dec_1 == dec_2
  // -1 dec_1 < dec_2
  // 1 dec_1 > dec_2
  int result = compare_decimal(first, second);
  return result == -1 ? 1 : 0;
}

int is_less_or_equal(decimal first, decimal second) {
  if (!is_dec_ok(first) || !is_dec_ok(second)) return 0;
  int buf = compare_decimal(first, second);
  int result = 0;
  if (buf == -1 || buf == 0) result = 1;
  return result;
}

int is_greater(decimal first, decimal second) {
  if (!is_dec_ok(first) || !is_dec_ok(second)) return 0;
  int compare = compare_decimal(first, second);
  return compare == 1 ? 1 : 0;
}

int is_greater_or_equal(decimal first, decimal second) {
  if (!is_dec_ok(first) || !is_dec_ok(second)) return 0;
  int buf = compare_decimal(first, second);
  int result = 0;
  if (buf == 1 || buf == 0) result = 1;
  return result;
}

int is_equal(decimal first, decimal second) {
  if (!is_dec_ok(first) || !is_dec_ok(second)) return 0;
  int result = compare_decimal(first, second);
  return result == 0 ? 1 : 0;
}

int is_not_equal(decimal first, decimal second) {
  if (!is_dec_ok(first) || !is_dec_ok(second)) return 0;
  int result = compare_decimal(first, second);
  return result != 0 ? 1 : 0;
}

// returns
// 0 - dec_1 == dec_2
// -1 dec_1 < dec_2
// 1 dec_1 > dec_2
int compare_decimal(decimal first, decimal second) {
  if (dec_iszero(first)) first.bits[3] = 0;
  if (dec_iszero(second)) second.bits[3] = 0;

  int result = 0;
  int sign_1 = get_dec_bit(first, 127);
  int sign_2 = get_dec_bit(second, 127);

  if (sign_1 != sign_2) {
    result = sign_1 == 1 ? -1 : 1;
  } else {  // sign_1 == sign_2: + +; - -
    int scale_1 = get_dec_scale(&first);
    int scale_2 = get_dec_scale(&second);

    bigdecimal temp_1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    bigdecimal temp_2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    dec_to_bigdec(&temp_1, first);
    dec_to_bigdec(&temp_2, second);

    if (scale_1 != scale_2) {
      bigdecs_normalize(&temp_1, &temp_2);
    }
    // returns 0 - dec_1 == dec_2
    // -1 dec_1 < dec_2
    // 1 dec_1 > dec_2
    result = bigdec_cmp_mantissa(temp_1, temp_2);
    if (sign_1 == 1) {
      if (result == 1) {
        result = -1;
      } else if (result == -1) {
        result = 1;
      }
    }
  }
  return result;
}
