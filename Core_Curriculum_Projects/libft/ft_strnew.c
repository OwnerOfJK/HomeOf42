#include <stdlib.h>

char *ft_strnew(size_t size)
{
    size_t i = 0;
    char *new_str = (char *)malloc((size + 1) * sizeof(char));
    if (new_str == NULL)
    {
        return (NULL);
    }
    while (i <= size)
    {
        new_str[i] = '\0';
        i++;
    }
    return (new_str);
}