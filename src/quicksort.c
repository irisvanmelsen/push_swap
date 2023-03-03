/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/03 18:00:44 by ivan-mel         ###   ########.fr       */
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
	if (check_a(*stack_a, total) == 1)
		return ;
	pivot = find_pivot(*stack_a, total);
	while (total > i)
	{
		if ((*stack_a)->nb < pivot)
		{
			printf("stacks in quicksort a before push:\n");
			print_stacks(*stack_a, *stack_b);
			printf("------------------\n");
			push_a_to_b(stack_a, stack_b);
			printf("stacks in quicksort a after push:\n");
			print_stacks(*stack_a, *stack_b);
			printf("------------------\n");
			counter++;
		}
		else
		{
			printf("stack in quicksort a before rotate:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			rotate_a(stack_a);
			printf("stack a in quicksort a after rotate:\n");
			print_stack(*stack_a);
			printf("------------------\n");
		}
		printf("i: %d\n total: %d\n", i, total);
		i++;
	}
	while (total - counter > i && (*stack_a)->sort == 1)
	{
		rev_rotate_a(stack_a);
		i++;
	}
	quicksort_a(stack_a, stack_b, old_total - counter);
	(*stack_a)->sort = 1;
	quicksort_b(stack_a, stack_b, total);
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
	if (check_b(*stack_b, total) == 1)
		return (push_a(*stack_a, *stack_b, total));
	pivot = find_pivot(*stack_b, total);
	while (i < total)
	{
		if ((*stack_b)->nb < pivot)
		{
			printf("stacks in quicksort b before push:\n");
			print_stacks(*stack_b, *stack_a);
			printf("------------------\n");
			push_b_to_a(stack_a, stack_b);
			printf("stacks in quicksort b after push:\n");
			print_stacks(*stack_b, *stack_a);
			printf("------------------\n");
			counter++;
		}
		else
		{
			printf("stack b in quicksort b before rotate:\n");
			print_stack(*stack_b);
			printf("------------------\n");
			rotate_b(stack_b);
			printf("------------------\n");
			printf("stack b in quicksort b after rotate:\n");
			print_stack(*stack_b);
			printf("------------------\n");
		}
		i++;
	}
	while (total - counter > i && (*stack_a)->sort == 1)
	{
		rev_rotate_b(stack_b);
		i++;
	}
	quicksort_a(stack_a, stack_b, total);
	quicksort_b(stack_b, stack_a, old_total - counter);
}