#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// bits[0] ... bits[2] - mantissa, bits[3] - sign and exponent
typedef struct {
  unsigned int bits[4];
} decimal;

// bits[0] ... bits[6] - mantissa, bits[7] - sign and exponent
typedef struct {
  unsigned int bits[8];
} bigdecimal;

void decimal_print(decimal* num);
void bigdecimal_print(bigdecimal* num);

void dec_reset(decimal* dec);
bool is_dec_ok(decimal dec);
bool dec_iszero(decimal dec);
void dec_to_bigdec(bigdecimal* dst, decimal src);
void dec_cpy(decimal* dst, decimal src);

void bigdec_reset(bigdecimal* dec);
bool bigdec_iszero(bigdecimal bdec);

void bigdec_to_dec(decimal* dst, bigdecimal src);
void bigdec_cpy(bigdecimal* dst, bigdecimal src);
// returns 1 - if is_overflow && scale == 0 after function
int bigdec_normalize(bigdecimal* bdec);
// returns 1 - if dec_1 != dec_2 after function
int bigdecs_normalize(bigdecimal* dec_1, bigdecimal* dec_2);

// doesn't consider scale!!!
// returns 1 - if there is bit '1' in 223...96 bits
int check_bigdec_overflow(bigdecimal bdec);

// doesn't consider scales!!!
// returns 1 - if there was an overflow in 223 bit during multiplying
int bigdec_mult_mantissa(bigdecimal* value_1, bigdecimal value_2);

// doesn't consider scales!!!
// returns 1 - if there was an overflow and scale == 0 after division
void bigdec_div_mantissa(bigdecimal* dec_1, bigdecimal dec_2);
void bigdec_mod_mantissa(bigdecimal dec_1, bigdecimal dec_2,
                         bigdecimal* mod_result);

// in dec_1 will be reminder after division:
// dec_1 = dec_1 % dec_2; result = dec_1 / dec_2
void dec_div_intmantissa(decimal* dec_1, decimal dec_2, decimal* result);
void bigdec_div_intmantissa(bigdecimal* dec_1, bigdecimal dec_2,
                            bigdecimal* result);
void dec_bank_round(decimal* quotient, decimal remainder);
void bigdec_bank_round(bigdecimal* quotient, bigdecimal remainder);

// returns true - if % 10 == 0
bool is_able_divide10(bigdecimal bdec);

// doesn't consider scales!!! scale_1 == scale_2
void bigdec_add_mantissa(bigdecimal* dec_1, bigdecimal dec_2);
void bigdec_sub_mantissa(bigdecimal* dec_1, bigdecimal dec_2);

// doesn't consider scales!!! scale_1 == scale_2
// returns 0 - dec_1 == dec_2
// -1 dec_1 < dec_2
// 1 dec_1 > dec_2
int bigdec_cmp_mantissa(bigdecimal dec_1, bigdecimal dec_2);
void exchange_values(bigdecimal* dec_1, bigdecimal* dec_2);

/* returns:
// 0 — OK;
// 1 — the number is too large or equal +infinity;
// 2 — the number is too small or equal -infinity;
// 3 — division by 0;
// 4 - wrong input.*/
int add(decimal value_1, decimal value_2, decimal* result);
int sub(decimal value_1, decimal value_2, decimal* result);
int mul(decimal value_1, decimal value_2, decimal* result);
int dec_div(decimal value_1, decimal value_2, decimal* result);

/* returns:
 - 0 — FALSE;
 - 1 — TRUE. */
int is_less(decimal, decimal);
int is_less_or_equal(decimal, decimal);
int is_greater(decimal, decimal);
int is_greater_or_equal(decimal, decimal);
int is_equal(decimal, decimal);
int is_not_equal(decimal, decimal);
int compare_decimal(decimal first, decimal second);

// returns:
// - 0 — OK;
// - 1 — conversion error or - if dst == NULL.
int from_int_to_decimal(int src, decimal* dst);
// int from_float_to_decimal(float src, decimal* dst);
int from_decimal_to_int(decimal src, int* dst);
// (0 < |x| < 1e-28) -> value = 0, returns 1
// (|x| > 79,228,162,514,264,337,593,543,950,335) +-infinity -> returns 1
int from_float_to_decimal(float src, decimal* dst);
int from_decimal_to_float(decimal src, float* dst);

// returns:
// - 0 — OK;
// - 1 — calculation error.
int dec_floor(decimal value, decimal* result);
int dec_round(decimal value, decimal* result);
int truncate(decimal value, decimal* result);
int negate(decimal value, decimal* result);

#define INT_BIT_COUNT 32
// bitn in range [0, 127] from right to left: [127 ... 96] [95 94 ... 2 1 0]
// returns 1 or 0
int get_dec_bit(decimal number, unsigned int bitn);
void set_dec_bit(decimal* number, unsigned int bitn, int value);

unsigned int get_dec_scale(decimal* dec);
void set_dec_scale(decimal* dec, unsigned int exp);

// bitn in range [0, 255] from right to left: [255 ... 224] [223 222 ... 2 1 0]
// returns 1 or 0
int get_bigdec_bit(bigdecimal number, unsigned int bitn);
void set_bigdec_bit(bigdecimal* number, unsigned int bitn, int value);

// shift only mantissa of the number to the left
// returns
// 1 - if there was an overflow in bits[6]
// 0 - OK
int bigdec_shift_bit(bigdecimal* number, unsigned int shift_count);

int get_bigdec_scale(bigdecimal* dec);
void set_bigdec_scale(bigdecimal* dec, int exp);

// bitn in range [0, 7] from right to left: 7 6 5 4 3 2 1 0
int get_uint_bit(unsigned int number, unsigned int bitn);
void set_uint_bit(unsigned int* number, unsigned int bitn, int value);