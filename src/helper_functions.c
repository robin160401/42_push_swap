/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/08 16:26:12 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	biggest_nbr(t_stack *stack)
{
	int	big;

	if (stack == NULL)
		return (0);
	big = INT_MIN;
	while (stack != NULL)
	{
		if (stack->nbr > big)
			big = stack->nbr;
		stack = stack->next;
	}
	return (big);
}

int	get_index(t_stack *stack, int last_index_nbr)
{
	static int	index = 0;
	int			actual_nbr;
	int			lowest;

	actual_nbr = stack->nbr;
	while (stack)
	{
		if (stack->nbr > last_index_nbr && stack->nbr < actual_nbr)
			lowest = stack->nbr;
		stack = stack->next;
	}
	while (stack)
	{
		if (stack->nbr == lowest)
			return (stack->index = index, 0);
		stack = stack->next;
	}
	index++;
	return (0);
}
