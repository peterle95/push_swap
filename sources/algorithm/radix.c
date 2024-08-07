/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/07 15:13:12 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


/*ᓚᘏᗢ BITSHIFTING ᓚᘏᗢ

Right bitshifting by 1 (>>) is a binary operation that moves all bits in a number one position to the right. 

Here's a visual representation:
Let's use an 8-bit integer as an example:

1. Starting number: 22 (decimal)
   Binary: 0 0 0 1 0 1 1 0

2. After right shift by 1:
   Binary: 0 0 0 0 1 0 1 1
   
   Result: 11 (decimal)

Visual representation of the shift:

```
Before shift:  0 0 0 1 0 1 1 0  (22 in decimal)
                ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↘
After shift:   0 0 0 0 1 0 1 1  (11 in decimal)
               ↑
               |
    This 0 comes in from the left
```

Key points:
1. Each bit moves one position to the right.
2. The rightmost bit (least significant bit) is lost.
3. A 0 is inserted on the left (most significant bit).
4. For positive numbers, this operation is equivalent to integer division by 2.

Let's look at a few more examples:

```
1. Number: 40 (101000 in binary)
   40 >> 1 = 20 (010100 in binary)

2. Number: 15 (1111 in binary)
   15 >> 1 = 7  (0111 in binary)

3. Number: 1 (0001 in binary)
   1 >> 1 = 0   (0000 in binary)
```

In the context of the `get_max_bits` function in the radix sort algorithm, 
right shifting is used to efficiently count the number of bits needed to represent the largest number. 
Each shift effectively divides the number by 2, 
and the loop continues until the number becomes 0, counting how many shifts were needed.*/
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
			& 1 performs a bitwise AND with 1, isolating just that bit.
			Let's visualize this operation step by step, using an index of 5 and showing the process for each bit position.

			Example:
			Index: 5 (binary representation: 101)
			
			We'll go through the operation for bit positions 0, 1, and 2:
			
			1. Bit position 0:
			
			   Index:        1 0 1
			   Right shift:  1 0 1 >> 0 = 1 0 1
			   AND with 1:   1 0 1
			               & 0 0 1
			               -------
			   Result:       0 0 1  (1 in decimal)
			
			Result is 1, so the condition is true.
			
			2. Bit position 1:
			
			   Index:        1 0 1
			   Right shift:  1 0 1 >> 1 = 0 1 0
			   AND with 1:   0 1 0
			               & 0 0 1
			               -------
			   Result:       0 0 0  (0 in decimal)
			
			Result is 0, so the condition is false.
			
			3. Bit position 2:
			
			   Index:        1 0 1
			   Right shift:  1 0 1 >> 2 = 0 0 1
			   AND with 1:   0 0 1
			               & 0 0 1
			               -------
			   Result:       0 0 1  (1 in decimal)
			
			Result is 1, so the condition is true.
			
			Visual summary:
			Index: 5 (101 in binary)
			
			Bit position:   2   1   0
			                |   |   |
			Binary:         1   0   1
			                |   |   |
			Condition:     true false true
			*/
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
	
	Initial stack:
	A: [100(1), 25(0), 102(2)]
	B: []
	
	Least Significant Bit (LSB):
	
	100(1): 001 & 1 = 1 (ra)
	A: [25(0), 102(2), 100(1)]
	B: []
	
	25(0):  000 & 1 = 0 (pb)
	A: [102(2), 100(1)]
	B: [25(0)]
	
	102(2): 010 & 1 = 0 (pb)
	A: [100(1)]
	B: [102(2), 25(0)]
	
	Now we pa all elements from B to A:
	A: [25(0), 102(2), 100(1)]
	B: []
	
	Second Bit:
	
	25(0):  000 & 10 = 0 (pb)
	A: [102(2), 100(1)]
	B: [25(0)]
	
	102(2): 010 & 10 = 10 = 2 (ra)
	A: [100(1), 102(2)]
	B: [25(0)]
	
	100(1): 001 & 10 = 0 (pb)
	A: [102(2)]
	B: [100(1), 25(0)]
	
	Now we pa all elements from B to A:
	A: [25(0), 100(1), 102(2)]
	B: []
	
	Most Significant Bit (MSB):
	
	25(0):  000 & 100 = 0 (ra)
	A: [100(1), 102(2), 25(0)]
	B: []
	
	100(1): 001 & 100 = 0 (ra)
	A: [102(2), 25(0), 100(1)]
	B: []
	
	102(2): 010 & 100 = 0 (ra)
	A: [25(0), 100(1), 102(2)]
	B: []
	
	No pa needed as B is empty and A is sorted.

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