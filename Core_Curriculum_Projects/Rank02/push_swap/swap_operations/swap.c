/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:09 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 16:30:33 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

int	*swap(t_list **head_stack)
{
	int	tmp_val;

	if (head_stack && *head_stack && (*head_stack)->next)
	{
		tmp_val = (*head_stack)->val;
		(*head_stack)->val = (*head_stack)->next->val;
		(*head_stack)->next->val = tmp_val;
	}
	return (0);
}

int	*swap_both(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && head_stack_b)
	{
		swap(head_stack_a);
		swap(head_stack_b);
	}
	return (0);
}