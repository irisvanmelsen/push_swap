/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:40:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 14:50:40 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a(t_stack *stack, int push)
{
	if (sorted_or_swap_a(stack, push) == 1)
		return (1);
	// printf("stack_a address: %p\n", stack->stack_a);
	if (sorted_a(stack->stack_a, push) == 1)
	{
		// printf("stack->elements_a %zu\n", stack->elements_a);
		return (1);
	}
	if (stack->elements_a > 3)
		return (0);
	sort_a_three(&(stack->stack_a));
	return (1);
}

int	sorted_or_swap_a(t_stack *stack, int push)
{
	if (push <= 2)
	{
		if (stack->stack_a->nb > stack->stack_a->next->nb)
			swap_a(stack->stack_a);
		return (1);
	}
	return (0);
}

int	sorted_a(t_node *stack_a, int push)
{
	int	i;

	i = 1;
	if (push <= 1)
		return (1);
	while (i < push)
	{
		if (stack_a->nb < stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}