/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:17:10 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/04 15:41:44 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list {
	int					val;
	struct s_list		*next;
	struct s_list		*previous;
}	t_list;

//list_specific_functions
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(t_list *));
void		ft_lstdelone(t_list *lst, void (*del)(t_list *));
void		ft_lstiter(t_list *lst, int (*f)(int));
t_list		*ft_lstlast(t_list	*lst);
t_list		*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
t_list		*ft_lstnew(int val);
int			ft_lstsize(t_list *lst);
void		increment_index(t_list *head_stack);
void		decrement_index(t_list *head_stack);
void		delete_list(t_list *lst);
void		ft_lstfree(t_list *lst);

//swap operations
int			*sa(t_list **head_stack_a);
int			*sb(t_list **head_stack_b);
int			*ss(t_list **head_stack_a, t_list **head_stack_b);
int			*pa(t_list **head_stack_a, t_list **head_stack_b);
int			*pb(t_list **head_stack_a, t_list **head_stack_b);
void		ra(t_list **head_stack_a);
void		rb(t_list **head_stack_b);
void		rr(t_list **head_stack_a, t_list **head_stack_b);
void		rra(t_list **head_stack_a);
void		rrb(t_list **head_stack_b);
void		rrr(t_list **head_stack_a, t_list **head_stack_b);

//sort three
int			sort_three(t_list **head_stack);
int			sort_132(t_list **head_stack);
int			sort_213(t_list **head_stack);
int			sort_231(t_list **head_stack);
int			sort_312(t_list **head_stack);
int			sort_321(t_list **head_stack);

//sort five
int			sort_five(t_list **head_stack_a, t_list **head_stack_b);

//sort hundred
int			sort_hundred(t_list **head_stack_a, t_list **head_stack_b);

//sort fivehundred
int			sort_fivehundred(t_list **head_stack_a, t_list **head_stack_b);

//valid checks
int			confirm_order(t_list *head_stack);

#endif