/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:17:10 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/28 16:55:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list {
	int					val;
	int					index;
	struct s_list		*previous;
	struct s_list		*next;
}	t_list;

int	*sa(int argc, int *stack_a);
int	*sb(int argc, int *stack_b);
int	*ss(int argc, int *stack_a, int *stack_b);
int	*pa(int *stack_a, int *stack_b);
int	*pb(int *stack_a, int *stack_b);

#endif