/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:41:05 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:37:26 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	change_stack_name(t_node *node)
{
	if (node->stack == 'A')
		node->stack = 'B';
	else
		node->stack = 'A';
	return ;
}
