/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:38 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 14:47:00 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)dst;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (dst);
}
