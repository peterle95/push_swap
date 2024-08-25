/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:41:21 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Calculates the number of bits needed to 
// represent the largest index in the stack
int	get_max_bits(t_push *stack)
{
	int		max;
	int		max_bits;

	max = 0;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while (max)
	{
		max = max >> 1;
		max_bits++;
	}
	return (max_bits);
}

// Implements the radix sort algorithm to sort the stack
void	radix(t_push **stack_a, t_push **stack_b)
{
	int		size;
	int		max_bits;
	int		bit;
	int		j;

	bit = 0;
	size = push_swap_lstsize(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (bit < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> bit) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}
