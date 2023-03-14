/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:43:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 14:50:35 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_b(t_stack *stack, int push)
{
	if (sorted_or_swap_b(stack, push) == 1)
		return (1);
	if (sorted_b(stack->stack_b, push) == 1)
		return (1);
	if (stack->elements_b > 3)
		return (0);
	sort_b_three(&(stack->stack_b));
	return (1);
}

int	sorted_or_swap_b(t_stack *stack, int push)
{
	if (push <= 2)
	{
		if (stack->stack_b->nb < stack->stack_b->next->nb)
		{
			// printf("test sorted or swap\n");
			swap_b(stack->stack_b);
		}
		return (1);
	}
	return (0);
}

int	sorted_b(t_node *stack_b, int push)
{
	int	i;

	i = 1;
	if (push <= 1)
		return (1);
	while (i < push)
	{
		if (stack_b->nb > stack_b->next->nb)
			return (0);
		stack_b = stack_b->next;
		i++;
	}
	return (1);
}