/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:00:12 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/23 14:19:26 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stack = temp2;
	if (temp2->stack == 'A')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return (0);
}

int	push_pop(t_stack **pushstack, t_stack **popstack)
{
	t_stack	*temp;

	if (popstack == NULL)
		return (-1);
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
		*pushstack = set_stack(temp);
	}
	else
		ft_stackadd_front(pushstack, temp);
	return (0);
}

int	rotate(t_stack **stack, int write_r)
{
	t_stack	*temp;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	temp = *stack;
	if (temp->stack == 'A' && write_r)
		write(1, "ra\n", 3);
	else if (temp->stack == 'B' && write_r)
		write(1, "rb\n", 3);
	*stack = temp->next;
	temp->next = NULL;
	ft_stackadd_back(stack, temp);
	return (0);
}

int	reverse_rotate(t_stack **stack, int write_rr)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	temp1 = ft_stacklast(*stack);
	temp2 = *stack;
	if (temp2->stack == 'A' && write_rr)
		write(1, "rra\n", 4);
	else if (temp2->stack == 'B' && write_rr)
		write(1, "rrb\n", 4);
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = *stack;
	*stack = temp1;
	return (0);
}
