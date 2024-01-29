/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:12 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 14:10:49 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	print(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = pft_putchar(va_arg(args, int));
	else if (c == 's')
		count = pft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_putptr((unsigned long)va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		count = pft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_lower_puthexa(va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_upper_puthexa(va_arg(args, unsigned int));
	else if (c == '%')
		count = pft_putchar(c);
	else
		count = pft_putchar(va_arg(args, int));
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
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] == '%')
		{
			result += print(format[i + 1], args);
			format_len -= 2;
			if (format[i + 2] == '\0')
				return (result + format_len);
			i += 2;
		}
		ft_putchar(format[i]);
		i++;
	}
	return (result + format_len);
}
