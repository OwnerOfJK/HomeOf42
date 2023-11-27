#include "libftprintf.h"

int ft_putnbr(long n) {
    int count;

    count = 0;
    if (n < 0) {
        count += ft_putchar('-');
        n = -n;
    }
    if (n < 10) {
        count += ft_putchar(n + '0');
    } else {
        count += ft_putnbr(n / 10);
        count += ft_putchar('0' + (n % 10));
    }
    return count;
}