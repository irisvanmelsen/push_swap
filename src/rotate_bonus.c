/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:32:31 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/20 13:52:17 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
// Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rotate(t_node **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_both(t_stack *stack)
{
	rotate(&(stack->stack_a));
	rotate(&(stack->stack_b));
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
// Shift down all elements of stack b by 1.
// The last element becomes the first one.

void	rev_rotate(t_node **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->prev;
}

// rra and rrb at the same time.

void	rev_rotate_rr(t_stack *stack)
{
	rev_rotate(&(stack->stack_a));
	rev_rotate(&(stack->stack_b));
}
