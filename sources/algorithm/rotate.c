/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:57:08 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/28 21:57:08 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include<stdio.h>

#include <stdio.h>

t_push_swap *ft_listlast(t_push_swap *lst)
{
    if (lst == NULL) {
        return NULL; // Empty list
    }

    while (lst->next != NULL) {
        lst = lst->next;
    }

    return lst; // Last element
}

int rotate(t_push_swap **stack)
{
    // Check for empty or single-element stacks (no rotation needed)
    if (*stack == NULL || (*stack)->next == NULL) {
        return (-1);
    }

    // Get the head and the last element
    t_push_swap *head = *stack;
    t_push_swap *last = ft_listlast(head);

    // Update head to point to the second element
    *stack = head->next;

    // Connect the last element to the original head
    last->next = head;

    // Terminate the original head's next pointer
    head->next = NULL;

    return (0);
}

int ra(t_push_swap **stack_a)
{
    if (rotate(stack_a) == -1) {
        return (-1);
    }
    ft_putendl_fd("ra", 1); // Assuming ft_putendl_fd prints "ra" to stdout
    return (0);
}

/* int rb(t_push_swap **stack_b)
{
    if (rotate(stack_b) == -1) {
        return (-1);
    }
    ft_putendl_fd("rb", 1); // Assuming ft_putendl_fd prints "rb" to stdout
    return (0);
}

int rr(t_push_swap **stack_a, t_push_swap **stack_b)
{
    if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2) {
        return (-1);
    }
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1); // Assuming ft_putendl_fd prints "rr" to stdout
    return (0);
} */
