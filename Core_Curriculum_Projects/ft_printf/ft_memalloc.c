/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:13 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 14:32:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*memory_area;

	i = 0;
	memory_area = malloc(size * sizeof(char));
	if (memory_area == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		memory_area[i] = 0;
		i++;
	}
	return (memory_area);
}
