/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/16 16:29:38 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty

#include "../push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;
	t_stack *node;

	tmp = (*stack1);
	node = (*stack1);
	printf("leftover nodes:%d\n", tmp->nb);
	*stack1 = tmp->next;
	(*stack1)->prev = tmp->prev;
	// printf("stack %d, stack->next %d start %d\n", tmp->prev->prev->prev, *stack1, NULL);
	// printf("*stack1=%d\ntemp=%d\ntemp->n=%d\ntemp->p=%d\n", (*stack1)->nb, tmp->nb,tmp->next->nb,tmp->prev->nb);
	tmp->prev = *stack1;
	if (!*stack2)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *stack2;
		tmp->prev = (*stack2)->prev;
		tmp->next->prev = tmp;
		tmp->prev->next = tmp;
	}
	if (node->next == node)
		*stack1 = NULL;
	*stack2 = tmp;
}