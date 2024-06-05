/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:35:01 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/16 22:30:47 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_moves(char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if ((ft_strlen(moves[i]) == 3
				&& (!ft_memcmp(moves[i], "sa\n", 3)
					|| !ft_memcmp(moves[i], "sb\n", 3)
					|| !ft_memcmp(moves[i], "ra\n", 3)
					|| !ft_memcmp(moves[i], "rb\n", 3)
					|| !ft_memcmp(moves[i], "pa\n", 3)
					|| !ft_memcmp(moves[i], "pb\n", 3)
					|| !ft_memcmp(moves[i], "rr\n", 3)
					|| !ft_memcmp(moves[i], "ss\n", 3)))
			|| (ft_strlen(moves[i]) == 4
				&& (!ft_memcmp(moves[i], "rra\n", 4)
					|| !ft_memcmp(moves[i], "rrb\n", 4)
					|| !ft_memcmp(moves[i], "rrr\n", 4))))
			i++;
		else
			return (1);
	}
	return (0);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, char **moves, int i)
{
	while (moves[++i])
	{
		if (!ft_memcmp(moves[i], "sa\n", 3))
			sa_sb(stack_a, 0);
		else if (!ft_memcmp(moves[i], "sb\n", 3))
			sa_sb(stack_b, 0);
		else if (!ft_memcmp(moves[i], "ss\n", 3))
			ss(stack_a, stack_b, 0);
		else if (!ft_memcmp(moves[i], "ra\n", 3))
			ra_rb(stack_a, 0);
		else if (!ft_memcmp(moves[i], "rb\n", 3))
			ra_rb(stack_b, 0);
		else if (!ft_memcmp(moves[i], "rr\n", 3))
			rr(stack_a, stack_b, 0);
		else if (!ft_memcmp(moves[i], "pa\n", 3))
			pa_pb(stack_b, stack_a, 0);
		else if (!ft_memcmp(moves[i], "pb\n", 3))
			pa_pb(stack_a, stack_b, 0);
		else if (!ft_memcmp(moves[i], "rra\n", 4))
			rra_rrb(stack_a, 0);
		else if (!ft_memcmp(moves[i], "rrb\n", 4))
			rra_rrb(stack_b, 0);
		else if (!ft_memcmp(moves[i], "rrr\n", 4))
			rrr(stack_a, stack_b, 0);
	}
}

void	sort_and_check_stack(t_stack **stack_a, t_stack **stack_b, char **moves)
{
	int	i;

	i = -1;
	sort_stack(stack_a, stack_b, moves, i);
	if (is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*moves[1000000];
	int		i;

	if (ac <= 1)
		return (0);
	full_stack_data(&stack_a, ac, av);
	if (is_so_large(stack_a) || is_duplicate(stack_a))
		return (free_stack(&stack_a), ft_error("Error"));
	i = 0;
	moves[i] = get_next_line(0);
	while (moves[i++])
		moves[i] = get_next_line(0);
	if (check_moves(moves))
		return (free_stack(&stack_a), ft_free(moves), ft_error("Error"));
	sort_and_check_stack(&stack_a, &stack_b, moves);
	free_stack(&stack_a);
	ft_free(moves);
	return (0);
}
