/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:38:52 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 12:15:53 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstnew(int val, bool above_median, bool cheapest)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!(lst))
		return (NULL);
	lst->val = val;
	lst->index = 0;
	lst->push_price = 0;
	lst->above_median = above_median;
	lst->cheapest = cheapest;
	lst->next = NULL;
	lst->previous = NULL;
	lst->next_neighbor = NULL;
	return (lst);
}
