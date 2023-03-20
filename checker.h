/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:25:43 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/20 13:52:55 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node			*stack_a;
	t_node			*stack_b;
	size_t			elements_a;
	size_t			elements_b;
	int				sort;
}	t_stack;

// -----------------------PARSING--------------------------------------
//
// ------------------------parser--------------------------------------
int		digit_checker(char *str, int *nb);
int		parse_args(char **argv, t_stack *stack);
int		ft_atoi_overflow(char *str, int *nb);
// ------------------------LIST----------------------------------------
//
// --------------------create list--------------------------------------
t_node	*create_node(int nb);
void	add_to_end(t_node **lst, t_node *new);
int		is_sorted(t_node *stack);
void	free_lst(t_node *stack);
// -------------------------BUBBLESORT---------------------------------
//
// ------------------------bubblesort_utils----------------------------
int		find_pivot(t_node *stack, int push);
int		find_middle(t_node *stack);
// --------------------------bubblesort--------------------------------
void	bubblesort(t_node *sorted);
void	bs_sort(t_node *tmp, int *swap, t_node *stack);
void	bs_swap(t_node *stack1, t_node *stack2);
// ------------------------OPERATIONS----------------------------------
//
// ------------------------push----------------------------------------
void	push_function_a_to_b(t_stack *stack);
void	push_function_a_to_b_utils(t_stack *stack, t_node *head);
void	push_function_b_to_a(t_stack *stack);
void	push_function_b_to_a_utils(t_stack *stack, t_node *head);
void	push_b(t_stack *stack, int push);
// ------------------------rotate--------------------------------------
void	rotate(t_node **stack);
void	rotate_rr(t_stack *stack);
void	rev_rotate(t_node **stack);
void	rev_rotate_rr(t_stack *stack);
// ------------------------swap_bonus-----------------------------------
void	swap(t_node *stack);
void	swap_ss(t_stack *stack);
// --------------------OPERATIONS CALL---------------------------------
//
// ----------------operations_push_swap_bonus--------------------------
void	push_b_to_a(t_stack *stack);
void	push_a_to_b(t_stack *stack);
void	swap_a(t_node *stack);
void	swap_b(t_node *stack);
void	swap_both(t_stack *stack);
// --------------------operations_rotate_bonus-------------------------
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	rotate_both(t_stack *stack);
// ------------------operations_rev_rotate_bonus-----------------------
void	rev_rotate_a(t_node **stack);
void	rev_rotate_b(t_node **stack);
void	rev_rotate_both(t_stack *stack);
// ------------------------------ERROR---------------------------------
//
// ---------------------------error_bonus------------------------------
void	error_message(void);
// -------------------------BONUS PUSH_SWAP----------------------------
//
// ---------------------------checker_bonus----------------------------
void	check_operations(t_stack *stack, char *output);
void	check_reading(t_stack *stack);

#endif
