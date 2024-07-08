#include "../../includes/push_swap.h"

void assign_indices(t_push_swap **stack)
{
    int index = 0;
    t_push_swap *current = *stack;
    
    while (current)
    {
        current->index = index;
        index++;
        current = current->next;
    }
}

void add_to_stack(t_push_swap **stack, t_push_swap *new_node)
{
    t_push_swap *last;

    if (*stack == NULL)
    {
        *stack = new_node;
        return;
    }
    last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

t_push_swap *create_new_node(int value)
{
    t_push_swap *new_node;

    new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
    if (new_node == NULL)
        return NULL;
    new_node->value = value;
    new_node->index = -1; // Initialize index as -1 or any default value
    new_node->next = NULL;
    return new_node;
}

void init_stack(t_push_swap ***stack_a, t_push_swap ***stack_b, int ac, char **av)
{
    int i;
    t_push_swap *new_node;

    i = 1;  // Start from 1 to skip the program name (av[0])
    while (i < ac)
    {
        new_node = create_new_node(ft_atoi(av[i]));
        if (new_node == NULL)
        {
            // Handle memory allocation error
            ft_putendl_fd("Error: Memory allocation failed", 2);
            // Free previously allocated nodes
            while (*stack_a && **stack_a)
            {
                t_push_swap *temp = **stack_a;
                **stack_a = (**stack_a)->next;
                free(temp);
            }
            free(*stack_a);
            free(*stack_b);
            exit(1);
        }
        add_to_stack(*stack_a, new_node);
        i++;
    }
    
    // Initialize stack_b as empty
    **stack_b = NULL;

    // Assign indices to elements in stack_a
    assign_indices(*stack_a);
}