/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:00:12 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 11:01:58 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_node **stack)
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
	write(1, "sa\n", 3);
	return ;
}
void	swap_b(t_node **stack)
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
	write(1, "sb\n", 3);
	return ;
}

void	push_a(t_node **pushstack, t_node **popstack, t_location to)
{
	t_node	*temp;

	temp = *popstack;
	write(1, "pa\n", 3);
	temp->location = to;
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

void	push_b(t_node **pushstack, t_node **popstack, t_location to)
{
	t_node	*temp;

	temp = *popstack;
	write(1, "pb\n", 3);
	temp->location = to;
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

void	rotate_a(t_node **stack, t_location to)
{
	t_node	*temp;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	write(1, "ra\n", 3);
	temp->location = to;
	*stack = temp->next;
	temp->next = NULL;
	ft_stackadd_back(stack, temp);
	return ;
}

void	rotate_b(t_node **stack, t_location to)
{
	t_node	*temp;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	write(1, "rb\n", 3);
	temp->location = to;
	*stack = temp->next;
	temp->next = NULL;
	ft_stackadd_back(stack, temp);
	return ;
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