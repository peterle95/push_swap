/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 23:33:20 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algorithm_3(t_push **stack)
{
	/* printf("Starting algorithm_3\n");
	print_stack(stack); */
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

void	algorithm_4(t_push **stack_a, t_push **stack_b)
{
   	/* printf("Starting algorithm_4\n");
    print_stacks(stack_a, stack_b); */
	int		min_pos;

	min_pos = find_min_position(*stack_a);
    // Move the smallest number to the top
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
    /* printf("Ending algorithm_4\n");
    print_stacks(stack_a, stack_b); */
}

void	algorithm_5(t_push **stack_a, t_push **stack_b)
{
	int		min_pos;
	min_pos = find_min_position(*stack_a);
    // Move the smallest number to the top
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

void	run_algorithm(t_push **stack_a, t_push **stack_b)
{
    // printf("Starting algorithm\n");
    // print_stacks(stack_a, stack_b);
    
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
   // printf("Ending algorithm\n");
}
