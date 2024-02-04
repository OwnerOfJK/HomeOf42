/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:42:15 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/04 15:40:46 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	ft_lstiter(t_list *lst, int (*f)(int))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)((lst->val));
		lst = lst->next;
	}
}
