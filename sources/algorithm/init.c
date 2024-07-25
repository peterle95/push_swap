/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:23 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/24 16:18:14 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_to_stack(t_push **stack, t_push *new_node)
/*This function takes two parameters:

stack: A double pointer to the head of the stack. 
	It's a double pointer because we might need to modify the head of the stack (if it's empty).
	This is crucial for adding the first node when the stack is empty.
new_node: A single pointer to the new node we want to add. 
	It's a single pointer because we're just passing the node, not modifying the pointer itself.*/
{
	t_push	*last;

	if (*stack == NULL)
	/*Checks if the stack is empty. We use *stack (dereferencing once) because stack is a double pointer.*/
	{
		*stack = new_node;
		/*If the stack is empty, we set the head of the stack (*stack) 
		to the new node. This is why we needed a double pointer -
		 we're modifying the pointer to the head of the stack.*/
		return ;
	}
	last = *stack;
	/*If the stack isn't empty, we start at the head of the stack. *stack gives us the pointer to the first node.*/
	while (last->next != NULL)
	/*We traverse the stack until we find the last node (the one with next set to NULL).
	We use last->next because last is a single pointer to a node.*/
		last = last->next;
	last->next = new_node;
	/*We set the next pointer of the last node to our new node, effectively adding it to the end of the stack.*/
}

t_push	*create_new_node(int value)
{
	t_push	*new_node;

	new_node = (t_push *)malloc(sizeof(t_push));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	/*Assignes the converted value from atol*/
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

/*
Single Pointer (t_push *):
This would represent a single node in the stack.

Double Pointer (t_push **):
This typically represents the head of the stack, allowing modifications to the first element.

Triple Pointer (t_push ***):
This allows the function to modify the pointer to the head of the stack itself.

The main reason for using a triple pointer here is likely to allow the init_stack function 
to create or modify the stack from scratch, even if the pointer to the stack is initially NULL or needs to be changed.
*/
void	init_stack(t_push ***stack_a, int ac, char **av)
{
	int		i;
	t_push	*new_node;
	/*A pointer to a t_push structure, used to create new nodes.*/
	char	**numbers;

	i = 0;
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	else
	{
		numbers = av;
		i = 1;
		/*Sets i to 1 to skip the program name in av.*/
	}
	while (numbers[i])
	{
		new_node = create_new_node(ft_atoi(numbers[i]));
		/*Converts the current number string to an integer using ft_atoi.
		Passes this integer to create_new_node to create a new stack node.*/
		add_to_stack(*stack_a, new_node);
		/*Adds the newly created node to the stack.
		Note that *stack_a is used here because stack_a is a triple pointer.*/
		i++;
	}
	if (ac == 2)
		free_split(numbers);
	assign_indices(*stack_a);
}
