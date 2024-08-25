/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:33:12 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:39:53 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Creates an array of pointers to the nodes in the original stack.
t_push	**create_sorted_array(t_push *stack, int size)
{
	t_push	**sorted_array;
	t_push	*current;
	int		i;

	sorted_array = malloc(sizeof(t_push *) * size);
	current = stack;
	i = 0;
	while (i < size)
	{
		sorted_array[i] = current;
		current = current->next;
		i++;
	}
	return (sorted_array);
}

// Implements the bubble sort algorithm on the array of pointers.
void	sort_node_pointers(t_push **arr, int size)
{
	int		i;
	int		j;
	t_push	*temp;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (arr[j]->value > arr[j + 1]->value)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// Assigns an index to each node based on its position in the sorted array.
void	set_indices_from_array(t_push **arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		arr[i]->index = i;
		i++;
	}
}

// Orchestrates the entire process of assigning indices to the stack nodes.
void	assign_indices(t_push **stack)
{
	int		size;
	t_push	**sorted_array;

	size = push_swap_lstsize(*stack);
	sorted_array = create_sorted_array(*stack, size);
	sort_node_pointers(sorted_array, size);
	set_indices_from_array(sorted_array, size);
	free(sorted_array);
}
