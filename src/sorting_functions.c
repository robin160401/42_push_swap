/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:35 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:44:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_numbers(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	if (first > second && first > third && second < third)
		rotate(stack, 1);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate(stack, 1);
		swap(stack, 1);
	}
	else if (first > second && second > third)
	{
		swap(stack, 1);
		reverse_rotate(stack, 1);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(stack, 1);
	else if (first > second && second < third && first < second)
		swap(stack, 1);
}
