#include "minishell.h"

/* 
pipe_split:
Split pipes except pipe in quote.
*/
char **pipe_split(char *entry) //test edilecek
{
    char    **splitted;
    int     end;
    int     start;
    int     index;

    start = 0;
    end = 0;
    index = 0;
    splitted = malloc(sizeof(char *) * (count_char(entry,'|') + 1));
    while (entry[end] != '\0')
    {
        end += pass_quote(entry,end);
        if (entry[end] == '|')
        {
            splitted[index] = ft_substr(entry, start, (end - start));
            start = end + 1;
            index++;
        }
        end++;
    }
    splitted[index] = ft_substr(entry, start, (end - start));
    splitted[index + 1] = "\0";
    return splitted;
}

/*
Holder[1] has new data in holder[0] old data merges it without memoryleak and returns.
*/
char *optimize_holder(char **holder) // free kullanıldığında quote için segfault alıyorum
{
    char *new_join_hold;
	if(holder[0]== NULL && holder[1] == NULL)
		return NULL;
	if(holder[0] == NULL)
		return holder[1];
	if(holder[1] == NULL)
		return holder[0];

    new_join_hold = ft_strjoin(holder[0],holder[1]);
    // free(holder[0]);
    // free(holder[1]);

    return (new_join_hold);
}

/*
data bana len'inden ayrılmış şekilde gelecek örnek merhaba 2 uzunluğu alınıp yeni entry me olacak
*/
char *edit_data(char *substring,int var_flag, int quote_flag, int len) //optimize holder'ın içinde strjoin kullanırken segfault alıyorum
{
	char	**holder;
	int		quote;

	quote = 0;
	holder = malloc(sizeof(char *) * 2);
    while (*substring != '\0')
    {
		if(quote_flag == 1)
		{
			while(quote_type(*substring,&quote))
				substring++;
		}
        if(var_flag == 1 && quote != 1 && *substring == '$')
        {
            holder[1] = get_variable_value(substring,&len);
			holder[0] = optimize_holder(holder);
			substring += len;
        }
		else
		{
			holder[1] = char_to_str(*substring++);
			holder[0] = optimize_holder(holder);
		}
    }
	reset_q_type(quote);
	return holder[0];
}
