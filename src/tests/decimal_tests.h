#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "../decimal.h"

Suite* suite_main_functions_tests(void);
Suite* suite_bit_functions_tests(void);
Suite* suite_common_functions_tests(void);
Suite* suite_conversion_functions_tests(void);
Suite* suite_from_int_to_decimal(void);
Suite* suite_from_decimal_to_int(void);
Suite* suite_float_to_decimal(void);
Suite* suite_from_decimal_to_float(void);

Suite* suite_mul(void);
Suite* suite_div(void);
Suite* add_cases(void);
Suite* sub_cases(void);

Suite* dec_floor_suite(void);
Suite* dec_round_suite(void);
Suite* suite_truncate(void);
Suite* negate_suite(void);

Suite* suite_is_equal_test(void);
Suite* suite_is_greater_or_equal_test(void);
Suite* suite_is_greater_test(void);
Suite* suite_is_less_test(void);
Suite* suite_is_less_or_equal_test(void);
Suite* suite_is_not_equal_test(void);

void run_tests(void);
void run_testcase(Suite* testcase);

#endif  // TESTS_H
