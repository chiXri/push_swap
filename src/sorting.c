/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:17:49 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/09 20:54:58 by m.chiri          ###   ########.fr       */
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
int get_index_at(t_stack *stack, int pos)
{
	t_node *current = stack->top;
	int i = 0;
	while (current != NULL)
	{
		if (i == pos)
			return current->index;
		current = current->next;
		i++;
	}
	return -1;
}

int find_max_position(t_stack *b)
{
	t_node *current = b->top;
	int max_index = current->index;
	int max_pos = 0;
	int i = 0;

	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return max_pos;
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
void sort_large(t_stack *a, t_stack *b)
{
	int size = a->size;
	int chunk_count = size <= 100 ? 6 : 14;
	int chunk_size = (size + chunk_count - 1) / chunk_count;
	int i = 0;

	while (i < chunk_count)
	{
		int start = i * chunk_size;
		int end = (i == chunk_count - 1) ? size - 1 : start + chunk_size - 1;

		int count = 0;
		int scanned = 0;
		int max_scans = a->size * 2;

		while (count < chunk_size && scanned < max_scans)
		{
			if (a->top->index >= start && a->top->index <= end)
			{
				pb(a, b);
				count++;
			}
			else
				ra(a);
			scanned++;
		}
		i++;
	}

	while (b->size > 0)
	{
		int max_pos = find_max_position(b);
		int max_index = get_index_at(b, max_pos);

		while (b->top->index != max_index)
		{
			if (max_pos <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}
