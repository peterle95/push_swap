/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 23:11:12 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


// CHANGE
/* Shifts down all elements of a stack by 1. 
 * The last element becomes the first one | rra and rrb
 */

/* int	reverse_rotate(t_push_swap **stack)
{
	t_push_swap	*head;
	t_push_swap	*tail;

	if (push_swap_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = push_swap_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
} */

/*Reasoning for the changes:

Simplified condition check:
Instead of using push_swap_lstsize, we directly check if the stack is empty or has only one element. This is more efficient and easier to read.
Removed unnecessary variables:
We don't need separate head and tail variables. We can use current to traverse the list and find the last element.
Simplified loop:
Instead of checking for head->next->next == NULL, we simply traverse until we reach the last element (current->next == NULL). This is more straightforward and less error-prone.
Streamlined rotation logic:
We keep track of the second-to-last element (prev) while traversing. This allows us to easily set the new last element's next to NULL without needing an additional loop.
Clearer operations:
The operations to perform the rotation are more clearly laid out:

Make the last element point to the start of the list
Make the last element the new start of the list
Set the new last element's next to NULL



This revised version accomplishes the same task more efficiently and with clearer logic. 
It's easier to understand at a glance what the function is doing, and it reduces the risk 
of errors that could come from more complex conditional checks or multiple traversals of the list.*/

int reverse_rotate(t_push_swap **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return (-1);

    t_push_swap *current = *stack;
    t_push_swap *prev = NULL;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    current->next = *stack;
    *stack = current;
    prev->next = NULL;

    return (0);
}

int	rra(t_push_swap **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_push_swap **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if ((push_swap_lstsize(*stack_a) < 2) || (push_swap_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
