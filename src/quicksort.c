/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/01 17:15:40 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pivot(t_stack *stack)
{
	t_stack	*one;
	t_stack	*two;

	one = stack;
	two = stack;
	if (!divided_by_2(stack))
		return (0);
	while (two && two->next != stack)
	{
		one = one->next;
		two = two->next->next;
	}
	printf("pivot: %d\n", one->nb);
	return (one->nb);
}

int	divided_by_2(t_stack *stack)
{
	t_stack	*first;
	int		i;

	first = stack;
	i = 0;
	while (first->next != stack)
	{
		first = first->next;
		i++;
	}
	i++;
	printf("i: %d\n", i);
	if (i % 2 == 0)
		return (0);
	return (1);
}