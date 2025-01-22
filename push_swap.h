/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:41:38 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/22 14:38:24 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	char			stack;
	int				index;
	int				indexed;
	int				current_index;
	int				over_median;
	int				lowest_operations;
	int				operations;
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

void	create_stack_a(t_stack **stack_a, int argc, char **argv);
void	create_stack_a_from_string(t_stack **stack_a, char **argv);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_newstacknode(int nbr, char stack);
int		ft_stacksize(t_stack *stack);
int		swap(t_stack **stack_a);
int		push_pop(t_stack **pushstack, t_stack **popstack);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
char	set_stack_new_node(char stacknode);
t_stack	*set_stack(t_stack *stacknode);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
int		set_index(t_stack *stack);
int		set_all_indexes(t_stack *stack);
void	push_lowerhalf_to_b(t_stack **stack_a, t_stack **stack_b, int len);
int		sort_first_numbers(t_stack **stack_a);
int		sort_3_numbers(t_stack **stack_a);
t_stack	*get_highest_index(t_stack *stack);
int		is_sorted(t_stack **stack);
int		set_current_indexes(t_stack *stack);
int		sort_all_nbrs(t_stack **stack_a, t_stack **stack_b);
void	find_less_operations(t_stack *stack_a, t_stack *stack_b);
void	set_lowest_opeartions(t_stack *stack);
void	set_target_a(t_stack *stack_a, t_stack *stack_b);
void	set_stack_a(t_stack *stack_a, t_stack *stack_b);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	set_target_b(t_stack *stack_a, t_stack *stack_b);
void	set_stack_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_stack(t_stack **stack, t_stack *top);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	low_to_top(t_stack **stack_a);

#endif