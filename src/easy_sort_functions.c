/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:54:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 18:24:47 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_top_b(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	swap(stack_b, 1);
	push_pop(stack_a, stack_b, to_sort->location);
	if ((*stack_b)->final_index == (*stack_a)->chunk + 1)
	{
		push_pop(stack_a, stack_b, to_sort->location);
		to_sort->size--;
	}
}

void	handle_bot_a(t_node **stack_a, t_chunk *to_sort)
{
	reverse_rotate(stack_a, 1, to_sort->location);
	reverse_rotate(stack_a, 1, to_sort->location);
	swap(stack_a, 1);
	if ((*stack_a)->final_index == (*stack_a)->next->final_index + 1)
		to_sort--;
	else
		rotate(stack_a, 1, to_sort->location);
}

void	handle_bot_b(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	reverse_rotate(stack_b, 1, to_sort->location);
	reverse_rotate(stack_b, 1, to_sort->location);
	push_pop(stack_a, stack_b, to_sort->location);
	if ((*stack_b)->final_index == (*stack_a)->final_index + 1)
	{
		push_pop(stack_a, stack_b, to_sort->location);
		to_sort--;
	}
	else
		rotate(stack_b, 1, to_sort->location);
}

void	easy_sort_second(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == TOP_B)
		handle_top_b(stack_a, stack_b, to_sort);
	else if (to_sort->location == BOTTOM_A)
		handle_bot_a(stack_a, to_sort);
	else if (to_sort->location == BOTTOM_B)
		handle_bot_b(stack_a, stack_b, to_sort);
	to_sort->size--;
}
