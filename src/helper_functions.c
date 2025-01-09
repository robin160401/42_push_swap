/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/09 18:30:43 by rstumpf          ###   ########.fr       */
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

int	set_index(t_stack *stack)
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
	return (index);
}

int	set_all_indexes(t_stack *stack)
{
	t_stack	*temp;
	int		len;

	temp = stack;
	len = 0;
	while (stack)
	{
		len = set_index(temp);
		stack = stack->next;
	}
	return (len);
}

void	push_lowerhalf_to_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	int		half;
	int		i;

	half = len / 2;
	i = 0;
	while (i < len)
	{
		if ((*stack_a)->index <= half)
			push_pop(stack_b, stack_a);
		else
			rotate(stack_a);
		i++;
	}
}
