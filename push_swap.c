/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 11:12:35 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("Stack Index: %d| Number: %d| Chunk: %d\n", stack->final_index, stack->nbr, stack->chunk);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 2)
	{
		if (create_stack_a_from_string(&stack_a, argv) == -1)
			return (-1);
	}
	else
	{
		if (create_stack_a(&stack_a, argc, argv) == -1)
			return (-1);
	}
	if (ft_stacksize(stack_a) <= 5)
		sort_first_numbers(&stack_a, &stack_b);
	else
	{
		set_all_indexes(stack_a);
		sort_chunks(&stack_a, &stack_b);
	}
	// printf("Stack A:\n");
	// print_stack(stack_a);
	// printf("____________________________________\n");
	// printf("Stack B:\n");
	// print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
