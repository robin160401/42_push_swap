/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/07 14:36:20 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
			*stack_a = ft_newstacknode(atoi(argv[i]), 'A');
		else
			ft_stackadd_back(stack_a, ft_newstacknode(atoi(argv[i]), 'A'));
		i++;
	}
}

void	create_stack_a_from_string(t_stack **stack_a, char **argv)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argv[1], ' ');
	i = 0;
	while (numbers[i])
	{
		if (i == 0)
			*stack_a = ft_newstacknode(atoi(numbers[i]), 'A');
		else
			ft_stackadd_back(stack_a, ft_newstacknode(atoi(numbers[i]), 'A'));
		i++;
	}
}
