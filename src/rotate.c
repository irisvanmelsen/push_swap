/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:32:31 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/10 19:54:12 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
// Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rotate(t_node *stack)
{
	if (!stack)
		return ;
	stack = stack->next;
}

//  ra and rb at the same time

void	rotate_rr(t_node *stack)
{
	rotate(stack);
	rotate(stack);
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

void	rev_rotate_rr(t_node *stack)
{
	rev_rotate(&stack);
	rev_rotate(&stack);
}