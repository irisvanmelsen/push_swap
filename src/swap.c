/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:45:35 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/08 11:25:28 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void	swap(t_node *stack)
{
	int		*one;
	int		*two;
	int		tmp;

	if (!stack || (stack->next == stack))
		return ;
	one = &((stack)->nb);
	two = &((stack)->next->nb);
	tmp = *one;
	*one = *two;
	*two = tmp;
}

// sa and sb at the same time.

void	swap_ss(t_node *stack)
{
	swap(stack);
	swap(stack);
}