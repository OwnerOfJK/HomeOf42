#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = ft_strlen(dest);
    if (dest[j] != '\0')
    {
        return (0);
    }
    while (src[i] != '\0')
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}