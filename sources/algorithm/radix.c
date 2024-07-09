/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 12:16:03 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int get_max_bits(t_push_swap *stack)
{
    int max = stack->value;
    t_push_swap *current = stack;
    int max_bits = 0;

    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix(t_push_swap **stack_a, t_push_swap **stack_b)
{
    int size = push_swap_lstsize(*stack_a);
    int max_bits = get_max_bits(*stack_a);
    int i, j;

    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (((*stack_a)->value >> i) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        print_stacks(stack_a, stack_b);
    }
}