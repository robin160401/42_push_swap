/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/02 15:04:38 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (create_stacks_check_errors(argv, &stack_a, argc) == -1)
		return (1);
	if (ft_stacksize(stack_a) <= 5)
		sort_first_numbers(&stack_a, &stack_b);
	else
	{
		set_all_indexes(stack_a);
		sort_chunks(&stack_a, &stack_b);
		free_stack(&stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
