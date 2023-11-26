/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:46:54 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/26 21:57:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	ft_puthexa(unsigned int nbr, bool upper_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		ft_puthexa((nbr / 16), upper_case);
	if (upper_case == true)
		ft_putchar(upper_digits[nbr % 16]);
		//write(STDOUT_FILENO, &upper_digits[nbr % 16], 1);
	else
		ft_putchar(lower_digits[nbr % 16]);
		//write(STDOUT_FILENO, &lower_digits[nbr % 16], 1);
	return (h_digits(nbr));
}
