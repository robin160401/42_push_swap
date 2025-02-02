/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:12:29 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/02 11:39:09 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_current_index(t_node *stack)
{
	int			biggest;
	static int	i = 0;
	t_node		*temp;

	temp = stack;
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > biggest && stack->current_index == -1)
			biggest = stack->nbr;
		stack = stack->next;
	}
	stack = temp;
	while (stack)
	{
		if (biggest == stack->nbr)
			stack->current_index = i;
		stack = stack->next;
	}
	i++;
}

void	set_all_current_indexes(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (stack)
	{
		set_current_index(temp);
		stack = stack->next;
	}
}

int	highest_chunk_index(t_node *stack_a, t_node *stack_b, t_chunk *chunk)
{
	int	highest;

	highest = INT_MIN;
	if (chunk->location == TOP_A || chunk->location == BOTTOM_A)
	{
		while (stack_a)
		{
			if (stack_a->location == chunk->location
				&& stack_a->final_index > highest)
				highest = stack_a->final_index;
			stack_a = stack_a->next;
		}
		return (highest);
	}
	else
	{
		while (stack_b)
		{
			if (stack_b->location == chunk->location
				&& stack_b->final_index > highest)
				highest = stack_b->final_index;
			stack_b = stack_b->next;
		}
	}
	return (highest);
}

static int	ft_skipspaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	return (i);
}

long	ft_atol(const char *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	sign = 1;
	i = ft_skipspaces(str);
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i == ft_skipspaces(str))
		return (0);
	return (sign * result);
}
