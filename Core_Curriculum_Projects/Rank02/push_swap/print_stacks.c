/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:20:18 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 14:41:32 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list *current_a = stack_a;
	
	while (current_a)
	{
		ft_printf("head_a: val %i | index %i | push_price %i | above_median %d | cheapest %d \n", current_a->val, current_a->index, current_a->push_price, current_a->above_median, current_a->cheapest);
		t_list *next_a = current_a->next;  // Declare next_a inside the loop
		//free(current_a);
		current_a = next_a;
	}
	ft_printf("______________________________\n\n");
	t_list *current_b = stack_b;
	while (current_b)
	{
		ft_printf("head_b: val %i | index %i | push_price %i | above_median %d | cheapest %d \n", current_b->val, current_b->index, current_b->push_price, current_b->above_median, current_b->cheapest);
		t_list *next_b = current_b->next;  // Declare next_b inside the loop
		//free(current_b);
		current_b = next_b;
	}
}

void	print_stack(t_list *stack)
{
	t_list *current_a = stack;

	ft_printf("current_node: val %i | index %i | push_price %i | above_median %d | cheapest %d \n", current_a->val, current_a->index, current_a->push_price, current_a->above_median, current_a->cheapest);
}