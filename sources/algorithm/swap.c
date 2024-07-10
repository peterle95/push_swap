/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:19:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/10 13:37:48 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

/* int	swap(t_push **stack)
{
	t_push	*head;
	t_push	*next;
	int		tmp_val;
	int		tmp_index;

	if (push_swap_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		return(-1);
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
} */

/*Reasons why the improved version is better:

More Efficient Error Checking:

Original: Uses push_swap_lstsize(*stack) < 2
Improved: Uses !*stack || !(*stack)->next
Reason: Avoids an extra function call, making it more efficient.


Clearer Variable Names:

Original: Uses head and next
Improved: Uses first and second
Reason: More descriptive, making the code's intent clearer.


Removed Redundant Check:

Original: Has an additional if (!head && !next) check
Improved: This check is removed
Reason: The initial check !*stack || !(*stack)->next already covers this case, simplifying the code.


Better Organized Structure:

Original: Mixes variable assignments with swapping operations
Improved: Clearly separates variable assignments from swapping operations
Reason: Improves readability and logical flow of the function.


More Consistent Naming:

Original: Uses tmp_val and tmp_index
Improved: Uses temp_value and temp_index
Reason: More consistent and descriptive naming improves readability.


Grouped Related Operations:

Original: Swapping values and indices are intermingled
Improved: Swapping values and indices are grouped separately
Reason: Improves code organization and makes the logic clearer.


Removed Unnecessary Variable Assignments:

Original: Assigns next = head->next separately
Improved: Directly uses first->next where needed
Reason: Reduces unnecessary variable usage, simplifying the code.


Better Compliance with C Standards:

The improved version declares all variables at the top, which is more compliant with older C standards and stricter compiler settings.



Overall, the improved version is more efficient, easier to read, and better organized. 
It achieves the same functionality with cleaner, 
more maintainable code, which is crucial for larger projects and collaborative development.*/

int swap(t_push **stack)
{
    t_push *first;
    t_push *second;
    int temp_value;
    int temp_index;

    if (!*stack || !(*stack)->next)
        return (-1);

    first = *stack;
    second = first->next;

    // Store temporary values
    temp_value = first->value;
    temp_index = first->index;

    // Swap values
    first->value = second->value;
    second->value = temp_value;

    // Swap indices
    first->index = second->index;
    second->index = temp_index;

    return (0);
}

int	sa(t_push **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_push **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_push **stack_a, t_push **stack_b)
{
	if ((push_swap_lstsize(*stack_a) < 2) || 
		(push_swap_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
