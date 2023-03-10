#include "minishell.h"

void print_syntx_err(int error)
{
    printf("syntax error near unexpected token ");
    if(error == 1)
        printf("\'newline\'");
    else if(error == 2)
        printf("\'<\'");
    else if(error == 3)
        printf("\'>\'");
    else if(error == 4)
        printf("\'|\'");
    printf("\n");
}

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
    if(h_data->limiter == NULL)
        h_data->limiter=malloc(sizeof(t_heredoc)*5);
    while (is_limiter(entry[len]))//space '<' '>' ya da '|'
    {
        pass = pass_quote(entry,index);
        if(pass)
            len += pass;
        else
            len++;
    }
    h_data->limiter[index] = malloc(len+1);
    ft_memcpy(h_data->limiter[index],entry,len);
    h_data->limiter[index][len] = '\0';
    index++;
    h_data->limiter[index] = NULL;
}

int is_syntx_err(char *entry,int pipe_flag,int heredoc_flag,t_heredoc *heredoc)
{
    char symbol;
    int index;

    index = pass_space(entry);
    symbol = entry[index];
    if(symbol == '\0')
        return 1;
    else if(symbol == '<' && !pipe_flag)
        return 2;
    else if (symbol == '>' && !pipe_flag)
        return 3;
    else if (symbol == '|')
        return 4;
    // if(pipe_flag) // redir_heredoc++;
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
            error = err_type(entry,&index,heredoc);
        else if (entry[index] == '|')
            error = err_type(entry,&index,heredoc);
        if(error)
        {
            print_syntx_err(error);
            return 1;
        }
        pass_q = pass_quote(entry,index);
        if(pass_q > 0)
            index += pass_q;
        else
            index++;
    }
    return 0;
}
