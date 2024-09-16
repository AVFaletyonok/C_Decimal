#include "decimal.h"

/* returns:
// 0 — OK;
// 1 — the number is too large or equal +infinity;
// 2 — the number is too small or equal -infinity;
// 3 — division by 0;
// 4 - wrong input.*/
int dec_div(decimal value_1, decimal value_2, decimal* result) {
  if (result == NULL || !is_dec_ok(value_1) || !is_dec_ok(value_2)) return 4;
  if (dec_iszero(value_2)) return 3;

  int scale_1 = get_dec_scale(&value_1);
  int scale_2 = get_dec_scale(&value_2);
  // can become < 0 (min -28) - in bigdec_normalize()
  int scale_result = scale_1 - scale_2;
  bigdecimal temp_1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal temp_2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  dec_to_bigdec(&temp_1, value_1);
  dec_to_bigdec(&temp_2, value_2);
  set_bigdec_scale(&temp_1, 0);
  set_bigdec_scale(&temp_2, 0);

  int overf_mult_cod = 0;
  while (scale_result < 0 && overf_mult_cod == 0) {
    bigdecimal dec10 = {{10, 0, 0, 0, 0, 0, 0, 0}};
    bigdecimal temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
    bigdec_cpy(&temp, temp_1);

    overf_mult_cod = bigdec_mult_mantissa(&temp, dec10);
    if (overf_mult_cod == 0) {
      bigdec_cpy(&temp_1, temp);
      scale_result++;
    }
  }
  bigdec_div_mantissa(&temp_1, temp_2);

  int sign_res = get_dec_bit(value_1, 127) ^ get_dec_bit(value_2, 127);
  set_bigdec_bit(&temp_1, 255, sign_res);

  scale_result += get_bigdec_scale(&temp_1);
  set_bigdec_scale(&temp_1, scale_result);
  int overf_error = check_bigdec_overflow(temp_1);

  if (overf_error != 0 || scale_result < 0 || 28 < scale_result)
    overf_error = bigdec_normalize(&temp_1);

  if (overf_error == 0) bigdec_to_dec(result, temp_1);

  if (overf_error != 0) overf_error = sign_res == 0 ? 1 : 2;
  return overf_error;
}