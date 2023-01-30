/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:45:35 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/30 14:04:18 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void	swap(t_stack **stack)
{
	int		*one;
	int		*two;
	int		tmp;

	if (!stack || ((*stack)->next == *stack))
		return ;
	one = &((*stack)->nb);
	two = &((*stack)->next->nb);
	tmp = *one;
	*one = *two;
	*two = tmp;
}

// sa and sb at the same time.

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}