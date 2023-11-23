/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:28 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 17:19:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned int			i;
	unsigned char			*p_dst;
	unsigned const char		*p_src;

	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned const char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < len)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
