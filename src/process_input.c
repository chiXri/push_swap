/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:13:16 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/15 20:57:10 by m.chiri          ###   ########.fr       */
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
    int value;
    int count = 0;

    if (!split || !split[0]) // 🚨 Línea nueva: detecta split vacío
    {
        free_split(split);
        return 0;
    }

    while (split[count])
        count++;

    while (--count >= 0)
    {
        if (!ft_atoi(split[count], &value) || check_duplicate(stack, value))
        {
            free_split(split);
            return 0;
        }
        push_stack(stack, value);
    }

    free_split(split);
    return 1;
}

int process_input(int argc, char **argv, t_stack *stack)
{
    while (--argc >= 0)
    {
        if (!process_args(argv[argc], stack))
        {
            free_stack(stack);
            write(2, "Error\n", 6);
            return 0;
        }
    }
    return 1;
}
