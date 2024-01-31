/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:17:10 by jkaller           #+#    #+#             */
/*   Updated: 2024/01/31 18:08:24 by jkaller          ###   ########.fr       */
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
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstlast(t_list	*lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);


//swap operations
int			*sa(int argc, int *stack_a);
int			*sb(int argc, int *stack_b);
int			*ss(int argc, int *stack_a, int *stack_b);
int			*pa(int *stack_a, int *stack_b);
int			*pb(int *stack_a, int *stack_b);

#endif