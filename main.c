/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:28:00 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/27 14:29:09 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		create_stack_a_from_string(&stack_a, argv);
	else
		create_stack_a(&stack_a, argc, argv);

		
	//Print Stack before
	printf("Stack A Before: \n");
	print_stack(stack_a);
	printf("____________________\n");

	//Code Here
	
	if (ft_stacksize(stack_a) <= 5)
		sort_first_numbers(&stack_a, &stack_b);
	else
		sort_all_nbrs(&stack_a, &stack_b);

	//Print Stack after
	printf("____________________\nStack A After: \n");
	print_stack(stack_a);
	printf("____________________\n");
	printf("____________________\nStack B After: \n");
	print_stack(stack_b);
	printf("____________________\n");
	return (0);
}
