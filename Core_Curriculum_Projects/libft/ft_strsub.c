#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    int i = 0;
    char *substr = (char *)malloc((len + 1) * sizeof(char));
    if (substr == NULL)
    {
        return (0);
    }
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}