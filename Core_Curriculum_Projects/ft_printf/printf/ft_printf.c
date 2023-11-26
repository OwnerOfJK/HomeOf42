/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:12 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 22:25:39 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		if (n < 10)
		{
			ft_putchar(n + 48);
		}
	}
}

int	print(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	if (c == 'p')
		return (0); //void * pointer argument
	if (c == 'd')
		ft_putnbr(va_arg(args, int));
	if (c == 'i')
		return (0); //decimal (base 10) number
	if (c == 'u')
		return (0); //decimal (base 10) number
	if (c == 'x')
		ft_puthexa(va_arg(args, unsigned int), 1);
	if (c == 'X')
		ft_puthexa(va_arg(args, unsigned int), 0);
	if (c == '%')
		ft_putchar('%');
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			print(format[i + 1], args);
			i += 2;
			if (format[i] == '\0')
				return (0);
		}
		ft_putchar(format[i]);
		i++;
	}
	i = 0;
	return (0);
}


int	main(void)
{
	ft_printf("I am number %d %s  %% %x %X", 1, "this is a test", 27, 27);
}
