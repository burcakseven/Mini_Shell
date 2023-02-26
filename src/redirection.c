#include "minishell.h"

/* 
The code finds the first index of a redirection character ('<' or '>') in a string,
excluding characters within quotation marks. It returns 0 if there is no such character.
*/
int search_redir(char *entry)
{
    int index;

    index = 0;
    while (entry[index] != '\0')
    {
        index += pass_quote(entry,index);
        if(entry[index] == '<' || entry[index] == '>')
            return index;
        index++;
    }
    return 0;
}

int redir_len(char *entry,int len)
{
    while (entry[len] != '\0')
    {
        len += pass_quote(entry,len);
        if(select_redir_symbol(entry) == 0 || spaceTypes)
            return (len);
        len++;
    }
    return (len);
}

int select_redir_symbol(char *entry)
{
    if(ft_strncmp(entry,">>",2))
        return 4;
    else if (*entry == '>')
        return 3;
    else if(ft_strncmp(entry,"<<",2))
        return 2;
    else if (*entry == '<')
        return 1;
    else
        return 0;
}

// char *parse_type(int symbol, char *entry)
// {
//     if(symbol != 2)
//     {
//         entry = edit_data(); //quote kontrolü $ kontrolü (single quote içinde çalışmaz)
//     }
//     else
//         entry = heredoc_parse;// heredoc'da eğer quote(herhangi) açılırsa heredoc var'ları çalıştırmıyor

//     return entry;
// }

int redirection_operation(char *entry, t_redir *redir)
{
    int symbol;
    int len;

    symbol = select_redir_symbol(entry);
    len = redir_len(entry,(symbol%2));
    entry = parse_type(symbol,ft_substr(entry,0,len));
    //open files and operations
    return len;
}

void redirection(char **entry, t_redir *redir)
{
    int index;
    int redir_index;
    int len;

    index = 0;
    while(entry[index])
    {
    redir_index = search_redir(entry[index]);
    if(redir_index == 0)
        return;
    len = redirection_operation(entry,redir);

    //del_red
    }
}