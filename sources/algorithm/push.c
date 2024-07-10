/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/10 13:20:32 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int	push(t_push **stack_to, t_push **stack_from)
{
	t_push	*tmp;
	t_push	*head_to;
	t_push	*head_from;

	if (push_swap_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
} */

/*
Key improvements in this version:

Simplified Logic: The function now has a more straightforward flow, making it easier to understand at a glance.
Reduced Variable Usage: We've eliminated unnecessary variables, using only node_to_push to represent the node being moved.
Early Return: We check if the source stack is empty at the beginning and return immediately if it is, avoiding unnecessary operations.
Direct Manipulation: Instead of using temporary variables for head nodes, we directly manipulate the stack pointers, which is more efficient.
Consistent Naming: We use node_to_push to clearly indicate what we're working with throughout the function.
Removed Redundant Checks: The original version had some redundant checks and conditions, which have been removed to streamline the function.

This version maintains the same functionality as the original:

It moves the top element from stack_from to stack_to.
It handles the case where stack_to is empty.
It returns -1 if stack_from is empty, and 0 on successful push.*/

int push(t_push **stack_to, t_push **stack_from)
{
    t_push *node_to_push;

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
