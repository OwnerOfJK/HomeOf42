/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:02 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 19:45:56 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		s_len;
	char	*new_string;

	i = 0;
	s_len = ft_strlen(s);
	new_string = (char *)malloc((s_len + 1) * sizeof(char));
	if (new_string == NULL)
	{
		return (0);
	}
	while (i < s_len)
	{
		new_string[i] = f(s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
