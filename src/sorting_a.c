/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:40:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/03 18:02:32 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a(t_stack *stack_a, int total)
{
	if (sorted_or_swap_a(stack_a, total) == 1)
		return (1);
	if (sorted_a(stack_a, total) == 1)
		return (1);
	if (stack_a->elements > 3)
		return (0);
	sort_a_three(stack_a);
	return (1);
}

int	sorted_or_swap_a(t_stack *stack_a, int total)
{
	if (total < 3)
	{
		if (stack_a->nb > stack_a->next->nb)
			swap_a(&stack_a);
		return (1);
	}
	return (0);
}

int	sorted_a(t_stack *stack_a, int total)
{
	int	i;

	i = 0;
	if (total <= 1)
		return (1);
	while (total > i)
	{
		if (stack_a->nb < stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}
