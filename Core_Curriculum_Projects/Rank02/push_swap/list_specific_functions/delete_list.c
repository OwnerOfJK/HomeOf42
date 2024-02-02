/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:59:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 17:07:58 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	delete_list(t_list *lst)
{
	t_list	*prev_node;
	t_list	*current_node;

	prev_node = NULL;
	current_node = lst;

	if (lst)
	{
		while (current_node && current_node->next)
		{
			prev_node = current_node;
			current_node = current_node->next;
		}
		free(lst);
	}
}
