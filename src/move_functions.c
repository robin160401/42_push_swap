/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:28:27 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/30 20:56:04 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_from_top_a(t_node **stack_a, t_node **stack_b, t_location to)
{
	if (to == TOP_B)
		push_b(stack_b, stack_a, to);
	else if (to == BOTTOM_A)
		rotate_a(stack_a, to);
	else if (to == BOTTOM_B)
	{
		push_b(stack_b, stack_a, to);
		rotate_b(stack_b, to);
	}
}

void	move_from_top_b(t_node **stack_a, t_node **stack_b, t_location to)
{
	if (to == TOP_A)
		push_a(stack_a, stack_b, TOP_A);
	else if (to == BOTTOM_B)
		rotate_b(stack_b, to);
	else if (to == BOTTOM_A)
	{
		push_a(stack_a, stack_b, to);
		rotate_a(stack_a, to);
	}
}

void	move_from_bot_a(t_node **stack_a, t_node **stack_b, t_location to)
{
	if (to == TOP_A)
		reverse_rotate_a(stack_a, TOP_A);
	else if (to == TOP_B)
	{
		reverse_rotate_a(stack_a, TOP_B);
		push_b(stack_b, stack_a, TOP_B);
	}
	else if (to == BOTTOM_B)
	{
		reverse_rotate_a(stack_a, BOTTOM_B);
		push_b(stack_b, stack_a, BOTTOM_B);
		rotate_b(stack_b, to);
	}
}

void	move_from_bot_b(t_node **stack_a, t_node **stack_b, t_location to)
{
	if (to == TOP_B)
		reverse_rotate_b(stack_b, to);
	else if (to == TOP_A)
	{
		reverse_rotate_b(stack_b, TOP_A);
		push_a(stack_a, stack_b, TOP_A);
	}
	else if (to == BOTTOM_A)
	{
		reverse_rotate_b(stack_b, to);
		push_a(stack_a, stack_b, to);
		rotate_a(stack_a, to);
	}
}

int	move_from_to(t_node **stack_a, t_node **stack_b,
					t_location from, t_location to)
{
	if (from == TOP_A)
		move_from_top_a(stack_a, stack_b, to);
	else if (from == TOP_B)
		move_from_top_b(stack_a, stack_b, to);
	else if (from == BOTTOM_A)
		move_from_bot_a(stack_a, stack_b, to);
	else if (from == BOTTOM_B)
		move_from_bot_b(stack_a, stack_b, to);
	return (1);
}
