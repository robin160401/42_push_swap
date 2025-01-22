/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:12:29 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/22 14:09:06 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_lowest_opeartions(t_stack *stack)
{
	int		lowest_operations;
	t_stack	*temp;

	if (!stack)
		return ;
	lowest_operations = INT_MAX;
	while (stack)
	{
		if (stack->operations < lowest_operations)
		{
			lowest_operations = stack->lowest_operations;
			temp = stack;
		}
		stack = stack->next;
	}
	temp->lowest_operations = 1;
}

t_stack	*get_lowest_ops(t_stack *stack)
{
	while (stack)
	{
		if (stack->lowest_operations)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_stack(t_stack **stack, t_stack *top)
{
	while (*stack != top)
	{
		if (top->over_median)
			rotate(stack);
		else
			reverse_rotate(stack);
	}
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lowest_ops;

	lowest_ops = get_lowest_ops(*stack_a);
	if (lowest_ops->over_median && lowest_ops->target_node->over_median)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr", 2);
	}
	else if (!(lowest_ops->over_median)
		&& !(lowest_ops->target_node->over_median))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr", 3);
	}
	rotate_stack(stack_a, lowest_ops);
	rotate_stack(stack_b, lowest_ops->target_node);
	push_pop(stack_b, stack_a);
}


void	set_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	set_current_indexes(stack_a);
	set_current_indexes(stack_b);
	set_target_a(stack_a, stack_b);
	find_less_operations(stack_a, stack_b);
	set_lowest_opeartions(stack_a);
}
