/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:57:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 15:00:17 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// CHECK

int	rotate(t_push **stack)
{
	t_push	*head;
	t_push	*tail;

	if (push_swap_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = push_swap_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int ra(t_push **stack_a)
{
    if (rotate(stack_a) == -1) {
        return (-1);
    }
    ft_putendl_fd("ra", 1); // Assuming ft_putendl_fd prints "ra" to stdout
    return (0);
}

int rb(t_push **stack_b)
{
    if (rotate(stack_b) == -1) {
        return (-1);
    }
    ft_putendl_fd("rb", 1); // Assuming ft_putendl_fd prints "rb" to stdout
    return (0);
}

int rr(t_push **stack_a, t_push **stack_b)
{
    if (push_swap_lstsize(*stack_a) < 2 || push_swap_lstsize(*stack_b) < 2) {
        return (-1);
    }
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1); // Assuming ft_putendl_fd prints "rr" to stdout
    return (0);
}
