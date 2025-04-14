/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:48:16 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/09 22:04:36 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/push_swap.h"

void init_stack(t_stack *stack)
{
    stack->top = NULL;  
    stack->size = 0;  
}

void swap(t_stack *stack) {
   
    if (stack->size > 1) {  
        t_node *temp;
            // 1 , 2 , 3 
        temp = stack->top; //1 -> 3
        stack->top = temp->next;// ahora stack-> top es 2  
        temp->next = stack->top->next;  //1 -> 3
        stack->top->next = temp;// aqui lo posiciona 2,1,3.
    }

}
//Función para mover un valor de stack_b a stack_a
void move_push(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->size > 0)
    {
        t_node *temp = stack_b->top;

        // Actualiza el top de b
        stack_b->top = temp->next;
        stack_b->size--;

        // Inserta en el top de a
        temp->next = stack_a->top;
        stack_a->top = temp;
        stack_a->size++;
    }
}

void move_rotate(t_stack *stack){
    /*Antes:
top → [1] → [2] → [3] → NULL

Después de rotate:
top → [2] → [3] → [1] → NULL */
    if ((stack->size > 1))
    {   
         
        //aqui cogemos el que este en el top.[1]
        t_node *temp = stack->top;
        //actualizamos el valor de top[2]
        stack->top =temp->next;
        
        //creeo un nodo ocasional para gestionar.
        t_node *current = temp->next;
        //recorremos hasta que sea null
        while (current->next != NULL) {
            //modifica la posicion de next en  la ultima posicion de los elementos.Antes de null
            current = current->next;
        }
        current->next = temp;
        //Aqui lo que hacemos es asegurarnos que despues de temp esta null;
        temp->next = NULL;
        
    }
}
    
void move_rotate_reverse(t_stack *stack){
 
        
        if ((stack->size > 1))
        {
            t_node *current = stack->top->next;

            while((current->next->next != NULL))
            {
                //penultimo
                current = current->next;
            }
            t_node *temp =current->next;;
            current->next = NULL;// reniciamos el valor
            temp->next = stack->top;
            stack->top = temp;
        
            
        }
        
    }
