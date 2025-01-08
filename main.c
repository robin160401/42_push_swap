/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:28:00 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/07 16:06:49 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d \n", stack->nbr);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 2)
		create_stack_a_from_string(&stack_a, argv);
	else
		create_stack_a(&stack_a, argc, argv);
	push_swap(&stack_a, &stack_b);
	print_stack(stack_a);
	printf("-------------- \n");
	print_stack(stack_b);
	return (0);
}
