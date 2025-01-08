/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:41:38 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/08 16:18:32 by rstumpf          ###   ########.fr       */
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
int		biggest_nbr(t_stack *stack);
int		get_index(t_stack *stack, int last_index_nbr);


#endif