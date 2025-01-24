/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:51 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 23:12:23 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_all_chunks(t_node *stack)
{
	int	chunk1;
	int	chunk2;

	chunk1 = ft_stacksize(stack) / 3;
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

void	find_fastest_rotate(t_node **stack, int chunk)
{
	int		i;
	int		median;
	t_node	*temp;

	i = 0;
	median = ft_stacksize(*stack) / 2;
	temp = *stack;
	while (*stack)
	{
		if ((*stack)->chunk == chunk)
			break ;
		else
			i++;
		*stack = (*stack)->next;
	}
	printf("Heres the I == %d", i);
	*stack = temp;
	if (i <= median)
		rotate(stack, 1);
	else
		reverse_rotate(stack, 1);
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

void	push_chunks_to_b(t_node **stack_a, t_node **stack_b, int chunk)
{
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
			find_fastest_rotate(stack_a, chunk);
	}
}

void	push_chunks_to_b_last(t_node **stack_a, t_node **stack_b)
{
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1
			|| (*stack_a)->index == 2)
		{
			rotate(stack_a, 1);
			continue ;
		}
		else
			push_pop(stack_b, stack_a);
	}
}
