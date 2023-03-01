#include "minishell.h"

int is_limiter(char symbol)
{
    if (symbol == '\0' || spaceTypes(symbol))
        return 0;
    if(symbol == '<' || symbol == '>')
        return 0;
    if (symbol == '|')
        return 0;
    return 1;
}

void fill_heredoc_limiter(char *entry,t_heredoc *h_data)
{
    static int index = 0;
    int len;
    int pass;

    pass = 0;
    len = 0;
    while (is_limiter(entry[len]))//space '<' '>' ya da '|'
    {
        pass = pass_quote(entry,index);
        if(pass)
            len += pass;
        else
            len++;
    }
    printf("%i",len);
    ft_memcpy(h_data->limiter[index],entry,len);
    index++;
}

int is_syntx_err(char *entry,int pipe_flag,int heredoc_flag,t_heredoc *heredoc)
{
    char symbol;
    int index;

    index = pass_space(entry);
    symbol = entry[index];
    if(symbol == '\0')
        return 1;
    else if(symbol == '<' && pipe_flag)
        return 2;
    else if (symbol == '>' && pipe_flag)
        return 3;
    else if (symbol == '|')
        return 4;
    if(heredoc_flag)
        fill_heredoc_limiter(&entry[index],heredoc);
    return 0;
}

int err_type(char *entry,int *index,t_heredoc *heredoc)
{
    if (entry[*index] == '|')
    {
        (*index)++;
        return(is_syntx_err(&entry[*index],1,0,heredoc));
    }
    else if (!ft_strncmp(&entry[*index],"<<",2))
    {
        *index += 2;
        return(is_syntx_err(&entry[*index],0,1,heredoc));
    }
    else if (!ft_strncmp(&entry[*index],">>",2))
    {
        *index += 2;
        return(is_syntx_err(&entry[*index],0,0,heredoc));
    }
    else if(entry[*index] == '<' || entry[*index] == '>')
    {
        (*index)++;
        return(is_syntx_err(&entry[*index],0,0,heredoc));
    }
    return 0;
}

int syntx_err(char *entry, t_heredoc *heredoc)
{
    int error;
    int index;
    int pass_q;

    index = 0;
    index += pass_quote(entry,index);
    error = 0;
    while (entry[index] != '\0')
    {
        if (entry[index] == '<' || entry[index] == '>')
        {
            error = err_type(entry,&index,heredoc);
        }else if (entry[index] == '|')
            error = err_type(entry,&index,heredoc);
        if(error)
            return 1;

        pass_q = pass_quote(entry,index);
        if(pass_q > 0)
            index += pass_q;
        else
            index++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    t_heredoc heredoc;
    char *entry;
    int error = 1;
    heredoc.limiter=malloc(sizeof(t_heredoc)*5);
    while (error)
    {
        // if(entry != NULL)
        //     free(entry);
        entry = readline(add_symbol());
        error = syntx_err(entry,&heredoc);
        printf("%s",heredoc.limiter[0]);
    }
    //heredoc okuması burada
}