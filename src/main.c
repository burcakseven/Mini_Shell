#include "minishell.h"

int main(int argc, char const *argv[])
{
    // while(1)
    char *deneme= readline("|");
    char *yzdr = edit_data(deneme,0,1,0);
    printf("%s",yzdr);
    return 0;
}
