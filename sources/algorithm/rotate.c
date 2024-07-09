/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:57:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 23:15:41 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// CHECK

/* int rotate(t_push_swap **stack)
{
    // Check for empty or single-element stacks (no rotation needed)
    if (*stack == NULL || (*stack)->next == NULL) {
        return (-1);
    }

    // Get the head and the last element
    t_push_swap *head = *stack;
    t_push_swap *last = push_swap_lstlast(head);

    // Update head to point to the second element
    *stack = head->next;

    // Connect the last element to the original head
    last->next = head;

    // Terminate the original head's next pointer
    head->next = NULL;

    return (0);
} */

/*Reasoning for the changes:

Condition check remains the same:
We keep the check for empty or single-element stacks as it's already concise and clear.
Removed head variable:
We can work directly with *stack, eliminating the need for a separate head variable.
Simplified last element finding:
Instead of using a separate push_swap_lstlast function, we integrate the process of finding the second-to-last element into our main logic. This reduces function call overhead and simplifies the code.
Combined operations:
We perform the rotation in three steps:

Make the last element point to the original first element
Make the last element the new first element
Set the new last element's next to NULL


Reduced variable usage:
We only use one additional variable (last) instead of two (head and last).
Eliminated redundant operation:
In the original version, we set *stack = head->next and then last->next = head. In the simplified version, 
we directly set *stack to the last element, which becomes the new first element.*/

int rotate(t_push_swap **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return (-1);

    t_push_swap *last = *stack;
    while (last->next->next != NULL)
        last = last->next;

    last->next->next = *stack;
    *stack = last->next;
    last->next = NULL;

    return (0);
}

int ra(t_push_swap **stack_a)
{
    if (rotate(stack_a) == -1) {
        return (-1);
    }
    ft_putendl_fd("ra", 1); // Assuming ft_putendl_fd prints "ra" to stdout
    return (0);
}

int rb(t_push_swap **stack_b)
{
    if (rotate(stack_b) == -1) {
        return (-1);
    }
    ft_putendl_fd("rb", 1); // Assuming ft_putendl_fd prints "rb" to stdout
    return (0);
}

int rr(t_push_swap **stack_a, t_push_swap **stack_b)
{
    if (push_swap_lstsize(*stack_a) < 2 || push_swap_lstsize(*stack_b) < 2) {
        return (-1);
    }
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1); // Assuming ft_putendl_fd prints "rr" to stdout
    return (0);
}
