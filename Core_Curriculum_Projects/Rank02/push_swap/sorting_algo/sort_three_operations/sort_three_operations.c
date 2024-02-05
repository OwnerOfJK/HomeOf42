/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:01:36 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/05 21:14:10 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft/libft.h"
#include "../../push_swap.h"

int	sort_132(t_list **head_stack)
{
	if (head_stack)
	{
		sa(head_stack);
		ra(head_stack, false);
	}
	return (2);
}

int	sort_231(t_list **head_stack)
{
	if (head_stack)
	{
		rra(head_stack, false);
	}
	return (1);
}

int	sort_213(t_list **head_stack)
{
	if (head_stack)
	{
		sa(head_stack);
	}
	return (1);
}

int	sort_312(t_list **head_stack)
{
	if (head_stack)
	{
		ra(head_stack, false);
	}
	return (1);
}

int	sort_321(t_list **head_stack)
{
	if (head_stack)
	{
		sa(head_stack);
		rra(head_stack, false);
	}
	return (2);
}
