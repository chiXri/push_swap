/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:17:49 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/08 19:19:41 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_three(t_stack *stack){

    int first;
    int second;
    int third;

    first = stack->top->value;//10
    second = stack->top->next->value;//50
    third = stack->top->next->next->value;//100

    if (first < second && second < third){
        
    }
    else if (first > second && second < third && first < third){
            sa(stack);}
    else if (first > second && second > third){
            sa(stack);
            rra(stack);
    }
    else if (first > second && second < third && first > third){
            ra(stack);}
    else if (first < second && second > third && first < third){
            sa(stack);
            ra(stack);}
    else if (first < second && second > third && first > third){
            rra(stack);}
}
int find_min_position(t_stack *stack){

    t_node *current;
    
    current = stack->top;
    int min = current->value;
    int min_pos = 0;
    int i = 0;
  
    while(current!= NULL)
    {
          if(current->value < min )
          {
                min = current->value;
                min_pos = i;   
          }
          i++;
          current = current->next;

    }
    return min_pos;
}
void push_min_to_b(t_stack *a, t_stack *b)
{
	int min_pos;
	int i;

	min_pos = find_min_position(a);
	i = 0;
	if (min_pos <= a->size / 2)
	{
		while (i++ < min_pos)
			ra(a);
	}
	else
	{
		i = 0;
		while (i++ < a->size - min_pos)
			rra(a);
	}
	pb(a, b);
}
void sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	if (b->top && b->top->next && b->top->value < b->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

