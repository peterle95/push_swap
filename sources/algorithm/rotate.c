/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:57:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:41:52 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotates the stack by moving the first element to the end
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

// Performs rotate operation on stack A and prints "ra"
int ra(t_push **stack_a)
{
    if (rotate(stack_a) == -1) 
    {
        return (-1);
    }
    ft_putendl_fd("ra", 1);
    return (0);
}

// Performs rotate operation on stack B and prints "rb"
int rb(t_push **stack_b)
{
    if (rotate(stack_b) == -1) 
    {
        return (-1);
    }
    ft_putendl_fd("rb", 1);
    return (0);
}

// Performs rotate operation on both stacks A and B and prints "rr"
int rr(t_push **stack_a, t_push **stack_b)
{
    if (push_swap_lstsize(*stack_a) < 2 || push_swap_lstsize(*stack_b) < 2) 
    {
        return (-1);
    }
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1);
    return (0);
}
