/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:26 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:44:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strnstr(char *str, char *substr, int len)
{
    int i = 0;
    int j;

    if (*substr == '\0')
    {
        return (str);
    }
    while (str[i] != '\0' && i < len)
    {
        j = 0;
        while (str[i + j] == substr[j] && str[i + j] != '\0' && i + j < len)
        {
            j++;
            if (substr[j] == '\0')
            {
                return(&str[i]);
            }
        }
        i++;
    }
    return (0);
}