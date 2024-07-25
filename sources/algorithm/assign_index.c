/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:33:12 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/25 18:10:51 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*This function creates an array of pointers to the nodes in the original stack. 
Its purpose is to prepare the data for sorting without altering the original stack structure. 
It allows us to work with the stack elements in array form, which is more convenient for certain sorting operations.*/
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

/*This function implements the bubble sort algorithm on the array of pointers created by create_sorted_array. 
It sorts the pointers based on the values in the nodes they point to. The purpose is to arrange the pointers in 
a way that reflects the sorted order of the stack elements, without actually modifying the original stack structure.*/
void	sort_node_pointers(t_push **arr, int size)
{
	int		i;
	int		j;
	t_push	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
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

/*After the array of pointers has been sorted, this function assigns an index to each node based on its position 
in the sorted array. The purpose is to give each node in the original stack a numerical index that represents its
position if the stack were sorted. 
This is useful for various sorting algorithms that might use these indices later.*/
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

/*This is the main function that orchestrates the entire process of assigning indices to the stack nodes. 
It calls the other functions in sequence: creating the array, sorting it, and then assigning indices. Its purpose is to provide a single, 
simple interface for the index assignment process, hiding the complexity of the individual steps involved.*/
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

/*This method was chosen for several reasons:

Non-destructive sorting:
The original stack structure remains unchanged.
We're working with an array of pointers to nodes, not the nodes themselves.

Time efficiency:
Creating an array of pointers is O(n) time complexity.
Bubble sort is O(n^2), but it's simple to implement and works well for small datasets.
Assigning indices is again O(n).

Space efficiency:
We only allocate additional space for an array of pointers, not for copying the entire node data.

Simplicity:
The process is straightforward and easy to understand.
Each step (create array, sort, assign indices) is isolated in its own function.

Flexibility:
This method allows us to sort based on node values without modifying the original stack structure.
The indices can be used later for various sorting algorithms or other operations.

Maintainability:
If we need to change the sorting algorithm later, we only need to modify the bubble_sort_array function.

Minimal data movement:
We're only moving pointers around, not entire node structures, which can be more efficient.*/
