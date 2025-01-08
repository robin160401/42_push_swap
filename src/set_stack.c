/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:41:05 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/07 15:07:23 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*set_stack(t_stack *stacknode)
{
	if (stacknode->stack == 'A')
		stacknode->stack = 'B';
	else
		stacknode->stack = 'A';
	return (stacknode);
}

char	set_stack_new_node(char stack)
{
	if (stack == 'A')
		return ('B');
	else
		return ('A');
}
