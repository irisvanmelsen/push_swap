/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 18:30:06 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	quicksort_a(t_stack *stack, int push)
{
	int	pivot;
	int	old_push;

	old_push = push;
	pivot = find_pivot(stack->stack_a, push);
	if (check_a(stack, push) == 1)
		return ;
	push = push_b_till_pivot(stack, push, pivot);
	quicksort_a(stack, old_push - push);
	stack->sort = 1;
	quicksort_b(stack, push);
}

int	push_b_till_pivot(t_stack *stack, int push, int pivot)
{
	int	i;
	int	total_pushed;

	i = 0;
	total_pushed = 0;
	while (i < push)
	{
		if ((stack->stack_a)->nb < pivot)
		{
			push_a_to_b(stack);
			total_pushed++;
		}
		else
			rotate_a(&(stack->stack_a));
		i++;
	}
	i = 0;
	if (stack->elements_a <= 3)
	{
		sort_a_three(&(stack->stack_a));
		return (total_pushed);
	}
	while (push - total_pushed > i && stack->sort == 1)
	{
		rev_rotate_a(&(stack->stack_a));
		i++;
	}
	return (total_pushed);
}

void	quicksort_b(t_stack *stack, int push)
{
	int	pivot;
	int	old_push;

	old_push = push;
	pivot = find_pivot(stack->stack_b, push);
	if (check_b(stack, push) == 1)
	{
		push_b(stack, push);
		return ;
	}
	push = push_a_till_pivot(stack, push, pivot);
	quicksort_a(stack, push);
	quicksort_b(stack, old_push - push);
}

int	push_a_till_pivot(t_stack *stack, int push, int pivot)
{
	int	i;
	int	total_pushed;

	i = 0;
	total_pushed = 0;
	while (push > i)
	{
		if ((stack->stack_b)->nb > pivot)
		{
			push_b_to_a(stack);
			total_pushed++;
		}
		else
			rotate_b(&(stack->stack_b));
		i++;
	}
	i = 0;
	while (push - total_pushed > i && stack->sort == 1)
	{
		rev_rotate_b(&(stack->stack_b));
		i++;
	}
	return (total_pushed);
}