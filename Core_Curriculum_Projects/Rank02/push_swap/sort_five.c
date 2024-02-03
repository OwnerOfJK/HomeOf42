/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:43:08 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/03 19:54:27 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

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

int	sort_five(t_list **head_stack_a, t_list **head_stack_b)
{
	int	count;

	count = 0;
	pb(head_stack_a, head_stack_b);
	pb(head_stack_a, head_stack_b);
	count += sort_three(head_stack_a);
	count += sort_stack_b(head_stack_b);
	pa(head_stack_a, head_stack_b);
	ra(head_stack_a);
	pa(head_stack_a, head_stack_b);
	ra(head_stack_a);
	return (count + 6);
}
