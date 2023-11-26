/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:12 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 23:10:39 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"

int	print(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	if (c == 'p')
		ft_putptr(va_arg(args, void *));
	if (c == 'd')
		//return (0);
		ft_putdec(va_arg(args, double));
	if (c == 'i')
		ft_putnbr(va_arg(args, int));
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
	int var = 10;
	int *ptr = &var;
	ft_printf("I am number %i %s  %% %x %X %p %d", 1, "this is a test", 27, 27, ptr, 2.7);
}
