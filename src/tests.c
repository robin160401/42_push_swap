/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:00:07 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 13:49:32 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operationtest(t_node **stack_a, t_node **stack_b)
{
	push_pop(stack_b, stack_a, BOTTOM_B);
	push_pop(stack_b, stack_a, TOP_B);
	push_pop(stack_b, stack_a, TOP_B);
	push_pop(stack_b, stack_a, TOP_B);
	reverse_rotate(stack_a, 1, TOP_A);
	rotate(stack_b, 1, BOTTOM_B);
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
	if (!stack)
		printf("No stack found!!\n");
	while (stack)
	{
		printf("Number: %d | Index: %d | Chunk %d\n", stack->nbr, stack->final_index, stack->location);
		stack = stack->next;
	}
}
