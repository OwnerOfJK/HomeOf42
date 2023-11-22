/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:13 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 16:19:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *str1, const char *str2, int len)
{
	int	i;

	i = 0;
	while (i < len && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	if (i == len)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
}
