#include "libft.h"

void    ft_putstr(char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
}