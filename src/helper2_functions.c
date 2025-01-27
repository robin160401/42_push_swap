/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:51 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/27 12:18:52 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_all_chunks(t_node *stack)
{
	int	chunk1;
	int	chunk2;
	int	chunk3;

	chunk3 = ft_stacksize(stack);
	chunk1 = chunk3 / 3;
	chunk2 = chunk1 * 2;
	while (stack)
	{
		if (stack->nbr < chunk1)
			stack->chunk = 1;
		else if (stack->nbr < chunk2)
			stack->chunk = 2;
		else
			stack->chunk = 3;
		stack = stack->next;
	}
}

int	find_fastest_rotate(t_node **stack, int chunk)
{
	int		i;
	int		median;
	int		size;
	t_node	*temp;

	i = 0;
	size = ft_stacksize(*stack);
	median = size / 2;
	temp = *stack;
	while (temp->chunk != chunk && temp)
	{
		i++;
		temp = temp->next;
	}
	if (i <= median)
		rotate(stack, 1);
	else
		reverse_rotate(stack, 1);
	return (i);
}

bool	check_if_chunks_exist(t_node *stack, int chunk)
{
	while (stack)
	{
		if (stack->chunk == chunk)
			return (true);
		stack = stack->next;
	}
	return (false);
}

int	push_chunks_to_b(t_node **stack_a, t_node **stack_b, int chunk)
{
	int	i;

	while (check_if_chunks_exist(*stack_a, chunk))
	{
		if ((*stack_a)->chunk == chunk)
			push_pop(stack_b, stack_a);
		else if ((*stack_a)->next->chunk == chunk)
		{
			swap(stack_a, 1);
			push_pop(stack_b, stack_a);
		}
		else
			i = find_fastest_rotate(stack_a, chunk);
	}
	return (i);
}

// void	push_chunks_to_b_last(t_node **stack_a, t_node **stack_b)
// {
// 	while (ft_stacksize(*stack_a) > 3)
// 	{
// 		if ((*stack_a)->final_index == 0 || (*stack_a)->final_index == 1
// 			|| (*stack_a)->final_index == 2)
// 		{
// 			rotate(stack_a, 1);
// 			continue ;
// 		}
// 		else
// 			push_pop(stack_b, stack_a);
// 	}
// }
