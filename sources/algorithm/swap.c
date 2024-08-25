/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:19:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:42:03 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Swaps the first two elements of a stack
int	swap(t_push **stack)
{
	int		temp_value;
	int		temp_index;
	t_push	*first;
	t_push	*second;

	if (!*stack || !(*stack)->next)
		return (-1);
	first = *stack;
	second = first->next;
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = temp_value;
	second->index = temp_index;
	return (0);
}

// Performs swap operation on stack A and prints "sa"
int	sa(t_push **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

// Performs swap operation on stack B and prints "sb"
int	sb(t_push **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

// Performs swap operation on both stacks A and B and prints "ss"
int	ss(t_push **stack_a, t_push **stack_b)
{
	if ((push_swap_lstsize(*stack_a) < 2)
		|| (push_swap_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
