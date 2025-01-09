/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:28:00 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/09 17:11:35 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Stack: %d | Index: %d\n", stack->nbr, stack->index);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 2)
		create_stack_a_from_string(&stack_a, argv);
	else
		create_stack_a(&stack_a, argc, argv);
	set_all_indexes(stack_a);
	print_stack(stack_a);
	return (0);
}
