/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:33:12 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/30 12:59:27 by pmolzer          ###   ########.fr       */
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
a way that reflects the sorted order of the stack elements, without actually modifying the original stack structure.

Yes, you could theoretically use the bubble sort algorithm directly on the stack instead of the radix sort. 
However, there are important considerations:

Implementation:
To use bubble sort directly on the stack, you'd need to modify the algorithm to work with 
linked list operations (swapping nodes) instead of array indices.

Efficiency:
Bubble sort has a time complexity of O(n^2) in the average and worst cases.
Radix sort, as implemented for this project, has a time complexity of O(d * (n + b)), 
where d is the number of digits, n is the number of elements, and b is the base (usually 10 or 2).
For large datasets, radix sort is generally more efficient.


Number of operations:
Bubble sort typically requires more swaps, which in the context of push_swap translates to more stack operations.
Radix sort can be implemented with fewer stack operations, which is crucial for the 
push_swap project where the goal is to minimize the number of operations.


Stack constraints:
The push_swap project typically restricts you to using only specific operations (push, swap, rotate, reverse rotate).
Implementing bubble sort with these constraints might lead to a higher number of operations compared to radix sort.


Stability:
Radix sort is stable, which can be beneficial in some scenarios.
Bubble sort is also stable, but this is less relevant given the specific requirements of push_swap.

Space complexity:
Bubble sort can be implemented in-place, which aligns well with the stack structure.
The radix sort implementation for push_swap typically uses the two stacks efficiently without additional space.*/
void	sort_node_pointers(t_push **arr, int size)
{
	int		i;
	int		j;
	t_push	*temp;
	/*Declares variables: i and j for loop counters, temp for swapping pointers.*/

	i = 1;
	/*The purpose of this structure is to reduce the number of comparisons in each pass:

	In the first pass, we compare all adjacent elements.
	In each subsequent pass, we compare one fewer pair of elements because the largest 
	element from the unsorted portion is already "bubbled up" to its correct position.
	
	This optimization reduces the total number of comparisons, 
	making the algorithm slightly more efficient. For a size of 6, we do:
	5 + 4 + 3 + 2 + 1 = 15 comparisons
	Instead of 6 * 5 = 30 comparisons if we compared all elements in each pass.*/
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		/*Inner loop that compares adjacent elements.*/
		{
			if (arr[j]->value > arr[j + 1]->value)
			/*Checks if the current element is greater than the next one.*/
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				/*Swaps the pointers if they're in the wrong order.*/
			}
			j++;
		}
		i++;
		/*Now, let's visualize this with the stack: 5, 2, 100, 33, 10, 7
		Initial state of arr:
		[5] -> [2] -> [100] -> [33] -> [10] -> [7] (i = 1)
		Pass 1:
		[2] -> [5] -> [33] -> [10] -> [7] -> [100] (i = 2)
		Pass 2:
		[2] -> [5] -> [10] -> [7] -> [33] -> [100] (i = 3)
		Pass 3:
		[2] -> [5] -> [7] -> [10] -> [33] -> [100] (i = 4)
		Pass 4:
		[2] -> [5] -> [7] -> [10] -> [33] -> [100] (i = 5)
		Pass 5: 
		[2] -> [5] -> [7] -> [10] -> [33] -> [100] (i = 6)

		The function doesn't change the actual stack structure, only the order of pointers in the array. 
		After sorting, the array of pointers is arranged so that they point to nodes in ascending order of their values.*/
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
	/*After sorting, our array of pointers looks like this:
	[2] -> [5] -> [7] -> [10] -> [33] -> [100]
	Now, let's apply the set_indices_from_array function:
	Initial state (values shown, indices not yet set):
	[2] -> [5] -> [7] -> [10] -> [33] -> [100]
	
	Step 1 (i = 0):
	[2,0] -> [5] -> [7] -> [10] -> [33] -> [100]

	Step 2 (i = 1):
	[2,0] -> [5,1] -> [7] -> [10] -> [33] -> [100]

	Step 3 (i = 2):
	[2,0] -> [5,1] -> [7,2] -> [10] -> [33] -> [100]

	Step 4 (i = 3):
	[2,0] -> [5,1] -> [7,2] -> [10,3] -> [33] -> [100]

	Step 5 (i = 4):
	[2,0] -> [5,1] -> [7,2] -> [10,3] -> [33,4] -> [100]
	
	Step 6 (i = 5):
	[2,0] -> [5,1] -> [7,2] -> [10,3] -> [33,4] -> [100,5]*/
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
