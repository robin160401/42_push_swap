/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/30 14:12:56 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	create_stack_a(t_node **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_int(argv[i]))
			return (ft_putendl_fd("Error", 2), -1);
		else if (i == 1)
			*stack_a = ft_newstacknode(ft_atoi(argv[i]));
		else
			ft_stackadd_back(stack_a, ft_newstacknode(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}

int	create_stack_a_from_string(t_node **stack_a, char **argv)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argv[1], ' ');
	i = 0;
	while (numbers[i])
	{
		if (!ft_str_is_int(numbers[i]))
			return (ft_putendl_fd("Error", 2), -1);
		else if (i == 0)
		{
			*stack_a = ft_newstacknode(ft_atoi(numbers[i]));
			if (!(*stack_a)->nbr)
				return (ft_putendl_fd("Error", 2), -1);
		}
		else
			ft_stackadd_back(stack_a, ft_newstacknode(ft_atoi(numbers[i])));
		i++;
	}
	return (0);
}
