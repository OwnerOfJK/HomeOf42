#include <stdlib.h>
#include "libft.h"

char *ft_strtrim(char const *s)
{
    int i = 0;
    int j = 0;
    int len = ft_strlen_const(s);
    char *trimmed_str = (char *)malloc((len + 1) * sizeof(char));
    if (trimmed_str == NULL)
    {
        return (0);
    }
    while (s[i] != '\0')
    {
        if (ft_isspace(s[i]) == 1)
        {
            i++;
            len--;
        }
        else
        {
            trimmed_str[j] = s[i];
            i++;
            j++;
        }
    }
    trimmed_str[j] = '\0';
    return (trimmed_str);
}