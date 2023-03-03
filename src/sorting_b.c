/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:43:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/03 17:40:04 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_b(t_stack *stack_b, int total)
{
	if (sorted_or_swap_b(stack_b, total))
		return (1);
	if (sorted_b(stack_b, total))
		return (1);
	if (stack_b->elements > 3)
		return (0);
	sort_b_three(stack_b);
	return (1);
}

int	sorted_or_swap_b(t_stack *stack_b, int total)
{
	if (total <= 3)
	{
		if (stack_b->nb < stack_b->next->nb)
			swap_b(&stack_b);
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