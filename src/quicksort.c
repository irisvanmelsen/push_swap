/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/07 14:27:22 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int total)
{
	t_stack	*tmp;
	int		i;
	int		pivot;
	int		old_total;
	int		counter;

	i = 0;
	old_total = total;
	counter = 0;
	tmp = *stack_a;
	pivot = find_pivot(*stack_a, total);
	print_stack(*stack_a);
	// (*stack_a)->index = stack_length(*stack_a);
	if (check_a(*stack_a, total) == 1)
		return ;
	while (total > i)
	{
		if ((*stack_a)->nb < pivot)
		{
			push_a_to_b(stack_a, stack_b);
			counter++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	printf("i: %d\ttotal: %d\tpivot: %d\n", i, total, pivot);
	i = 0;
	// if ((*stack_a)->elements < 3)
	// 	return ;
	while (total - counter > i && (*stack_a)->sort == 1)
	{
		rev_rotate_a(stack_a);
		i++;
	}
	quicksort_a(stack_a, stack_b, old_total - counter);
	(*stack_a)->sort = 1;
	quicksort_b(stack_a, stack_b, counter);
}

void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int total)
{
	t_stack	*tmp;
	int		i;
	int		pivot;
	int		old_total;
	int		counter;

	i = 0;
	old_total = total;
	counter = 0;
	tmp = *stack_b;
	pivot = find_pivot(*stack_b, total);
	// printf("stack_b->index: %d\n", (*stack_b)->index);
	if (check_b(*stack_b, total) == 1)
		return (push_a(*stack_a, *stack_b, total));
	while (i < total)
	{
		if ((*stack_b)->nb >= pivot)
		{
			push_b_to_a(stack_a, stack_b);
			counter++;
		}
		else
			rotate_b(stack_b);
		i++;
	}
	i = 0;
	// if ((*stack_b)->elements < 3)
	// 	return ;
	while (total - counter > i && (*stack_a)->sort == 1)
	{
		rev_rotate_b(stack_b);
		i++;
	}
	quicksort_a(stack_a, stack_b, counter);
	quicksort_b(stack_b, stack_a, old_total - counter);
}