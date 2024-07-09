/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:55:02 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 18:04:00 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_stack_sorted(t_push_swap **stack)
{
    t_push_swap *current;

    if (!stack)
        return (1);  // An empty stack is considered sorted

    current = *stack;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);  // Not sorted
        current = current->next;
    }
    return (1);  // Sorted
}

int find_min_position(t_push_swap *stack)
{
    int min = stack->value;
    int pos = 0;
    int min_pos = 0;
    t_push_swap *current = stack;

    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }

    return min_pos;
}

long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;
    
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (sign * result);
}