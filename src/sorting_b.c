/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:43:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/07 14:30:14 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_b(t_stack *stack_b, int total)
{
	printf("stack_b->index: %d\n", stack_b->index);
	if (sorted_or_swap_b(stack_b, total))
		return (1);
	if (sorted_b(stack_b, total))
		return (1);
	if (stack_b->index == 2)
		return (0);
	sort_b_three(stack_b);
	return (0);
}

int	sorted_or_swap_b(t_stack *stack_b, int total)
{
	if (total <= 2)
	{
		if (stack_b->nb < stack_b->next->nb)
			swap_b(&stack_b);
		return (1);
	}
	return (0);
}

// i is used as a counter to iterate through the stack
// descending is a flag to keep track of whether the order is correct
// if element is smaller than next descending is set to 0
// if it is in descending order then descending should be 1

int	sorted_b(t_stack *stack_b, int total)
{
	int	i;
	int	descending;

	i = 0;
	descending = 1;
	if (total <= 1)
		return (1);
	while (total > i + 1)
	{
		if (stack_b->nb < stack_b->next->nb)
			descending = 0;
		stack_b = stack_b->next;
		i++;
	}
	if (descending)
		return (1);
	else
		return (0);
}