/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/08 16:17:21 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	quicksort_a(t_stack *stack, int total)
{
	t_node	*tmp;
	int		i;
	int		pivot;
	int		old_total;
	int		counter;

	i = 0;
	old_total = total;
	counter = 0;
	tmp = stack->stack_a;
	print_stack (stack->stack_a);
	// (*stack_a)->index = stack_length(*stack_a);
	if (check_a(stack, total) == 1)
		return ;
	pivot = find_pivot(stack->stack_a, total);
	while (total > i)
	{
		if ((stack->stack_a)->nb < pivot)
		{
			push_a_to_b(stack);
			counter++;
		}
		else
			rotate_a(stack->stack_a);
		i++;
	}
	printf("i: %d\ttotal: %d\tpivot: %d\n", i, total, pivot);
	i = 0;
	// if ((*stack_a)->elements < 3)
	// 	return ;
	while (total - counter > i && stack->sort == 1)
	{
		rev_rotate_a(stack->stack_a);
		i++;
	}
	quicksort_a(stack, old_total - counter);
	stack->sort = 1;
	quicksort_b(stack, counter);
}

void	quicksort_b(t_stack *stack, int total)
{
	t_node	*tmp;
	int		i;
	int		pivot;
	int		old_total;
	int		counter;

	i = 0;
	old_total = total;
	counter = 0;
	tmp = stack->stack_b;
	// printf("stack_b->index: %d\n", (*stack_b)->index);
	if (check_b(stack, total) == 1)
		return (push_a(stack, total));
	pivot = find_pivot(stack->stack_b, total);
	while (i < total)
	{
		if ((stack->stack_b)->nb >= pivot)
		{
			push_b_to_a(stack);
			counter++;
		}
		else
			rotate_b(stack->stack_b);
		i++;
	}
	i = 0;
	// if ((*stack_b)->elements < 3)
	// 	return ;
	while (total - counter > i && stack->sort == 1)
	{
		rev_rotate_b(stack->stack_b);
		i++;
	}
	quicksort_a(stack, counter);
	quicksort_b(stack, old_total - counter);
}