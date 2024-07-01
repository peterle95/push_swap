/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:51:41 by pmolzer           #+#    #+#             */
/*   Updated: 2024/06/20 17:51:41 by pmolzer          ###   ########.fr       */
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


// Rotation
int ra(t_push_swap **stack_a);
int rb(t_push_swap **stack_b);
int rr(t_push_swap **stack_a, t_push_swap **stack_b);

// Parsing / Checking Input
int ft_check_input(int ac, char **av);

#endif