/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 17:33:49 by rstumpf          ###   ########.fr       */
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

	if (create_stacks_throw_errors(argv, &stack_a, argc) == -1)
		return (1);
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
