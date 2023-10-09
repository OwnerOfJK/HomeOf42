#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int total_len = ft_strlen_const(s1) + ft_strlen_const(s2);
    char *joined_str = (char *)malloc((total_len + 1) * sizeof(char));
    if (joined_str == NULL)
    {
        return (0);
    }
    while (s1[i] != '\0')
    {
        joined_str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        joined_str[i] = s2[j];
        i++;
        j++;
    }
    joined_str[i] = '\0';
    return (joined_str);
}