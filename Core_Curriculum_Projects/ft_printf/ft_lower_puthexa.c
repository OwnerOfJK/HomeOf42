/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_puthexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:28:40 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 18:11:17 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_lower_puthexa(long nbr, int base)
{
	static char	lower_digits[] = "0123456789abcdef";

	if ((int)nbr >= base)
		ft_lower_puthexa((nbr / base), base);
	ft_putchar(lower_digits[nbr % base]);
	return (ft_getdigits(nbr, base));
}
