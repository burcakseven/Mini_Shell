#include "minishell.h"

int is_variable_char(char data)
{
    if(data >= 'A' && data <= 'Z')
        return 1;
    else if (data >= 'a' && data <= 'z')
        return 1;
    else if(data >= '0' && data <= '9')
        return 1;
    else if(data == '_')
        return 1;
    else
        return 0;
}

int variable_len(char *data)
{
    int len = 0;

    while (data[len] != '\0' &&\
    is_variable_char(data[len]))
        len++;
    return len;
}

char *get_variable_value(char *data, int *len)
{
    char *variable;
    char *variable_value;

    *len = 0;
    if(*data != '$')
        return NULL;
    data++;
    if(is_variable_char(*data))
        return NULL;
    if(*data == '?')
    //len = 2;
    //execve_builtin return değeri ataması
    *len  = variable_len(data);
    variable = ft_substr(data,0,*len);
    variable_value = getenv(variable);
    *len++;
    free(variable);
    return variable_value;
}