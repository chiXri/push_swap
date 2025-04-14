/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:38:14 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/14 19:40:05 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(const char *str)
{
	int i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
void free_stack(t_stack *stack)
{
    t_node *temp;
    while (stack->top != NULL)
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->size = 0;
}
void free_split(char **split)
{
	int i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
int is_sorted(t_stack *stack)
{
	t_node *current = stack->top;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return 0;
		current = current->next;
	}
	return 1;
}
