/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:34 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/23 16:50:46 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *substr)
{
	int	i;
	int	j;

	i = 0;
	if (*substr == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == substr[j] && str[i + j] != '\0')
		{
			j++;
			if (substr[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
