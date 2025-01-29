/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:26:46 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 18:22:56 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_top_a(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort, int highest)
{
	if ((*stack_a)->final_index == highest)
	{
		swap(stack_a, 1);
		rotate(stack_a, 1, TOP_A);
		swap(stack_a, 1);
		reverse_rotate(stack_a, 1, TOP_A);
	}
	else if ((*stack_a)->next->final_index == highest)
	{
		rotate(stack_a, 1, TOP_A);
		swap(stack_a, 1);
		reverse_rotate(stack_a, 1, TOP_A);
	}
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_top_b(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort, int highest)
{
	push_pop(stack_a, stack_b, TOP_A);
	if ((*stack_b)->final_index == highest)
	{
		push_pop(stack_a, stack_b, TOP_A);
		swap(stack_a, 1);
	}
	else if ((*stack_b)->next->final_index == highest)
	{
		swap(stack_b, 1);
		push_pop(stack_a, stack_b, TOP_A);
		swap(stack_a, 1);
	}
	else
		push_pop(stack_a, stack_b, TOP_A);
	push_pop(stack_a, stack_b, TOP_A);
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_bot_a(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort, int highest)
{
	reverse_rotate(stack_a, 1, TOP_A);
	reverse_rotate(stack_a, 1, TOP_A);
	if ((*stack_a)->final_index == highest)
	{
		swap(stack_a, 1);
		reverse_rotate(stack_a, 1, TOP_A);
	}
	else if ((*stack_a)->next->final_index == highest)
	{
		reverse_rotate(stack_a, 1, TOP_A);
	}
	else
	{
		push_pop(stack_b, stack_a, TOP_A);
		reverse_rotate(stack_a, 1, TOP_A);
		swap(stack_a, 1);
		push_pop(stack_a, stack_b, TOP_A);
	}
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_bot_b(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort, int highest)
{
	reverse_rotate(stack_b, 1, TOP_B);
	reverse_rotate(stack_b, 1, TOP_B);
	if ((*stack_b)->final_index == highest)
	{
		push_pop(stack_a, stack_b, TOP_B);
		reverse_rotate(stack_b, 1, TOP_B);
	}
	else if ((*stack_b)->next->final_index == highest)
	{
		swap(stack_b, 1);
		push_pop(stack_a, stack_b, TOP_B);
		reverse_rotate(stack_b, 1, TOP_B);
	}
	else
	{
		reverse_rotate(stack_b, 1, TOP_B);
		push_pop(stack_a, stack_b, TOP_B);
	}
	to_sort->location = TOP_B;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	int	highest;

	highest = highest_chunk_index(*stack_a, *stack_b, to_sort);
	if (to_sort->location == TOP_A)
	{
		sort_three_top_a(stack_a, stack_b, to_sort, highest);
		// printf("sort to A Top\n");
	}
	else if (to_sort->location == BOTTOM_A)
	{
		sort_three_bot_a(stack_a, stack_b, to_sort, highest);
		// printf("sort to A Bot\n");
	}
	else if (to_sort->location == TOP_B)
	{
		sort_three_top_b(stack_a, stack_b, to_sort, highest);
		// printf("sort to B Top\n");
	}
	else if (to_sort->location == BOTTOM_B)
	{
		sort_three_bot_b(stack_a, stack_b, to_sort, highest);
		// printf("sort to B Bot\n");
	}
}
