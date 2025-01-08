/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:04:16 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/08 17:15:58 by rstumpf          ###   ########.fr       */
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

int	check_if_num_is_in_array(int num, int arr[])
{
	int	i;

	i = 0; 
	while (arr[i])
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	set_index(t_stack *stack)
{
	static int	index = 0;
	static int	arr[1024];
	int			lowest;
	t_stack		*temp;

	lowest = INT_MAX;

	temp = stack;
	while (stack)
	{
		if (stack->nbr < lowest && check_if_num_is_in_array(stack->nbr, arr) == 0)
			lowest = stack->nbr;
		stack = stack->next;
	}
	index++;
	arr[index] = lowest;
	stack = temp;
	while (stack)
	{
		if (stack->nbr == lowest)
			stack->index = index;
		stack = stack->next;
	}
	return (lowest);
}
