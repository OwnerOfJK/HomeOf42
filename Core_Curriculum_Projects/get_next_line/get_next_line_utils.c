/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:27:28 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/30 14:54:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>
#include <stddef.h>

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

char	*ft_strchr(char *s, int c)
{
	unsigned int		i;
	char				tmp;

	i = 0;
	tmp = (char)c;
	while (s[i])
	{
		if (s[i] == tmp)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == tmp)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		total_len;
	char	*joined_str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (joined_str == NULL)
	{
		return (0);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}