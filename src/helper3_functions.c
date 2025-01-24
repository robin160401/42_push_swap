/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:12:29 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 22:55:46 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			rotate(stack_b, 1);
	}
}