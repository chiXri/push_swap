/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:56:44 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/07 16:35:21 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"
//imaginemos una lista [2, 5, 8, 9, 12] y vamos añadir un valor mas al elemento [15].
void push_stack(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));      
    if (!new_node)
        return;

    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    
    t_node *current = stack->top;
    while (current != NULL) {
        
        current = current->next;
    }
}
