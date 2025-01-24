/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:41:38 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/24 16:53:21 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				nbr;
	char			stack;
	struct s_node	*target_node;
	struct s_node	*next;
}					t_node;

//Node Functions
t_node	*ft_newstacknode(int nbr, char stack);
void	ft_stackadd_front(t_node **stack, t_node *new);
void	ft_stackadd_back(t_node **stack, t_node *new);
t_node	*ft_stacklast(t_node *stack);
int		ft_stacksize(t_node *stack);
void	change_stack_name(t_node *node);

//Operations
void	swap(t_node **stack_a, int write_s);
void	push_pop(t_node **pushstack, t_node **popstack);
void	push_swap(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack, int write_r);
void	reverse_rotate(t_node **stack, int write_rr);
void	rotate_both_stacks(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_both_stacks(t_node **stack_a, t_node **stack_b);
void	swap_both_stacks(t_node **stack_a, t_node **stack_b);

//Create Stacks
void	create_stack_a(t_node **stack_a, int argc, char **argv);
void	create_stack_a_from_string(t_node **stack_a, char **argv);

//Helper Functions
int		is_sorted(t_node **stack);

//Sort Functions
int		sort_first_numbers(t_node **stack_a);
void	sort_3_numbers(t_node **stack_a);

//Tests
void	operationtest(t_node **stack_a, t_node **stack_b);
#endif