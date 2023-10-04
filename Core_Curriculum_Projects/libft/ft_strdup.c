#include <stdlib.h>
#include "libft.h"

char *ft_strdup(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    char *dup = (char *)malloc((len + 1) * sizeof(char))

    if (dup == NULL)
    {
        return (0);
    }
    while (str[i] != '\0')
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}