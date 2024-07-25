/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/24 16:35:15 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_push	**stack_a;
	t_push	**stack_b;
    /*The use of double pointers for stack_a and stack_b in the main function is related to how linked lists are typically managed in C. 
    Let's break down the reasons:
    Representation of the stack:
    
    In a linked list implementation, we typically use a pointer to represent the head of the list.
    So, t_push *stack_a would be a pointer to the first node of the stack.
    
    Need for modification:
    The double pointer t_push **stack_a allows functions to modify the pointer to the head of the stack.
    This is crucial for operations that might change the first element of the stack, like pushing or popping elements.
    
    Flexibility in initialization:
    With a double pointer, we can initialize the stack to NULL and then modify it in functions
    
    Consistent function signatures:
    Functions that need to modify the stack (like push, pop, or initialize) can have a consistent signature:    
        void some_function(t_push **stack); 
    This allows these functions to potentially change where the head of the stack points.
    
    Handling empty stacks:
    With a double pointer, functions can easily handle the case of an empty stack by checking if *stack_a is NULL.
    */

	if (parse(ac, av) == 0)
		return (0);
	stack_a = malloc(sizeof(t_push *));
	stack_b = malloc(sizeof(t_push *));
    /*stack_a and stack_b are declared as double pointers (t_push **).
    This means they are pointers to pointers of t_push structures.
    
    malloc(sizeof(t_push *)):
    This allocates memory for a single pointer to a t_push structure.
    sizeof(t_push *) gives the size of a pointer to a t_push structure.
    
    Now, let's break down the pointer levels:
    t_push is the structure for a single node in the stack.
    t_push * is a pointer to a single node.
    t_push ** is a pointer to a pointer to a node, which we're using to represent the entire stack.
    
    What this code does:
    It allocates memory for a single pointer.
    This pointer will be used to point to the first node of the stack (or NULL if the stack is empty).
    stack_a and stack_b are now pointers to these allocated pointers.
    
    Why it's done this way:
    This setup allows you to change the head of the stack by modifying what the allocated 
    pointer points to, without changing stack_a or stack_b themselves.
    It provides a consistent way to represent an empty stack (the allocated pointer can be 
    set to NULL) and a stack with elements (the allocated pointer points to the first node).
    This structure is compatible with functions that expect a double pointer to manipulate
     the stack, like your init_stack function.
    
    After these lines:
    *stack_a and *stack_b are uninitialized pointers that will be set to either NULL (for empty 
    stacks) or to the first node of their respective stacks.
    stack_a and stack_b themselves point to these allocated memory locations.*/
    *stack_a = NULL;
	*stack_b = NULL;
	init_stack(&stack_a, ac, av);
	if (is_stack_sorted(stack_a))
	{
		free_stack(stack_a);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	run_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
