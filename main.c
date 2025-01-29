/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 18:29:09 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 2)
		create_stack_a_from_string(&stack_a, argv);
	else
		create_stack_a(&stack_a, argc, argv);
	
	// printf("stack a before:\n");
	// print_stack(stack_a);
	// printf("------------ \n");

	if (ft_stacksize(stack_a) <= 5)
		sort_first_numbers(&stack_a, &stack_b);
	else
		sort_all_nbrs(&stack_a, &stack_b);
	
	printf("stack a after:\n");
	print_stack(stack_a);
	printf("------------ \n");
	printf("stack b \n");
	print_stack(stack_b);
	return (0);
}