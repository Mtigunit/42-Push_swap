/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:32:43 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 17:01:08 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast_new(t_stack *lst)
{
	int	i;

	i = ft_lstsize_new(lst);
	while (i > 1)
	{
		i--;
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_new(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstadd_back_new(t_stack **lst, t_stack *new)
{
	t_stack	*list;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		list = ft_lstlast_new(*lst);
		list->next = new;
	}
}

t_stack	*ft_lstnew_new(long int data)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->data = data;
	list->next = NULL;
	return (list);
}
