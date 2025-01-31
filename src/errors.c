/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:08:56 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 15:19:11 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_str_is_int(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	has_errors(t_node *stack_a)
{
	t_node	*checker;
	
	while (stack_a)
	{
		checker = stack_a->next;
		while (checker)
		{
			if (stack_a->nbr == checker->nbr)
				return (true);
			checker = checker->next;
		}
		stack_a = stack_a->next;
	}
	return (false);
}
