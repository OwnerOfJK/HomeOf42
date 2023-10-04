#include "libft.h"

int ft_toupper(int c)
{
    if (ft_islowalpha(c) == 1)
    {
        c -= 32;
    }
    return (c);
}