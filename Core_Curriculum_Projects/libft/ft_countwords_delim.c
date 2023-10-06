#include "libft.h"

int ft_countwords_delim(char *str, char charset)
{
    int i = 0;
    int word_count = 0;

    while (str[i] != '\0')
    {
        while (ft_checkchar(str[i], charset) == 0 && str[i] != '\0')
        {
            if(ft_checkchar(str[i + 1], charset) == 1)
            {
                word_count++;
            }
            i++;
        }
        i++;
    }
    if (ft_checkchar(str[i - 1], charset) == 0)
    {
        word_count++;
    }
    return(word_count);
}