/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/14 15:06:23 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
It moves the top element from stack_from to stack_to.
It handles the case where stack_to is empty.
It returns -1 if stack_from is empty, and 0 on successful push.*/

int	push(t_push **stack_to, t_push **stack_from)
{
	t_push	*node_to_push;

    // Check if the source stack is empty
	if (!*stack_from)
		return (-1);

    // Remove the top node from the source stack
	node_to_push = *stack_from;
	*stack_from = (*stack_from)->next;

    // Add the node to the destination stack
	node_to_push->next = *stack_to;
	*stack_to = node_to_push;

	return (0);
}

/*Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_push **stack_a, t_push **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

/*Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_push **stack_a, t_push **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
