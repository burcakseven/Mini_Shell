#include "minishell.h"

void prompt_msg(char **cwd)
{
    char    buff[4096 + 1];
    *cwd = getcwd(buff, 4096);
}

char *add_symbol()
{
    char *cwd;
    prompt_msg(&cwd);
    cwd = ft_strjoin(cwd," % ");
    return cwd;
}
