/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:55:33 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// quicksort is a recursive algorithm
// it first finds the perfect pivot with bubblesort
// then it checks whether the stack has 2 or 3 elements in it
// and whether these are sorted or not
// then it either pushes, rotates or reverse rotates
// quicksort is then called again until everything except
// 2 or 3 elements are in stack_a, then quicksort b is called

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

// checks if number is smaller than pivot
// those numbers are being pushes to stack_b
// otherwise it will rotate until it has been through
// everything. If quicksort A is called from quicksort B
// then there is also a possibility you have to reverse rotate
// therefore there is a whileloop with a check

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
		elements_three_or_less(stack, total_pushed);
	while (push - total_pushed > i && stack->sort == 1)
	{
		rev_rotate_a(&(stack->stack_a));
		i++;
	}
	return (total_pushed);
}

// function that calls sort_a_three to sort the stack_a when
// it only consists of three elements

int	elements_three_or_less(t_stack *stack, int total_pushed)
{
	if (stack->elements_a == 3)
	{
		sort_a_three(&(stack->stack_a));
		return (total_pushed);
	}
	return (0);
}

// quicksort is a recursive algorithm
// it first finds the perfect pivot with bubblesort
// then it checks whether the stack has 2 or 3 elements in it
// and whether these are sorted or not
// then it either pushes, rotates or reverse rotates
// quicksort is then called again until everything except
// 2 or 3 elements are in stack_b
// each time quicksort_a is called so that is being sorted as well

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

// checks if number is smaller than pivot
// those numbers are being pushes to stack_b
// otherwise it will rotate until it has been through
// everything. You might have to reverse rotate when done

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
