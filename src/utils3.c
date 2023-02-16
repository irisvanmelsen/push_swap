/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:43:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/16 14:17:13 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_b(t_stack *stack_b, int total)
{
	if (swap_a(stack_b, total))
		return (1);
	if (sorted_a(stack_b, total))
		return (1);
	if (total != 3)
		return (0);
	sort_b_three(stack_b);
	return (1);
}

int	swap_b(t_stack *stack_b, int total)
{
	if (total <= 2)
	{
		if (stack_b->nb < stack_b->next->nb)
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
		if (stack_b->nb > stack_b->next->nb)
			return (0);
		stack_b = stack_b->next;
		i++;
	}
	return (1);
}