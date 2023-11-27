/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:37:41 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/27 17:17:54 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr(long n, int base)
{
	if (n < 0)
		return (ft_putnbr((n + 1 + 4294967295), base));
	else
		return (ft_putnbr(n, base));
}
