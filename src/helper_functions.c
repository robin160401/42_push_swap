/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/09 17:10:57 by rstumpf          ###   ########.fr       */
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

void	set_index(t_stack *stack)
{
	static int	index = 0;
	int			lowest;
	t_stack		*temp;

	lowest = INT_MAX;
	temp = stack;
	while (stack)
	{
		if (stack->nbr < lowest && !stack->indexed)
			lowest = stack->nbr;
		stack = stack->next;
	}
	stack = temp;
	while (stack)
	{
		if (stack->nbr == lowest && !stack->indexed)
		{
			stack->index = index;
			stack->indexed = 1;
		}
		stack = stack->next;
	}
	index++;
}

void	set_all_indexes(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack)
	{
		set_index(temp);
		stack = stack->next;
	}
}
