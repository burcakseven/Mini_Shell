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
    splitted = malloc(sizeof(char *) * (count_char(entry,'|') + 2));
    while (entry[end] != '\0')
    {
        end += pass_quote(entry,end);
        if (entry[end] == '|')
        {
			ft_substr(entry, start, (end - start));
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

char *edit_data(char *substring, int len)
{
	char *edited_data;
	char *temp;
	char *joined_data;
	int quote;

	quote = 0;
	joined_data = "";
	while (*substring != '\0')
	{
		while (quote_type(*substring, &quote))
			substring++;

		if (quote != 1 && *substring == '$')
		{
			edited_data = get_variable_value(substring, &len);
			substring += len;
		}
		else
			edited_data = char_to_str(*substring++);
		temp = ft_strjoin(joined_data, edited_data);
		joined_data = temp;
	}
	reset_q_type(quote);
	return joined_data;
}

