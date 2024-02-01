/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:15:05 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/27 21:00:07 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	*pa(int *stack_a, int *stack_b)
{
	int	tmp;

	if (stack_b)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_b[0];
		stack_b[0] = tmp;
	}
	return (0);
}

int	*pb(int *stack_a, int *stack_b)
{
	int	tmp;

	if (stack_a)
	{
		tmp = stack_b[0];
		stack_a[0] = stack_b[0];
		stack_b[0] = tmp;
	}
	return (0);
}