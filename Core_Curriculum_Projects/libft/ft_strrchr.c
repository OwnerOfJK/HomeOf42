#include "libft.h"

char *ft_strrchr(char *str, int c)
{
    int len = ft_strlen(str);
    while (len > 0)
    {
        if(str[len] == c)
        {
            return(&str[len]);
        }
        len--;
    }
    return (0);
}