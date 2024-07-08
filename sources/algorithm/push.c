/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:43 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 18:33:40 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push(t_push_swap **stack_to, t_push_swap **stack_from)
{
	t_push_swap	*tmp;
	t_push_swap	*head_to;
	t_push_swap	*head_from;

	if (push_swap_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

/*Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

/*Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}