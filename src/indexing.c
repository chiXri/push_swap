/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:40:29 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/14 18:07:03 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *stack_to_array(t_stack *a)
{
    int *arr = calloc(a->size, sizeof(int));
    if (!arr)
    return NULL;

    int i = 0;
    t_node *current = a->top;

    while (current != NULL)
    {
        arr[i] = current->value;
        i++;
        current = current->next;
    }
    return arr;
}
void assign_indexes(t_stack *a)
{
    int *arr = stack_to_array(a);
    int *index_map;
    int size = a->size;
    t_node *current;

    sort_array(arr, size);
    index_map = (int *)malloc(sizeof(int) * size);
    if (!index_map)
        return ;

    for (int i = 0; i < size; i++)
        index_map[i] = arr[i];

    current = a->top;
    while (current)
    {
        int i = 0;
        while (i < size)
        {
            if (index_map[i] == current->value)
            {
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
    free(index_map);
    free(arr);
}

void sort_array(int *arr, int size)
{
	int max_bits = get_max_bits(arr, size);
	int bit = 0;

	while (bit < max_bits)
	{
		radix_pass(arr, size, bit);
		bit++;
	}
}
