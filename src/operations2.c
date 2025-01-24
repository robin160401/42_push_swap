/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:11:09 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:24:55 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both_stacks(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_both_stacks(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}

void	swap_both_stacks(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	write(1, "ss\n", 3);
}
