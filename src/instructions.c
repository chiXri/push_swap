/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:48:39 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/17 17:59:43 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack *a) { swap(a); write(1, "sa\n", 3); }
void sb(t_stack *b) { swap(b); write(1, "sb\n", 3); }
void ss(t_stack *a,t_stack *b) { swap(a);swap(b); write(1, "ss\n", 3); }

void pa(t_stack *a, t_stack *b) { move_push(a, b); write(1, "pa\n", 3); }
void pb(t_stack *a, t_stack *b) { move_push(b, a); write(1, "pb\n", 3); }

void ra(t_stack *a) { move_rotate(a); write(1, "ra\n", 3); }
void rb(t_stack *b) { move_rotate(b); write(1, "rb\n", 3); }
void rr(t_stack *a,t_stack *b) { move_rotate(a);move_rotate(b); write(1, "rr\n", 3); }

void rra(t_stack *a) { move_rotate_reverse(a); write(1, "rra\n", 4); }
void rrb(t_stack *b) { move_rotate_reverse(b); write(1, "rrb\n", 4); }
void rrr(t_stack *a,t_stack *b) { move_rotate_reverse(a);move_rotate_reverse(b); write(1, "rrr\n", 4); }

