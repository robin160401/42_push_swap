/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:26:46 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 11:11:25 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_top_a(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->final_index;
	b = (*stack_a)->next->final_index;
	c = (*stack_a)->next->next->final_index;
	// printf("I sort Stack a Top");
	// printf("I sorted: %d and %d and %d\n", a, b, c);
	if (a > b && a > c)
	{
		swap_a(stack_a);
		rotate_a(stack_a, TOP_A);
		swap_a(stack_a);
		reverse_rotate_a(stack_a, TOP_A);
	}
	else if (a < b && a > c)
	{
		rotate_a(stack_a, TOP_A);
		swap_a(stack_a);
		reverse_rotate_a(stack_a, TOP_A);
	}
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_top_b(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_b)->final_index;
	b = (*stack_b)->next->final_index;
	c = (*stack_b)->next->next->final_index;
	// printf("I sort stack b Top: %d\n", (*stack_a)->final_index);
	push_a(stack_a, stack_b, TOP_A);
	if (a > b && a > c)
	{
		push_a(stack_a, stack_b, TOP_A);
		swap_a(stack_a);
	}
	else if (a < b && a > c)
	{
		swap_b(stack_b);
		push_a(stack_a, stack_b, TOP_A);
		swap_a(stack_a);
	}
	else
		push_a(stack_a, stack_b, TOP_A);
	push_a(stack_a, stack_b, TOP_A);
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_bot_a(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort)
{
	int	a;
	int	b;
	int	c;

	c = (*stack_a)->next->next->final_index;
	b = (*stack_a)->next->final_index;
	a = (*stack_a)->final_index;
	// printf("I sort stack a Bot: %d\n", (*stack_a)->final_index);
	// printf("I sorted: %d and %d and %d\n", a, b, c);
	reverse_rotate_a(stack_a, TOP_A);
	reverse_rotate_a(stack_a, TOP_A);
	if (a > b && a > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a, TOP_A);
		// printf("HII1\n\n\n");
	}
	else if (a < b && a < c)
	{
		reverse_rotate_a(stack_a, TOP_A);
		// printf("HII2\n\n\n");
	}
	else
	{
		push_b(stack_b, stack_a, TOP_A);
		reverse_rotate_a(stack_a, TOP_A);
		swap_a(stack_a);
		push_a(stack_a, stack_b, TOP_A);
		// printf("HII3\n\n\n");
	}
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_bot_b(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_b)->final_index;
	b = (*stack_b)->next->final_index;
	c = (*stack_b)->next->next->final_index;
	// printf("I sort stack b bot: %d\n", (*stack_b)->final_index);
	// printf("I sorted: %d and %d and %d\n", a, b, c);
	reverse_rotate_b(stack_b, TOP_B);
	reverse_rotate_b(stack_b, TOP_B);
	if (a > b && a > c)
	{
		push_a(stack_a, stack_b, TOP_B);
		reverse_rotate_b(stack_b, TOP_B);
	}
	else if (a < b && a < c)
	{
		swap_b(stack_b);
		push_a(stack_a, stack_b, TOP_B);
		reverse_rotate_b(stack_b, TOP_B);
	}
	else
	{
		reverse_rotate_b(stack_b, TOP_B);
		push_a(stack_a, stack_b, TOP_B);
	}
	to_sort->location = TOP_B;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == TOP_A)
		sort_three_top_a(stack_a, stack_b, to_sort);
	else if (to_sort->location == BOTTOM_A)
		sort_three_bot_a(stack_a, stack_b, to_sort);
	else if (to_sort->location == TOP_B)
		sort_three_top_b(stack_a, stack_b, to_sort);
	else if (to_sort->location == BOTTOM_B)
		sort_three_bot_b(stack_a, stack_b, to_sort);
}
