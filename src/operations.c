/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:00:12 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/07 16:56:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stack = temp2;
	if (temp2->stack == 'A')
		write(1, "sa", 2);
	else
		write(1, "sb", 2);
}

void	push_pop(t_stack **pushstack, t_stack **popstack)
{
	t_stack	*temp;

	if (popstack == NULL)
		return ;
	temp = *popstack;
	*popstack = temp->next;
	if (*pushstack == NULL)
	{
		temp->next = NULL;
		*pushstack = set_stack(temp);
	}
	else
		ft_stackadd_front(pushstack, temp);
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	ft_stackadd_back(stack, temp);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = ft_stacklast(*stack);
	temp2 = *stack;
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp1->next = *stack;
	*stack = temp1;
}
