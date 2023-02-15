/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:43:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/15 15:51:36 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_b(t_stack *stack_b, int total)
{
	if (!swap_a(stack_b, total))
		return (0);
	if (!sorted_a(stack_b, total))
		return (0);
	sort_b_three(stack_b);
	return (1);
}

int	swap_b(t_stack *stack_b, int total)
{
	if (total <= 2)
	{
		if (stack_b->index < stack_b->next->index)
			sb(&stack_b);
		return (1);
	}
	return (0);
}

int	sorted_b(t_stack *stack_b, int total)
{
	int	i;

	i = 1;
	if (total == 1)
		return (1);
	while (total > i)
	{
		if (stack_b->index > stack_b->next->index)
			return (0);
		i++;
	}
	return (1);
}