#include "minishell.h"

int fill_heredoc(char *entry, int *index,)
{
    *index += 2;
    
}

int is_syntx_err(char symbol,int pipe,int heredoc,t_heredoc *heredoc)
{
    if(symbol == '\0')
        return 1;
    else if(symbol == '<' != pipe)
        return 2;
    else if (symbol == '>' != pipe)
        return 3;
    else if (symbol == '|')
        return 4;
    if(heredoc)
        // fill_heredoc() t_heredoc heredoc burada kullanılacak
    return 0;
}

int err_type(char *entry,int *index,t_heredoc *heredoc)
{
    if (entry[*index] == '|')
    {
        *index++;
        *index += pass_quote(&entry[*index],*index);
        return(is_syntx_err(entry[*index],1,0,heredoc));
    }
    else if (ft_strncmp(&entry[*index],"<<",2))
    {
        *index += 2;
        *index += pass_quote(&entry[*index],*index);
        return(is_syntx_err(entry[*index],0,1,heredoc));
    }
    else if (ft_strcnmp(&entry[*index],">>",2))
    {
        *index += 2;
        *index += pass_quote(&entry[*index],*index);
        return(is_syntx_err(entry[*index],0,0,heredoc));
    }
    else if(entry[*index] == '<' || entry[*index] == '>')
    {
        *index++;
        *index += pass_quote(&entry[*index],*index);
        return(is_syntx_err(entry[*index],0,0,heredoc));
    }
    else
        return 0;
}

int syntx_err(char *entry, t_heredoc *heredoc)
{
    int error;
    int index;

    index = 0;
    while (entry[index] != '\0')
    {
        // index += pass_quote(entry,index);
        if (entry[index] == '<' || entry[index] == '>')
            error = err_type(entry,index,heredoc);
        else if (entry[index] == '|')
            error = err_type(entry,index,heredoc);
        if(error)
            return 1;
        index++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    t_heredoc heredoc;
    char *entry;
    int error = 1;
    while (error)
    {
        if(entry)
            free(entry);
        entry = readline(add_symbol());
        error = syntx_err(entry,&heredoc);
    }
    //heredoc okuması burada
}