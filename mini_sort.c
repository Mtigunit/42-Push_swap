/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:50:34 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 21:33:45 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack *stack, int index)
{
	int		position;

	position = 1;
	while (stack->index != index)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

static void	sort_three(t_stack **stack, int index)
{
	if ((*stack)->index == index + 1 && (*stack)->next->index == index)
		sa_sb(stack, 'a');
	else if ((*stack)->index == index + 1 && (*stack)->next->index == index + 2)
		rra_rrb(stack, 'a');
	else if ((*stack)->index == index + 2 && (*stack)->next->index == index)
		ra_rb(stack, 'a');
	else if ((*stack)->index == index && (*stack)->next->index == index + 2)
	{
		sa_sb(stack, 'a');
		ra_rb(stack, 'a');
	}
	else if ((*stack)->index == index + 2 && (*stack)->next->index == index + 1)
	{
		sa_sb(stack, 'a');
		rra_rrb(stack, 'a');
	}
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b, int index)
{
	t_stack	*head;
	int		position;

	if (is_sorted(*stack_a))
		return ;
	head = *stack_a;
	position = get_position(*stack_a, index);
	if (position == 2)
		sa_sb(stack_a, 'a');
	else if (position == 3)
	{
		ra_rb(stack_a, 'a');
		ra_rb(stack_a, 'a');
	}
	else if (position == 4)
		rra_rrb(stack_a, 'a');
	if (is_sorted(*stack_a))
		return ;
	pa_pb(stack_a, stack_b, 'b');
	sort_three(stack_a, index + 1);
	pa_pb(stack_b, stack_a, 'a');
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b, int index)
{
	t_stack	*head;
	int		position;

	head = *stack_a;
	position = get_position(*stack_a, index);
	if (position == 2)
		ra_rb(stack_a, 'a');
	else if (position == 3)
	{
		ra_rb(stack_a, 'a');
		ra_rb(stack_a, 'a');
	}
	else if (position == 4)
	{
		rra_rrb(stack_a, 'a');
		rra_rrb(stack_a, 'a');
	}
	else if (position == 5)
		rra_rrb(stack_a, 'a');
	pa_pb(stack_a, stack_b, 'b');
	sort_four(stack_a, stack_b, index + 1);
	pa_pb(stack_b, stack_a, 'a');
}

int	mini_sort(t_stack **stack_a, t_stack **stack_b, int lst_size)
{
	if (lst_size == 1)
		return (0);
	else if (lst_size == 2 && (*stack_a)->data > (*stack_a)->next->data)
		sa_sb(stack_a, 'a');
	else if (lst_size == 3)
		sort_three(stack_a, 0);
	else if (lst_size == 4)
		sort_four(stack_a, stack_b, 0);
	else if (lst_size == 5)
		sort_five(stack_a, stack_b, 0);
	return (0);
}
