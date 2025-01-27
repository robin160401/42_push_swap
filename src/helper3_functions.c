/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:12:29 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/27 14:23:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_fastest_rotate_b(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		median;
	int		size;
	t_node	*temp;

	i = 0;
	size = ft_stacksize(*stack_b);
	median = size / 2;
	temp = *stack_b;
	while (temp && temp->final_index - 1 != (*stack_a)->final_index)
	{
		i++;
		temp = temp->next;
	}
	if (i <= median)
		rotate(stack_b, 1);
	else
		reverse_rotate(stack_b, 1);
	return (i);
}

void	push_b_to_a(t_node **stack_a, t_node **stack_b)
{
	while (ft_stacksize(*stack_b))
	{
		if ((*stack_a)->final_index == (*stack_b)->final_index - 1)
			push_pop(stack_a, stack_b);
		else if ((*stack_a)->final_index == (*stack_b)->next->final_index)
		{
			swap(stack_b, 1);
			push_pop(stack_a, stack_b);
		}
		else
			find_fastest_rotate_b(stack_a, stack_b);
	}
}

void	set_current_index(t_node *stack)
{
	int			biggest;
	static int	i = 0;
	t_node		*temp;

	temp = stack;
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > biggest && stack->current_index == -1)
			biggest = stack->nbr;
		stack = stack->next;
	}
	stack = temp;
	while (stack)
	{
		if (biggest == stack->nbr)
			stack->current_index = i;
		stack = stack->next;
	}
	i++;
}

void	set_all_current_indexes(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (stack)
	{
		set_current_index(temp);
		stack = stack->next;
	}
}
