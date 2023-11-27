/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:39:34 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 18:12:46 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdio.h>

static void	put_ptr_char(unsigned long n, unsigned int base)
{
	static char	digits[] = "0123456789abcdef";

	if (n >= base)
		put_ptr_char((n / base), base);
	ft_putchar(digits[n % base]);
}

int	ft_putptr(unsigned long n, unsigned int base)
{
	if (n == 0)
		return (0);
	ft_putstr("0x");
	put_ptr_char(n, base);
	return (ft_getdigits(n, base) + 2); //to be corrected
}
