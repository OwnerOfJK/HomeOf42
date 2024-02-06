/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:20:18 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 12:54:19 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	while (current_a)
	{
		ft_printf("head_a: val %i | index %i | push_price %i | "
			"above_median %d | cheapest %d \n", current_a->val,
			current_a->index, current_a->push_price,
			current_a->above_median, current_a->cheapest);
		current_a = current_a->next;
	}
	current_b = stack_b;
	while (current_b)
	{
		ft_printf("head_b: val %i | index %i | push_price %i | "
			"above_median %d | cheapest %d \n", current_b->val,
			current_b->index, current_b->push_price, 
			current_b->above_median, current_b->cheapest);
		current_b = current_b->next;
	}
}

void	print_node(t_list *stack)
{
	t_list	*current;

	current = stack;
	ft_printf("current_node: val %i | index %i | push_price %i | "
		"above_median %d | cheapest %d \n", current->val,
		current->index, current->push_price, 
		current->above_median, current->cheapest);
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		ft_printf("head_a: val %i | index %i | push_price %i | "
			"above_median %d | cheapest %d \n", current->val, 
			current->index, current->push_price, 
			current->above_median, current->cheapest);
		current = current->next;
	}
	ft_printf("______________________________\n\n");
}
