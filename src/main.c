#include "minishell.h"

int main(int argc, char const *argv[])
{
    while(1)
    {
    char *deneme= readline("|");
    char **merha= pipe_split(deneme);
    int i = 0;
    while (ft_strncmp(merha[i],"\0",2))
    {
        printf("%s",merha[i++]);
    }
    // edit_data(deneme,1,1,0);
    
    }
    return 0;
}
