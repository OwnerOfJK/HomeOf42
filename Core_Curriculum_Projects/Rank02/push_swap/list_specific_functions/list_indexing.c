/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:58:30 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 14:58:41 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	increment_index(t_list *head_stack)
{
	while (head_stack)
	{
		head_stack->index++;
		head_stack = head_stack->next;
	}
}

void	decrement_index(t_list *head_stack)
{
	while (head_stack)
	{
		head_stack->index--;
		head_stack = head_stack->next;
	}
}