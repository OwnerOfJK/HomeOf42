/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:41:36 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 19:06:00 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_countwords_delim(char *str, char charset)
// {
// 	int	i;
// 	int	word_count;

// 	i = 0;
// 	word_count = 0;
// 	while (str[i] != '\0')
// 	{
// 		while (ft_checkchar(str[i], charset) == 0 && str[i] != '\0')
// 		{
// 			if (ft_checkchar(str[i + 1], charset) == 1)
// 			{
// 				word_count++;
// 			}
// 			i++;
// 		}
// 		i++;
// 	}
// 	if (ft_checkchar(str[i - 1], charset) == 0)
// 	{
// 		word_count++;
// 	}
// 	return (word_count);
// }

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}
