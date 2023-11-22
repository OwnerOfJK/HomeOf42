/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:20 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:42:21 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memchr(void *src, int c, size_t size)
{
    unsigned int i = 0;
    unsigned char *p = (unsigned char*)src;

    while (i < size)
    {
        if (p[i] == c)
        {
            return (&p[i]);
        }
        i++;
    }
    return (0);
}