/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:01 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 14:22:58 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (ft_isalnum(c) == 1 || (c >= ' ' && c <= '/')
		|| (c >= ':' && c <= '@')
		|| (c >= '[' && c <= '`') || (c >= '{' && c <= '~'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}