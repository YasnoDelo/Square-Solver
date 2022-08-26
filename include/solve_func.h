#ifndef solve_func
#define solve_func

#include <math.h>

#include "support.h"

Errors approx(NumberRoots *smth, double *arg1, double *arg2);

int is_equal_with_zero(double comp_num);

Errors settle_square(NumberRoots *smth, double *koeff, double *x1, double *x2);

Errors settle_linear_eq(NumberRoots *smth, double b, double c, double *x1);

Errors run(double *peremen);
#endif
