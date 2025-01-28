/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:35 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/28 15:26:57 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_numbers(t_node **stack, t_location to)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first > second && first > third && second < third)
		rotate(stack, 1, to);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate(stack, 1, to);
		swap(stack, 1);
	}
	else if (first > second && second > third)
	{
		swap(stack, 1);
		reverse_rotate(stack, 1, to);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, 1, to);
	else if (first > second && second < third && first < third)
		swap(stack, 1);
}

void	sort_5_numbers(t_node **stack_a, t_node **stack_b, t_location to)
{
	set_all_current_indexes(*stack_a);
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->current_index == 3 || (*stack_a)->current_index == 4)
			push_pop(stack_b, stack_a, to);
		else
			rotate(stack_a, 1, to);
	}
	sort_3_numbers(stack_a, to);
	if ((*stack_b)->current_index > (*stack_b)->next->current_index)
		swap(stack_b, 1);
	sort_3_numbers(stack_a, to);
	push_pop(stack_a, stack_b, to);
	push_pop(stack_a, stack_b, to);
}

void	sort_one(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_A || to_sort->location == BOTTOM_B
		|| to_sort->location == TOP_B)
		move_from_to(stack_a, stack_b, to_sort->location, TOP_A);
	to_sort->size--;
}

void	sort_two(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_A || to_sort->location == BOTTOM_B
		|| to_sort->location == TOP_B)
	{
		move_from_to(stack_a, stack_b, to_sort->location, TOP_A);
		move_from_to(stack_a, stack_b, to_sort->location, TOP_A);
	}
	if ((*stack_a)->final_index < (*stack_a)->next->final_index)
		swap(stack_a, 1);
	to_sort->size -= 2;
}
