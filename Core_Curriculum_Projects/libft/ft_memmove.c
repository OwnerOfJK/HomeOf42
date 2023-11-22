/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:34 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:42:35 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned int i = 0;
    unsigned char *p_dst = (unsigned char *)dst;
    const unsigned char *p_src = (const unsigned char *)src;

    if (p_dst < p_src)
    {
        while (i < len)
        {
            p_dst[i] = p_src[i];
            i++;
        }
    }
    else if (p_dst > p_src)
    {
        while (len > 0)
        {
            p_dst[len - 1] = p_src[len - 1];
            len--;
        }
    }
    return (dst);
}