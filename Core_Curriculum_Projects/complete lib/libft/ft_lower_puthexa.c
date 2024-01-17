/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_puthexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:28:40 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 14:09:46 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_lower_puthexa(long nbr)
{
	int					count;
	static const char	hex_digits[] = "0123456789abcdef";

	count = 0;
	if (nbr < 16)
		count += pft_putchar(hex_digits[nbr]);
	else
	{
		count += ft_lower_puthexa(nbr / 16);
		count += pft_putchar(hex_digits[nbr % 16]);
	}
	return (count);
}
