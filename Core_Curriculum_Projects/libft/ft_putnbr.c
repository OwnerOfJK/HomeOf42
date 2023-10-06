#include "libft.h"

void ft_putnbr(int nbr)
{
    if (nbr == -2147483648)
    {
        ft_putstr("-2147483648");
    }
    else
    {
        if (nbr < 0)
        {
            ft_putchar('-');
            nbr = -nbr;
        }
        if (nbr > 9)
        {
            ft_putnbr(nbr / 10);
            ft_putnbr(nbr % 10);
        }
        if (nbr < 10)
        {
        ft_putchar(nbr + 48);
        }
    }
}