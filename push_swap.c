/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:50:30 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/17 21:34:28 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *head, int value)
{
	int	index;

	index = 0;
	while (head)
	{
		if (value > head->data)
			index++;
		head = head->next;
	}
	return (index);
}

static void	full_stack_index(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (*stack)
	{
		(*stack)->index = get_index(head, (*stack)->data);
		*stack = (*stack)->next;
	}
	*stack = head;
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		lst_size;

	if (ac < 2)
		return (0);
	full_stack_data(&stack_a, ac, av);
	if (is_so_large(stack_a) || is_duplicate(stack_a))
		return (free_stack(&stack_a), ft_error("Error"));
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	lst_size = ft_lstsize_new(stack_a);
	full_stack_index(&stack_a);
	if (lst_size <= 5)
		mini_sort(&stack_a, &stack_b, lst_size);
	if (lst_size > 5)
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
}
