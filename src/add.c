#include "decimal.h"

// retuns
// 0 — OK;
// 1 — the number is too large or equal +infinity;
// 2 — the number is too small or equal -infinity;
// 3 — division by 0;
// 4 - wrong input.
int add(decimal value_1, decimal value_2, decimal* result) {
  if (result == NULL || !is_dec_ok(value_1) || !is_dec_ok(value_2)) return 4;
  dec_reset(result);

  int sign_1 = get_dec_bit(value_1, 127);
  int sign_2 = get_dec_bit(value_2, 127);
  int overf_error = 0;

  if (sign_1 == sign_2) {
    int scale_1 = get_dec_scale(&value_1);
    int scale_2 = get_dec_scale(&value_2);

    bigdecimal temp_1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    bigdecimal temp_2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    dec_to_bigdec(&temp_1, value_1);
    dec_to_bigdec(&temp_2, value_2);

    if (scale_1 != scale_2) {
      overf_error = bigdecs_normalize(&temp_1, &temp_2);
    }
    if (overf_error == 0) {
      bigdec_add_mantissa(&temp_1, temp_2);

      overf_error = check_bigdec_overflow(temp_1);
      if (overf_error != 0) overf_error = bigdec_normalize(&temp_1);
      if (overf_error == 0) bigdec_to_dec(result, temp_1);
      if (!dec_iszero(*result)) {
        set_dec_bit(result, 127, sign_1);
      } else {
        result->bits[3] = 0;
      }
    }
  } else if (sign_1 == 0 && sign_2 == 1) {
    set_dec_bit(&value_2, 127, 0);
    overf_error = sub(value_1, value_2, result);
  } else {
    set_dec_bit(&value_1, 127, 0);
    overf_error = sub(value_2, value_1, result);
  }
  if (overf_error != 0) overf_error = sign_1 == 0 ? 1 : 2;
  return overf_error;
}
