/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:42:31 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 23:22:29 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int check_duplicates_split(char **numbers)
{
    int i;
    int j;
    long num1;
    long num2;

    i = 0;
    while (numbers[i])
    {
        j = i + 1;
        while (numbers[j])
        {
            num1 = ft_atol(numbers[i]);
            num2 = ft_atol(numbers[j]);
            if (num1 == num2)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int check_duplicates_args(int ac, char **av)
{
    int i;
    int j;
    long num1;
    long num2;

    i = 1;
    while (i < ac - 1)
    {
        j = i + 1;
        while (j < ac)
        {
            num1 = ft_atol(av[i]);
            num2 = ft_atol(av[j]);
            if (num1 == num2)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_duplicates(int ac, char **av)
{
    char **numbers;
    int result;

    if (ac == 2)
    {
        numbers = ft_split(av[1], ' ');
        if (!numbers)
            return (1);
        result = check_duplicates_split(numbers);
        free_split(numbers);
    }
    else
        result = check_duplicates_args(ac, av);
    return (result);
}