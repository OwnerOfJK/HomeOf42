/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:50:38 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 13:30:01 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"
#include <limits.h>

void	set_index(t_list *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_price(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b && stack_b->next)
	{
		stack_b->push_price = stack_b->index;
		if (!(stack_b->above_median))
			stack_b->push_price = len_b - (stack_b->index);
		if (stack_b->next_neighbor->above_median)
			stack_b->push_price += stack_b->next_neighbor->index;
		else
			stack_b->push_price += len_a - (stack_b->next_neighbor->index);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_list *stack_b)
{
	long			best_match_value;
	t_list			*best_neigbor_node;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_price < best_match_value)
		{
			best_match_value = stack_b->push_price;
			best_neigbor_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_neigbor_node->cheapest = true;
}

void	set_next_neighbors(t_list *stack_a, t_list *current_node_b)
{
	int			value_dif;
	long		highscore;
	t_list		*current_node_a;

	highscore = LONG_MAX;
	while (current_node_b)
	{
		current_node_a = stack_a;
		while (current_node_a)
		{
			if (current_node_a->val > current_node_b->val)
			{
				value_dif = current_node_a->val - current_node_b->val;
				if (value_dif < highscore)
				{
					highscore = value_dif;
					current_node_b->next_neighbor = current_node_a;
				}
			}
			current_node_a = current_node_a->next;
		}
		if (highscore == LONG_MAX)
			current_node_b->next_neighbor = return_smallest_node(stack_a);
		current_node_b = current_node_b->next;
	}
}

void	set_node_values(t_list *stack_a, t_list *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_next_neighbors(stack_a, stack_b);
	set_price(stack_a, stack_b);
	//set_cheapest(stack_b);
}