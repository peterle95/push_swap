/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 14:54:09 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* void run_algorithm2(t_push_swap **stack_a, t_push_swap **stack_b)
{
    printf("Starting algorithm\n");
    print_stacks(stack_a, stack_b);

    pb(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    pb(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    pb(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    sa(stack_a);
    print_stacks(stack_a, stack_b);

    sb(stack_b);
    print_stacks(stack_a, stack_b);

    ss(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    ra(stack_a);
    print_stacks(stack_a, stack_b);

    rra(stack_a);
    print_stacks(stack_a, stack_b);

    rr(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    rrr(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    rb(stack_a);
    print_stacks(stack_a, stack_b);

    rrb(stack_b);
    print_stacks(stack_a, stack_b);

    pa(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    pa(stack_a, stack_b);
    print_stacks(stack_a, stack_b);

    printf("Algorithm completed\n");
} */

void    algorithm_3(t_push_swap **stack)
{
    printf("Starting algorithm_3\n");
    print_stack(stack);
    int     a;
    int     b;
    int     c;

    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;
    
    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

void algorithm_4(t_push_swap **stack_a, t_push_swap **stack_b)
{
    printf("Starting algorithm_4\n");
    print_stacks(stack_a, stack_b);
    int min_pos = find_min_position(*stack_a);

    // Move the smallest number to the top
    if (min_pos == 1)
        ra(stack_a);
    else if (min_pos == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (min_pos == 3)
        rra(stack_a);

    // Push the smallest number to stack B
    pb(stack_a, stack_b);

    // Sort the remaining 3 numbers
    algorithm_3(stack_a);

    // Push back the smallest number
    pa(stack_a, stack_b);
    printf("Ending algorithm_4\n");
    print_stacks(stack_a, stack_b);
}

void algorithm_5(t_push_swap **stack_a, t_push_swap **stack_b)
{
    int min_pos = find_min_position(*stack_a);

    // Move the smallest number to the top
    if (min_pos == 1)
        ra(stack_a);
    else if (min_pos == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (min_pos == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if (min_pos == 4)
        rra(stack_a);

    // Push the smallest number to stack B
    pb(stack_a, stack_b);

    // Now we have 4 numbers in stack A, so we can use algorithm_4
    algorithm_4(stack_a, stack_b);

    // Push back the smallest number
    pa(stack_a, stack_b);
}

void run_algorithm(t_push_swap **stack_a, t_push_swap **stack_b)
{
    // run_algorithm2(stack_a, stack_a);
    printf("Starting algorithm\n");
    print_stacks(stack_a, stack_b);
    /* int i;

    i = push_swap_lstsize */

   /*  if (push_swap_lstsize == 1)
        return; is_sorted should check this*/
    if (push_swap_lstsize(*stack_a) == 2)
        sa(stack_a);
    else if (push_swap_lstsize(*stack_a) == 3)
        algorithm_3(stack_a);
    else if(push_swap_lstsize(*stack_a) == 4)
        algorithm_4(stack_a, stack_b);
    else if (push_swap_lstsize(*stack_a) == 5)
        algorithm_5(stack_a, stack_b);
    else
        radix(stack_a, stack_b);
    printf("Ending algorithm\n");
}