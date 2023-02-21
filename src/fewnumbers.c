/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewnumbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:51:44 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/21 17:17:43 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_three(t_stack *stack)
{
	if (stack->nb > stack->next->nb
		&& stack->next->nb > stack->next->next->nb)
	{
		sa(&stack);
		rra(&stack);
	}
	else if (stack->nb - 1 > stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		ra(&stack);
	else if (stack->nb == stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		rra(&stack);
	else if (stack->nb - 1 == stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		sa(&stack);
	else if (stack->nb < stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
	{
		sa(&stack);
		ra(&stack);
	}
}

void	sort_b_three(t_stack *stack)
{
	if (stack->nb < stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
	{
		rb(&stack);
		sb(&stack);
	}
	else if (stack->nb < stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		rb(&stack);
	else if (stack->nb - 1 == stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		rrb(&stack);
	else if (stack->nb == stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		sb(&stack);
	else if (stack->nb - 1 > stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
	{
		sb(&stack);
		rb(&stack);
	}
}