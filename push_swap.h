/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 13:01:16 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	rev_rotate(t_node **stack);
// ------------------------swap----------------------------------------
void	swap(t_node *stack);
// --------------------OPERATIONS CALL---------------------------------
//
// --------------------operations_push_swap----------------------------
void	push_b_to_a(t_stack *stack);
void	push_a_to_b(t_stack *stack);
void	swap_a(t_node *stack);
void	swap_b(t_node *stack);
// --------------------operations_rotate------------------------------
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
// void	rotate_both(t_node **stack);
// --------------------operations_rev_rotate---------------------------
void	rev_rotate_a(t_node **stack);
void	rev_rotate_b(t_node **stack);
// ----------------------BUBBLESORT FUNCTIONS--------------------------
//
// ---------------------------bubblesort-------------------------------
// void	stack_sorted_same(t_node *stack, t_node *sorted);
void	bubblesort(t_node *sorted);
void	bs_sort(t_node *tmp, int *swap, t_node *stack);
void	bs_swap(t_node *stack1, t_node *stack2);
// -------------------------BUBBLESORT UTILS---------------------------
//
// ---------------------bubblesort functions---------------------------
int		find_pivot(t_node *stack, int total);
int		find_middle(t_node *stack);
// --------------------------QUICKSORT--------------------------------
//
// ---------------------quicksort functions---------------------------
void	quicksort_a(t_stack *stack, int total);
int		push_b_till_pivot(t_stack *stack, int push, int pivot);
void	quicksort_b(t_stack *stack, int total);
int		push_a_till_pivot(t_stack *stack, int push, int pivot);
int		elements_three_or_less(t_stack *stack, int total_pushed);
// -------------------------CHECK SORTING------------------------------
//
// ---------------------------sorting_a-------------------------------
int		check_a(t_stack *stack, int total);
int		sorted_or_swap_a(t_stack *stack, int total);
int		sorted_a(t_node *stack_a, int total);
// -------------------------CHECK SORTING------------------------------
//
// ---------------------------sorting_b--------------------------------
int		check_b(t_stack *stack, int total);
int		sorted_or_swap_b(t_stack *stack_b, int total);
int		sorted_b(t_node *stack_b, int push);
// ------------------------------ERROR---------------------------------
//
// ------------------------------error---------------------------------
void	error_message(void);
// --------------------------THREE NUMBERS-----------------------------
//
// ---------------------------few_numbers------------------------------
void	sort_a_three(t_node **stack);
void	sort_b_three(t_node **stack);

#endif