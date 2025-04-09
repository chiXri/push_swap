/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:43:08 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/09 19:53:19 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node {
    int value;
    int index;
    struct s_node *next;
} t_node;


typedef struct s_stack {
    t_node *top;            
    int size;
} t_stack;

void push_stack(t_stack *stack, int value);
int process_input(int argc, char **argv, t_stack *stack);
int check_duplicate(t_stack *stack, int value);
void init_stack(t_stack *stack);
void swap(t_stack *stack);
void move_push(t_stack *stack_a,t_stack *stack_b);
void move_rotate(t_stack *stack);
void move_rotate_reverse(t_stack *stack);
void sort_three(t_stack *stack);
void sort_five(t_stack *a,t_stack *b);
int find_min_position(t_stack *stack);
void push_min_to_b(t_stack *a, t_stack *b);
int *stack_to_array(t_stack *a);
void assign_indexes(t_stack *a);
void sort_array(int* arr, int size);
int get_max_bits(int *arr, int size);
void radix_pass(int *arr, int size, int bit);
void sort_large(t_stack *a,t_stack *b);
int find_max_position(t_stack *b);
    //Instrucctions
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a,t_stack *b);
//utils
int	ft_isdigit(int c);
int	is_valid_number(const char *str);
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void init_stack(t_stack *stack);
void print_stack(t_stack *stack);

#endif