/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:35 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 22:52:37 by rstumpf          ###   ########.fr       */
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
		rotate(stack, 1);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate(stack, 1);
		swap(stack, 1);
	}
	else if (first > second && second > third)
	{
		swap(stack, 1);
		reverse_rotate(stack, 1);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, 1);
	else if (first > second && second < third && first < third)
		swap(stack, 1);
}

void	sort_all_nbrs(t_node **stack_a, t_node **stack_b)
{
	set_all_indexes(*stack_a);
	set_all_chunks(*stack_a);
	push_chunks_to_b(stack_a, stack_b, 1);
	push_chunks_to_b(stack_a, stack_b, 2);
	push_chunks_to_b_last(stack_a, stack_b);
	sort_3_numbers(stack_a);
	push_b_to_a(stack_a, stack_b);

}
