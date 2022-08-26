#ifndef user_func
#define user_func

#include "support.h"

void clear_buf();

void preview(double a, double b, double c);

Errors enter_koeff(double *change, char koeff_sym);

Errors enter_pers_data(double *koeff, size_t size);

void output_root(NumberRoots number, double x1, double x2);

int enter_run_var();

#endif
