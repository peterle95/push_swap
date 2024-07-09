/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:55:02 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 12:08:27 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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