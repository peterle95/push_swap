/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:11:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/14 12:00:08 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	validate_number(char *str)
{
	long	num;

	num = ft_atol(str);
	if (!is_number(str))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

static int	validate_numbers(char **numbers, int start)
{
	int		i;

	i = start;
	while (numbers[i])
	{
		if (!validate_number(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**get_numbers(int ac, char **av, int *start)
{
	char	**numbers;
	/*Declares a pointer to a pointer of characters to store the array of number strings.*/

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		*start = 0;
		/*Sets the start index to 0 for the split string array*/
	}
	else
	{
		numbers = av;
		/*It directly assigns the argument vector to numbers.*/
		*start = 1;
		/*Skip the prog name*/
	}
	return (numbers);
}
/*The use of double pointers (char **numbers) in both functions is related to 
how arrays of strings are represented in C. Let's break down why this is necessary:

In C, strings are represented as arrays of characters.
When you have multiple strings, you essentially have an array of arrays of characters.
In memory, this is represented as a contiguous block of memory addresses, each pointing to the start of a string.
A double pointer (char **) is used to point to this array of pointers.
Here's why it's used in each function:

In get_numbers:
When ac == 2, ft_split is used to split a single string into multiple strings. The 
result of ft_split is an array of strings, which is represented as char **.
When ac > 2, av (which is already a char **) is directly assigned to numbers.
In parse:
It needs to handle the result from get_numbers, which is a char **.
This allows it to work with both the split result (when ac == 2) and the original av (when ac > 2).
Using a double pointer allows these functions to:

Handle an unknown number of strings
Modify the array of strings if needed
Pass this array of strings to other functions
In essence, char **numbers represents a dynamic array of strings, which is necessary for 
the flexibility required in parsing command-line arguments or split strings.

*/
int	parse(int ac, char **av)
{
	char	**numbers;
	/*Declares a pointer to a pointer of characters to store the array of number strings.*/
	int		start;

	if (ac < 2)
		return (0);
	numbers = get_numbers(ac, av, &start);
	if (!numbers)
		return (0);
	if (!validate_numbers(numbers, start))
	{
		if (ac == 2)
			free_split(numbers);
		return (0);
	}
	if (check_duplicates(ac, av))
	{
		ft_putendl_fd("Error", 2);
		if (ac == 2)
			free_split(numbers);
		return (0);
	}
	if (ac == 2)
		free_split(numbers);
	return (1);
}

