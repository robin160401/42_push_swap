/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:51 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 17:21:42 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_to_sort_location(t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_B
		&& to_sort->size == 0)
		to_sort->location = TOP_B;
	if (to_sort->location == BOTTOM_A
		&& to_sort->size == 0)
		to_sort->location = TOP_A;
}

t_node	*get_first_chunk_node(t_node *stack, t_chunk *chunk)
{
	if (chunk->location == TOP_A || chunk->location == TOP_B)
		return (stack);
	else
		return (ft_stacklast(stack));
	return (NULL);
}

int	chunk_value(t_node *stack_a, t_node *stack_b, t_chunk *chunk, int n)
{
	t_node	*chunk_value;

	if (chunk->location == TOP_A || chunk->location == BOTTOM_A)
		chunk_value = get_first_chunk_node(stack_a, chunk);
	else
		chunk_value = get_first_chunk_node(stack_b, chunk);
	while (--n > 0)
		chunk_value = chunk_value->next;
	if (chunk_value)
		return (chunk_value->final_index);
	return (0);
}

int	chunk_index(t_node **stack_a, t_node **stack_b, t_chunk *chunk)
{
	t_node	*chunk_value;

	if (chunk->location == TOP_A || chunk->location == BOTTOM_A)
		chunk_value = get_first_chunk_node(*stack_a, chunk);
	else
		chunk_value = get_first_chunk_node(*stack_b, chunk);
	if (chunk_value)
		return (chunk_value->final_index);
	return (0);
}

int	current_chunk_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->location == BOTTOM_A || stack->location == BOTTOM_B)
			i++;
		stack = stack->next;
	}
	return (i);
}
