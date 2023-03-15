/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:55:24 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// function that pushes node from stack_a to stack_b

void	push_function_a_to_b(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;
	t_node	*head;

	head = (stack->stack_a);
	tmp = (stack->stack_a)->next;
	last = (stack->stack_a)->prev;
	if (last->next == last)
	{
		(stack->stack_a) = NULL;
		return ;
	}
	else
	{
		tmp->prev = last;
		last->next = tmp;
		stack->stack_a = tmp;
	}
	push_function_a_to_b_utils(stack, head);
	stack->stack_b = head;
}

void	push_function_a_to_b_utils(t_stack *stack, t_node *head)
{
	if (!stack->stack_b)
	{
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->next = stack->stack_b;
		head->prev = (stack->stack_b)->prev;
		head->next->prev = head;
		head->prev->next = head;
	}
}

// function that pushes node from stack_b to stack_a

void	push_function_b_to_a(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;
	t_node	*head;

	head = (stack->stack_b);
	tmp = (stack->stack_b)->next;
	last = (stack->stack_b)->prev;
	if (head->next == head)
	{
		head->next = stack->stack_a;
		head->prev = (stack->stack_a)->prev;
		head->next->prev = head;
		head->prev->next = head;
		(stack->stack_b) = NULL;
		stack->stack_a = head;
		return ;
	}
	else
	{
		tmp->prev = last;
		last->next = tmp;
		stack->stack_b = tmp;
	}
	push_function_b_to_a_utils(stack, head);
	stack->stack_a = head;
}

void	push_function_b_to_a_utils(t_stack *stack, t_node *head)
{
	if (!stack->stack_a)
	{
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->next = stack->stack_a;
		head->prev = (stack->stack_a)->prev;
		head->next->prev = head;
		head->prev->next = head;
	}
}

// function that pushes from stack_b to stack_a until
// it went through all elements

void	push_b(t_stack *stack, int push)
{
	int	i;

	i = 0;
	while (i < push)
	{
		push_b_to_a(stack);
		i++;
	}
}
