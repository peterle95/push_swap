/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:55:02 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/25 17:12:33 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_number(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_sorted(t_push **stack)
{
	t_push	*current;

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

int	find_min_position(t_push *stack)
/*This function takes a pointer to the first node of a stack (t_push *stack).
It returns an integer, which will be the position of the minimum value in the stack.*/
{
	int		min;
	/*Will store the minimum value found so far.*/
	int		pos;
	/*Will keep track of the current position in the stack.*/
	int		min_pos;
	/*Will store the position of the minimum value.*/
	t_push	*current; // A pointer used to traverse the stack.

	min = stack->value; // Initializes min with the value of the first node in the stack.
	pos = 0;
	min_pos = 0;
	current = stack;
	//Initializes current to point to the first node of the stack.
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
	/*Esempio: 2 1 3 4
	min = stack->value (2)
	...
	current = stack (2)
	while(current)
	{
		if(2 < 2) [no!]	
	}
	current = current->next (1)
	pos++ (1)
	...
		if(1 < 2) [yes!]
		{
			min = current->value (1)
			min_pos = pos (1)
		}
	...
	return(min_pos) (1)
	*/
	return (min_pos);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
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
