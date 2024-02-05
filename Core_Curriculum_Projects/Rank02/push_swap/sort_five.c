/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:43:08 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 11:56:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

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

int	sort_five(t_list **head_stack_a, t_list **head_stack_b)
{
	int	count;

	count = 0;
	pb(head_stack_a, head_stack_b);
	pb(head_stack_a, head_stack_b);
	count += sort_three(head_stack_a);
	//set_next_neighbors(*head_stack_a, *head_stack_b);
	count += sort_stack_b(head_stack_b);
	pa(head_stack_a, head_stack_b);
	ra(head_stack_a);
	pa(head_stack_a, head_stack_b);
	ra(head_stack_a);
	return (count + 6);
}
