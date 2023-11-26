/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:39:34 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 22:57:15 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	p_digits(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	put_ptr_char(unsigned long long addr)
{
	static char	digits[] = "0123456789abcdef";

	if (addr >= 16)
		put_ptr_char(addr / 16);
	ft_putchar(digits[(unsigned long long)addr % 16]);
}

int	ft_putptr(void *addr)
{
	if (addr == NULL)
		return (0);
	ft_putstr("0x");
	put_ptr_char((unsigned long long)addr);
	return (p_digits((unsigned long long)addr) + 2);
}
