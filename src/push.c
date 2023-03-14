/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:28:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 14:53:58 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty

#include "../push_swap.h"

// void push(t_stack *stack)
// {
// 	t_node	*tmp;
// 	t_node	*last;
// 	t_node	*head;

// 	// printf("push function:\n");
// 	// print_stacks(*stack_a, *stack_b);
// 	// printf("A:%p\nB:%p", stack_a, stack_b);
// 	head = (stack->stack_a);
// 	tmp = (stack->stack_a)->next;
// 	last = (stack->stack_a)->prev;
// 	if (last->next == last)
// 	{
// 		printf("test\n");
// 		(stack->stack_a) = NULL;
// 		return ;
// 	}
// 	else
// 	{
// 		tmp->prev = last;
// 		last->next = tmp;
// 		stack->stack_a = tmp;
// 	}
// 	if (!stack->stack_b)
// 	{
// 		head->next = head;
// 		head->prev = head;
// 	}
// 	else
// 	{
// 		head->next = stack->stack_b;
// 		head->prev = (stack->stack_b)->prev;
// 		head->next->prev = head;
// 		head->prev->next = head;
// 	}
// 	stack->stack_b = head;
// }

void push_function_a_to_b(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;
	t_node	*head;

	// printf("push function:\n");
	// print_stacks(*stack_a, *stack_b);
	// printf("A:%p\nB:%p", stack_a, stack_b);
	head = (stack->stack_a);
	tmp = (stack->stack_a)->next;
	last = (stack->stack_a)->prev;
	if (last->next == last)
	{
		// printf("test\n");
		(stack->stack_a) = NULL;
		return ;
	}
	else
	{
		tmp->prev = last;
		last->next = tmp;
		stack->stack_a = tmp;
	}
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
	stack->stack_b = head;
}

void push_function_b_to_a(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;
	t_node	*head;

	head = (stack->stack_b);
	tmp = (stack->stack_b)->next;
	last = (stack->stack_b)->prev;
	// printf("print stacks in b to a:");
	// print_stacks(stack);
	if (head->next == head)
	{
		// printf("test\n");
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
		// printf("else\n");
		tmp->prev = last;
		last->next = tmp;
		stack->stack_b = tmp;
	}
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
	stack->stack_a = head;
}

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

