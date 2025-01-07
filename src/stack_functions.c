/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/07 10:53:20 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_newstacknode(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	ft_stacklast(*stack)->next = new;
}

void	create_stack_a(t_stack **stack_a, int argc, char **argv)
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

void	create_stack_a_from_string(t_stack **stack_a, char **argv)
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