
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:59 by m.chiri           #+#    #+#             */
/*   Updated: 2025/03/25 19:41:24 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int check_duplicate(t_stack *stack, int value)
{
    t_node *current;

    current = stack->top;
    
    while(current != NULL) {
        if(current->value == value) {
            return 1;  // Duplicado encontrado
        }
        current = current->next;
    }
    return 0;  // No duplicado
}


int process_input(int argc, char **argv, t_stack *stack)
{

    int num;
    int i;
    
    i = 1;
    
    while (i < argc)
    {   
        num = ft_atoi(argv[i]);
        
        if (!is_valid_number(argv[i]))
        {
            write(2,"Error1 \n",6);
            return 0;
        }
        if (check_duplicate(stack, num)) {
            printf("Duplicate detected: %d\n", num); // Depuración
            write(2, "Error numero duplicado\n", 24);
            return 0;
        }
            

        push_stack(stack,num);
        i++;
        
    }
    
    return(1);
}