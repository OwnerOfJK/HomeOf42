/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen_delim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:52 by jkaller           #+#    #+#             */
/*   Updated: 2023/11/22 13:44:53 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_wordlen_delim(char *str, char delim)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != delim)
    {
        i++;
    }
    return (i);
}