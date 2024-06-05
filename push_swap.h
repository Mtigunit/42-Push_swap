/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:28:16 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 19:42:20 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_stack {
	long int		data;
	int				index;
	struct s_stack	*next;
}					t_stack;

// instructions
void		sa_sb(t_stack **lst, char stack);
void		ss(t_stack **stack_a, t_stack **stack_b, int flag);
void		ra_rb(t_stack **head, char stack);
void		rra_rrb(t_stack **head, char stack);
void		pa_pb(t_stack **to_push, t_stack **stk, char stack);

// utils
void		rr(t_stack **stack_a, t_stack **stack_b, int flag);
void		rrr(t_stack **stack_a, t_stack **stack_b, int flag);
void		ft_free(char **str);
void		free_stack(t_stack **stack);
long int	ft_atoi_long(const char *str);

// check error
int			is_so_large(t_stack *stack);
int			is_sorted(t_stack *stack);
int			is_not_num(char *str);
int			ft_error(char *err);
int			is_duplicate(t_stack *stack);

// lst funcs
void		ft_lstadd_back_new(t_stack **lst, t_stack *new);
int			ft_lstsize_new(t_stack *lst);
t_stack		*ft_lstlast_new(t_stack *lst);
t_stack		*ft_lstnew_new(long int data);

// Radix sort
void		radix_sort(t_stack **stack_a, t_stack **stack_b);
int			full_stack_data(t_stack **stack, int ac, char **av);

// mini_sort 
int			mini_sort(t_stack **stack_a, t_stack **stack_b, int lst_size);

#endif
