/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:00:07 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/27 14:21:30 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operationtest(t_node **stack_a, t_node **stack_b)
{
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	// rotate(stack_a, 1);
	// rotate(stack_b, 1);
	// reverse_rotate(stack_b, 1);
	// reverse_rotate(stack_a, 1);
	// swap(stack_b, 1);
	// swap(stack_a, 1);
	// swap_both_stacks(stack_a, stack_b);
	// rotate_both_stacks(stack_a, stack_b);
	// reverse_rotate_both_stacks(stack_a, stack_b);
	// push_pop(stack_a, stack_b);
	// push_pop(stack_a, stack_b);
	// push_pop(stack_a, stack_b);
	// push_pop(stack_a, stack_b);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("Number: %d | Index: %d | Chunk %d\n", stack->nbr, stack->final_index ,stack->chunk);
		stack = stack->next;
	}
}
