#include "decimal.h"

// returns
// 0 - OK
// 1 - error
int dec_floor(decimal value, decimal* result) {
  if (result == NULL || !is_dec_ok(value)) return 1;
  dec_reset(result);

  int sign = get_dec_bit(value, 127);
  int scale = get_dec_scale(&value);
  int count = scale;

  if (scale == 0) dec_cpy(result, value);
  for (int i = 0; i < count; i++) {
    decimal dec10 = {{10, 0, 0, 0}};
    dec_div_intmantissa(&value, dec10, result);
    if (sign == 1 && !dec_iszero(value)) {
      decimal dec1 = {{1, 0, 0, 0}};
      add(*result, dec1, result);
    }
    set_dec_scale(result, --scale);
    dec_cpy(&value, *result);
  }
  set_dec_bit(result, 127, sign);
  return 0;
}

int dec_round(decimal value, decimal* result) {
  if (result == NULL || !is_dec_ok(value)) return 1;
  dec_reset(result);

  int sign = get_dec_bit(value, 127);
  int scale = get_dec_scale(&value);
  int count = scale;

  if (scale == 0) dec_cpy(result, value);
  for (int i = 0; i < count; i++) {
    decimal dec10 = {{10, 0, 0, 0}};
    dec_div_intmantissa(&value, dec10, result);
    dec_bank_round(result, value);

    set_dec_scale(result, --scale);
    dec_cpy(&value, *result);
  }
  set_dec_bit(result, 127, sign);
  return 0;
}

int truncate(decimal value, decimal* result) {
  if (result == NULL || !is_dec_ok(value)) return 1;
  dec_reset(result);

  int scale = get_dec_scale(&value);
  int sign = get_dec_bit(value, 127);
  int count = scale;

  if (scale == 0) dec_cpy(result, value);
  for (int i = 0; i < count; i++) {
    decimal dec10 = {{10, 0, 0, 0}};
    dec_div_intmantissa(&value, dec10, result);
    set_dec_scale(result, --scale);
    dec_cpy(&value, *result);
  }

  if (!dec_iszero(*result)) {
    set_dec_bit(result, 127, sign);
  } else {
    result->bits[3] = 0;
  }

  return 0;
}

int negate(decimal value, decimal* result) {
  if (result == NULL || !is_dec_ok(value)) return 1;
  dec_cpy(result, value);
  int sign = get_dec_bit(value, 127);
  if (sign == 0) {
    set_dec_bit(result, 127, 1);
  } else {
    set_dec_bit(result, 127, 0);
  }
  return 0;
}
