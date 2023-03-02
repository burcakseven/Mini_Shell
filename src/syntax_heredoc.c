#include "minishell.h"

int is_contain_quote(char *heredoc) //$den sonra quote içindeyse a $ ekleme
{
	char *squote;
	char *dquote;
	dquote = ft_strchr(heredoc,'\"');
	squote = ft_strchr(heredoc,'\'');
	if(dquote != 0 || squote != 0)
		return 1;
	return 0;
}

char* append_char(char* str, char c) {
    size_t len = strlen(str);
    char* new_str = malloc(sizeof(char) * (len + 3));

    if (new_str == NULL) { // handle memory allocation failure
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    new_str[0] = c;
    strncpy(new_str + 1, str, len);
    new_str[len + 1] = c;
    new_str[len + 2] = '\0';

    return new_str;
}

char *edit_heredoc_read(int quote_type)
{
	if(quote_type == 1)
		return(edit_data(append_char(readline(">"),'\''),0));
	else
		return(edit_data(append_char(readline(">"),'\"'),0));
}

void wait_limiter(char *heredoc_limit,int heredoc_fd)
{
	char *edit_limiter;
	int quote_type;
	char *readl;

	quote_type = is_contain_quote(heredoc_limit);
	// edit_limiter = edit_data(heredoc_limit,0); //edit_data seg fault alıyo
	// edit_data(heredoc_limit,0);
	edit_limiter = heredoc_limit;
	// readl = edit_heredoc_read(quote_type);
	// while (strncmp(edit_limiter,readl,ft_strlen(readl)))
	// {
	// 	write(heredoc_fd,readl,ft_strlen(readl));
	// 	write(heredoc_fd,"\n",1);
	// 	readl = edit_heredoc_read(quote_type);
	// }
	
}

void read_heredoc(t_heredoc *heredoc)
{
	int	heredoc_index;

	heredoc_index = 0;
	while (heredoc->limiter[heredoc_index] != NULL)
	{
	if(heredoc->heredoc_fd>0)
		close(heredoc->heredoc_fd);
	heredoc->heredoc_fd = open("build/heredoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	wait_limiter(heredoc->limiter[heredoc_index],heredoc->heredoc_fd);
	heredoc_index++;
	}
}

int main(int argc, char const *argv[])
{
    t_heredoc heredoc;
    char *entry;
    int error = 1;
	heredoc.limiter = NULL;
    while (error)
    {
        entry = readline(add_symbol());
        error = syntx_err(entry,&heredoc);
    }
	if(heredoc.limiter != NULL)
		read_heredoc(&heredoc);
    //heredoc okuması burada
}