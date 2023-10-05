#include <stdio.h>
#include "libft.h"

char *ft_strrchr(char *str, int c);

int main(void)
{
    char str[] = "hello";
    char c = 'l';
    printf("%s", ft_strrchr(str, c));
}

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