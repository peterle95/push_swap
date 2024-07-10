/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/10 13:27:55 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int	reverse_rotate(t_push **stack)
{
	t_push	*head;
	t_push	*tail;

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

/*Reasoning behind the modifications:

Simplified Size Check:

Old: if (push_swap_lstsize(*stack) < 2)
New: if (!*stack || !(*stack)->next)
Reason: This avoids calling a separate function, making the check more efficient and direct.


Improved Variable Naming:

Changed head to current, tail to old_last, and introduced new_last.
Reason: These names more clearly describe the roles of each pointer in the function.


Single-Pass Algorithm:

The new version traverses the list only once, finding both the new last node and the old last node in a single loop.
Reason: This is more efficient than the previous version which potentially traversed the list multiple times (once in push_swap_lstlast and again in the while loop).


Removed Redundant Loop:

The original function had a loop that continued until the second-to-last element, then broke.
The new version achieves this more elegantly within the main traversal loop.


Direct Pointer Manipulation:

Instead of using a separate tail variable and then assigning it, we directly use old_last.
Reason: This is more straightforward and reduces unnecessary variable usage.


Clearer Structure:

The operations after the loop are now more clearly laid out, showing exactly how the list is being rearranged.


Removed Dependency:

The function no longer depends on push_swap_lstlast, making it more self-contained.



This improved version maintains the same functionality:

It moves the last element of the stack to the front.
It handles cases with less than two elements correctly.
It returns -1 for invalid operations and 0 for successful ones.

The new version is more efficient (single-pass), clearer in its intentions, and easier to understand and maintain.*/

int reverse_rotate(t_push **stack)
{
    t_push *current;
    t_push *new_last;
    t_push *old_last;

    if (!*stack || !(*stack)->next)
        return (-1);

    current = *stack;
    new_last = *stack;

    while (current->next)
    {
        if (current->next->next == NULL)
            new_last = current;
        current = current->next;
    }
    old_last = current;

    new_last->next = NULL;
    old_last->next = *stack;
    *stack = old_last;

    return (0);
}

int	rra(t_push **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_push **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_push **stack_a, t_push **stack_b)
{
	if ((push_swap_lstsize(*stack_a) < 2) || (push_swap_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
