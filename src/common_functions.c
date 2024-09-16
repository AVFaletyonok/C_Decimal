#include "decimal.h"

void dec_reset(decimal* dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0b0;
  }
}

bool is_dec_ok(decimal dec) {
  bool result = true;
  for (int i = 96; i < 112 && result; i++) {
    if (get_dec_bit(dec, i) == 1) result = false;
  }
  for (int i = 120; i < 127 && result; i++) {
    if (get_dec_bit(dec, i) == 1) result = false;
  }
  int exp = get_dec_scale(&dec);
  if (exp < 0 || exp > 28) result = false;
  return result;
}

bool dec_iszero(decimal dec) {
  return dec.bits[0] == 0 && dec.bits[1] == 0 && dec.bits[2] == 0;
}

void dec_to_bigdec(bigdecimal* dst, decimal src) {
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }
  for (int i = 3; i < 7; i++) {
    dst->bits[i] = 0;
  }
  dst->bits[7] = src.bits[3];
}

void dec_cpy(decimal* dst, decimal src) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = src.bits[i];
  }
}

void bigdec_reset(bigdecimal* dec) {
  for (int i = 0; i < 8; i++) {
    dec->bits[i] = 0;
  }
}

bool bigdec_iszero(bigdecimal bdec) {
  return bdec.bits[0] == 0 && bdec.bits[1] == 0 && bdec.bits[2] == 0 &&
         bdec.bits[3] == 0 && bdec.bits[4] == 0 && bdec.bits[5] == 0 &&
         bdec.bits[6] == 0;
}

void bigdec_to_dec(decimal* dst, bigdecimal src) {
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }
  dst->bits[3] = src.bits[7];
}

void bigdec_cpy(bigdecimal* dst, bigdecimal src) {
  for (int i = 0; i < 8; i++) {
    dst->bits[i] = src.bits[i];
  }
}

// returns 1 - if is_overflow in 223 - 96 bits && scale == 0 after function
// if 1 - you can't convert bdec to decimal !!!
int bigdec_normalize(bigdecimal* bdec) {
  // check overflow in 223-96 bits -> to convert to decimal
  int is_overflow = check_bigdec_overflow(*bdec);
  int scale = get_bigdec_scale(bdec);
  bool is_zero = bigdec_iszero(*bdec);

  if (is_zero) {
    bdec->bits[3] = 0;
  } else {
    bigdecimal bdec10 = {{10, 0, 0, 0, 0, 0, 0, 0}};
    // there is overflow
    // devide by 10, scale-- (round in bigdec_div_mantissa)
    while ((is_overflow && scale > 0) || scale > 28) {
      bigdec_div_mantissa(bdec, bdec10);
      set_bigdec_scale(bdec, --scale);
      is_overflow = check_bigdec_overflow(*bdec);
    }
    // scale < 0 after devision
    // * 10, scale++
    is_overflow = check_bigdec_overflow(*bdec);
    while (is_overflow == 0 && scale < 0) {
      is_overflow = bigdec_mult_mantissa(bdec, bdec10);
      set_bigdec_scale(bdec, ++scale);
    }
    is_overflow = check_bigdec_overflow(*bdec);
  }
  return is_overflow || scale < 0 || 28 < scale;
}

// doesn't consider scales!!!
// returns 1 - if there is bit '1' in 223...96 bits
int check_bigdec_overflow(bigdecimal bdec) {
  int result = 0;
  for (int i = 223; i >= 96 && result == 0; i--) {
    result = get_bigdec_bit(bdec, i);
  }
  return result;
}

// doesn't consider scales!!! dec_2 != 0
void bigdec_div_mantissa(bigdecimal* dec_1, bigdecimal dec_2) {
  bigdecimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  // dec_1 >= dec_2
  int cmp_result = bigdec_cmp_mantissa(*dec_1, dec_2);
  if (cmp_result >= 0) bigdec_div_intmantissa(dec_1, dec_2, &result);
  // doesn't consider overflow!!!!!
  // dec_1 < dec_2 && dec_1 != 0
  bigdecimal bdec10 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int scale = 0;
  int is_overflow = check_bigdec_overflow(result);

  // add float part, scale++ while scale < 28
  while (!bigdec_iszero(*dec_1) && scale < 28 && is_overflow == 0) {
    bigdecimal temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
    bigdec_cpy(&temp, result);
    bigdecimal temp_dec_1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    bigdec_cpy(&temp_dec_1, *dec_1);

    is_overflow = bigdec_mult_mantissa(&temp, bdec10);  // in 223 bit
    if (is_overflow == 0) is_overflow = check_bigdec_overflow(temp);
    if (is_overflow == 0) {
      bigdec_mult_mantissa(&temp_dec_1, bdec10);

      if (bigdec_cmp_mantissa(temp_dec_1, dec_2) >= 0) {
        bigdecimal temp_add = {{0, 0, 0, 0, 0, 0, 0, 0}};
        bigdec_div_intmantissa(&temp_dec_1, dec_2, &temp_add);
        bigdec_add_mantissa(&temp, temp_add);
      }
    }
    is_overflow = check_bigdec_overflow(temp);
    if (is_overflow == 0) {
      scale++;
      set_bigdec_scale(&temp, scale);
      bigdec_cpy(&result, temp);
      bigdec_cpy(dec_1, temp_dec_1);
    }
  }
  is_overflow = check_bigdec_overflow(result);
  // create reminder and round
  if (!bigdec_iszero(*dec_1) && is_overflow == 0) {
    bigdecimal bdec100 = {{100, 0, 0, 0, 0, 0, 0, 0}};
    bigdec_mult_mantissa(dec_1, bdec100);
    if (bigdec_cmp_mantissa(*dec_1, dec_2) >= 0) {
      bigdecimal temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
      bigdec_div_intmantissa(dec_1, dec_2, &temp);

      int last_bit = get_bigdec_bit(result, 0);
      bigdecimal bdec50 = {{50, 0, 0, 0, 0, 0, 0, 0}};
      int cmp5_reminder = bigdec_cmp_mantissa(temp, bdec50);

      if (cmp5_reminder > 0 || (cmp5_reminder == 0 && last_bit == 1)) {
        bigdecimal bdec1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
        bigdec_add_mantissa(&result, bdec1);
      }
    }  // else reminder = .0... -> don't need to increase result
  }
  set_bigdec_scale(&result, scale);
  bigdec_cpy(dec_1, result);
}

void dec_bank_round(decimal* quotient, decimal remainder) {
  bigdecimal temp_quot = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal temp_rem = {{0, 0, 0, 0, 0, 0, 0, 0}};
  dec_to_bigdec(&temp_quot, *quotient);
  dec_to_bigdec(&temp_rem, remainder);
  bigdec_bank_round(&temp_quot, temp_rem);
  bigdec_to_dec(quotient, temp_quot);
}

void bigdec_bank_round(bigdecimal* quotient, bigdecimal remainder) {
  int last_bit = get_bigdec_bit(*quotient, 0);
  bigdecimal bdec5 = {{5, 0, 0, 0, 0, 0, 0, 0}};
  int cmp5_reminder = bigdec_cmp_mantissa(remainder, bdec5);
  if (cmp5_reminder > 0 || (cmp5_reminder == 0 && last_bit == 1)) {
    bigdecimal bdec1 = {{1, 0, 0, 0, 0, 0, 0, 0}};
    bigdec_add_mantissa(quotient, bdec1);
  }
}

void bigdec_mod_mantissa(bigdecimal dec_1, bigdecimal dec_2,
                         bigdecimal* mod_result) {
  if (bigdec_iszero(dec_1) || bigdec_iszero(dec_2)) {
    bigdec_reset(mod_result);
  } else {
    bigdecimal dont_need_temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
    bigdec_cpy(mod_result, dec_1);
    bigdec_div_intmantissa(mod_result, dec_2, &dont_need_temp);
  }
}

// in dec_1 will be reminder after division:
// dec_1 = dec_1 % dec_2; result = dec_1 / dec_2
void dec_div_intmantissa(decimal* dec_1, decimal dec_2, decimal* result) {
  bigdecimal bdec_1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal bdec_result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  dec_reset(result);
  dec_to_bigdec(&bdec_1, *dec_1);
  dec_to_bigdec(&bdec_2, dec_2);

  bigdec_div_intmantissa(&bdec_1, bdec_2, &bdec_result);
  bigdec_to_dec(dec_1, bdec_1);
  bigdec_to_dec(result, bdec_result);
}

// in dec_1 will be reminder after division:
// dec_1 = dec_1 % dec_2; result = dec_1 / dec_2
void bigdec_div_intmantissa(bigdecimal* dec_1, bigdecimal dec_2,
                            bigdecimal* result) {
  bigdecimal temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdecimal temp2 = {{0, 0, 0, 0, 0, 0, 0, 0}};

  int cmp_result = bigdec_cmp_mantissa(*dec_1, dec_2);
  // dec_1 >= dec_2; Devide int part
  while (!bigdec_iszero(*dec_1) && cmp_result >= 0) {
    bigdec_cpy(&temp2, dec_2);
    bigdec_cpy(&temp, temp2);
    int count = 0;
    while (cmp_result == 1 && get_bigdec_bit(temp2, 223) == 0) {
      // shift temp2 to the left
      bigdec_shift_bit(&temp2, 1);
      cmp_result = bigdec_cmp_mantissa(*dec_1, temp2);
      if (cmp_result >= 0) {
        bigdec_cpy(&temp, temp2);
        count++;
      }
    }
    bigdec_sub_mantissa(dec_1, temp);
    set_bigdec_bit(result, count, 1);
    cmp_result = bigdec_cmp_mantissa(*dec_1, dec_2);
  }
}

// doesn't consider scales!!!
// returns 1 - if there was an overflow in 223 bit during multiplying
int bigdec_mult_mantissa(bigdecimal* value_1, bigdecimal value_2) {
  bigdecimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  unsigned int bit_zero = value_1->bits[7];

  int overf_error = 0;
  // multiple in columns
  for (int i = 223; i >= 0; i--) {
    int bit_val = get_bigdec_bit(value_2, i);
    if (bit_val == 1) {
      bigdec_add_mantissa(&result, *value_1);
    }
    if (i > 0) {
      overf_error = get_bigdec_bit(result, 223);
      bigdec_shift_bit(&result, 1);
    }
  }
  bigdec_cpy(value_1, result);
  value_1->bits[7] = bit_zero;
  return overf_error;
}

// !!! dec_1 > 0 && dec_2 > 0
void bigdec_add_mantissa(bigdecimal* dec_1, bigdecimal dec_2) {
  bigdecimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  unsigned int bit_zero = dec_1->bits[7];

  int minded = 0;
  for (int i = 0; i < 224; i++) {
    int bit_1 = get_bigdec_bit(*dec_1, i);
    int bit_2 = get_bigdec_bit(dec_2, i);
    int sum = bit_1 + bit_2 + minded;

    switch (sum) {
      case 0:
        set_bigdec_bit(&result, i, 0);
        break;
      case 1:
        minded = 0;
        set_bigdec_bit(&result, i, 1);
        break;
      case 2:
        minded = 1;
        set_bigdec_bit(&result, i, 0);
        break;
      default:  // case 3:
        minded = 1;
        set_bigdec_bit(&result, i, 1);
    }
  }
  bigdec_cpy(dec_1, result);
  dec_1->bits[7] = bit_zero;
}

// !!! dec_1 >= dec_2
void bigdec_sub_mantissa(bigdecimal* dec_1, bigdecimal dec_2) {
  bigdecimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_cpy(&result, *dec_1);
  unsigned int bit_zero = dec_1->bits[7];

  for (int i = 0; i < 224; i++) {
    int bit_1 = get_bigdec_bit(result, i);
    int bit_2 = get_bigdec_bit(dec_2, i);
    if (bit_1 == bit_2) {
      set_bigdec_bit(&result, i, 0);
    } else if (bit_1 == 0 && bit_2 == 1) {
      // borrow older bit
      int borrow_i = i + 1;
      for (; borrow_i < 224; borrow_i++) {
        bit_1 = get_bigdec_bit(result, borrow_i);
        if (bit_1 == 1) break;
      }
      set_bigdec_bit(&result, borrow_i--, 0);
      for (; borrow_i >= i; borrow_i--) {
        set_bigdec_bit(&result, borrow_i, 1);
      }
    }
  }
  bigdec_cpy(dec_1, result);
  dec_1->bits[7] = bit_zero;
}

// doesn't consider scales!!! scale_1 == scale_2
// returns 0 - dec_1 == dec_2
// -1 dec_1 < dec_2
// 1 dec_1 > dec_2
int bigdec_cmp_mantissa(bigdecimal dec_1, bigdecimal dec_2) {
  int result = 0;
  for (int i = 223; i >= 0 && result == 0; i--) {
    int bit_1 = get_bigdec_bit(dec_1, i);
    int bit_2 = get_bigdec_bit(dec_2, i);
    if (bit_1 > bit_2)
      result = 1;
    else if (bit_1 < bit_2)
      result = -1;
  }
  return result;
}

// !doesn't check 0 <= scale <= 28
// multi while it's possible
// after that if dec_1 != dec_2 devide while it's possible
// after all of that if dec_1 != dec_2 -> returns 1
int bigdecs_normalize(bigdecimal* dec_1, bigdecimal* dec_2) {
  int overf_error = 0;
  int scale_1 = get_bigdec_scale(dec_1);
  int scale_2 = get_bigdec_scale(dec_2);
  bigdecimal bdec10 = {{10, 0, 0, 0, 0, 0, 0, 0}};

  while (scale_1 < scale_2 && overf_error == 0) {  // dec_1 * 10, scale_1++
    overf_error = bigdec_mult_mantissa(dec_1, bdec10);
    if (overf_error == 0) set_bigdec_scale(dec_1, ++scale_1);
  }
  while (scale_1 < scale_2 && overf_error == 0) {  // dec_2 / 10, scale_2--
    bigdec_div_mantissa(dec_2, bdec10);
    set_bigdec_scale(dec_2, --scale_2);
  }

  while (scale_2 < scale_1 && overf_error == 0) {  // dec_2 * 10, scale_2++
    overf_error = bigdec_mult_mantissa(dec_2, bdec10);
    if (overf_error == 0) set_bigdec_scale(dec_2, ++scale_2);
  }
  while (scale_2 < scale_1 && overf_error == 0) {  // dec_1 / 10, scale_1--
    bigdec_div_mantissa(dec_1, bdec10);
    set_bigdec_scale(dec_1, --scale_1);
  }

  if (overf_error == 0) overf_error = scale_1 == scale_2 ? 0 : 1;
  return overf_error;
}

void exchange_values(bigdecimal* dec_1, bigdecimal* dec_2) {
  bigdecimal tmp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  bigdec_cpy(&tmp, *dec_1);
  bigdec_cpy(dec_1, *dec_2);
  bigdec_cpy(dec_2, tmp);
}
