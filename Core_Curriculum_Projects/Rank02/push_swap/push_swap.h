/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:17:10 by jkaller           #+#    #+#             */
/*   Updated: 2024/02/02 14:58:06 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list {
	int					val;
	int					index;
	struct s_list		*next;
}	t_list;

//list_specific_functions
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(int, int));
void		ft_lstdelone(t_list *lst, void (*del)(int, int));
void		ft_lstiter(t_list *lst, int (*f)(int, int));
t_list		*ft_lstlast(t_list	*lst);
t_list		*ft_lstmap(t_list *lst, int (*f)(int, int), void (*del)(int, int));
t_list		*ft_lstnew(int val, int index);
int			ft_lstsize(t_list *lst);
void 		increment_index(t_list *head_stack);
void		decrement_index(t_list *head_stack);
void		delete_list(t_list *lst);

//swap operations
int			*swap(t_list **head_stack);
int			*swap_both(t_list **head_stack_a, t_list **head_stack_b);
int			*pa(t_list **head_stack_a, t_list **head_stack_b);
int			*pb(t_list **head_stack_a, t_list **head_stack_b);
void		rotate_up(t_list **head_stack);
void		rotate_up_both(t_list **head_stack_a, t_list **head_stack_b);
void		rotate_down(t_list **head_stack);
void		rotate_down_both(t_list **head_stack_a, t_list **head_stack_b);

#endif