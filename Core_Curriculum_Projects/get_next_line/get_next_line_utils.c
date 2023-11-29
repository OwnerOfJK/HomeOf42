/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:25 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/29 11:44:34 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>


char	*ft_strjoin(char const *s1, char const *s2)
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
