/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 18:46:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void run_algorithm(t_push_swap **stack_a, t_push_swap **stack_b)
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
}