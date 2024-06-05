/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:18:45 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 18:06:37 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_so_large(t_stack *stack)
{
	while (stack)
	{
		if (stack->data > 2147483647 || stack->data < -2147483648)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	is_not_num(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	is_duplicate(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;
	int		flag;

	head = stack;
	tmp = stack;
	while (stack)
	{
		flag = 0;
		while (tmp)
		{
			if (tmp->data == stack->data)
				flag++;
			tmp = tmp->next;
		}
		if (flag > 1)
			return (1);
		tmp = head;
		stack = stack->next;
	}
	return (0);
}

int	ft_error(char *err)
{
	ft_putendl_fd(err, 2);
	exit(-1);
}
