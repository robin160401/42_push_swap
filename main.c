/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:28:00 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/22 14:43:40 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Stack: %d | Index: %d\n", stack->nbr, stack->index);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		create_stack_a_from_string(&stack_a, argv);
	else
		create_stack_a(&stack_a, argc, argv);

	set_all_indexes(stack_a);
	printf("____________________\nStack A Before: \n");
	print_stack(stack_a);
	printf("____________________\n");
	printf("____________________\nStack B Before: \n");
	print_stack(stack_b);
	printf("____________________\n");
	if (ft_stacksize(stack_a) <= 3)
		sort_first_numbers(&stack_a);
	else
		sort_all_nbrs(&stack_a, &stack_b);
	printf("____________________\nStack A After: \n");
	print_stack(stack_a);
	printf("____________________\n");
	printf("____________________\nStack B After: \n");
	print_stack(stack_b);
	printf("____________________\n");
	return (0);
}
