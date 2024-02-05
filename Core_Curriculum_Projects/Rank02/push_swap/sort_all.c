/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:09:43 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 13:13:23 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	sort_all(t_list **stack_a, t_list **stack_b)
{
	t_list		*smallest_node;
	int			stack_a_len;

	stack_a_len = ft_lstsize(*stack_a);
	if (stack_a_len == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (stack_a_len-- > 3)
			pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_node_values(*stack_a, *stack_b);
		move_cheapest_to_top(stack_a, stack_b);
	}
	set_index(*stack_a);
	smallest_node = return_smallest_node(*stack_a);
	if (smallest_node->above_median)
		while (*stack_a != smallest_node)
			ra(stack_a);
	else
		while (*stack_a != smallest_node)
			rra(stack_a);
	return (0);
}