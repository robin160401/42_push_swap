/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/28 14:42:31 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack_a(t_node **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
			*stack_a = ft_newstacknode(atoi(argv[i]));
		else
			ft_stackadd_back(stack_a, ft_newstacknode(atoi(argv[i])));
		i++;
	}
}

void	create_stack_a_from_string(t_node **stack_a, char **argv)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argv[1], ' ');
	i = 0;
	while (numbers[i])
	{
		if (i == 0)
			*stack_a = ft_newstacknode(atoi(numbers[i]));
		else
			ft_stackadd_back(stack_a, ft_newstacknode(atoi(numbers[i])));
		i++;
	}
}
