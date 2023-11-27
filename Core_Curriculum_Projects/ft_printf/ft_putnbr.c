#include "libftprintf.h"

int	ft_putnbr(long n, int base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(-n, base) + 1);
	}
	else if (n < base)
	{
		ft_putchar(n + '0');
		return (count + 1);
	}
	else
	{
		count = ft_putnbr(n / base, base);
		return (count + ft_putnbr(n % base, base));
	}
}
