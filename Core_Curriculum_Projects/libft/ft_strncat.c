#include "libft.h"

char *ft_strncat(char *dest, const char *src, int len)
{
    int i = 0;
    int j = ft_strlen(dest);
    if (dest[j] != '\0')
    {
        return (0);
    }
    while (src[i] != '\0' && i < len)
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    return (dest);
}