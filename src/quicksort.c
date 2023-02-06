/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/06 14:33:04 by ivan-mel         ###   ########.fr       */
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

void	algorithm(t_stack **stack_a, t_stack **stack_b, int pivot)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack_a;
	tmp = *stack_a;
	while (last->next != tmp)
		last = last->next;
	while (tmp != last)
	{
		if (tmp->nb < pivot)
		{
			pb(stack_a, stack_b);
		}
		tmp = tmp->next;
	}
}