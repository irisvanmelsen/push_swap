/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:40:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/07 14:30:05 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a(t_stack *stack_a, int total)
{
	if (sorted_or_swap_a(stack_a, total) == 1)
		return (1);
	if (sorted_a(stack_a, total) == 1)
		return (1);
	// printf("stack_a->index: %d\n", stack_a->index);
	if (stack_a->index > 2)
		return (0);
	sort_a_three(stack_a);
	return (1);
}

int	sorted_or_swap_a(t_stack *stack_a, int total)
{
	if (total <= 2)
	{
		if (stack_a->nb > stack_a->next->nb)
			swap_a(&stack_a);
		return (1);
	}
	return (0);
}

// i is used as a counter to iterate through the stack
// ascending is a flag to keep track of whether the order is correct
// if element is greater than next ascending is set to 0
// if it is in ascending order then ascending should be 1

int	sorted_a(t_stack *stack_a, int total)
{
	int	i;
	int	ascending;

	i = 0;
	ascending = 1;
	if (total <= 1)
		return (1);
	while (total > i + 1)
	{
		if (stack_a->nb > stack_a->next->nb)
			ascending = 0;
		stack_a = stack_a->next;
		i++;
	}
	if (ascending)
		return (1);
	else
		return (0);
}
