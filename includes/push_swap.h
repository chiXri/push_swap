/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:43:08 by m.chiri           #+#    #+#             */
/*   Updated: 2025/03/25 19:46:02 by m.chiri          ###   ########.fr       */
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

int	ft_isdigit(int c);
int	is_valid_number(const char *str);
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);



#endif