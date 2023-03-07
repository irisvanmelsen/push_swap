/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/07 13:44:50 by ivan-mel         ###   ########.fr       */
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
	int				index;
	int				sort;
	// int				elements;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// -----------------------PARSING--------------------------------------
//
// ------------------------parser--------------------------------------
int		digit_checker(char *str, int *nb);
int		parse_args(char **argv, t_stack **stack_a);
int		ft_atoi_overflow(char *str, int *nb);
// ------------------------LIST----------------------------------------
//
// --------------------create list--------------------------------------
t_stack	*create_node(int nb);
void	add_to_end(t_stack **lst, t_stack *new);
size_t	list_size(t_stack *stack);
t_stack	*list_add_node_front(t_stack *node, t_stack stack);
t_stack	*list_take_node(t_stack stack);
// ------------------------OPERATIONS----------------------------------
//
// ------------------------push----------------------------------------
void	push(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b, int total);
// ------------------------rotate--------------------------------------
void	rotate(t_stack **stack);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack);
void	rev_rotate_rr(t_stack **stack_a, t_stack **stack_b);
// ------------------------swap----------------------------------------
void	swap(t_stack **stack);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
// --------------------OPERATIONS CALL---------------------------------
//
// --------------------operations_push_swap----------------------------
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
// --------------------operations_rotate------------------------------
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
// --------------------operations_rev_rotate---------------------------
void	rev_rotate_a(t_stack **stack_a);
void	rev_rotate_b(t_stack **stack_b);
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b);
// ----------------------BUBBLESORT FUNCTIONS--------------------------
//
// ---------------------------bubblesort-------------------------------
void	stack_sorted_same(t_stack *stack, t_stack *sorted, int i);
void	bubblesort(t_stack *stack, t_stack *sorted);
void	bs_sort(t_stack *tmp, int *swap, t_stack *stack);
void	bs_swap(t_stack *stack1, t_stack *stack2);
// -------------------------BUBBLESORT UTILS---------------------------
//
// ---------------------bubblesort functions---------------------------
int		find_pivot(t_stack *stack, int total);
int		find_middle(t_stack *stack);
// --------------------------PRINTING----------------------------------
//
// ---------------------printing functions-----------------------------
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack *a);
void	print_index(t_stack *stack);
int		stack_length(t_stack *stack);
// --------------------------QUICKSORT--------------------------------
//
// ---------------------quicksort functions---------------------------
void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int total);
void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int total);
// -------------------------CHECK SORTING------------------------------
//
// ---------------------------sorting_a-------------------------------
int		check_a(t_stack *stack_b, int total);
int		sorted_or_swap_a(t_stack *stack_a, int total);
int		sorted_a(t_stack *stack_b, int total);
// -------------------------CHECK SORTING------------------------------
//
// ---------------------------sorting_b--------------------------------
int		check_b(t_stack *stack_b, int total);
int		sorted_or_swap_b(t_stack *stack_b, int total);
int		sorted_b(t_stack *stack_b, int total);
// ------------------------------ERROR---------------------------------
//
// ------------------------------error---------------------------------
void	error_message(void);
// ------------------------------ERROR---------------------------------
//
// ------------------------------error---------------------------------
void	sort_a_three(t_stack *stack);
void	sort_b_three(t_stack *stack);

#endif