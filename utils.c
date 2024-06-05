/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:17:01 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 17:01:19 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_long(const char *str)
{
	long int	res;
	long int	tmp;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		tmp = res;
		res = res * 10 + (*str - 48);
		if ((tmp != res / 10) && sign == -1)
			return (0);
		if ((tmp != res / 10) && sign == 1)
			return (-1);
		str++;
	}
	return (res * sign);
}

void	free_stack(t_stack **stack)
{
	int		stack_size;
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	stack_size = ft_lstsize_new(*stack);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	ft_free(char **str)
{
	char	*tmp;

	while (*str)
	{
		tmp = *str;
		str++;
		free(tmp);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ra_rb(stack_a, 0);
	ra_rb(stack_b, 0);
	if (flag)
		write(1, "rr\n", 3);
}
// =============================================================

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rra_rrb(stack_a, 0);
	rra_rrb(stack_b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
// =============================================================