/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:11:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:40:49 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Validates a single number string
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

// Validates all numbers in the array
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

// Retrieves the array of number strings from command line arguments
static char	**get_numbers(int ac, char **av, int *start)
{
	char	**numbers;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		*start = 0;
	}
	else
	{
		numbers = av;
		*start = 1;
	}
	return (numbers);
}

// Parses and validates the input arguments
int	parse(int ac, char **av)
{
	char	**numbers;
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
