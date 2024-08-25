/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:56 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:41:36 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Moves the last element of the stack to the front
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

// Performs reverse rotate operation on stack A and prints "rra"
int	rra(t_push **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

// Performs reverse rotate operation on stack B and prints "rrb"
int	rrb(t_push **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

// Performs reverse rotate operation on both stacks A and B and prints "rrr"
int	rrr(t_push **stack_a, t_push **stack_b)
{
	if ((push_swap_lstsize(*stack_a) < 2) || (push_swap_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
