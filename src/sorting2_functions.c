/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:54:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/28 15:12:23 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_one(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_A || to_sort->location == BOTTOM_B
		|| to_sort->location == TOP_B)
		
}

void	easy_sort(t_node **stack_a, t_node **stack_b, t_chunk *to_sort)
{
	while (to_sort->location != TOP_A && to_sort->size)
		if ((*stack_a)->final_index
			== chunk_value(stack_a, stack_b, to_sort, 1) - 1)
			sort_one(stack_a, stack_b, to_sort)
}