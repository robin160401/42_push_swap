/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/02 11:45:22 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	create_stack_a(t_node **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_int(argv[i]) || ft_atol(argv[i]) > INT_MAX
			|| ft_atol(argv[i]) < INT_MIN)
			return (ft_putendl_fd("Error", 2), free_stack(stack_a), -1);
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

	if (ft_strlen(argv[1]) == 0)
		return (ft_putendl_fd("Error", 2), -1);
	numbers = ft_split(argv[1], ' ');
	i = 0;
	while (numbers[i])
	{
		if (!ft_str_is_int(numbers[i])
			|| ft_atol(numbers[i]) > INT_MAX || ft_atol(numbers[i]) < INT_MIN)
			return (ft_putendl_fd("Error", 2), free_stack(stack_a),
				free_split(numbers), -1);
		else if (i == 0)
			*stack_a = ft_newstacknode(ft_atoi(numbers[i]));
		else
			ft_stackadd_back(stack_a, ft_newstacknode(ft_atoi(numbers[i])));
		i++;
	}
	free_split(numbers);
	return (0);
}

int	create_stacks_check_errors(char **argv, t_node **stack_a, int argc)
{
	if (argc < 2)
		return (ft_putendl_fd("Error", 2), -1);
	if (argc == 2)
	{
		if (create_stack_a_from_string(stack_a, argv) == -1)
			return (-1);
	}
	else
	{
		if (create_stack_a(stack_a, argc, argv) == -1)
			return (-1);
	}
	if (has_errors(*stack_a))
		return (ft_putendl_fd("Error", 2), free_stack(stack_a), -1);
	return (0);
}
