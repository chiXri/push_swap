/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:40:29 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/09 17:33:51 by m.chiri          ###   ########.fr       */
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
    sort_array(arr, a->size);
    int i ;

    t_node *current = a->top;
 
    while(current != NULL){
        i = 0;
            while (i < a->size)
            {
                    if (arr[i] == current->value){
                        current->index = i;
                        printf("Valor: %d → Índice: %d\n", current->value, current->index);
                        break;
                       
                    }   
                i++;
            }
            current = current->next; 
            
        }
      
   
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
