/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:39:57 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/02 15:21:28 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_node **stack, t_location to)
{
	t_node	*temp;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	write(1, "rb\n", 3);
	temp->location = to;
	*stack = temp->next;
	ft_stackadd_back(stack, temp);
}

void	reverse_rotate_a(t_node **stack, t_location to)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = ft_stacklast(*stack);
	temp2 = *stack;
	if (!temp2)
		return ;
	write(1, "rra\n", 4);
	if (!temp2->next)
	{
		(*stack)->location = to;
		return ;
	}
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = *stack;
	temp1->location = to;
	*stack = temp1;
}

void	reverse_rotate_b(t_node **stack, t_location to)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = ft_stacklast(*stack);
	temp2 = *stack;
	if (!temp2)
		return ;
	write(1, "rrb\n", 4);
	if (!temp2->next)
	{
		(*stack)->location = to;
		return ;
	}
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = *stack;
	temp1->location = to;
	*stack = temp1;
}
