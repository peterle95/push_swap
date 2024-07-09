/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:23 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 15:00:51 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_indices(t_push_swap **stack)
{
	int		index;
	t_push_swap	*current;
	
	index = 0;
	current = *stack;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

void	add_to_stack(t_push_swap **stack, t_push_swap *new_node)
{
    t_push_swap *last;

    if (*stack == NULL)
    {
        *stack = new_node;
        return;
    }
    last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

t_push_swap *create_new_node(int value)
{
    t_push_swap *new_node;

    new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
    if (new_node == NULL)
        return NULL;
    new_node->value = value;
    new_node->index = -1; // Initialize index as -1 or any default value
    new_node->next = NULL;
    return (new_node);
}

/* void init_stack(t_push_swap ***stack_a, int ac, char **av)
{
    int i;
    t_push_swap *new_node;
    char **numbers;

    i = 0;
    if (ac == 2)
        numbers = ft_split(av[1], ' ');
    else
    {
        numbers = av;
        i = 1;  // Start from 1 to skip the program name (av[0])
    }
    while (numbers[i])
    {
        new_node = create_new_node(ft_atoi(numbers[i]));
        add_to_stack(*stack_a, new_node);
        i++;
    }
    if (ac == 2)
        free_split(numbers);
    assign_indices(*stack_a);
} */

void init_stack(t_push_swap ***stack_a, int ac, char **av)
{
    int i;
    t_push_swap *new_node;
    char **numbers;

    printf("Entering init_stack function\n");

    i = 0;
    if (ac == 2)
    {
        printf("Splitting single argument\n");
        numbers = ft_split(av[1], ' ');
    }
    else
    {
        printf("Using multiple arguments\n");
        numbers = av;
        i = 1;
    }

    while (numbers[i])
    {
        printf("Creating node for value: %s\n", numbers[i]);
        new_node = create_new_node(ft_atoi(numbers[i]));
        add_to_stack(*stack_a, new_node);
        i++;
    }

    if (ac == 2)
    {
        printf("Freeing split numbers\n");
        free_split(numbers);
    }

    printf("Assigning indices\n");
    assign_indices(*stack_a);

    printf("Exiting init_stack function\n");
}
