/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:30:58 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:54:31 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// looks for the pivot by first makign a copy of the 
// original stack so we can sort the copy and return the pivot
// bubblesort is used as an algorithm to sort
// then the middle / pivot is found and returned after the
// stack is being freed

int	find_pivot(t_node *stack, int push)
{
	t_node	*sorted;
	t_node	*tmp;
	int		pivot;
	int		i;

	tmp = stack;
	i = 0;
	sorted = NULL;
	while (tmp && i <= push)
	{
		add_to_end(&sorted, create_node(stack->nb));
		stack = stack->next;
		if (tmp == stack)
			break ;
		i++;
	}
	bubblesort(sorted);
	pivot = find_middle(sorted);
	free_lst(sorted);
	return (pivot);
}

// function that finds the middle, it does so
// by having one node doing one step at the time and
// the other two. When the two step node is at the end,
// the one step node is halway

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
