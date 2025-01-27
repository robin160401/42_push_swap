/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:51 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/27 16:47:41 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_to_sort_location(t_node **stack_a,
	t_node **stack_b, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_B
		&& ft_stacksize(*stack_b) == to_sort->size)
		to_sort->location = TOP_B;
	if (to_sort->location == BOTTOM_A
		&& ft_stacksize(*stack_a) == to_sort->size)
		to_sort->location = TOP_A;
}

