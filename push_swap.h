/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:41:38 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/31 17:33:23 by rstumpf          ###   ########.fr       */
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

int		main(int argc, char **argv);

//Node Functions
t_node	*ft_newstacknode(int nbr);
void	ft_stackadd_front(t_node **stack, t_node *new);
void	ft_stackadd_back(t_node **stack, t_node *new);
t_node	*ft_stacklast(t_node *stack);
int		ft_stacksize(t_node *stack);

//Operations
void	swap_a(t_node **stack_a);
void	push_a(t_node **pushstack, t_node **popstack, t_location to);
void	rotate_a(t_node **stack, t_location to);
void	reverse_rotate_a(t_node **stack, t_location to);
void	swap_b(t_node **stack_a);
void	push_b(t_node **pushstack, t_node **popstack, t_location to);
void	rotate_b(t_node **stack, t_location to);
void	reverse_rotate_b(t_node **stack, t_location to);

//Error Check
int		check_errors(t_node *stack);
bool	ft_str_is_int(const char *str);
bool	has_errors(t_node *stack_a);

//Create Stacks
int		create_stack_a(t_node **stack_a, int argc, char **argv);
int		create_stack_a_from_string(t_node **stack_a, char **argv);
int		create_stacks_throw_errors(char **argv, t_node **stack_a, int argc);

//Helper Functions
void	free_stack(t_node **stack);
bool	checker(t_node **stack);
int		set_index(t_node *stack);
void	set_all_indexes(t_node *stack);
void	set_all_current_indexes(t_node *stack);
void	set_to_sort_location(t_chunk *to_sort);
void	rec_sort_chunk(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
t_node	*get_first_chunk_node(t_node *stack, t_chunk *chunk);
int		chunk_value(t_node *stack_a, t_node *stack_b, t_chunk *chunk, int n);
int		current_chunk_size(t_node *stack);
int		highest_chunk_index(t_node *stack_a, t_node *stack_b, t_chunk *chunk);
int		chunk_index(t_node **stack_a, t_node **stack_b, t_chunk *chunk);
long	ft_atol(const char *str);

//Sort Functions
int		sort_first_numbers(t_node **stack_a, t_node **stack_b);
void	sort_chunks(t_node **stack_a, t_node **stack_b);

//Sort Number Functions
void	sort_one(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
void	sort_two(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
void	sort_three(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);
void	sort_3_numbers(t_node **stack_a, t_location to);
void	sort_5_numbers(t_node **stack_a, t_node **stack_b, t_location to);
void	sort_4_numbers(t_node **stack_a, t_node **stack_b);


//Move
int		move_from_to(t_node **stack_a, t_node **stack_b,
			t_location from, t_location to);
//Chunk split
void	chunk_split(t_node **stack_a, t_node **stack_b,
			t_chunk *to_split, t_split *dest);

//EasySort
void	split_reduction(t_node **stack_a,t_node **stack_b, t_chunk *max);
void	easy_sort(t_node **stack_a, t_node **stack_b, t_chunk *to_sort);

//Tests
void	operationtest(t_node **stack_a, t_node **stack_b);
void	print_stack(t_node *stack);

#endif