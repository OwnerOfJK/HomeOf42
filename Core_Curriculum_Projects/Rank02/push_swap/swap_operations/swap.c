/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:09 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/27 20:49:28 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	*swap(t_list *head_stack)
{
	int			tmp_val;
	int			tmp_index;
	
	if (head_stack && head_stack->next)
	{
		//store tmp values
		tmp_val = head_stack->val;
		tmp_index = head_stack->index;

		//swap values
		head_stack->val = head_stack->next->val;
		head_stack->index = head_stack->next->index;

		//swap next list pointer
		head_stack->next = head_stack->next->next;
		head_stack->next->next = head_stack;
	}
	return (0);
}

int	*swap_both(t_list *head_stack_a, t_list *head_stack_b)
{
	if (head_stack_a && head_stack_b)
	{
		swap(head_stack_a);
		swap(head_stack_b);
	}
	return (0);
}