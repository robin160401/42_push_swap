/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:26:46 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/02 11:38:34 by rstumpf          ###   ########.fr       */
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
	if (a > b && a > c)
	{
		swap_a(stack_a);
		rotate_a(stack_a, TOP_A);
		swap_a(stack_a);
		reverse_rotate_a(stack_a, TOP_A);
	}
	else if (b > a && b > c)
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

	push_a(stack_a, stack_b, TOP_A);
	a = (*stack_a)->final_index;
	b = (*stack_b)->final_index;
	c = (*stack_b)->next->final_index;
	if (a > b && a > c)
		push_a(stack_a, stack_b, TOP_A);
	else if (b > a && b > c)
	{
		push_a(stack_a, stack_b, TOP_A);
		swap_a(stack_a);
	}
	else
	{
		swap_b(stack_b);
		push_a(stack_a, stack_b, TOP_A);
		swap_a(stack_a);
	}
	push_a(stack_a, stack_b, TOP_A);
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_bot_a(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort)
{
	t_values	compare;

	reverse_rotate_a(stack_a, TOP_A);
	reverse_rotate_a(stack_a, TOP_A);
	compare.a = (*stack_a)->final_index;
	compare.b = (*stack_a)->next->final_index;
	compare.c = ft_stacklast(*stack_a)->final_index;
	if (compare.a > compare.b && compare.a > compare.c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a, TOP_A);
	}
	else if (compare.b > compare.a && compare.b > compare.c)
		reverse_rotate_a(stack_a, TOP_A);
	else
	{
		push_b(stack_b, stack_a, TOP_A);
		reverse_rotate_a(stack_a, TOP_A);
		swap_a(stack_a);
		push_a(stack_a, stack_b, TOP_A);
	}
	to_sort->location = TOP_A;
	to_sort->size--;
	sort_two(stack_a, stack_b, to_sort);
}

void	sort_three_bot_b(t_node **stack_a, t_node **stack_b,
					t_chunk *to_sort)
{
	t_values	compare;

	reverse_rotate_b(stack_b, TOP_B);
	reverse_rotate_b(stack_b, TOP_B);
	compare.a = (*stack_b)->final_index;
	compare.b = (*stack_b)->next->final_index;
	compare.c = ft_stacklast(*stack_b)->final_index;
	if (compare.a > compare.b && compare.a > compare.c)
	{
		push_a(stack_a, stack_b, TOP_B);
		reverse_rotate_b(stack_b, TOP_B);
	}
	else if (compare.b > compare.a && compare.b > compare.c)
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
	to_sort->size--;
	return (to_sort->location = TOP_B, sort_two(stack_a, stack_b, to_sort));
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
