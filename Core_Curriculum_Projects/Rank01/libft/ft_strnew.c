/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:21 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 15:32:33 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}
	while (i <= size)
	{
		new_str[i] = '\0';
		i++;
	}
	return (new_str);
}
