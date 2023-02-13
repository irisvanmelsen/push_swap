/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:38 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/13 12:45:28 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a(t_stack *stack_a, int total)
{
	if (!swap_a(stack_a, total))
		return (0);
	if (!sorted_a(stack_a, total))
		return (0);
	return (1);
}

int	swap_a(t_stack *stack_a, int total)
{
	if (total <= 2)
	{
		if (stack_a->nb > stack_a->next->nb)
			sa(&stack_a);
		return (1);
	}
	return (0);
}

int	sorted_a(t_stack *stack_a, int total)
{
	int	i;

	i = 1;
	while (total > i)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		i++;
	}
	return (1);
}