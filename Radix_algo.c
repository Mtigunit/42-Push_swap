/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:32:44 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 21:34:23 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	full_stack_data(t_stack **stack, int ac, char **av)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	if (ac == 2 && av[1][0])
		split = ft_split(av[1], ' ');
	else
	{
		i = 1;
		split = av;
	}
	j = i;
	while (split[j])
		if (is_not_num(split[j++]))
			ft_error("Error");
	while (split[i])
	{
		if (!split[i][0])
			ft_error("Error");
		ft_lstadd_back_new(stack, ft_lstnew_new(ft_atoi_long(split[i++])));
	}
	if (ac == 2)
		ft_free(split);
	return (0);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize_new(head_a);
	while (!is_sorted(*stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra_rb(stack_a, 'a');
			else
				pa_pb(stack_a, stack_b, 'b');
		}
		while (ft_lstsize_new(*stack_b) != 0)
			pa_pb(stack_b, stack_a, 'a');
		i++;
	}
}
