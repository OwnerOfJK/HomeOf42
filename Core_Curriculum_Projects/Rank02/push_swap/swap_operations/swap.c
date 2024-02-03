/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:09 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/03 15:37:41 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

int	*sa(t_list **head_stack_a)
{
	int	tmp_val;

	if (head_stack_a && *head_stack_a && (*head_stack_a)->next)
	{
		tmp_val = (*head_stack_a)->val;
		(*head_stack_a)->val = (*head_stack_a)->next->val;
		(*head_stack_a)->next->val = tmp_val;
	}
	ft_printf("sa\n");
	return (0);
}

int	*sb(t_list **head_stack_b)
{
	int	tmp_val;

	if (head_stack_b && *head_stack_b && (*head_stack_b)->next)
	{
		tmp_val = (*head_stack_b)->val;
		(*head_stack_b)->val = (*head_stack_b)->next->val;
		(*head_stack_b)->next->val = tmp_val;
	}
	ft_printf("sb\n");
	return (0);
}

int	*ss(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && head_stack_b)
	{
		sa(head_stack_a);
		sb(head_stack_b);
	}
	return (0);
}