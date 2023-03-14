/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 14:51:24 by ivan-mel         ###   ########.fr       */
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
	// print_stacks(stack);
	if (check_a(stack, push) == 1)
	{
		// printf("test in check_a quicksort\n");
		// print_stacks(stack);
		return ;
	}
	pivot = find_pivot(stack->stack_a, push);
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
	// printf("stack_a->nb: %d\nstack_a->next: %d\nstack_a->prev: %d\n", stack->stack_a->nb, stack->stack_a->next->nb, stack->stack_a->prev->nb);
	while (i < push)
	{
	// printf("pivot stack_a: %d\n", find_pivot(stack->stack_a, push));
		if ((stack->stack_a)->nb < pivot)
		{
			push_a_to_b(stack);
			total_pushed++;
		}
		else
		{
			// print_stacks(stack);
			rotate_a(&(stack->stack_a));
			// print_stacks(stack);
		}
		i++;
	}
	i = 0;
	// printf("stack->elements_a: %zu\n", stack->elements_a);
	if (stack->elements_a <= 3)
	{
		sort_a_three(&(stack->stack_a));
		return (total_pushed);
	}
	// printf("stack->elements_a check 2: %zu\n", stack->elements_a);
	// printf("push: %d\n", push);
	while (push - total_pushed > i && stack->sort == 1)
	{
		// printf("push in loop: %d\n", push);
		rev_rotate_a(&(stack->stack_a));
		i++;
	}
	return (total_pushed);
}

void	quicksort_b(t_stack *stack, int push)
{
	// printf("start quicksort b\n");
	int	pivot;
	int	old_push;

	old_push = push;
	if (check_b(stack, push) == 1)
	{
		// printf("test in check_b quicksort\n");
		push_b(stack, push);
		return ;
	}
	pivot = find_pivot(stack->stack_b, push);
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
	// printf("stack_b pivot: %d\n", push);
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
	// if ((*stack_a)->elements < 3)
	// 	return ;
	while (push - total_pushed > i && stack->sort == 1)
	{
		rev_rotate_b(&(stack->stack_b));
		i++;
	}
	return (total_pushed);
}