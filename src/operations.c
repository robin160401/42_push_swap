/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:00:12 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:52:09 by rstumpf          ###   ########.fr       */
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
	if (temp2->stack == 'A' && write_s == 1)
		write(1, "sa\n", 3);
	else if (temp2->stack == 'B' && write_s == 1)
		write(1, "sb\n", 3);
	return ;
}

void	push_pop(t_node **pushstack, t_node **popstack)
{
	t_node	*temp;

	if (popstack == NULL)
		return ;
	temp = *popstack;
	if (temp->stack == 'A')
	{
		temp->stack = 'B';
		write(1, "pb\n", 3);
	}
	else
	{
		temp->stack = 'A';
		write(1, "pa\n", 3);
	}
	*popstack = temp->next;
	if (*pushstack == NULL)
	{
		temp->next = NULL;
		*pushstack = temp;
		temp->stack = 'B';
	}
	else
		ft_stackadd_front(pushstack, temp);
	return ;
}

void	rotate(t_node **stack, int write_r)
{
	t_node	*temp;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	if (temp->stack == 'A' && write_r == 1)
		write(1, "ra\n", 3);
	else if (temp->stack == 'B' && write_r == 1)
		write(1, "rb\n", 3);
	*stack = temp->next;
	temp->next = NULL;
	ft_stackadd_back(stack, temp);
	return ;
}

void	reverse_rotate(t_node **stack, int write_rr)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = ft_stacklast(*stack);
	temp2 = *stack;
	if (temp2->stack == 'A' && write_rr == 1)
		write(1, "rra\n", 4);
	else if (temp2->stack == 'B' && write_rr == 1)
		write(1, "rrb\n", 4);
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = *stack;
	*stack = temp1;
}
