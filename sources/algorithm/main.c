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

void add_to_stack(t_push_swap **stack, int value)
{
    t_push_swap *new_node = malloc(sizeof(t_push_swap));
    if (!new_node)
        return;  // Handle malloc failure
    
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

void print_stack(t_push_swap *node) {
    if (node == NULL) {
        return; // Base case: Reached the end of the list
    }
    printf("%d ", node->value); // Modify this based on your data member name
    print_stack(node->next); // Recursive call to print the remaining elements
}


int main(int ac, char **av)
{
    t_push_swap **stack_a;
    // t_push_swap **stack_b;

    if (ac < 2)
        return (0);

    stack_a = (t_push_swap **)malloc(sizeof(t_push_swap));
    // stack_b = (t_push_swap **)malloc(sizeof(t_push_swap));
    *stack_a = NULL;
    // stack_b = NULL;
    ft_check_input(ac, av); 
    printf("exit checker\n");
    /* init_stack(&stack_a, &stack_b);
    if(is_stack_sorted(stack_a))
    {
      free_stack(stack_a);
      free_stack(stack_b);
      return (0);
    } */
    // run_algorithm(stack_a, stack_b);
    printf("add_to_stack\n");
    for (int i = 1; i < ac; i++) {
        int value = atoi(av[i]);
        // Assuming you have a function to add a new node to the stack
        add_to_stack(stack_a, value);
    }
    printf("exit add_to_stack\n");

    printf("Stack before ra: ");
    print_stack(*stack_a);

    ra(stack_a);
    
    printf("\nStack after ra: ");
    print_stack(*stack_a);

    // free_stack(stack_a);
    // free_stack(stack_b);
    return (0);
}

