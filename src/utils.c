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
int quote_type(char quote, int hold)
{
    if (quote == '\'' || quote == '\"')
    {
        if(quote == '\'' && (hold == 0 || hold == 1))
            return (Qt(hold,1));
		else if(quote == '\"' && (hold == 0 || hold == 2 ))
        	return (Qt(hold,2));
    }
    return hold;
}

/*
pass_quote:
Passes the quote part and returns its length.
*/
int pass_quote(char *entry,int index)
{
    int in_quote;
    int len;

    entry += index;
    len = 0;
    in_quote = quote_type(*entry,0);
    while (entry[len] != '\0' && in_quote)
    {
        len++;
        in_quote = quote_type(*entry,in_quote);
        if (in_quote == 0)
            len++;
    }
    return len;
}

char *char_to_str(char ch)
{
    char* str = (char*) malloc(2 * sizeof(char)); // '\0' için yer ayırmak için 2 boyutlu char dizisi oluşturulur.
    str[0] = ch;
    str[1] = '\0';
    return str;
}

// void *ft_realloc(void *ptr, size_t size)
// {
//     void *new_ptr = NULL;

//     if (size == 0) {  // boyut sıfır ise bellek bloğunu serbest bırakır
//         free(ptr);
//         return NULL;
//     }

//     if (ptr == NULL) {  // bellek bloğu daha önce ayrılmamışsa, malloc() ile ayrılır
//         return malloc(size);
//     }

//     new_ptr = malloc(size);  // yeni bellek bloğu oluşturulur

//     if (new_ptr != NULL) {  // bellek bloğu başarıyla oluşturulduysa, eski veriler kopyalanır
//         memcpy(new_ptr, ptr, size);
//         free(ptr);  // eski bellek bloğu serbest bırakılır
//     }

//     return new_ptr;  // yeni bellek bloğunun adresi döndürülür
// }
