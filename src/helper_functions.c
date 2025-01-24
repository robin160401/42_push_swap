/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 22:45:14 by rstumpf          ###   ########.fr       */
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

int	set_index(t_node *stack)
{
	int			biggest;
	static int	i = 0;
	t_node		*temp;

	temp = stack;
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > biggest && stack->index == -1)
			biggest = stack->nbr;
		stack = stack->next;
	}
	stack = temp;
	while (stack)
	{
		if (biggest == stack->nbr)
			stack->index = i;
		stack = stack->next;
	}
	i++;
	return (-1);
}

void	set_all_indexes(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (stack)
	{
		set_index(temp);
		stack = stack->next;
	}
}
