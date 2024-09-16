#include "decimal.h"

// returns
// - 0 - OK;
// - 1 — conversion error or if dst == NULL.
int from_int_to_decimal(int src, decimal* dst) {
  if (dst == NULL) return 1;
  dec_reset(dst);

  if (src < 0) {
    src--;
    src = ~src;
    set_dec_bit(dst, 127, 1);
  } else {
    set_dec_bit(dst, 127, 0);
  }
  dst->bits[0] = (unsigned int)src;
  return 0;
}

// returns
// - 0 - OK;
// - 1 — conversion error or if dst == NULL or (dec > INT_MAX || dec < INT_MIN).
int from_decimal_to_int(decimal src, int* dst) {
  if (dst == NULL) return 1;
  int result = 1;

  bool flag_is_dec_ok = is_dec_ok(src);

  if (flag_is_dec_ok) {
    int exp = get_dec_scale(&src);
    if (0 <= exp && exp < 29) {
      while (exp > 0) {
        decimal temp_result = {{0, 0, 0, 0}};
        decimal dec10 = {{10, 0, 0, 0}};
        dec_div_intmantissa(&src, dec10, &temp_result);
        dec_cpy(&src, temp_result);
        set_dec_scale(&src, --exp);
      }  // exp == 0

      bool is_overflow = 0;  // check overflow in bits[2], bits[1]
      for (int i = 95; i >= 32 && !is_overflow; --i) {
        if (get_dec_bit(src, i)) is_overflow = 1;
      }
      if (!is_overflow) {
        // check is the number in range [INT_MIN, INT_MAX]
        long number = 0;
        for (int i = 31; i >= 0; --i) {
          int val = get_dec_bit(src, i);
          number = number * 2 + val;
        }
        // get sign
        int sign = get_dec_bit(src, 127);
        if (sign == 1) number = -number;

        if ((long)INT_MIN <= number && number <= (long)INT_MAX) {
          *dst = (int)number;
          result = 0;
        }
      }
    }
  }
  return result;
}

// returns
// - 0 - OK;
// - 1 — conversion error or if dst == NULL or (exp > 28 || dec < 0).
// (0 < |x| < 1e-28) -> value = 0, returns 1
// (|x| > 79,228,162,514,264,337,593,543,950,335) +-infinity -> returns 1
int from_float_to_decimal(float src, decimal* dst) {
  if (dst == NULL || fabsf(src) > 7.922816e+28f || isnan(src) || isinf(src))
    return 1;
  dec_reset(dst);
  int result = 1;

  char str_float[15] = "";  // 1.111111E+-20
  sprintf(str_float, "%+.6e", src);
  int sign = (str_float[0] == '+') ? 0 : 1;

  if (1e-35 < fabsf(src) && fabsf(src) < 1e-28) {
    if (src < 0) set_dec_bit(dst, 127, 1);
  } else if (fabsf(src) < 1e-35) {
    result = 0;
    if (sign == 1) set_dec_bit(dst, 127, 1);
  } else {
    // parse float
    unsigned int temp_int = str_float[1] - '0';
    for (int i = 3; i < 9; i++) {
      temp_int = 10 * temp_int + (str_float[i] - '0');
    }
    int sale = 0;
    for (int i = 11; i <= 12; i++) {
      sale = 10 * sale + (str_float[i] - '0');
    }
    if (str_float[10] == '+') sale = -sale;
    sale += 6;
    while (temp_int % 10 == 0) {
      temp_int /= 10;
      sale--;
    }

    // create decimal
    decimal temp = {{0, 0, 0, 0}};
    decimal dec10 = {{10, 0, 0, 0}};
    dst->bits[0] = temp_int;
    int overflow_error = 0;
    while (sale < 0 && overflow_error == 0) {
      overflow_error = mul(*dst, dec10, &temp);
      dec_cpy(dst, temp);
      sale++;
    }
    while (sale > 28 && overflow_error == 0) {
      overflow_error = dec_div(*dst, dec10, &temp);
      dec_cpy(dst, temp);
      sale--;
    }
    if (overflow_error == 0) {
      set_dec_scale(dst, sale);
      if (sign == 1) set_dec_bit(dst, 127, 1);
      result = 0;
    }
  }
  return result;
}

// returns
// - 0 - OK;
// - 1 — conversion error or if dst == NULL or (exp > 28 || dec < 0).
int from_decimal_to_float(decimal src, float* dst) {
  if (dst == NULL) return 1;
  int cod_result = 1;
  bool flag_is_dec_ok = is_dec_ok(src);

  if (flag_is_dec_ok) {
    int exp = get_dec_scale(&src);
    bigdecimal big_src = {{0, 0, 0, 0, 0, 0, 0, 0}};
    dec_to_bigdec(&big_src, src);

    int sign = get_dec_bit(src, 127);
    if (bigdec_iszero(big_src)) {
      if (sign == 1)
        *dst = -0.0f;
      else
        *dst = 0.0f;
      cod_result = 0;
    } else if (0 <= exp && exp < 29) {
      double temp_result = 0.0f;
      for (int i = 95; i >= 0; --i) {
        int val = get_dec_bit(src, i);
        temp_result = temp_result * 2 + val;
      }
      for (; exp > 0; --exp) {
        temp_result /= 10;
      }
      if (sign == 1) temp_result = -temp_result;

      *dst = (float)temp_result;
      cod_result = 0;
    }
  }
  return cod_result;
}
