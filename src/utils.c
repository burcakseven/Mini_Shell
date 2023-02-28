#include "minishell.h"

/*
count_char
counts the number of specified characters in the entry
*/
int count_char(char *read, char input)
{
    int count;

    count = 0;
    while (*read != '\0')
    {
        if(*read++ == input)
            count++;
    }
    return count;
}

/*
quote_type:
It allows us to understand whether double quotes or single quotes come first.
*/
int quote_type(char quote,int *q_hold)
{
    static int hold = 0;
    if (quote == '\'' || quote == '\"')
    {
        if(quote == '\''&&(hold == 0 || hold == 1))
        {
            *q_hold = Qt(*q_hold,1);
            if(hold == 0)
                hold = 1;
            else if(hold == 1)
                hold = 0;
            return (1);
        }
		else if(quote == '\"' && (hold == 0 || hold == 2 )){
            *q_hold = Qt(*q_hold,2);
            if(hold == 0)
                hold = (2);
            else if (hold == 2)
                hold = 0;
            return(2);}
    }
    return 0;
}

/*
pass_quote:
Passes the quote part and returns its length.
*/
int pass_quote(char *entry,int index) //split_pipe için test edilecek
{
    int in_quote;
    int len;
    int q_hold;

    q_hold = 0;
    entry += index;
    len = 0;
    if(*entry != '\''&& *entry != '\"')
        return 0;
    quote_type(entry[len],&q_hold);
    while (entry[++len] != '\0')
    {
        if(quote_type(entry[len],&q_hold)!= 0)
            return len+1;
    }
    reset_q_type(q_hold);
    return len;
}

char *char_to_str(char ch)
{
    char* str = (char*) malloc(2 * sizeof(char)); // '\0' için yer ayırmak için 2 boyutlu char dizisi oluşturulur.
    str[0] = ch;
    str[1] = '\0';
    return str;
}
