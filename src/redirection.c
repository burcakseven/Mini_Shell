#include "minishell.h"

/* 
The code finds the first index of a redirection character ('<' or '>') in a string,
excluding characters within quotation marks. It returns 0 if there is no such character.
*/
// /*
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

int redir_len(char *entry,int len)
{
    while (entry[len] != '\0')
    {
        len += pass_quote(entry,len);
        if(select_redir_symbol(entry) != 0 || spaceTypes(*entry))
            return (len);
        len++;
    }
    return (len);
}


int set_std_file(int in_fd, int out_fd)
{
    if(STDIN_FILENO != in_fd && in_fd > 0)
    {    
        dup2(STDIN_FILENO,in_fd);
        return in_fd;
    }
    if(STDOUT_FILENO != out_fd && out_fd > 0)
    {
        dup2(STDOUT_FILENO,out_fd);
        return out_fd;
    }
    return 0;
}

void file_operations(char *redir_param,int symbol, t_redir *redir)
{
    char *edited_param;
    int in_fd = STDIN_FILENO;
    int out_fd = STDOUT_FILENO;

    edited_param = edit_data(redir_param,0); // path'le birleştirilmesi gerekiyor
    if (symbol == 1)
        in_fd = open(edited_param, O_RDONLY);
	else if (symbol == 2)
        in_fd = redir->s_heredoc.heredoc_fd;//değişebilir (her pipe için heredoc'u nasıl depoluyorum?)
	if (symbol == 3)
    	out_fd = open(edited_param, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (symbol == 4)
    	out_fd = open(edited_param, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        
    if(set_std_file(in_fd,out_fd) == 0)
        printf("deneme");
    //file didnt opened
}

int redirection_operation(char *entry, t_redir *redir)
{
    int symbol;
    int len;

    symbol = select_redir_symbol(entry);
    len = redir_len(entry,(symbol%2)); // symbol doğru değil 4%2 = 0
    entry = ft_substr(entry,(symbol%2),len);
    file_operations(entry,symbol,redir);
    return len;
}

void redirection(char *entry, t_redir *redir) //char ** döndürecek
{
    int index;
    int redir_index;
    int len;

    index = 0;
    while(entry[index])
    redir_index = search_redir(entry);
    if(redir_index == 0)
        return;
    len = redirection_operation(entry,redir);
    //del_red
}
//  */