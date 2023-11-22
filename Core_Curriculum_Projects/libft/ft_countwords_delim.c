/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords_delim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:41:36 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 14:20:02 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords_delim(char *str, char charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (ft_checkchar(str[i], charset) == 0 && str[i] != '\0')
		{
			if (ft_checkchar(str[i + 1], charset) == 1)
			{
				word_count++;
			}
			i++;
		}
		i++;
	}
	if (ft_checkchar(str[i - 1], charset) == 0)
	{
		word_count++;
	}
	return (word_count);
}
