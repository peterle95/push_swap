/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:41 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/23 13:55:05 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

// test
typedef struct s_push
{
	int				value;
	int				index;
	struct s_push	*next;
}				t_push;

// Rotation
int		ra(t_push **stack_a);
int		rb(t_push **stack_b);
int		rr(t_push **stack_a, t_push **stack_b);

// Reverse_rotation
int		rra(t_push **stack_a);
int		rrb(t_push **stack_b);
int		rrr(t_push **stack_a, t_push **stack_b);

// Push
int		pa(t_push **stack_a, t_push **stack_b);
int		pb(t_push **stack_a, t_push **stack_b);

// Swap
int		sa(t_push **stack_a);
int		sb(t_push **stack_b);
int		ss(t_push **stack_a, t_push **stack_b);

// Parsing / Checking Input
int		parse(int ac, char **av);

// Initialization
void	init_stack(t_push ***stack_a, int ac, char **av);
t_push	*create_new_node(int value);
void	add_to_stack(t_push **stack, t_push *new_node);
void	assign_indices(t_push **stack);

// Free 
void	free_stack(t_push **stack);
void	free_split(char **split);

// Utils
long	ft_atol(const char *str);
int		find_min_position(t_push *stack);
int		is_stack_sorted(t_push **stack);
int		is_number(char *str);

// Check_arg
int		check_duplicates(int ac, char **av);

// Lists
int		push_swap_lstsize(t_push *lst);
t_push	*push_swap__listlast(t_push *lst);
t_push	*push_swap_lstlast(t_push *head);

// Algorithm
void	run_algorithm(t_push **stack_a, t_push **stack_b);
void	radix(t_push **stack_a, t_push **stack_b);

#endif
