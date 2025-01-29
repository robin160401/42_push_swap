/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:41:38 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/29 17:21:58 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef enum e_location
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_location;

typedef struct s_node
{
	int				nbr;
	int				final_index;
	int				current_index;
	int				chunk;
	struct s_node	*next;
	t_location		location;
}					t_node;

typedef struct s_chunk
{
	t_location	location;
	int			size;
}				t_chunk;

typedef struct s_split
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split;

//Node Functions
t_node	*ft_newstacknode(int nbr);
void	ft_stackadd_front(t_node **stack, t_node *new);
void	ft_stackadd_back(t_node **stack, t_node *new);
t_node	*ft_stacklast(t_node *stack);
int		ft_stacksize(t_node *stack);
void	change_stack_name(t_node *node);

//Operations
void	swap(t_node **stack_a, int write_s);
void	push_pop(t_node **pushstack, t_node **popstack, t_location to);
void	rotate(t_node **stack, int write_r, t_location to);
void	reverse_rotate(t_node **stack, int write_rr, t_location to);
void	rotate_both_stacks(t_node **stack_a, t_node **stack_b);

//Create Stacks
void	create_stack_a(t_node **stack_a, int argc, char **argv);
void	create_stack_a_from_string(t_node **stack_a, char **argv);

//Helper Functions
int		is_sorted(t_node **stack);
int		set_index(t_node *stack);
void	set_all_indexes(t_node *stack);
void	push_b_to_a(t_node **stack_a, t_node **stack_b);
void	set_all_current_indexes(t_node *stack);
int		ft_chunk_size(t_node *stack, t_location location);
void	set_to_sort_location(t_chunk *to_sort);
void	rec_sort_chunk(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
t_node	*get_first_chunk_node(t_node *stack, t_chunk *chunk);
int		chunk_value(t_node *stack_a, t_node *stack_b, t_chunk *chunk, int n);
int		current_chunk_size(t_node *stack);
int		lowest_chunk_index(t_node *stack_a, t_node *stack_b, t_chunk *chunk);
int		highest_chunk_index(t_node *stack_a, t_node *stack_b, t_chunk *chunk);
int		chunk_index(t_node **stack_a, t_node **stack_b, t_chunk *chunk);

//Sort Functions
int		sort_first_numbers(t_node **stack_a, t_node **stack_b);
void	sort_all_nbrs(t_node **stack_a, t_node **stack_b);

//Sort Number Functions
void	sort_one(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
void	sort_two(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
void	sort_three(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
void	sort_3_numbers(t_node **stack_a, t_location to);
void	sort_5_numbers(t_node **stack_a, t_node **stack_b, t_location to);

//Move
int		move_from_to(t_node **stack_a, t_node **stack_b,
					t_location from, t_location to);
//Chunk split
void	chunk_split(t_node **stack_a, t_node **stack_b,
					t_chunk *to_split, t_split *dest);

//EasySort
void	easy_sort(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);

//Tests
void	operationtest(t_node **stack_a, t_node **stack_b);
void	print_stack(t_node *stack);

#endif