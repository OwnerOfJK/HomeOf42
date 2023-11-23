/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:43:52 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 18:34:05 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strlcat(char *dest, const char *src, int len)
{
	int	dest_len;
	int	src_len;
	int	total_len;
	int	i;

	dest_len = ft_strlen_const(dest);
	src_len = ft_strlen_const(src);
	total_len = dest_len + src_len;
	i = 0;
	if (len <= dest_len)
		return (src_len + len);
	while (src[i] != '\0' && dest_len + i < len - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (total_len);
}
