/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/22 13:38:44 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

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

int	sort_first_numbers(t_stack **stack_a)
{
	if (ft_stacksize((*stack_a)) == 2)
	{
		if ((*stack_a)->index == 1)
			swap(stack_a);
	}
	else
		sort_3_numbers(stack_a);
	return (1);
}
