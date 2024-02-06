/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:43:08 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 11:30:44 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a);
}
