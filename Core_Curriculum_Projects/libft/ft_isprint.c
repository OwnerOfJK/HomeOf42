#include "libft.h"

int ft_isprint(int c)
{
    if (ft_isalnum(c) == 1 || (c >= ' ' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~'))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}