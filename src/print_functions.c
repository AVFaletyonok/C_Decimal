#include "decimal.h"

void bigdecimal_print(bigdecimal* num) {
  for (int i = 255; i >= 0; i--) {
    if ((i + 1) % 32 == 0) printf("[");
    printf("%d", get_bigdec_bit(*num, i) ? 1 : 0);
    if ((i + 1) % 32 == 1) printf("]");
    if (i % 8 == 0) printf(" ");
  }
  printf("\n");
}

void decimal_print(decimal* num) {
  for (int i = 127; i >= 0; i--) {
    if ((i + 1) % 32 == 0) printf("[");
    printf("%d", get_dec_bit(*num, i) ? 1 : 0);
    if ((i + 1) % 32 == 1) printf("]");
    if (i % 8 == 0) printf(" ");
  }
  printf("\n");
}

void float_print(float num) {
  unsigned int i_number = 0;
  memcpy(&i_number, &num, 4);
  printf("%d ", get_uint_bit(i_number, 31) ? 1 : 0);
  for (int j = 30; j >= 0; j--) {
    printf("%d", get_uint_bit(i_number, j) ? 1 : 0);
    if (j == 23 || j == 15 || j == 7) printf(" ");
  }
  printf("\n");
}

void uint_print(unsigned int number) {
  for (int j = 31; j >= 0; j--) {
    printf("%d", get_uint_bit(number, j) ? 1 : 0);
    if (j == 24 || j == 16 || j == 8) printf(" ");
  }
  printf("\n");
}
