/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 19:18:12 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 2)
		create_stack_a_from_string(&stack_a, argv);
	else
		create_stack_a(&stack_a, argc, argv);
	if (ft_stacksize(stack_a) <= 5)
		sort_first_numbers(&stack_a, &stack_b);
	else
	{
		set_all_indexes(stack_a);
		sort_chunks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
