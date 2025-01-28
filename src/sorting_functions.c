/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:35 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/28 15:08:02 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_numbers(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first > second && first > third && second < third)
		rotate(stack, 1, TOP_A);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate(stack, 1, TOP_A);
		swap(stack, 1);
	}
	else if (first > second && second > third)
	{
		swap(stack, 1);
		reverse_rotate(stack, 1, TOP_A);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, 1, TOP_A);
	else if (first > second && second < third && first < third)
		swap(stack, 1);
}

void	sort_5_numbers(t_node **stack_a, t_node **stack_b)
{
	set_all_current_indexes(*stack_a);
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->current_index == 3 || (*stack_a)->current_index == 4)
			push_pop(stack_b, stack_a, TOP_A);
		else
			rotate(stack_a, 1, TOP_A);
	}
	sort_3_numbers(stack_a);
	if ((*stack_b)->current_index > (*stack_b)->next->current_index)
		swap(stack_b, 1);
	sort_3_numbers(stack_a);
	push_pop(stack_a, stack_b, TOP_A);
	push_pop(stack_a, stack_b, TOP_A);
}

void	sort_chunks(t_node **stack_a, t_node **stack_b)
{
	t_chunk	chunk_all;

	chunk_all.location = TOP_A;
	chunk_all.size = ft_stacksize(*stack_a);
	rec_sort_chunk(stack_a, stack_b, &chunk_all);
}

void	rec_sort_chunk(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	// t_split	dest;

	set_to_sort_location(stack_a, stack_b, to_sort);
	
}

void	sort_all_nbrs(t_node **stack_a, t_node **stack_b)
{
	set_all_indexes(*stack_a);
	sort_chunks(stack_a, stack_b);
	operationtest(stack_a, stack_b);
}
