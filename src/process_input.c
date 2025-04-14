/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:13:16 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/14 19:30:13 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(t_stack *stack, int value)
{
	t_node	*current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}
int process_args(char *arg, t_stack *stack)
{
    char **split = ft_split(arg, ' ');
    int i = 0;
    int value;

    if (!split)
        return 0;

    while (split[i])
    {
        if (!ft_atoi(split[i], &value) || check_duplicate(stack, value))
        {
            free_split(split);
            return 0; 
        }
        push_stack(stack, value);
        i++;
    }
    free_split(split);
    return 1;
}

int process_input(int argc, char **argv, t_stack *stack)
{
    int i = 0;

    while (i < argc)
    {
        if (!process_args(argv[i], stack))
        {
            free_stack(stack);
            write(2, "Error\n", 6); 
            return 0;
        }
        i++;
    }
    return 1;
}
