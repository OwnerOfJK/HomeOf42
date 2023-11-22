/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:29 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:44:30 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(char *str, int c)
{
    int len = ft_strlen(str);
    while (len > 0)
    {
        if(str[len] == c)
        {
            return(&str[len]);
        }
        len--;
    }
    return (0);
}