/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/30 17:19:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int get_max_bits(t_push *stack)
{
    int max = 0;
    int max_bits = 0;

    while (stack)
	// Loop through each node in the stack.
    {
        if (stack->index > max)
            max = stack->index;
			//If the current node's index is larger than max, update max.
        stack = stack->next;
    }

    while (max)
	// Start a new loop that continues while max is not zero.
    {
        max >>= 1;
		// Right-shift max by 1 bit (equivalent to dividing by 2).
        max_bits++;
    }

    return (max_bits);
	//Return the number of bits needed to represent the largest index.

/*Now, let's visualize this with the stack: 10, 3, 1, 22, 5
Assume the indices have been assigned based on the sorted order of these values:
[1,0] -> [3,1] -> [5,2] -> [10,3] -> [22,4] -> NULL
Step 1: Finding the maximum index

Iterate through the stack, comparing indices:
0 -> 1 -> 2 -> 3 -> 4
max = 4

Step 2: Counting bits

Start with max = 4 (binary: 100)
First iteration:  max = 2 (binary: 10),  max_bits = 1
Second iteration: max = 1 (binary: 1),   max_bits = 2
Third iteration:  max = 0 (binary: 0),   max_bits = 3

The function returns 3, indicating that 3 bits are needed to represent the largest index (4) in binary.
This information is crucial for the radix sort algorithm, 
as it determines how many passes through the stack are needed to fully sort it based on the binary representation of the indices.*/
}



/*The key idea is that this process sorts the numbers based on their binary representation, 
starting from the least significant bit. After each pass, the numbers are partially sorted, 
and after processing all bits, the stack is fully sorted.
This implementation is efficient because:

It only requires a fixed number of passes (equal to the number of bits in the largest number).
It uses only the allowed stack operations (push, rotate).
It maintains the relative order of elements with the same bit value, which is crucial for the stability of the sort.*/
void	radix(t_push **stack_a, t_push **stack_b)
{
	int		size;
	int		max_bits;
	int		bit;
	int		j;

	bit = 0;
	size = push_swap_lstsize(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (bit < max_bits)
	// This loop runs once for each bit, from least significant to most significant.
	{
		j = 0;
		while (j < size)
		// This loop processes each element in the stack once per bit.
		{
			if (((*stack_a)->index >> bit) & 1)
			/*((*stack_a)->index >> bit) & 1: This checks the bit-th bit of the index.

			>> shifts the bits right, bringing the bit we're interested in to the least significant position.
			& 1 performs a bitwise AND with 1, isolating just that bit.*/
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}

/*The radix sort algorithm was chosen for the push_swap project for several key reasons:

1. Efficiency: For the constraints of push_swap, radix sort can be very efficient, especially for large datasets. 
It has a time complexity of O(d * n), where d is the number of digits (or bits) and n is the number of elements.

2. Limited operations: Radix sort can be implemented using only the allowed stack operations 
(push, swap, rotate, reverse rotate), which is crucial for the push_swap project.

3. Predictable number of operations: The number of operations in radix sort is consistent and 
predictable, which helps in optimizing for the project's requirements.

How Radix Sort works in this context:

1. Indexing: First, the elements are assigned indices based on their sorted order. This allows us to work with 
positive integers regardless of the original input values.

2. Bit-by-bit sorting: The algorithm sorts the numbers based on their binary representation, starting from the 
least significant bit (LSB) to the most significant bit (MSB).
	
	We'll use the same example: 3, 7, 1, 5, 2.
	First, let's assign indices based on the sorted order:
		Value:  1  2  3  5  7
		Index:  0  1  2  3  4
		Binary: 000 001 010 011 100

	Now, let's sort these indices using radix sort, examining each bit from LSB to MSB:
	Initial state:
	Stack A: [3(2), 7(4), 1(0), 5(3), 2(1)]
	Stack B: []

	Sorting by Least Significant Bit (rightmost bit):
	A: [7(4), 5(3), 3(2)]  // Odd indices (ending in 1)
	B: [1(0), 2(1)]        // Even indices (ending in 0)
	After merging: [1(0), 2(1), 7(4), 5(3), 3(2)]

	Sorting by Second Bit:
	A: [7(4), 5(3), 2(1)]  // 1 in second position
	B: [1(0), 3(2)]        // 0 in second position
	After merging: [1(0), 3(2), 7(4), 5(3), 2(1)]

	Sorting by Most Significant Bit (leftmost bit):
	A: [7(4), 5(3)]        // 1 in third position
	B: [1(0), 3(2), 2(1)]  // 0 in third position
	After merging: [1(0), 3(2), 2(1), 7(4), 5(3)]

	Final Result:
	Sorted Stack: [1(0), 2(1), 3(2), 5(3), 7(4)]

		Key Points:

		We sort based on the binary representation of indices, not original values.
		We start from the rightmost (least significant) bit and move left.
		In each pass, we divide numbers into two groups: 0-bit and 1-bit in the current position.
		By processing from right to left, we maintain the order established by previous bits.
		This method works well with push_swap operations:
		
		'pb' moves 0-bit numbers to Stack B
		'ra' rotates 1-bit numbers in Stack A
		'pa' brings everything back to Stack A in the correct order for each bit
		
		This radix sort implementation efficiently sorts the stack while adhering to the push_swap project's constraints.
		
3. For each bit:
   - If the bit is 0, the element is pushed to stack B.
   - If the bit is 1, the element is rotated to the bottom of stack A.
   - After processing all elements, everything in stack B is pushed back to stack A.

4. This process is repeated for each bit, up to the most significant bit of the largest number.

5. After processing all bits, the stack is sorted.

Why it works:
- By sorting from LSB to MSB, we maintain the relative order of elements in each pass.
- Each pass groups numbers with the same bit value together.
- After processing all bits, the numbers are fully sorted.

Advantages:
- It's non-comparative, which can be faster for certain datasets.
- It's stable, maintaining the relative order of elements with equal values.
- It works well with the limited set of operations available in push_swap.

In the context of push_swap, radix sort provides a good balance between efficiency, 
simplicity of implementation, and adherence to the project's constraints. 
It's particularly effective for larger datasets where other algorithms might require significantly more operations.*/