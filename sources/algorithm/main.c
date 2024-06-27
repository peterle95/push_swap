/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/20 17:51:34 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include<stdio.h>

#include "push_swap.h"

int main(int ac, char **av)
{
    t_push_swap *stack_a;
    t_push_swap *stack_b;
    int i;

    if (ac < 2)
        return (0);

    stack_a = NULL;
    stack_b = NULL;
    ft_check_input(ac, av); 
    stack_a = (t_push_swap **)malloc(sizeof(t_push_swap));
    stack_b = (t_push_swap **)malloc(sizeof(t_push_swap));
    init_stack(&stack_a, &stack_b);
    if(is_stack_sorted(stack_a))
    {
      free_stack(stack_a);
      free_stack(stack_b);
      return (0);
    }
    run_algorithm(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
