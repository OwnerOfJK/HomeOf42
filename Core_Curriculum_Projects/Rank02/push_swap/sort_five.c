/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:43:08 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/04 16:43:49 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

// int	sort_top_stack_a(t_list **head_stack_a, t_list **head_stack_b)
// {
// 	int	count;

// 	count = 0;
// 	if ((*head_stack_a)->val > (*head_stack_a)->next->val)
// 	{
// 		pb(head_stack_a, head_stack_b);
// 		count += sort_stack_b(head_stack_b);
// 		return (count + 1);
// 	}
// 	else
// 	{
// 		sa(head_stack_a);
// 		pb(head_stack_a, head_stack_b);
// 		count += sort_stack_b(head_stack_b);
// 		return (count + 2);
// 	}
// 	return (count);
// }

int	sort_stack_b(t_list **head_stack_b)
{
	if ((*head_stack_b)->val > (*head_stack_b)->next->val)
	{
		sb(head_stack_b);
		return (1);
	}
	return (0);
}

int	move_biggest_to_last(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && head_stack_b)
	{
		pa(head_stack_a, head_stack_b);
		ra(head_stack_a);
		return (2);
	}
	return (0);
}

void	set_next_neighbors(t_list *current_node_a, t_list *current_node_b)
{
	int			value_dif;
	long		highscore;

	highscore = LONG_MAX;
	while (current_node_b && current_node_b)
	{
		while (current_node_a && current_node_a)
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
		//if (highscore == LONG_MAX) this means there is no smaller node in stack_a, but possible in stack_b so need a checker
		current_node_b = current_node_b->next;
	}
}

int	sort_five(t_list **head_stack_a, t_list **head_stack_b)
{
	int	count;

	count = 0;
	pb(head_stack_a, head_stack_b);
	pb(head_stack_a, head_stack_b);
	count += sort_three(head_stack_a);
	set_next_neighbors(*head_stack_a, *head_stack_b);




	
	count += sort_stack_b(head_stack_b);
	pa(head_stack_a, head_stack_b);
	ra(head_stack_a);
	pa(head_stack_a, head_stack_b);
	ra(head_stack_a);
	return (count + 6);
}
