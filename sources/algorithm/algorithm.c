/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:39:23 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Sorts a stack of 3 elements using optimal moves
void	algorithm_3(t_push **stack)
{
	int		a;
	int		b;
	int		c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

// Sorts a stack of 4 elements by moving the smallest to stack B, sorting the remaining 3, then moving the smallest back
void	algorithm_4(t_push **stack_a, t_push **stack_b)
{
	int		min_pos;

	min_pos = find_min_position(*stack_a);
	if (min_pos == 1)
		ra(stack_a);
	else if (min_pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	algorithm_3(stack_a);
	pa(stack_a, stack_b);
}

// Sorts a stack of 5 elements by moving the smallest to stack B, sorting the remaining 4, then moving the smallest back
void	algorithm_5(t_push **stack_a, t_push **stack_b)
{
	int		min_pos;

	min_pos = find_min_position(*stack_a);
	if (min_pos == 1)
		ra(stack_a);
	else if (min_pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (min_pos == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	algorithm_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

// Chooses and runs the appropriate sorting algorithm based on the number of elements in the stack
void	run_algorithm(t_push **stack_a, t_push **stack_b)
{
	if (push_swap_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (push_swap_lstsize(*stack_a) == 3)
		algorithm_3(stack_a);
	else if (push_swap_lstsize(*stack_a) == 4)
		algorithm_4(stack_a, stack_b);
	else if (push_swap_lstsize(*stack_a) == 5)
		algorithm_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
