/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:03 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/03 17:35:05 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	(*stack_a)->elements++;
	(*stack_b)->elements--;
	write(1, "pa\n", 3);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	(*stack_a)->elements--;
	(*stack_b)->elements++;
	write(1, "pb\n", 3);
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
