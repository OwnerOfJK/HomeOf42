/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:16 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 15:41:18 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned int			i;
	unsigned char			*p_dst;
	unsigned const char		*p_src;
	unsigned char			ch;

	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned const char *)src;
	ch = (unsigned char)c;
	while (i < len)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == c)
		{
			return (&p_dst[i]);
		}
		i++;
	}
	return (0);
}
