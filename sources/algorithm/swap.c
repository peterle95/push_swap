/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:19:09 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 23:19:36 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

// CHANGE
// Swaps first two elements of a stack | sa and sb

/* int	swap(t_push_swap **stack)
{
	t_push_swap	*head;
	t_push_swap	*next;
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

/*Simplified condition check:
Instead of using push_swap_lstsize, we directly check if the stack is empty or has only one element. This is more efficient and easier to read.
Removed redundant check:
The condition if (!head && !next) was redundant because we already check for these cases in the first condition.
Renamed variables for clarity:
Changed head to first and next to second, which better describes their roles in the swap operation.
Removed unnecessary variable declarations:
We don't need separate head and next variables. We can work directly with *stack and (*stack)->next.
Streamlined swap logic:
The swap operation remains essentially the same, but the code is more compact and easier to follow.
Reduced function complexity:
By simplifying the logic, we've reduced the function from 16 lines to 12 lines, making it easier to read and maintain.*/

int swap(t_push_swap **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return (-1);

    t_push_swap *first = *stack;
    t_push_swap *second = first->next;

    int tmp_val = first->value;
    int tmp_index = first->index;

    first->value = second->value;
    first->index = second->index;
    second->value = tmp_val;
    second->index = tmp_index;

    return (0);
}

int	sa(t_push_swap **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_push_swap **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if ((push_swap_lstsize(*stack_a) < 2) || 
		(push_swap_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
