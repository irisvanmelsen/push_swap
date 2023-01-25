/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:30:55 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/25 19:09:02 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.

void	rotate(t_stack **stack)
{
	if (!stack)
		return ;
	*stack = (*stack)->prev;
}

//  ra and rb at the same time

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(**stack_a);
	rotate(**stack_b);
}

