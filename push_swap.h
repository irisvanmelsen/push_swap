/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/06 14:28:18 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		digit_checker(char *str, int *nb);
char	*ps_checker(t_stack *lst, char **argv);
int		parse_args(char **argv, t_stack **stack_a);
t_stack	*create_node(int nb);
int		ft_atoi_overflow(char *str, int *nb);
void	add_to_end(t_stack **lst, t_stack *new);
int		arg_checker(int argc, char **argv);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack);
void	rev_rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	bubblesort(t_stack **stack);
void	bs_sort(t_stack *tmp, int *swap, t_stack *stack);
void	bs_swap(t_stack *stack1, t_stack *stack2);
void	print_stack(t_stack *a);
int		find_pivot(t_stack *stack);
void	quicksort(t_stack **stack_a, t_stack **stack_b);
void	algorithm(t_stack **stack_a, t_stack **stack_b, int pivot);

#endif