#include "minishell.h"

/* 
pipe_split:
Split pipes except pipe in quote.
*/
char **pipe_split(char *entry)
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
char *optimize_holder(char **holder)
{
    char *new_join_hold;

    new_join_hold = ft_strjoin(holder[0],holder[1]);

	if(new_join_hold == NULL)
		return holder[0];

    free(holder[0]);
    free(holder[1]);
    return (new_join_hold);
}

char *edit_quote(char *data, int len, int var_flag)// holder'in freelenmesi gerekiyor
{
	char	**holder;
	int		variable_len;
	int		q_type;

	holder = malloc(sizeof(char *) * 2);
	q_type = quote_type(*data++,0);
	while (len > 0)
	{
		if(var_flag == 1 && *data == '$' && q_type == 2)
		{
			holder[1] = get_variable_value(data,&variable_len);
			holder[0] = optimize_holder(holder);
			data += variable_len;
		}
		else
		{
			holder[1] = char_to_str(*data++);
			holder[0] = optimize_holder(holder);
		}
	}
	return holder[0];
}

/*
data bana len'inden ayrılmış şekilde gelecek örnek merhaba 2 uzunluğu alınıp yeni entry me olacak
*/
char *edit_data(char *substring,int var_flag, int quote_flag, int len) //bundan çıkıtktan sonra substring free'lenebilir
{
	char	**holder;

	holder = malloc(sizeof(char *) * 2);
    while (*substring != '\0')
    {
        if(var_flag == 1)
        {
            holder[1] = get_variable_value(substring,&len);
			holder[0] = optimize_holder(holder);
			substring += len;
        }
		if(quote_flag == 1)
		{
			len = pass_quote(substring,0);
			holder[1] = edit_quote(substring,len,var_flag);
			holder[0] = optimize_holder(holder);
			substring += len;
		}
		if(is_regular_data(*substring,var_flag,quote_flag))
		{
			holder[1] = char_to_str(*substring++);
			holder[0] = optimize_holder(holder);
		}
    }
	return holder[0];
}
