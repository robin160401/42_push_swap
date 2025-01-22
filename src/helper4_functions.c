/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:51 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/22 14:39:14 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_lowest_index(t_stack *stack)
{
	int		low;
	t_stack	*temp;

	if (stack == NULL)
		return (0);
	low = INT_MAX;
	temp = stack;
	while (stack != NULL)
	{
		if ((stack->index) < low)
			low = stack->index;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->index == low)
			return (temp);

		temp = temp->next;
	}
	return (NULL);
}

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	int		best;

	while (stack_b)
	{
		best = INT_MAX;
		temp = stack_a;
		while (temp)
		{
			if (temp->nbr < stack_b->nbr && temp->nbr < best)
			{
				best = temp->nbr;
				target = temp;
			}
			temp = temp->next;
		}
		if (best == INT_MAX)
			stack_b->target_node = get_lowest_index(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	set_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	set_current_indexes(stack_a);
	set_current_indexes(stack_b);
	set_target_b(stack_a, stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, (*stack_b)->target_node);
	push_pop(stack_a, stack_b);
}

void	low_to_top(t_stack **stack_a)
{
	while ((*stack_a)->nbr != get_lowest_index(*stack_a)->nbr)
	{
		if (get_lowest_index(*stack_a)->over_median)
			rotate(stack_a);
		else
			reverse_rotate(stack_a);
	}
}
