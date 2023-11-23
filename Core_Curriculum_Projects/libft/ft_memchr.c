/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:20 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 18:33:35 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t size)
{
	size_t		i;
	const char	*p;

	i = 0;
	p = (const char *)src;
	while (i < size)
	{
		if (p[i] == c)
		{
			return ((void *)(&p[i]));
		}
		i++;
	}
	return (0);
}
