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
#include <string.h>

#define Qt(hold,num) ((hold+num) % (num*2))

// typedef struct	s_heredoc
// {
// 	char *content;
// 	struct s_heredoc *next;
// }				t_heredoc;
typedef struct	s_heredoc
{
	int heredoc_fd;
	char **limiter;
}				t_heredoc;

typedef struct	s_redir
{
	int	in;
	int	out;
    int append;
    t_heredoc s_heredoc;
}				t_redir;

/* parse.c */
char **pipe_split(char *entry);
char *edit_data(char *substring,int var_flag, int quote_flag, int len);

/* utils.c */
int     quote_type(char quote,int *q_hold);
int		pass_quote(char *entry,int index);
int		count_char(char *read, char input);
char	*char_to_str(char ch);

/* utils2.c */
int spaceTypes(char input);
int pass_space(char *entry);
// char *in_quote(char *entry, int var_flag);
void reset_q_type(int q_hold);

/* utils3.c */
int is_regular_data(char data, int var_flag, int quote_flag, int quote);

/* variable.c */
char *get_variable_value(char *data, int *len);

/* prompt.c */
char *add_symbol();

#endif