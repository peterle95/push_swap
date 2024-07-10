/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:57:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/10 13:31:21 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int	rotate(t_push **stack)
{
	t_push	*head;
	t_push	*tail;

	if (push_swap_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = push_swap_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
} */

/*Reasoning behind the modifications:

Simplified Size Check:

Old: if (push_swap_lstsize(*stack) < 2)
New: if (!*stack || !(*stack)->next)
Reason: This avoids calling a separate function, making the check more efficient and direct.


Improved Variable Naming:

Changed head to old_first, introduced new_first, and tail to last.
Reason: These names more clearly describe the roles of each pointer in the function.


Removed Dependency:

The function no longer depends on push_swap_lstlast, making it more self-contained.
Reason: This improves modularity and reduces function call overhead.


Single-Pass Algorithm:

The new version finds the last node in a single pass through the list.
Reason: This is more efficient than calling a separate function to find the last node.


Clear Structure:

The operations are now more clearly laid out, showing exactly how the list is being rearranged.
Reason: Improves readability and makes the function's logic more apparent.


Direct Pointer Manipulation:

We directly manipulate the pointers to rearrange the list.
Reason: This approach is more straightforward and efficient.


Logical Order of Operations:

The new version first identifies all necessary nodes, then performs the rotation.
Reason: This separation of "finding" and "manipulating" makes the code easier to understand and maintain.



This improved version maintains the same functionality:

It moves the first element of the stack to the end.
It handles cases with less than two elements correctly.
It returns -1 for invalid operations and 0 for successful ones.

The new version is more efficient (avoids extra function calls), clearer in its intentions, 
and easier to understand and maintain. It also follows a more logical flow, first identifying 
all the nodes it needs to work with, and then performing the rotation operation.*/

int rotate(t_push **stack)
{
    t_push *old_first;
    t_push *new_first;
    t_push *last;

    if (!*stack || !(*stack)->next)
        return (-1);

    old_first = *stack;
    new_first = old_first->next;
    last = new_first;

    while (last->next)
        last = last->next;

    *stack = new_first;
    last->next = old_first;
    old_first->next = NULL;

    return (0);
}

int ra(t_push **stack_a)
{
    if (rotate(stack_a) == -1) 
    {
        return (-1);
    }
    ft_putendl_fd("ra", 1); // Assuming ft_putendl_fd prints "ra" to stdout
    return (0);
}

int rb(t_push **stack_b)
{
    if (rotate(stack_b) == -1) 
    {
        return (-1);
    }
    ft_putendl_fd("rb", 1); // Assuming ft_putendl_fd prints "rb" to stdout
    return (0);
}

int rr(t_push **stack_a, t_push **stack_b)
{
    if (push_swap_lstsize(*stack_a) < 2 || push_swap_lstsize(*stack_b) < 2) 
    {
        return (-1);
    }
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1); // Assuming ft_putendl_fd prints "rr" to stdout
    return (0);
}
