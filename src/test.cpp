#include "../include/support.h"
#include "../include/solve_func.h"
#include "../include/test.h"

#define check_for_test(condition, error)      				        														                   	 \
if (!(condition))                                                                                                                                \
{                                                                                                                                                \
    printf("\033[91mОшибка в условии %s в строке %d в файле %s в функции %s \n\033[39m", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__ );  \
    *error = test_error;                                                                                                                         \
}

const char *INPUT_FILE_WITH_TESTS = "res/proverka.txt";

//============================================================================================
///@brief  Запуск тестового режима
///
///@note
///
///@return код ошибки
//============================================================================================

Errors test_of_setter()
{
    FILE *f_input = fopen(INPUT_FILE_WITH_TESTS, "r");

    read_file(f_input);

    if (f_input != nullptr) fclose(f_input);
    return no_error;
}

//============================================================================================
///@brief              Чтение тестового файла
///
///@param [in] f_input файл с входными данными
///
///@note
///
///@return             код ошибки
//============================================================================================

Errors read_file(FILE *f_input)
{
    check((f_input != 0), arg_function_is_nullptr)

    int amount = 0;

    Errors error = no_error;

    double koef[3] = {};

    NumberRoots n_roots = strange_case;
    int true_n_roots = strange_case;

    double root1 = 0.0;
    double root2 = 0.0;

    double true_root1 = 0.0;
    double true_root2 = 0.0;

    fscanf(f_input, "%d", &amount);

    for (int num = 1; num <= amount; num++)
    {
        fscanf(f_input, "%lf %lf %lf %d %lf %lf", &koef[0], &koef[1], &koef[2], &true_n_roots, &true_root1, &true_root2 );

        check( true_n_roots >= -1 && true_n_roots <= 3, test_read_error)

        settle_square(&n_roots, koef, &root1, &root2);

        check_for_test( (int)n_roots == true_n_roots &&
                        is_equal_with_zero(fabs(root1) - fabs(true_root1)) &&
                        is_equal_with_zero(fabs(root2) - fabs(true_root2)),
                        &error)

        if (error == no_error)
        {
            printf("\033[92mТест № %d прошёл успешно\n\033[39m", num);
        }
        else
        {
            printf("\033[91m(!)Тест № %d провален\n\033[39m", num);
        }
        error = no_error;
    }

    return no_error;
}
