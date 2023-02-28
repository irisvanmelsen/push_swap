/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:38 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/28 18:59:24 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a(t_stack *stack_a, int total)
{
	if (swap_a(stack_a, total) == 1)
		return (1);
	if (sorted_a(stack_a, total) == 1)
		return (1);
	printf("test check_a\n");
	if (total > 2)
		return (0);
	sort_a_three(stack_a);
	return (1);
}

int	swap_a(t_stack *stack_a, int total)
{
	if (total < 3)
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

	i = 0;
	if (total <= 1)
		return (1);
	while (total > i)
	{
		printf("stack_a->nb: %d\n", stack_a->nb);
		if (stack_a->nb < stack_a->next->nb)
			return (0);
		printf("sorted_a check\n");
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}
