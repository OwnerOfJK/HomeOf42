#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
    }
    else
    {
        if (n < 0)
        {
            ft_putchar_fd('-', fd);
            n = -n;
        }
        if (n > 9)
        {
            ft_putnbr(n / 10);
            ft_putnbr(n % 10);
        }
        if (n < 10)
        {
        ft_putchar_fd(n + 48, fd);
        }
    }
}