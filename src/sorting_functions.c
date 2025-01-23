/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:35 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/23 14:20:49 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_3_numbers(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next || !(*stack)->next->next)
		return (-1);
	if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->nbr > (*stack)->next->next->nbr
		&& (*stack)->next->nbr < (*stack)->next->next->nbr)
		rotate(stack, 1);
	else if ((*stack)->nbr < (*stack)->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr
		&& (*stack)->nbr < (*stack)->next->next->nbr)
	{
		reverse_rotate(stack, 1);
		swap(stack);
	}
	else if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr)
	{
		swap(stack);
		reverse_rotate(stack, 1);
	}
	else if ((*stack)->nbr < (*stack)->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr
		&& (*stack)->nbr > (*stack)->next->next->nbr)
		reverse_rotate(stack, 1);
	else if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->next->nbr < (*stack)->next->next->nbr
		&& (*stack)->nbr < (*stack)->next->next->nbr)
		swap(stack);
	return (1);
}

int	sort_all_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_stacksize(*stack_a);
	if (!is_sorted(stack_a) && stack_size-- > 3)
		push_pop(stack_b, stack_a);
	if (!is_sorted(stack_a) && stack_size-- > 3)
		push_pop(stack_b, stack_a);
	while (!is_sorted(stack_a) && stack_size-- > 3)
	{
		set_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_3_numbers(stack_a);
	while (*stack_b)
	{
		set_stack_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_current_indexes(*stack_a);
	low_to_top(stack_a);
	return (1);
}
