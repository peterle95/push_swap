/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:11:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 17:56:25 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_number(char *str)
{
    int i = 0;

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

static int check_duplicates_split(char **numbers)
{
    int i, j;
    long num1, num2;

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
    int i, j;
    long num1, num2;

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

static int validate_number(char *str)
{
    long num;

    if (!is_number(str))
    {
        ft_putendl_fd("Error", 2);
        return (0);
    }
    num = ft_atol(str);
    if (num > INT_MAX || num < INT_MIN)
    {
        ft_putendl_fd("Error", 2);
        return (0);
    }
    return (1);
}

static int validate_numbers(char **numbers, int start)
{
    int i;

    i = start;
    while (numbers[i])
    {
        if (!validate_number(numbers[i]))
            return (0);
        i++;
    }
    return (1);
}

static char **get_numbers(int ac, char **av, int *start)
{
    char **numbers;

    if (ac == 2)
    {
        printf("Splitting single argument\n");
        numbers = ft_split(av[1], ' ');
        *start = 0;
    }
    else
    {
        printf("Using multiple arguments\n");
        numbers = av;
        *start = 1;
    }
    return (numbers);
}

int parse(int ac, char **av)
{
    char **numbers;
    int start;

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