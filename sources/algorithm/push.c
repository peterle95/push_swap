/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:41:03 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Moves the top element from one stack to another.
int	push(t_push **stack_to, t_push **stack_from)
{
	t_push	*node_to_push;

	if (!*stack_from)
		return (-1);
	node_to_push = *stack_from;
	*stack_from = (*stack_from)->next;
	node_to_push->next = *stack_to;
	*stack_to = node_to_push;
	return (0);
}

// Pushes the top element from stack B to stack A.
int	pa(t_push **stack_a, t_push **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

// Pushes the top element from stack A to stack B.
int	pb(t_push **stack_a, t_push **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
