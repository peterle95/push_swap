/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:23 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:40:13 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Adds a new node to the end of the stack
void	add_to_stack(t_push **stack, t_push *new_node)
{
	t_push	*last;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

// Creates a new node with the given value
t_push	*create_new_node(int value)
{
	t_push	*new_node;

	new_node = (t_push *)malloc(sizeof(t_push));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

// Initializes the stack with values from command line arguments
void	init_stack(t_push ***stack_a, int ac, char **av)
{
	int		i;
	t_push	*new_node;
	char	**numbers;

	i = 0;
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	else
	{
		numbers = av;
		i = 1;
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
}
