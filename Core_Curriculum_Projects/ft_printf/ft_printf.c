/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:12 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 18:41:56 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"

int	print(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_putptr((unsigned long)va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		count = ft_putnbr((long)va_arg(args, int));
	else if (c == 'u')
		count = ft_putunbr((long)va_arg(args, int));
	else if (c == 'x')
		count = ft_lower_puthexa((long)va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_upper_puthexa((long)va_arg(args, unsigned int));
	else
		count = ft_putchar(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;
	int		format_len;

	i = 0;
	result = 0;
	format_len = ft_strlen(format);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			result += print(format[i + 1], args);
			printf("\n result %d \n", result);
			i += 2;
			format_len -= 2;
			if (format[i] == '\0')
				break;
		}
		ft_putchar(format[i]);
		i++;
	}
	i = 0;
	printf("\n result %d \n", result);
	return (result + format_len);
}
