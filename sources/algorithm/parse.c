/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:11:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 23:06:45 by pmolzer          ###   ########.fr       */
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

int check_duplicates(int ac, char **av)
{
    int     i;
    int     j;
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

int parse(int ac, char **av)
{
    int i;
    long num;

    i = 1;
    if (ac < 2)
        return (0);
    while (i < ac)
    {
        if (!is_number(av[i]))
        {
            ft_putendl_fd("Error", 2);
            return (0);
        }
        num = ft_atol(av[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            ft_putendl_fd("Error", 2);
            return (0);
        }
    i++;
    }
    if (check_duplicates(ac, av))
    {
        ft_putendl_fd("Error", 2);
        return (0);
    }
    return (1);
}