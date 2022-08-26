#include "../include/solve_func.h"
#include "../include/support.h"

const double EPSILON = 1.0e-09;
const int END_FUNC = 0;

//===========================================================================================
///@brief                Вычисление корней квадратного уравнения
///
///@param [in]  koeff[3] массив коэффициентов упорядоченный по убыванию старшинства
///@param [out] n_roots  колличество корней введённого уравнения
///@param [out] x1       первый корень
///@param [out] x2       второй корень
///
///@note                 в случае отсутствия корней или при бесконечном количестве решений \
                         корень уравнения зануляется
///
///@return               код ошибки
//============================================================================================

Errors settle_square(NumberRoots *n_roots, double *koeff, double *x1, double *x2)
{
	check(x1 != nullptr, arg_function_is_nullptr)
	check(x2 != nullptr, arg_function_is_nullptr)
	check(koeff != nullptr, arg_function_is_nullptr)
	check(n_roots != nullptr, arg_function_is_nullptr)

	double dis = 0;
	double sqrt_dis = 0;

	double a = koeff[0], b = koeff[1], c = koeff[2];

	double double_a = 2*a;

	*x1 = 0, *x2 = 0;

	if (is_equal_with_zero(a))
	{
		return settle_linear_eq(n_roots, b, c, x1);
	}
	else
	{
		dis = b*b - 2*double_a*c;

		if (is_equal_with_zero(dis))
		{
			*x1 = -b / double_a;
			*n_roots = one_root_eq;

			return no_error;
		}
		else if (dis < 0)
		{
			*n_roots = zero_root_eq;

			return no_error;
		}
		else if (dis > 0)
		{
			sqrt_dis = sqrt(dis);

			*x1 = (-b - sqrt_dis) / (double_a);
			*x2 = (-b + sqrt_dis) / (double_a);

			*n_roots = two_root_eq;

			return no_error;
		}
		else
		{
			check(END_FUNC, unknown_error)
		}
	}
}

//============================================================================================
///@brief               Решение линейного уравнения
///
///@param [in]  b       коэффициент при x
///@param [in]  c       свободный член
///@param [out] n_roots количество корней уравнения
///@param [out] x1      корень уравнения
///
///@note                в случае отсутствия корней или при бесконечном количестве решений \
                        корень уравнения зануляется
///
///@return              код ошибки
//============================================================================================


Errors settle_linear_eq(NumberRoots *n_roots, double b, double c, double *x1)
{
	check(n_roots != nullptr, arg_function_is_nullptr)
	check(n_roots != nullptr, arg_function_is_nullptr)

	if (is_equal_with_zero(b))
	{
		if (is_equal_with_zero(c))
		{
			*n_roots = inf_root_eq;

			return no_error;
		}
		else
		{
			*n_roots = zero_root_eq;

			return no_error;
		}
	}
	else
	{
		*x1 = -c / b;
		*n_roots = one_root_eq;

		return no_error;
	}
}

//============================================================================================
///@brief               Сравнение аргумента с нолём
///
///@param [in] comp_num сравниваемый аргумент
///
///@note
///
///@return              1 в случае, когда введённое число близко к нолю, иначе 0
//============================================================================================


int is_equal_with_zero(double comp_num)
{
	return ( fabs(comp_num) < EPSILON ) ? 1 : 0;
}
