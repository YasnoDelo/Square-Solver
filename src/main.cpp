//--------------------------------------------------
// TODO: 4) доки.
//--------------------------------------------------

#include "../include/user_func.h"
#include "../include/solve_func.h"
#include "../include/test.h"


const int N_KOEFF = 3;

int main()
{
	double koeff[N_KOEFF] = {};
	double root1 = NAN, root2 = NAN;

	NumberRoots n_roots = strange_case;

	Errors error = no_error;

	test_of_setter();

    int is_run_solver_quadr_eq = 1;

	printf("Решение уравнения вида a*x^2+b*x+c = 0 \n");
	while (is_run_solver_quadr_eq)
	{
		error = enter_pers_data(koeff, N_KOEFF);
		if (error != no_error)
		{
            return error;
		}

		preview(koeff[0], koeff[1], koeff[2]);

		settle_square(&n_roots, koeff, &root1, &root2);

		output_root(n_roots, root1, root2);

		printf("Для продолжения введите 1. Для выхода из программы введите любое другое число \n");

		is_run_solver_quadr_eq = enter_run_var();
	}

    return no_error;
}
