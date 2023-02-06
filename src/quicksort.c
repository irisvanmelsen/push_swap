/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/06 17:46:06 by ivan-mel         ###   ########.fr       */
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

void	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	algorithm(stack_a, stack_b, find_pivot(*stack_a));
}

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	algorithm(t_stack **stack_a, t_stack **stack_b, int pivot)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->nb < pivot)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
	tmp = tmp->next;
}