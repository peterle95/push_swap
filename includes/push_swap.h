/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:41 by pmolzer           #+#    #+#             */
/*   Updated: 2024/07/08 16:15:26 by pmolzer          ###   ########.fr       */
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
#include<stdio.h>
#include<string.h>


// Rotation
int ra(t_push_swap **stack_a);
int rb(t_push_swap **stack_b);
int rr(t_push_swap **stack_a, t_push_swap **stack_b);

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

// Lists
int push_swap_lstsize(t_push_swap *lst);

#endif