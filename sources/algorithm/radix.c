/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 23:46:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int get_max_bits(t_push_swap *stack)
{
    int max;
    t_push_swap *current;
    int max_bits;

    max = stack->index;
    current = stack;
    max_bits = 0;
    while (current)
    {
        if (current->index > max)
            max = current->index;
        current = current->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix(t_push_swap **stack_a, t_push_swap **stack_b)
{
    int size;
    int max_bits;
    int i = 0;
    int j;

    i = 0;
    size = push_swap_lstsize(*stack_a);
    max_bits = get_max_bits(*stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*stack_a)->index >> i) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        // print_stacks(stack_a, stack_b);
        i++;
    }
}