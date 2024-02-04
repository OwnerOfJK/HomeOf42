/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:05 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/04 15:39:47 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

int	*pa(t_list **head_stack_a, t_list **head_stack_b)
{
	t_list	*tmp;

	if (head_stack_b && *head_stack_b)
	{
		tmp = *head_stack_b;
		ft_lstadd_front(head_stack_a, ft_lstnew(tmp->val));
		*head_stack_b = (*head_stack_b)->next;
		free(tmp);
	}
	ft_printf("pa\n");
	return (0);
}

int	*pb(t_list **head_stack_a, t_list **head_stack_b)
{
	t_list	*tmp;

	if (head_stack_a && *head_stack_a)
	{
		tmp = *head_stack_a;
		ft_lstadd_front(head_stack_b, ft_lstnew(tmp->val));
		*head_stack_a = (*head_stack_a)->next;
		free(tmp);
	}
	ft_printf("pb\n");
	return (0);
}
