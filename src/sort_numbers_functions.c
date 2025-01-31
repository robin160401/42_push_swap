/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:35 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 11:03:15 by rstumpf          ###   ########.fr       */
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
		rotate_a(stack, to);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate_a(stack, to);
		swap_a(stack);
	}
	else if (first > second && second > third)
	{
		swap_a(stack);
		reverse_rotate_a(stack, to);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack, to);
	else if (first > second && second < third && first < third)
		swap_a(stack);
}

void	sort_5_numbers(t_node **stack_a, t_node **stack_b, t_location to)
{
	set_all_current_indexes(*stack_a);
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->current_index == 3 || (*stack_a)->current_index == 4)
			push_b(stack_b, stack_a, to);
		else
			rotate_a(stack_a, to);
	}
	sort_3_numbers(stack_a, to);
	if ((*stack_b)->current_index > (*stack_b)->next->current_index)
		swap_b(stack_b);
	sort_3_numbers(stack_a, to);
	push_a(stack_a, stack_b, to);
	push_a(stack_a, stack_b, to);
}

void	sort_one(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_A || to_sort->location == BOTTOM_B
		|| to_sort->location == TOP_B)
		{
			move_from_to(stack_a, stack_b, to_sort->location, TOP_A);
			// printf("I sorted %d\n", (*stack_a)->final_index);
		}
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
	if ((*stack_a)->final_index > (*stack_a)->next->final_index && to_sort)
	{
		// printf("I swapped %d with %d\n", (*stack_a)->final_index, (*stack_a)->next->final_index);
		swap_a(stack_a);
	}
	to_sort->size -= 2;
}
