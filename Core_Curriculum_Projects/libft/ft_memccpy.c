/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:16 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:42:17 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void* ft_memccpy(void* dst, const void* src, int c, size_t len)
{
    unsigned int i = 0;
    unsigned char *p_dst = (unsigned char *)dst;
    unsigned const char *p_src = (unsigned const char *)src;
    unsigned char ch = (unsigned char)ch;
    
    while (i < len)
    {
        p_dst[i] = p_src[i];
        if (p_src[i] == c)
        {
            return (&p_dst[i]);
        }
        i++;
    }
    return (0);
}