/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:51 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/22 14:48:57 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack **stack)
{
	if (!(*stack))
		return (0);
	while ((*stack)->next)
	{
		if ((*stack)->nbr > (*stack)->next->nbr)
			return (1);
		*stack = (*stack)->next;
	}
	return (0);
}

int	set_current_indexes(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ft_stacksize(stack) / 2;
	if (!stack)
		return (0);
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->over_median = 1;
		else
			stack->over_median = 0;
		stack = stack->next;
		i++;
	}
	return (1);
}

t_stack	*get_highest_index(t_stack *stack)
{
	int		big;
	t_stack	*temp;

	if (stack == NULL)
		return (0);
	big = INT_MIN;
	temp = stack;
	while (stack != NULL)
	{
		if ((stack->index) > big)
			big = stack->index;
		stack = stack->next;
	}
	while (temp)
	{
		if (stack->index == big)
			return (temp);

		temp = temp->next;
	}
	return (NULL);
}

void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	int		best;

	while (stack_a)
	{
		best = INT_MIN;
		temp = stack_b;
		while (temp)
		{
			if (temp->nbr < stack_a->nbr && temp->nbr > best)
			{
				best = temp->nbr;
				target = temp;
			}
			temp = temp->next;
		}
		if (best == INT_MIN)
			stack_a->target_node = get_highest_index(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

void	find_less_operations(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	while (stack_a)
	{
		stack_a->operations = stack_a->current_index;
		if (!stack_a->over_median)
			stack_a->operations = size_a - stack_a->current_index;
		if (stack_a->target_node->over_median)
			stack_a->operations += stack_a->target_node->current_index;
		else
			stack_a->operations += size_b - stack_a->target_node->current_index;
		stack_a = stack_a->next;
	}
}
