/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:17:10 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/06 15:43:48 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_list {
	int					val;
	int					index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_list		*next;
	struct s_list		*previous;
	struct s_list		*next_neighbor;
}	t_list;

//data parsing
int			parse_to_linkedlist(int *argc, char **argv, t_list **head_stack_a);

//list_specific_functions
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list	*lst);
t_list		*ft_lstnew(int val, bool above_median, bool cheapest);
int			ft_lstsize(t_list *lst);
void		ft_lstfree(t_list *lst);

//swap operations
void		sa(t_list **head_stack_a);
void		sb(t_list **head_stack_b);
void		ss(t_list **head_stack_a, t_list **head_stack_b);
void		pa(t_list **head_stack_a, t_list **head_stack_b);
void		pb(t_list **head_stack_a, t_list **head_stack_b);
void		ra(t_list **head_stack_a, bool flag);
void		rb(t_list **head_stack_b, bool flag);
void		rr(t_list **head_stack_a, t_list **head_stack_b, bool flag);
void		rra(t_list **head_stack_a, bool flag);
void		rrb(t_list **head_stack_b, bool flag);
void		rrr(t_list **head_stack_a, t_list **head_stack_b, bool flag);

//sort two
void		sort_two(t_list **stack_a);

//sort three
int			sort_three(t_list **head_stack);
int			sort_132(t_list **head_stack);
int			sort_213(t_list **head_stack);
int			sort_231(t_list **head_stack);
int			sort_312(t_list **head_stack);
int			sort_321(t_list **head_stack);

//sort all
void		sort_all(t_list **head_stack_a, t_list **head_stack_b);
void		set_node_values(t_list *stack_a, t_list *stack_b);
void		move_cheapest_to_top(t_list **stack_a, t_list **stack_b);
void		set_index(t_list *stack);

//valid checks
int			confirm_order(t_list *head_stack);
void		print_stacks(t_list *stack_a, t_list *stack_b);
void		print_stack(t_list *stack);
void		print_node(t_list *stack);
t_list		*return_cheapest(t_list *stack);
t_list		*return_smallest_node(t_list *stack);

#endif