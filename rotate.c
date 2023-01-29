/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:32:31 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/29 22:29:38 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
// Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rotate(t_stack **stack)
{
	if (!stack)
		return ;
	*stack = (*stack)->next;
}

//  ra and rb at the same time

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
// Shift down all elements of stack b by 1.
// The last element becomes the first one.

void	rev_rotate(t_stack **stack)
{
	if (!stack)
		return ;
	*stack = (*stack)->prev;
}
// rra and rrb at the same time.

void	rev_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_rr(stack_a);
	rotate_rr(stack_b);
}