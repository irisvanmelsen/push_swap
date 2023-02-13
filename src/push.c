/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/13 13:15:01 by ivan-mel         ###   ########.fr       */
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

	tmp = (*stack1);
	*stack1 = (*stack1)->next;
	(*stack1)->prev = tmp->prev;
	tmp->prev->next = *stack1;
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
	*stack2 = tmp;
}