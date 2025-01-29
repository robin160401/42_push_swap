/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:12:29 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 18:18:57 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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



int	highest_chunk_index(t_node *stack_a, t_node *stack_b, t_chunk *chunk)
{
	int	highest;

	highest = INT_MIN;
	if (chunk->location == TOP_A || chunk->location == BOTTOM_A)
	{
		while (stack_a)
		{
			if (stack_a->location == chunk->location
				&& stack_a->final_index > highest)
				highest = stack_a->final_index;
			stack_a = stack_a->next;
		}
		return (highest);
	}
	else
	{
		while (stack_b)
		{
			if (stack_b->location == chunk->location
				&& stack_b->final_index > highest)
				highest = stack_b->final_index;
			stack_b = stack_b->next;
		}
	}
	return (highest);
}
