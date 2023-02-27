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

/* parse.c */
char *edit_data(char *substring,int var_flag, int quote_flag, int len);

/* utils.c */
// int		quote_type(char quote, int hold);
int quote_type(char quote);
int		pass_quote(char *entry,int index);
int		count_char(char *read, char input);
char	*char_to_str(char ch);

/* utils2.c */
int spaceTypes(char input);
char *in_quote(char *entry, int var_flag);

/* utils3.c */
int is_regular_data(char data, int var_flag, int quote_flag);

/* variable.c */
char *get_variable_value(char *data, int *len);

#endif