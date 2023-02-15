/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:38 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/15 17:32:23 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a(t_stack *stack_a, int total)
{
	if (swap_a(stack_a, total))
		return (1);
	if (sorted_a(stack_a, total))
		return (1);
	sort_a_three(stack_a);
	return (0);
}

int	swap_a(t_stack *stack_a, int total)
{
	if (total <= 2)
	{
		if (stack_a->index > stack_a->next->index)
			sa(&stack_a);
		return (1);
	}
	return (0);
}

int	sorted_a(t_stack *stack_a, int total)
{
	int	i;

	i = 1;
	if (total <= 1)
		return (1);
	while (total > i)
	{
		if (stack_a->index < stack_a->next->index)
			return (0);
		i++;
	}
	return (1);
}