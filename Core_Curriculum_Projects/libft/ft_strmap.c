/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:02 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:44:03 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char    *ft_strmap(char const *s, char (*f)(char))
{
    int i = 0;
    int s_len = ft_strlen_const(s);
    char *new_string = (char *)malloc((s_len + 1) * sizeof(char));
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