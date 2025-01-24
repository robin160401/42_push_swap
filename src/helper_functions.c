/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:47:16 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	sort_first_numbers(t_node **stack_a)
{
	if (ft_stacksize((*stack_a)) == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			swap(stack_a, 1);
	}
	else
		sort_3_numbers(stack_a);
	return (1);
}

int	is_sorted(t_node **stack)
{
	if (!(*stack))
		return (0);
	while ((*stack)->next)
	{
		if ((*stack)->nbr != ((*stack)->nbr - (*stack)->next->nbr - 1))
			return (0);
		*stack = (*stack)->next;
	}
	return (1);
}
