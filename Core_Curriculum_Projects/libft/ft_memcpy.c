/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:28 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:42:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void* ft_memcpy(void* dst, const void* src, size_t len)
{
    unsigned int i = 0;
    unsigned char *p_dst = (unsigned char *)dst;
    unsigned const char *p_src = (unsigned const char *)src;
    
    while (i < len)
    {
        p_dst[i] = p_src[i];
        i++;
    }
    return (dst);
}