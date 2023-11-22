/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:24 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:42:25 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_memcmp(const void *str1, const void *str2, size_t size)
{
    size_t i = 0;
    const unsigned char *p_str1 = (const unsigned char*)str1;
    const unsigned char *p_str2 = (const unsigned char*)str2;

    while (i < size && p_str1[i] == p_str2[i])
    {
        i++;
    }
    return (p_str1[i] - p_str2[i]);
}