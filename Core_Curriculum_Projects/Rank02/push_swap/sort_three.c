/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:53:06 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/03 17:28:41 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	sort_three(t_list **head_stack)
{
	int	first;
	int	mid;
	int	last;
	int	required_operations;

	first = (*head_stack)->val;
	mid = (*head_stack)->next->val;
	last = (*head_stack)->next->next->val;
	required_operations = 0;
	if (first < mid && mid > last && last > first)
		required_operations += sort_132(head_stack);
	if (first < mid && mid > last && last < first)
		required_operations += sort_231(head_stack);
	if (first > mid && mid < last && last > first)
		required_operations += sort_213(head_stack);
	if (first > mid && mid > last && last < first)
		required_operations += sort_321(head_stack);
	if (first > mid && mid < last && last < first)
		required_operations += sort_312(head_stack);
	if (confirm_order(*head_stack) == 1)
		return (required_operations);
	return (0);
}
