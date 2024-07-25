/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/25 01:13:06 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algorithm_3(t_push **stack)
{
	int		a;
	int		b;
	int		c;

	a = (*stack)->value;
	/*(*stack) refers to the first node in the stack.
	The parentheses are necessary because stack is a pointer to a pointer.
	
	In the context of this function, stack is likely a double pointer (t_push **).
	When we use *stack, we're dereferencing this pointer once. This gives us a single pointer (t_push *) that points to the first node in the stack.
	So, (*stack) is equivalent to the first node of the stack.
	
	Here's a visual representation:
	stack (t_push **) ---> [ptr] ---> [Node1] -> [Node2] -> [Node3]
	                         ^
	                         |
	                      *stack
	When we write (*stack), we're accessing the node that *stack points to, which is the first node in the stack.
	The parentheses in (*stack) are necessary because of operator precedence. If we wrote *stack->value, 
	it would be interpreted as *(stack->value), which is not what we want.
	Let's break down what *stack->value would mean if it were valid syntax:
	
	Due to operator precedence, *stack->value would be interpreted as *(stack->value).
	This interpretation assumes that:
	stack is a pointer to a structure that has a member called value.
	value is itself a pointer.
	
	
	The operation would then attempt to dereference value.
	However, in the context of the t_push structure we've been discussing, this expression doesn't make sense because:
	stack is a double pointer (t_push **), not a pointer to a structure.
	Even if we consider *stack (which is a t_push *), value is typically an integer, not a pointer.
	
	If we had a structure where value was a pointer, like this:
	struct example {
	    int *value;
	    // other members...
	};
	
	struct example *stack;
	
	Then *stack->value would mean:
	
	Access the value member of the structure pointed to by stack.
	Dereference the pointer stored in value.
	
	But in our actual t_push context, *stack->value would be a syntax error because:
	
	stack is a double pointer, so stack->value is not valid.
	value is typically not a pointer, so dereferencing it doesn't make sense.
	
	This is why we use (*stack)->value instead:
	
	(*stack) dereferences the double pointer to get the first node.
	-> then accesses the value member of that node.
	
*/
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	algorithm_4(t_push **stack_a, t_push **stack_b)
{
	int		min_pos;

	min_pos = find_min_position(*stack_a);
	if (min_pos == 1)
		ra(stack_a);
	else if (min_pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	algorithm_3(stack_a);
	pa(stack_a, stack_b);
}

void	algorithm_5(t_push **stack_a, t_push **stack_b)
{
	int		min_pos;

	min_pos = find_min_position(*stack_a);
	if (min_pos == 1)
		ra(stack_a);
	else if (min_pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (min_pos == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	algorithm_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	run_algorithm(t_push **stack_a, t_push **stack_b)
{
	if (push_swap_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (push_swap_lstsize(*stack_a) == 3)
		algorithm_3(stack_a);
	else if (push_swap_lstsize(*stack_a) == 4)
		algorithm_4(stack_a, stack_b);
	else if (push_swap_lstsize(*stack_a) == 5)
		algorithm_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
