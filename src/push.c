/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/07 12:33:37 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty

#include "../push_swap.h"

void push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*head;

	// printf("push function:\n");
	// print_stacks(*stack_a, *stack_b);
	// printf("A:%p\nB:%p", stack_a, stack_b);
	head = (*stack_a);
	tmp = (*stack_a)->next;
	last = (*stack_a)->prev;
	if (last->next == last)
	{
		printf("test\n");
		(*stack_a) = NULL;
		return ;
	}
	else
	{
		tmp->prev = last;
		last->next = tmp;
		*stack_a = tmp;
	}
	if (!*stack_b)
	{
		head->next = head;
		head->prev = head;
		*stack_b = malloc(sizeof(t_stack));
		(*stack_b)->index = 0;
	}
	else
	{
		head->next = *stack_b;
		head->prev = (*stack_b)->prev;
		head->next->prev = head;
		head->prev->next = head;
	}
	*stack_b = head;
}

void	push_a(t_stack *stack_a, t_stack *stack_b, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		push_b_to_a(&stack_a, &stack_b);
		i++;
	}
}