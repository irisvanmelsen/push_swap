/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:43:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:56 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_b(t_stack *stack, int push)
{
	if (sorted_or_swap_b(stack, push))
		return (1);
	if (sorted_b(stack->stack_b, push))
		return (1);
	if (stack->elements_b > 3)
		return (0);
	sort_b_three(&(stack->stack_b));
	return (0);
}

int	sorted_or_swap_b(t_stack *stack, int push)
{
	if (push <= 2)
	{
		if (stack->stack_b->nb < stack->stack_b->next->nb)
		{
			printf("test sorted or swap\n");
			swap_b(stack->stack_b);
		}
		return (1);
	}
	return (0);
}

// i is used as a counter to iterate through the stack
// descending is a flag to keep track of whether the order is correct
// if element is smaller than next descending is set to 0
// if it is in descending order then descending should be 1

int	sorted_b(t_node *stack_b, int push)
{
	int	i;

	i = 1;
	if (push == 1)
		return (1);
	while (i < push)
	{
		if (stack_b->nb - i > stack_b->next->nb - i + 1)
			return (0);
		stack_b = stack_b->next;
		i++;
	}
	return (1);
}