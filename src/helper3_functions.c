/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:12:29 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 23:37:34 by rstumpf          ###   ########.fr       */
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
	while (temp && temp->index - 1 != (*stack_a)->index)
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
		if ((*stack_a)->index == (*stack_b)->index - 1)
			push_pop(stack_a, stack_b);
		else if ((*stack_a)->index == (*stack_b)->next->index)
		{
			swap(stack_b, 1);
			push_pop(stack_a, stack_b);
		}
		else
			find_fastest_rotate_b(stack_a, stack_b);
	}
}