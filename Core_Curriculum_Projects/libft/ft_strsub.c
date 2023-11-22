/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:37 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:44:38 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    size_t i = 0;
    char *substr = (char *)malloc((len + 1) * sizeof(char));
    if (substr == NULL)
    {
        return (0);
    }
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}