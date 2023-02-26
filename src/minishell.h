#ifndef MINISHELL_H
#define MINISHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include "libft.h"

#define Qt(hold,num) ((hold+num) % (num*2))

typedef struct	s_redir
{
	int	*in;
    int *in_index;
    int in_len;
	int	*out;
    int out_len;
    int *append;
    int append_len;
    char **heredoc;
    int heredoc_len;
}				t_redir;


/* utils.c */
int quote_type(char quote, int hold);
int pass_quote(char *entry,int index);
void *ft_realloc(void *ptr, size_t size);

/* utils2.c */
int spaceTypes(char input);
char *in_quote(char *entry, int var_flag);

/* variable.c */
char *get_variable_value(char *data, int *index, int *len);

#endif