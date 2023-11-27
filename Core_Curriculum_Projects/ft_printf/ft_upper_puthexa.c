/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_puthexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:46:54 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 18:12:53 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_upper_puthexa(long nbr, int base)
{
	static char	upper_digits[] = "0123456789ABCDEF";

	if ((int)nbr >= base)
		ft_upper_puthexa((nbr / base), base);
	ft_putchar(upper_digits[nbr % base]);
	return (ft_getdigits(nbr, base));
}
