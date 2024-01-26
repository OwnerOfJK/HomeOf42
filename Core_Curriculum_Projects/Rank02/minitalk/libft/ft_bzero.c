/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:41:24 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 15:36:20 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *dst, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)dst;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
