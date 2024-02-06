/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:24:37 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 12:19:19 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"
#include <limits.h>

t_list	*return_smallest_node(t_list *stack)
{
	long	smallest;
	t_list	*smallest_node;
	t_list	*current_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	current_node = stack;
	while (current_node)
	{
		if (current_node->val < smallest)
		{
			smallest_node = current_node;
			smallest = current_node->val;
		}
		current_node = current_node->next;
	}
	return (smallest_node);
}

t_list	*return_cheapest(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	confirm_order(t_list *head_stack)
{
	while (head_stack && head_stack->next)
	{
		if (head_stack->val > head_stack->next->val)
			return (0);
		head_stack = head_stack->next;
	}
	return (1);
}
