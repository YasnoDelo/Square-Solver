#include "../include/user_func.h"
#include "../include/solve_func.h"
#include "../include/support.h"

void clear_buf()
{
	while (getchar() != '\n');
}

void preview(double a, double b, double c)
{
	if (!is_equal_with_zero(a))
	{
		if (!is_equal_with_zero(b))
			if (!is_equal_with_zero(c))
			{
				printf("Введённое уравнение: \n%.2f*x^2 %+.2f*x %+.2f = 0 \n", a,b,c);
			}
			else
			{
				printf("Введённое уравнение: \n%.2f*x^2 %+.2f*x = 0 \n", a,b);
			}
		else
			if (!is_equal_with_zero(c))
			{
				printf("Введённое уравнение: \n%.2f*x^2 = 0 \n", a);
			}
			else
			{
				printf("Введённое уравнение: \n%.2f*x^2 +%+.2f = 0 \n", a,c);
			}
	}
	else
	{
		if (!is_equal_with_zero(b))
		{
			if (!is_equal_with_zero(c))
			{
				printf("Введённое уравнение: \n%.2f*x +%+.2f = 0 \n", b,c);
			}
			else
			{
				printf("Введённое уравнение: \n%.2f*x = 0 \n",b);
			}
		}
		else
		{
			if (!is_equal_with_zero(c))
			{
				printf("Введённое уравнение: \n%.2f = 0 \n", c);
			}
			else
			{
				printf("Введённое уравнение: \n0 = 0 \n");
			}
		}
	}
}

void output_root(NumberRoots root_status, double x1, double x2) // answer in x1 when just 1 root  // -1 in ammount then infinity
{
	switch (root_status)
	{
		case inf_root_eq:
		{
			printf("Уравнение имеет бесконечно много решений. Любое рациональное значение является ответом. \n");
			break;
		}
		case zero_root_eq:
		{
			printf("Уравнение не имеет решений. \n");
			break;
		}
		case one_root_eq:
		{
			printf("У уравнения одно решение: %.4lf \n", x1);
			break;
		}
		case two_root_eq:
		{
			printf("У уравнения два решения: %.4lf и %.4lf \n", x1, x2);
			break;
		}
		default:
		{
			printf("Такого быть не может! Ошибочное количество решений! \n");
		}
	}
}

Errors enter_pers_data(double *koeff, size_t array_koeff_size)
{
	check(koeff != nullptr, arg_function_is_nullptr)

	char array_koeff_symbs[] = {'a', 'b', 'c'};

	for (size_t count = 0; count < array_koeff_size; count++)
	{
		enter_koeff(koeff + count, array_koeff_symbs[count]);
	}

	return no_error;
}

Errors enter_koeff(double *koeff, char koeff_symbs)
{
	check(koeff != nullptr, arg_function_is_nullptr)

	printf("Введите %c: \n", koeff_symbs);
	while ( (scanf("%lf", koeff)) != 1 )
	{
			printf("Коэффициент должен быть числовым. Попробуйте ввести его ещё раз. \n");
			clear_buf();
	}

	clear_buf();

	return no_error;
}

int enter_run_var()
{
	int var = 0;

	while ( !(scanf("%d", &var)) )
	{
		printf("Введите числовое значение: \n");
		clear_buf();
	}

	clear_buf();

	return (var == 1) ? 1 : 0;
}
