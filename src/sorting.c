/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:17:49 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/22 19:07:52 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_small(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return;

	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
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

void sort_five(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return;
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	if (b->top && b->top->next && b->top->value < b->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

int find_min_position(t_stack *stack)
{
	t_node *current = stack->top;
	int min = current->value;
	int min_pos = 0;
	int i = 0;

	while (current)
	{
		if (current->value < min)
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
	int min_pos = find_min_position(a);
	int i = 0;

	if (min_pos <= a->size / 2)
		while (i++ < min_pos)
			ra(a);
	else
		while (i++ < a->size - min_pos)
			rra(a);
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
void sort_large(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return;

	int size = a->size;
	int chunk_count = (size <= 100) ? 6 : 11;
	int chunk_size = (size + chunk_count - 1) / chunk_count;
	int i = 0;

	while (i < chunk_count)
	{
		int start = i * chunk_size;
		int end = (i == chunk_count - 1) ? size - 1 : start + chunk_size - 1;
		int pushed = 0;
		int scans = 0;

		while (pushed < chunk_size && a->size > 0 && scans < size * 2)
		{
			int pos = 0;
			t_node *tmp = a->top;

			while (tmp && !(tmp->index >= start && tmp->index <= end))
			{
				tmp = tmp->next;
				pos++;
			}

			if (!tmp)
				break;

			if (pos <= a->size / 2)
			{
				while (pos-- > 0)
					ra(a);
			}
			else
			{
				while (pos++ < a->size)
					rra(a);
			}

			int pushed_index = a->top->index;
			pb(a, b);

			// 🔧 Mejora: rota B solo si está en el tercio bajo del chunk
			if (pushed_index < (start + end) / 2)
				rb(b);

			pushed++;
			scans++;
		}
		i++;
	}

	// Volver desde B a A
	while (b->size > 0)
	{
		int max_pos = find_max_position(b);
		if (max_pos <= b->size / 2)
			while (max_pos-- > 0)
				rb(b);
		else
			while (max_pos++ < b->size)
				rrb(b);

		pa(a, b);
	}
}
