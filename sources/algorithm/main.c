/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/20 17:51:34 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include<stdio.h>

int main(int ac, char **av)
{
      int i = 1; // Loop counter starting from 1 (skip program name)

  if (ac > 1) {
    while (av[i] != NULL) { // Loop until null terminator
      printf("%s\n", av[i]);
      i++;
    }
  } else {
    printf("OK\n"); // Print OK if no arguments
  }

  return 0;
}
