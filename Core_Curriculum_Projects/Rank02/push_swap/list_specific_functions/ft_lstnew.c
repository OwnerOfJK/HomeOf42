/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:38:52 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/28 16:49:36 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *stack;

    if (!(stack = (t_list*)malloc(sizeof(*stack))))
		return (NULL);
	stack->val = content;
	stack->next = NULL;
	return (stack);
}