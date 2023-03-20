/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:03 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/20 13:38:40 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pushes a node from stack_b to stack_a
// changes elements as the quantity of nodes changes

void	push_b_to_a(t_stack *stack)
{
	if (!stack->stack_b)
	{
		write(1, "pa\n", 3);
		return ;
	}
	push_function_b_to_a(stack);
	if (stack->stack_a)
		stack->elements_a++;
	if (stack->stack_b)
		stack->elements_b--;
	write(1, "pa\n", 3);
}

// pushes a node from stack_a to stack_b
// changes elements as the quantity of nodes changes

void	push_a_to_b(t_stack *stack)
{
	if (!stack->stack_a)
	{
		write(1, "pb\n", 3);
		return ;
	}
	push_function_a_to_b(stack);
	if (stack->stack_a)
		stack->elements_a--;
	if (stack->stack_b)
		stack->elements_b++;
	write(1, "pb\n", 3);
}

// function that swaps within stack_a

void	swap_a(t_node *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

// function that swaps within stack_b

void	swap_b(t_node *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack *stack)
{
	swap(stack->stack_a);
	swap(stack->stack_b);
	write(1, "ss\n", 3);
}
