/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:37:41 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 20:06:04 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = ft_putstr("0");
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar('0' + (n % 10));
	return (count);
}
