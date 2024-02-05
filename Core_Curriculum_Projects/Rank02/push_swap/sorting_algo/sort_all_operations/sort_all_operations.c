/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:55:12 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 21:07:05 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft/libft.h"
#include "../../push_swap.h"

void	rotate_both(t_list **stack_a,
						t_list **stack_b,
						t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->next_neighbor
		&& *stack_b != cheapest_node)
		rr(stack_a, stack_b, true);
	set_index(*stack_a);
	set_index(*stack_b);
}

void	reverse_rotate_both(t_list **stack_a,
								t_list **stack_b,
								t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->next_neighbor
		&& *stack_b != cheapest_node)
		rrr(stack_a, stack_b, true);
	set_index(*stack_a);
	set_index(*stack_b);
}

void	finish_rotation(t_list **stack,
							t_list *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_cheapest_to_top(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(*stack_b);
	if (cheapest_node->above_median
		&& cheapest_node->next_neighbor->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->next_neighbor->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, cheapest_node->next_neighbor, 'a');
	pa(stack_a, stack_b);
}
