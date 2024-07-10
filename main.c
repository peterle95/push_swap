/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 23:50:51 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* void print_stack(t_push **stack_a)
{
    t_push *temp_a = *stack_a;

    printf("Stack A:\n");
    while (temp_a)
    {
        if (temp_a)
        {
            printf("%d (%d)\t\t", temp_a->value, temp_a->index);
            temp_a = temp_a->next;
        }
        else
            printf("    \t\t");
        printf("\n");
    }
    printf("--------------------\n");
}

void print_stacks(t_push **stack_a, t_push **stack_b)
{
    t_push *temp_a = *stack_a;
    t_push *temp_b = *stack_b;

    printf("Stack A:\t\tStack B:\n");
    while (temp_a || temp_b)
    {
        if (temp_a)
        {
            printf("%d (%d)\t\t", temp_a->value, temp_a->index);
            temp_a = temp_a->next;
        }
        else
            printf("    \t\t");
        
        if (temp_b)
        {
            printf("%d (%d)", temp_b->value, temp_b->index);
            temp_b = temp_b->next;
        }
        printf("\n");
    }
    printf("--------------------\n");
} */

int	main(int ac, char **av)
{
	t_push	**stack_a;
	t_push	**stack_b;

	if (parse(ac, av) == 0)
	{
		printf("Parsing failed\n");
		return(0);
	}
	stack_a = (t_push **)malloc(sizeof(t_push));
	stack_b = (t_push **)malloc(sizeof(t_push));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(&stack_a, ac, av);
	if (is_stack_sorted(stack_a))
	{
		printf("Stack is already sorted\n");
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	run_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

