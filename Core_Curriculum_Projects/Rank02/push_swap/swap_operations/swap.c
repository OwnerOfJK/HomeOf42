/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:09 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 12:13:50 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	swap(t_list **head_stack)
{
	if (NULL == *head_stack || NULL == head_stack
		|| 1 == ft_lstsize(*head_stack))
		return ;
	*head_stack = (*head_stack)->next;
	(*head_stack)->previous->previous = *head_stack;
	(*head_stack)->previous->next = (*head_stack)->next;
	if ((*head_stack)->next)
		(*head_stack)->next->previous = (*head_stack)->previous;
	(*head_stack)->next = (*head_stack)->previous;
	(*head_stack)->previous = NULL;
}

void	sa(t_list **head_stack_a)
{
	if (head_stack_a)
	{
		swap(head_stack_a);
		ft_printf("sa\n");
	}
}

void	sb(t_list **head_stack_b)
{
	if (head_stack_b)
	{
		swap(head_stack_b);
		ft_printf("sb\n");
	}
}

void	ss(t_list **head_stack_a, t_list **head_stack_b)
{
	if (head_stack_a && head_stack_b)
	{
		sa(head_stack_a);
		sb(head_stack_b);
	}
}
