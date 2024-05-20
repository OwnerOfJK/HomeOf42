/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_puthexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:46:54 by jkaller           #+#    #+#             */
/*   Updated: 2024/05/20 14:30:21 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_upper_puthexa(long nbr)
{
	int					count;
	static const char	hex_digits[] = "0123456789ABCDEF";

	count = 0;
	if (nbr < 16)
		count += ft_putchar(hex_digits[nbr]);
	else
	{
		count += ft_upper_puthexa(nbr / 16);
		count += ft_putchar(hex_digits[nbr % 16]);
	}
	return (count);
}
