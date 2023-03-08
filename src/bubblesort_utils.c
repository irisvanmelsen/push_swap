/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:30:58 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/08 16:05:27 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pivot(t_node *stack, int total)
{
	t_node	**sorted;
	t_node	*tmp;
	int		pivot;
	int		i;
	int		sort;

	sort = 1;
	tmp = stack;
	sorted = malloc(sizeof(t_stack *));
	*sorted = NULL;
	i = 0;
	if (!sorted)
		error_message();
	while (tmp && i <= total)
	{
		add_to_end(sorted, create_node(stack->nb));
		stack = stack->next;
		if (tmp == stack)
			break ;
		i++;
	}
	bubblesort(stack, *sorted);
	pivot = find_middle(*sorted);
	free(sorted);
	return (pivot);
}

int	find_middle(t_node *stack)
{
	t_node	*one;
	t_node	*two;

	one = stack;
	two = stack;
	while (two && two->next != stack)
	{
		if (two->next->next == stack)
			break ;
		one = one->next;
		two = two->next->next;
	}
	return (one->nb);
}