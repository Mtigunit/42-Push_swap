/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:32:30 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 19:21:46 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **lst, char stack)
{
	int	tmp;

	if (!lst || !*lst)
		return ;
	tmp = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = tmp;
	tmp = (*lst)->index;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->index = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write (1, "sb\n", 3);
}
// =============================================================

void	ra_rb(t_stack **list, char stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!list || !*list || ft_lstsize_new(*list) < 2)
		return ;
	head = *list;
	*list = head->next;
	last = ft_lstlast_new(*list);
	last->next = head;
	head->next = NULL;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write (1, "rb\n", 3);
}
// =============================================================

void	rra_rrb(t_stack **list, char stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!list || !*list || ft_lstsize_new(*list) < 2)
		return ;
	head = *list;
	while ((*list)->next->next)
		*list = (*list)->next;
	last = (*list)->next;
	(*list)->next = NULL;
	last->next = head;
	*list = last;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write (1, "rrb\n", 4);
}
// =============================================================

void	pa_pb(t_stack **from, t_stack **to, char stack)
{
	t_stack	*tmp;

	if (!from || !*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (!*to)
	{
		*to = tmp;
		(*to)->next = NULL;
	}
	else
	{
		tmp->next = *to;
		*to = tmp;
	}
	if (stack == 'a')
		write(1, "pa\n", 3);
	else if (stack == 'b')
		write(1, "pb\n", 3);
}
// =============================================================

void	ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	sa_sb(stack_a, 0);
	sa_sb(stack_b, 0);
	if (flag)
		write (1, "ss\n", 3);
}
// =============================================================
