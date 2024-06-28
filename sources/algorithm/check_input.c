/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:11:47 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/28 22:11:47 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include<stdio.h>
#include<string.h>

int ft_check_input(int ac, char **av)
{
    int i;
    long long value;
    char *endptr;

    if (ac < 2) {
        printf("Error: Please provide at least one integer argument.\n");
        return (-1);
    }

    for (i = 1; i < ac; i++) {
        // Check for non-numeric characters
        if (strspn(av[i], "-+0123456789") != ft_strlen(av[i])) {
            printf("Error: Invalid argument '%s'. Only integers allowed.\n", av[i]);
            return (-1);
        }

        // Convert string to integer (long long for wider range)
        value = strtoll(av[i], &endptr, 10);

        // Check for conversion errors (overflow/underflow)
        if (*endptr != '\0' || (value < -1000000000 || value > 100000000)) {
            printf("Error: Invalid argument '%s'. Value out of integer range.\n", av[i]);
            return (-1);
        }
    }

    printf("Input is valid.\n");
    return (0);
}