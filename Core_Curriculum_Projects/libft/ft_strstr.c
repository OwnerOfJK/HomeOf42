#include "libft.h"

char *ft_strstr(char *str, char *substr)
{
    int i = 0;
    int j = 0;
    int len_sub = ft_strlen(substr);

    while (str[i] != '\0')
    {
        while (str[i] == substr[j])
        {
            i++;
            j++;
            if (j == len_sub)
            {
                return(&str[i - len_sub]);
            }
        }
        i++;
    }
    return (0);
}