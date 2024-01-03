/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:10 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 19:42:30 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, int len)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	if (dest[j] != '\0')
	{
		return (0);
	}
	while (src[i] != '\0' && i < len)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
