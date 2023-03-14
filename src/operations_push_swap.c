/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:03 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 13:44:33 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	swap_a(t_node *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_node *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	swap_both(t_node *stack)
{
	swap(stack);
	swap(stack);
	write(1, "ss\n", 3);
}
