/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:00:07 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:32:03 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operationtest(t_node **stack_a, t_node **stack_b)
{
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	reverse_rotate(stack_a, 1);
	rotate(stack_b, 1);
	reverse_rotate(stack_b, 1);
	rotate(stack_a, 1);
	swap(stack_b, 1);
	swap(stack_a, 1);
}
