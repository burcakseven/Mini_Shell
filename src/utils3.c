#include "minishell.h"

int is_regular_data(char data, int var_flag, int quote_flag)
{
    if(var_flag == 0 && quote_flag == 0)
        return 1;
    else if(var_flag == 1 && data != '$')
        return 1;
    else if(quote_flag == 1 && quote_type(data,0))
        return 1;
    return 0;
}