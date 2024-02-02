/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:27:22 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 15:02:03 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(int, int))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)((lst->val), (lst->index));
		free(lst);
	}
}
