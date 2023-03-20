/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:52 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:54:20 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// tmp is a temporary of stack so it can be adjusted
// int swap is a counter that keeps track of whether
// a swap happened or not
// bs sort is called to sort the stack and is in a while
// loop as it can be that we need to iterate multiple times
// through the stack to sort it completely

void	bubblesort(t_node *sorted)

{
	t_node	*tmp;
	int		swap;

	tmp = sorted;
	if (!tmp)
		return ;
	swap = 1;
	while (swap != 0)
	{
		swap = 0;
		bs_sort(tmp, &swap, sorted);
	}
	return ;
}

// tmp is used as a starting point of sorting process
// swap keeps track of whether a swap happened or not
// function starts with initializing pointer last to stack
// and moving it to the last node before tmp (start)
// then tmp continues to sort up until the end (last)
// has been reached
// if there are duplicates then there will be an error
// if there is only one number / node then tmp->next = stack
// in this case last is updated to be equal to tmp

void	bs_sort(t_node *tmp, int *swap, t_node *stack)
{
	t_node	*last;

	last = stack;
	while (last->next != tmp)
		last = last->next;
	while (tmp != last)
	{
		if (tmp->nb == tmp->next->nb)
		{
			error_message();
			exit(0);
		}
		if (tmp->nb > tmp->next->nb)
		{
			bs_swap(tmp, tmp->next);
			*swap = 1;
		}
		tmp = tmp->next;
		if (tmp->next == stack)
			last = tmp;
	}
}

// uses a tmp to swap the value of stack1 and stack2

void	bs_swap(t_node *stack1, t_node *stack2)
{
	int	tmp;

	tmp = stack1->nb;
	stack1->nb = stack2->nb;
	stack2->nb = tmp;
}
