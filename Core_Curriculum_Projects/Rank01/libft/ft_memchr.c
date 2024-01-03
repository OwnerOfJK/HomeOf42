/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:20 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 20:49:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				cur;
	unsigned char const	*data;

	cur = 0;
	data = (unsigned char const *)s;
	while (cur < n)
	{
		if (data[cur] == (unsigned char)c)
			return ((void *)(data + cur));
		cur++;
	}
	return (NULL);
}
