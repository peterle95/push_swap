/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/08/25 14:40:28 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Main function to initialize, sort, and clean up the push_swap program
int	main(int ac, char **av)
{
	t_push	**stack_a;
	t_push	**stack_b;

	if (parse(ac, av) == 0)
		return (0);
	stack_a = malloc(sizeof(t_push *));
	stack_b = malloc(sizeof(t_push *));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(&stack_a, ac, av);
	if (is_stack_sorted(stack_a))
	{
		free_stack(stack_a);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	run_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
