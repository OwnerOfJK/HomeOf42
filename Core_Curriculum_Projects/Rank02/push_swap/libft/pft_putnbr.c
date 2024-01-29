/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:32:19 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/17 14:06:40 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += pft_putchar('-');
		n = -n;
	}
	if (n < 10)
		count += pft_putchar(n + '0');
	else
	{
		count += pft_putnbr(n / 10);
		count += pft_putchar('0' + (n % 10));
	}
	return (count);
}
