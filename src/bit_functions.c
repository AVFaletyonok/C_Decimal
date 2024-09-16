#include "decimal.h"

// bitn in range [0, 127] from right to left: [127 ... 96] [95 94 ... 2 1 0]
// returns 1 or 0
int get_dec_bit(decimal number, unsigned int bitn) {
  int int_index = bitn / INT_BIT_COUNT;  // 32
  int bit_index = bitn % INT_BIT_COUNT;
  return (number.bits[int_index] >> bit_index) & 00000001;
}

// bitn in range [0, 127] from right to left: [127 ... 96] [95 94 ... 2 1 0]
void set_dec_bit(decimal* number, unsigned int bitn, int value) {
  int int_index = bitn / INT_BIT_COUNT;
  int bit_index = bitn % INT_BIT_COUNT;
  if (value)
    number->bits[int_index] = number->bits[int_index] | (00000001 << bit_index);
  else
    number->bits[int_index] =
        number->bits[int_index] & ~(00000001 << bit_index);
}

unsigned int get_dec_scale(decimal* dec) {
  unsigned int exp = 0;
  // `bits[3]` stores scale and sign: bits from 16 to 23 store scale from 0
  // to 28.
  for (int i = 119; i >= 112; i--) {
    int val = get_dec_bit(*dec, i);
    exp = exp * 2 + val;
  }
  return exp;
}

void set_dec_scale(decimal* dec, unsigned int exp) {
  for (int i = 112; i < 120; i++) {
    set_dec_bit(dec, i, exp % 2);
    exp = exp / 2;
  }
}

// bitn in range [0, 255] from right to left: [255 ... 224] [223 222 ... 2 1 0]
// returns 1 or 0
int get_bigdec_bit(bigdecimal number, unsigned int bitn) {
  int int_index = bitn / INT_BIT_COUNT;
  int bit_index = bitn % INT_BIT_COUNT;
  return (number.bits[int_index] >> bit_index) & 00000001;
}

// bitn in range [0, 255] from right to left: [255 ... 224] [223 222 ... 2 1 0]
void set_bigdec_bit(bigdecimal* number, unsigned int bitn, int value) {
  int int_index = bitn / INT_BIT_COUNT;
  int bit_index = bitn % INT_BIT_COUNT;
  if (value)
    number->bits[int_index] = number->bits[int_index] | (00000001 << bit_index);
  else
    number->bits[int_index] =
        number->bits[int_index] & ~(00000001 << bit_index);
}

// shift only mantissa of the number to the left
// !shift_count < 32
// returns 1 - if there was an overflow in bits[6]
// 0 - OK
int bigdec_shift_bit(bigdecimal* number, unsigned int shift_count) {
  unsigned int memory = 0;
  shift_count %= INT_BIT_COUNT;
  memory = 0;
  for (int i = 0; i < (int)(sizeof(bigdecimal) / sizeof(unsigned) - 1); i++) {
    unsigned int temp = number->bits[i];
    number->bits[i] <<= shift_count;
    number->bits[i] |= memory;
    memory = temp >> (INT_BIT_COUNT - shift_count);
  }
  return memory == 0 ? 0 : 1;
}

int get_bigdec_scale(bigdecimal* dec) {
  unsigned int exp = 0;
  for (int i = 247; i >= 240; i--) {
    int val = get_bigdec_bit(*dec, i);
    exp = exp * 2 + val;
  }
  if (get_bigdec_bit(*dec, 248) == 1) exp = -exp;
  return exp;
}

void set_bigdec_scale(bigdecimal* dec, int exp) {
  if (exp < 0) {
    set_bigdec_bit(dec, 248, 1);
    exp = -exp;
  } else {
    set_bigdec_bit(dec, 248, 0);
  }
  for (int i = 240; i < 248; i++) {
    set_bigdec_bit(dec, i, exp % 2);
    exp /= 2;
  }
}

// bitn in range [0, 7] from right to left: 7 6 5 4 3 2 1 0
// returns 1 or 0
int get_uint_bit(unsigned int number, unsigned int bitn) {
  return (number >> bitn) & 00000001;
}

// bitn in range [0, 7] from right to left: 7 6 5 4 3 2 1 0
void set_uint_bit(unsigned int* number, unsigned int bitn, int value) {
  if (value)
    *number = *number | (00000001 << bitn);
  else
    *number = *number & ~(00000001 << bitn);
}
