#include "minishell.h"

/* 
spaceTypes:
Checks if a character is a space character
*/
int spaceTypes(char input)
{
    if (input == ' ' || input == '\t' || \
        input == '\r' || input == '\n') {
        return 1;
    }
    return 0;
}

/* 
pass_space:
Counts how many consecutive space characters are at the beginning of a string.
*/
int pass_space(char *entry)
{
    int in_quote;
    int len;

    len = 0;
    while (entry[len] != '\0' && spaceTypes(entry[len]))
    {
        len++;
    }
    return len;
}

/*
del_first_last_space:
Deletes the stack of first and last spaces of entries
*/
char *del_first_last_space(char *entry)
{
	int	frst;
	int	lst;
	int	len;

	frst = 0;
	lst = 0;
	while (spaceTypes(entry[frst]))
		frst++;
	lst = ft_strlen(entry)-1;
	while (spaceTypes(entry[lst]))
		lst--;
	len = lst-frst+1;
	return (ft_substr(entry,frst,len));
}


char *in_quote(char *entry, int var_flag)
{
    int     in_quote;
    int     len;
    char    *fixed_data;
    int     index;

    in_quote = quote_type(*entry,0);
    while (*entry != '\0' && in_quote != 0)
    {
        entry++;
        //if flag
        //getvar() //realloc gerekli
        in_quote = quote_type(*entry,in_quote);
        if(in_quote != 0)
            fixed_data[index++] = *entry;
        else
        {
            fixed_data[index] = '\0';
            return fixed_data;
        }
    }
    fixed_data[index] = '\0';
    return fixed_data;
}