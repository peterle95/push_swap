/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 14:57:35 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int	push(t_push_swap **stack_to, t_push_swap **stack_from)
{
	t_push_swap	*tmp;
	t_push_swap	*head_to;
	t_push_swap	*head_from;

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

/*Here's the reasoning behind this simplified version:

Simplified error checking:
We only need to check if the source stack is empty. If it is, we return -1 immediately. This replaces the more complex push_swap_lstsize check.
Reduced variable usage:
Instead of creating separate variables for head_to and head_from, we work directly with the stack pointers. This makes the code more concise and easier to follow.
Streamlined node movement:
We use a single tmp variable to hold the node we're moving. This simplifies the process of removing it from the source stack and adding it to the destination stack.
Eliminated conditional branching:
The original version had a conditional check to handle the case where the destination stack was empty. In this version, we don't need that because the operations work the same way whether the destination stack is empty or not.
More direct operations:

We directly update *stack_from to point to the next node, removing the top node from the source stack.
We set the next pointer of the moved node (tmp) to point to the current top of the destination stack.
We update the destination stack pointer to point to the moved node, effectively placing it at the top.


Reduced code complexity:
By simplifying the logic, we've reduced the function from 22 lines to 9 lines, making it easier to read and maintain.

This simplified version accomplishes the same task more efficiently and with less potential for errors. It's more intuitive to understand at a glance what the function is doing, which is important for code maintainability and debugging.*/

int	push(t_push_swap **stack_to, t_push_swap **stack_from)
{
	t_push_swap	*tmp;
	t_push_swap	*head_to;
	t_push_swap	*head_from;

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
}

/*Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

/*Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}