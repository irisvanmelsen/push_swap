/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/08 16:01:56 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pivot(t_stack *stack)
{
	t_stack	*one;
	t_stack	*two;

	one = stack;
	two = stack;
	while (two && two->next != stack)
	{
		if (two->next->next == stack)
			break ;
		one = one->next;
		two = two->next->next;
	}
	printf("pivot: %d\n", one->nb);
	return (one->nb);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	quicksort_a(stack_a, stack_b);
}

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	quicksort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		pivot;
	// int		counter;

	pivot = find_pivot(*stack_a);
	tmp = *stack_a;
	if (tmp->nb < pivot)
	{
		pb(stack_a, stack_b);
		// counter++;
	}
	else
		ra(stack_a);
	// tmp = tmp->next;

	quicksort_a(stack_a, stack_b);
	print_stack(*stack_a);
}

// void	quicksort_b(t_stack **stack_a, t_stack **stack_b)
// {

// }