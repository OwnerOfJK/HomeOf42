/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:38:52 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/04 15:33:57 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstnew(int val)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!(lst))
		return (NULL);
	lst->val = val;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}