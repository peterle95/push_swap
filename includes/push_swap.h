/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:41 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/09 17:57:18 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



# include "../libft/libft.h"

typedef struct s_push_swap
{
    int value;
    int index;
    struct s_push_swap  *next;
}t_push_swap;


# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>
#include <string.h>


// Rotation
int ra(t_push_swap **stack_a);
int rb(t_push_swap **stack_b);
int rr(t_push_swap **stack_a, t_push_swap **stack_b);

// Reverse_rotation
int	rra(t_push_swap **stack_a);
int	rrb(t_push_swap **stack_b);
int	rrr(t_push_swap **stack_a, t_push_swap **stack_b);

// Push
int	pa(t_push_swap **stack_a, t_push_swap **stack_b);
int	pb(t_push_swap **stack_a, t_push_swap **stack_b);

// Swap
int	sa(t_push_swap **stack_a);
int	sb(t_push_swap **stack_b);
int	ss(t_push_swap **stack_a, t_push_swap **stack_b);

// Parsing / Checking Input
int parse(int ac, char **av);

// Initialization
void init_stack(t_push_swap ***stack_a, int ac, char **av);
t_push_swap *create_new_node(int value);
void add_to_stack(t_push_swap **stack, t_push_swap *new_node);
void assign_indices(t_push_swap **stack);

// Free 
void free_stack(t_push_swap **stack);
void free_split(char **split);

// Utils
long ft_atol(const char *str);
int find_min_position(t_push_swap *stack);

// Lists
int push_swap_lstsize(t_push_swap *lst);
t_push_swap *push_swap__listlast(t_push_swap *lst);
t_push_swap	*push_swap_lstlast(t_push_swap *head);

// Algorithm
void run_algorithm(t_push_swap **stack_a, t_push_swap **stack_b);
void radix(t_push_swap **stack_a, t_push_swap **stack_b);

// Debugging
void print_stacks(t_push_swap **stack_a, t_push_swap **stack_b);
void print_stack(t_push_swap **stack_a);

#endif