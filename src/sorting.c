/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:17:49 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/14 23:50:13 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/push_swap.h"

void sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
	}
	else if (a->size == 3)
	{
		if (!is_sorted(a)) 
			sort_three(a);
	}
	else if (a->size == 4 || a->size == 5)
	{
		while (a->size > 3)
			push_min_to_b(a, b);
		sort_three(a);
		while (b->size > 0)
			pa(a, b);
	}
	else if (a->size == 6)
	{
		push_min_to_b(a, b);
		sort_small(a, b);
		pa(a, b);
	}
}
void sort_three(t_stack *stack)
{
	int a = stack->top->index;
	int b = stack->top->next->index;
	int c = stack->top->next->next->index;

	// Ya ordenado
	if (a < b && b < c)
		return;

	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
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
	while (current)
	{
		if (i == pos)
			return current->index;
		current = current->next;
		i++;
	}
	return -9999;
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
	int chunk_count = (a->size <= 100) ? 5 : 25;
	int chunk_size = (a->size + chunk_count - 1) / chunk_count;
	int i = 0;

	while (i < chunk_count)
	{
		int start = i * chunk_size;
		int end = (i == chunk_count - 1) ? a->size - 1 : start + chunk_size - 1;
		int pushed = 0;
		int total = a->size;

		while (pushed < chunk_size && total--)
		{
			if (a->top->index >= start && a->top->index <= end)
			{
				pb(a, b);
				pushed++;
			}
			else
				ra(a);
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
