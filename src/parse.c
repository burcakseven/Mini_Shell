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
    splitted = malloc(sizeof(char *) * (count(entry,'|') + 1));
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

// char *add_variable_to_data(char *data, int *index, int *len) silinebilir
// {
// 	char *variable;
// 	variable = get_variable_value(data, index, len);
// 	return(ft_strjoin(data-1,variable));
// }

char *optimize_holder(char **holder, char *cleaned_text)
{

}

/*
data bana len'inden ayrılmış şekilde gelecek örnek merhaba 2 uzunluğu alınıp yeni entry me olacak
*/
char *edit_data(char *substring,int var_flag, int quote_flag)
{
	char **holder;

	holder = malloc(sizeof(char *) * 2);


}





    // char	*cleaned_text;
    // int		index;
	// int		len;

    // cleaned_text = (char*) malloc((ft_strlen(substring)) * sizeof(char));
    // substring = del_first_last_space(substring);
    // while (*substring !='\0')
    // {
	// 	len = pass_quote(substring,0);
    //     //get_var
	// 	if()
    //     if((*substring != '\'' || *substring != '\"'))
    //         cleaned_text[index++] = *substring;
	// 	substring;
    // }
    // return