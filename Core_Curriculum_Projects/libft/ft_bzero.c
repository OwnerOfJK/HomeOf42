/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:41:24 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:41:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void ft_bzero(void *dst, size_t n)
{
    unsigned int i = 0;
    unsigned char *p = (unsigned char *)dst;

    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}