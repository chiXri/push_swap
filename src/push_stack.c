/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:56:44 by m.chiri           #+#    #+#             */
/*   Updated: 2025/03/25 19:50:14 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"
//imaginemos una lista [2, 5, 8, 9, 12] y vamos añadir un valor mas al elemento [15].
void push_stack(t_stack *stack, int value) {
    // Crear un nuevo nodo
    t_node *new_node = (t_node *)ft_calloc(1, sizeof(t_node));

    if (!new_node)
        exit(1);  // Si no se puede asignar memoria, salir

    new_node->value = value; // Asignar el valor
    new_node->next = stack->top; // El nuevo nodo apunta al anterior top

    stack->top = new_node; // Ahora el nuevo nodo es el top de la pila

    stack->size++; // Aumentar el tamaño de la pila
}
