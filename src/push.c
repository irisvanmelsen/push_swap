/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/28 19:06:03 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty

#include "../push_swap.h"

void push(t_stack **stack1, t_stack **stack2)
{
	t_stack *tmp;
	t_stack *last;
	t_stack *head;

	head = (*stack1);
	tmp = (*stack1)->next;
	last = (*stack1)->prev;
	if (!*stack1)
		return ;
	if (last->next == last)
		*stack1 = NULL;
	// printf("leftover nodes:%d\n", tmp->nb);
	else
	{
		tmp->prev = last;
		last->next = tmp;
		*stack1 = tmp;
	}
	// *stack1 = tmp->next;
	// (*stack1)->prev = tmp->prev;
	// printf("stack %d, stack->next %d start %d\n", tmp->prev->prev->prev, *stack1, NULL);
	// tmp->prev = *stack1;
	if (!*stack2)
	{
		head->next = head;
		head->prev = head;
	}
	else
	{
		// printf("*stack1=%d\ntemp=%d\ntemp->n=%d\ntemp->p=%d\n", (*stack1)->nb, tmp->nb, tmp->next->nb, tmp->prev->nb);
		head->next = *stack2;
		head->prev = (*stack2)->prev;
		head->next->prev = head;
		head->prev->next = head;
	}
	*stack2 = head;
}

void	push_a(t_stack *stack_a, t_stack *stack_b, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		pa(&stack_b, &stack_a);
		i++;
	}
}