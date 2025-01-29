/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:00:12 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 19:04:23 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **stack, int write_s)
{
	t_node	*temp;
	t_node	*temp2;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stack = temp2;
	if ((temp2->location == TOP_A || temp2->location == BOTTOM_A)
		&& write_s == 1)
		write(1, "sa\n", 3);
	else if ((temp->location == TOP_A || temp->location == BOTTOM_A)
		&& write_s == 1)
		write(1, "sb\n", 3);
	return ;
}

void	push_pop(t_node **pushstack, t_node **popstack, t_location to)
{
	t_node	*temp;

	temp = *popstack;
	if (temp->location == TOP_A || temp->location == BOTTOM_A)
	{
		write(1, "pb\n", 3);
		temp->location = to;
	}
	else
	{
		write(1, "pa\n", 3);
		temp->location = to;
	}
	*popstack = temp->next;
	if (*pushstack == NULL)
	{
		temp->next = NULL;
		*pushstack = temp;
		temp->location = to;
	}
	else
		ft_stackadd_front(pushstack, temp);
	return ;
}

void	rotate(t_node **stack, int write_r, t_location to)
{
	t_node	*temp;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	if ((temp->location == TOP_A || temp->location == BOTTOM_A)
		&& write_r == 1)
		write(1, "ra\n", 3);
	else if ((temp->location == TOP_B || temp->location == BOTTOM_B)
		&& write_r == 1)
		write(1, "rb\n", 3);
	temp->location = to;
	*stack = temp->next;
	temp->next = NULL;
	ft_stackadd_back(stack, temp);
	return ;
}

void	reverse_rotate(t_node **stack, int write_rr, t_location to)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = ft_stacklast(*stack);
	temp2 = *stack;
	if (!temp2)
		return ;
	if ((temp2->location == TOP_A || temp2->location == BOTTOM_A)
		&& write_rr == 1)
		write(1, "rra\n", 4);
	else if ((temp2->location == TOP_B || temp2->location == BOTTOM_B)
		&& write_rr == 1)
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
