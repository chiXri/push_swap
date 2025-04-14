/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:39:06 by m.chiri           #+#    #+#             */
/*   Updated: 2025/04/14 19:42:29 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"
int main(int argc, char **argv)
{
	t_stack a, b;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return 0;

	init_stack(&a);
	init_stack(&b);

	if (!process_input(argc - 1, argv + 1, &a))
	{
		free_stack(&a);
		return 1;
	}

	if (a.size <= 1 || is_sorted(&a)) 
	{
		free_stack(&a);
		return 0;
	}


	assign_indexes(&a);
	if (a.size <= 6)
		sort_small(&a, &b);
	else
		sort_large(&a, &b);

	free_stack(&a);
	free_stack(&b);
	return 0;
}
