#ifndef support
#define support
#include <stdio.h>

enum NumberRoots : int
{
	inf_root_eq = -1,
	zero_root_eq,
	one_root_eq,
	two_root_eq,
    strange_case
};

enum Errors
{
    no_error,
    arg_function_is_nullptr,
    unknown_error,
    test_error,
    test_read_error
}; 

#define check(condition, type_error)      				        														                   		     \
    if (!(condition))                                                                                                                                \
    {                                                                                                                                                \
		printf("\033[91mОшибка в условии %s в строке %d в файле %s в функции %s \n \033[39m", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__ ); \
        return type_error;                                                                                                                           \
    }		                                                                                                                       

#endif
