/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/02 15:21:56 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_newstacknode(int nbr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->final_index = -1;
	new->current_index = -1;
	new->chunk = 0;
	new->location = TOP_A;
	return (new);
}

t_node	*ft_stacklast(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_node **stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		(*stack)->next = NULL;
		return ;
	}
	ft_stacklast(*stack)->next = new;
	new->next = NULL;
}

int	ft_stacksize(t_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack != NULL)
	{
		i++;
		// printf("Hallo hir ist meien Adresse: %p\n", stack);
		// printf("Hallo hir ist meien next Adresse: %p\n", stack->next);
		stack = stack->next;
	}
	return (i);	
}

void	ft_stackadd_front(t_node **stack, t_node *new)
{
	new->next = *stack;
	*stack = new;
}
