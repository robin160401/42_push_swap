/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 18:43:07 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_first_numbers(t_node **stack_a, t_node **stack_b)
{
	if (ft_stacksize(*stack_a) == 1)
		return (free_stack(stack_a), 1);
	if (ft_stacksize((*stack_a)) == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			swap_a(stack_a);
	}
	else if (ft_stacksize(*stack_a) == 3)
		sort_3_numbers(stack_a, TOP_A);
	else if (ft_stacksize(*stack_a) == 4)
		sort_4_numbers(stack_a, stack_b);
	else
		sort_5_numbers(stack_a, stack_b, TOP_A);
	return (1);
}

int	set_index(t_node *stack)
{
	int			lowest;
	static int	i = 0;
	t_node		*temp;

	temp = stack;
	lowest = INT_MAX;
	while (stack)
	{
		if (stack->nbr < lowest && stack->final_index == -1)
			lowest = stack->nbr;
		stack = stack->next;
	}
	stack = temp;
	while (stack)
	{
		if (lowest == stack->nbr)
			stack->final_index = i;
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
