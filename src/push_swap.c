/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:00:07 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/08 08:47:55 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	push_pop(stack_b, stack_a);
	// reverse_rotate(stack_a);
	// rotate(stack_b);
	// reverse_rotate(stack_b);
	// rotate(stack_a);
	// swap(stack_b);
	// swap(stack_a);
}
