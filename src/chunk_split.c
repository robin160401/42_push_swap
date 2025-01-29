/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:03:17 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 18:21:32 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_chunk_sizes_to_0(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	set_split_location(t_location location, t_chunk *min,
							t_chunk *mid, t_chunk *max)
{
	if (location == TOP_A)
	{
		min->location = BOTTOM_B;
		mid->location = TOP_B;
		max->location = BOTTOM_A;
	}
	else if (location == BOTTOM_A)
	{
		min->location = BOTTOM_B;
		mid->location = TOP_B;
		max->location = TOP_A;
	}
	else if (location == TOP_B)
	{
		min->location = BOTTOM_B;
		mid->location = BOTTOM_A;
		max->location = TOP_A;
	}
	else if (location == BOTTOM_B)
	{
		min->location = TOP_B;
		mid->location = BOTTOM_A;
		max->location = TOP_A;
	}
}

void	set_pivots(t_location location, int crt_size,
						int *pivot_1, int *pivot_2)
{
	*pivot_2 = crt_size / 3;
	if (location == TOP_A || location == BOTTOM_A)
		*pivot_1 = 2 * crt_size / 3;
	if (location == TOP_B || location == BOTTOM_B)
		*pivot_1 = crt_size / 2;
	if ((location == TOP_A || location == BOTTOM_A) && crt_size < 15)
		*pivot_1 = crt_size;
	if (location == BOTTOM_B && crt_size < 8)
		*pivot_2 = crt_size / 2;
}

void	chunk_split(t_node **stack_a, t_node **stack_b,
					t_chunk *to_split, t_split *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	highest_index;
	int	current_index;

	set_chunk_sizes_to_0(&dest->min, &dest->mid, &dest->max);
	set_split_location(to_split->location, &dest->min, &dest->mid, &dest->max);
	set_pivots(to_split->location, to_split->size, &pivot_1, &pivot_2);
	highest_index = highest_chunk_index(*stack_a, *stack_b, to_split);
	// printf("Highest Index: %d\n", highest_index);
	while (to_split->size--)
	{
		current_index = chunk_index(stack_a, stack_b, to_split);
		// printf("Current Index: %d\n", current_index);
		if (current_index > highest_index - pivot_2)
		{
			// printf("move to max\n");
			dest->max.size += move_from_to(stack_a, stack_b, to_split->location,
					dest->max.location);
		}
		else if (current_index > highest_index - pivot_1)
		{
			// printf("move to mid\n");
			dest->mid.size += move_from_to(stack_a, stack_b, to_split->location,
					dest->mid.location);
		}
		else
		{
			// printf("move to min\n");
			dest->min.size += move_from_to(stack_a, stack_b, to_split->location,
					dest->min.location);
		}
		// printf("_______________\n");
		// print_stack(*stack_a);
		// printf("_______________\n");
		// print_stack(*stack_b);
	}
}

