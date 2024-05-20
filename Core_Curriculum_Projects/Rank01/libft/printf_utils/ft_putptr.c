/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:39:34 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/20 14:30:09 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>

static int	put_ptr_char(unsigned long n)
{
	int					count;
	static const char	digits[] = "0123456789abcdef";

	count = 0;
	if (n >= 16)
	{
		count += put_ptr_char(n / 16);
	}
	count += ft_putchar(digits[n % 16]);
	return (count);
}

int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	else
		count += ft_putstr("0x");
	count += put_ptr_char(n);
	return (count);
}
