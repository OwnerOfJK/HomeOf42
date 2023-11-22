/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:40 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 15:35:18 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*trimmed_str;

	i = 0;
	j = 0;
	len = ft_strlen_const(s);
	trimmed_str = (char *)malloc((len + 1) * sizeof(char));
	if (trimmed_str == NULL)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 1)
		{
			i++;
			len--;
		}
		else
		{
			trimmed_str[j] = s[i];
			i++;
			j++;
		}
	}
	trimmed_str[j] = '\0';
	return (trimmed_str);
}
