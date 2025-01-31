/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:24:18 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 11:12:26 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_chunks(t_node **stack_a, t_node **stack_b)
{
	t_chunk	chunk_all;

	chunk_all.location = TOP_A;
	chunk_all.size = ft_stacksize(*stack_a);
	rec_sort_chunk(stack_a, stack_b, &chunk_all);
}

void	rec_sort_chunk(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	t_split	dest;

	set_to_sort_location(to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
		{
			// printf("I am sort Three\n");
			sort_three(stack_a, stack_b, to_sort);
		}
		if (to_sort->size == 2)
		{
			sort_two(stack_a, stack_b, to_sort);
			// printf("I am sort Two\n");
		}
		else if (to_sort->size == 1)
		{
			// printf("I am sort One\n");
			sort_one(stack_a, stack_b, to_sort);
		}
		return ;
	}
	chunk_split(stack_a, stack_b, to_sort, &dest);
	rec_sort_chunk(stack_a, stack_b, &dest.max);
	rec_sort_chunk(stack_a, stack_b, &dest.mid);
	rec_sort_chunk(stack_a, stack_b, &dest.min);
}
