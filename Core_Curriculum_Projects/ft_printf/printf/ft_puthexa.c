/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:46:54 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 22:25:57 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	h_digits(unsigned int n)
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

int	ft_puthexa(unsigned int nbr, int upper_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		ft_puthexa((nbr / 16), upper_case);
	if (upper_case == 1)
		ft_putchar(upper_digits[nbr % 16]);
	else
		ft_putchar(lower_digits[nbr % 16]);
	return (h_digits(nbr));
}
