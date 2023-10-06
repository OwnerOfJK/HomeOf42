#include <stdio.h>
#include "libft.h"

int main(void)
{
    // char c = 'b';
    // printf("%d\n", ft_isalnum(c));
    // printf("%d\n", ft_isalpha(c));
    // printf("%d\n", ft_isascii(c));
    // printf("%d\n", ft_isdigit(c));
    // printf("%d\n", ft_isprint(c));
    // printf("%d\n", ft_isspace(c));
    // printf("%d\n", ft_atoi("   +234"));
    // printf("%d\n", ft_islowalpha(c));
    // printf("%d\n", ft_isupalpha(c));
    // printf("%c\n", ft_toupper(c));
    // printf("%c\n", ft_tolower(c));
    ft_putchar('b');
    ft_putchar('\n');
    ft_putchar_fd('b', 1);
    ft_putchar('\n');
    ft_putstr("hello_str");
    ft_putchar('\n');
    ft_putstr_fd("hello_str", 1);
    ft_putchar('\n');
    ft_putendl("hello_endl");
    ft_putchar('\n');
    ft_putendl_fd("hello_endl", 1);
    ft_putchar('\n');
    ft_putnbr(-123);
    ft_putchar('\n');
    ft_putnbr_fd(-123, 1);
    ft_putchar('\n');
}